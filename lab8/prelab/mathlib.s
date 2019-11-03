; Yu Du, yd2am
; mathlib.s
; 2019.11.3
;
; Purpose : product multiplies the two integers
;			power calculates the power of two integers
;

	global product
	global power

	section .text


; Parameter 1 in rdi: x
; Parameter 2 in rsi: y
; Return x * y

product:
	; Prologue

	; Subroutine body:
	xor	rax, rax	 ; zero out the return register
	xor	r10, r10	 ; zero out the counter i
start:
	cmp	r10, rsi	 ; does i == y?
	je	done		 ; if so, we are done with the loop
	add	rax, rdi	 ; add x to rax
	inc	r10		 	 ; increment our counter i
	jmp	start		 ; we are done with this loop iteration
done:	
	; Standard epilogue: the return value is already in rax
	; We do not have any callee-saved registers to restore
	; We do not have any local variables to deallocate, so all we do is return
	ret


; Parameter 1 in rdi: x
; Parameter 2 in rsi: y
; Return x ^ y

power:
	xor	rax, rax	 ; zero out the return register
	mov rax, 1		 ; init: x^0 = 1
recursion:
	cmp	rsi, 0	 	 ; does y == 0?
	je	end		 	 ; if so, we are done with the loop
	push rdi		 ; to store the original x
	push rsi 		 ; to store the original y (in this recursion loop)
	dec rsi
	call power
	pop rsi			 ; will return to this instruction! update x and y
	pop rdi
	mov rsi, rax
	call product	 ; x*x
end:
	ret
