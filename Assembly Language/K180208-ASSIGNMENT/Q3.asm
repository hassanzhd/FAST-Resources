include C:\Irvine\Irvine32.inc
includelib C:\Irvine\Irvine32.Lib
includelib C:\Irvine\Kernel32.Lib
includelib C:\Irvine\User32.Lib

.data 
temp1 DWORD 1
temp2 DWORD 1
multiplier DWORD 2
space DWORD 32

.code 
main proc
mov edx, 0
mov ecx, 5 ; 5 levels
mov esi,1
call makePattern
call crlf

exit
main endp

makePattern proc
push ebp
mov ebp, esp
cmp ecx, 0
je return

mov ebx, ecx
mov eax, space

printSpaces:
call writechar
loop printSpaces

mov ecx, temp2 

printInt:
mov eax, temp1
call writedec
mul multiplier
mov temp1, eax
mov eax, space
call writechar
loop printInt

mov ecx, ebx
dec ecx
add temp2, 2 ; odd iterations 
call crlf
call makePattern
jmp return

return:
pop ebp
ret 
makePattern endp

end main
