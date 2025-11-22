	.text
	.global main
	.type main, %function

main:
	push {lr}

	ldr r0, [r1, #4]	@ get x (str)
	bl atoi			@ convert x to int
	bl fattoriale		@ call fattoriale(x)
	mov r1, r0		@ printf(..., x)
	ldr r0, =format		@ printf(format_str, x)
	bl printf

	pop {lr}
	mov pc, lr

fattoriale:
	cmp r0, #0	@ base case
	bne recurse
	mov r0, #1	@ return 1
	
	mov pc, lr

recurse:
	push {lr}

	push {r0}	@ save x
	sub r0, r0, #1	@ calculate x - 1
	bl fattoriale	@ call fattoriale(x - 1)
	pop {r1}	@ get x
	mul r0, r0, r1	@ calculate fattoriale(x - 1) * x

	pop {lr}
	mov pc, lr

	.data
format:	.string "Fattoriale(x): %u\n"
