.686
.model flat, c
public funcName
.data
num1 dd 100
num2 dd 22
num3 dd 31
.code
extrn funcName1 : proc;
funcName proc
mov eax, num3
push eax
mov eax, num2
push eax
mov eax, num1
push eax
call funcName1
pop ebx
pop ebx
pop ebx
ret
funcName endp
end
