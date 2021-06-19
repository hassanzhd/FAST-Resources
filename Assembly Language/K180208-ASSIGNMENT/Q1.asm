include C:\Irvine\Irvine32.inc
includelib C:\Irvine\Irvine32.Lib
includelib C:\Irvine\Kernel32.Lib
includelib C:\Irvine\User32.Lib
.data 
dividend sbyte -20

.code 
main proc
mov eax,0
mov al, dividend

mov bl,+2
idiv bl
call dumpregs
movsx eax,al
call writeInt
call crlf

mov eax,0
mov al,dividend
cbw
mov bl,+2
idiv bl
call dumpregs
movsx eax,al
call writeInt

exit
main endp

end main
