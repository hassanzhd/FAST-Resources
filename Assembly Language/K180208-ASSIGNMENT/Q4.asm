include C:\Irvine\Irvine32.inc
includelib C:\Irvine\Irvine32.Lib
includelib C:\Irvine\Kernel32.Lib
includelib C:\Irvine\User32.Lib

.data 
stringToCopy BYTE "SOURCE: ",0
stringCopied BYTE "DESTINATION: ",0
equalString BYTE "STRINGS ARE EQUAL", 0
unEqualString BYTE "STRINGS ARE UNEQUAL", 0
notFound BYTE "STRING NOT FOUND", 0
found BYTE "STRING FOUND AT ", 0
subs BYTE "SUBSTRING: ", 0
stringCmp1 BYTE "JOHN",0
stringCmp2 BYTE 20 DUP(?),0
subString1 BYTE 20 DUP(?),0
findstring1 BYTE "HN",0
firstIndex DWORD 0
secondIndex DWORD 3

.code 
main PROC
mov ecx, lengthof stringCmp1
push OFFSET stringCmp2
push OFFSET stringCmp1
call stringCopy
add ebp, 8
mov ecx, lengthof stringCmp1
push OFFSET stringCmp2
push OFFSET stringCmp1
call stringCompare
add ebp, 8

push OFFSET stringCmp1
push OFFSET findString1
call findString
add ebp, 8

push firstIndex
push secondIndex
push OFFSET stringCmp1
call subString

exit
main ENDP


stringCopy PROC
push ebp
mov ebp, esp
mov esi, [ebp+8]
mov edi, [ebp+12]
cld
rep movsb
mov edx, OFFSET stringToCopy
call writestring
mov edx, [ebp+8]
call writestring
call crlf
mov edx, OFFSET stringCopied
call writestring
mov edx, [ebp+12]
call writestring
call crlf
pop ebp
ret
stringCopy ENDP

stringCompare PROC
push ebp
mov ebp, esp
mov esi, [ebp+8]
mov edi, [ebp+12]
cld
repe cmpsb
jne notEqual

equal:
mov edx, OFFSET equalString
call writestring
call crlf
jmp return

notEqual:
mov eax, OFFSET unEqualString
call writestring
call crlf
jmp return

return:
pop ebp
ret

stringCompare ENDP

findString PROC
push ebp
mov ebp, esp
mov esi, [ebp+12]
mov edi, [ebp+8]
mov ebx, 0
mov edx, 0
mov eax, 0
mov ecx, LENGTHOF stringCmp1

find:
mov edx, ecx
mov ecx, LENGTHOF findString1
dec ecx
repe cmpsb
je equal
inc eax
mov edi, OFFSET findString1
mov ecx, edx
loop find

mov edx , OFFSET notFound
call writestring
call crlf
pop ebp
ret

equal:
mov edx , OFFSET found
call writestring
call writedec
call crlf

pop ebp
ret

findString ENDP

subString PROC
push ebp
mov ebp, esp
mov ebx, 0
mov eax, 0
mov esi, [ebp+8]
mov ebx, [ebp+12]
mov eax, [ebp+16]

add esi, eax
sub ebx, eax
mov ecx, ebx
mov edi, OFFSET subString1
rep movsb

mov edx, OFFSET subs
call writestring
mov edx, OFFSET subString1
call writestring
call crlf

pop ebp
ret

subString ENDP

end main

