@ echo off
:1
echo good
gen.exe > input.txt
wa.exe < input.txt > out1.txt
tl.exe < input.txt > out2.txt
fc /L out1.txt out2.txt 
if %errorlevel% == 0 goto 1
echo NeSovpalo
pause