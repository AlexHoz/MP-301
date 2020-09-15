.386
.model flat, stdcall
option casemap:none
include includes\windows.inc
include includes\kernel32.inc
include includes\user32.inc
includelib includes\user32.lib
includelib includes\kernel32.lib
.data

.code
start:

invoke ExitProcess, 0
end start
