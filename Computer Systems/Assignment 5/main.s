	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15, 4	sdk_version 10, 15, 4
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movl	$0, -4(%rbp)
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	leaq	L_.str.1(%rip), %rdi
	leaq	-16(%rbp), %rsi
	leaq	-24(%rbp), %rdx
	movb	$0, %al
	callq	_scanf
	cmpl	$0, %eax
	je	LBB0_3
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movq	-16(%rbp), %rsi
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rdi
	movq	-24(%rbp), %rax
	movq	%rsi, -32(%rbp)         ## 8-byte Spill
	movq	%rax, %rsi
	movq	%rdx, -40(%rbp)         ## 8-byte Spill
	callq	_multiply
	leaq	L_.str.2(%rip), %rdi
	movq	-32(%rbp), %rsi         ## 8-byte Reload
	movq	-40(%rbp), %rdx         ## 8-byte Reload
	movq	%rax, %rcx
	movb	$0, %al
	callq	_printf
	leaq	L_.str(%rip), %rdi
	movl	%eax, -44(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	jmp	LBB0_1
LBB0_3:
	xorl	%eax, %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"> "

L_.str.1:                               ## @.str.1
	.asciz	"%ld %ld"

L_.str.2:                               ## @.str.2
	.asciz	" %ld * %ld = %ld\n"


.subsections_via_symbols
