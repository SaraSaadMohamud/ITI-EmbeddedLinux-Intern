#!/bin/bash

# Functions 
function Date() {
    echo "Date : $(date)"
}

function Uptime() {
    echo "Uptime: $(uptime)"
}

function LoggedUser() {
    echo "Logged User:  $(who)"
}

function  CurrentDirectory() {
    echo "Current Directoy: $(pwd)"
}

function ShowingDiskUsage() {
    echo "Disk Usage $(df -h)"
}

function ShowMemoryUsage() {
    echo "Memory USage: $(free -h)" 
}

function FileList() {
    echo "Files: $(ls -la)" 
}

function Exit() {
    exit 0
}

while [ 1 ]; do

    counter=1
    echo "================================================"
    echo "                  Linux ToolKit                 "
    echo "================================================"
    echo "1) Show Date"
    echo "2) UpTime"
    echo "3) Show Logged USer"
    echo "4) Show Current Directory"
    echo "5) Show Disk Usage"
    echo "6) Show Memory Usage"
    echo "7) File List"
    echo "8) Exit"

    while [ $counter -le 3 ]; do
        read -p "Enter Your Choice: " choice
        if [ $choice -gt 8 ] || [ $choice -lt 1 ]; then
            echo "Invalid Input!"
            counter=$((counter+1))
            continue
        fi
        break
    done

    if [ $counter -gt 3 ]; then
        echo "Too many invalid attempts."
        exit 0
    fi
    case $choice in 
        1)
            Date
        ;;
        2)
            Uptime
        ;;
        3)
            LoggedUser
        ;;
        4)
            CurrentDirectory
        ;;
        5)
            ShowingDiskUsage
        ;;

        6)
            ShowMemoryUsage
        ;;
        7)
            FileList
        ;;

        8)
            Exit
        ;;
    esac
done