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

MyArray1 db 15, 29, 8, 2 ; Массив чисел, размером в 1 байт

.code
start:
	invoke ArrayMin, offset MyArray, 5d
	mov ebx, eax
	invoke ArrayMin, offset MyArray1, 4d
	add ebx, eax
	invoke ExitProcess, 0
	
ArrayMin proc a:DWORD, b:DWORD
	PUSH ecx
	PUSH ebx
	PUSH edx
	mov ebx, a
	mov ecx, b
	mov eax, 0 ; Обнуляем EAX
	mov edx, 0 ; Обнуляем EDX
	mov al, [ebx+ecx-1]
Min:
	mov dl, [ebx+ecx-1] ; Записываем в однобайтовый регистр DL значение массива
	cmp eax, edx ;Cравнение
	jna NEXT
	mov eax, edx ; Складываем значение двух 4 байтовых регистров
	NEXT:
		loop Min ; Запускаем цикл
	POP edx
	POP ebx
	POP ecx
ret 
ArrayMin endp 

end start	
