.386
.model flat, stdcall
option casemap :none
include includes\masm32.inc
include includes\kernel32.inc
include includes\macros\macros.asm
includelib includes\masm32.lib
includelib includes\kernel32.lib
.data

N dd 5d

.code
start:
	mov eax, 1 ;Записываем 1 в регистр eax
	mov edx, [N] ;Записываем 5 в регистр edx
	call MyFunc ;Вызываем процедуру Factorial
	invoke ExitProcess, 0
	
	MyFunc proc ;Процедура Factorial
		PUSH edx ;Копируем значение edx в стек
		dec edx ;Уменьшаем значение регистра eax на 1
		jz stop ;Проверяем, стало ли значение eax равно нулю
		call MyFunc
		stop:
			POP edx ;Извлекаем в регистр eax значение из вершины стека
			mul edx ;Умножаем значение edx на значение eax и записываем в eax
			ret ;Выходим из подпрограммы
	MyFunc endp
end start
