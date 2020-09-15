.386
.model flat, stdcall
option casemap:none
include includes\windows.inc
include includes\kernel32.inc
include includes\user32.inc
includelib includes\user32.lib
includelib includes\kernel32.lib

.data
X DB 19
Y DB 12
Z DB 0
str_format DB "(x * y) / (x + y) = %d",0
str_buffer DB 256 dup (0)
mb_title DB "Result", 0

.code
start:
	; Помещаем сумму x и y в ecx
	mov eax, 0
	mov ecx, 0
	mov cl, [X]
	add cl, [Y]
	
	; Помещаем произведение x и y в eax
	mov al, [X]
	imul [Y]
	
	; Делим eax на ecx
	idiv cl
  
	; Выводим результат в диалоговое окно
	mov [Z], al
	invoke wsprintf, ADDR str_buffer, ADDR str_format, [Z]
	invoke MessageBox, 0, offset str_buffer, offset mb_title, MB_OK
	invoke ExitProcess, 0
end start
