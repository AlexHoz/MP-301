LXI H, 0x0025 ; Записываем в H место хранения числа
MOV B, M ; Читаем в B число, взятое из памяти

MVI A, 1 ; Кладем в A единицу

ANA B ; Выполняем побитовое сравнение с единицей
INX H ; Увеличиваем адрес на единицу

JNZ ODD ; При Z не равном 0
JZ EVEN ; При Z равном 0

EVEN:
DCR B ; Пришло четное число, следовательно, уменьшаем на единицу
CALL PRINT ; Вызываем функцию Print

ODD:
DCR B ; Пришло нечетное число, следовательно, нужно вывести следующее нечетное
DCR B
CALL PRINT

PRINT:
MOV M, B ; Записываем в память значение из B

INX H ; Увеличиваем адрес на единицу

DCR B ; Уменьшаем B на 2
DCR B

JM END ; Так как последнее нечетное число - это 1, то делаем проверку на (1 - 2) - отрицательное число,
JNZ PRINT

END:
HLT
