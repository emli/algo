@echo off
:t
gen.exe > input.txt
wa.exe || exit
echo ok
goto t
pause