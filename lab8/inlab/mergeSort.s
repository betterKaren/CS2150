; Yu Du, yd2am
; mergeSort.s
; 2019.11.5

	global mergeSort
	global merge

	section .text


; Parameter 1 is a pointer to the int array 
; Parameter 2 is the left index in the array 
; Parameter 3 is the right index in the array
; Return type is void 
mergeSort:
	; Implement mergeSort here
	cmp rsi, rdx		; compare left index & right index
	jge end 			; if(start >= end) exit
	mov r8, rsi 		; r8 = left index
	mov r9, rdx 		; r9 = right index
	mov rcx, rsi 		; rcx = left index
	add rcx, rdx		; rcx = left index + right index
	shr rcx, 1			; rcx /= 2 = mid
	push r8				; push left index into stack (keep the original)
	push r9 			; push right index into stack (keep the original)
	push rsi			; push left index into stack (to be update)
	push rdx			; push right index into stack (to be update)
	push rcx			; push mid index into stack
	call mergeSort 		; the first half, call mergerSort(start, mid)
	pop rcx				; pop mid index
	pop rdx 			; pop rigth index
	pop rsi 			; pop left index
	pop r9				; pop right index
	pop r8				; pop left index
	mov rdx, rcx		; right index = mid
	mov rsi, r8			; left index = left index
	push r8
	push r9
	push rsi
	push rdx
	push rcx
	call mergeSort 		; the second half, call mergeSort(mid+1, end)
	pop rcx
	pop rdx
	pop rsi
	pop r9
	pop r8
	mov rsi, rcx		; left index = mid
	add rsi 			; left index++ -> left index = mid+1
	mov rdx, r9			; right index = end
	call merge 			; call merge
end:
	ret

	



; Parameter 1 is a pointer to the int array 
; Parameter 2 is the left index in the array
; Parameter 3 is the middle index in the array 
; Parameter 4 is the right index in the array
; Return type is void 
merge:
	; Save callee-save registers
	; Store local variables 
	push rbx			; int i
	push r12			; int j
	push r13			; int k
	push r14			; int n1
	push r15			; int n2
	
	mov r14, rdx			; n1 = mid - left + 1
	sub r14, rsi
	inc r14

	mov r15, rcx			; n2 = right - mid 
	sub r15, rdx

	lea r11, [r14+r15]		; r11 = rsp offset = 4(n1 + n2)
	lea r11, [4*r11]		
	sub rsp, r11			; allocate space for temp arrays

	mov rbx, 0			; i = 0
	mov r12, 0			; j = 0
	
; Copy elements of arr[] into L[]	
copyLloop:
	cmp rbx, r14			; is i >= n1?
	jge copyRloop
					; L[i] = arr[left + i]
	lea r10, [rsi+rbx]		
	mov r10d, DWORD [rdi+4*r10]	; r10 = arr[left + i]
	mov DWORD [rsp+4*rbx], r10d	; L[i] = r10
	inc rbx				; i++
	jmp copyLloop

; Copy elements of arr[] into R[]
copyRloop:
	cmp r12, r15			; is j >= n2?
	jge endcopyR
 					; R[j] = arr[mid + 1 + j]
	lea r10, [rdx+r12+1]	
	mov r10d, DWORD [rdi+4*r10]	; r10 = arr[mid + 1 + j]
	lea rax, [r12+r14]		
	mov DWORD [rsp+4*rax], r10d	; R[j] = r10
	inc r12				; j++
	jmp copyRloop

endcopyR:	
	mov rbx, 0			; i = 0
	mov r12, 0			; j = 0
	mov r13, rsi			; k = left

; Merge L[] and R[] into arr[]
mergeLoop:
	cmp rbx, r14			; is i >= n1 or j >= n2?
	jge loopL
	cmp r12, r15
	jge loopL
	lea r10, [r12+r14]
	mov r10d, DWORD [rsp+4*r10] 	; r10d = R[j]
	cmp DWORD [rsp+4*rbx], r10d	; is L[i] <= R[j]?
	jle if
	mov DWORD [rdi+4*r13], r10d	; arr[k] = R[j]
	inc r12				; j++
	jmp endif 
if:
	mov r10d, DWORD [rsp+4*rbx] 
	mov DWORD [rdi+4*r13], r10d	; arr[k] = L[i] 
	inc rbx				; i++
endif:	
	inc r13				; k++	
	jmp mergeLoop
	
; Copy elements of L[] into arr[]
loopL:				
	cmp rbx, r14			; is i >= n1?
	jge loopR
	mov r10d, DWORD [rsp+4*rbx] 
	mov DWORD [rdi+4*r13], r10d	; arr[k] = L[i]
	inc rbx				; i++
	inc r13				; k++
	jmp loopL

; Copy elements of R[] into arr[]
loopR:	
	cmp r12, r15			; is j >= n2?
	jge endR
	lea r10, [r12+r14]
	mov r10d, DWORD [rsp+4*r10] 	
	mov DWORD [rdi+4*r13], r10d	; arr[k] = R[j]

	inc r12				; j++
	inc r13				; k++
	jmp loopR
	
endR:
	; deallocate temp arrays
	; restore callee-save registers
	add rsp, r11	
	pop r15			
	pop r14
	pop r13
	pop r12
	pop rbx
	ret
