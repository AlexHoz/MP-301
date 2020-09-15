.386
.model flat, stdcall
option casemap :none
include includes\masm32.inc
include includes\kernel32.inc
include includes\macros\macros.asm
includelib includes\masm32.lib
includelib includes\kernel32.lib

ArrayMin proto :DWORD, :DWORD

.data

MyArray db 15, 29, 8, 3, 7 ; Массив чисел, размером в 1 байт

.code
start:
	invoke ArrayMin, offset MyArray, 5d
	invoke ExitProcess, 0
	
ArraySum proc a:DWORD, b:DWORD
	mov ebx, a
	mov ecx, b
	mov eax, 0 ; Обнуляем EAX
	mov edx, 0 ; Обнуляем EDX
	mov al, [ebx+ecx-1]
Min:
	mov dl, [ebx+ecx-1] ; Записываем в однобайтовый регистр DL значение массива
	cmp eax, edx ; Сравниваем
	jna NEXT
	mov eax, edx ; Складываем значение регистров
	NEXT:
		loop Min ; Запускаем цикл
ret 
ArrayMin endp 

end start	
