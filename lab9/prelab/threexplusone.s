; Yu Du, yd2am
; threexplusone.s
; 2019.11.16
; 
; Purpose : find the number of steps for the input value (stored in rdi) to reach 1
; Optimizations: Use left/right shift to avoid using 'imul' or 'idiv', 
;				 Use 'and' and 'cmp' (avoid using 'idiv') to check whether x is even or odd,
; 				 Computing 3x+1 by using lea and 2x+x+1,
;				 Store the counter in rax rather than using another register to avoid additional pushing,
;				 


	global threexplusone

	section .text

; input x stored in rdi, the counter stored in rax
threexplusone:
	xor	rax, rax			; zero out the return register
	push rdx
	mov rdx, 1				; to be used
start:
	cmp rdi, 1		 		; if x == 1, return 0, end
	je done
	push rdi		 		; to store the last x
	and rdx, rdi
	cmp rdx,1
	je odd			 		; if result==1, x is odd
	jmp even		 		; else, x is even
odd:
	pop rdi			 		; get x
	lea rdi, [rdi*2+rdi]	; 3x
	inc rdi					; 3x+1
	call threexplusone 		; recurssion
	inc rax					; count++
	jmp start
even:
	pop rdi			 		; get x
	sar rdi, 1				; x/2
	call threexplusone 		; recurssion
	inc rax					; count++
	jmp start
done:
	pop rdx
	ret
