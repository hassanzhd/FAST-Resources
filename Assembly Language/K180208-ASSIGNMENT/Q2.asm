include C:\Irvine\Irvine32.inc
includelib C:\Irvine\Irvine32.Lib
includelib C:\Irvine\Kernel32.Lib
includelib C:\Irvine\User32.Lib

.data 
array1 SWORD 20 DUP(?)
result sword 0
str1 BYTE "SUM OF RANDOM ODD NUMBERS ARE: ", 0
str2 BYTE "RANDOM NUMBER: ", 0

.code 
main proc

mov ebx, offset array1
mov ecx, 20
call randomize

fillArray:
mov eax , 99
call randomrange
sub eax, 50
mov [ebx] , eax
add ebx, 2
loop fillArray

mov ecx, lengthof array1
mov esi,0

print:
movsx eax, [array1[esi]]
add esi, 2
mov edx, offset str2
call writestring
call writeint
call crlf 
loop print

mov ecx, lengthof array1
mov eax, 0
mov ebx, 0
mov edx, 0
mov esi, 0
mov edi, 0
mov bl, 2

call oddSum
mov edx, OFFSET str1
call crlf
call writestring
call writeint
call crlf

exit
main endp

oddSum proc 
push ebp
mov ebp, esp
cmp ecx, 0
jz  return
jg  check

check:
mov ax, [array1[esi]]
cmp ax, 49
jg range
cmp ax, -50
jl range
idiv bl
cmp ah, 0
jne getOdd

range:
dec ecx
add esi, 2
call oddSum
jmp return

getOdd:
mov ax, [array1[esi]]
add result, ax
add esi, 2
dec ecx
call oddSum

return:
mov eax, 0
movsx eax, result
pop ebp
ret
oddSum endp

end main
