#!/bin/bash

read -p "Enter Number1: " number1
read -p "Enter Number1: " number2

sum=$((number1+number2))
difference=$((number1-number2))
Multiplication=$((number1*number2))
division=$((number1/number2))
modules=$((number1%number2))

echo "Sum = $sum"
echo "Difference = $difference"
echo "Multiplication = $Multiplication"
echo "Division = $division"
echo "Modules = $modules"