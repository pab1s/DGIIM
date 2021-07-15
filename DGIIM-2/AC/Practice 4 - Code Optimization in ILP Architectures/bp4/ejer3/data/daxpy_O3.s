	.file	"daxpy.c"
	.text
	.p2align 4
	.globl	daxpy
	.type	daxpy, @function
daxpy:
.LFB39:
	.cfi_startproc
	endbr64
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	movq	%r9, %r14
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	movl	%edx, %r13d
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	movl	%ecx, %r12d
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	movq	%rsi, %rbp
	movq	%r8, %rsi
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	movq	%rdi, %rbx
	xorl	%edi, %edi
	call	clock_gettime@PLT
	testl	%r12d, %r12d
	je	.L2
	leaq	4(%rbp), %rdx
	movq	%rbx, %rax
	subq	%rdx, %rax
	cmpq	$8, %rax
	jbe	.L3
	leal	-1(%r12), %eax
	cmpl	$2, %eax
	jbe	.L3
	movd	%r13d, %xmm4
	movl	%r12d, %edx
	xorl	%eax, %eax
	pshufd	$0, %xmm4, %xmm2
	shrl	$2, %edx
	movdqa	%xmm2, %xmm3
	salq	$4, %rdx
	psrlq	$32, %xmm3
	.p2align 4,,10
	.p2align 3
.L4:
	movdqu	0(%rbp,%rax), %xmm0
	movdqu	0(%rbp,%rax), %xmm1
	psrlq	$32, %xmm0
	pmuludq	%xmm2, %xmm1
	pmuludq	%xmm3, %xmm0
	pshufd	$8, %xmm1, %xmm1
	pshufd	$8, %xmm0, %xmm0
	punpckldq	%xmm0, %xmm1
	movdqu	(%rbx,%rax), %xmm0
	paddd	%xmm1, %xmm0
	movups	%xmm0, (%rbx,%rax)
	addq	$16, %rax
	cmpq	%rdx, %rax
	jne	.L4
	movl	%r12d, %eax
	andl	$-4, %eax
	testb	$3, %r12b
	je	.L2
	movl	%eax, %edx
	movl	0(%rbp,%rdx,4), %ecx
	imull	%r13d, %ecx
	addl	%ecx, (%rbx,%rdx,4)
	leal	1(%rax), %edx
	cmpl	%edx, %r12d
	jbe	.L2
	movl	0(%rbp,%rdx,4), %ecx
	addl	$2, %eax
	imull	%r13d, %ecx
	addl	%ecx, (%rbx,%rdx,4)
	cmpl	%eax, %r12d
	jbe	.L2
	imull	0(%rbp,%rax,4), %r13d
	addl	%r13d, (%rbx,%rax,4)
.L2:
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	movq	%r14, %rsi
	popq	%rbp
	.cfi_def_cfa_offset 32
	xorl	%edi, %edi
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	jmp	clock_gettime@PLT
	.p2align 4,,10
	.p2align 3
.L3:
	.cfi_restore_state
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L6:
	movl	0(%rbp,%rax,4), %edx
	imull	%r13d, %edx
	addl	%edx, (%rbx,%rax,4)
	addq	$1, %rax
	cmpq	%r12, %rax
	jne	.L6
	jmp	.L2
	.cfi_endproc
.LFE39:
	.size	daxpy, .-daxpy
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"ERROR: Falta tama\303\261o del vector y constante\n"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC2:
	.string	"y[0] = %i, y[%i] = %i\n"
.LC3:
	.string	"\nTiempo (seg.) = %11.9f\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB40:
	.cfi_startproc
	endbr64
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$72, %rsp
	.cfi_def_cfa_offset 128
	movq	%fs:40, %rax
	movq	%rax, 56(%rsp)
	xorl	%eax, %eax
	cmpl	$2, %edi
	jle	.L28
	movq	8(%rsi), %rdi
	movq	%rsi, %rbx
	movl	$10, %edx
	xorl	%esi, %esi
	call	strtol@PLT
	movq	16(%rbx), %rdi
	xorl	%esi, %esi
	movl	$10, %edx
	movq	%rax, %r14
	call	strtol@PLT
	movl	%r14d, %r13d
	leaq	0(,%r13,4), %r12
	movq	%rax, %r15
	movq	%r12, %rdi
	call	malloc@PLT
	movq	%r12, %rdi
	movq	%rax, %rbp
	call	malloc@PLT
	xorl	%edi, %edi
	movq	%rax, %r12
	call	time@PLT
	movq	%rax, %rdi
	call	srand@PLT
	testl	%r14d, %r14d
	je	.L23
	xorl	%ebx, %ebx
	.p2align 4,,10
	.p2align 3
.L24:
	call	rand@PLT
	movl	%eax, 0(%rbp,%rbx,4)
	call	rand@PLT
	movl	%eax, (%r12,%rbx,4)
	addq	$1, %rbx
	cmpq	%rbx, %r13
	jne	.L24
.L23:
	leaq	32(%rsp), %r9
	leaq	16(%rsp), %r8
	movl	%r14d, %ecx
	movl	%r15d, %edx
	movq	%r12, %rsi
	movq	%rbp, %rdi
	call	daxpy
	pxor	%xmm0, %xmm0
	pxor	%xmm1, %xmm1
	movl	0(%rbp), %edx
	movq	40(%rsp), %rax
	subq	24(%rsp), %rax
	movl	$1, %edi
	leaq	.LC2(%rip), %rsi
	cvtsi2sdq	%rax, %xmm0
	movq	32(%rsp), %rax
	subq	16(%rsp), %rax
	divsd	.LC1(%rip), %xmm0
	cvtsi2sdq	%rax, %xmm1
	leal	-1(%r14), %eax
	movl	0(%rbp,%rax,4), %r8d
	movq	%rax, %rcx
	xorl	%eax, %eax
	addsd	%xmm1, %xmm0
	movsd	%xmm0, 8(%rsp)
	call	__printf_chk@PLT
	movsd	8(%rsp), %xmm0
	movl	$1, %edi
	leaq	.LC3(%rip), %rsi
	movl	$1, %eax
	call	__printf_chk@PLT
	movq	%rbp, %rdi
	call	free@PLT
	movq	%r12, %rdi
	call	free@PLT
	movq	56(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L29
	addq	$72, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.L28:
	.cfi_restore_state
	movq	stderr(%rip), %rcx
	movl	$44, %edx
	movl	$1, %esi
	leaq	.LC0(%rip), %rdi
	call	fwrite@PLT
	movl	$1, %edi
	call	exit@PLT
.L29:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE40:
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC1:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu 10.2.0-13ubuntu1) 10.2.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
