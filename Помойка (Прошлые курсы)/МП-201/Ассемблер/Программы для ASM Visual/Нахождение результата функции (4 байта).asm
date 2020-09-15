.386
.model flat, stdcall
option casemap:none
include includes\windows.inc
include includes\kernel32.inc
include includes\user32.inc
includelib includes\user32.lib
includelib includes\kernel32.lib

.data
X dd 15000
Y dd 3768
Z DD 0
str_format DB "(x * y) / (x + y) = %d", 0
str_buffer DB 256 dup (0)
mb_title DB "Result", 0

.code
start:
	; Помещаем сумму x и y в ecx
	mov ecx, [X]
	add ecx, [Y]
	
	; Помещаем произведение x и y в eax
	mov eax, [X]
	imul [Y]
	
	; Делим eax на ecx
	idiv ecx
	
	; Выводим результат в диалоговое окно
	mov [Z], eax
	invoke wsprintf, ADDR str_buffer, ADDR str_format, [Z]
	invoke MessageBox, 0, offset str_buffer, offset mb_title, MB_OK
	invoke ExitProcess, 0
end start
