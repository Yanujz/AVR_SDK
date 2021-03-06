	.file	"interrupt.cpp"
__SP_H__ = 0x3e
__SP_L__ = 0x3d
__SREG__ = 0x3f
__RAMPZ__ = 0x3b
__tmp_reg__ = 0
__zero_reg__ = 1
	.text
.global	_ZN9Interrupt9searchPinEhP9PCINT_PINP10HW_INT_PIN
	.type	_ZN9Interrupt9searchPinEhP9PCINT_PINP10HW_INT_PIN, @function
_ZN9Interrupt9searchPinEhP9PCINT_PINP10HW_INT_PIN:
	push r28
	push r29
/* prologue: function */
/* frame size = 0 */
/* stack size = 2 */
.L__stack_usage = 2
	movw r28,r22
	movw r26,r20
	lds r25,int_vect+33
	cp r25,r24
	brne .+2
	rjmp .L17
	cp r24,r25
	brlo .L3
	lds r25,int_vect+44
	ldi r30,lo8(4)
	cpse r24,r25
	ldi r30,lo8(-1)
.L4:
	lds r25,int_vect+55
	cpse r24,r25
	rjmp .L5
	ldi r30,lo8(5)
	rjmp .L2
.L3:
	lds r25,int_vect+22
	ldi r30,lo8(2)
	cpse r24,r25
	ldi r30,lo8(-1)
.L6:
	lds r25,int_vect+11
	cpse r24,r25
	rjmp .L7
	ldi r30,lo8(1)
.L7:
	lds r25,int_vect
	cp r25,r24
	breq .L21
.L5:
	cpi r30,lo8(-1)
	breq .L8
.L2:
	ldi r24,lo8(11)
	mul r30,r24
	movw r30,r0
	clr __zero_reg__
	subi r30,lo8(-(int_vect))
	sbci r31,hi8(-(int_vect))
	ldd r24,Z+1
	adiw r26,1
	st X,r24
	sbiw r26,1
	ldd r24,Z+4
	ldd r25,Z+5
	adiw r26,4+1
	st X,r25
	st -X,r24
	sbiw r26,4
	ldd r24,Z+6
	adiw r26,6
	st X,r24
	sbiw r26,6
	ldd r24,Z+7
	adiw r26,7
	st X,r24
	sbiw r26,7
	ldd r24,Z+8
	adiw r26,8
	st X,r24
	sbiw r26,8
	ldd r24,Z+9
	adiw r26,9
	st X,r24
	sbiw r26,9
	ldd r24,Z+10
	adiw r26,10
	st X,r24
	sbiw r26,10
	ldd r24,Z+2
	ldd r25,Z+3
	adiw r26,2+1
	st X,r25
	st -X,r24
	sbiw r26,2
	ldi r24,lo8(2)
.L1:
/* epilogue start */
	pop r29
	pop r28
	ret
.L17:
	ldi r30,lo8(3)
	rjmp .L2
.L21:
	ldi r30,0
	rjmp .L2
.L8:
	lds r25,pcint_vect+70
	cp r25,r24
	breq .L22
	cp r24,r25
	brlo .L11
	ldi r18,lo8(pcint_vect)
	ldi r19,hi8(pcint_vect)
	ldi r25,lo8(10)
.L12:
	subi r25,lo8(-(1))
	cpi r25,lo8(21)
	breq .L14
	movw r26,r18
	subi r26,-77
	sbci r27,-1
	ld r20,X
	cpse r20,r24
	rjmp .L16
	mov r30,r25
.L16:
	subi r18,-7
	sbci r19,-1
	rjmp .L12
.L11:
	ldi r26,lo8(pcint_vect)
	ldi r27,hi8(pcint_vect)
	ldi r25,lo8(10)
.L15:
	subi r25,lo8(-(-1))
	adiw r26,63
	ld r18,X
	sbiw r26,63
	cpse r18,r24
	rjmp .L13
	mov r30,r25
.L13:
	sbiw r26,7
	cpse r25,__zero_reg__
	rjmp .L15
.L14:
	ldi r24,0
	cpi r30,lo8(-1)
	breq .L1
.L10:
	ldi r24,lo8(7)
	mul r30,r24
	movw r30,r0
	clr __zero_reg__
	subi r30,lo8(-(pcint_vect))
	sbci r31,hi8(-(pcint_vect))
	ldd r24,Z+1
	std Y+1,r24
	ldd r24,Z+2
	std Y+2,r24
	ldd r24,Z+5
	ldd r25,Z+6
	std Y+6,r25
	std Y+5,r24
	ldd r24,Z+3
	ldd r25,Z+4
	std Y+4,r25
	std Y+3,r24
	ldi r24,lo8(1)
	rjmp .L1
.L22:
	ldi r30,lo8(10)
	rjmp .L10
	.size	_ZN9Interrupt9searchPinEhP9PCINT_PINP10HW_INT_PIN, .-_ZN9Interrupt9searchPinEhP9PCINT_PINP10HW_INT_PIN
.global	_ZN9Interrupt15attachInterruptEh8INT_EDGEPFvhE
	.type	_ZN9Interrupt15attachInterruptEh8INT_EDGEPFvhE, @function
_ZN9Interrupt15attachInterruptEh8INT_EDGEPFvhE:
	push r12
	push r13
	push r15
	push r16
	push r17
	push r28
	push r29
	in r28,__SP_L__
	in r29,__SP_H__
	sbiw r28,18
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
/* prologue: function */
/* frame size = 18 */
/* stack size = 25 */
.L__stack_usage = 25
	mov r17,r24
	mov r16,r22
	movw r12,r20
	movw r20,r28
	subi r20,-1
	sbci r21,-1
	movw r22,r28
	subi r22,-12
	sbci r23,-1
	call _ZN9Interrupt9searchPinEhP9PCINT_PINP10HW_INT_PIN
	cpi r24,lo8(1)
	breq .L31
	cpi r24,lo8(2)
	brne .+2
	rjmp .L32
	cpi r16,lo8(4)
	brne .L46
	ldi r18,lo8(5)
	mul r17,r18
	movw r24,r0
	clr __zero_reg__
	movw r30,r24
	subi r30,lo8(-(_ZL16_flashMappedPort+2))
	sbci r31,hi8(-(_ZL16_flashMappedPort+2))
/* #APP */
 ;  64 "libs//gpio/interrupt/interrupt.cpp" 1
	lpm r20, Z
	
 ;  0 "" 2
/* #NOAPP */
	movw r30,r24
	subi r30,lo8(-(_ZL16_flashMappedPort))
	sbci r31,hi8(-(_ZL16_flashMappedPort))
/* #APP */
 ;  63 "libs//gpio/interrupt/interrupt.cpp" 1
	lpm r26, Z+
	lpm r27, Z
	
 ;  0 "" 2
/* #NOAPP */
	adiw r26,2
	ld r24,X
	sbiw r26,2
	ldi r18,lo8(1)
	ldi r19,0
	rjmp 2f
	1:
	lsl r18
	2:
	dec r20
	brpl 1b
	or r24,r18
	adiw r26,2
	st X,r24
.L46:
	ldi r24,0
	rjmp .L30
.L31:
	ldd r24,Y+13
	cpi r24,lo8(1)
	breq .L34
	tst r24
	breq .L35
	cpi r24,lo8(2)
	breq .L36
.L37:
	ldd r30,Y+15
	ldd r31,Y+16
	std Z+1,r13
	st Z,r12
	ldd r30,Y+17
	ldd r31,Y+18
	st Z,r16
.L51:
	ldi r24,lo8(1)
.L30:
/* epilogue start */
	adiw r28,18
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
	pop r29
	pop r28
	pop r17
	pop r16
	pop r15
	pop r13
	pop r12
	ret
.L35:
	lds r24,104
	ori r24,lo8(1)
	sts 104,r24
	lds r24,107
	ldd r25,Y+14
	ldi r18,lo8(1)
	ldi r19,0
	rjmp 2f
	1:
	lsl r18
	2:
	dec r25
	brpl 1b
	or r24,r18
	sts 107,r24
	rjmp .L37
.L34:
	lds r24,104
	ori r24,lo8(2)
	sts 104,r24
	lds r24,108
	ldd r25,Y+14
	ldi r18,lo8(1)
	ldi r19,0
	rjmp 2f
	1:
	lsl r18
	2:
	dec r25
	brpl 1b
	or r24,r18
	sts 108,r24
	rjmp .L37
.L36:
	lds r24,104
	ori r24,lo8(4)
	sts 104,r24
	lds r24,109
	ldd r25,Y+14
	ldi r18,lo8(1)
	ldi r19,0
	rjmp 2f
	1:
	lsl r18
	2:
	dec r25
	brpl 1b
	or r24,r18
	sts 109,r24
	rjmp .L37
.L32:
/* #APP */
 ;  33 "libs//gpio/interrupt/interrupt.cpp" 1
	cli
 ;  0 "" 2
/* #NOAPP */
	cpi r16,lo8(1)
	breq .L39
	tst r16
	breq .L40
	cpi r16,lo8(2)
	breq .L41
	cpi r16,lo8(5)
	brne .L42
.L40:
	ldd r15,Y+8
.L42:
	ldd r24,Y+2
	tst r24
	breq .L43
	cpi r24,lo8(1)
	breq .L44
.L45:
	in r24,0x1d
	ldd r25,Y+11
	ldi r18,lo8(1)
	ldi r19,0
	rjmp 2f
	1:
	lsl r18
	2:
	dec r25
	brpl 1b
	or r24,r18
	out 0x1d,r24
	ldd r30,Y+3
	ldd r31,Y+4
	std Z+1,r13
	st Z,r12
	ldd r30,Y+5
	ldd r31,Y+6
	st Z,r15
/* #APP */
 ;  58 "libs//gpio/interrupt/interrupt.cpp" 1
	sei
 ;  0 "" 2
/* #NOAPP */
	rjmp .L51
.L41:
	ldd r15,Y+9
	rjmp .L42
.L39:
	ldd r15,Y+10
	rjmp .L42
.L43:
	lds r24,105
	or r24,r15
	sts 105,r24
	rjmp .L45
.L44:
	lds r24,106
	or r24,r15
	sts 106,r24
	rjmp .L45
	.size	_ZN9Interrupt15attachInterruptEh8INT_EDGEPFvhE, .-_ZN9Interrupt15attachInterruptEh8INT_EDGEPFvhE
.global	_ZN9Interrupt15deatchInterruptEh
	.type	_ZN9Interrupt15deatchInterruptEh, @function
_ZN9Interrupt15deatchInterruptEh:
	push r28
	push r29
	in r28,__SP_L__
	in r29,__SP_H__
	sbiw r28,18
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
/* prologue: function */
/* frame size = 18 */
/* stack size = 20 */
.L__stack_usage = 20
	movw r20,r28
	subi r20,-1
	sbci r21,-1
	movw r22,r28
	subi r22,-12
	sbci r23,-1
	call _ZN9Interrupt9searchPinEhP9PCINT_PINP10HW_INT_PIN
	cpi r24,lo8(1)
	breq .L53
	cpi r24,lo8(2)
	breq .L54
.L66:
	ldi r24,0
	rjmp .L52
.L53:
	ldd r24,Y+13
	cpi r24,lo8(1)
	breq .L56
	tst r24
	breq .L57
	cpi r24,lo8(2)
	brne .+2
	rjmp .L58
.L54:
	in r20,0x1d
	ldd r18,Y+11
	ldi r24,lo8(1)
	ldi r25,0
	movw r22,r24
	rjmp 2f
	1:
	lsl r22
	rol r23
	2:
	dec r18
	brpl 1b
	movw r18,r22
	com r18
	and r18,r20
	out 0x1d,r18
	in r18,0x1d
	ldd r19,Y+11
	rjmp 2f
	1:
	lsl r24
	rol r25
	2:
	dec r19
	brpl 1b
	ldi r19,0
	and r18,r24
	and r19,r25
	ldi r24,lo8(1)
	or r18,r19
	brne .L66
.L52:
/* epilogue start */
	adiw r28,18
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
	pop r29
	pop r28
	ret
.L57:
	lds r18,107
	ldd r19,Y+14
	ldi r24,lo8(1)
	ldi r25,0
	rjmp 2f
	1:
	lsl r24
	2:
	dec r19
	brpl 1b
	com r24
	and r24,r18
	sts 107,r24
	lds r24,107
	rjmp .L54
.L56:
	lds r18,108
	ldd r19,Y+14
	ldi r24,lo8(1)
	ldi r25,0
	rjmp 2f
	1:
	lsl r24
	2:
	dec r19
	brpl 1b
	com r24
	and r24,r18
	sts 108,r24
	lds r24,108
	rjmp .L54
.L58:
	lds r18,109
	ldd r19,Y+14
	ldi r24,lo8(1)
	ldi r25,0
	rjmp 2f
	1:
	lsl r24
	2:
	dec r19
	brpl 1b
	com r24
	and r24,r18
	sts 109,r24
	lds r24,109
	rjmp .L54
	.size	_ZN9Interrupt15deatchInterruptEh, .-_ZN9Interrupt15deatchInterruptEh
.global	_Z17call_int_callbackPFvhE8INT_EDGEPVhhhh
	.type	_Z17call_int_callbackPFvhE8INT_EDGEPVhhhh, @function
_Z17call_int_callbackPFvhE8INT_EDGEPVhhhh:
	push r14
	push r16
	push r28
	push r29
	push __tmp_reg__
	in r28,__SP_L__
	in r29,__SP_H__
/* prologue: function */
/* frame size = 1 */
/* stack size = 5 */
.L__stack_usage = 5
	movw r30,r24
	movw r26,r20
	mov r24,r16
	std Y+1,r14
	cpi r22,lo8(3)
	breq .L68
	brsh .L69
	cpi r22,lo8(1)
	breq .L70
	cpi r22,lo8(2)
	breq .L71
.L67:
/* epilogue start */
	pop __tmp_reg__
	pop r29
	pop r28
	pop r16
	pop r14
	ret
.L69:
	cpi r22,lo8(4)
	breq .L73
	cpi r22,lo8(5)
	brne .L67
.L74:
/* epilogue start */
	pop __tmp_reg__
	pop r29
	pop r28
	pop r16
	pop r14
	eijmp
.L70:
	ld r20,X
	ldi r21,0
	rjmp 2f
	1:
	asr r21
	ror r20
	2:
	dec r18
	brpl 1b
	sbrs r20,0
	rjmp .L67
	rjmp .L74
.L71:
	ld r22,X
	ldi r20,lo8(1)
	ldi r21,0
	mov r0,r18
	rjmp 2f
	1:
	lsl r20
	rol r21
	2:
	dec r0
	brpl 1b
	ldi r23,0
	and r20,r22
	and r21,r23
	rjmp 2f
	1:
	asr r21
	ror r20
	2:
	dec r18
	brpl 1b
	or r20,r21
	breq .L74
	rjmp .L67
.L68:
	ld r20,X
	ldi r21,0
	rjmp 2f
	1:
	asr r21
	ror r20
	2:
	dec r18
	brpl 1b
	sbrs r20,0
	rjmp .L74
.L85:
	ldd r25,Y+1
	rjmp .L74
.L73:
	ld r22,X
	ldi r20,lo8(1)
	ldi r21,0
	mov r0,r18
	rjmp 2f
	1:
	lsl r20
	rol r21
	2:
	dec r0
	brpl 1b
	ldi r23,0
	and r20,r22
	and r21,r23
	rjmp 2f
	1:
	asr r21
	ror r20
	2:
	dec r18
	brpl 1b
	or r20,r21
	breq .+2
	rjmp .L74
	rjmp .L85
	.size	_Z17call_int_callbackPFvhE8INT_EDGEPVhhhh, .-_Z17call_int_callbackPFvhE8INT_EDGEPVhhhh
.global	__vector_9
	.type	__vector_9, @function
__vector_9:
	push r1
	push r0
	in r0,__SREG__
	push r0
	clr __zero_reg__
	in r0,__RAMPZ__
	push r0
	push r14
	push r16
	push r18
	push r19
	push r20
	push r21
	push r22
	push r23
	push r24
	push r25
	push r26
	push r27
	push r30
	push r31
	push r28
	push r29
	push __tmp_reg__
	in r28,__SP_L__
	in r29,__SP_H__
/* prologue: Signal */
/* frame size = 1 */
/* stack size = 21 */
.L__stack_usage = 21
	in r24,0x3
	lds r25,port_b_history
	eor r24,r25
	std Y+1,r24
	in r24,0x3
	sts port_b_history,r24
	ldi r19,0
	ldi r18,0
.L90:
	ldd r24,Y+1
	ldi r25,0
	mov r0,r18
	rjmp 2f
	1:
	asr r25
	ror r24
	2:
	dec r0
	brpl 1b
	sbrs r24,0
	rjmp .L87
	ldi r22,lo8(7)
	mul r22,r18
	movw r26,r0
	mul r22,r19
	add r27,r0
	clr __zero_reg__
	subi r26,lo8(-(vectB))
	sbci r27,hi8(-(vectB))
	adiw r26,3
	ld r30,X+
	ld r31,X
	sbiw r26,3+1
	ld r24,Z
	ldd r25,Z+1
	lds r20,pcint_vect+3
	lds r21,pcint_vect+3+1
	sub r30,r20
	sbc r31,r21
	asr r31
	ror r30
	mul r22,r30
	movw r20,r0
	mul r22,r31
	add r21,r0
	clr __zero_reg__
	movw r30,r20
	subi r30,lo8(-(pcint_vect))
	sbci r31,hi8(-(pcint_vect))
	ld r16,Z
	ldi r20,lo8(5)
	mul r16,r20
	movw r30,r0
	clr __zero_reg__
	subi r30,lo8(-(_ZL16_flashMappedPort))
	sbci r31,hi8(-(_ZL16_flashMappedPort))
/* #APP */
 ;  279 "libs//gpio/interrupt/interrupt.cpp" 1
	lpm r20, Z+
	lpm r21, Z
	
 ;  0 "" 2
/* #NOAPP */
	adiw r26,5
	ld r30,X+
	ld r31,X
	ld r22,Z
	sbiw r24,0
	brne .L88
.L86:
/* epilogue start */
	pop __tmp_reg__
	pop r29
	pop r28
	pop r31
	pop r30
	pop r27
	pop r26
	pop r25
	pop r24
	pop r23
	pop r22
	pop r21
	pop r20
	pop r19
	pop r18
	pop r16
	pop r14
	pop r0
	out __RAMPZ__,r0
	pop r0
	out __SREG__,r0
	pop r0
	pop r1
	reti
.L87:
	subi r18,-1
	sbci r19,-1
	cpi r18,8
	cpc r19,__zero_reg__
	breq .+2
	rjmp .L90
	rjmp .L86
.L88:
	lds r14,port_b_history
	call _Z17call_int_callbackPFvhE8INT_EDGEPVhhhh
	rjmp .L86
	.size	__vector_9, .-__vector_9
.global	__vector_10
	.type	__vector_10, @function
__vector_10:
	push r1
	push r0
	in r0,__SREG__
	push r0
	clr __zero_reg__
	in r0,__RAMPZ__
	push r0
	push r14
	push r16
	push r18
	push r19
	push r20
	push r21
	push r22
	push r23
	push r24
	push r25
	push r26
	push r27
	push r30
	push r31
	push r28
	push r29
	push __tmp_reg__
	in r28,__SP_L__
	in r29,__SP_H__
/* prologue: Signal */
/* frame size = 1 */
/* stack size = 21 */
.L__stack_usage = 21
	lds r18,259
	lds r19,port_j_history
	eor r18,r19
	std Y+1,r18
	lds r18,259
	sts port_j_history,r18
	ldd r18,Y+1
	sbrc r18,0
	rjmp .L97
	ldd r18,Y+1
	bst r18,1
	clr r24
	bld r24,0
	ldi r25,0
	sbrs r18,1
	rjmp .L94
	ldi r18,lo8(1)
.L95:
	ldi r19,lo8(7)
	mul r19,r24
	movw r26,r0
	mul r19,r25
	add r27,r0
	clr __zero_reg__
	subi r26,lo8(-(vectJ))
	sbci r27,hi8(-(vectJ))
	adiw r26,3
	ld r30,X+
	ld r31,X
	sbiw r26,3+1
	ld r24,Z
	ldd r25,Z+1
	lds r20,pcint_vect+3
	lds r21,pcint_vect+3+1
	sub r30,r20
	sbc r31,r21
	asr r31
	ror r30
	mul r19,r30
	movw r20,r0
	mul r19,r31
	add r21,r0
	clr __zero_reg__
	movw r30,r20
	subi r30,lo8(-(pcint_vect))
	sbci r31,hi8(-(pcint_vect))
	ld r16,Z
	ldi r19,lo8(5)
	mul r16,r19
	movw r30,r0
	clr __zero_reg__
	subi r30,lo8(-(_ZL16_flashMappedPort))
	sbci r31,hi8(-(_ZL16_flashMappedPort))
/* #APP */
 ;  310 "libs//gpio/interrupt/interrupt.cpp" 1
	lpm r20, Z+
	lpm r21, Z
	
 ;  0 "" 2
/* #NOAPP */
	adiw r26,5
	ld r30,X+
	ld r31,X
	ld r22,Z
	sbiw r24,0
	breq .L94
	lds r14,port_j_history
	call _Z17call_int_callbackPFvhE8INT_EDGEPVhhhh
.L94:
/* epilogue start */
	pop __tmp_reg__
	pop r29
	pop r28
	pop r31
	pop r30
	pop r27
	pop r26
	pop r25
	pop r24
	pop r23
	pop r22
	pop r21
	pop r20
	pop r19
	pop r18
	pop r16
	pop r14
	pop r0
	out __RAMPZ__,r0
	pop r0
	out __SREG__,r0
	pop r0
	pop r1
	reti
.L97:
	ldi r18,0
	ldi r25,0
	ldi r24,0
	rjmp .L95
	.size	__vector_10, .-__vector_10
.global	__vector_11
	.type	__vector_11, @function
__vector_11:
	push r1
	push r0
	in r0,__SREG__
	push r0
	clr __zero_reg__
	in r0,__RAMPZ__
	push r0
	push r10
	push r11
	push r12
	push r13
	push r14
	push r15
	push r16
	push r17
	push r18
	push r19
	push r20
	push r21
	push r22
	push r23
	push r24
	push r25
	push r26
	push r27
	push r30
	push r31
	push r28
	push r29
	push __tmp_reg__
	in r28,__SP_L__
	in r29,__SP_H__
/* prologue: Signal */
/* frame size = 1 */
/* stack size = 27 */
.L__stack_usage = 27
	lds r24,262
	lds r25,port_k_history
	eor r24,r25
	std Y+1,r24
	lds r24,262
	sts port_k_history,r24
	ldi r19,lo8(vectK)
	mov r10,r19
	ldi r19,hi8(vectK)
	mov r11,r19
	mov r13,__zero_reg__
	mov r12,__zero_reg__
	ldi r17,lo8(7)
	ldi r20,lo8(5)
	mov r15,r20
.L106:
	ldd r24,Y+1
	ldi r25,0
	mov r0,r12
	rjmp 2f
	1:
	asr r25
	ror r24
	2:
	dec r0
	brpl 1b
	sbrs r24,0
	rjmp .L105
	movw r26,r10
	adiw r26,3
	ld r30,X+
	ld r31,X
	sbiw r26,3+1
	ld r24,Z
	ldd r25,Z+1
	lds r18,pcint_vect+3
	lds r19,pcint_vect+3+1
	sub r30,r18
	sbc r31,r19
	asr r31
	ror r30
	mul r17,r30
	movw r18,r0
	mul r17,r31
	add r19,r0
	clr __zero_reg__
	movw r30,r18
	subi r30,lo8(-(pcint_vect))
	sbci r31,hi8(-(pcint_vect))
	ld r16,Z
	mul r16,r15
	movw r30,r0
	clr __zero_reg__
	subi r30,lo8(-(_ZL16_flashMappedPort))
	sbci r31,hi8(-(_ZL16_flashMappedPort))
/* #APP */
 ;  341 "libs//gpio/interrupt/interrupt.cpp" 1
	lpm r20, Z+
	lpm r21, Z
	
 ;  0 "" 2
/* #NOAPP */
	sbiw r24,0
	breq .L105
	lds r14,port_k_history
	adiw r26,5
	ld r30,X+
	ld r31,X
	mov r18,r12
	ld r22,Z
	call _Z17call_int_callbackPFvhE8INT_EDGEPVhhhh
.L105:
	ldi r27,-1
	sub r12,r27
	sbc r13,r27
	ldi r24,7
	add r10,r24
	adc r11,__zero_reg__
	ldi r26,8
	cp r12,r26
	cpc r13,__zero_reg__
	breq .+2
	rjmp .L106
/* epilogue start */
	pop __tmp_reg__
	pop r29
	pop r28
	pop r31
	pop r30
	pop r27
	pop r26
	pop r25
	pop r24
	pop r23
	pop r22
	pop r21
	pop r20
	pop r19
	pop r18
	pop r17
	pop r16
	pop r15
	pop r14
	pop r13
	pop r12
	pop r11
	pop r10
	pop r0
	out __RAMPZ__,r0
	pop r0
	out __SREG__,r0
	pop r0
	pop r1
	reti
	.size	__vector_11, .-__vector_11
.global	__vector_1
	.type	__vector_1, @function
__vector_1:
	push r1
	push r0
	in r0,__SREG__
	push r0
	clr __zero_reg__
	in r0,__RAMPZ__
	push r0
	push r18
	push r19
	push r20
	push r21
	push r22
	push r23
	push r24
	push r25
	push r26
	push r27
	push r30
	push r31
/* prologue: Signal */
/* frame size = 0 */
/* stack size = 16 */
.L__stack_usage = 16
/* #APP */
 ;  361 "libs//gpio/interrupt/interrupt.cpp" 1
	cli
 ;  0 "" 2
/* #NOAPP */
	ldi r26,lo8(int_vect)
	ldi r27,hi8(int_vect)
	adiw r26,57
	ld r30,X+
	ld r31,X
	sbiw r26,57+1
	ld __tmp_reg__,Z+
	ld r31,Z
	mov r30,__tmp_reg__
	adiw r26,55
	ld r24,X
	eicall
/* #APP */
 ;  364 "libs//gpio/interrupt/interrupt.cpp" 1
	sei
 ;  0 "" 2
/* #NOAPP */
/* epilogue start */
	pop r31
	pop r30
	pop r27
	pop r26
	pop r25
	pop r24
	pop r23
	pop r22
	pop r21
	pop r20
	pop r19
	pop r18
	pop r0
	out __RAMPZ__,r0
	pop r0
	out __SREG__,r0
	pop r0
	pop r1
	reti
	.size	__vector_1, .-__vector_1
.global	__vector_2
	.type	__vector_2, @function
__vector_2:
	push r1
	push r0
	in r0,__SREG__
	push r0
	clr __zero_reg__
	in r0,__RAMPZ__
	push r0
	push r18
	push r19
	push r20
	push r21
	push r22
	push r23
	push r24
	push r25
	push r26
	push r27
	push r30
	push r31
/* prologue: Signal */
/* frame size = 0 */
/* stack size = 16 */
.L__stack_usage = 16
/* #APP */
 ;  367 "libs//gpio/interrupt/interrupt.cpp" 1
	cli
 ;  0 "" 2
/* #NOAPP */
	ldi r26,lo8(int_vect)
	ldi r27,hi8(int_vect)
	adiw r26,46
	ld r30,X+
	ld r31,X
	sbiw r26,46+1
	ld __tmp_reg__,Z+
	ld r31,Z
	mov r30,__tmp_reg__
	adiw r26,44
	ld r24,X
	eicall
/* #APP */
 ;  370 "libs//gpio/interrupt/interrupt.cpp" 1
	sei
 ;  0 "" 2
/* #NOAPP */
/* epilogue start */
	pop r31
	pop r30
	pop r27
	pop r26
	pop r25
	pop r24
	pop r23
	pop r22
	pop r21
	pop r20
	pop r19
	pop r18
	pop r0
	out __RAMPZ__,r0
	pop r0
	out __SREG__,r0
	pop r0
	pop r1
	reti
	.size	__vector_2, .-__vector_2
.global	__vector_3
	.type	__vector_3, @function
__vector_3:
	push r1
	push r0
	in r0,__SREG__
	push r0
	clr __zero_reg__
	in r0,__RAMPZ__
	push r0
	push r18
	push r19
	push r20
	push r21
	push r22
	push r23
	push r24
	push r25
	push r26
	push r27
	push r30
	push r31
/* prologue: Signal */
/* frame size = 0 */
/* stack size = 16 */
.L__stack_usage = 16
/* #APP */
 ;  373 "libs//gpio/interrupt/interrupt.cpp" 1
	cli
 ;  0 "" 2
/* #NOAPP */
	ldi r26,lo8(int_vect)
	ldi r27,hi8(int_vect)
	adiw r26,35
	ld r30,X+
	ld r31,X
	sbiw r26,35+1
	ld __tmp_reg__,Z+
	ld r31,Z
	mov r30,__tmp_reg__
	adiw r26,33
	ld r24,X
	eicall
/* #APP */
 ;  376 "libs//gpio/interrupt/interrupt.cpp" 1
	sei
 ;  0 "" 2
/* #NOAPP */
/* epilogue start */
	pop r31
	pop r30
	pop r27
	pop r26
	pop r25
	pop r24
	pop r23
	pop r22
	pop r21
	pop r20
	pop r19
	pop r18
	pop r0
	out __RAMPZ__,r0
	pop r0
	out __SREG__,r0
	pop r0
	pop r1
	reti
	.size	__vector_3, .-__vector_3
.global	__vector_4
	.type	__vector_4, @function
__vector_4:
	push r1
	push r0
	in r0,__SREG__
	push r0
	clr __zero_reg__
	in r0,__RAMPZ__
	push r0
	push r18
	push r19
	push r20
	push r21
	push r22
	push r23
	push r24
	push r25
	push r26
	push r27
	push r30
	push r31
/* prologue: Signal */
/* frame size = 0 */
/* stack size = 16 */
.L__stack_usage = 16
/* #APP */
 ;  381 "libs//gpio/interrupt/interrupt.cpp" 1
	cli
 ;  0 "" 2
/* #NOAPP */
	ldi r26,lo8(int_vect)
	ldi r27,hi8(int_vect)
	adiw r26,24
	ld r30,X+
	ld r31,X
	sbiw r26,24+1
	ld __tmp_reg__,Z+
	ld r31,Z
	mov r30,__tmp_reg__
	adiw r26,22
	ld r24,X
	eicall
/* #APP */
 ;  384 "libs//gpio/interrupt/interrupt.cpp" 1
	sei
 ;  0 "" 2
/* #NOAPP */
/* epilogue start */
	pop r31
	pop r30
	pop r27
	pop r26
	pop r25
	pop r24
	pop r23
	pop r22
	pop r21
	pop r20
	pop r19
	pop r18
	pop r0
	out __RAMPZ__,r0
	pop r0
	out __SREG__,r0
	pop r0
	pop r1
	reti
	.size	__vector_4, .-__vector_4
.global	__vector_5
	.type	__vector_5, @function
__vector_5:
	push r1
	push r0
	in r0,__SREG__
	push r0
	clr __zero_reg__
	in r0,__RAMPZ__
	push r0
	push r18
	push r19
	push r20
	push r21
	push r22
	push r23
	push r24
	push r25
	push r26
	push r27
	push r30
	push r31
/* prologue: Signal */
/* frame size = 0 */
/* stack size = 16 */
.L__stack_usage = 16
/* #APP */
 ;  387 "libs//gpio/interrupt/interrupt.cpp" 1
	cli
 ;  0 "" 2
/* #NOAPP */
	ldi r26,lo8(int_vect)
	ldi r27,hi8(int_vect)
	adiw r26,2
	ld r30,X+
	ld r31,X
	sbiw r26,2+1
	ld __tmp_reg__,Z+
	ld r31,Z
	mov r30,__tmp_reg__
	ld r24,X
	eicall
/* #APP */
 ;  390 "libs//gpio/interrupt/interrupt.cpp" 1
	sei
 ;  0 "" 2
/* #NOAPP */
/* epilogue start */
	pop r31
	pop r30
	pop r27
	pop r26
	pop r25
	pop r24
	pop r23
	pop r22
	pop r21
	pop r20
	pop r19
	pop r18
	pop r0
	out __RAMPZ__,r0
	pop r0
	out __SREG__,r0
	pop r0
	pop r1
	reti
	.size	__vector_5, .-__vector_5
.global	__vector_6
	.type	__vector_6, @function
__vector_6:
	push r1
	push r0
	in r0,__SREG__
	push r0
	clr __zero_reg__
	in r0,__RAMPZ__
	push r0
	push r18
	push r19
	push r20
	push r21
	push r22
	push r23
	push r24
	push r25
	push r26
	push r27
	push r30
	push r31
/* prologue: Signal */
/* frame size = 0 */
/* stack size = 16 */
.L__stack_usage = 16
/* #APP */
 ;  393 "libs//gpio/interrupt/interrupt.cpp" 1
	cli
 ;  0 "" 2
/* #NOAPP */
	ldi r26,lo8(int_vect)
	ldi r27,hi8(int_vect)
	adiw r26,13
	ld r30,X+
	ld r31,X
	sbiw r26,13+1
	ld __tmp_reg__,Z+
	ld r31,Z
	mov r30,__tmp_reg__
	adiw r26,11
	ld r24,X
	eicall
/* #APP */
 ;  396 "libs//gpio/interrupt/interrupt.cpp" 1
	sei
 ;  0 "" 2
/* #NOAPP */
/* epilogue start */
	pop r31
	pop r30
	pop r27
	pop r26
	pop r25
	pop r24
	pop r23
	pop r22
	pop r21
	pop r20
	pop r19
	pop r18
	pop r0
	out __RAMPZ__,r0
	pop r0
	out __SREG__,r0
	pop r0
	pop r1
	reti
	.size	__vector_6, .-__vector_6
.global	__vector_7
	.type	__vector_7, @function
__vector_7:
	__gcc_isr 1
/* prologue: Signal */
/* frame size = 0 */
/* stack size = 0...3 */
.L__stack_usage = 0 + __gcc_isr.n_pushed
/* epilogue start */
	__gcc_isr 2
	reti
	__gcc_isr 0,r0
	.size	__vector_7, .-__vector_7
.global	__vector_8
	.type	__vector_8, @function
__vector_8:
	__gcc_isr 1
/* prologue: Signal */
/* frame size = 0 */
/* stack size = 0...3 */
.L__stack_usage = 0 + __gcc_isr.n_pushed
/* epilogue start */
	__gcc_isr 2
	reti
	__gcc_isr 0,r0
	.size	__vector_8, .-__vector_8
	.section	.text.startup,"ax",@progbits
	.type	_GLOBAL__sub_I__ZN9Interrupt17interruptCallbackE, @function
_GLOBAL__sub_I__ZN9Interrupt17interruptCallbackE:
/* prologue: function */
/* frame size = 0 */
/* stack size = 0 */
.L__stack_usage = 0
	ldi r30,lo8(_ZN9Interrupt17interruptCallbackE)
	ldi r31,hi8(_ZN9Interrupt17interruptCallbackE)
	std Z+1,__zero_reg__
	st Z,__zero_reg__
	std Z+3,__zero_reg__
	std Z+2,__zero_reg__
	std Z+5,__zero_reg__
	std Z+4,__zero_reg__
	std Z+7,__zero_reg__
	std Z+6,__zero_reg__
	std Z+9,__zero_reg__
	std Z+8,__zero_reg__
	std Z+11,__zero_reg__
	std Z+10,__zero_reg__
	std Z+13,__zero_reg__
	std Z+12,__zero_reg__
	std Z+15,__zero_reg__
	std Z+14,__zero_reg__
	std Z+17,__zero_reg__
	std Z+16,__zero_reg__
	std Z+19,__zero_reg__
	std Z+18,__zero_reg__
	std Z+21,__zero_reg__
	std Z+20,__zero_reg__
	std Z+23,__zero_reg__
	std Z+22,__zero_reg__
	std Z+25,__zero_reg__
	std Z+24,__zero_reg__
	std Z+27,__zero_reg__
	std Z+26,__zero_reg__
	std Z+29,__zero_reg__
	std Z+28,__zero_reg__
	std Z+31,__zero_reg__
	std Z+30,__zero_reg__
	std Z+33,__zero_reg__
	std Z+32,__zero_reg__
	std Z+35,__zero_reg__
	std Z+34,__zero_reg__
	std Z+37,__zero_reg__
	std Z+36,__zero_reg__
	std Z+39,__zero_reg__
	std Z+38,__zero_reg__
	std Z+41,__zero_reg__
	std Z+40,__zero_reg__
	sts _ZN9Interrupt17interruptCallbackE+63+1,__zero_reg__
	sts _ZN9Interrupt17interruptCallbackE+63,__zero_reg__
	sts _ZN9Interrupt17interruptCallbackE+65+1,__zero_reg__
	sts _ZN9Interrupt17interruptCallbackE+65,__zero_reg__
	sts _ZN9Interrupt17interruptCallbackE+67+1,__zero_reg__
	sts _ZN9Interrupt17interruptCallbackE+67,__zero_reg__
	sts _ZN9Interrupt17interruptCallbackE+69+1,__zero_reg__
	sts _ZN9Interrupt17interruptCallbackE+69,__zero_reg__
	sts _ZN9Interrupt17interruptCallbackE+71+1,__zero_reg__
	sts _ZN9Interrupt17interruptCallbackE+71,__zero_reg__
	sts _ZN9Interrupt17interruptCallbackE+73+1,__zero_reg__
	sts _ZN9Interrupt17interruptCallbackE+73,__zero_reg__
	ldi r24,lo8(7)
	ldi r30,lo8(pcint_vect+84)
	ldi r31,hi8(pcint_vect+84)
	ldi r26,lo8(vectB)
	ldi r27,hi8(vectB)
	0:
	ld r0,Z+
	st X+,r0
	dec r24
	brne 0b
	ldi r24,lo8(7)
	ldi r30,lo8(pcint_vect+77)
	ldi r31,hi8(pcint_vect+77)
	ldi r26,lo8(vectB+7)
	ldi r27,hi8(vectB+7)
	0:
	ld r0,Z+
	st X+,r0
	dec r24
	brne 0b
	ldi r24,lo8(7)
	ldi r30,lo8(pcint_vect+70)
	ldi r31,hi8(pcint_vect+70)
	ldi r26,lo8(vectB+14)
	ldi r27,hi8(vectB+14)
	0:
	ld r0,Z+
	st X+,r0
	dec r24
	brne 0b
	ldi r24,lo8(7)
	ldi r30,lo8(pcint_vect+63)
	ldi r31,hi8(pcint_vect+63)
	ldi r26,lo8(vectB+21)
	ldi r27,hi8(vectB+21)
	0:
	ld r0,Z+
	st X+,r0
	dec r24
	brne 0b
	ldi r24,lo8(7)
	ldi r30,lo8(pcint_vect+21)
	ldi r31,hi8(pcint_vect+21)
	ldi r26,lo8(vectB+28)
	ldi r27,hi8(vectB+28)
	0:
	ld r0,Z+
	st X+,r0
	dec r24
	brne 0b
	ldi r24,lo8(7)
	ldi r30,lo8(pcint_vect+28)
	ldi r31,hi8(pcint_vect+28)
	ldi r26,lo8(vectB+35)
	ldi r27,hi8(vectB+35)
	0:
	ld r0,Z+
	st X+,r0
	dec r24
	brne 0b
	ldi r24,lo8(7)
	ldi r30,lo8(pcint_vect+35)
	ldi r31,hi8(pcint_vect+35)
	ldi r26,lo8(vectB+42)
	ldi r27,hi8(vectB+42)
	0:
	ld r0,Z+
	st X+,r0
	dec r24
	brne 0b
	ldi r24,lo8(7)
	ldi r30,lo8(pcint_vect+42)
	ldi r31,hi8(pcint_vect+42)
	ldi r26,lo8(vectB+49)
	ldi r27,hi8(vectB+49)
	0:
	ld r0,Z+
	st X+,r0
	dec r24
	brne 0b
	ldi r24,lo8(7)
	ldi r30,lo8(pcint_vect+91)
	ldi r31,hi8(pcint_vect+91)
	ldi r26,lo8(vectK)
	ldi r27,hi8(vectK)
	0:
	ld r0,Z+
	st X+,r0
	dec r24
	brne 0b
	ldi r24,lo8(7)
	ldi r30,lo8(pcint_vect+98)
	ldi r31,hi8(pcint_vect+98)
	ldi r26,lo8(vectK+7)
	ldi r27,hi8(vectK+7)
	0:
	ld r0,Z+
	st X+,r0
	dec r24
	brne 0b
	ldi r24,lo8(7)
	ldi r30,lo8(pcint_vect+105)
	ldi r31,hi8(pcint_vect+105)
	ldi r26,lo8(vectK+14)
	ldi r27,hi8(vectK+14)
	0:
	ld r0,Z+
	st X+,r0
	dec r24
	brne 0b
	ldi r24,lo8(7)
	ldi r30,lo8(pcint_vect+112)
	ldi r31,hi8(pcint_vect+112)
	ldi r26,lo8(vectK+21)
	ldi r27,hi8(vectK+21)
	0:
	ld r0,Z+
	st X+,r0
	dec r24
	brne 0b
	ldi r24,lo8(7)
	ldi r30,lo8(pcint_vect+119)
	ldi r31,hi8(pcint_vect+119)
	ldi r26,lo8(vectK+28)
	ldi r27,hi8(vectK+28)
	0:
	ld r0,Z+
	st X+,r0
	dec r24
	brne 0b
	ldi r24,lo8(7)
	ldi r30,lo8(pcint_vect+126)
	ldi r31,hi8(pcint_vect+126)
	ldi r26,lo8(vectK+35)
	ldi r27,hi8(vectK+35)
	0:
	ld r0,Z+
	st X+,r0
	dec r24
	brne 0b
	ldi r24,lo8(7)
	ldi r30,lo8(pcint_vect+133)
	ldi r31,hi8(pcint_vect+133)
	ldi r26,lo8(vectK+42)
	ldi r27,hi8(vectK+42)
	0:
	ld r0,Z+
	st X+,r0
	dec r24
	brne 0b
	ldi r24,lo8(7)
	ldi r30,lo8(pcint_vect+140)
	ldi r31,hi8(pcint_vect+140)
	ldi r26,lo8(vectK+49)
	ldi r27,hi8(vectK+49)
	0:
	ld r0,Z+
	st X+,r0
	dec r24
	brne 0b
	ldi r24,lo8(7)
	ldi r30,lo8(pcint_vect+56)
	ldi r31,hi8(pcint_vect+56)
	ldi r26,lo8(vectJ)
	ldi r27,hi8(vectJ)
	0:
	ld r0,Z+
	st X+,r0
	dec r24
	brne 0b
	ldi r24,lo8(7)
	ldi r30,lo8(pcint_vect+49)
	ldi r31,hi8(pcint_vect+49)
	ldi r26,lo8(vectJ+7)
	ldi r27,hi8(vectJ+7)
	0:
	ld r0,Z+
	st X+,r0
	dec r24
	brne 0b
	in r24,0x3
	sts port_b_history,r24
	lds r24,259
	sts port_j_history,r24
	lds r24,262
	sts port_k_history,r24
/* epilogue start */
	ret
	.size	_GLOBAL__sub_I__ZN9Interrupt17interruptCallbackE, .-_GLOBAL__sub_I__ZN9Interrupt17interruptCallbackE
	.global __do_global_ctors
	.section .ctors,"a",@progbits
	.p2align	1
	.word	gs(_GLOBAL__sub_I__ZN9Interrupt17interruptCallbackE)
.global	port_k_history
	.section .bss
	.type	port_k_history, @object
	.size	port_k_history, 1
port_k_history:
	.zero	1
.global	port_j_history
	.type	port_j_history, @object
	.size	port_j_history, 1
port_j_history:
	.zero	1
.global	port_b_history
	.type	port_b_history, @object
	.size	port_b_history, 1
port_b_history:
	.zero	1
.global	int_vect
	.data
	.type	int_vect, @object
	.size	int_vect, 66
int_vect:
	.byte	2
	.byte	1
	.word	_ZN9Interrupt17interruptCallbackE+71
	.word	_ZN9Interrupt17interruptCallbackE+79
	.byte	0
	.byte	1
	.byte	2
	.byte	3
	.byte	4
	.byte	3
	.byte	1
	.word	_ZN9Interrupt17interruptCallbackE+73
	.word	_ZN9Interrupt17interruptCallbackE+80
	.byte	0
	.byte	4
	.byte	8
	.byte	12
	.byte	5
	.byte	18
	.byte	0
	.word	_ZN9Interrupt17interruptCallbackE+69
	.word	_ZN9Interrupt17interruptCallbackE+78
	.byte	0
	.byte	64
	.byte	-128
	.byte	-64
	.byte	3
	.byte	19
	.byte	0
	.word	_ZN9Interrupt17interruptCallbackE+67
	.word	_ZN9Interrupt17interruptCallbackE+77
	.byte	0
	.byte	16
	.byte	32
	.byte	48
	.byte	2
	.byte	20
	.byte	0
	.word	_ZN9Interrupt17interruptCallbackE+65
	.word	_ZN9Interrupt17interruptCallbackE+76
	.byte	0
	.byte	4
	.byte	8
	.byte	12
	.byte	1
	.byte	21
	.byte	0
	.word	_ZN9Interrupt17interruptCallbackE+63
	.word	_ZN9Interrupt17interruptCallbackE+75
	.byte	0
	.byte	1
	.byte	2
	.byte	3
	.byte	0
.global	vectJ
	.section .bss
	.type	vectJ, @object
	.size	vectJ, 14
vectJ:
	.zero	14
.global	vectK
	.type	vectK, @object
	.size	vectK, 56
vectK:
	.zero	56
.global	vectB
	.type	vectB, @object
	.size	vectB, 56
vectB:
	.zero	56
.global	pcint_vect
	.data
	.type	pcint_vect, @object
	.size	pcint_vect, 147
pcint_vect:
	.byte	0
	.byte	1
	.byte	0
	.word	_ZN9Interrupt17interruptCallbackE
	.word	_ZN9Interrupt17interruptCallbackE+42
	.byte	1
	.byte	0
	.byte	3
	.word	_ZN9Interrupt17interruptCallbackE+2
	.word	_ZN9Interrupt17interruptCallbackE+43
	.byte	6
	.byte	1
	.byte	0
	.word	_ZN9Interrupt17interruptCallbackE+4
	.word	_ZN9Interrupt17interruptCallbackE+44
	.byte	10
	.byte	0
	.byte	4
	.word	_ZN9Interrupt17interruptCallbackE+6
	.word	_ZN9Interrupt17interruptCallbackE+51
	.byte	11
	.byte	0
	.byte	5
	.word	_ZN9Interrupt17interruptCallbackE+8
	.word	_ZN9Interrupt17interruptCallbackE+52
	.byte	12
	.byte	0
	.byte	6
	.word	_ZN9Interrupt17interruptCallbackE+10
	.word	_ZN9Interrupt17interruptCallbackE+53
	.byte	13
	.byte	0
	.byte	7
	.word	_ZN9Interrupt17interruptCallbackE+12
	.word	_ZN9Interrupt17interruptCallbackE+54
	.byte	14
	.byte	1
	.byte	2
	.word	_ZN9Interrupt17interruptCallbackE+14
	.word	_ZN9Interrupt17interruptCallbackE+46
	.byte	15
	.byte	1
	.byte	1
	.word	_ZN9Interrupt17interruptCallbackE+16
	.word	_ZN9Interrupt17interruptCallbackE+45
	.byte	50
	.byte	0
	.byte	3
	.word	_ZN9Interrupt17interruptCallbackE+18
	.word	_ZN9Interrupt17interruptCallbackE+50
	.byte	51
	.byte	0
	.byte	2
	.word	_ZN9Interrupt17interruptCallbackE+20
	.word	_ZN9Interrupt17interruptCallbackE+49
	.byte	52
	.byte	0
	.byte	1
	.word	_ZN9Interrupt17interruptCallbackE+22
	.word	_ZN9Interrupt17interruptCallbackE+48
	.byte	53
	.byte	0
	.byte	0
	.word	_ZN9Interrupt17interruptCallbackE+24
	.word	_ZN9Interrupt17interruptCallbackE+47
	.byte	62
	.byte	2
	.byte	0
	.word	_ZN9Interrupt17interruptCallbackE+26
	.word	_ZN9Interrupt17interruptCallbackE+55
	.byte	63
	.byte	2
	.byte	1
	.word	_ZN9Interrupt17interruptCallbackE+28
	.word	_ZN9Interrupt17interruptCallbackE+56
	.byte	64
	.byte	2
	.byte	2
	.word	_ZN9Interrupt17interruptCallbackE+30
	.word	_ZN9Interrupt17interruptCallbackE+57
	.byte	65
	.byte	2
	.byte	3
	.word	_ZN9Interrupt17interruptCallbackE+32
	.word	_ZN9Interrupt17interruptCallbackE+58
	.byte	66
	.byte	2
	.byte	4
	.word	_ZN9Interrupt17interruptCallbackE+34
	.word	_ZN9Interrupt17interruptCallbackE+59
	.byte	67
	.byte	2
	.byte	5
	.word	_ZN9Interrupt17interruptCallbackE+36
	.word	_ZN9Interrupt17interruptCallbackE+60
	.byte	68
	.byte	2
	.byte	6
	.word	_ZN9Interrupt17interruptCallbackE+38
	.word	_ZN9Interrupt17interruptCallbackE+61
	.byte	69
	.byte	2
	.byte	7
	.word	_ZN9Interrupt17interruptCallbackE+40
	.word	_ZN9Interrupt17interruptCallbackE+62
.global	_ZN9Interrupt17interruptCallbackE
	.section .bss
	.type	_ZN9Interrupt17interruptCallbackE, @object
	.size	_ZN9Interrupt17interruptCallbackE, 81
_ZN9Interrupt17interruptCallbackE:
	.zero	81
	.section	.progmem.data,"a",@progbits
	.type	_ZL16_flashMappedPort, @object
	.size	_ZL16_flashMappedPort, 350
_ZL16_flashMappedPort:
	.word	44
	.byte	0
	.word	4
	.word	44
	.byte	1
	.word	4
	.word	44
	.byte	4
	.word	11520
	.word	44
	.byte	5
	.word	11776
	.word	50
	.byte	5
	.word	8448
	.word	44
	.byte	3
	.word	11264
	.word	256
	.byte	3
	.word	12288
	.word	256
	.byte	4
	.word	12544
	.word	256
	.byte	5
	.word	12800
	.word	256
	.byte	6
	.word	10496
	.word	35
	.byte	4
	.word	10240
	.word	35
	.byte	5
	.word	9216
	.word	35
	.byte	6
	.word	9472
	.word	35
	.byte	7
	.word	9728
	.word	259
	.byte	1
	.word	7
	.word	259
	.byte	0
	.word	7
	.word	256
	.byte	1
	.word	6
	.word	256
	.byte	0
	.word	6
	.word	41
	.byte	3
	.word	5
	.word	41
	.byte	2
	.word	5
	.word	41
	.byte	1
	.word	0
	.word	41
	.byte	0
	.word	0
	.word	32
	.byte	0
	.word	0
	.word	32
	.byte	1
	.word	0
	.word	32
	.byte	2
	.word	0
	.word	32
	.byte	3
	.word	0
	.word	32
	.byte	4
	.word	0
	.word	32
	.byte	5
	.word	0
	.word	32
	.byte	6
	.word	0
	.word	32
	.byte	7
	.word	0
	.word	38
	.byte	7
	.word	0
	.word	38
	.byte	6
	.word	0
	.word	38
	.byte	5
	.word	0
	.word	38
	.byte	4
	.word	0
	.word	38
	.byte	3
	.word	0
	.word	38
	.byte	2
	.word	0
	.word	38
	.byte	1
	.word	0
	.word	38
	.byte	0
	.word	0
	.word	41
	.byte	7
	.word	0
	.word	50
	.byte	2
	.word	0
	.word	50
	.byte	1
	.word	0
	.word	50
	.byte	0
	.word	0
	.word	265
	.byte	7
	.word	0
	.word	265
	.byte	6
	.word	0
	.word	265
	.byte	5
	.word	13824
	.word	265
	.byte	4
	.word	13568
	.word	265
	.byte	3
	.word	13312
	.word	265
	.byte	2
	.word	0
	.word	265
	.byte	1
	.word	0
	.word	265
	.byte	0
	.word	0
	.word	35
	.byte	3
	.word	0
	.word	35
	.byte	2
	.word	0
	.word	35
	.byte	1
	.word	0
	.word	35
	.byte	0
	.word	0
	.word	47
	.byte	0
	.word	128
	.word	47
	.byte	1
	.word	136
	.word	47
	.byte	2
	.word	144
	.word	47
	.byte	3
	.word	152
	.word	47
	.byte	4
	.word	160
	.word	47
	.byte	5
	.word	168
	.word	47
	.byte	6
	.word	176
	.word	47
	.byte	7
	.word	184
	.word	262
	.byte	0
	.word	192
	.word	262
	.byte	1
	.word	200
	.word	262
	.byte	2
	.word	208
	.word	262
	.byte	3
	.word	216
	.word	262
	.byte	4
	.word	224
	.word	262
	.byte	5
	.word	232
	.word	262
	.byte	6
	.word	240
	.word	262
	.byte	7
	.word	248
	.ident	"GCC: (GNU) 8.2.0"
.global __do_copy_data
.global __do_clear_bss
