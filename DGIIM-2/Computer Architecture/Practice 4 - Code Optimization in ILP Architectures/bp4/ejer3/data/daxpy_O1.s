	.file	"daxpy.c"
	.text
	.globl	daxpy
	.type	daxpy, @function
daxpy:
.LFB39:
	.cfi_startproc
	endbr64
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	movq	%rdi, %rbx
	movq	%rsi, %rbp
	movl	%edx, %r12d
	movl	%ecx, %r14d
	movq	%r8, %rsi
	movq	%r9, %r13
	movl	$0, %edi
	call	clock_gettime@PLT
	testl	%r14d, %r14d
	je	.L2
	movl	%r14d, %ecx
	movl	$0, %eax
.L3:
	movl	%r12d, %edx
	imull	0(%rbp,%rax,4), %edx
	addl	%edx, (%rbx,%rax,4)
	addq	$1, %rax
	cmpq	%rcx, %rax
	jne	.L3
.L2:
	movq	%r13, %rsi
	movl	$0, %edi
	call	clock_gettime@PLT
	popq	%rbx
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
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
	.text
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
	subq	$56, %rsp
	.cfi_def_cfa_offset 112
	movq	%fs:40, %rax
	movq	%rax, 40(%rsp)
	xorl	%eax, %eax
	cmpl	$2, %edi
	jle	.L13
	movq	%rsi, %rbx
	movq	8(%rsi), %rdi
	movl	$10, %edx
	movl	$0, %esi
	call	strtol@PLT
	movq	%rax, %r13
	movq	16(%rbx), %rdi
	movl	$10, %edx
	movl	$0, %esi
	call	strtol@PLT
	movq	%rax, %r15
	movl	%r13d, %ebx
	salq	$2, %rbx
	movq	%rbx, %rdi
	call	malloc@PLT
	movq	%rax, %rbp
	movq	%rbx, %rdi
	call	malloc@PLT
	movq	%rax, %r12
	movl	$0, %edi
	call	time@PLT
	movq	%rax, %rdi
	call	srand@PLT
	testl	%r13d, %r13d
	je	.L8
	leal	-1(%r13), %r14d
	movl	$0, %ebx
.L9:
	call	rand@PLT
	movl	%eax, 0(%rbp,%rbx,4)
	call	rand@PLT
	movl	%eax, (%r12,%rbx,4)
	movq	%rbx, %rax
	addq	$1, %rbx
	cmpq	%r14, %rax
	jne	.L9
.L8:
	leaq	16(%rsp), %r9
	movq	%rsp, %r8
	movl	%r13d, %ecx
	movl	%r15d, %edx
	movq	%r12, %rsi
	movq	%rbp, %rdi
	call	daxpy
	movq	24(%rsp), %rax
	subq	8(%rsp), %rax
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rax, %xmm0
	divsd	.LC1(%rip), %xmm0
	movq	16(%rsp), %rax
	subq	(%rsp), %rax
	pxor	%xmm1, %xmm1
	cvtsi2sdq	%rax, %xmm1
	addsd	%xmm1, %xmm0
	movq	%xmm0, %rbx
	leal	-1(%r13), %ecx
	movl	%ecx, %eax
	movl	0(%rbp,%rax,4), %r8d
	movl	0(%rbp), %edx
	leaq	.LC2(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movq	%rbx, %xmm0
	leaq	.LC3(%rip), %rsi
	movl	$1, %edi
	movl	$1, %eax
	call	__printf_chk@PLT
	movq	%rbp, %rdi
	call	free@PLT
	movq	%r12, %rdi
	call	free@PLT
	movq	40(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L14
	movl	$0, %eax
	addq	$56, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
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
.L13:
	.cfi_restore_state
	movq	stderr(%rip), %rcx
	movl	$44, %edx
	movl	$1, %esi
	leaq	.LC0(%rip), %rdi
	call	fwrite@PLT
	movl	$1, %edi
	call	exit@PLT
.L14:
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
