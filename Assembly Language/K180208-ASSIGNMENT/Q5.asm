include C:\Irvine\Irvine32.inc
includelib C:\Irvine\Irvine32.Lib
includelib C:\Irvine\Kernel32.Lib
includelib C:\Irvine\User32.Lib
.data 
numbers byte 24 dup(?)
rs = 6
prompt1 byte "rows",0
prompt2 byte "col ",0
rows byte 6
col = 4
sum word 0
prompt3 byte "table",0
prompt4 byte "enter numbers  ", 0
cols byte 4
divisor byte 24

.code 
main proc
mov ebx , offset numbers
mov edi , offset numbers
mov ecx , 24
mov edx , offset prompt4
call crlf
call writestring
call crlf
mov edx , 0
L1:
call readdec
mov [edi] , al
inc edi
loop L1
mov edi , 0
mov esi , offset numbers
mov ecx , 24
call crlf
mov esi , 0
mov ecx , col
mov edx , offset prompt1
call writestring
call crlf
avgr:
mov esi , 0
mov edi , ecx
mov ecx , rs
sumr:
add al , [ebx+esi]
inc esi
loop sumr
add sum , ax
div rows
mov ah , 0 
mov ecx , edi
call writedec
call crlf
mov eax,0
add ebx , rs
loop avgr

call crlf
mov edx , offset prompt2
call writestring
call crlf
mov ebx , offset numbers
mov eax , 0
mov ecx , rs
avgc:
mov edi , ecx
mov eax , 0
mov esi , ebx
mov cl , 4
sums:
add al , [esi]
add esi , 6
loop sums
div cols
call writedec
call crlf
inc ebx
mov ecx , edi
loop avgc
mov edx , offset prompt3
call writestring
call crlf
call crlf
mov eax , 0
movzx eax , sum
div divisor
mov ah , 0
dec eax
call writedec
exit
main endp
end main