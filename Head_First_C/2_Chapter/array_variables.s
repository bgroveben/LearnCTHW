/*
* This is the assembly code output generated by running:
* => gcc -S array_variables.c
*/
	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi0:
	.cfi_def_cfa_offset 16
Lcfi1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi2:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	leaq	L_.str(%rip), %rdi
	leaq	-32(%rbp), %rsi
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -36(%rbp)
	movq	L_main.quote(%rip), %rax
	movq	%rax, -32(%rbp)
	movq	L_main.quote+8(%rip), %rax
	movq	%rax, -24(%rbp)
	movl	L_main.quote+16(%rip), %ecx
	movl	%ecx, -16(%rbp)
	movw	L_main.quote+20(%rip), %dx
	movw	%dx, -12(%rbp)
	movb	L_main.quote+22(%rip), %r8b
	movb	%r8b, -10(%rbp)
	movb	$0, %al
	callq	_printf
	movq	___stack_chk_guard@GOTPCREL(%rip), %rsi
	movq	(%rsi), %rsi
	movq	-8(%rbp), %rdi
	cmpq	%rdi, %rsi
	movl	%eax, -40(%rbp)         ## 4-byte Spill
	jne	LBB0_2
## BB#1:
	xorl	%eax, %eax
	addq	$48, %rsp
	popq	%rbp
	retq
LBB0_2:
	callq	___stack_chk_fail
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
	.p2align	4               ## @main.quote
L_main.quote:
	.asciz	"Cookies make you sexy."

L_.str:                                 ## @.str
	.asciz	"The quote string is stored at : %p\n"


.subsections_via_symbols
