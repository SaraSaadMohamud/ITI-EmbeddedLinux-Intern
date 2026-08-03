#!/bin/bash

read -s -p "Enter Password: " password

if [ ${#password} -ge 8 ]; then
    length="OK"
else
    length="Missing"
fi
####################################################################################################

if [[ "$password" =~ [A-Z] ]]; then
    upper_case="OK"
else
    upper_case="NO"
fi
####################################################################################################

if [[ "$password" =~ [a-z] ]]; then
    lower_case="OK"
else
    lower_case="NO"
fi
####################################################################################################

if [[ "$password" =~ [0-9] ]]; then
    digit="OK"
else
    digit="NO"
fi
####################################################################################################

if [[ "$password" =~ [\!\@\#\$\&\%] ]]; then
    special_cherecter="OK"
else
    special_cherecter="NO"
fi
####################################################################################################

if [[ $length == "OK" && $upper_case == "OK" && $lower_case == "OK" && $digit == "OK" && $special_cherecter == "OK" ]]; then
    overall="Strong"
else
    overall="Weak"
fi
####################################################################################################
echo
echo "======================================================="
echo "Password Strength Report"
echo
echo "Length            : $length"
echo "UpperCase         : $upper_case"
echo "LowerCase         : $lower_case"
echo "Digit             : $digit"
echo "Special Character : $special_cherecter"
echo
echo "Overall : $overall"
echo "======================================================="
####################################################################################################
