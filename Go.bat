if .%USERDOMAIN% == .MYLAPTOP goto :savasPC
Rem MIF kompiuteris
path C:\PROGRA~2\Dev-Cpp\MinGW64\bin\;%path
mingw32-make.exe
goto :toliau

:savasPC
make -f MakeFile

:toliau
partitionTest.exe input.txt > partitionTest.txt