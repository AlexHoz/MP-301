LXI H, 0x001A
MOV B, M
MVI A, 1
ANA B
INX H
JNZ ODD
JZ EVEN

EVEN:
MVI M, 1
HLT

ODD:
MVI M, 2
HLT

HLT
