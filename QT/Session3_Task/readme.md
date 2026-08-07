#  Smart Home Control Dashboard

A front-end **Smart Home Control Dashboard** built with **Qt Quick (QML + JavaScript)**.

This is a **UI/front-end simulation only** — there is no real backend, no C++ device logic, and no actual hardware connection. All device states, login, and settings behavior are simulated using QML properties, `console.log`, and `Timer`.

---

##  Project Overview

The project simulates a simple smart home control panel with three screens:

1. **Login Page** – simulated authentication with a loading delay.
2. **Dashboard Page** – a list of smart devices with ON/OFF switches and usage bars.
3. **Settings Page** – application preferences (language, brightness, temperature, notifications).

Navigation between these three pages is handled with a single `StackView` hosted inside `Main.qml`, the application's entry point (loaded by `main.cpp`).

---

##  Project Features

Based strictly on what is implemented in the provided `.qml` files:

- **Simulated Login** with username/password validation (non-empty check only — no real authentication)
- **Loading state simulation** using a `Timer` and `BusyIndicator`
- **Exit button** that closes the application (`Qt.quit()`)
- **Device list** rendered from a `ListModel` (5 predefined devices)
- **Custom-styled ON/OFF switches** for each device (state is local to the delegate, logged to console)
- **Custom-styled usage progress bars** per device
- **Settings screen** with:
  - Language selection (`ComboBox`)
  - Brightness control (`Slider`)
  - Room temperature control (`Dial`)
  - Notification toggle (`CheckBox`)
  - "Save Settings" button that logs all current values to the console (simulation only — nothing is persisted)
- **Page navigation** via `StackView` (`push()` / `pop()`)
- **Logout** button that pops back to the Login page
- Consistent color theme across all pages

---


## 🎥 Demo Video

 **[Watch the Smart Home Control Dashboard Demo](https://drive.google.com/drive/folders/1G8ECsHfv8yyApcDIvTp57noQU3CuPf-m)**

The demo video showcases the application's main features, UI navigation, smart-home controls, and English / Arabic / French runtime localization.

## Technologies Used

| Technology | Usage |
|---|---|
| QML | Building the user interface |
| JavaScript | Logic and simulation (inside signal handlers) |
| Qt Quick | Core declarative UI framework |
| Qt Quick Controls | Buttons, TextFields, Switches, Sliders, etc. |
| Qt Quick Layouts | Arranging UI elements (`ColumnLayout`, `RowLayout`) |
| StackView | Page navigation between Login / Dashboard / Settings |
| ListModel / ListView | Storing and displaying smart devices |
| ScrollView | Scrollable device list |
| Timer | Simulating login delay |
| Console (`console.log`) | Simulating backend operations |

---

## 📂 Project Structure

```text
SmartHomeDashboard/
│
├── Main.qml              # Application entry point (StackView host)
│
├── LoginPage.qml          # Login screen
├── DashboardPage.qml      # Device dashboard screen
├── SettingsPage.qml       # Application settings screen
│
├── images/
│   ├── user.png
│   ├── light.png
│   ├── bedroom_light.png
│   ├── air_conditioner.png
│   ├── fan.png
│   └── garage_door.png
│
├── main.cpp
└── CMakeLists.txt
```

---

##  How to Build and Run the Project

### Requirements

- Qt 6.x with **Qt Quick**, **Qt Quick Controls**, and **Qt Quick Layouts** modules
- Qt Creator (recommended) or CMake + a Qt-compatible compiler toolchain

### Steps (Qt Creator)

1. Open **Qt Creator**.
2. Select **File → Open File or Project…** and choose `CMakeLists.txt`.
3. Configure the project with a Qt 6 kit.
4. Click **Run** (▶) to build and launch the application.

### Steps (Command Line)

```bash
mkdir build
cd build
cmake ..
cmake --build .
./Session3_Task
```

> The executable name comes from the module name used in `main.cpp`:
> `engine.loadFromModule("Session3_Task", "Main");`

---

##  Application Flow / Navigation

```text
┌───────────────┐   loginSuccessful()   ┌─────────────────┐
│  LoginPage    │ ─────────────────────▶ │  DashboardPage   │
└───────────────┘                        └─────────────────┘
                                                 │      ▲
                                     push("Settings")  │ pop()
                                                 ▼      │
                                          ┌─────────────────┐
                                          │  SettingsPage    │
                                          └─────────────────┘
```

- **Login → Dashboard**: `LoginPage` emits `loginSuccessful()` after a simulated 2-second delay; `Main.qml` listens for this signal and pushes `DashboardPage.qml` onto the `StackView`.
- **Dashboard → Settings**: The **Settings** button calls `stackView.push("SettingsPage.qml", { stackView: dashboardPage.stackView })`.
- **Settings → Dashboard**: The **Back to Dashboard** button calls `stackView.pop()`.
- **Dashboard → Login (Logout)**: The **Logout** button calls `stackView.pop()`, returning to whatever is beneath it on the stack (`LoginPage`, assuming `Main.qml` initialized the stack with `LoginPage` as the base).
- **Exit**: The **Exit** button on the Login page calls `Qt.quit()`, closing the app entirely.

---

## Detailed Explanation of Each QML File

### 1. `Main.qml`

```qml
import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic

ApplicationWindow {
    id: window
    width: 1000
    height: 700
    visible: true
    color: "#F4F7FB"
    title: qsTr("Smart Home Control Dash Board")

    StackView {
        id: stackview_id
        anchors.fill: parent
        initialItem: LoginPage {
            id: loginPage
            onLoginSuccessful: {
                stackview_id.push(
                    "DashboardPage.qml",
                    {
                        stackView: stackview_id
                    }
                )
            }
        }
    }
}
```

This is the application's root component and its responsibilities are:
- Create the top-level `ApplicationWindow` (1000×700, background `#F4F7FB`, window title *"Smart Home Control Dash Board"*)
- Host the single `StackView` (`stackview_id`) used for navigation across the whole app, anchored to fill the window
- Set `LoginPage` as the `initialItem` of the `StackView` — this is the base of the navigation stack, and what the **Logout** button returns to
- Listen for `LoginPage`'s `onLoginSuccessful` signal handler and respond by calling `stackview_id.push("DashboardPage.qml", { stackView: stackview_id })`, which both navigates to the Dashboard **and** hands it the `stackView` reference it needs to navigate further (to Settings, or back via Logout)

### 2. `LoginPage.qml`

- A `Page` with a light background (`#F4F7FB`).
- Centered `ColumnLayout` containing:
  - App logo `Image`
  - Title (`"Smart Home"`) and subtitle (`"Control Dashboard"`) labels
  - `TextField` for username, `TextField` for password (`echoMode: TextInput.Password`)
  - `errorLabel` for validation feedback
  - `loginButton` — validates that both fields are non-empty, then starts `loginTimer`
  - `exitButton` — calls `Qt.quit()`
  - `BusyIndicator` — visible only while `isLoading` is `true`
  - `loginTimer` — a 2-second, non-repeating `Timer` that ends the loading state and emits `loginSuccessful()`

### 3. `DashboardPage.qml`

- A `Page` that receives `property StackView stackView` from whoever pushes it.
- Declares a local `ListModel` (`devicesModel`) with 5 devices, each with `name`, `image`, `status`, and `usage`.
- Top `RowLayout`: dashboard title, **Settings** button (pushes `SettingsPage.qml`), **Logout** button (pops the stack).
- `ScrollView` containing a `ListView` (`devicesList`) bound to `devicesModel`.
- Each row is rendered by a **delegate**: a white rounded `Rectangle` containing the device image, name, a custom `ProgressBar` showing usage, and a custom `Switch` with an "ON"/"OFF" `Label` beneath it.

### 4. `SettingsPage.qml`

- A `Page` that also receives `property StackView stackView`.
- Centered `ColumnLayout` containing:
  - `ComboBox` for language selection
  - `Slider` for screen brightness (0–100)
  - `Dial` for room temperature (16–35 °C)
  - `CheckBox` for enabling/disabling notifications
  - **Save Settings** button — logs all current values to the console (no persistence/backend)
  - **Back to Dashboard** button — calls `stackView.pop()`

---

##  Qt/QML Components Used

| Component | Role in this project |
|---|---|
| `ApplicationWindow` | Top-level window of the app (expected in `Main.qml`) |
| `Page` | Root container for each screen (Login, Dashboard, Settings) — provides a `header`/`background`/content area |
| `StackView` | Manages navigation history between pages, like a stack of screens |
| `ColumnLayout` | Arranges children vertically with consistent spacing |
| `RowLayout` | Arranges children horizontally (e.g., dashboard header buttons) |
| `ListModel` | Holds the static list of smart devices (`devicesModel`) |
| `ListView` | Renders the `ListModel` as a scrollable list of rows |
| **delegate** | The template (a `Rectangle`) used to visually render each item in `devicesModel` |
| `Rectangle` | Used for backgrounds, custom control styling, and device cards |
| `Image` | Displays the logo and device icons |
| `Label` | Displays static or bound text (titles, values, status) |
| `TextField` | Username and password input fields |
| `Button` | Login, Exit, Settings, Logout, Save, Back — all use custom `contentItem`/`background` |
| `Switch` | Toggles each device ON/OFF on the dashboard |
| `ProgressBar` | Shows each device's simulated usage percentage |
| `ScrollView` | Makes the device list scrollable when it overflows the page |
| `ComboBox` | Language selector in Settings |
| `Slider` | Brightness control in Settings |
| `Dial` | Temperature control in Settings |
| `CheckBox` | Notification toggle in Settings |
| `BusyIndicator` | Spinner shown while `isLoading` is `true` on the Login page |
| `Timer` | Simulates a network/login delay before emitting `loginSuccessful()` |

---

##  Important QML Concepts Used

### `id`
Gives an object a name so it can be referenced elsewhere in the same file.
```qml
TextField {
    id: userNameFeild
}
```

### `property`
Declares custom data on an object — used here to hold state and pass data between pages.
```qml
property bool isLoading: false
property StackView stackView
```

### `signal`
Declares a custom event that a component can emit.
```qml
signal loginSuccessful()
```

### signal handler
The automatically generated `on<SignalName>` handler used to react to a signal.
```qml
LoginPage {
    onLoginSuccessful: {
        stackView.push("DashboardPage.qml")
    }
}
```

### `onClicked`
Built-in signal handler fired when a `Button`/`MouseArea` is clicked.
```qml
onClicked: {
    console.log("Application closed")
    Qt.quit()
}
```

### `onToggled`
Built-in signal handler fired when a `Switch` changes state.
```qml
onToggled: {
    console.log(model.name + " is now " + (checked ? "ON" : "OFF"))
}
```

### `onTriggered`
Built-in signal handler fired when a `Timer` reaches its interval.
```qml
Timer {
    id: loginTimer
    interval: 2000
    onTriggered: {
        loginPage.isLoading = false
        loginPage.loginSuccessful()
    }
}
```

### Bindings
An expression assigned to a property that automatically re-evaluates whenever the values it depends on change.
```qml
Label {
    text: "Screen Brightness: " + Math.round(brightnessSlider.value) + "%"
}
```
Here, the `Label`'s text updates automatically every time `brightnessSlider.value` changes — no manual update code required.

### `model` / `delegate`
`model` supplies the data (`devicesModel`); `delegate` is the visual template instantiated once per item in that data.
```qml
ListView {
    model: devicesModel
    delegate: Rectangle {
        // one row per device
    }
}
```

### StackView navigation — `push()` / `pop()` / `replace()`
- **`push(item, properties)`** — adds a new page on top of the stack and displays it.
  ```qml
  stackView.push("SettingsPage.qml", { stackView: dashboardPage.stackView })
  ```
- **`pop()`** — removes the current top page and reveals the one beneath it.
  ```qml
  stackView.pop()
  ```
- **`replace(item)`** — swaps the current top page for a new one without keeping the old one in history (not used in this project, but useful e.g. to prevent going "back" into a logged-out session).

### Anchors
A layout system for positioning an item relative to its parent or siblings.
```qml
background: Rectangle {
    anchors.fill: parent
}
```

### Layouts
`ColumnLayout` and `RowLayout` (from `QtQuick.Layouts`) automatically position and space children, using `Layout.fillWidth`, `Layout.alignment`, etc., instead of manual anchoring.

### Conditional expressions
Inline `if`/ternary logic used inside bindings to pick colors or text based on state.
```qml
color: {
    if (!loginButton.enabled)
        return "#D1D5DB"
    if (loginButton.pressed)
        return "#007A9E"
    if (loginButton.hovered)
        return "#008FB8"
    return "#00A6D6"
}
```

---

## 🔗 How `LoginPage` Communicates with `Main.qml`

`LoginPage.qml` never navigates by itself — it has no knowledge of the `StackView`. Instead, it exposes a custom signal:

```qml
signal loginSuccessful()
```

which is emitted once `loginTimer` finishes:

```qml
onTriggered: {
    loginPage.isLoading = false
    loginPage.loginSuccessful()
}
```

`Main.qml` is responsible for listening to this signal (because it is the parent that instantiates `LoginPage` as the `initialItem` of the `StackView`) and reacting to it by pushing `DashboardPage.qml`:

```qml
initialItem: LoginPage {
    id: loginPage
    onLoginSuccessful: {
        stackview_id.push(
            "DashboardPage.qml",
            { stackView: stackview_id }
        )
    }
}
```

This is a common QML pattern: **child pages emit signals describing "what happened"; the parent decides "what to do about it."** `LoginPage` stays reusable and doesn't need to know anything about navigation.

---

##  How `StackView` Is Passed Between Pages

`DashboardPage` and `SettingsPage` do not create their own `StackView` — they each declare:

```qml
property StackView stackView
```

This is an empty "slot" that must be filled in by whoever pushes the page. It's first filled by `Main.qml`, which passes its `stackview_id` in when pushing `DashboardPage.qml`:
```qml
stackview_id.push("DashboardPage.qml", { stackView: stackview_id })
```
From there, `DashboardPage` passes that same reference along whenever it pushes `SettingsPage.qml`, e.g. from the Dashboard's Settings button:

```qml
onClicked: {
    if (dashboardPage.stackView) {
        dashboardPage.stackView.push(
            "SettingsPage.qml",
            { stackView: dashboardPage.stackView }
        )
    } else {
        console.log("ERROR: StackView reference is missing")
    }
}
```

The same `stackView` reference is passed along every time a new page is pushed, so every page in the chain keeps access to the same single `StackView` instance and can call `push()` / `pop()` on it.

---

## Settings Navigation and the "Back to Dashboard" Button

The **Settings** button on `DashboardPage` pushes `SettingsPage.qml` onto the stack, passing its own `stackView` reference along:
```qml
dashboardPage.stackView.push("SettingsPage.qml", { stackView: dashboardPage.stackView })
```

The **Back to Dashboard** button on `SettingsPage` simply pops the stack:
```qml
onClicked: {
    if (settingsPage.stackView) {
        settingsPage.stackView.pop()
    } else {
        console.log("ERROR: StackView reference is missing")
    }
}
```
Since `SettingsPage` was pushed *on top of* `DashboardPage`, `pop()` removes it and reveals the Dashboard again underneath — no need to manually recreate or reference the Dashboard.

---

## Logout Functionality

The **Logout** button on `DashboardPage` also just calls:
```qml
onClicked: {
    console.log("Logging out")
    if (dashboardPage.stackView) {
        dashboardPage.stackView.pop()
    }
}
```
This works because of how the stack was built: `LoginPage` is expected to be the `initialItem` (the base of the stack) in `Main.qml`, and `DashboardPage` was pushed on top of it after a successful login. Calling `pop()` from the Dashboard therefore removes it and reveals `LoginPage` underneath — effectively "logging out" without any real session/auth logic.

---

## The Device `Switch` and Its ON/OFF State

Each row in the device list contains a `Switch`:
```qml
Switch {
    id: deviceSwitch
    checked: model.status

    onToggled: {
        console.log(model.name + " is now " + (checked ? "ON" : "OFF"))
    }
}
```
- `checked: model.status` initializes the switch from the device's stored status in `devicesModel`.
- `onToggled` fires whenever the user flips the switch, and simply logs the new state — it does **not** write the new value back into `devicesModel` (i.e. `model.status = checked` is not called). This means the visible `Switch` state is correct while the app is running, but the underlying model data doesn't stay in sync if the delegate were ever recreated.
- A `Label` beneath the switch mirrors its state:
  ```qml
  text: deviceSwitch.checked ? "ON" : "OFF"
  color: deviceSwitch.checked ? "#00A6D6" : "#6B7280"
  ```

---

## Customized `ProgressBar` and `Switch` Styling

Both controls override their default look using the `background` / `contentItem` / `indicator` properties, which is the standard way to restyle Qt Quick Controls.

**ProgressBar** — the `background` draws a light gray track; the `contentItem` draws a colored fill whose width is driven by `visualPosition` (a value from 0–1 representing how "full" the bar is):
```qml
contentItem: Item {
    Rectangle {
        width: usageBar.visualPosition * parent.width
        height: parent.height
        radius: 4
        color: "#00B4D8"
    }
}
```

**Switch** — the `indicator` is a rounded `Rectangle` "track" that changes color based on `checked`, containing a smaller white circular "handle" `Rectangle` whose `x` position slides left/right depending on state:
```qml
indicator: Rectangle {
    color: deviceSwitch.checked ? "#00A6D6" : "#D1D5DB"

    Rectangle {
        x: deviceSwitch.checked ? parent.width - width - 3 : 3
        color: "white"
    }
}
```
This is a common QML pattern: instead of a hard state change, the `x` binding automatically animates-ready position changes purely through property bindings.

---

## Colors / Theme

| Color | Hex | Usage |
|---|---|---|
| Background | `#F4F7FB` | Page backgrounds across all screens |
| Primary accent | `#00A6D6` | Buttons, active switches, subtitle text, focus accents |
| Primary hover | `#008FB8` | Button hover state |
| Primary pressed | `#007A9E` | Button pressed state |
| Danger / error | `#DC2626` | Error labels, logout button pressed state |
| Danger hover | `#EF4444` | Logout/Exit button default state |
| Danger dark | `#991B1B` | Logout/Exit button pressed state |
| Disabled | `#D1D5DB` | Disabled button background, inactive switch track |
| Text (dark) | `#1F2937` | Primary text, field text |
| Text (muted) | `#6B7280` / `#9CA3AF` | Secondary text, placeholders, "OFF" label |
| Progress fill | `#00B4D8` | Usage `ProgressBar` fill |

The palette is consistent across `LoginPage`, `DashboardPage`, and `SettingsPage`, giving the app a cohesive, modern look built entirely from custom-styled controls rather than default Qt Quick Controls styling.

---

## What I Learned

This project was a practical exercise in core Qt Quick / QML concepts:

- Structuring a multi-screen app with **`Page`** and a single shared **`StackView`**
- Passing data between screens using **custom `property` declarations** (`property StackView stackView`)
- Communicating "upward" from a child to a parent using **custom `signal`s** (`loginSuccessful()`) instead of tight coupling
- Building responsive layouts with **`ColumnLayout`** and **`RowLayout`** instead of manual anchoring
- Displaying dynamic lists of data with **`ListModel` + `ListView` + delegate**
- Fully **restyling Qt Quick Controls** (`Button`, `Switch`, `ProgressBar`, `ComboBox`, `Slider`, `Dial`, `CheckBox`) via `background`, `contentItem`, and `indicator`
- Using **property bindings** so the UI updates automatically without manual "update" calls
- Simulating asynchronous behavior (like a login request) using **`Timer`**
- Using **conditional expressions inside bindings** to drive dynamic colors/text based on component state (`pressed`, `hovered`, `enabled`, `checked`)

---

## Future Improvements

- Implement a real `Main.qml` if not already present, wiring `LoginPage → DashboardPage` via `loginSuccessful()`
- Persist device switch state back into `devicesModel` (`model.status = checked` in `onToggled`)
- Replace simulated login validation with real authentication (backend or local credential store)
- Persist Settings values (language, brightness, temperature, notifications) using `Qt.labs.settings` or a backend
- Add real device communication (MQTT, REST API, or a C++ backend) instead of `console.log` simulation
- Add animations (`Behavior on x`, `NumberAnimation`) to the Switch handle and ProgressBar fill for smoother transitions
- Add unit/UI tests using `Qt Quick Test`
- Add input validation feedback (e.g., shake animation) on the Login page
- Localize the UI based on the selected language in Settings instead of just logging it