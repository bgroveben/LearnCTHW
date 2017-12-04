# This is the assembly code from the array_variables file in Chapter 2.
# It has been copy-pasted from the terminal output of running:
# => otool -tV array_variables
# This error is thrown on every line of the instruction set:
# => error: unexpected token at start of statement 0000000100000eb0
# I have quite a bit to learn.
_main:
0000000100000eb0	pushq	%rbp
0000000100000eb1	movq	%rsp, %rbp
0000000100000eb4	subq	$0x30, %rsp
0000000100000eb8	leaq	0xc8(%rip), %rdi ## literal pool for: "The quote string is stored at : %p\n"
0000000100000ebf	leaq	-0x20(%rbp), %rsi
0000000100000ec3	movq	0x136(%rip), %rax ## literal pool symbol address: ___stack_chk_guard
0000000100000eca	movq	(%rax), %rax
0000000100000ecd	movq	%rax, -0x8(%rbp)
0000000100000ed1	movl	$0x0, -0x24(%rbp)
0000000100000ed8	movq	0x91(%rip), %rax ## literal pool for: "Cookies make you sexy."
0000000100000edf	movq	%rax, -0x20(%rbp)
0000000100000ee3	movq	0x8e(%rip), %rax ## literal pool for: "make you sexy."
0000000100000eea	movq	%rax, -0x18(%rbp)
0000000100000eee	movl	0x8c(%rip), %ecx ## literal pool for: " sexy."
0000000100000ef4	movl	%ecx, -0x10(%rbp)
0000000100000ef7	movw	0x86(%rip), %dx ## literal pool for: "exy."
0000000100000efe	movw	%dx, -0xc(%rbp)
0000000100000f02	movb	0x7d(%rip), %r8b ## literal pool for: ""
0000000100000f09	movb	%r8b, -0xa(%rbp)
0000000100000f0d	movb	$0x0, %al
0000000100000f0f	callq	0x100000f42 ## symbol stub for: _printf
0000000100000f14	movq	0xe5(%rip), %rsi ## literal pool symbol address: ___stack_chk_guard
0000000100000f1b	movq	(%rsi), %rsi
0000000100000f1e	movq	-0x8(%rbp), %rdi
0000000100000f22	cmpq	%rdi, %rsi
0000000100000f25	movl	%eax, -0x28(%rbp)
0000000100000f28	jne	0x100000f36
0000000100000f2e	xorl	%eax, %eax
0000000100000f30	addq	$0x30, %rsp
0000000100000f34	popq	%rbp
