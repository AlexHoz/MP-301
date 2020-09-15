.386
.model flat, stdcall
option casemap:none
include includes\windows.inc
include includes\kernel32.inc
include includes\user32.inc
includelib includes\user32.lib
includelib includes\kernel32.lib
.data

N dd 5
int_one DD  0
int_two DD  0
str_format  DB  "int_one = %d",0
str_buffer  DB  256 dup (0)
mb_title DB "tmp", 0

.code
start:
	mov edx, [N]
	mov edi, 1
	call MyFunc
	invoke ExitProcess, 0
	
	MyFunc proc
		push edx
		dec edx
		jz exit
		call MyFunc
		exit: 
			pop edx
			imul edi, edx
			mov [int_one], edi
			invoke  wsprintf,ADDR str_buffer, ADDR str_format,[int_one]
			invoke MessageBox, 0, offset str_buffer, offset mb_title, MB_OK
			ret
	MyFunc endp
end start
