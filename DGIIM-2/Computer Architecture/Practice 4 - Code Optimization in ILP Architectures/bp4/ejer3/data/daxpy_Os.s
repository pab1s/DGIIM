	.file	"daxpy.c"
	.text
	.globl	daxpy
	.type	daxpy, @function
daxpy:
.LFB24:
	.cfi_startproc
	endbr64
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	movq	%rsi, %r14
	movq	%r8, %rsi
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
	movq	%r9, %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	movq	%rdi, %rbx
	xorl	%edi, %edi
	call	clock_gettime@PLT
	xorl	%eax, %eax
.L2:
	cmpl	%eax, %r12d
	jbe	.L6
	movl	(%r14,%rax,4), %edx
	imull	%r13d, %edx
	addl	%edx, (%rbx,%rax,4)
	incq	%rax
	jmp	.L2
.L6:
	popq	%rbx
	.cfi_def_cfa_offset 40
	movq	%rbp, %rsi
	xorl	%edi, %edi
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	jmp	clock_gettime@PLT
	.cfi_endproc
.LFE24:
	.size	daxpy, .-daxpy
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"ERROR: Falta tama\303\261o del vector y constante\n"
.LC2:
	.string	"y[0] = %i, y[%i] = %i\n"
.LC3:
	.string	"\nTiempo (seg.) = %11.9f\n"
	.section	.text.startup,"ax",@progbits
	.globl	main
	.type	main, @function
main:
.LFB25:
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
	jg	.L8
	movq	stderr(%rip), %rsi
	leaq	.LC0(%rip), %rdi
	call	fputs@PLT
	movl	$1, %edi
	call	exit@PLT
.L8:
	movq	8(%rsi), %rdi
	movq	%rsi, %rbp
	movl	$10, %edx
	xorl	%esi, %esi
	xorl	%r13d, %r13d
	call	strtol@PLT
	movq	16(%rbp), %rdi
	movl	$10, %edx
	xorl	%esi, %esi
	movq	%rax, %rbx
	movl	%eax, %r15d
	call	strtol@PLT
	movl	%ebx, %r12d
	salq	$2, %r12
	movq	%rax, %r14
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
.L9:
	cmpl	%r13d, %r15d
	jbe	.L13
	call	rand@PLT
	movl	%eax, 0(%rbp,%r13,4)
	call	rand@PLT
	movl	%eax, (%r12,%r13,4)
	incq	%r13
	jmp	.L9
.L13:
	leaq	40(%rsp), %r9
	leaq	24(%rsp), %r8
	movl	%ebx, %ecx
	movl	%r14d, %edx
	movq	%r12, %rsi
	movq	%rbp, %rdi
	call	daxpy
	movq	48(%rsp), %rax
	subq	32(%rsp), %rax
	leaq	.LC2(%rip), %rsi
	cvtsi2sdq	%rax, %xmm0
	movq	40(%rsp), %rax
	subq	24(%rsp), %rax
	divsd	.LC1(%rip), %xmm0
	cvtsi2sdq	%rax, %xmm1
	leal	-1(%rbx), %eax
	movl	0(%rbp), %edx
	movl	$1, %edi
	movl	0(%rbp,%rax,4), %r8d
	movq	%rax, %rcx
	xorl	%eax, %eax
	addsd	%xmm1, %xmm0
	movsd	%xmm0, 8(%rsp)
	call	__printf_chk@PLT
	movsd	8(%rsp), %xmm0
	leaq	.LC3(%rip), %rsi
	movb	$1, %al
	movl	$1, %edi
	call	__printf_chk@PLT
	movq	%rbp, %rdi
	call	free@PLT
	movq	%r12, %rdi
	call	free@PLT
	movq	56(%rsp), %rax
	subq	%fs:40, %rax
	je	.L11
	call	__stack_chk_fail@PLT
.L11:
	addq	$72, %rsp
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
	.cfi_endproc
.LFE25:
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
