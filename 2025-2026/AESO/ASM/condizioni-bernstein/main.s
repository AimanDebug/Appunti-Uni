	.text
	.global main
	.type main, %function

main:
	push {lr}

	ldr r0, [r1, #4]	@ fst bitmap
	ldr r1, [r1, #8]	@ snd bitmap

	push {r1}
	bl atoi			@ convert fst to int
	
	push {r0}
	mov r0, r1
	bl atoi			@ convert snd to int
	mov r1, r0
	pop {r0}

	bl check_bernstein
	cmp r0, #0
	beq main_if_false

@ if_true:
	ldr r0, =true_str
	b main_endif
main_if_false:
	ldr r0, =false_str
main_endif:
	bl printf

	pop {lr}
	mov pc, lr

check_bernstein:
	push {lr}

	push {r0, r1}
	bl check_dip
	cmp r0, #0
	beq end
	pop {r0, r1}

	push {r0, r1}
	bl check_antidip
	cmp r0, #0
	beq end
	pop {r0, r1}

	bl check_dipout		@ if the last check is successful everything is successful and vice versa
	
end:
	pop {lr}
	mov pc, lr

check_dip:
	lsl r0, r0, #16		@ tolgo i primi 16 bit
	lsr r0, r0, #16		@ i primi 16 vanno a 0

	lsr r1, r1, #16		@ prendo solo gli ultimi 16

	and r0, r0, r1		@ se 1 reg letto/scritto ci sara un 1 nell'and
	cmp r0, #0
	bne check_dip_if_false

@ check_dip_if_true:
	mov r0, #1
	b check_dip_endif
check_dip_if_false:
	mov r0, #0
check_dip_endif:

	mov pc, lr

check_antidip:
	push {lr}

	@ switch r0 and r1 so we can call check_dip
	mov r2, r1
	mov r1, r0
	mov r0, r2

	bl check_dip

	pop {lr}
	mov pc, lr

check_dipout:
	lsl r0, r0, #16
	lsr r0, r0, #16

	lsl r1, r1, #16
	lsr r1, r1, #16

	and r0, r0, r1
	cmp r0, #0
	bne check_dipout_if_false
@ check_dipout_if_true:
	mov r0, #1
	b check_dipout_endif
check_dipout_if_false:
	mov r0, #0
check_dipout_endif:
	
	mov pc, lr

	.data

true_str:
	.string "true\n"
false_str:
	.string "false\n"
