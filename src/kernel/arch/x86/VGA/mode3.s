	.file	"mode3.cpp"
	.text
	.globl	_ZN3VGA3clsEv
	.type	_ZN3VGA3clsEv, @function
_ZN3VGA3clsEv:
.LFB3:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	call	__x86.get_pc_thunk.bx
	addl	$_GLOBAL_OFFSET_TABLE_, %ebx
	movl	$753664, %ecx
	jmp	.L3
.L8:
	addl	$2, %ecx
	cmpl	$753824, %ecx
	je	.L7
.L3:
	leal	4000(%ecx), %edx
	movl	%ecx, %eax
.L2:
	movw	$15, (%eax)
	addl	$160, %eax
	cmpl	%edx, %eax
	jne	.L2
	jmp	.L8
.L7:
	movb	$0, 1+_ZN3VGA6cursorE@GOTOFF(%ebx)
	movb	$0, _ZN3VGA6cursorE@GOTOFF(%ebx)
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE3:
	.size	_ZN3VGA3clsEv, .-_ZN3VGA3clsEv
	.globl	_ZN3VGA10scrollOnceEv
	.type	_ZN3VGA10scrollOnceEv, @function
_ZN3VGA10scrollOnceEv:
.LFB4:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	call	__x86.get_pc_thunk.bx
	addl	$_GLOBAL_OFFSET_TABLE_, %ebx
	movl	$753664, %eax
.L11:
	leal	160(%eax), %ecx
.L10:
	movzwl	160(%eax), %edx
	movw	%dx, (%eax)
	addl	$2, %eax
	cmpl	%ecx, %eax
	jne	.L10
	cmpl	$757504, %eax
	jne	.L11
.L12:
	movw	$15, (%eax)
	addl	$2, %eax
	cmpl	$757664, %eax
	jne	.L12
	movb	$0, _ZN3VGA6cursorE@GOTOFF(%ebx)
	subb	$1, 1+_ZN3VGA6cursorE@GOTOFF(%ebx)
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE4:
	.size	_ZN3VGA10scrollOnceEv, .-_ZN3VGA10scrollOnceEv
	.globl	_ZN3VGA5putchEhhcNS_5colorES0_
	.type	_ZN3VGA5putchEhhcNS_5colorES0_, @function
_ZN3VGA5putchEhhcNS_5colorES0_:
.LFB1:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$4, %esp
	.cfi_def_cfa_offset 16
	call	__x86.get_pc_thunk.cx
	addl	$_GLOBAL_OFFSET_TABLE_, %ecx
	movl	16(%esp), %ebx
	movl	20(%esp), %edx
	movl	24(%esp), %eax
	cmpb	$10, %al
	je	.L22
	movzbl	%dl, %edx
	leal	(%edx,%edx,4), %edx
	sall	$4, %edx
	movzbl	%bl, %ebx
	leal	376832(%edx,%ebx), %ebx
	addl	%ebx, %ebx
	movl	32(%esp), %edx
	sall	$4, %edx
	movl	%edx, %esi
	andl	$4080, %esi
	movl	28(%esp), %edx
	andl	$15, %edx
	orl	%esi, %edx
	sall	$8, %edx
	cbtw
	orl	%edx, %eax
	movw	%ax, (%ebx)
	movzbl	_ZN3VGA6cursorE@GOTOFF(%ecx), %eax
	movb	%al, 3(%esp)
	addl	$1, %eax
	cmpb	$80, %al
	je	.L20
	movb	%al, _ZN3VGA6cursorE@GOTOFF(%ecx)
.L17:
	addl	$4, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
.L22:
	.cfi_restore_state
	movb	$0, _ZN3VGA6cursorE@GOTOFF(%ecx)
	movzbl	1+_ZN3VGA6cursorE@GOTOFF(%ecx), %eax
	movb	%al, 3(%esp)
	addl	$1, %eax
	movb	%al, 1+_ZN3VGA6cursorE@GOTOFF(%ecx)
	cmpb	$24, %al
	jbe	.L17
	call	_ZN3VGA10scrollOnceEv
	jmp	.L17
.L20:
	movb	$0, _ZN3VGA6cursorE@GOTOFF(%ecx)
	movzbl	1+_ZN3VGA6cursorE@GOTOFF(%ecx), %eax
	movb	%al, 3(%esp)
	addl	$1, %eax
	movb	%al, 1+_ZN3VGA6cursorE@GOTOFF(%ecx)
	cmpb	$24, %al
	jbe	.L17
	call	_ZN3VGA10scrollOnceEv
	jmp	.L17
	.cfi_endproc
.LFE1:
	.size	_ZN3VGA5putchEhhcNS_5colorES0_, .-_ZN3VGA5putchEhhcNS_5colorES0_
	.globl	_ZN3VGA4putsEPKc
	.type	_ZN3VGA4putsEPKc, @function
_ZN3VGA4putsEPKc:
.LFB2:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	call	__x86.get_pc_thunk.si
	addl	$_GLOBAL_OFFSET_TABLE_, %esi
	movl	16(%esp), %ebx
	movzbl	(%ebx), %eax
	testb	%al, %al
	je	.L23
	leal	_ZN3VGA6cursorE@GOTOFF, %edi
.L25:
	pushl	$0
	.cfi_def_cfa_offset 20
	pushl	$15
	.cfi_def_cfa_offset 24
	movsbl	%al, %eax
	pushl	%eax
	.cfi_def_cfa_offset 28
	movzbl	1(%esi,%edi), %eax
	pushl	%eax
	.cfi_def_cfa_offset 32
	movzbl	(%esi,%edi), %eax
	pushl	%eax
	.cfi_def_cfa_offset 36
	call	_ZN3VGA5putchEhhcNS_5colorES0_
	addl	$1, %ebx
	movzbl	(%ebx), %eax
	addl	$20, %esp
	.cfi_def_cfa_offset 16
	testb	%al, %al
	jne	.L25
.L23:
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE2:
	.size	_ZN3VGA4putsEPKc, .-_ZN3VGA4putsEPKc
	.globl	_ZN3VGA4putiEii
	.type	_ZN3VGA4putiEii, @function
_ZN3VGA4putiEii:
.LFB0:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$40, %esp
	.cfi_def_cfa_offset 52
	call	__x86.get_pc_thunk.bx
	addl	$_GLOBAL_OFFSET_TABLE_, %ebx
	movb	$0, 35(%esp)
	pushl	56(%esp)
	.cfi_def_cfa_offset 56
	leal	20(%esp), %esi
	pushl	%esi
	.cfi_def_cfa_offset 60
	pushl	60(%esp)
	.cfi_def_cfa_offset 64
	call	itoa@PLT
	movl	%esi, (%esp)
	call	_ZN3VGA4putsEPKc
	addl	$52, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE0:
	.size	_ZN3VGA4putiEii, .-_ZN3VGA4putiEii
	.local	_ZN3VGA6cursorE
	.comm	_ZN3VGA6cursorE,2,1
	.section	.text.__x86.get_pc_thunk.cx,"axG",@progbits,__x86.get_pc_thunk.cx,comdat
	.globl	__x86.get_pc_thunk.cx
	.hidden	__x86.get_pc_thunk.cx
	.type	__x86.get_pc_thunk.cx, @function
__x86.get_pc_thunk.cx:
.LFB5:
	.cfi_startproc
	movl	(%esp), %ecx
	ret
	.cfi_endproc
.LFE5:
	.section	.text.__x86.get_pc_thunk.bx,"axG",@progbits,__x86.get_pc_thunk.bx,comdat
	.globl	__x86.get_pc_thunk.bx
	.hidden	__x86.get_pc_thunk.bx
	.type	__x86.get_pc_thunk.bx, @function
__x86.get_pc_thunk.bx:
.LFB6:
	.cfi_startproc
	movl	(%esp), %ebx
	ret
	.cfi_endproc
.LFE6:
	.section	.text.__x86.get_pc_thunk.si,"axG",@progbits,__x86.get_pc_thunk.si,comdat
	.globl	__x86.get_pc_thunk.si
	.hidden	__x86.get_pc_thunk.si
	.type	__x86.get_pc_thunk.si, @function
__x86.get_pc_thunk.si:
.LFB7:
	.cfi_startproc
	movl	(%esp), %esi
	ret
	.cfi_endproc
.LFE7:
	.ident	"GCC: (Debian 7.2.0-7) 7.2.0"
	.section	.note.GNU-stack,"",@progbits
