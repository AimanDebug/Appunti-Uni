	.text
	.global main
	.type main, %function

main:	push {lr}
	ldr r0, [r1, #4]	@ x da linea di comando
	bl atoi
	bl fun			@ chiamo f(x)
	mov r1, r0
	ldr r0, =format
	bl printf
	pop {lr}
	mov pc, lr

	.text
	.global fun
	.type fun, %function

fun:	LSL r1, r0, #1		@ x * 2
	ADD r0, r1, r0		@ x * 2 + x (x * 3)
	ADD r0, r0, #1		@ x * 3 + 1
	LSR r0, r0, #2		@ (x * 3 + 1) / 4
	mov pc, lr

	.data

format:	.string "f(x): %d\n"
