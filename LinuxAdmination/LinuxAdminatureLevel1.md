# Linux System Administration — Session 1 Handbook

> Target system: **Ubuntu 24.04 LTS (Noble Numbat)**
> Everything here also applies to Debian/Mint. Where RHEL/Fedora/CentOS differ, it's marked `RHEL:`.

---

## Table of Contents

| # | Section |
|---|---------|
| 0 | [How You Actually Talk to Linux](#0-how-you-actually-talk-to-linux) |
| 1 | [Anatomy of a Command](#1-anatomy-of-a-command) |
| 2 | [Getting Help — man, --help, info, apropos](#2-getting-help--the-most-important-skill) |
| 3 | [The Filesystem Hierarchy](#3-the-filesystem-hierarchy-fhs) |
| 4 | [Navigation](#4-navigation) |
| 5 | [Creating, Copying, Moving, Deleting](#5-creating-copying-moving-deleting) |
| 6 | [Viewing File Contents](#6-viewing-file-contents) |
| 7 | [Finding Things](#7-finding-things) |
| 8 | [Redirection, Pipes and Streams](#8-redirection-pipes-and-streams) |
| 9 | [Text Processing Toolkit](#9-text-processing-toolkit) |
| 10 | [Permissions and Ownership](#10-permissions-and-ownership) |
| 11 | [Users and Groups](#11-users-and-groups) |
| 12 | [Processes and Jobs](#12-processes-and-jobs) |
| 13 | [systemd and Services](#13-systemd-and-services) |
| 14 | [Package Management](#14-package-management) |
| 15 | [Disks, Filesystems, Mounting](#15-disks-filesystems-mounting) |
| 16 | [Archiving and Compression](#16-archiving-and-compression) |
| 17 | [Networking](#17-networking) |
| 18 | [System Information and Logs](#18-system-information-and-logs) |
| 19 | [Scheduling Tasks](#19-scheduling-tasks) |
| 20 | [The Shell Itself](#20-the-shell-itself-bash) |
| 21 | [Editors: nano and vim](#21-editors-nano-and-vim) |
| 22 | [Quick Reference Cheat Sheet](#22-quick-reference-cheat-sheet) |
| 23 | [Quizzes & Assignments](#23-quizzes--assignments) |

---

## 0. How You Actually Talk to Linux

Linux is built in layers. When you type a command, here's the chain:

```
   YOU (keyboard)
        │
        ▼
 ┌──────────────────┐
 │  Terminal / TTY  │   gnome-terminal, ssh session, Ctrl+Alt+F3
 └──────────────────┘   Just a window that shows text and reads keys
        │
        ▼
 ┌──────────────────┐
 │   SHELL (bash)   │   Parses your line, expands wildcards & variables,
 └──────────────────┘   sets up pipes/redirection, then forks + execs
        │
        ▼
 ┌──────────────────┐
 │  Program binary  │   /usr/bin/ls, /usr/bin/grep ...
 └──────────────────┘   A normal ELF executable on disk
        │  system calls (open, read, write, fork, execve...)
        ▼
 ┌──────────────────┐
 │  LINUX KERNEL    │   The only thing allowed to touch hardware
 └──────────────────┘   Memory, scheduling, filesystems, drivers, network
        │
        ▼
 ┌──────────────────┐
 │    HARDWARE      │
 └──────────────────┘
```

**Key mental model:** the shell is *not* Linux. The shell is a program whose job is to
read a line of text and launch other programs. `ls` is not "part of bash" — it's a
separate executable file at `/usr/bin/ls`. Prove it:

```bash
type ls          # ls is aliased to `ls --color=auto'
type -a ls       # shows the alias AND /usr/bin/ls
which ls         # /usr/bin/ls
file /usr/bin/ls # ELF 64-bit LSB pie executable, x86-64 ...
```

Some things *are* built into bash (no file on disk) because they must change the shell's
own state — `cd`, `export`, `alias`, `echo`, `pwd`:

```bash
type cd          # cd is a shell builtin
which cd         # (nothing / not found on some systems)
```

### Watch the syscalls yourself

This makes the "programs talk to the kernel" idea concrete:

```bash
sudo apt install strace -y
strace -c ls /etc          # -c = summarize syscall counts
strace ls /tmp 2>&1 | head -30
```

You'll see `openat`, `read`, `write`, `close`, `getdents64` — those are the actual
requests `ls` makes to the kernel. **Every** command you learn below is ultimately
just a wrapper around syscalls.

### Everything is a file

The unifying Unix philosophy. Directories, devices, sockets, running processes, even
kernel settings are exposed as files:

```bash
ls -l /dev/sda            # a disk, as a file
cat /proc/cpuinfo         # CPU info, as a file
cat /proc/meminfo         # RAM info, as a file
ls /proc/$$/              # $$ = this shell's PID; its whole state as files
cat /sys/class/net/*/address   # MAC addresses of all NICs
echo 1 | sudo tee /proc/sys/net/ipv4/ip_forward   # change kernel behaviour by writing a file
```

Because of this, the same small set of tools (`cat`, `grep`, `>`, `|`) works on
*everything*. That is why learning 40 commands well gets you very far.

### Unix philosophy in one line

> Write programs that do one thing and do it well. Write programs to work together.
> Write programs to handle text streams, because that is a universal interface.
> — Doug McIlroy

That's why `|` (pipe) exists, and why you'll chain small tools instead of hunting for
one big one.

---

## 1. Anatomy of a Command

```
    command   -a  --long-option   value   argument1  argument2
    ───┬───   ─┬─  ──────┬─────   ──┬──   ──────┬──────────────
       │       │         │          │           │
    program  short     long      option's    what to operate on
             flag      flag       value       (files, dirs, text)
```

Real example broken down:

```bash
ls -l -a --human-readable /var/log
│  │  │  │                └── argument: the directory to list
│  │  │  └── long option: readable sizes (4.0K instead of 4096)
│  │  └── short flag: show hidden files (dotfiles)
│  └── short flag: long listing format
└── the program
```

### Rules for flags

| Rule | Example |
|---|---|
| Short flags = one dash, one letter | `-l` |
| Short flags can be bundled | `ls -lah` == `ls -l -a -h` |
| Long flags = two dashes, a word | `--all`, `--human-readable` |
| Long flag with value | `--block-size=M` or `--block-size M` |
| Short flag with value | `-n 5` or `-n5` |
| `--` means "no more flags after this" | `rm -- -weirdfile` |
| Order usually doesn't matter | `ls -l /tmp` == `ls /tmp -l` (GNU) |

**Why `--` matters:** if you have a file literally named `-rf`, then `rm -rf` would be
read as flags. `rm -- -rf` deletes the file.

### Case sensitivity

Linux is **case sensitive**, always. `File.txt`, `file.txt`, and `FILE.TXT` are three
different files. `-r` and `-R` are often two different flags (in `grep`, `-r` and `-R`
differ on following symlinks).

### Exit status — how commands report success

Every command returns a number: `0` = success, anything else = failure.

```bash
ls /etc
echo $?          # 0

ls /nonexistent
echo $?          # 2

grep "root" /etc/passwd > /dev/null; echo $?   # 0 (found)
grep "zzzz" /etc/passwd > /dev/null; echo $?   # 1 (not found)
```

Chain on exit status:

```bash
mkdir /tmp/proj && cd /tmp/proj      # && = run second ONLY if first succeeded
ping -c1 8.8.8.8 || echo "no net"    # || = run second ONLY if first failed
command1 ; command2                  # ;  = run both regardless
```

---

## 2. Getting Help — The Most Important Skill

You will never memorize every flag. Nobody does. **Learn the lookup reflex instead.**

### 2.1 `man` — the manual pages

```bash
man ls
man chmod
man 5 passwd        # section 5: the FILE /etc/passwd
man 1 passwd        # section 1: the COMMAND passwd
```

**Manual sections** (this trips up beginners constantly):

| Section | Contains | Example |
|---|---|---|
| 1 | User commands | `man 1 passwd` → the `passwd` program |
| 2 | System calls (kernel) | `man 2 open` |
| 3 | Library functions (C) | `man 3 printf` |
| 4 | Device / special files | `man 4 tty` |
| 5 | **File formats & config files** | `man 5 passwd` → `/etc/passwd` layout |
| 6 | Games | `man 6 sl` |
| 7 | Misc / conventions | `man 7 signal`, `man 7 hier` |
| 8 | **Sysadmin commands** | `man 8 mount`, `man 8 useradd` |

As an admin you'll live in sections **1, 5, and 8**.

**Navigating inside `man`** (it uses `less`):

| Key | Action |
|---|---|
| `Space` / `f` | Page down |
| `b` | Page up |
| `↑` `↓` | Line up/down |
| `/word` | Search forward for "word" |
| `?word` | Search backward |
| `n` / `N` | Next / previous match |
| `g` / `G` | Go to start / end |
| `q` | Quit |
| `h` | Help on the pager itself |

**Reading a man page — the structure:**

```
NAME          one-line summary
SYNOPSIS      the grammar of the command  ← read this first
DESCRIPTION   what it does
OPTIONS       every flag explained        ← use /-flagname to jump
EXAMPLES      (not always present, but gold when it is)
EXIT STATUS   what the return codes mean
FILES         config files it reads
SEE ALSO      related commands            ← how you discover new tools
```

**Decoding SYNOPSIS notation:**

```
ls [OPTION]... [FILE]...
   └────┬───┘   └──┬─┘
   [ ] = optional  ... = repeatable

cp [OPTION]... SOURCE DEST        ← SOURCE and DEST have no brackets = REQUIRED
tar {-c|-x|-t} [OPTIONS] ...      ← { | } = pick exactly one
```

Practice: `man ls`, then type `/-h` and press Enter, then `n` until you land on the
`-h, --human-readable` entry. That is the whole workflow.

### 2.2 `--help` — the fast path

Most GNU tools support it. Faster than `man` when you just need to recall a flag.

```bash
ls --help
ls --help | head -20
cp --help | grep -A2 recursive     # find the recursive flag + 2 lines after
```

Some old/BSD-style tools use `-h` or nothing:

```bash
tar --help
find -help         # note: single dash for find
```

### 2.3 `apropos` / `man -k` — search when you don't know the command name

This is the one people forget. **"I need to do X but don't know the tool."**

```bash
apropos "list directory"
apropos partition
apropos -s 8 network          # only section 8
man -k compress               # identical to apropos
man -k "change password"
```

If it returns nothing on a fresh system, build the index:

```bash
sudo mandb
```

### 2.4 `whatis` — one-line description

```bash
whatis ls
# ls (1) - list directory contents

whatis passwd
# passwd (1)  - change user password
# passwd (5)  - the password file
```

### 2.5 `info` — GNU's fuller documentation

Some GNU tools have far more detail in `info` than in `man`.

```bash
info coreutils 'ls invocation'
info bash
```

Keys: `n` next node, `p` previous, `u` up, `q` quit, `Enter` follow link.

### 2.6 `type`, `which`, `whereis` — what am I actually running?

```bash
type cd            # cd is a shell builtin
type ls            # ls is aliased to `ls --color=auto'
type -a python3    # every match, in priority order
which grep         # /usr/bin/grep
whereis grep       # binary + source + man page locations
command -v ls      # POSIX-portable version of `which`
```

Use `help` for **builtins** (they have no man page of their own):

```bash
help cd
help export
help test
help
```

### 2.7 `tldr` — practical examples, community-written

```bash
sudo apt install tldr -y
tldr tar
tldr find
tldr chmod
```

`man` tells you what every flag means. `tldr` tells you the 8 commands people actually
type. Use both.

### 2.8 Local documentation on disk

```bash
ls /usr/share/doc/            # docs shipped with every installed package
ls /usr/share/doc/bash/
zless /usr/share/doc/bash/README.gz
```

### Help cheat table

| I want to... | Command |
|---|---|
| Full reference for a command | `man cmd` |
| Quick flag reminder | `cmd --help` |
| Find a command by what it does | `apropos "keyword"` |
| One-line "what is this?" | `whatis cmd` |
| Practical examples | `tldr cmd` |
| Help for a shell builtin | `help cmd` |
| Where does this binary live | `which cmd` / `type -a cmd` |
| Config file format | `man 5 filename` |

---

## 3. The Filesystem Hierarchy (FHS)

Linux has **one** tree starting at `/`. There is no `C:\`. Extra disks get *mounted*
into the tree as directories.

```
/
├── bin      → /usr/bin    Essential user commands (ls, cp, bash)
├── sbin     → /usr/sbin   System binaries (fdisk, iptables) — usually need root
├── lib      → /usr/lib    Shared libraries (.so files)
├── boot                   Kernel (vmlinuz), initramfs, GRUB config
├── dev                    Device files: sda, null, zero, random, tty
├── etc                    ★ ALL system config. Text files. Your home as an admin.
├── home                   Regular users' home dirs: /home/akhamees
├── root                   root user's home (NOT /home/root)
├── mnt                    Manual/temporary mount point
├── media                  Auto-mounted removable media (USB, CD)
├── opt                    Third-party / self-contained software
├── proc                   Virtual: live kernel + process info (not on disk)
├── sys                    Virtual: kernel device/driver interface
├── run                    Runtime state since boot (PID files, sockets)
├── srv                    Data served by this machine (www, ftp)
├── tmp                    Temp files, world-writable, wiped on reboot
├── usr                    User programs & read-only data
│   ├── bin   most commands        ├── lib   libraries
│   ├── sbin  admin commands       ├── share docs, man pages, icons
│   └── local ★ software YOU compile/install manually
└── var                    ★ Variable data that grows
    ├── log    ← system logs (syslog, auth.log) — you will live here
    ├── spool  ← queues (cron, mail, print)
    ├── cache  ← app caches, apt package cache
    ├── lib    ← app state (databases, dpkg records)
    └── www    ← web server files
```

Explore it:

```bash
ls /
man 7 hier              # the official FHS explanation — read this!
ls -l /bin              # notice: it's a symlink to usr/bin on modern Ubuntu
df -h                   # which disks are mounted where
```

### Filename rules

- Anything except `/` and the NUL byte is legal in a name.
- A leading `.` makes it **hidden** (`.bashrc`) — nothing more magical than that.
- Extensions (`.txt`, `.sh`) are **conventions only**. Linux uses content, not the name:
  ```bash
  file /etc/passwd        # ASCII text
  file /usr/bin/ls        # ELF 64-bit executable
  file image.png
  ```
- Avoid spaces; if you must, quote or escape: `"my file.txt"` or `my\ file.txt`.

### Paths: absolute vs relative

```bash
/home/akhamees/notes.txt    # ABSOLUTE — starts at /, works from anywhere
notes.txt                   # RELATIVE — relative to current directory
./notes.txt                 # explicitly "in current dir"
../sibling/file.txt         # up one level, then down
~/notes.txt                 # ~ = your home = /home/akhamees
~root/                      # root's home
```

| Symbol | Meaning |
|---|---|
| `/` | Root of the tree (or a path separator) |
| `.` | Current directory |
| `..` | Parent directory |
| `~` | Current user's home |
| `~user` | That user's home |
| `-` | Previous directory (with `cd`) |

---

## 4. Navigation

### `pwd` — print working directory

```bash
pwd            # /home/akhamees
pwd -P         # resolve symlinks to the real physical path
pwd -L         # logical path (default, keeps symlinks)
```

### `cd` — change directory (a shell builtin)

```bash
cd /var/log         # absolute
cd log              # relative (if you're in /var)
cd ..               # up one
cd ../..            # up two
cd                  # → home (bare cd)
cd ~                # → home
cd -                # → previous directory (toggle!)
cd /var/log && pwd  # verify you arrived
```

`cd -` is genuinely one of the highest-value tricks: jump between two dirs endlessly.

### `ls` — list

Flags you must know:

| Flag | Meaning |
|---|---|
| `-l` | Long format (perms, links, owner, group, size, mtime, name) |
| `-a` | All, including `.` hidden files |
| `-A` | Almost all — hidden but not `.` and `..` |
| `-h` | Human-readable sizes (use with `-l`) |
| `-t` | Sort by modification time, newest first |
| `-r` | Reverse sort order |
| `-S` | Sort by file size |
| `-R` | Recurse into subdirectories |
| `-d` | The directory itself, not its contents |
| `-i` | Show inode numbers |
| `-1` | One entry per line |
| `-F` | Append type indicator: `/` dir, `*` exec, `@` symlink |

```bash
ls
ls -l
ls -lh /var/log
ls -la ~                  # everything incl. dotfiles
ls -ltr /var/log          # oldest→newest: newest at BOTTOM, best for logs
ls -lS /var/log           # biggest files first
ls -ld /etc               # info about /etc itself
ls -li                    # with inode numbers
ls -R /etc/apt            # whole subtree
ls -F /                   # mark types
ls *.txt                  # glob: all .txt in cwd
ls /etc/*.conf            # glob with path
```

**Decoding `ls -l` output:**

```
-rw-r--r--  1 akhamees akhamees  1234 Jul 26 17:24 notes.txt
│└┬┘└┬┘└┬┘  │ └───┬──┘ └───┬──┘  └─┬─┘ └────┬────┘ └───┬───┘
│ │  │  │   │     │        │       │        │          └─ name
│ │  │  │   │     │        │       │        └─ last modified
│ │  │  │   │     │        │       └─ size in bytes
│ │  │  │   │     │        └─ group owner
│ │  │  │   │     └─ user owner
│ │  │  │   └─ hard link count
│ │  │  └─ others' permissions (r--)
│ │  └─ group's permissions (r--)
│ └─ owner's permissions (rw-)
└─ file type
```

**File type characters (first column):**

| Char | Type |
|---|---|
| `-` | Regular file |
| `d` | Directory |
| `l` | Symbolic link |
| `c` | Character device (`/dev/tty`) |
| `b` | Block device (`/dev/sda`) |
| `s` | Socket |
| `p` | Named pipe (FIFO) |

### `tree` — visual hierarchy

```bash
sudo apt install tree -y
tree /etc/apt
tree -L 2 /var            # only 2 levels deep
tree -d /usr              # directories only
tree -a ~                 # include hidden
tree -h -L 1 /var         # with sizes
```

### Globbing (wildcards) — expanded by the SHELL, not the command

```bash
ls *.txt          # * = any number of any chars (incl. none)
ls file?.txt      # ? = exactly one char
ls file[123].txt  # [] = one char from the set
ls file[1-5].txt  # ranges
ls file[!1].txt   # ! = NOT
ls *.{txt,log}    # brace expansion → *.txt *.log
touch file{1..5}.txt      # creates file1..file5 — sequences
mkdir -p proj/{src,docs,tests}/   # 3 dirs at once
echo *            # proves the shell expands it before the command runs
```

---

## 5. Creating, Copying, Moving, Deleting

### `touch` — create empty file / update timestamps

```bash
touch newfile.txt
touch a.txt b.txt c.txt
touch file{1..10}.txt
touch -c existing.txt        # -c: don't create if missing, just update time
touch -t 202601011200 f.txt  # set a specific time (YYYYMMDDhhmm)
touch -d "2 days ago" f.txt
touch -r ref.txt target.txt  # copy ref.txt's timestamp onto target.txt
touch -a f.txt               # only access time
touch -m f.txt               # only modification time
```

### `mkdir` — make directories

```bash
mkdir projects
mkdir dir1 dir2 dir3
mkdir -p a/b/c/d             # -p: create parents as needed, no error if exists
mkdir -m 750 secure_dir      # -m: set permissions at creation
mkdir -pv a/b/c              # -v: verbose, print what was made
mkdir -p site/{css,js,img}   # combine with brace expansion
```

`-p` is the flag you'll use 90% of the time — it's idempotent (safe to re-run).

### `cp` — copy

| Flag | Meaning |
|---|---|
| `-r` / `-R` | Recursive — **required** for directories |
| `-i` | Interactive — prompt before overwrite |
| `-n` | No-clobber — never overwrite |
| `-v` | Verbose |
| `-p` | Preserve mode, ownership, timestamps |
| `-a` | Archive = `-dR --preserve=all` — the backup flag |
| `-u` | Update — only if source is newer |
| `-l` | Hard link instead of copying |
| `-s` | Symlink instead of copying |

```bash
cp file.txt backup.txt
cp file.txt /tmp/                    # keep name, new dir
cp file1 file2 file3 /tmp/           # many → one dir
cp -r mydir /tmp/                    # directory
cp -av /etc/apt /tmp/apt-backup      # preserve everything + show progress
cp -i important.txt /tmp/            # ask before clobbering
cp file.txt{,.bak}                   # brace trick → cp file.txt file.txt.bak
cp -u src/* dest/                    # sync only newer files
```

### `mv` — move / rename (same operation in Unix)

```bash
mv old.txt new.txt              # rename
mv file.txt /tmp/               # move
mv file.txt /tmp/renamed.txt    # move + rename
mv dir1 dir2                    # no -r needed for mv!
mv -i a.txt b.txt               # prompt on overwrite
mv -n a.txt b.txt               # never overwrite
mv -v *.log /var/log/archive/   # verbose
mv -b a.txt b.txt               # backup the overwritten file as b.txt~
```

**Gotcha:** `mv` silently overwrites by default. Alias it: `alias mv='mv -i'`.

### `rm` — remove (there is NO trash bin)

| Flag | Meaning |
|---|---|
| `-r` | Recursive — needed for directories |
| `-f` | Force — no prompts, ignore missing files |
| `-i` | Interactive — prompt for each |
| `-I` | Prompt once if >3 files (safer middle ground) |
| `-v` | Verbose |
| `-d` | Remove empty directory |

```bash
rm file.txt
rm -i file.txt
rm -r mydir/
rm -rf /tmp/junk/           # the classic; be certain of the path
rm -I *.log                 # single confirm for the batch
rm -- -weirdname            # file that starts with a dash
rm ./-weirdname             # alternative
```

**Safety habits (adopt these today):**

```bash
alias rm='rm -I'                     # confirm on bulk deletes
ls /path/to/delete/                  # ALWAYS list before you rm -rf
echo rm -rf /path/*                  # dry-run: echo it first, read it, then remove `echo`
```

> **Never** run `rm -rf /` or `rm -rf /*`. Also beware `rm -rf $VAR/` when `$VAR` is
> empty — it becomes `rm -rf /`. Always quote: `rm -rf "${VAR:?}/"` (the `:?` aborts
> if unset).

### `rmdir` — remove empty directories only

```bash
rmdir emptydir
rmdir -p a/b/c        # remove c, then b, then a if each becomes empty
```

Safer than `rm -r` when you *expect* the directory to be empty — it errors if it isn't.

### `ln` — links

```bash
ln -s /path/to/original linkname     # SOFT/symbolic link (most common)
ln original.txt hardlink.txt         # HARD link (same inode, same data)
ln -sf /new/target existinglink      # -f: replace existing link
ls -li                               # compare inode numbers
```

| | Hard link | Symbolic link |
|---|---|---|
| Points to | The inode (data itself) | A path string |
| Across filesystems | ❌ No | ✅ Yes |
| To directories | ❌ No | ✅ Yes |
| Survives original deletion | ✅ Yes | ❌ Becomes broken |
| `ls -l` shows | Normal file | `link -> target` |

```bash
# Demonstrate it
echo "hello" > orig.txt
ln orig.txt hard.txt
ln -s orig.txt soft.txt
ls -li *.txt          # orig and hard share an inode
rm orig.txt
cat hard.txt          # still "hello"
cat soft.txt          # No such file or directory — dangling
```

---

## 6. Viewing File Contents

### `cat` — concatenate and print

```bash
cat file.txt
cat file1 file2 > merged.txt     # actual purpose: concatenation
cat -n file.txt                  # number ALL lines
cat -b file.txt                  # number only non-blank lines
cat -A file.txt                  # show all invisibles: tabs ^I, line ends $
cat -s file.txt                  # squeeze repeated blank lines
cat > new.txt                    # type text, Ctrl+D to finish
cat >> existing.txt              # append mode
cat << 'EOF' > script.sh         # heredoc
#!/bin/bash
echo hi
EOF
```

`cat -A` is the tool for "why won't my script run?" — it reveals Windows `^M`
line endings.

### `less` — the pager (use this for big files)

```bash
less /var/log/syslog
less +F /var/log/syslog     # follow mode, like tail -f (Ctrl+C then q to exit)
less -N file.txt            # show line numbers
less -S file.txt            # don't wrap long lines (chop)
```

Same keys as `man` (see §2.1): `/search`, `n`, `g`, `G`, `q`.
Rule of thumb: **`cat` for small files, `less` for anything you might scroll.**

### `head` / `tail`

```bash
head file.txt              # first 10 lines
head -n 20 file.txt        # first 20
head -5 file.txt           # shorthand
head -c 100 file.txt       # first 100 BYTES
head -n -5 file.txt        # all but last 5

tail file.txt              # last 10 lines
tail -n 50 /var/log/syslog
tail -f /var/log/syslog    # ★ FOLLOW: live stream as it grows
tail -F /var/log/syslog    # follow + survive log rotation
tail -n +10 file.txt       # from line 10 to the END
```

`tail -f` is the single most-used admin command for debugging live services.

```bash
head -n 20 /etc/passwd | tail -n 5    # lines 16–20
```

### `wc` — word count

```bash
wc file.txt          # lines words bytes filename
wc -l file.txt       # lines only  ← most used
wc -w file.txt       # words
wc -c file.txt       # bytes
wc -m file.txt       # characters (differs from bytes in UTF-8)
wc -L file.txt       # length of longest line
ls | wc -l           # count files in a directory
grep -c root /etc/passwd     # (grep -c is better than | wc -l for counting matches)
```

### `file` — identify content type

```bash
file /etc/passwd
file /usr/bin/ls
file *
file -b photo.jpg     # brief, no filename
file -i doc.txt       # MIME type
```

### `stat` — full metadata

```bash
stat file.txt
stat -c '%s' file.txt          # size only
stat -c '%U %G %a %n' file.txt # user group octal-perms name
stat -f /                      # filesystem stats instead
```

`stat` shows the three timestamps: **atime** (accessed), **mtime** (content modified),
**ctime** (inode changed — perms/owner/name).

### Others

```bash
nl file.txt            # number lines (more control than cat -n)
tac file.txt           # cat backwards (last line first)
rev file.txt           # reverse each line's characters
od -c file.bin         # octal/char dump
xxd file.bin | head    # hex dump
strings /usr/bin/ls    # printable strings inside a binary
zcat file.gz           # cat a gzip without decompressing to disk
zless / zgrep          # same idea for less/grep
```

---

## 7. Finding Things

### `find` — the powerhouse (searches live, by attribute)

```
find [WHERE] [CRITERIA] [ACTION]
```

**By name:**
```bash
find /etc -name "*.conf"
find . -iname "readme*"          # -iname = case-insensitive
find / -name "sshd_config" 2>/dev/null   # hide permission-denied noise
find . -not -name "*.txt"        # negate
find . -path "*/src/*.js"        # match whole path
```

**By type:**
```bash
find /var -type f        # f=file  d=dir  l=link  b=block  c=char  s=socket  p=pipe
find /etc -type d -name "*apt*"
find /usr/bin -type l    # all symlinks
```

**By size:**
```bash
find /var -size +100M            # bigger than 100 MB
find . -size -1k                 # smaller than 1 KB
find . -size +10M -size -100M    # between (criteria are ANDed)
find . -empty                    # zero-byte files / empty dirs
```
Units: `c` bytes, `k` KB, `M` MB, `G` GB. `+` = more than, `-` = less than.

**By time:**
```bash
find /var/log -mtime -7      # content modified in last 7 DAYS
find /var/log -mtime +30     # older than 30 days
find /etc -mmin -60          # modified in last 60 MINUTES
find . -atime -1             # accessed in last day
find . -newer reference.txt  # newer than another file
```

**By owner / permission:**
```bash
find /home -user akhamees
find / -group sudo 2>/dev/null
find /home -nouser              # orphaned files (deleted user)
find / -perm 777 -type f 2>/dev/null
find / -perm -4000 -type f 2>/dev/null   # ★ SUID files — a security audit staple
find / -perm -2000 -type f 2>/dev/null   # SGID files
```

**Actions — do something with each result:**
```bash
find . -name "*.tmp" -delete
find . -name "*.log" -exec rm {} \;        # {} = each result, \; ends the cmd
find . -name "*.log" -exec rm {} +         # + batches them: much faster
find . -name "*.sh" -exec chmod +x {} +
find . -name "*.conf" -exec grep -l "Port" {} +
find /var/log -name "*.log" -ok rm {} \;   # -ok = -exec but asks first
find . -type f -printf "%s %p\n" | sort -rn | head   # size + path, biggest first
```

**Depth and pruning:**
```bash
find /etc -maxdepth 1 -name "*.conf"     # don't recurse
find . -mindepth 2
find / -path /proc -prune -o -name "*.log" -print    # skip /proc
```

**Combining:**
```bash
find /var/log -type f -name "*.log" -size +10M -mtime +30 -exec ls -lh {} +
find . \( -name "*.jpg" -o -name "*.png" \) -size +1M     # -o = OR
```

### `locate` — instant, but from a database

```bash
sudo apt install plocate -y
sudo updatedb              # refresh the index (cron does this daily)
locate sshd_config
locate -i README           # case-insensitive
locate -c "*.conf"         # just the count
locate -e file.txt         # only entries that still exist
```

| | `find` | `locate` |
|---|---|---|
| Speed | Slow (walks the disk) | Instant (DB lookup) |
| Freshness | Always current | As of last `updatedb` |
| Criteria | Name, size, time, perms, owner... | Name only |

### `which` / `whereis` / `type`

```bash
which python3          # first match in $PATH
which -a python3       # all matches
whereis python3        # binary, source, man
type -a python3        # shell's view: aliases, builtins, functions, files
```

### `grep` — search *inside* files

| Flag | Meaning |
|---|---|
| `-i` | Ignore case |
| `-v` | Invert — lines that do NOT match |
| `-n` | Show line numbers |
| `-r` / `-R` | Recursive through directories |
| `-l` | Only list filenames with matches |
| `-L` | Only filenames WITHOUT matches |
| `-c` | Count matching lines |
| `-w` | Whole word only |
| `-x` | Whole line only |
| `-A n` | n lines After match |
| `-B n` | n lines Before |
| `-C n` | n lines of Context both sides |
| `-E` | Extended regex (same as `egrep`) |
| `-F` | Fixed string, no regex (fast, safe) |
| `-o` | Print only the matched part |
| `-q` | Quiet — exit status only, for scripts |
| `--color=auto` | Highlight matches |

```bash
grep root /etc/passwd
grep -i ERROR /var/log/syslog
grep -n "bash" /etc/passwd
grep -rn "TODO" ~/projects/
grep -v "^#" /etc/ssh/sshd_config           # strip comments
grep -v "^#" /etc/ssh/sshd_config | grep -v "^$"   # strip comments AND blanks
grep -c "Failed password" /var/log/auth.log
grep -l "PermitRootLogin" /etc/ssh/*
grep -A3 -B3 "error" app.log
grep -w "cat" file.txt              # matches "cat", not "category"
grep -E "^(root|akhamees)" /etc/passwd
grep -oE "[0-9]{1,3}(\.[0-9]{1,3}){3}" /var/log/auth.log | sort -u   # extract IPs
ps aux | grep [s]shd                # the [] trick excludes the grep itself
```

**Regex quick reference:**

| Pattern | Matches |
|---|---|
| `^` | Start of line |
| `$` | End of line |
| `.` | Any single char |
| `*` | 0+ of previous |
| `+` | 1+ of previous (needs `-E`) |
| `?` | 0 or 1 (needs `-E`) |
| `[abc]` | a, b, or c |
| `[^abc]` | NOT a, b, or c |
| `[0-9]` | Any digit |
| `\|` | OR (needs `-E`, then plain `\|` → `\|`) |
| `{n,m}` | n to m repeats (needs `-E`) |
| `\<` `\>` | Word boundaries |
| `\.` | A literal dot |

```bash
grep "^root" /etc/passwd        # lines starting with root
grep "bash$" /etc/passwd        # lines ending with bash
grep "^$" file.txt              # blank lines
grep -E "^[0-9]+$" file.txt     # lines that are only digits
```

---

## 8. Redirection, Pipes and Streams

Every process starts with three open channels:

| FD | Name | Default |
|---|---|---|
| `0` | **stdin** | keyboard |
| `1` | **stdout** | terminal |
| `2` | **stderr** | terminal |

Understanding these is what separates a user from an admin.

### Output redirection

```bash
ls > out.txt              # stdout → file (OVERWRITE)
ls >> out.txt             # stdout → file (APPEND)
ls 1> out.txt             # explicit; 1 is the default so it's the same

ls /nope 2> err.txt       # stderr → file
ls /nope 2>> err.txt      # append stderr

ls /etc /nope > out.txt 2> err.txt        # split them
ls /etc /nope > all.txt 2>&1              # BOTH to one file (order matters!)
ls /etc /nope &> all.txt                  # bash shorthand for the same
ls /etc /nope &>> all.txt                 # append both

command > /dev/null                       # discard stdout
command 2> /dev/null                      # discard stderr (silence errors)
command &> /dev/null                      # discard everything
```

> **`> file 2>&1` vs `2>&1 > file`** — `2>&1` means "make fd 2 point where fd 1
> *currently* points." So it must come **after** the redirect. `2>&1 > file` sends
> stderr to the terminal and stdout to the file. Classic interview question.

### Input redirection

```bash
wc -l < /etc/passwd            # file → stdin
sort < unsorted.txt > sorted.txt
mysql -u root db < dump.sql

cat << EOF                     # heredoc: literal block as stdin
line one
line two
EOF

cat <<< "a here-string"        # herestring: one string as stdin
```

### Pipes `|` — stdout of one → stdin of the next

This is the core of Unix. Chain small tools into a solution:

```bash
ls -l | grep "^d"                                  # directories only
cat /etc/passwd | grep bash | wc -l                # count bash users
ps aux | grep firefox
ps aux | sort -k4 -rn | head -5                    # top 5 memory hogs
history | grep ssh
cut -d: -f7 /etc/passwd | sort | uniq -c | sort -rn   # shell popularity chart
du -h /var | sort -rh | head -10                   # 10 biggest dirs
grep "Failed password" /var/log/auth.log | awk '{print $11}' | sort | uniq -c | sort -rn
```

Note: pipes carry **stdout only**. To pipe stderr too: `cmd 2>&1 | less`.

### `tee` — write to a file AND keep piping

```bash
ls -l | tee listing.txt                # save + display
ls -l | tee listing.txt | grep ".conf" # save full, filter display
ls -l | tee -a listing.txt             # append
echo "1" | sudo tee /proc/sys/net/ipv4/ip_forward   # ★ how to sudo-write a file
```

> `sudo echo x > /root/f` **fails** — the shell opens the file as *you*, before sudo
> runs. `echo x | sudo tee /root/f` works because `tee` runs as root.

### `xargs` — turn stdin into command arguments

Some commands (`rm`, `echo`, `mkdir`) don't read stdin. `xargs` bridges the gap.

```bash
find . -name "*.tmp" | xargs rm
cat servers.txt | xargs -n1 ping -c1
ls *.txt | xargs -I{} cp {} /backup/{}.bak     # -I{} = placeholder
find . -name "*.log" -print0 | xargs -0 rm     # ★ -print0/-0 handles spaces safely
seq 1 10 | xargs -n2                           # 2 args per invocation
cat urls.txt | xargs -P4 -n1 curl -O           # -P4 = 4 in parallel
xargs -p rm < files.txt                        # -p = prompt first
```

---

## 9. Text Processing Toolkit

### `sort`

```bash
sort file.txt
sort -r file.txt         # reverse
sort -n file.txt         # NUMERIC (2 before 10; without -n, "10" < "2")
sort -h file.txt         # human sizes (2K < 1M < 1G)
sort -u file.txt         # unique
sort -k2 file.txt        # by 2nd field
sort -t: -k3 -n /etc/passwd     # -t: sets delimiter → sort users by UID
sort -f file.txt         # ignore case
sort -R file.txt         # random shuffle
sort -c file.txt         # check if sorted
```

### `uniq` — collapse **adjacent** duplicates (so always `sort` first)

```bash
sort file.txt | uniq
sort file.txt | uniq -c        # ★ prefix with counts
sort file.txt | uniq -d        # only duplicated lines
sort file.txt | uniq -u        # only unique (non-repeated) lines
sort file.txt | uniq -i        # case-insensitive
sort f.txt | uniq -c | sort -rn   # ★ THE frequency-count idiom
```

### `cut` — extract columns

```bash
cut -d: -f1 /etc/passwd          # -d delimiter, -f field → usernames
cut -d: -f1,3 /etc/passwd        # multiple fields
cut -d: -f1-3 /etc/passwd        # range
cut -c1-10 file.txt              # by CHARACTER position
cut -d, -f2 data.csv
cut -d: -f7 /etc/passwd | sort -u  # all shells in use
```
Limitation: `cut` needs a *single* consistent delimiter. For whitespace-aligned
columns, use `awk`.

### `tr` — translate/delete characters

```bash
echo "hello" | tr 'a-z' 'A-Z'      # uppercase
tr 'a-z' 'A-Z' < file.txt
echo "a,b,c" | tr ',' '\n'         # commas → newlines
tr -d ' ' < file.txt               # delete all spaces
tr -s ' ' < file.txt               # squeeze repeated spaces to one
tr -d '\r' < win.txt > unix.txt    # strip Windows CR
tr -cd '[:print:]\n' < f.txt       # keep only printable
```

### `sed` — stream editor

```bash
sed 's/old/new/' file.txt          # first occurrence per line
sed 's/old/new/g' file.txt         # g = all occurrences
sed 's/old/new/gi' file.txt        # + case-insensitive
sed -i 's/old/new/g' file.txt      # ★ -i = edit file IN PLACE
sed -i.bak 's/old/new/g' file.txt  # in place, keeping file.txt.bak
sed -n '5p' file.txt               # print only line 5 (-n suppresses default print)
sed -n '10,20p' file.txt           # lines 10–20
sed '3d' file.txt                  # delete line 3
sed '/^#/d' file.txt               # delete comment lines
sed '/^$/d' file.txt               # delete blank lines
sed '/^#/d; /^$/d' /etc/ssh/sshd_config   # both at once
sed 's|/old/path|/new/path|g' f    # any delimiter works — great for paths
sed '2i\inserted line' file.txt    # insert before line 2
sed '$a\appended' file.txt         # append at end
```

### `awk` — field-aware pattern processing

```awk
awk 'PATTERN { ACTION }' file
```
`$0` = whole line, `$1` `$2`... = fields, `NF` = number of fields, `NR` = record number.

```bash
awk '{print $1}' file.txt
awk '{print $1, $3}' file.txt
awk -F: '{print $1}' /etc/passwd            # -F sets delimiter
awk -F: '$3 >= 1000 {print $1}' /etc/passwd # real (non-system) users
awk 'NR==5' file.txt                        # line 5
awk 'NR>=10 && NR<=20' file.txt             # lines 10-20
awk '{print NR": "$0}' file.txt             # number lines
awk '{print NF}' file.txt                   # fields per line
awk '{print $NF}' file.txt                  # LAST field
awk '/error/ {print $2}' app.log            # pattern + action
awk '{sum+=$1} END {print sum}' nums.txt    # sum a column
awk '{sum+=$1} END {print sum/NR}' nums.txt # average
awk 'length > 80' file.txt                  # long lines
df -h | awk '{print $5, $6}'                # disk use % and mount
ps aux | awk '$3 > 1.0 {print $11, $3"%"}'  # processes over 1% CPU
awk -F: 'BEGIN{print "USER SHELL"} {print $1, $7}' /etc/passwd
```

### Others

```bash
paste f1.txt f2.txt          # merge files side by side
join -t: f1 f2               # SQL-style join on a common field
diff a.txt b.txt             # differences
diff -u a.txt b.txt          # unified format (patch-style)
diff -y a.txt b.txt          # side by side
comm a.txt b.txt             # 3 columns: only-a, only-b, both (needs sorted input)
column -t file.txt           # align into pretty columns
split -l 1000 big.txt part_  # split into 1000-line chunks
seq 1 10                     # generate numbers
shuf file.txt                # shuffle lines
fold -w 60 file.txt          # wrap at 60 chars
expand / unexpand            # tabs ↔ spaces
```

---

## 10. Permissions and Ownership

Every file has an **owner (user)**, a **group**, and three permission triads.

```
 -rwxr-xr--
 │└┬┘└┬┘└┬┘
 │ │  │  └── OTHER: everyone else        (r--  = read only)
 │ │  └───── GROUP: members of the group (r-x  = read + execute)
 │ └──────── USER:  the owner            (rwx  = read + write + execute)
 └────────── file type
```

### What r/w/x mean — **different for files vs directories**

| | On a FILE | On a DIRECTORY |
|---|---|---|
| `r` (4) | Read the contents | List the names inside (`ls`) |
| `w` (2) | Modify the contents | Create/delete/rename entries inside |
| `x` (1) | Execute it as a program | **Enter** it (`cd`) and access items by name |

Critical consequences:
- A directory with `r` but no `x`: you can see names but can't `cd` or `stat` them.
- A directory with `x` but no `r`: you can't `ls` it, but you *can* access files if you
  know the exact name. (This is how `/etc/ssl/private` style dirs work.)
- **Deleting a file depends on the DIRECTORY's `w`, not the file's.** You can delete a
  read-only file you don't own if you can write to its directory.

### Octal notation

| Octal | Binary | Perms |
|---|---|---|
| 0 | 000 | `---` |
| 1 | 001 | `--x` |
| 2 | 010 | `-w-` |
| 3 | 011 | `-wx` |
| 4 | 100 | `r--` |
| 5 | 101 | `r-x` |
| 6 | 110 | `rw-` |
| 7 | 111 | `rwx` |

Common values:

| Mode | Meaning | Typical use |
|---|---|---|
| `644` | `rw-r--r--` | Regular files |
| `755` | `rwxr-xr-x` | Scripts, binaries, directories |
| `600` | `rw-------` | Private files, SSH keys, `/etc/shadow` |
| `700` | `rwx------` | Private directories, `~/.ssh` |
| `666` | `rw-rw-rw-` | World-writable file (usually wrong) |
| `777` | `rwxrwxrwx` | **Never** on a real system |

### `chmod` — change mode

**Octal (absolute):**
```bash
chmod 644 file.txt
chmod 755 script.sh
chmod 600 ~/.ssh/id_rsa
chmod 700 ~/.ssh
chmod -R 755 /var/www/html      # -R recursive
```

**Symbolic (relative):**
```
chmod [ugoa][+-=][rwxXst] file
       │      │     └── permissions
       │      └── + add, - remove, = set exactly
       └── u=user g=group o=other a=all
```
```bash
chmod +x script.sh          # add execute for all (respects umask)
chmod u+x script.sh         # only owner
chmod g-w file.txt          # remove group write
chmod o=r file.txt          # others: exactly read
chmod a-w file.txt          # nobody can write
chmod u=rwx,g=rx,o= file    # full spec — same as 750
chmod -R u+w,go-w dir/
chmod -R a+X dir/           # ★ capital X: add x to DIRS and already-exec files only
chmod --reference=a.txt b.txt   # copy a.txt's mode
```

`a+X` is the flag that saves you: `chmod -R a+x` would make every `.txt` executable;
`a+X` only touches directories and things already executable.

### `chown` / `chgrp`

```bash
sudo chown akhamees file.txt
sudo chown akhamees:developers file.txt    # user:group
sudo chown :developers file.txt            # group only
sudo chown -R www-data:www-data /var/www
sudo chgrp developers file.txt
sudo chown --reference=a.txt b.txt
sudo chown -h akhamees link                # -h: the symlink itself, not its target
```

### `umask` — default permission mask

New files start at `666`, new dirs at `777`, then umask bits are **subtracted**.

```bash
umask              # 0022
umask -S           # u=rwx,g=rx,o=rx
umask 077          # private: new files 600, new dirs 700
umask 022          # default: new files 644, new dirs 755
```
```
        Files            Dirs
base     666             777
umask   -022            -022
       ─────           ─────
        644             755
```
Make it permanent in `~/.bashrc` (per user) or `/etc/profile` (system-wide).

### Special permission bits

| Bit | Octal | Shows as | Effect |
|---|---|---|---|
| **SUID** | 4000 | `s` in user-x | Run the file as its **owner** |
| **SGID** | 2000 | `s` in group-x | File: run as group. **Dir: new items inherit the dir's group** |
| **Sticky** | 1000 | `t` in other-x | In a shared dir, only the owner can delete their own files |

```bash
ls -l /usr/bin/passwd     # -rwsr-xr-x root root  ← SUID: users can edit /etc/shadow
ls -ld /tmp               # drwxrwxrwt root root  ← sticky: you can't delete my temp files

sudo chmod u+s file       # or: chmod 4755 file
sudo chmod g+s /shared    # or: chmod 2775 /shared   ← team directory pattern
sudo chmod +t /shared     # or: chmod 1777 /shared

find / -perm -4000 -type f 2>/dev/null    # audit all SUID binaries
```

A capital `S`/`T` instead of lowercase means the bit is set but the underlying `x`
is not — usually a mistake.

### ACLs — per-user permissions beyond the three triads

```bash
sudo apt install acl -y
getfacl file.txt
setfacl -m u:sara:rw file.txt        # give sara rw
setfacl -m g:devs:rx dir/
setfacl -R -m u:sara:rx dir/
setfacl -d -m u:sara:rw dir/         # -d = DEFAULT: applies to new files inside
setfacl -x u:sara file.txt           # remove one entry
setfacl -b file.txt                  # remove all ACLs
```
A `+` at the end of `ls -l` perms (`-rw-rw-r--+`) means an ACL is present.

### Immutable attribute

```bash
sudo chattr +i important.conf   # nobody, not even root, can modify/delete
lsattr important.conf
sudo chattr -i important.conf   # remove
sudo chattr +a /var/log/mylog   # append-only
```

---

## 11. Users and Groups

### The account files

```bash
cat /etc/passwd     # accounts (world-readable)
sudo cat /etc/shadow  # password hashes (root only, 640)
cat /etc/group      # groups
sudo cat /etc/gshadow
cat /etc/skel/ -R   # template copied into every new home dir
cat /etc/login.defs # defaults: UID ranges, password aging
```

**`/etc/passwd` — 7 colon-separated fields:**
```
akhamees:x:1000:1000:Anas Khamees:/home/akhamees:/bin/bash
   │     │  │    │        │             │            │
   │     │  │    │        │             │            └─ 7. login shell
   │     │  │    │        │             └─ 6. home directory
   │     │  │    │        └─ 5. GECOS (full name/comment)
   │     │  │    └─ 4. primary GID
   │     │  └─ 3. UID
   │     └─ 2. password placeholder ('x' = it's in /etc/shadow)
   └─ 1. username
```

**`/etc/shadow` — 9 fields:**
```
akhamees:$y$j9T$...:19900:0:99999:7:::
    │         │       │   │   │   │
    │         │       │   │   │   └─ 6. warning days before expiry
    │         │       │   │   └─ 5. max days password valid
    │         │       │   └─ 4. min days between changes
    │         │       └─ 3. last change (days since 1970-01-01)
    │         └─ 2. hash ($y$=yescrypt, $6$=SHA-512, `!`/`*` = locked/no login)
    └─ 1. username
```

**UID conventions on Ubuntu:**

| UID | Meaning |
|---|---|
| 0 | root |
| 1–999 | System/service accounts |
| 1000+ | Regular human users |
| 65534 | `nobody` |

```bash
awk -F: '$3>=1000 && $3<65534 {print $1}' /etc/passwd   # list real users
```

### Identity commands

```bash
whoami           # current username
id               # uid, gid, all groups
id akhamees      # for another user
id -u            # numeric uid (0 means root — used in scripts)
id -nG           # group names only
groups           # my groups
groups akhamees
who              # who is logged in now
w                # who + what they're running + load
last             # login history (from /var/log/wtmp)
lastlog          # last login per account
logname          # original login name (survives su)
```

### Creating users

```bash
sudo useradd -m -s /bin/bash -c "Sara Ali" sara
#            │   │            └─ GECOS comment
#            │   └─ login shell
#            └─ ★ CREATE HOME DIR (without -m there is no home!)

sudo useradd -m -G sudo,developers -s /bin/bash sara   # secondary groups
sudo useradd -r -s /usr/sbin/nologin svcacct           # -r = system account
sudo useradd -u 1500 -g devs -m custom
sudo useradd -m -e 2026-12-31 temp                     # account expiry date
sudo passwd sara                                       # set the password
```

**Ubuntu's friendlier wrapper:**
```bash
sudo adduser sara          # interactive: home, shell, password, GECOS — all handled
sudo deluser sara
sudo adduser sara sudo     # add sara to the sudo group
```
> `useradd` = low-level, portable, does exactly what you flag.
> `adduser` = Debian/Ubuntu Perl script, interactive, sane defaults. **Prefer
> `adduser` for humans, `useradd` in scripts.**

### Modifying users

```bash
sudo usermod -aG sudo sara      # ★ -aG = APPEND to groups. Forgetting -a REPLACES
                                #   all secondary groups — a classic disaster.
sudo usermod -g devs sara       # change PRIMARY group
sudo usermod -s /bin/zsh sara   # change shell
sudo usermod -l newname oldname # rename login
sudo usermod -d /new/home -m sara   # move home dir
sudo usermod -L sara            # LOCK (puts ! before the hash)
sudo usermod -U sara            # unlock
sudo usermod -e 2026-12-31 sara # set expiry
sudo usermod -u 1501 sara       # change UID
```

Group changes take effect on next login. To refresh now: `newgrp devs` or re-login.

### Deleting users

```bash
sudo userdel sara            # keeps home directory
sudo userdel -r sara         # ★ removes home dir and mail spool
sudo deluser --remove-home sara
sudo deluser --backup --remove-home sara   # tar up the home first
```

### Passwords and aging

```bash
passwd                    # change my own
sudo passwd sara          # change sara's
sudo passwd -l sara       # lock
sudo passwd -u sara       # unlock
sudo passwd -e sara       # expire now → must change at next login
sudo passwd -d sara       # delete password (passwordless — dangerous)
sudo passwd -S sara       # status

sudo chage -l sara                 # ★ list aging info
sudo chage -M 90 sara              # max 90 days
sudo chage -m 7 sara               # min 7 days between changes
sudo chage -W 14 sara              # warn 14 days ahead
sudo chage -E 2026-12-31 sara      # account expires
sudo chage -d 0 sara               # force change at next login
sudo chage sara                    # interactive
```

### Groups

```bash
sudo groupadd developers
sudo groupadd -g 5000 devops       # specific GID
sudo groupmod -n newname oldname   # rename
sudo groupdel developers
sudo gpasswd -a sara developers    # add member
sudo gpasswd -d sara developers    # remove member
sudo gpasswd -A sara developers    # make sara a group admin
getent group developers            # query (works with LDAP too, unlike cat)
getent passwd sara
groups sara
```

**Primary vs secondary group:** every user has exactly one primary GID (field 4 of
`/etc/passwd`) used for new files they create, plus any number of secondary groups
(listed in `/etc/group`).

### Switching identity

```bash
su - sara            # ★ the dash: full login shell, loads sara's env & cd's to her home
su sara              # keeps your env and cwd — usually not what you want
su -                 # become root (needs root's password; disabled by default on Ubuntu)
sudo -i              # ★ root login shell (uses YOUR password) — the Ubuntu way
sudo -s              # root shell, keeps your env
sudo command         # run one command as root
sudo -u sara command # run as sara
sudo -l              # what am I allowed to run?
sudo -k              # forget the cached credential
exit                 # go back
```

### `sudo` configuration

```bash
sudo visudo                       # ★ ALWAYS use visudo — it syntax-checks before saving
sudo visudo -f /etc/sudoers.d/mycfg   # preferred: drop-in file
sudo visudo -c                    # check syntax
```

Syntax: `who  where=(as_whom:as_group)  what`

```
root      ALL=(ALL:ALL) ALL
%sudo     ALL=(ALL:ALL) ALL           # % = a group
sara      ALL=(ALL) NOPASSWD: /usr/bin/systemctl restart nginx
%devs     ALL=(ALL) /usr/bin/apt, /usr/bin/systemctl
akhamees  ALL=(ALL) NOPASSWD: ALL
```

> Editing `/etc/sudoers` with a plain editor and making a typo can lock you out of
> root entirely. `visudo` exists to prevent exactly that.

---

## 12. Processes and Jobs

A **process** is a running program with a PID, a parent (PPID), an owner, and a state.
PID 1 is `systemd` — the ancestor of everything.

### `ps` — snapshot of processes

Two flag styles coexist for historical reasons:

```bash
ps                # just my processes on this terminal
ps aux            # ★ BSD style: ALL processes, all users, incl. no-terminal
ps -ef            # ★ UNIX style: same idea, different columns
ps -eLf           # include threads
ps aux --sort=-%mem | head    # sort by memory desc
ps aux --sort=-%cpu | head
ps -u akhamees                # by user
ps -C nginx                   # by command name
ps -p 1234                    # by PID
ps -ef --forest               # ★ tree view showing parent/child
ps -eo pid,ppid,user,%cpu,%mem,stat,cmd --sort=-%cpu | head
```

**Reading `ps aux`:**
```
USER  PID %CPU %MEM    VSZ   RSS TTY  STAT START TIME COMMAND
root    1  0.0  0.1 168404 11924 ?    Ss   10:00 0:02 /sbin/init
```
- `VSZ` virtual memory reserved · `RSS` actual physical RAM used
- `TTY` controlling terminal (`?` = none, a daemon)
- `STAT` process state:

| Code | Meaning |
|---|---|
| `R` | Running / runnable |
| `S` | Interruptible sleep (waiting) |
| `D` | Uninterruptible sleep (usually disk I/O) — can't be killed |
| `T` | Stopped (Ctrl+Z) |
| `Z` | **Zombie** — finished, parent hasn't reaped it |
| `s` | Session leader |
| `+` | In the foreground |
| `<` | High priority · `N` low priority |
| `l` | Multi-threaded |

### `top` / `htop` — live view

```bash
top
```
| Key in `top` | Action |
|---|---|
| `q` | Quit |
| `k` | Kill (asks for PID) |
| `M` | Sort by memory |
| `P` | Sort by CPU |
| `T` | Sort by time |
| `1` | Show each CPU core separately |
| `u` | Filter by user |
| `c` | Toggle full command line |
| `h` | Help |

```bash
top -u akhamees
top -p 1234
top -b -n1 > snapshot.txt     # batch mode — for scripts/cron

sudo apt install htop -y
htop                          # colored, mouse-driven, F-keys, tree view (F5)
```

### `pgrep` / `pidof`

```bash
pgrep firefox
pgrep -u akhamees
pgrep -l ssh          # with names
pgrep -a ssh          # with full command lines
pgrep -f "python3 app.py"     # match the whole command line
pidof nginx
```

### Signals and killing

```bash
kill -l               # list all 64 signals
```

| Signal | Num | Meaning |
|---|---|---|
| `SIGHUP` | 1 | Hangup — many daemons use it to **reload config** |
| `SIGINT` | 2 | Interrupt — what Ctrl+C sends |
| `SIGQUIT` | 3 | Quit + core dump (Ctrl+\\) |
| `SIGKILL` | 9 | **Kill, uncatchable** — last resort, no cleanup |
| `SIGTERM` | 15 | **Terminate politely** — the default, allows cleanup |
| `SIGSTOP` | 19 | Pause, uncatchable |
| `SIGCONT` | 18 | Resume |
| `SIGTSTP` | 20 | Pause from terminal (Ctrl+Z) |

```bash
kill 1234                 # SIGTERM (15) — always try this FIRST
kill -9 1234              # SIGKILL — only if TERM failed
kill -15 1234
kill -SIGTERM 1234
kill -HUP 1234            # reload config without restarting

killall firefox           # by NAME, all matching
killall -9 firefox
killall -u sara           # everything owned by sara

pkill firefox             # pattern-based
pkill -u sara
pkill -f "python3 app.py" # match full command line
pkill -9 -f myscript
```

> Reach for `-9` last. `SIGKILL` gives the process no chance to flush buffers, close
> files, or release locks — that's how you corrupt databases.

### Job control (background/foreground)

```bash
sleep 300 &          # & = start in background
jobs                 # list this shell's jobs
jobs -l              # with PIDs
fg                   # bring most recent job to foreground
fg %1                # bring job 1
bg %1                # resume job 1 in background
Ctrl+Z               # suspend the foreground job
Ctrl+C               # interrupt (SIGINT)
kill %1              # kill by job number
disown %1            # detach from shell (survives logout)
wait                 # wait for all background jobs
```

**Surviving logout:**
```bash
nohup ./long.sh &            # ignores SIGHUP, output → nohup.out
nohup ./long.sh > out.log 2>&1 &

sudo apt install tmux -y
tmux                         # ★ best answer: a persistent session
#   Ctrl+B then D  → detach
tmux ls
tmux attach -t 0
```

### Priority: `nice` / `renice`

Niceness ranges **-20 (highest priority) to +19 (lowest)**. Default 0.
Only root can set negative values.

```bash
nice -n 10 ./heavy.sh          # start with low priority
nice -n -5 ./important.sh      # needs sudo
renice -n 5 -p 1234            # change a running process
renice -n 5 -u sara            # all of sara's processes
ps -eo pid,ni,cmd | head
```

### Resource inspection

```bash
free -h              # ★ RAM and swap
free -m
vmstat 1 5           # virtual memory stats, 5 samples 1s apart
iostat               # disk I/O (apt install sysstat)
lsof                 # ★ list open files
lsof -u akhamees
lsof -i              # network connections
lsof -i :80          # who has port 80?
lsof /var/log/syslog # who has this file open?
lsof +D /var/log     # everything open under a directory
fuser -v /mnt        # which processes use this mount (before unmounting)
sudo fuser -k /mnt   # kill them
uptime               # ★ uptime + load average
```

**Load average** (`1.5 0.8 0.4`) = avg runnable processes over 1, 5, 15 minutes.
Compare against `nproc` (core count): load 4.0 on a 4-core box = fully busy.

---

## 13. systemd and Services

`systemd` is PID 1 on Ubuntu — it boots the machine and supervises services.
A **unit** is anything systemd manages: `.service`, `.socket`, `.timer`, `.mount`, `.target`.

### `systemctl` — the main interface

```bash
systemctl status                    # overall system state
systemctl status ssh                # ★ one service: state, PID, recent logs
systemctl start nginx
systemctl stop nginx
systemctl restart nginx
systemctl reload nginx              # re-read config, don't drop connections
systemctl reload-or-restart nginx

systemctl enable nginx              # ★ start at boot
systemctl disable nginx
systemctl enable --now nginx        # enable AND start in one step
systemctl disable --now nginx

systemctl is-active nginx
systemctl is-enabled nginx
systemctl is-failed nginx

systemctl mask nginx                # ★ make it impossible to start (stronger than disable)
systemctl unmask nginx
```

> `disable` = won't auto-start at boot, but you can still start it manually.
> `mask` = symlinks the unit to `/dev/null`; it cannot start at all.

### Listing and inspecting

```bash
systemctl list-units --type=service
systemctl list-units --type=service --state=running
systemctl list-unit-files --type=service        # incl. disabled ones
systemctl --failed                              # ★ what's broken right now
systemctl cat nginx                             # show the unit file
systemctl show nginx                            # all properties
systemctl list-dependencies nginx
systemctl daemon-reload                         # ★ after editing any unit file
systemctl edit nginx                            # safe override drop-in
systemctl edit --full nginx                     # edit a full copy
```

### Targets (the old "runlevels")

```bash
systemctl get-default
systemctl set-default multi-user.target      # boot to CLI
systemctl set-default graphical.target       # boot to GUI
systemctl isolate multi-user.target          # switch now
systemctl list-units --type=target
```

| Target | Old runlevel | Meaning |
|---|---|---|
| `poweroff.target` | 0 | Halt |
| `rescue.target` | 1 | Single-user |
| `multi-user.target` | 3 | Multi-user CLI + network |
| `graphical.target` | 5 | + GUI |
| `reboot.target` | 6 | Reboot |

### Power

```bash
systemctl poweroff
systemctl reboot
systemctl suspend
shutdown -h now
shutdown -r +10 "Rebooting in 10 min"
shutdown -c            # cancel a scheduled shutdown
```

### Writing a unit file

```bash
sudo nano /etc/systemd/system/myapp.service
```
```ini
[Unit]
Description=My Application
After=network.target

[Service]
Type=simple
User=akhamees
WorkingDirectory=/opt/myapp
ExecStart=/usr/bin/python3 /opt/myapp/app.py
Restart=on-failure
RestartSec=5

[Install]
WantedBy=multi-user.target
```
```bash
sudo systemctl daemon-reload
sudo systemctl enable --now myapp
systemctl status myapp
journalctl -u myapp -f
```

Unit file locations, in override priority order:
1. `/etc/systemd/system/` — your overrides (highest)
2. `/run/systemd/system/` — runtime
3. `/lib/systemd/system/` — shipped by packages (don't edit these)

---

## 14. Package Management

### `apt` — the friendly front-end (Debian/Ubuntu)

```bash
sudo apt update                   # ★ refresh package lists (does NOT upgrade anything)
sudo apt upgrade                  # upgrade installed packages
sudo apt full-upgrade             # upgrade, allowing removals to resolve deps
sudo apt update && sudo apt upgrade -y

sudo apt install nginx
sudo apt install nginx vim htop   # several at once
sudo apt install nginx=1.24.0-1   # specific version
sudo apt install --no-install-recommends nginx
sudo apt install ./local.deb      # a local .deb with deps resolved

sudo apt remove nginx             # remove binaries, KEEP config
sudo apt purge nginx              # ★ remove binaries AND config
sudo apt autoremove               # remove orphaned dependencies
sudo apt autoclean / clean        # clear the downloaded-package cache

apt search webserver
apt show nginx
apt list --installed
apt list --upgradable
apt list --installed | grep nginx
apt depends nginx
apt rdepends nginx                # reverse: what needs nginx
sudo apt-mark hold nginx          # pin: never upgrade it
sudo apt-mark unhold nginx
```

Key files:
```bash
cat /etc/apt/sources.list
ls /etc/apt/sources.list.d/
ls /var/cache/apt/archives/       # downloaded .deb files
```

### `dpkg` — the low-level tool

`apt` handles dependencies; `dpkg` handles single `.deb` files and doesn't.

```bash
sudo dpkg -i package.deb          # install (deps NOT resolved)
sudo apt install -f               # ★ fix broken deps after a dpkg -i
sudo dpkg -r package              # remove
sudo dpkg -P package              # purge
dpkg -l                           # list all installed
dpkg -l | grep nginx
dpkg -L nginx                     # ★ list every file the package installed
dpkg -S /usr/bin/ls               # ★ which package owns this file?
dpkg -s nginx                     # status/details
dpkg -c package.deb               # contents of a .deb without installing
dpkg --get-selections
```

### `snap` (Ubuntu)

```bash
snap list
sudo snap install code --classic
sudo snap remove code
sudo snap refresh
snap find editor
snap info code
```

### `RHEL:` equivalents

```bash
sudo dnf install nginx        # (or yum on older systems)
sudo dnf remove nginx
sudo dnf update
dnf search nginx
dnf info nginx
rpm -qa                       # ≈ dpkg -l
rpm -ql nginx                 # ≈ dpkg -L
rpm -qf /usr/bin/ls           # ≈ dpkg -S
rpm -ivh pkg.rpm              # ≈ dpkg -i
```

---

## 15. Disks, Filesystems, Mounting

### Inspecting

```bash
df -h                # ★ disk free, human-readable
df -h /              # one filesystem
df -i                # INODE usage — "disk full" with free space = out of inodes
df -T                # show filesystem types

du -h file.txt
du -sh /var          # ★ -s summary, -h human → total size of a dir
du -sh /var/*        # size of each child
du -h --max-depth=1 /var | sort -rh
du -sh /var/* 2>/dev/null | sort -rh | head -10   # ★ find the space hogs

lsblk                # ★ block devices as a tree
lsblk -f             # + filesystems, labels, UUIDs
blkid                # UUIDs and types
sudo fdisk -l        # partition tables
sudo parted -l
```

### Naming

```
/dev/sda        first SATA/SCSI/USB disk
/dev/sda1       first partition on it
/dev/nvme0n1    first NVMe disk
/dev/nvme0n1p1  first partition on it
/dev/vda        virtio disk (VMs)
```

### Mounting

```bash
mount                              # everything currently mounted
findmnt                            # ★ nicer tree view
findmnt /home

sudo mkdir /mnt/usb
sudo mount /dev/sdb1 /mnt/usb
sudo mount -t ext4 /dev/sdb1 /mnt/usb
sudo mount -o ro /dev/sdb1 /mnt/usb     # read-only
sudo mount -o remount,rw /              # remount root writable (rescue mode)
sudo umount /mnt/usb
sudo umount -l /mnt/usb                 # lazy unmount (device busy)
sudo mount -a                           # ★ mount everything in /etc/fstab
```

Common `-o` options: `ro`, `rw`, `noexec`, `nosuid`, `nodev`, `noatime`, `defaults`.

### `/etc/fstab` — persistent mounts

```bash
cat /etc/fstab
```
```
UUID=abc-123  /data  ext4  defaults  0  2
    │           │      │      │      │  └─ fsck order (0 skip, 1 root, 2 others)
    │           │      │      │      └─ dump backup flag (almost always 0)
    │           │      │      └─ mount options
    │           │      └─ filesystem type
    │           └─ mount point
    └─ device (★ use UUID, not /dev/sdb1 — device names can change between boots)
```
```bash
sudo blkid /dev/sdb1                    # get the UUID
echo 'UUID=... /data ext4 defaults 0 2' | sudo tee -a /etc/fstab
sudo mount -a                           # ★ TEST IT before rebooting
```
> A broken `/etc/fstab` can prevent boot. **Always run `sudo mount -a` and confirm no
> errors** before you reboot.

### Creating filesystems

```bash
sudo fdisk /dev/sdb          # MBR partitioning (n, p, w)
sudo parted /dev/sdb         # GPT partitioning
sudo mkfs.ext4 /dev/sdb1
sudo mkfs.xfs /dev/sdb1
sudo mkfs.vfat -F32 /dev/sdb1
sudo e2label /dev/sdb1 DATA
sudo fsck /dev/sdb1          # check (UNMOUNT FIRST)
sudo tune2fs -l /dev/sdb1
```

### Swap

```bash
free -h
swapon --show
sudo fallocate -l 2G /swapfile
sudo chmod 600 /swapfile
sudo mkswap /swapfile
sudo swapon /swapfile
echo '/swapfile none swap sw 0 0' | sudo tee -a /etc/fstab
sudo swapoff /swapfile
```

### LVM (brief)

```bash
sudo pvcreate /dev/sdb1          # physical volume
sudo vgcreate vg0 /dev/sdb1      # volume group
sudo lvcreate -L 10G -n lv_data vg0
sudo mkfs.ext4 /dev/vg0/lv_data
pvs / vgs / lvs                  # summaries
sudo lvextend -L +5G /dev/vg0/lv_data
sudo resize2fs /dev/vg0/lv_data  # grow the filesystem to match
```

---

## 16. Archiving and Compression

**Archiving** (`tar`) bundles many files into one. **Compression** (`gzip`) makes a
file smaller. `tar` does both when you add `-z`/`-j`/`-J`.

### `tar`

| Flag | Meaning |
|---|---|
| `-c` | Create |
| `-x` | Extract |
| `-t` | List contents |
| `-f` | **Filename** (must come last before the name) |
| `-v` | Verbose |
| `-z` | gzip (`.tar.gz`) |
| `-j` | bzip2 (`.tar.bz2`) — smaller, slower |
| `-J` | xz (`.tar.xz`) — smallest, slowest |
| `-C` | Change to directory |
| `--exclude` | Skip a pattern |

```bash
tar -cvf archive.tar dir/                  # create, uncompressed
tar -czvf archive.tar.gz dir/              # ★ create + gzip
tar -cjvf archive.tar.bz2 dir/
tar -cJvf archive.tar.xz dir/

tar -xvf archive.tar                       # extract
tar -xzvf archive.tar.gz                   # ★ extract gzip
tar -xzvf archive.tar.gz -C /tmp/          # extract INTO /tmp
tar -xzvf archive.tar.gz path/inside/file  # extract one member

tar -tvf archive.tar.gz                    # ★ LIST before extracting — always
tar -czvf backup.tar.gz --exclude='*.log' --exclude='node_modules' dir/
tar -czvf etc-$(date +%F).tar.gz /etc      # dated backup
tar -rvf archive.tar newfile.txt           # append to an uncompressed tar
tar -czf - dir/ | ssh user@host "cat > backup.tar.gz"   # stream over SSH
```

Modern `tar` auto-detects compression on extract, so `tar -xvf x.tar.gz` works — but
be explicit in scripts.

### Single-file compressors

```bash
gzip file.txt          # → file.txt.gz, ORIGINAL IS REPLACED
gzip -k file.txt       # -k = keep the original
gzip -9 file.txt       # max compression (1=fast, 9=best)
gunzip file.txt.gz
gzip -d file.txt.gz
gzip -l file.txt.gz    # info
zcat file.txt.gz       # read without decompressing

bzip2 / bunzip2        # same flags, better ratio
xz / unxz              # best ratio
```

### `zip` (cross-platform)

```bash
sudo apt install zip unzip -y
zip archive.zip file.txt
zip -r archive.zip dir/          # ★ -r needed for directories
zip -e secure.zip file.txt       # encrypted
unzip archive.zip
unzip archive.zip -d /tmp/       # into a directory
unzip -l archive.zip             # list
```

### `rsync` — smart sync (the real backup tool)

```bash
rsync -av source/ dest/               # ★ archive + verbose
rsync -avz source/ user@host:/dest/   # -z compress over network
rsync -av --delete source/ dest/      # mirror: delete extras in dest
rsync -av --dry-run source/ dest/     # ★ -n/--dry-run: ALWAYS test first
rsync -avP big.iso user@host:/tmp/    # -P progress + resume
rsync -av --exclude='*.log' src/ dst/
```
> **Trailing slash matters:** `rsync -av src/ dst/` copies the *contents* of src into
> dst. `rsync -av src dst/` creates `dst/src/`.

---

## 17. Networking

### `ip` — the modern tool (replaces `ifconfig`/`route`)

```bash
ip a                        # ★ short for `ip addr show` — all interfaces + IPs
ip addr show eth0
ip -4 a                     # IPv4 only
ip -br a                    # brief, one line each
ip link show                # layer-2: interfaces, MACs, state
sudo ip link set eth0 up
sudo ip link set eth0 down
sudo ip addr add 192.168.1.50/24 dev eth0     # temporary, lost on reboot
sudo ip addr del 192.168.1.50/24 dev eth0

ip r                        # ★ routing table
ip route show
sudo ip route add default via 192.168.1.1
sudo ip route add 10.0.0.0/24 via 192.168.1.1
ip neigh                    # ARP table
```

Persistent config on Ubuntu 24.04 is **netplan**:
```bash
ls /etc/netplan/
sudo nano /etc/netplan/50-cloud-init.yaml
sudo netplan try            # ★ apply with auto-rollback if you lose connectivity
sudo netplan apply
```

### Connectivity testing

```bash
ping 8.8.8.8
ping -c4 google.com         # ★ -c = stop after 4 (otherwise it runs forever)
ping -i 0.5 -c 10 host      # interval
ping6 ipv6.google.com

traceroute google.com       # apt install traceroute
mtr google.com              # ★ live traceroute + loss stats
```

### Ports and sockets

```bash
ss -tuln            # ★ TCP, UDP, Listening, Numeric — the everyday command
ss -tulnp           # + owning process (needs sudo for other users')
ss -t               # established TCP
ss -s               # summary stats
ss -tn state established
sudo lsof -i :80    # who's on port 80
sudo netstat -tulnp # legacy (apt install net-tools)
```

`ss` flags: `-t` tcp, `-u` udp, `-l` listening, `-n` numeric (no DNS lookups),
`-p` process, `-a` all.

### DNS

```bash
dig google.com                 # apt install dnsutils
dig +short google.com          # ★ just the answer
dig MX google.com
dig @8.8.8.8 google.com        # query a specific server
nslookup google.com
host google.com
resolvectl status              # systemd-resolved: what DNS am I using?
cat /etc/hosts                 # static overrides, checked BEFORE DNS
cat /etc/resolv.conf
```

### Transfers

```bash
curl https://example.com
curl -O https://example.com/file.zip     # save with remote name
curl -o my.zip https://example.com/f.zip # save as
curl -L https://short.url                # ★ follow redirects
curl -I https://example.com              # headers only
curl -s https://api.github.com | head    # silent
curl -X POST -d '{"a":1}' -H "Content-Type: application/json" https://api/endpoint
curl -u user:pass https://example.com

wget https://example.com/file.zip
wget -c https://example.com/big.iso      # ★ continue a partial download
wget -O name.zip URL
wget -r -np -k https://site.com          # recursive mirror
wget -q URL                              # quiet
```
`curl` prints to stdout (great in pipes); `wget` saves to disk and can recurse.

### SSH

```bash
ssh user@host
ssh -p 2222 user@host              # non-default port
ssh -i ~/.ssh/mykey user@host      # specific key
ssh user@host "uptime"             # run one command and exit
ssh -v user@host                   # verbose — debug auth failures

ssh-keygen -t ed25519 -C "anaskhamees65@gmail.com"   # ★ generate a key pair
ssh-copy-id user@host                                # install your public key
ssh-add ~/.ssh/id_ed25519

scp file.txt user@host:/tmp/
scp user@host:/tmp/file.txt .
scp -r dir/ user@host:/tmp/
scp -P 2222 file.txt user@host:/tmp/     # ★ capital P for scp (lowercase for ssh)

sftp user@host
```

`~/.ssh/config` — stop typing long commands:
```
Host web
    HostName 203.0.113.10
    User akhamees
    Port 2222
    IdentityFile ~/.ssh/id_ed25519
```
Then just: `ssh web`

Permissions matter — SSH refuses loose ones:
```bash
chmod 700 ~/.ssh
chmod 600 ~/.ssh/id_ed25519
chmod 644 ~/.ssh/id_ed25519.pub
chmod 600 ~/.ssh/authorized_keys
```

Server config: `/etc/ssh/sshd_config` (note the **d**). Hardening basics:
```
PermitRootLogin no
PasswordAuthentication no
Port 2222
```
```bash
sudo sshd -t                       # ★ test config syntax
sudo systemctl restart ssh
```

### Firewall — `ufw`

```bash
sudo ufw status verbose
sudo ufw enable
sudo ufw allow 22/tcp
sudo ufw allow ssh                 # by service name
sudo ufw allow from 192.168.1.0/24
sudo ufw allow from 10.0.0.5 to any port 3306
sudo ufw deny 23
sudo ufw delete allow 80
sudo ufw status numbered
sudo ufw default deny incoming
sudo ufw default allow outgoing
```
> **Allow SSH before enabling ufw on a remote machine**, or you'll lock yourself out.

### Misc

```bash
hostname
hostnamectl                        # ★ full host info
sudo hostnamectl set-hostname web01
nc -zv host 22                     # netcat: port open?
nc -l 1234                         # listen
telnet host 80                     # crude port test
arp -a
ip -s link                         # interface statistics/errors
nmap -sV localhost                 # port scan (apt install nmap)
```

---

## 18. System Information and Logs

### System info

```bash
uname -a             # ★ everything
uname -r             # kernel release ← needed for header packages
uname -m             # architecture (x86_64)
hostnamectl          # hostname, OS, kernel, virtualization
cat /etc/os-release  # ★ distro details
lsb_release -a
uptime               # ★ up-time + load average
uptime -p            # pretty
date                 # current date/time
date +"%Y-%m-%d %H:%M:%S"
date -d "next friday"
timedatectl          # time, timezone, NTP sync
sudo timedatectl set-timezone Africa/Cairo
cal                  # calendar
```

### Hardware

```bash
lscpu                # ★ CPU details
nproc                # core count
lsmem
free -h              # ★ memory
lsblk                # block devices
lspci                # PCI devices (GPU, NIC)
lsusb                # USB devices
lsmod                # loaded kernel modules
sudo dmidecode -t memory     # RAM slots/sticks
sudo lshw -short             # full hardware summary
sensors                      # temperatures (apt install lm-sensors)
```

### Logs

Modern systemd systems use the **journal** (binary, queried with `journalctl`);
some services still write plain text to `/var/log`.

```bash
journalctl                          # everything, oldest first
journalctl -e                       # ★ jump to the end
journalctl -f                       # ★ FOLLOW live
journalctl -n 50                    # last 50 lines
journalctl -r                       # reverse (newest first)

journalctl -u ssh                   # ★ one unit
journalctl -u ssh -f
journalctl -u nginx --since today
journalctl --since "2026-07-26 10:00" --until "2026-07-26 12:00"
journalctl --since "1 hour ago"
journalctl --since yesterday

journalctl -p err                   # ★ priority: emerg alert crit err warning notice info debug
journalctl -p err -b                # errors since this boot
journalctl -b                       # this boot
journalctl -b -1                    # previous boot
journalctl --list-boots
journalctl -k                       # kernel messages only
journalctl _UID=1000
journalctl /usr/bin/sshd
journalctl -o json-pretty           # output formats
journalctl --disk-usage
sudo journalctl --vacuum-size=200M  # ★ shrink the journal
sudo journalctl --vacuum-time=7d
```

Plain-text logs:
```bash
ls -lh /var/log/
sudo tail -f /var/log/syslog        # general system log
sudo tail -f /var/log/auth.log      # ★ logins, sudo, SSH — security
sudo less /var/log/dpkg.log         # package install history
sudo less /var/log/kern.log
dmesg                               # kernel ring buffer
dmesg -T | tail -20                 # -T = human timestamps
dmesg -w                            # follow
sudo grep "Failed password" /var/log/auth.log | tail
```

Log rotation:
```bash
cat /etc/logrotate.conf
ls /etc/logrotate.d/
sudo logrotate -d /etc/logrotate.conf   # -d = debug/dry run
```

---

## 19. Scheduling Tasks

### `cron` — recurring jobs

```bash
crontab -e         # ★ edit MY crontab
crontab -l         # list
crontab -r         # remove all (careful — no confirmation)
sudo crontab -e -u sara
```

**The five fields:**
```
┌───── minute        (0-59)
│ ┌─── hour          (0-23)
│ │ ┌─ day of month  (1-31)
│ │ │ ┌─ month       (1-12)
│ │ │ │ ┌─ day of week (0-7, both 0 and 7 = Sunday)
│ │ │ │ │
* * * * *  command to run
```

```cron
0 2 * * *        /home/akhamees/backup.sh          # daily at 02:00
*/15 * * * *     /usr/local/bin/check.sh           # every 15 minutes
0 */6 * * *      /usr/local/bin/sync.sh            # every 6 hours
30 3 * * 0       /usr/local/bin/weekly.sh          # Sundays at 03:30
0 9 1 * *        /usr/local/bin/monthly.sh         # 1st of month, 09:00
0 9 * * 1-5      /usr/local/bin/workday.sh         # weekdays at 09:00
@reboot          /home/akhamees/startup.sh         # once at boot
@daily / @weekly / @monthly / @yearly / @hourly
```

**Cron gotchas** (these bite everyone once):
1. `PATH` is minimal — **use absolute paths** for every command and script.
2. No interactive environment — `~/.bashrc` is not sourced.
3. `%` must be escaped as `\%` (especially inside `date +%F`).
4. Output is emailed by default; redirect it:
   ```cron
   0 2 * * * /home/akhamees/backup.sh >> /var/log/backup.log 2>&1
   ```
5. Test the script manually first, with `env -i` to simulate the empty environment.

System-wide cron:
```bash
cat /etc/crontab              # note: has an extra USER field before the command
ls /etc/cron.d/
ls /etc/cron.{hourly,daily,weekly,monthly}/
```

### `at` — one-off jobs

```bash
sudo apt install at -y
echo "/home/akhamees/script.sh" | at 14:30
at now + 1 hour
at 09:00 tomorrow
at 4pm friday
atq              # list pending
atrm 3           # remove job 3
```

### systemd timers — the modern alternative

```bash
systemctl list-timers            # ★ all timers + next run time
systemctl list-timers --all
systemctl status logrotate.timer
```

`myjob.timer` next to `myjob.service`:
```ini
[Unit]
Description=Run myjob daily

[Timer]
OnCalendar=daily
Persistent=true          # run on boot if the machine was off at the scheduled time

[Install]
WantedBy=timers.target
```
```bash
sudo systemctl enable --now myjob.timer
systemd-analyze calendar "daily"     # verify a schedule expression
```

Timers beat cron for: dependency ordering, journal-integrated logging, `Persistent=`,
and resource limits.

---

## 20. The Shell Itself (bash)

### Variables

```bash
NAME="Anas"              # ★ no spaces around =
echo $NAME
echo "${NAME}_suffix"    # braces disambiguate
export NAME              # make it visible to child processes
export PATH=$PATH:/opt/bin
unset NAME
readonly PI=3.14
```

**Important environment variables:**
```bash
echo $HOME $USER $SHELL $PATH $PWD $OLDPWD $LANG $EDITOR $HOSTNAME
echo $?      # last exit status
echo $$      # this shell's PID
echo $!      # PID of last background job
echo $0      # name of the shell/script
env          # ★ all environment variables
printenv PATH
set          # all variables incl. shell-local ones
```

**`$PATH`** is a colon-separated list of directories the shell searches, in order:
```bash
echo $PATH | tr ':' '\n'
export PATH="$HOME/bin:$PATH"        # prepend → your bin wins
```
This is why you must type `./script.sh` — `.` is deliberately not in `$PATH`.

### Quoting — the #1 source of bugs

```bash
NAME="Anas"
echo "Hello $NAME"     # Hello Anas     ← double: variables EXPAND
echo 'Hello $NAME'     # Hello $NAME    ← single: everything LITERAL
echo Hello $NAME       # Hello Anas     ← unquoted: expands AND word-splits
echo "Today: $(date)"  # command substitution
echo "Sum: $((2+3))"   # arithmetic
echo "Path: \$HOME"    # backslash escapes
```
> **Rule: quote your variables.** `rm $FILE` breaks on spaces; `rm "$FILE"` doesn't.

### Command substitution

```bash
TODAY=$(date +%F)
echo "Backup-$TODAY.tar.gz"
FILES=$(ls | wc -l)
tar -czf "backup-$(date +%F).tar.gz" /etc
echo "Kernel: $(uname -r)"
```
Prefer `$( )` over backticks — it nests and reads better.

### History

```bash
history
history 20
history | grep ssh
!!                 # ★ repeat last command
sudo !!            # ★ re-run last command with sudo — the classic
!123               # run history entry 123
!ssh               # last command starting with ssh
!$                 # last ARGUMENT of previous command
!^                 # first argument
Ctrl+R             # ★ reverse interactive search — learn this today
^old^new           # re-run last command replacing old with new
history -c         # clear
```
Config: `HISTSIZE`, `HISTFILESIZE`, `HISTCONTROL=ignoreboth` (in `~/.bashrc`).

### Aliases and functions

```bash
alias ll='ls -alF'
alias ..='cd ..'
alias grep='grep --color=auto'
alias update='sudo apt update && sudo apt upgrade -y'
alias                # list all
unalias ll
\ls                  # ★ backslash bypasses an alias

mkcd() { mkdir -p "$1" && cd "$1"; }      # function with an argument
```
Put them in `~/.bashrc` (or `~/.bash_aliases`, which Ubuntu sources for you) to persist.

### Startup files — which one do I edit?

| File | When it runs |
|---|---|
| `/etc/profile` | Login shells, system-wide |
| `/etc/bash.bashrc` | Interactive shells, system-wide |
| `~/.bash_profile` / `~/.profile` | Login shells, per user |
| `~/.bashrc` | **Interactive non-login shells, per user ← put aliases here** |
| `~/.bash_logout` | On logout |

```bash
source ~/.bashrc     # ★ apply changes without logging out
. ~/.bashrc          # same thing
```

### Keyboard shortcuts (worth memorizing today)

| Keys | Action |
|---|---|
| `Tab` | ★ Autocomplete (press twice for all options) |
| `Ctrl+C` | Interrupt the running command |
| `Ctrl+D` | End of input / logout |
| `Ctrl+Z` | Suspend to background |
| `Ctrl+L` | Clear screen (same as `clear`) |
| `Ctrl+A` / `Ctrl+E` | Start / end of line |
| `Ctrl+U` / `Ctrl+K` | Delete to start / end of line |
| `Ctrl+W` | Delete previous word |
| `Ctrl+Y` | Paste what you deleted |
| `Ctrl+R` | ★ Reverse history search |
| `Alt+.` | Insert last argument of previous command |
| `↑` `↓` | History |

### Scripting starter

```bash
#!/bin/bash
# ↑ shebang: which interpreter runs this file
set -euo pipefail    # ★ exit on error, on unset variable, on any pipe failure

echo "Hello, $USER"

# Conditionals
if [ -f /etc/passwd ]; then
    echo "exists"
elif [ -d /etc ]; then
    echo "dir"
else
    echo "neither"
fi

# Loops
for i in {1..5}; do echo "$i"; done
for f in *.txt; do echo "$f"; done
while read -r line; do echo "$line"; done < file.txt

# Arguments: $1 $2 ... $# = count, $@ = all
if [ $# -eq 0 ]; then
    echo "Usage: $0 <arg>" >&2
    exit 1
fi

# Case
case "$1" in
    start) echo "starting" ;;
    stop)  echo "stopping" ;;
    *)     echo "unknown" ; exit 1 ;;
esac
```

**Test operators** (`man test` for the full list):

| Files | | Strings | | Numbers | |
|---|---|---|---|---|---|
| `-f` | is a regular file | `-z` | is empty | `-eq` | equal |
| `-d` | is a directory | `-n` | is non-empty | `-ne` | not equal |
| `-e` | exists | `=` | equal | `-gt` | greater than |
| `-r` `-w` `-x` | readable/writable/executable | `!=` | not equal | `-lt` | less than |
| `-s` | non-empty file | | | `-ge` `-le` | ≥ ≤ |

Run it:
```bash
chmod +x script.sh
./script.sh
bash script.sh          # works even without +x
bash -x script.sh       # ★ trace every line — the debugging flag
bash -n script.sh       # syntax check only
shellcheck script.sh    # ★ linter (apt install shellcheck) — use it always
```

---

## 21. Editors: nano and vim

### `nano` — beginner-friendly

```bash
nano file.txt
nano +25 file.txt     # open at line 25
sudo nano /etc/hosts
```
`^` in the on-screen menu means **Ctrl**:

| Keys | Action |
|---|---|
| `Ctrl+O` | Write out (save), then Enter |
| `Ctrl+X` | Exit |
| `Ctrl+W` | Where is (search) |
| `Ctrl+\` | Replace |
| `Ctrl+K` | Cut line |
| `Ctrl+U` | Paste |
| `Ctrl+G` | Help |
| `Alt+U` | Undo |

### `vim` — everywhere, always installed

Vim is **modal**. `Esc` always returns to Normal mode.

```
NORMAL (Esc)  → navigate & run commands   [the default]
INSERT (i)    → type text
VISUAL (v)    → select text
COMMAND (:)   → save, quit, search/replace
```

```bash
vim file.txt
vimtutor        # ★ 30-minute built-in tutorial — do this once, seriously
```

| Command | Action |
|---|---|
| `i` / `a` / `o` | Insert before / after cursor / new line below |
| `Esc` | Back to Normal |
| `:w` | Save |
| `:q` | Quit |
| `:wq` or `ZZ` | Save and quit |
| `:q!` | ★ Quit, discard changes |
| `:w !sudo tee %` | Save a root-owned file you opened without sudo |
| `h j k l` | Left down up right |
| `gg` / `G` | Top / bottom of file |
| `:42` | Go to line 42 |
| `0` / `$` | Start / end of line |
| `w` / `b` | Next / previous word |
| `dd` / `3dd` | Delete line / 3 lines |
| `yy` / `p` | Copy line / paste |
| `u` / `Ctrl+R` | Undo / redo |
| `/word` `n` `N` | Search, next, previous |
| `:%s/old/new/g` | ★ Replace all in file |
| `:%s/old/new/gc` | Replace all, confirm each |
| `:set nu` | Line numbers |

> **The exit riddle:** stuck in vim? Press `Esc`, then type `:q!` and Enter.

---

## 22. Quick Reference Cheat Sheet

### Navigation & files
```bash
pwd                 ls -lah            cd -              tree -L 2
touch f             mkdir -p a/b/c     cp -r s d         mv a b
rm -rf d            ln -s tgt lnk      file f            stat f
```
### Viewing
```bash
cat f     less f     head -20 f     tail -f f     wc -l f     diff a b
```
### Search
```bash
find / -name "*.conf"          grep -rn "text" dir/
locate file                    which cmd            apropos keyword
```
### Text
```bash
sort f | uniq -c | sort -rn        cut -d: -f1 /etc/passwd
sed -i 's/a/b/g' f                 awk -F: '{print $1}' /etc/passwd
tr 'a-z' 'A-Z'                     xargs -I{} cmd {}
```
### Permissions
```bash
chmod 755 f     chmod u+x f     chown u:g f     umask 022     getfacl f
```
### Users
```bash
sudo adduser u          sudo usermod -aG grp u        sudo passwd u
id u                    groups u                      sudo chage -l u
```
### Processes
```bash
ps aux     top     htop     kill -15 PID     pkill -f name
jobs       bg %1   fg %1    nohup cmd &      free -h      lsof -i :80
```
### Services
```bash
systemctl status|start|stop|restart|enable|disable svc
systemctl --failed        journalctl -u svc -f
```
### Packages
```bash
sudo apt update && sudo apt upgrade      sudo apt install pkg
sudo apt purge pkg      apt search x     dpkg -L pkg     dpkg -S /path
```
### Disks
```bash
df -h     du -sh /var/*     lsblk -f     mount|umount     findmnt
```
### Network
```bash
ip a      ip r      ss -tulnp     ping -c4 h     dig +short d
curl -O url         wget -c url   ssh u@h        scp f u@h:/p
```
### Archives
```bash
tar -czvf a.tar.gz d/       tar -xzvf a.tar.gz -C /tmp
tar -tvf a.tar.gz           rsync -av --dry-run s/ d/
```
### Logs
```bash
journalctl -u svc -f -p err       tail -f /var/log/syslog
dmesg -T | tail                   sudo tail -f /var/log/auth.log
```

### The 10 commands you'll type most as an admin
```bash
ls -lah        cd -           grep -rn        systemctl status
journalctl -u  df -h          du -sh *        ps aux | grep
tail -f        man
```

### Emergency
| Situation | Do this |
|---|---|
| Command hangs | `Ctrl+C` |
| Stuck in vim | `Esc` then `:q!` |
| Stuck in `less`/`man` | `q` |
| Terminal garbled | `reset` or `stty sane` |
| Disk full | `du -sh /var/* \| sort -rh \| head` |
| Service dead | `systemctl status X` then `journalctl -u X -n 50` |
| Forgot sudo | `sudo !!` |
| Can't find a command | `apropos "what it does"` |
| Locked out after fstab edit | Boot recovery → `mount -o remount,rw /` → fix fstab |

---

## 23. Quizzes & Assignments

The practice material lives in separate files so you can work through them without
scrolling this document:

| File | Contents |
|---|---|
| [QUIZZES.md](QUIZZES.md) | 7 quizzes, 100 questions — MCQ, fill-in-the-blank, output prediction, debugging |
| [ASSIGNMENTS.md](ASSIGNMENTS.md) | 10 hands-on labs, from file navigation to a full server setup + a capstone |
| [ANSWERS.md](ANSWERS.md) | Full solutions with explanations — **try first, then check** |

**Suggested order for session 1:**
1. Read sections 0–2 (how Linux works + how to get help).
2. Do **Assignment 1** and **Assignment 2**.
3. Take **Quiz 1** and **Quiz 2**.
4. Read sections 3–9, do Assignments 3–5, take Quizzes 3–4.
5. Continue through the rest at your own pace.

**Study rule:** every time you meet a new command in this document, run
`man <command>` and read at least the NAME, SYNOPSIS, and three OPTIONS entries.
The goal of session 1 is not memorization — it's building the reflex to look things up.

---

## Further Reading

- `man 7 hier` — filesystem hierarchy, straight from the source
- `man 1 bash` — long, but the definitive shell reference
- [The Linux Command Line (free PDF)](https://linuxcommand.org/tlcl.php) — William Shotts
- [ExplainShell.com](https://explainshell.com) — paste any command, get every flag explained
- [ShellCheck.net](https://www.shellcheck.net) — paste a script, get bugs found
- `https://linuxjourney.com` — structured beginner path
- `https://overthewire.org/wargames/bandit/` — learn by CTF-style puzzles