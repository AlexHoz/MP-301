.386
.model flat, stdcall
option casemap :none
include includes\masm32.inc
include includes\kernel32.inc
include includes\macros\macros.asm
includelib includes\masm32.lib
includelib includes\kernel32.lib

ArraySum proto :DWORD, :DWORD

.data

MyArray db 5,2,1,4,3

.code
start:
	invoke ArraySum, offset MyArray, 5d
	invoke ExitProcess, 0
	
ArraySum proc a:DWORD, b:DWORD
	mov ebx, a
	mov ecx, b
	mov eax, 0 ; Обнуляем EAX
	mov edx, 0 ; Обнуляем EDX
Sum:
	add dl, [ebx+ecx-1] ; Записываем значение массива
	mov eax, edx ; Складываем значение регистров
	loop Sum
ret 
ArraySum endp 
end start
