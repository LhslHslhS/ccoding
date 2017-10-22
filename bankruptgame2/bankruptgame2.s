	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.section	__TEXT,__StaticInit,regular,pure_instructions
	.p2align	4, 0x90
___cxx_global_var_init:                 ## @__cxx_global_var_init
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
	subq	$32, %rsp
	leaq	_players(%rip), %rax
	movq	%rax, %rcx
	addq	$44, %rcx
	leaq	_chanhoPlayer(%rip), %rdx
	movl	$44, %esi
	movl	%esi, %edi
	leaq	_hyunseoPlayer(%rip), %r8
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	movq	%rax, %rdi
	movq	%r8, %rsi
	movq	-8(%rbp), %rax          ## 8-byte Reload
	movq	%rdx, -16(%rbp)         ## 8-byte Spill
	movq	%rax, %rdx
	movq	%rcx, -24(%rbp)         ## 8-byte Spill
	callq	_memcpy
	movq	-24(%rbp), %rdi         ## 8-byte Reload
	movq	-16(%rbp), %rsi         ## 8-byte Reload
	movq	-8(%rbp), %rdx          ## 8-byte Reload
	callq	_memcpy
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.p2align	4, 0x90
___cxx_global_var_init.1:               ## @__cxx_global_var_init.1
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi3:
	.cfi_def_cfa_offset 16
Lcfi4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi5:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%rbx
	subq	$72, %rsp
Lcfi6:
	.cfi_offset %rbx, -40
Lcfi7:
	.cfi_offset %r14, -32
Lcfi8:
	.cfi_offset %r15, -24
	leaq	_lands(%rip), %rax
	movq	%rax, %rcx
	addq	$496, %rcx              ## imm = 0x1F0
	leaq	_land5(%rip), %rdx
	movl	$124, %esi
	movl	%esi, %edi
	movq	%rax, %r8
	addq	$372, %r8               ## imm = 0x174
	leaq	_land4(%rip), %r9
	movq	%rax, %r10
	addq	$248, %r10
	leaq	_land3(%rip), %r11
	movq	%rax, %rbx
	addq	$124, %rbx
	leaq	_land2(%rip), %r14
	leaq	_land1(%rip), %r15
	movq	%rdi, -32(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	movq	%r15, %rsi
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	%rdx, -40(%rbp)         ## 8-byte Spill
	movq	%rax, %rdx
	movq	%r14, -48(%rbp)         ## 8-byte Spill
	movq	%rcx, -56(%rbp)         ## 8-byte Spill
	movq	%rbx, -64(%rbp)         ## 8-byte Spill
	movq	%r8, -72(%rbp)          ## 8-byte Spill
	movq	%r9, -80(%rbp)          ## 8-byte Spill
	movq	%r10, -88(%rbp)         ## 8-byte Spill
	movq	%r11, -96(%rbp)         ## 8-byte Spill
	callq	_memcpy
	movq	-64(%rbp), %rdi         ## 8-byte Reload
	movq	-48(%rbp), %rsi         ## 8-byte Reload
	movq	-32(%rbp), %rdx         ## 8-byte Reload
	callq	_memcpy
	movq	-88(%rbp), %rdi         ## 8-byte Reload
	movq	-96(%rbp), %rsi         ## 8-byte Reload
	movq	-32(%rbp), %rdx         ## 8-byte Reload
	callq	_memcpy
	movq	-72(%rbp), %rdi         ## 8-byte Reload
	movq	-80(%rbp), %rsi         ## 8-byte Reload
	movq	-32(%rbp), %rdx         ## 8-byte Reload
	callq	_memcpy
	movq	-56(%rbp), %rdi         ## 8-byte Reload
	movq	-40(%rbp), %rsi         ## 8-byte Reload
	movq	-32(%rbp), %rdx         ## 8-byte Reload
	callq	_memcpy
	addq	$72, %rsp
	popq	%rbx
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
	.cfi_endproc

	.p2align	4, 0x90
___cxx_global_var_init.2:               ## @__cxx_global_var_init.2
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi9:
	.cfi_def_cfa_offset 16
Lcfi10:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi11:
	.cfi_def_cfa_register %rbp
	pushq	%rbx
	subq	$56, %rsp
Lcfi12:
	.cfi_offset %rbx, -24
	leaq	_factories(%rip), %rax
	movq	%rax, %rcx
	addq	$372, %rcx              ## imm = 0x174
	leaq	_factory4(%rip), %rdx
	movl	$124, %esi
	movl	%esi, %edi
	movq	%rax, %r8
	addq	$248, %r8
	leaq	_factory3(%rip), %r9
	movq	%rax, %r10
	addq	$124, %r10
	leaq	_factory2(%rip), %r11
	leaq	_factory1(%rip), %rbx
	movq	%rdi, -16(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	movq	%rbx, %rsi
	movq	-16(%rbp), %rax         ## 8-byte Reload
	movq	%rdx, -24(%rbp)         ## 8-byte Spill
	movq	%rax, %rdx
	movq	%r11, -32(%rbp)         ## 8-byte Spill
	movq	%rcx, -40(%rbp)         ## 8-byte Spill
	movq	%r10, -48(%rbp)         ## 8-byte Spill
	movq	%r8, -56(%rbp)          ## 8-byte Spill
	movq	%r9, -64(%rbp)          ## 8-byte Spill
	callq	_memcpy
	movq	-48(%rbp), %rdi         ## 8-byte Reload
	movq	-32(%rbp), %rsi         ## 8-byte Reload
	movq	-16(%rbp), %rdx         ## 8-byte Reload
	callq	_memcpy
	movq	-56(%rbp), %rdi         ## 8-byte Reload
	movq	-64(%rbp), %rsi         ## 8-byte Reload
	movq	-16(%rbp), %rdx         ## 8-byte Reload
	callq	_memcpy
	movq	-40(%rbp), %rdi         ## 8-byte Reload
	movq	-24(%rbp), %rsi         ## 8-byte Reload
	movq	-16(%rbp), %rdx         ## 8-byte Reload
	callq	_memcpy
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	retq
	.cfi_endproc

	.p2align	4, 0x90
___cxx_global_var_init.3:               ## @__cxx_global_var_init.3
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi13:
	.cfi_def_cfa_offset 16
Lcfi14:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi15:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	leaq	_electricFactories(%rip), %rax
	movq	%rax, %rcx
	addq	$128, %rcx
	leaq	_electricFactory2(%rip), %rdx
	movl	$128, %esi
	movl	%esi, %edi
	leaq	_electricFactory1(%rip), %r8
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	movq	%rax, %rdi
	movq	%r8, %rsi
	movq	-8(%rbp), %rax          ## 8-byte Reload
	movq	%rdx, -16(%rbp)         ## 8-byte Spill
	movq	%rax, %rdx
	movq	%rcx, -24(%rbp)         ## 8-byte Spill
	callq	_memcpy
	movq	-24(%rbp), %rdi         ## 8-byte Reload
	movq	-16(%rbp), %rsi         ## 8-byte Reload
	movq	-8(%rbp), %rdx          ## 8-byte Reload
	callq	_memcpy
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__Z12playerInLandi
	.p2align	4, 0x90
__Z12playerInLandi:                     ## @_Z12playerInLandi
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi16:
	.cfi_def_cfa_offset 16
Lcfi17:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi18:
	.cfi_def_cfa_register %rbp
	subq	$80, %rsp
	movl	$1, %eax
	leaq	_lands(%rip), %rcx
	movl	%edi, -4(%rbp)
	movslq	-4(%rbp), %rdx
	imulq	$124, %rdx, %rdx
	addq	%rdx, %rcx
	movl	116(%rcx), %edi
	subl	_turn(%rip), %eax
	cmpl	%eax, %edi
	je	LBB4_2
## BB#1:
	leaq	_lands(%rip), %rax
	movslq	-4(%rbp), %rcx
	imulq	$124, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	$2, 116(%rax)
	jne	LBB4_3
LBB4_2:
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -16(%rbp)         ## 4-byte Spill
	jmp	LBB4_30
LBB4_3:
	leaq	L_.str.4(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.5(%rip), %rdi
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.6(%rip), %rdi
	movl	%eax, -24(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.7(%rip), %rdi
	leaq	-8(%rbp), %rsi
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	cmpl	$1, -8(%rbp)
	movl	%eax, -32(%rbp)         ## 4-byte Spill
	jne	LBB4_15
## BB#4:
	leaq	_lands(%rip), %rax
	movslq	-4(%rbp), %rcx
	imulq	$124, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	$10, 112(%rax)
	jne	LBB4_11
## BB#5:
	leaq	_lands(%rip), %rax
	movslq	-4(%rbp), %rcx
	imulq	$124, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	$0, 108(%rax)
	jne	LBB4_7
## BB#6:
	leaq	L_.str.8(%rip), %rdi
	leaq	_players(%rip), %rax
	movslq	_turn(%rip), %rcx
	imulq	$44, %rcx, %rcx
	addq	%rcx, %rax
	movsbl	20(%rax), %edx
	addl	$100, %edx
	movb	%dl, %sil
	movb	%sil, 20(%rax)
	movb	$0, %al
	callq	_printf
	movl	%eax, -36(%rbp)         ## 4-byte Spill
	callq	__Z7processv
	jmp	LBB4_10
LBB4_7:
	leaq	_lands(%rip), %rax
	movslq	-4(%rbp), %rcx
	imulq	$124, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	$1, 108(%rax)
	jne	LBB4_9
## BB#8:
	leaq	L_.str.8(%rip), %rdi
	leaq	_players(%rip), %rax
	movslq	_turn(%rip), %rcx
	imulq	$44, %rcx, %rcx
	addq	%rcx, %rax
	movsbl	21(%rax), %edx
	addl	$100, %edx
	movb	%dl, %sil
	movb	%sil, 21(%rax)
	movb	$0, %al
	callq	_printf
	movl	%eax, -40(%rbp)         ## 4-byte Spill
	callq	__Z7processv
LBB4_9:
	jmp	LBB4_10
LBB4_10:
	jmp	LBB4_14
LBB4_11:
	leaq	_lands(%rip), %rax
	movslq	-4(%rbp), %rcx
	imulq	$124, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	$10, 112(%rax)
	jge	LBB4_13
## BB#12:
	leaq	L_.str.9(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	-4(%rbp), %edi
	movl	%eax, -44(%rbp)         ## 4-byte Spill
	callq	__Z12playerInLandi
LBB4_13:
	jmp	LBB4_14
LBB4_14:
	jmp	LBB4_29
LBB4_15:
	cmpl	$2, -8(%rbp)
	jne	LBB4_22
## BB#16:
	leaq	L_.str.10(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.11(%rip), %rdi
	movl	%eax, -48(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.7(%rip), %rdi
	leaq	-12(%rbp), %rsi
	movl	%eax, -52(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	leaq	_players(%rip), %rsi
	movslq	_turn(%rip), %rdi
	imulq	$44, %rdi, %rdi
	addq	%rdi, %rsi
	movslq	-12(%rbp), %rdi
	movsbl	20(%rsi,%rdi), %ecx
	cmpl	$1, %ecx
	movl	%eax, -56(%rbp)         ## 4-byte Spill
	jge	LBB4_18
## BB#17:
	leaq	L_.str.12(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	-4(%rbp), %edi
	movl	%eax, -60(%rbp)         ## 4-byte Spill
	callq	__Z12playerInLandi
	jmp	LBB4_21
LBB4_18:
	leaq	_players(%rip), %rax
	movslq	_turn(%rip), %rcx
	imulq	$44, %rcx, %rcx
	addq	%rcx, %rax
	movslq	-12(%rbp), %rcx
	movsbl	20(%rax,%rcx), %edx
	cmpl	$1, %edx
	jl	LBB4_20
## BB#19:
	leaq	L_.str.13(%rip), %rdi
	leaq	_lands(%rip), %rax
	movl	-12(%rbp), %ecx
	movslq	-4(%rbp), %rdx
	imulq	$124, %rdx, %rdx
	addq	%rdx, %rax
	movl	%ecx, 108(%rax)
	movb	$0, %al
	callq	_printf
	movl	%eax, -64(%rbp)         ## 4-byte Spill
	callq	__Z7processv
LBB4_20:
	jmp	LBB4_21
LBB4_21:
	jmp	LBB4_28
LBB4_22:
	cmpl	$3, -8(%rbp)
	jne	LBB4_27
## BB#23:
	leaq	_players(%rip), %rax
	movslq	_turn(%rip), %rcx
	imulq	$44, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	$1000000, 12(%rax)      ## imm = 0xF4240
	jge	LBB4_25
## BB#24:
	leaq	L_.str.14(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -68(%rbp)         ## 4-byte Spill
	jmp	LBB4_26
LBB4_25:
	leaq	L_.str.15(%rip), %rdi
	leaq	_lands(%rip), %rax
	leaq	_players(%rip), %rcx
	movslq	_turn(%rip), %rdx
	imulq	$44, %rdx, %rdx
	addq	%rdx, %rcx
	movl	12(%rcx), %esi
	subl	$1000000, %esi          ## imm = 0xF4240
	movl	%esi, 12(%rcx)
	movslq	-4(%rbp), %rcx
	imulq	$124, %rcx, %rcx
	addq	%rcx, %rax
	movl	120(%rax), %esi
	addl	$1, %esi
	movl	%esi, 120(%rax)
	movb	$0, %al
	callq	_printf
	movl	%eax, -72(%rbp)         ## 4-byte Spill
LBB4_26:
	jmp	LBB4_27
LBB4_27:
	jmp	LBB4_28
LBB4_28:
	jmp	LBB4_29
LBB4_29:
	jmp	LBB4_30
LBB4_30:
	addq	$80, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__Z7processv
	.p2align	4, 0x90
__Z7processv:                           ## @_Z7processv
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi19:
	.cfi_def_cfa_offset 16
Lcfi20:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi21:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$1, %eax
	leaq	_menu(%rip), %rcx
	movl	$56, %edx
	movslq	_cursor(%rip), %rsi
	movb	$46, (%rcx,%rsi)
	movl	_cursor(%rip), %edi
	addl	$1, %edi
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	movl	%edi, %eax
	movl	%edx, -24(%rbp)         ## 4-byte Spill
	cltd
	movl	-24(%rbp), %edi         ## 4-byte Reload
	idivl	%edi
	movl	%edx, _cursor(%rip)
	movslq	_cursor(%rip), %rsi
	movb	$43, (%rcx,%rsi)
	movl	-20(%rbp), %edx         ## 4-byte Reload
	subl	_turn(%rip), %edx
	movl	%edx, _turn(%rip)
	movl	$0, -4(%rbp)
LBB5_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$5, -4(%rbp)
	jge	LBB5_6
## BB#2:                                ##   in Loop: Header=BB5_1 Depth=1
	leaq	_lands(%rip), %rax
	movslq	-4(%rbp), %rcx
	imulq	$124, %rcx, %rcx
	movq	%rax, %rdx
	addq	%rcx, %rdx
	movl	112(%rdx), %esi
	addl	$1, %esi
	movl	%esi, 112(%rdx)
	movslq	-4(%rbp), %rcx
	imulq	$124, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	$1, 120(%rax)
	jne	LBB5_4
## BB#3:                                ##   in Loop: Header=BB5_1 Depth=1
	leaq	_lands(%rip), %rax
	movslq	-4(%rbp), %rcx
	imulq	$124, %rcx, %rcx
	addq	%rcx, %rax
	movl	112(%rax), %edx
	addl	$1, %edx
	movl	%edx, 112(%rax)
LBB5_4:                                 ##   in Loop: Header=BB5_1 Depth=1
	jmp	LBB5_5
LBB5_5:                                 ##   in Loop: Header=BB5_1 Depth=1
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -4(%rbp)
	jmp	LBB5_1
LBB5_6:
	movl	_tax(%rip), %eax
	addl	$1, %eax
	movl	%eax, _tax(%rip)
	movl	_tax(%rip), %eax
	cmpl	_maxTurn(%rip), %eax
	jne	LBB5_8
## BB#7:
	leaq	L_.str.102(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	callq	__Z16playerInCityHallv
LBB5_8:
	movl	$0, -8(%rbp)
LBB5_9:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$10, -8(%rbp)
	jge	LBB5_12
## BB#10:                               ##   in Loop: Header=BB5_9 Depth=1
	callq	_rand
	leaq	_prices(%rip), %rcx
	movl	$100, %edx
	movl	%edx, %esi
	movl	$140, %edx
	movl	%edx, -32(%rbp)         ## 4-byte Spill
	cltd
	movl	-32(%rbp), %edi         ## 4-byte Reload
	idivl	%edi
	addl	$40, %edx
	movl	%edx, -12(%rbp)
	movslq	-8(%rbp), %r8
	movq	(%rcx,%r8,8), %r8
	movslq	-12(%rbp), %r9
	imulq	%r9, %r8
	movq	%r8, %rax
	xorl	%edx, %edx
                                        ## kill: %RDX<def> %EDX<kill>
	divq	%rsi
	movslq	-8(%rbp), %rsi
	movq	%rax, (%rcx,%rsi,8)
## BB#11:                               ##   in Loop: Header=BB5_9 Depth=1
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	LBB5_9
LBB5_12:
	movl	$0, -16(%rbp)
LBB5_13:                                ## =>This Inner Loop Header: Depth=1
	cmpl	$2, -16(%rbp)
	jge	LBB5_18
## BB#14:                               ##   in Loop: Header=BB5_13 Depth=1
	leaq	_electricFactories(%rip), %rax
	movslq	-16(%rbp), %rcx
	shlq	$7, %rcx
	movq	%rax, %rdx
	addq	%rcx, %rdx
	movl	112(%rdx), %esi
	addl	$1, %esi
	movl	%esi, 112(%rdx)
	movslq	-16(%rbp), %rcx
	shlq	$7, %rcx
	addq	%rcx, %rax
	cmpl	$20, 112(%rax)
	jl	LBB5_16
## BB#15:                               ##   in Loop: Header=BB5_13 Depth=1
	leaq	_electricFactories(%rip), %rax
	movslq	-16(%rbp), %rcx
	shlq	$7, %rcx
	addq	%rcx, %rax
	movl	$0, 112(%rax)
LBB5_16:                                ##   in Loop: Header=BB5_13 Depth=1
	jmp	LBB5_17
LBB5_17:                                ##   in Loop: Header=BB5_13 Depth=1
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -16(%rbp)
	jmp	LBB5_13
LBB5_18:
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__Z23playerInElectricFactoryi
	.p2align	4, 0x90
__Z23playerInElectricFactoryi:          ## @_Z23playerInElectricFactoryi
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi22:
	.cfi_def_cfa_offset 16
Lcfi23:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi24:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movl	$1, %eax
	leaq	_electricFactories(%rip), %rcx
	movl	%edi, -4(%rbp)
	movslq	-4(%rbp), %rdx
	shlq	$7, %rdx
	addq	%rdx, %rcx
	movl	120(%rcx), %edi
	subl	_turn(%rip), %eax
	cmpl	%eax, %edi
	je	LBB6_2
## BB#1:
	leaq	_electricFactories(%rip), %rax
	movslq	-4(%rbp), %rcx
	shlq	$7, %rcx
	addq	%rcx, %rax
	cmpl	$2, 120(%rax)
	jne	LBB6_3
LBB6_2:
	leaq	L_.str.16(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -12(%rbp)         ## 4-byte Spill
	jmp	LBB6_21
LBB6_3:
	leaq	L_.str.17(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.18(%rip), %rdi
	movl	%eax, -16(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.19(%rip), %rdi
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.20(%rip), %rdi
	movl	%eax, -24(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.7(%rip), %rdi
	leaq	-8(%rbp), %rsi
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	cmpl	$1, -8(%rbp)
	movl	%eax, -32(%rbp)         ## 4-byte Spill
	jne	LBB6_5
## BB#4:
	leaq	L_.str.21(%rip), %rdi
	leaq	_players(%rip), %rax
	leaq	_electricFactories(%rip), %rcx
	movslq	-4(%rbp), %rdx
	shlq	$7, %rdx
	addq	%rdx, %rcx
	imull	$408000, 108(%rcx), %esi ## imm = 0x639C0
	movslq	_turn(%rip), %rcx
	imulq	$44, %rcx, %rcx
	addq	%rcx, %rax
	addl	12(%rax), %esi
	movl	%esi, 12(%rax)
	movb	$0, %al
	callq	_printf
	movl	%eax, -36(%rbp)         ## 4-byte Spill
	jmp	LBB6_20
LBB6_5:
	cmpl	$2, -8(%rbp)
	jne	LBB6_13
## BB#6:
	leaq	_electricFactories(%rip), %rax
	movslq	-4(%rbp), %rcx
	shlq	$7, %rcx
	addq	%rcx, %rax
	cmpl	$0, 124(%rax)
	jne	LBB6_12
## BB#7:
	leaq	_players(%rip), %rax
	leaq	_electricFactories(%rip), %rcx
	movslq	-4(%rbp), %rdx
	shlq	$7, %rdx
	addq	%rdx, %rcx
	movslq	120(%rcx), %rcx
	imulq	$44, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	$0, 40(%rax)
	jle	LBB6_11
## BB#8:
	leaq	_electricFactories(%rip), %rax
	movslq	-4(%rbp), %rcx
	shlq	$7, %rcx
	addq	%rcx, %rax
	cmpl	$20, 112(%rax)
	jne	LBB6_10
## BB#9:
	leaq	_players(%rip), %rax
	leaq	_electricFactories(%rip), %rcx
	movslq	-4(%rbp), %rdx
	shlq	$7, %rdx
	movq	%rcx, %rsi
	addq	%rdx, %rsi
	movl	108(%rsi), %edi
	addl	$1, %edi
	movl	%edi, 108(%rsi)
	movslq	-4(%rbp), %rdx
	shlq	$7, %rdx
	addq	%rdx, %rcx
	movslq	120(%rcx), %rcx
	imulq	$44, %rcx, %rcx
	addq	%rcx, %rax
	movl	40(%rax), %edi
	addl	$-1, %edi
	movl	%edi, 40(%rax)
LBB6_10:
	jmp	LBB6_11
LBB6_11:
	jmp	LBB6_12
LBB6_12:
	jmp	LBB6_19
LBB6_13:
	cmpl	$3, -8(%rbp)
	jne	LBB6_18
## BB#14:
	leaq	_players(%rip), %rax
	movslq	_turn(%rip), %rcx
	imulq	$44, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	$130000, 12(%rax)       ## imm = 0x1FBD0
	jge	LBB6_16
## BB#15:
	leaq	L_.str.22(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -40(%rbp)         ## 4-byte Spill
	jmp	LBB6_17
LBB6_16:
	leaq	_electricFactories(%rip), %rax
	leaq	_players(%rip), %rcx
	movslq	_turn(%rip), %rdx
	imulq	$44, %rdx, %rdx
	addq	%rdx, %rcx
	movl	12(%rcx), %esi
	subl	$1300000, %esi          ## imm = 0x13D620
	movl	%esi, 12(%rcx)
	movslq	-4(%rbp), %rcx
	shlq	$7, %rcx
	addq	%rcx, %rax
	movl	124(%rax), %esi
	addl	$1, %esi
	movl	%esi, 124(%rax)
LBB6_17:
	jmp	LBB6_18
LBB6_18:
	jmp	LBB6_19
LBB6_19:
	jmp	LBB6_20
LBB6_20:
	jmp	LBB6_21
LBB6_21:
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__Z15playerInFactoryi
	.p2align	4, 0x90
__Z15playerInFactoryi:                  ## @_Z15playerInFactoryi
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi25:
	.cfi_def_cfa_offset 16
Lcfi26:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi27:
	.cfi_def_cfa_register %rbp
	subq	$80, %rsp
	movl	$1, %eax
	leaq	_factories(%rip), %rcx
	movl	%edi, -4(%rbp)
	movslq	-4(%rbp), %rdx
	imulq	$124, %rdx, %rdx
	addq	%rdx, %rcx
	movl	116(%rcx), %edi
	subl	_turn(%rip), %eax
	cmpl	%eax, %edi
	je	LBB7_2
## BB#1:
	leaq	_factories(%rip), %rax
	movslq	-4(%rbp), %rcx
	imulq	$124, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	$2, 116(%rax)
	jne	LBB7_3
LBB7_2:
	leaq	L_.str.23(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -16(%rbp)         ## 4-byte Spill
	jmp	LBB7_30
LBB7_3:
	leaq	L_.str.4(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.5(%rip), %rdi
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.24(%rip), %rdi
	movl	%eax, -24(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.7(%rip), %rdi
	leaq	-8(%rbp), %rsi
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	cmpl	$1, -8(%rbp)
	movl	%eax, -32(%rbp)         ## 4-byte Spill
	jne	LBB7_15
## BB#4:
	leaq	_factories(%rip), %rax
	movslq	-4(%rbp), %rcx
	imulq	$124, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	$10, 112(%rax)
	jne	LBB7_11
## BB#5:
	leaq	_factories(%rip), %rax
	movslq	-4(%rbp), %rcx
	imulq	$124, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	$0, 108(%rax)
	jne	LBB7_7
## BB#6:
	leaq	L_.str.8(%rip), %rdi
	leaq	_players(%rip), %rax
	movslq	_turn(%rip), %rcx
	imulq	$44, %rcx, %rcx
	addq	%rcx, %rax
	movsbl	20(%rax), %edx
	addl	$500, %edx              ## imm = 0x1F4
	movb	%dl, %sil
	movb	%sil, 20(%rax)
	movb	$0, %al
	callq	_printf
	movl	%eax, -36(%rbp)         ## 4-byte Spill
	callq	__Z7processv
	jmp	LBB7_10
LBB7_7:
	leaq	_factories(%rip), %rax
	movslq	-4(%rbp), %rcx
	imulq	$124, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	$1, 108(%rax)
	jne	LBB7_9
## BB#8:
	leaq	L_.str.8(%rip), %rdi
	leaq	_players(%rip), %rax
	movslq	_turn(%rip), %rcx
	imulq	$44, %rcx, %rcx
	addq	%rcx, %rax
	movsbl	21(%rax), %edx
	addl	$500, %edx              ## imm = 0x1F4
	movb	%dl, %sil
	movb	%sil, 21(%rax)
	movb	$0, %al
	callq	_printf
	movl	%eax, -40(%rbp)         ## 4-byte Spill
	callq	__Z7processv
LBB7_9:
	jmp	LBB7_10
LBB7_10:
	jmp	LBB7_14
LBB7_11:
	leaq	_factories(%rip), %rax
	movslq	-4(%rbp), %rcx
	imulq	$124, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	$10, 112(%rax)
	jge	LBB7_13
## BB#12:
	leaq	L_.str.9(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	-4(%rbp), %edi
	movl	%eax, -44(%rbp)         ## 4-byte Spill
	callq	__Z12playerInLandi
LBB7_13:
	jmp	LBB7_14
LBB7_14:
	jmp	LBB7_29
LBB7_15:
	cmpl	$2, -8(%rbp)
	jne	LBB7_22
## BB#16:
	leaq	L_.str.10(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.11(%rip), %rdi
	movl	%eax, -48(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.7(%rip), %rdi
	leaq	-12(%rbp), %rsi
	movl	%eax, -52(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	leaq	_players(%rip), %rsi
	movslq	_turn(%rip), %rdi
	imulq	$44, %rdi, %rdi
	addq	%rdi, %rsi
	movslq	-12(%rbp), %rdi
	movsbl	20(%rsi,%rdi), %ecx
	cmpl	$5, %ecx
	movl	%eax, -56(%rbp)         ## 4-byte Spill
	jge	LBB7_18
## BB#17:
	leaq	L_.str.12(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	-4(%rbp), %edi
	movl	%eax, -60(%rbp)         ## 4-byte Spill
	callq	__Z12playerInLandi
	jmp	LBB7_21
LBB7_18:
	leaq	_players(%rip), %rax
	movslq	_turn(%rip), %rcx
	imulq	$44, %rcx, %rcx
	addq	%rcx, %rax
	movslq	-12(%rbp), %rcx
	movsbl	20(%rax,%rcx), %edx
	cmpl	$5, %edx
	jl	LBB7_20
## BB#19:
	leaq	L_.str.13(%rip), %rdi
	leaq	_factories(%rip), %rax
	movl	-12(%rbp), %ecx
	movslq	-4(%rbp), %rdx
	imulq	$124, %rdx, %rdx
	addq	%rdx, %rax
	movl	%ecx, 108(%rax)
	movb	$0, %al
	callq	_printf
	movl	%eax, -64(%rbp)         ## 4-byte Spill
	callq	__Z7processv
LBB7_20:
	jmp	LBB7_21
LBB7_21:
	jmp	LBB7_28
LBB7_22:
	cmpl	$3, -8(%rbp)
	jne	LBB7_27
## BB#23:
	leaq	_players(%rip), %rax
	movslq	_turn(%rip), %rcx
	imulq	$44, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	$5000000, 12(%rax)      ## imm = 0x4C4B40
	jge	LBB7_25
## BB#24:
	leaq	L_.str.14(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -68(%rbp)         ## 4-byte Spill
	jmp	LBB7_26
LBB7_25:
	leaq	L_.str.15(%rip), %rdi
	leaq	_factories(%rip), %rax
	leaq	_players(%rip), %rcx
	movslq	_turn(%rip), %rdx
	imulq	$44, %rdx, %rdx
	addq	%rdx, %rcx
	movl	12(%rcx), %esi
	subl	$5000000, %esi          ## imm = 0x4C4B40
	movl	%esi, 12(%rcx)
	movslq	-4(%rbp), %rcx
	imulq	$124, %rcx, %rcx
	addq	%rcx, %rax
	movl	120(%rax), %esi
	addl	$1, %esi
	movl	%esi, 120(%rax)
	movb	$0, %al
	callq	_printf
	movl	%eax, -72(%rbp)         ## 4-byte Spill
LBB7_26:
	jmp	LBB7_27
LBB7_27:
	jmp	LBB7_28
LBB7_28:
	jmp	LBB7_29
LBB7_29:
	jmp	LBB7_30
LBB7_30:
	addq	$80, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__Z18playerInRealEstatev
	.p2align	4, 0x90
__Z18playerInRealEstatev:               ## @_Z18playerInRealEstatev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi28:
	.cfi_def_cfa_offset 16
Lcfi29:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi30:
	.cfi_def_cfa_register %rbp
	subq	$128, %rsp
	leaq	L_.str.25(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	$0, -4(%rbp)
	movl	%eax, -24(%rbp)         ## 4-byte Spill
LBB8_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$5, -4(%rbp)
	jge	LBB8_12
## BB#2:                                ##   in Loop: Header=BB8_1 Depth=1
	leaq	_lands(%rip), %rax
	movslq	-4(%rbp), %rcx
	imulq	$124, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	$0, 116(%rax)
	jne	LBB8_4
## BB#3:                                ##   in Loop: Header=BB8_1 Depth=1
	leaq	L_.str.26(%rip), %rdi
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	jmp	LBB8_10
LBB8_4:                                 ##   in Loop: Header=BB8_1 Depth=1
	leaq	_lands(%rip), %rax
	movslq	-4(%rbp), %rcx
	imulq	$124, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	$1, 116(%rax)
	jne	LBB8_6
## BB#5:                                ##   in Loop: Header=BB8_1 Depth=1
	leaq	L_.str.27(%rip), %rdi
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -32(%rbp)         ## 4-byte Spill
	jmp	LBB8_9
LBB8_6:                                 ##   in Loop: Header=BB8_1 Depth=1
	leaq	_lands(%rip), %rax
	movslq	-4(%rbp), %rcx
	imulq	$124, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	$2, 116(%rax)
	jne	LBB8_8
## BB#7:                                ##   in Loop: Header=BB8_1 Depth=1
	leaq	L_.str.28(%rip), %rdi
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -36(%rbp)         ## 4-byte Spill
LBB8_8:                                 ##   in Loop: Header=BB8_1 Depth=1
	jmp	LBB8_9
LBB8_9:                                 ##   in Loop: Header=BB8_1 Depth=1
	jmp	LBB8_10
LBB8_10:                                ##   in Loop: Header=BB8_1 Depth=1
	jmp	LBB8_11
LBB8_11:                                ##   in Loop: Header=BB8_1 Depth=1
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -4(%rbp)
	jmp	LBB8_1
LBB8_12:
	movl	$0, -8(%rbp)
LBB8_13:                                ## =>This Inner Loop Header: Depth=1
	cmpl	$2, -8(%rbp)
	jge	LBB8_24
## BB#14:                               ##   in Loop: Header=BB8_13 Depth=1
	leaq	_electricFactories(%rip), %rax
	movslq	-8(%rbp), %rcx
	shlq	$7, %rcx
	addq	%rcx, %rax
	cmpl	$0, 120(%rax)
	jne	LBB8_16
## BB#15:                               ##   in Loop: Header=BB8_13 Depth=1
	leaq	L_.str.29(%rip), %rdi
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -40(%rbp)         ## 4-byte Spill
	jmp	LBB8_22
LBB8_16:                                ##   in Loop: Header=BB8_13 Depth=1
	leaq	_electricFactories(%rip), %rax
	movslq	-8(%rbp), %rcx
	shlq	$7, %rcx
	addq	%rcx, %rax
	cmpl	$1, 120(%rax)
	jne	LBB8_18
## BB#17:                               ##   in Loop: Header=BB8_13 Depth=1
	leaq	L_.str.30(%rip), %rdi
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -44(%rbp)         ## 4-byte Spill
	jmp	LBB8_21
LBB8_18:                                ##   in Loop: Header=BB8_13 Depth=1
	leaq	_electricFactories(%rip), %rax
	movslq	-8(%rbp), %rcx
	shlq	$7, %rcx
	addq	%rcx, %rax
	cmpl	$2, 120(%rax)
	jne	LBB8_20
## BB#19:                               ##   in Loop: Header=BB8_13 Depth=1
	leaq	L_.str.31(%rip), %rdi
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -48(%rbp)         ## 4-byte Spill
LBB8_20:                                ##   in Loop: Header=BB8_13 Depth=1
	jmp	LBB8_21
LBB8_21:                                ##   in Loop: Header=BB8_13 Depth=1
	jmp	LBB8_22
LBB8_22:                                ##   in Loop: Header=BB8_13 Depth=1
	jmp	LBB8_23
LBB8_23:                                ##   in Loop: Header=BB8_13 Depth=1
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	LBB8_13
LBB8_24:
	movl	$0, -12(%rbp)
LBB8_25:                                ## =>This Inner Loop Header: Depth=1
	cmpl	$4, -12(%rbp)
	jge	LBB8_36
## BB#26:                               ##   in Loop: Header=BB8_25 Depth=1
	leaq	_factories(%rip), %rax
	movslq	-12(%rbp), %rcx
	imulq	$124, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	$0, 116(%rax)
	jne	LBB8_28
## BB#27:                               ##   in Loop: Header=BB8_25 Depth=1
	leaq	L_.str.32(%rip), %rdi
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -52(%rbp)         ## 4-byte Spill
	jmp	LBB8_34
LBB8_28:                                ##   in Loop: Header=BB8_25 Depth=1
	leaq	_factories(%rip), %rax
	movslq	-12(%rbp), %rcx
	imulq	$124, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	$1, 116(%rax)
	jne	LBB8_30
## BB#29:                               ##   in Loop: Header=BB8_25 Depth=1
	leaq	L_.str.33(%rip), %rdi
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -56(%rbp)         ## 4-byte Spill
	jmp	LBB8_33
LBB8_30:                                ##   in Loop: Header=BB8_25 Depth=1
	leaq	_factories(%rip), %rax
	movslq	-12(%rbp), %rcx
	imulq	$124, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	$2, 116(%rax)
	jne	LBB8_32
## BB#31:                               ##   in Loop: Header=BB8_25 Depth=1
	leaq	L_.str.34(%rip), %rdi
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -60(%rbp)         ## 4-byte Spill
LBB8_32:                                ##   in Loop: Header=BB8_25 Depth=1
	jmp	LBB8_33
LBB8_33:                                ##   in Loop: Header=BB8_25 Depth=1
	jmp	LBB8_34
LBB8_34:                                ##   in Loop: Header=BB8_25 Depth=1
	jmp	LBB8_35
LBB8_35:                                ##   in Loop: Header=BB8_25 Depth=1
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -12(%rbp)
	jmp	LBB8_25
LBB8_36:
	leaq	L_.str.35(%rip), %rdi
	movl	$0, -16(%rbp)
	movl	$0, -20(%rbp)
	movb	$0, %al
	callq	_printf
	leaq	L_.str.36(%rip), %rdi
	movl	%eax, -64(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.37(%rip), %rdi
	movl	%eax, -68(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.38(%rip), %rdi
	movl	%eax, -72(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.7(%rip), %rdi
	leaq	-16(%rbp), %rsi
	movl	%eax, -76(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	leaq	L_.str.39(%rip), %rdi
	movl	%eax, -80(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.7(%rip), %rdi
	leaq	-20(%rbp), %rsi
	movl	%eax, -84(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	cmpl	$1, -16(%rbp)
	movl	%eax, -88(%rbp)         ## 4-byte Spill
	jne	LBB8_43
## BB#37:
	leaq	_players(%rip), %rax
	movslq	_turn(%rip), %rcx
	imulq	$44, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	$300000, 12(%rax)       ## imm = 0x493E0
	jge	LBB8_39
## BB#38:
	leaq	L_.str.22(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -92(%rbp)         ## 4-byte Spill
	callq	__Z8getInputv
LBB8_39:
	movl	$1, %eax
	leaq	_lands(%rip), %rcx
	movslq	-20(%rbp), %rdx
	imulq	$124, %rdx, %rdx
	addq	%rdx, %rcx
	movl	116(%rcx), %esi
	subl	_turn(%rip), %eax
	cmpl	%eax, %esi
	je	LBB8_41
## BB#40:
	leaq	_lands(%rip), %rax
	movslq	-20(%rbp), %rcx
	imulq	$124, %rcx, %rcx
	addq	%rcx, %rax
	movl	116(%rax), %edx
	cmpl	_turn(%rip), %edx
	jne	LBB8_42
LBB8_41:
	leaq	L_.str.40(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -96(%rbp)         ## 4-byte Spill
LBB8_42:
	leaq	L_.str.41(%rip), %rdi
	leaq	_lands(%rip), %rax
	leaq	_players(%rip), %rcx
	movslq	_turn(%rip), %rdx
	imulq	$44, %rdx, %rdx
	addq	%rdx, %rcx
	movl	12(%rcx), %esi
	subl	$300000, %esi           ## imm = 0x493E0
	movl	%esi, 12(%rcx)
	movl	_turn(%rip), %esi
	movslq	-20(%rbp), %rcx
	imulq	$124, %rcx, %rcx
	addq	%rcx, %rax
	movl	%esi, 116(%rax)
	movb	$0, %al
	callq	_printf
	movl	%eax, -100(%rbp)        ## 4-byte Spill
	jmp	LBB8_59
LBB8_43:
	cmpl	$2, -16(%rbp)
	jne	LBB8_50
## BB#44:
	leaq	_players(%rip), %rax
	movslq	_turn(%rip), %rcx
	imulq	$44, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	$2000000, 12(%rax)      ## imm = 0x1E8480
	jge	LBB8_46
## BB#45:
	leaq	L_.str.22(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -104(%rbp)        ## 4-byte Spill
	callq	__Z8getInputv
LBB8_46:
	movl	$1, %eax
	leaq	_factories(%rip), %rcx
	movslq	-20(%rbp), %rdx
	imulq	$124, %rdx, %rdx
	addq	%rdx, %rcx
	movl	116(%rcx), %esi
	subl	_turn(%rip), %eax
	cmpl	%eax, %esi
	je	LBB8_48
## BB#47:
	leaq	_factories(%rip), %rax
	movslq	-20(%rbp), %rcx
	imulq	$124, %rcx, %rcx
	addq	%rcx, %rax
	movl	116(%rax), %edx
	cmpl	_turn(%rip), %edx
	jne	LBB8_49
LBB8_48:
	leaq	L_.str.40(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -108(%rbp)        ## 4-byte Spill
LBB8_49:
	leaq	L_.str.41(%rip), %rdi
	leaq	_factories(%rip), %rax
	leaq	_players(%rip), %rcx
	movslq	_turn(%rip), %rdx
	imulq	$44, %rdx, %rdx
	addq	%rdx, %rcx
	movl	12(%rcx), %esi
	subl	$2000000, %esi          ## imm = 0x1E8480
	movl	%esi, 12(%rcx)
	movl	_turn(%rip), %esi
	movslq	-20(%rbp), %rcx
	imulq	$124, %rcx, %rcx
	addq	%rcx, %rax
	movl	%esi, 116(%rax)
	movb	$0, %al
	callq	_printf
	movl	%eax, -112(%rbp)        ## 4-byte Spill
	jmp	LBB8_58
LBB8_50:
	cmpl	$3, -16(%rbp)
	jne	LBB8_57
## BB#51:
	leaq	_players(%rip), %rax
	movslq	_turn(%rip), %rcx
	imulq	$44, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	$30000000, 12(%rax)     ## imm = 0x1C9C380
	jge	LBB8_53
## BB#52:
	leaq	L_.str.22(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -116(%rbp)        ## 4-byte Spill
	callq	__Z8getInputv
LBB8_53:
	movl	$1, %eax
	leaq	_electricFactories(%rip), %rcx
	movslq	-20(%rbp), %rdx
	shlq	$7, %rdx
	addq	%rdx, %rcx
	movl	120(%rcx), %esi
	subl	_turn(%rip), %eax
	cmpl	%eax, %esi
	je	LBB8_55
## BB#54:
	leaq	_electricFactories(%rip), %rax
	movslq	-20(%rbp), %rcx
	shlq	$7, %rcx
	addq	%rcx, %rax
	movl	120(%rax), %edx
	cmpl	_turn(%rip), %edx
	jne	LBB8_56
LBB8_55:
	leaq	L_.str.40(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -120(%rbp)        ## 4-byte Spill
LBB8_56:
	leaq	L_.str.41(%rip), %rdi
	leaq	_electricFactories(%rip), %rax
	leaq	_players(%rip), %rcx
	movslq	_turn(%rip), %rdx
	imulq	$44, %rdx, %rdx
	addq	%rdx, %rcx
	movl	12(%rcx), %esi
	subl	$30000000, %esi         ## imm = 0x1C9C380
	movl	%esi, 12(%rcx)
	movl	_turn(%rip), %esi
	movslq	-20(%rbp), %rcx
	shlq	$7, %rcx
	addq	%rcx, %rax
	movl	%esi, 120(%rax)
	movb	$0, %al
	callq	_printf
	movl	%eax, -124(%rbp)        ## 4-byte Spill
LBB8_57:
	jmp	LBB8_58
LBB8_58:
	jmp	LBB8_59
LBB8_59:
	addq	$128, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__Z8getInputv
	.p2align	4, 0x90
__Z8getInputv:                          ## @_Z8getInputv
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi31:
	.cfi_def_cfa_offset 16
Lcfi32:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi33:
	.cfi_def_cfa_register %rbp
	subq	$128, %rsp
	leaq	L_.str.101(%rip), %rdi
	leaq	-18(%rbp), %rsi
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movb	$0, %al
	callq	_scanf
	leaq	_players(%rip), %rsi
	movb	-18(%rbp), %cl
	movb	%cl, -19(%rbp)
	movslq	_turn(%rip), %rdi
	imulq	$44, %rdi, %rdi
	movq	%rsi, %rdx
	addq	%rdi, %rdx
	movl	(%rdx), %r8d
	movl	%r8d, -24(%rbp)
	movslq	_turn(%rip), %rdx
	imulq	$44, %rdx, %rdx
	addq	%rdx, %rsi
	movl	4(%rsi), %r8d
	movl	%r8d, -28(%rbp)
	movl	-24(%rbp), %r8d
	movl	%r8d, -32(%rbp)
	movl	-28(%rbp), %r8d
	movl	%r8d, -36(%rbp)
	movsbl	-19(%rbp), %r8d
	cmpl	$119, %r8d
	movl	%eax, -52(%rbp)         ## 4-byte Spill
	je	LBB9_2
## BB#1:
	movsbl	-19(%rbp), %eax
	cmpl	$105, %eax
	jne	LBB9_3
LBB9_2:
	movl	-32(%rbp), %eax
	addl	$-1, %eax
	movl	%eax, -32(%rbp)
	jmp	LBB9_15
LBB9_3:
	movsbl	-19(%rbp), %eax
	cmpl	$115, %eax
	je	LBB9_5
## BB#4:
	movsbl	-19(%rbp), %eax
	cmpl	$107, %eax
	jne	LBB9_6
LBB9_5:
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	jmp	LBB9_14
LBB9_6:
	movsbl	-19(%rbp), %eax
	cmpl	$97, %eax
	je	LBB9_8
## BB#7:
	movsbl	-19(%rbp), %eax
	cmpl	$106, %eax
	jne	LBB9_9
LBB9_8:
	movl	-36(%rbp), %eax
	addl	$-1, %eax
	movl	%eax, -36(%rbp)
	jmp	LBB9_13
LBB9_9:
	movsbl	-19(%rbp), %eax
	cmpl	$100, %eax
	je	LBB9_11
## BB#10:
	movsbl	-19(%rbp), %eax
	cmpl	$108, %eax
	jne	LBB9_12
LBB9_11:
	movl	-36(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -36(%rbp)
LBB9_12:
	jmp	LBB9_13
LBB9_13:
	jmp	LBB9_14
LBB9_14:
	jmp	LBB9_15
LBB9_15:
	leaq	_map(%rip), %rax
	movslq	-32(%rbp), %rcx
	imulq	$57, %rcx, %rcx
	addq	%rcx, %rax
	movslq	-36(%rbp), %rcx
	movsbl	(%rax,%rcx), %edx
	cmpl	$124, %edx
	jne	LBB9_17
## BB#16:
	callq	__Z8getInputv
LBB9_17:
	movl	$0, -40(%rbp)
LBB9_18:                                ## =>This Inner Loop Header: Depth=1
	cmpl	$5, -40(%rbp)
	jge	LBB9_24
## BB#19:                               ##   in Loop: Header=BB9_18 Depth=1
	leaq	_lands(%rip), %rax
	movl	$2, %ecx
	movl	-32(%rbp), %edx
	movq	%rax, -64(%rbp)         ## 8-byte Spill
	movl	%edx, %eax
	cltd
	idivl	%ecx
	movslq	-40(%rbp), %rsi
	imulq	$124, %rsi, %rsi
	movq	-64(%rbp), %rdi         ## 8-byte Reload
	addq	%rsi, %rdi
	cmpl	(%rdi), %eax
	jne	LBB9_22
## BB#20:                               ##   in Loop: Header=BB9_18 Depth=1
	leaq	_lands(%rip), %rax
	movl	$4, %ecx
	movl	-36(%rbp), %edx
	movq	%rax, -72(%rbp)         ## 8-byte Spill
	movl	%edx, %eax
	cltd
	idivl	%ecx
	movslq	-40(%rbp), %rsi
	imulq	$124, %rsi, %rsi
	movq	-72(%rbp), %rdi         ## 8-byte Reload
	addq	%rsi, %rdi
	cmpl	4(%rdi), %eax
	jne	LBB9_22
## BB#21:                               ##   in Loop: Header=BB9_18 Depth=1
	movl	-40(%rbp), %edi
	callq	__Z12playerInLandi
LBB9_22:                                ##   in Loop: Header=BB9_18 Depth=1
	jmp	LBB9_23
LBB9_23:                                ##   in Loop: Header=BB9_18 Depth=1
	movl	-40(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -40(%rbp)
	jmp	LBB9_18
LBB9_24:
	movl	$0, -44(%rbp)
LBB9_25:                                ## =>This Inner Loop Header: Depth=1
	cmpl	$4, -44(%rbp)
	jge	LBB9_31
## BB#26:                               ##   in Loop: Header=BB9_25 Depth=1
	leaq	_factories(%rip), %rax
	movl	$2, %ecx
	movl	-32(%rbp), %edx
	movq	%rax, -80(%rbp)         ## 8-byte Spill
	movl	%edx, %eax
	cltd
	idivl	%ecx
	movslq	-44(%rbp), %rsi
	imulq	$124, %rsi, %rsi
	movq	-80(%rbp), %rdi         ## 8-byte Reload
	addq	%rsi, %rdi
	cmpl	(%rdi), %eax
	jne	LBB9_29
## BB#27:                               ##   in Loop: Header=BB9_25 Depth=1
	leaq	_factories(%rip), %rax
	movl	$4, %ecx
	movl	-36(%rbp), %edx
	movq	%rax, -88(%rbp)         ## 8-byte Spill
	movl	%edx, %eax
	cltd
	idivl	%ecx
	movslq	-44(%rbp), %rsi
	imulq	$124, %rsi, %rsi
	movq	-88(%rbp), %rdi         ## 8-byte Reload
	addq	%rsi, %rdi
	cmpl	4(%rdi), %eax
	jne	LBB9_29
## BB#28:                               ##   in Loop: Header=BB9_25 Depth=1
	movl	-44(%rbp), %edi
	callq	__Z15playerInFactoryi
LBB9_29:                                ##   in Loop: Header=BB9_25 Depth=1
	jmp	LBB9_30
LBB9_30:                                ##   in Loop: Header=BB9_25 Depth=1
	movl	-44(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -44(%rbp)
	jmp	LBB9_25
LBB9_31:
	movl	$0, -48(%rbp)
LBB9_32:                                ## =>This Inner Loop Header: Depth=1
	cmpl	$2, -48(%rbp)
	jge	LBB9_38
## BB#33:                               ##   in Loop: Header=BB9_32 Depth=1
	leaq	_electricFactories(%rip), %rax
	movl	$2, %ecx
	movl	-32(%rbp), %edx
	movq	%rax, -96(%rbp)         ## 8-byte Spill
	movl	%edx, %eax
	cltd
	idivl	%ecx
	movslq	-48(%rbp), %rsi
	shlq	$7, %rsi
	movq	-96(%rbp), %rdi         ## 8-byte Reload
	addq	%rsi, %rdi
	cmpl	(%rdi), %eax
	jne	LBB9_36
## BB#34:                               ##   in Loop: Header=BB9_32 Depth=1
	leaq	_electricFactories(%rip), %rax
	movl	$4, %ecx
	movl	-36(%rbp), %edx
	movq	%rax, -104(%rbp)        ## 8-byte Spill
	movl	%edx, %eax
	cltd
	idivl	%ecx
	movslq	-48(%rbp), %rsi
	shlq	$7, %rsi
	movq	-104(%rbp), %rdi        ## 8-byte Reload
	addq	%rsi, %rdi
	cmpl	4(%rdi), %eax
	jne	LBB9_36
## BB#35:                               ##   in Loop: Header=BB9_32 Depth=1
	movl	-48(%rbp), %edi
	callq	__Z23playerInElectricFactoryi
LBB9_36:                                ##   in Loop: Header=BB9_32 Depth=1
	jmp	LBB9_37
LBB9_37:                                ##   in Loop: Header=BB9_32 Depth=1
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	jmp	LBB9_32
LBB9_38:
	movl	$2, %eax
	movl	-32(%rbp), %ecx
	movl	%eax, -108(%rbp)        ## 4-byte Spill
	movl	%ecx, %eax
	cltd
	movl	-108(%rbp), %ecx        ## 4-byte Reload
	idivl	%ecx
	cmpl	$1, %eax
	jne	LBB9_41
## BB#39:
	movl	$4, %eax
	movl	-36(%rbp), %ecx
	movl	%eax, -112(%rbp)        ## 4-byte Spill
	movl	%ecx, %eax
	cltd
	movl	-112(%rbp), %ecx        ## 4-byte Reload
	idivl	%ecx
	cmpl	$10, %eax
	jne	LBB9_41
## BB#40:
	callq	__Z15playerInJewelryv
LBB9_41:
	movl	$2, %eax
	movl	-32(%rbp), %ecx
	movl	%eax, -116(%rbp)        ## 4-byte Spill
	movl	%ecx, %eax
	cltd
	movl	-116(%rbp), %ecx        ## 4-byte Reload
	idivl	%ecx
	cmpl	$5, %eax
	jne	LBB9_44
## BB#42:
	movl	$4, %eax
	movl	-36(%rbp), %ecx
	movl	%eax, -120(%rbp)        ## 4-byte Spill
	movl	%ecx, %eax
	cltd
	movl	-120(%rbp), %ecx        ## 4-byte Reload
	idivl	%ecx
	cmpl	$10, %eax
	jne	LBB9_44
## BB#43:
	callq	__Z14playerInCasinov
LBB9_44:
	movl	$2, %eax
	movl	-32(%rbp), %ecx
	movl	%eax, -124(%rbp)        ## 4-byte Spill
	movl	%ecx, %eax
	cltd
	movl	-124(%rbp), %ecx        ## 4-byte Reload
	idivl	%ecx
	cmpl	$11, %eax
	jne	LBB9_47
## BB#45:
	movl	$4, %eax
	movl	-36(%rbp), %ecx
	movl	%eax, -128(%rbp)        ## 4-byte Spill
	movl	%ecx, %eax
	cltd
	movl	-128(%rbp), %ecx        ## 4-byte Reload
	idivl	%ecx
	cmpl	$1, %eax
	jne	LBB9_47
## BB#46:
	callq	__Z18playerInRealEstatev
LBB9_47:
	leaq	_players(%rip), %rax
	movl	-32(%rbp), %ecx
	movslq	_turn(%rip), %rdx
	imulq	$44, %rdx, %rdx
	movq	%rax, %rsi
	addq	%rdx, %rsi
	movl	%ecx, (%rsi)
	movl	-36(%rbp), %ecx
	movslq	_turn(%rip), %rdx
	imulq	$44, %rdx, %rdx
	addq	%rdx, %rax
	movl	%ecx, 4(%rax)
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rdx
	cmpq	%rdx, %rax
	jne	LBB9_49
## BB#48:
	addq	$128, %rsp
	popq	%rbp
	retq
LBB9_49:
	callq	___stack_chk_fail
	.cfi_endproc

	.globl	__Z12playerInWildv
	.p2align	4, 0x90
__Z12playerInWildv:                     ## @_Z12playerInWildv
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi34:
	.cfi_def_cfa_offset 16
Lcfi35:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi36:
	.cfi_def_cfa_register %rbp
	subq	$96, %rsp
	callq	_rand
	movl	$3, %ecx
	cltd
	idivl	%ecx
	movl	%edx, -20(%rbp)
	movl	$0, -48(%rbp)
LBB10_1:                                ## =>This Inner Loop Header: Depth=1
	cmpl	$20, -48(%rbp)
	jge	LBB10_22
## BB#2:                                ##   in Loop: Header=BB10_1 Depth=1
	callq	_rand
	movl	$10, %ecx
	cltd
	idivl	%ecx
	movl	%edx, -4(%rbp)
	callq	_rand
	leaq	L_.str.42(%rip), %rdi
	movl	$10, %ecx
	cltd
	idivl	%ecx
	movl	%edx, -12(%rbp)
	movb	$0, %al
	callq	_printf
	leaq	L_.str.7(%rip), %rdi
	leaq	-8(%rbp), %rsi
	movl	%eax, -52(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	leaq	L_.str.43(%rip), %rdi
	movl	%eax, -56(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.7(%rip), %rdi
	leaq	-16(%rbp), %rsi
	movl	%eax, -60(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	movl	-8(%rbp), %ecx
	cmpl	-4(%rbp), %ecx
	movl	%eax, -64(%rbp)         ## 4-byte Spill
	jne	LBB10_5
## BB#3:                                ##   in Loop: Header=BB10_1 Depth=1
	movl	-16(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jne	LBB10_5
## BB#4:                                ##   in Loop: Header=BB10_1 Depth=1
	leaq	L_.str.44(%rip), %rdi
	leaq	_players(%rip), %rax
	movslq	_turn(%rip), %rcx
	imulq	$44, %rcx, %rcx
	addq	%rcx, %rax
	movsbl	27(%rax), %edx
	addl	$15, %edx
	movb	%dl, %sil
	movb	%sil, 27(%rax)
	movb	$0, %al
	callq	_printf
	movl	-24(%rbp), %edx
	addl	$15, %edx
	movl	%edx, -24(%rbp)
	movl	%eax, -68(%rbp)         ## 4-byte Spill
	jmp	LBB10_20
LBB10_5:                                ##   in Loop: Header=BB10_1 Depth=1
	movl	-8(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jne	LBB10_7
## BB#6:                                ##   in Loop: Header=BB10_1 Depth=1
	leaq	L_.str.45(%rip), %rdi
	leaq	_players(%rip), %rax
	movslq	_turn(%rip), %rcx
	imulq	$44, %rcx, %rcx
	addq	%rcx, %rax
	movsbl	26(%rax), %edx
	addl	$15, %edx
	movb	%dl, %sil
	movb	%sil, 26(%rax)
	movb	$0, %al
	callq	_printf
	movl	-28(%rbp), %edx
	addl	$15, %edx
	movl	%edx, -28(%rbp)
	movl	%eax, -72(%rbp)         ## 4-byte Spill
	jmp	LBB10_19
LBB10_7:                                ##   in Loop: Header=BB10_1 Depth=1
	movl	-16(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jne	LBB10_9
## BB#8:                                ##   in Loop: Header=BB10_1 Depth=1
	leaq	L_.str.46(%rip), %rdi
	leaq	_players(%rip), %rax
	movslq	_turn(%rip), %rcx
	imulq	$44, %rcx, %rcx
	addq	%rcx, %rax
	movsbl	25(%rax), %edx
	addl	$20, %edx
	movb	%dl, %sil
	movb	%sil, 25(%rax)
	movb	$0, %al
	callq	_printf
	movl	-32(%rbp), %edx
	addl	$20, %edx
	movl	%edx, -32(%rbp)
	movl	%eax, -76(%rbp)         ## 4-byte Spill
	jmp	LBB10_18
LBB10_9:                                ##   in Loop: Header=BB10_1 Depth=1
	cmpl	$1, -20(%rbp)
	jne	LBB10_11
## BB#10:                               ##   in Loop: Header=BB10_1 Depth=1
	leaq	L_.str.47(%rip), %rdi
	leaq	_players(%rip), %rax
	movslq	_turn(%rip), %rcx
	imulq	$44, %rcx, %rcx
	addq	%rcx, %rax
	movsbl	24(%rax), %edx
	addl	$30, %edx
	movb	%dl, %sil
	movb	%sil, 24(%rax)
	movb	$0, %al
	callq	_printf
	movl	-36(%rbp), %edx
	addl	$30, %edx
	movl	%edx, -36(%rbp)
	movl	%eax, -80(%rbp)         ## 4-byte Spill
	jmp	LBB10_17
LBB10_11:                               ##   in Loop: Header=BB10_1 Depth=1
	cmpl	$2, -20(%rbp)
	jne	LBB10_13
## BB#12:                               ##   in Loop: Header=BB10_1 Depth=1
	leaq	L_.str.48(%rip), %rdi
	leaq	_players(%rip), %rax
	movslq	_turn(%rip), %rcx
	imulq	$44, %rcx, %rcx
	addq	%rcx, %rax
	movsbl	23(%rax), %edx
	addl	$64, %edx
	movb	%dl, %sil
	movb	%sil, 23(%rax)
	movb	$0, %al
	callq	_printf
	movl	-40(%rbp), %edx
	addl	$64, %edx
	movl	%edx, -40(%rbp)
	movl	%eax, -84(%rbp)         ## 4-byte Spill
	jmp	LBB10_16
LBB10_13:                               ##   in Loop: Header=BB10_1 Depth=1
	cmpl	$3, -20(%rbp)
	jne	LBB10_15
## BB#14:                               ##   in Loop: Header=BB10_1 Depth=1
	leaq	L_.str.49(%rip), %rdi
	leaq	_players(%rip), %rax
	movslq	_turn(%rip), %rcx
	imulq	$44, %rcx, %rcx
	addq	%rcx, %rax
	movsbl	22(%rax), %edx
	addl	$252, %edx
	movb	%dl, %sil
	movb	%sil, 22(%rax)
	movb	$0, %al
	callq	_printf
	movl	-44(%rbp), %edx
	addl	$300, %edx              ## imm = 0x12C
	movl	%edx, -44(%rbp)
	movl	%eax, -88(%rbp)         ## 4-byte Spill
LBB10_15:                               ##   in Loop: Header=BB10_1 Depth=1
	jmp	LBB10_16
LBB10_16:                               ##   in Loop: Header=BB10_1 Depth=1
	jmp	LBB10_17
LBB10_17:                               ##   in Loop: Header=BB10_1 Depth=1
	jmp	LBB10_18
LBB10_18:                               ##   in Loop: Header=BB10_1 Depth=1
	jmp	LBB10_19
LBB10_19:                               ##   in Loop: Header=BB10_1 Depth=1
	jmp	LBB10_20
LBB10_20:                               ##   in Loop: Header=BB10_1 Depth=1
	leaq	L_.str.50(%rip), %rdi
	leaq	_players(%rip), %rax
	imull	$5000, -24(%rbp), %ecx  ## imm = 0x1388
	imull	$3000, -28(%rbp), %edx  ## imm = 0xBB8
	addl	%edx, %ecx
	imull	$2000, -32(%rbp), %edx  ## imm = 0x7D0
	addl	%edx, %ecx
	imull	$1000, -36(%rbp), %edx  ## imm = 0x3E8
	addl	%edx, %ecx
	imull	$100, -40(%rbp), %edx
	addl	%edx, %ecx
	imull	$10, -44(%rbp), %edx
	addl	%edx, %ecx
	movslq	_turn(%rip), %rsi
	imulq	$44, %rsi, %rsi
	addq	%rsi, %rax
	addl	12(%rax), %ecx
	movl	%ecx, 12(%rax)
	imull	$5000, -24(%rbp), %ecx  ## imm = 0x1388
	imull	$3000, -28(%rbp), %edx  ## imm = 0xBB8
	addl	%edx, %ecx
	imull	$2000, -32(%rbp), %edx  ## imm = 0x7D0
	addl	%edx, %ecx
	imull	$1000, -36(%rbp), %edx  ## imm = 0x3E8
	addl	%edx, %ecx
	imull	$100, -40(%rbp), %edx
	addl	%edx, %ecx
	imull	$10, -44(%rbp), %edx
	addl	%edx, %ecx
	movl	%ecx, %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -92(%rbp)         ## 4-byte Spill
## BB#21:                               ##   in Loop: Header=BB10_1 Depth=1
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	jmp	LBB10_1
LBB10_22:
	addq	$96, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__Z16playerInCityHallv
	.p2align	4, 0x90
__Z16playerInCityHallv:                 ## @_Z16playerInCityHallv
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi37:
	.cfi_def_cfa_offset 16
Lcfi38:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi39:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	_tax(%rip), %eax
	cmpl	_maxTurn(%rip), %eax
	jne	LBB11_6
## BB#1:
	movl	$0, -4(%rbp)
LBB11_2:                                ## =>This Inner Loop Header: Depth=1
	cmpl	$2, -4(%rbp)
	jge	LBB11_5
## BB#3:                                ##   in Loop: Header=BB11_2 Depth=1
	leaq	L_.str.51(%rip), %rdi
	leaq	_players(%rip), %rax
	movl	$20, %ecx
	movslq	-4(%rbp), %rdx
	imulq	$44, %rdx, %rdx
	movq	%rax, %rsi
	addq	%rdx, %rsi
	movl	12(%rsi), %r8d
	movq	%rax, -16(%rbp)         ## 8-byte Spill
	movl	%r8d, %eax
	cltd
	idivl	%ecx
	imull	$19, %eax, %eax
	movslq	-4(%rbp), %rsi
	imulq	$44, %rsi, %rsi
	movq	-16(%rbp), %r9          ## 8-byte Reload
	addq	%rsi, %r9
	movl	%eax, 12(%r9)
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	leaq	_players(%rip), %rdi
	movslq	-4(%rbp), %r9
	imulq	$44, %r9, %r9
	movq	%rdi, %r10
	addq	%r9, %r10
	movl	$22, (%r10)
	movslq	-4(%rbp), %r9
	imulq	$44, %r9, %r9
	addq	%r9, %rdi
	movl	$40, 4(%rdi)
	movl	%eax, -20(%rbp)         ## 4-byte Spill
## BB#4:                                ##   in Loop: Header=BB11_2 Depth=1
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -4(%rbp)
	jmp	LBB11_2
LBB11_5:
	jmp	LBB11_6
LBB11_6:
	movl	$0, _tax(%rip)
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__Z15playerInJewelryv
	.p2align	4, 0x90
__Z15playerInJewelryv:                  ## @_Z15playerInJewelryv
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi40:
	.cfi_def_cfa_offset 16
Lcfi41:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi42:
	.cfi_def_cfa_register %rbp
	subq	$144, %rsp
	leaq	L_.str.52(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.53(%rip), %rdi
	movq	_prices(%rip), %rsi
	movl	%eax, -24(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.54(%rip), %rdi
	movq	_prices+8(%rip), %rsi
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.55(%rip), %rdi
	movq	_prices+16(%rip), %rsi
	movl	%eax, -32(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.56(%rip), %rdi
	movq	_prices+24(%rip), %rsi
	movl	%eax, -36(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.57(%rip), %rdi
	movq	_prices+32(%rip), %rsi
	movl	%eax, -40(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.58(%rip), %rdi
	movq	_prices+40(%rip), %rsi
	movl	%eax, -44(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.59(%rip), %rdi
	movq	_prices+48(%rip), %rsi
	movl	%eax, -48(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.60(%rip), %rdi
	movq	_prices+56(%rip), %rsi
	movl	%eax, -52(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.61(%rip), %rdi
	movq	_prices+64(%rip), %rsi
	movl	%eax, -56(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.62(%rip), %rdi
	movq	_prices+72(%rip), %rsi
	movl	%eax, -60(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.52(%rip), %rdi
	movl	%eax, -64(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.17(%rip), %rdi
	movl	%eax, -68(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.63(%rip), %rdi
	movl	%eax, -72(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.64(%rip), %rdi
	movl	%eax, -76(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.52(%rip), %rdi
	movl	%eax, -80(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.7(%rip), %rdi
	leaq	-4(%rbp), %rsi
	movl	%eax, -84(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	cmpl	$1, -4(%rbp)
	movl	%eax, -88(%rbp)         ## 4-byte Spill
	jne	LBB12_5
## BB#1:
	leaq	L_.str.35(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.7(%rip), %rdi
	leaq	-8(%rbp), %rsi
	movl	%eax, -92(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	leaq	L_.str.65(%rip), %rdi
	movl	%eax, -96(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.7(%rip), %rdi
	leaq	-12(%rbp), %rsi
	movl	%eax, -100(%rbp)        ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	leaq	_prices(%rip), %rsi
	leaq	_players(%rip), %rdi
	movslq	_turn(%rip), %rcx
	imulq	$44, %rcx, %rcx
	addq	%rcx, %rdi
	movslq	12(%rdi), %rcx
	movslq	-8(%rbp), %rdi
	movq	(%rsi,%rdi,8), %rsi
	movslq	-12(%rbp), %rdi
	imulq	%rdi, %rsi
	cmpq	%rsi, %rcx
	movl	%eax, -104(%rbp)        ## 4-byte Spill
	jae	LBB12_3
## BB#2:
	leaq	L_.str.66(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -108(%rbp)        ## 4-byte Spill
	callq	__Z15playerInJewelryv
	jmp	LBB12_4
LBB12_3:
	leaq	L_.str.67(%rip), %rdi
	leaq	_players(%rip), %rax
	leaq	_prices(%rip), %rcx
	movslq	-8(%rbp), %rdx
	movq	(%rcx,%rdx,8), %rcx
	movslq	-12(%rbp), %rdx
	imulq	%rdx, %rcx
	movslq	_turn(%rip), %rdx
	imulq	$44, %rdx, %rdx
	movq	%rax, %rsi
	addq	%rdx, %rsi
	movslq	12(%rsi), %rdx
	subq	%rcx, %rdx
	movl	%edx, %r8d
	movl	%r8d, 12(%rsi)
	movl	-12(%rbp), %r8d
	movslq	_turn(%rip), %rcx
	imulq	$44, %rcx, %rcx
	addq	%rcx, %rax
	movslq	-8(%rbp), %rcx
	movsbl	28(%rax,%rcx), %r9d
	addl	%r8d, %r9d
	movb	%r9b, %r10b
	movb	%r10b, 28(%rax,%rcx)
	movb	$0, %al
	callq	_printf
	movl	%eax, -112(%rbp)        ## 4-byte Spill
	callq	__Z8getInputv
LBB12_4:
	jmp	LBB12_13
LBB12_5:
	cmpl	$2, -4(%rbp)
	jne	LBB12_12
## BB#6:
	leaq	L_.str.68(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.7(%rip), %rdi
	leaq	-16(%rbp), %rsi
	movl	%eax, -116(%rbp)        ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	leaq	L_.str.69(%rip), %rdi
	movl	%eax, -120(%rbp)        ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.7(%rip), %rdi
	leaq	-20(%rbp), %rsi
	movl	%eax, -124(%rbp)        ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	leaq	_players(%rip), %rsi
	movslq	_turn(%rip), %rdi
	imulq	$44, %rdi, %rdi
	addq	%rdi, %rsi
	movslq	-16(%rbp), %rdi
	movsbl	28(%rsi,%rdi), %ecx
	cmpl	-20(%rbp), %ecx
	movl	%eax, -128(%rbp)        ## 4-byte Spill
	jge	LBB12_8
## BB#7:
	leaq	L_.str.70(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -132(%rbp)        ## 4-byte Spill
	callq	__Z15playerInJewelryv
	jmp	LBB12_11
LBB12_8:
	leaq	_players(%rip), %rax
	movslq	_turn(%rip), %rcx
	imulq	$44, %rcx, %rcx
	addq	%rcx, %rax
	movslq	-16(%rbp), %rcx
	movsbl	28(%rax,%rcx), %edx
	cmpl	-20(%rbp), %edx
	jl	LBB12_10
## BB#9:
	leaq	L_.str.71(%rip), %rdi
	leaq	_players(%rip), %rax
	leaq	_prices(%rip), %rcx
	movslq	-16(%rbp), %rdx
	movq	(%rcx,%rdx,8), %rcx
	movslq	-20(%rbp), %rdx
	imulq	%rdx, %rcx
	movslq	_turn(%rip), %rdx
	imulq	$44, %rdx, %rdx
	addq	%rdx, %rax
	movslq	12(%rax), %rdx
	addq	%rcx, %rdx
	movl	%edx, %esi
	movl	%esi, 12(%rax)
	movb	$0, %al
	callq	_printf
	movl	%eax, -136(%rbp)        ## 4-byte Spill
	callq	__Z8getInputv
LBB12_10:
	jmp	LBB12_11
LBB12_11:
	jmp	LBB12_12
LBB12_12:
	jmp	LBB12_13
LBB12_13:
	addq	$144, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__literal4,4byte_literals
	.p2align	2
LCPI13_0:
	.long	1073741824              ## float 2
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3
LCPI13_1:
	.quad	4602678819172646912     ## double 0.5
	.section	__TEXT,__text,regular,pure_instructions
	.globl	__Z14playerInCasinov
	.p2align	4, 0x90
__Z14playerInCasinov:                   ## @_Z14playerInCasinov
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi43:
	.cfi_def_cfa_offset 16
Lcfi44:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi45:
	.cfi_def_cfa_register %rbp
	subq	$96, %rsp
	leaq	L_.str.72(%rip), %rdi
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -28(%rbp)
	movl	$0, -32(%rbp)
	movl	$1, -36(%rbp)
	movb	$0, %al
	callq	_printf
	leaq	L_.str.73(%rip), %rdi
	movl	%eax, -40(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.74(%rip), %rdi
	movl	%eax, -44(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.7(%rip), %rdi
	leaq	-24(%rbp), %rsi
	movl	%eax, -48(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	leaq	_players(%rip), %rsi
	movq	l__ZZ14playerInCasinovE6casino(%rip), %rdi
	movq	%rdi, -20(%rbp)
	movl	l__ZZ14playerInCasinovE6casino+8(%rip), %ecx
	movl	%ecx, -12(%rbp)
	movslq	_turn(%rip), %rdi
	imulq	$44, %rdi, %rdi
	addq	%rdi, %rsi
	movl	12(%rsi), %ecx
	movl	-24(%rbp), %edx
	subl	$1, %edx
	movslq	%edx, %rsi
	cmpl	-20(%rbp,%rsi,4), %ecx
	movl	%eax, -52(%rbp)         ## 4-byte Spill
	jge	LBB13_2
## BB#1:
	leaq	L_.str.75(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -56(%rbp)         ## 4-byte Spill
	callq	__Z8getInputv
LBB13_2:
	movl	-24(%rbp), %eax
	movl	%eax, %ecx
	subl	$1, %ecx
	movl	%eax, -60(%rbp)         ## 4-byte Spill
	movl	%ecx, -64(%rbp)         ## 4-byte Spill
	je	LBB13_3
	jmp	LBB13_10
LBB13_10:
	movl	-60(%rbp), %eax         ## 4-byte Reload
	subl	$2, %eax
	movl	%eax, -68(%rbp)         ## 4-byte Spill
	je	LBB13_4
	jmp	LBB13_11
LBB13_11:
	movl	-60(%rbp), %eax         ## 4-byte Reload
	subl	$3, %eax
	movl	%eax, -72(%rbp)         ## 4-byte Spill
	je	LBB13_5
	jmp	LBB13_6
LBB13_3:
	leaq	_players(%rip), %rax
	movslq	_turn(%rip), %rcx
	imulq	$44, %rcx, %rcx
	addq	%rcx, %rax
	movl	12(%rax), %edx
	subl	$50000, %edx            ## imm = 0xC350
	movl	%edx, 12(%rax)
	callq	_rand
	leaq	_players(%rip), %rcx
	movl	$100000, %edx           ## imm = 0x186A0
	movl	%edx, -76(%rbp)         ## 4-byte Spill
	cltd
	movl	-76(%rbp), %esi         ## 4-byte Reload
	idivl	%esi
	movl	%edx, -32(%rbp)
	movl	_turn(%rip), %edx
	movl	%edx, -28(%rbp)
	movl	-32(%rbp), %edx
	movslq	_turn(%rip), %rdi
	imulq	$44, %rdi, %rdi
	addq	%rdi, %rcx
	addl	12(%rcx), %edx
	movl	%edx, 12(%rcx)
	jmp	LBB13_7
LBB13_4:
	leaq	_players(%rip), %rax
	movslq	_turn(%rip), %rcx
	imulq	$44, %rcx, %rcx
	addq	%rcx, %rax
	movl	12(%rax), %edx
	subl	$200000, %edx           ## imm = 0x30D40
	movl	%edx, 12(%rax)
	callq	_rand
	leaq	_players(%rip), %rcx
	movl	$1, %edx
	movl	$700000, %esi           ## imm = 0xAAE60
	movl	%edx, -80(%rbp)         ## 4-byte Spill
	cltd
	idivl	%esi
	subl	$300000, %edx           ## imm = 0x493E0
	movl	%edx, -32(%rbp)
	movl	-80(%rbp), %edx         ## 4-byte Reload
	subl	_turn(%rip), %edx
	movl	%edx, -28(%rbp)
	movl	-32(%rbp), %edx
	movl	-80(%rbp), %esi         ## 4-byte Reload
	subl	_turn(%rip), %esi
	movslq	%esi, %rdi
	imulq	$44, %rdi, %rdi
	addq	%rdi, %rcx
	addl	12(%rcx), %edx
	movl	%edx, 12(%rcx)
	jmp	LBB13_7
LBB13_5:
	leaq	_players(%rip), %rax
	movslq	_turn(%rip), %rcx
	imulq	$44, %rcx, %rcx
	addq	%rcx, %rax
	movl	12(%rax), %edx
	subl	$100000, %edx           ## imm = 0x186A0
	movl	%edx, 12(%rax)
	callq	_rand
	movl	$200000, %edx           ## imm = 0x30D40
	movl	%edx, -84(%rbp)         ## 4-byte Spill
	cltd
	movl	-84(%rbp), %esi         ## 4-byte Reload
	idivl	%esi
	movl	%edx, -32(%rbp)
	callq	_rand
	movl	$2, %edx
	movl	%edx, -88(%rbp)         ## 4-byte Spill
	cltd
	movl	-88(%rbp), %esi         ## 4-byte Reload
	idivl	%esi
	movl	%edx, -28(%rbp)
	callq	_rand
	leaq	_players(%rip), %rcx
	movss	LCPI13_0(%rip), %xmm0   ## xmm0 = mem[0],zero,zero,zero
	movsd	LCPI13_1(%rip), %xmm1   ## xmm1 = mem[0],zero
	movl	$2, %edx
	movl	%edx, -92(%rbp)         ## 4-byte Spill
	cltd
	movl	-92(%rbp), %esi         ## 4-byte Reload
	idivl	%esi
	cvtsi2sdl	%edx, %xmm2
	subsd	%xmm1, %xmm2
	cvtsd2ss	%xmm2, %xmm1
	mulss	%xmm0, %xmm1
	cvttss2si	%xmm1, %edx
	movl	%edx, -36(%rbp)
	movl	-36(%rbp), %edx
	imull	-32(%rbp), %edx
	movslq	-28(%rbp), %rdi
	imulq	$44, %rdi, %rdi
	addq	%rdi, %rcx
	addl	12(%rcx), %edx
	movl	%edx, 12(%rcx)
	jmp	LBB13_7
LBB13_6:
	jmp	LBB13_7
LBB13_7:
	leaq	L_.str.76(%rip), %rdi
	leaq	_players(%rip), %rax
	movslq	-28(%rbp), %rcx
	imulq	$44, %rcx, %rcx
	addq	%rcx, %rax
	movsbl	8(%rax), %esi
	movl	-32(%rbp), %edx
	movb	$0, %al
	callq	_printf
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	-8(%rbp), %rdi
	cmpq	%rdi, %rcx
	movl	%eax, -96(%rbp)         ## 4-byte Spill
	jne	LBB13_9
## BB#8:
	addq	$96, %rsp
	popq	%rbp
	retq
LBB13_9:
	callq	___stack_chk_fail
	.cfi_endproc

	.globl	__Z8setupMapv
	.p2align	4, 0x90
__Z8setupMapv:                          ## @_Z8setupMapv
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi46:
	.cfi_def_cfa_offset 16
Lcfi47:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi48:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$376, %rsp              ## imm = 0x178
Lcfi49:
	.cfi_offset %rbx, -56
Lcfi50:
	.cfi_offset %r12, -48
Lcfi51:
	.cfi_offset %r13, -40
Lcfi52:
	.cfi_offset %r14, -32
Lcfi53:
	.cfi_offset %r15, -24
	leaq	L_.str.77(%rip), %rdi
	movl	$1000, %eax             ## imm = 0x3E8
	subl	_tax(%rip), %eax
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.78(%rip), %rdi
	movl	_players+12(%rip), %esi
	movl	%eax, -44(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.79(%rip), %rdi
	movl	_players+56(%rip), %esi
	movl	%eax, -48(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	_map(%rip), %rdi
	movq	%rdi, %rcx
	addq	$1425, %rcx             ## imm = 0x591
	leaq	L_.str.80(%rip), %rdx
	movl	$56, %esi
	movl	%esi, %r8d
	movq	%rdi, %r9
	addq	$1368, %r9              ## imm = 0x558
	movq	%rdi, %r10
	addq	$1311, %r10             ## imm = 0x51F
	leaq	L_.str.97(%rip), %rsi
	movq	%rdi, %r11
	addq	$1254, %r11             ## imm = 0x4E6
	leaq	L_.str.96(%rip), %rbx
	movq	%rdi, %r14
	addq	$1197, %r14             ## imm = 0x4AD
	leaq	L_.str.94(%rip), %r15
	movq	%rdi, %r12
	addq	$1140, %r12             ## imm = 0x474
	movq	%rdi, %r13
	addq	$1083, %r13             ## imm = 0x43B
	movq	%rcx, -56(%rbp)         ## 8-byte Spill
	leaq	L_.str.95(%rip), %rcx
	movq	%rcx, -64(%rbp)         ## 8-byte Spill
	movq	%rdi, %rcx
	addq	$1026, %rcx             ## imm = 0x402
	movq	%rcx, -72(%rbp)         ## 8-byte Spill
	movq	%rdi, %rcx
	addq	$969, %rcx              ## imm = 0x3C9
	movq	%rcx, -80(%rbp)         ## 8-byte Spill
	movq	%rdi, %rcx
	addq	$912, %rcx              ## imm = 0x390
	movq	%rcx, -88(%rbp)         ## 8-byte Spill
	movq	%rdi, %rcx
	addq	$855, %rcx              ## imm = 0x357
	movq	%rcx, -96(%rbp)         ## 8-byte Spill
	leaq	L_.str.93(%rip), %rcx
	movq	%rcx, -104(%rbp)        ## 8-byte Spill
	movq	%rdi, %rcx
	addq	$798, %rcx              ## imm = 0x31E
	movq	%rcx, -112(%rbp)        ## 8-byte Spill
	leaq	L_.str.92(%rip), %rcx
	movq	%rcx, -120(%rbp)        ## 8-byte Spill
	movq	%rdi, %rcx
	addq	$741, %rcx              ## imm = 0x2E5
	movq	%rcx, -128(%rbp)        ## 8-byte Spill
	leaq	L_.str.91(%rip), %rcx
	movq	%rcx, -136(%rbp)        ## 8-byte Spill
	movq	%rdi, %rcx
	addq	$684, %rcx              ## imm = 0x2AC
	movq	%rcx, -144(%rbp)        ## 8-byte Spill
	movq	%rdi, %rcx
	addq	$627, %rcx              ## imm = 0x273
	movq	%rcx, -152(%rbp)        ## 8-byte Spill
	leaq	L_.str.90(%rip), %rcx
	movq	%rcx, -160(%rbp)        ## 8-byte Spill
	movq	%rdi, %rcx
	addq	$570, %rcx              ## imm = 0x23A
	movq	%rcx, -168(%rbp)        ## 8-byte Spill
	leaq	L_.str.89(%rip), %rcx
	movq	%rcx, -176(%rbp)        ## 8-byte Spill
	movq	%rdi, %rcx
	addq	$513, %rcx              ## imm = 0x201
	movq	%rcx, -184(%rbp)        ## 8-byte Spill
	leaq	L_.str.88(%rip), %rcx
	movq	%rcx, -192(%rbp)        ## 8-byte Spill
	movq	%rdi, %rcx
	addq	$456, %rcx              ## imm = 0x1C8
	movq	%rcx, -200(%rbp)        ## 8-byte Spill
	leaq	L_.str.87(%rip), %rcx
	movq	%rcx, -208(%rbp)        ## 8-byte Spill
	movq	%rdi, %rcx
	addq	$399, %rcx              ## imm = 0x18F
	movq	%rcx, -216(%rbp)        ## 8-byte Spill
	leaq	L_.str.86(%rip), %rcx
	movq	%rcx, -224(%rbp)        ## 8-byte Spill
	movq	%rdi, %rcx
	addq	$342, %rcx              ## imm = 0x156
	movq	%rcx, -232(%rbp)        ## 8-byte Spill
	leaq	L_.str.85(%rip), %rcx
	movq	%rcx, -240(%rbp)        ## 8-byte Spill
	movq	%rdi, %rcx
	addq	$285, %rcx              ## imm = 0x11D
	movq	%rcx, -248(%rbp)        ## 8-byte Spill
	leaq	L_.str.84(%rip), %rcx
	movq	%rcx, -256(%rbp)        ## 8-byte Spill
	movq	%rdi, %rcx
	addq	$228, %rcx
	movq	%rcx, -264(%rbp)        ## 8-byte Spill
	leaq	L_.str.83(%rip), %rcx
	movq	%rcx, -272(%rbp)        ## 8-byte Spill
	movq	%rdi, %rcx
	addq	$171, %rcx
	movq	%rcx, -280(%rbp)        ## 8-byte Spill
	leaq	L_.str.82(%rip), %rcx
	movq	%rcx, -288(%rbp)        ## 8-byte Spill
	movq	%rdi, %rcx
	addq	$114, %rcx
	movq	%rcx, -296(%rbp)        ## 8-byte Spill
	leaq	L_.str.81(%rip), %rcx
	movq	%rcx, -304(%rbp)        ## 8-byte Spill
	movq	%rdi, %rcx
	addq	$57, %rcx
	movq	%rsi, -312(%rbp)        ## 8-byte Spill
	movq	%rdx, %rsi
	movq	%rdx, -320(%rbp)        ## 8-byte Spill
	movq	%r8, %rdx
	movl	%eax, -324(%rbp)        ## 4-byte Spill
	movq	%r13, -336(%rbp)        ## 8-byte Spill
	movq	%rcx, -344(%rbp)        ## 8-byte Spill
	movq	%r15, -352(%rbp)        ## 8-byte Spill
	movq	%r8, -360(%rbp)         ## 8-byte Spill
	movq	%r9, -368(%rbp)         ## 8-byte Spill
	movq	%r10, -376(%rbp)        ## 8-byte Spill
	movq	%r12, -384(%rbp)        ## 8-byte Spill
	movq	%r11, -392(%rbp)        ## 8-byte Spill
	movq	%rbx, -400(%rbp)        ## 8-byte Spill
	movq	%r14, -408(%rbp)        ## 8-byte Spill
	callq	_memcpy
	movq	-344(%rbp), %rdi        ## 8-byte Reload
	movq	-320(%rbp), %rsi        ## 8-byte Reload
	movq	-360(%rbp), %rdx        ## 8-byte Reload
	callq	_memcpy
	movq	-296(%rbp), %rdi        ## 8-byte Reload
	movq	-304(%rbp), %rsi        ## 8-byte Reload
	movq	-360(%rbp), %rdx        ## 8-byte Reload
	callq	_memcpy
	movq	-280(%rbp), %rdi        ## 8-byte Reload
	movq	-288(%rbp), %rsi        ## 8-byte Reload
	movq	-360(%rbp), %rdx        ## 8-byte Reload
	callq	_memcpy
	movq	-264(%rbp), %rdi        ## 8-byte Reload
	movq	-272(%rbp), %rsi        ## 8-byte Reload
	movq	-360(%rbp), %rdx        ## 8-byte Reload
	callq	_memcpy
	movq	-248(%rbp), %rdi        ## 8-byte Reload
	movq	-256(%rbp), %rsi        ## 8-byte Reload
	movq	-360(%rbp), %rdx        ## 8-byte Reload
	callq	_memcpy
	movq	-232(%rbp), %rdi        ## 8-byte Reload
	movq	-240(%rbp), %rsi        ## 8-byte Reload
	movq	-360(%rbp), %rdx        ## 8-byte Reload
	callq	_memcpy
	movq	-216(%rbp), %rdi        ## 8-byte Reload
	movq	-224(%rbp), %rsi        ## 8-byte Reload
	movq	-360(%rbp), %rdx        ## 8-byte Reload
	callq	_memcpy
	movq	-200(%rbp), %rdi        ## 8-byte Reload
	movq	-208(%rbp), %rsi        ## 8-byte Reload
	movq	-360(%rbp), %rdx        ## 8-byte Reload
	callq	_memcpy
	movq	-184(%rbp), %rdi        ## 8-byte Reload
	movq	-192(%rbp), %rsi        ## 8-byte Reload
	movq	-360(%rbp), %rdx        ## 8-byte Reload
	callq	_memcpy
	movq	-168(%rbp), %rdi        ## 8-byte Reload
	movq	-176(%rbp), %rsi        ## 8-byte Reload
	movq	-360(%rbp), %rdx        ## 8-byte Reload
	callq	_memcpy
	movq	-152(%rbp), %rdi        ## 8-byte Reload
	movq	-160(%rbp), %rsi        ## 8-byte Reload
	movq	-360(%rbp), %rdx        ## 8-byte Reload
	callq	_memcpy
	movq	-144(%rbp), %rdi        ## 8-byte Reload
	movq	-136(%rbp), %rsi        ## 8-byte Reload
	movq	-360(%rbp), %rdx        ## 8-byte Reload
	callq	_memcpy
	movq	-128(%rbp), %rdi        ## 8-byte Reload
	movq	-136(%rbp), %rsi        ## 8-byte Reload
	movq	-360(%rbp), %rdx        ## 8-byte Reload
	callq	_memcpy
	movq	-112(%rbp), %rdi        ## 8-byte Reload
	movq	-120(%rbp), %rsi        ## 8-byte Reload
	movq	-360(%rbp), %rdx        ## 8-byte Reload
	callq	_memcpy
	movq	-96(%rbp), %rdi         ## 8-byte Reload
	movq	-104(%rbp), %rsi        ## 8-byte Reload
	movq	-360(%rbp), %rdx        ## 8-byte Reload
	callq	_memcpy
	movq	-88(%rbp), %rdi         ## 8-byte Reload
	movq	-352(%rbp), %rsi        ## 8-byte Reload
	movq	-360(%rbp), %rdx        ## 8-byte Reload
	callq	_memcpy
	movq	-80(%rbp), %rdi         ## 8-byte Reload
	movq	-352(%rbp), %rsi        ## 8-byte Reload
	movq	-360(%rbp), %rdx        ## 8-byte Reload
	callq	_memcpy
	movq	-72(%rbp), %rdi         ## 8-byte Reload
	movq	-64(%rbp), %rsi         ## 8-byte Reload
	movq	-360(%rbp), %rdx        ## 8-byte Reload
	callq	_memcpy
	movq	-336(%rbp), %rdi        ## 8-byte Reload
	movq	-64(%rbp), %rsi         ## 8-byte Reload
	movq	-360(%rbp), %rdx        ## 8-byte Reload
	callq	_memcpy
	movq	-384(%rbp), %rdi        ## 8-byte Reload
	movq	-352(%rbp), %rsi        ## 8-byte Reload
	movq	-360(%rbp), %rdx        ## 8-byte Reload
	callq	_memcpy
	movq	-408(%rbp), %rdi        ## 8-byte Reload
	movq	-352(%rbp), %rsi        ## 8-byte Reload
	movq	-360(%rbp), %rdx        ## 8-byte Reload
	callq	_memcpy
	movq	-392(%rbp), %rdi        ## 8-byte Reload
	movq	-400(%rbp), %rsi        ## 8-byte Reload
	movq	-360(%rbp), %rdx        ## 8-byte Reload
	callq	_memcpy
	movq	-376(%rbp), %rdi        ## 8-byte Reload
	movq	-312(%rbp), %rsi        ## 8-byte Reload
	movq	-360(%rbp), %rdx        ## 8-byte Reload
	callq	_memcpy
	movq	-368(%rbp), %rdi        ## 8-byte Reload
	movq	-320(%rbp), %rsi        ## 8-byte Reload
	movq	-360(%rbp), %rdx        ## 8-byte Reload
	callq	_memcpy
	movq	-56(%rbp), %rdi         ## 8-byte Reload
	movq	-320(%rbp), %rsi        ## 8-byte Reload
	movq	-360(%rbp), %rdx        ## 8-byte Reload
	callq	_memcpy
	addq	$376, %rsp              ## imm = 0x178
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__Z5setupv
	.p2align	4, 0x90
__Z5setupv:                             ## @_Z5setupv
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi54:
	.cfi_def_cfa_offset 16
Lcfi55:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi56:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	xorl	%eax, %eax
	movl	%eax, %edi
	callq	_time
	movl	%eax, %ecx
	movl	%ecx, %edi
	callq	_srand
	movl	$0, -4(%rbp)
LBB15_1:                                ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB15_3 Depth 2
	cmpl	$26, -4(%rbp)
	jge	LBB15_8
## BB#2:                                ##   in Loop: Header=BB15_1 Depth=1
	movl	$0, -8(%rbp)
LBB15_3:                                ##   Parent Loop BB15_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpl	$56, -8(%rbp)
	jge	LBB15_6
## BB#4:                                ##   in Loop: Header=BB15_3 Depth=2
	leaq	_map(%rip), %rax
	movslq	-4(%rbp), %rcx
	imulq	$57, %rcx, %rcx
	addq	%rcx, %rax
	movslq	-8(%rbp), %rcx
	movb	$32, (%rax,%rcx)
## BB#5:                                ##   in Loop: Header=BB15_3 Depth=2
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	LBB15_3
LBB15_6:                                ##   in Loop: Header=BB15_1 Depth=1
	leaq	_map(%rip), %rax
	movslq	-4(%rbp), %rcx
	imulq	$57, %rcx, %rcx
	addq	%rcx, %rax
	movb	$0, 56(%rax)
## BB#7:                                ##   in Loop: Header=BB15_1 Depth=1
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -4(%rbp)
	jmp	LBB15_1
LBB15_8:
	movl	$0, -12(%rbp)
LBB15_9:                                ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB15_11 Depth 2
	cmpl	$7, -12(%rbp)
	jge	LBB15_16
## BB#10:                               ##   in Loop: Header=BB15_9 Depth=1
	movl	$0, -16(%rbp)
LBB15_11:                               ##   Parent Loop BB15_9 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpl	$56, -16(%rbp)
	jge	LBB15_14
## BB#12:                               ##   in Loop: Header=BB15_11 Depth=2
	leaq	_menu(%rip), %rax
	movslq	-12(%rbp), %rcx
	imulq	$57, %rcx, %rcx
	addq	%rcx, %rax
	movslq	-16(%rbp), %rcx
	movb	$46, (%rax,%rcx)
## BB#13:                               ##   in Loop: Header=BB15_11 Depth=2
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -16(%rbp)
	jmp	LBB15_11
LBB15_14:                               ##   in Loop: Header=BB15_9 Depth=1
	leaq	_menu(%rip), %rax
	movslq	-12(%rbp), %rcx
	imulq	$57, %rcx, %rcx
	addq	%rcx, %rax
	movb	$0, 56(%rax)
## BB#15:                               ##   in Loop: Header=BB15_9 Depth=1
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -12(%rbp)
	jmp	LBB15_9
LBB15_16:
	callq	__Z8setupMapv
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__Z4drawv
	.p2align	4, 0x90
__Z4drawv:                              ## @_Z4drawv
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi57:
	.cfi_def_cfa_offset 16
Lcfi58:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi59:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	callq	__Z8setupMapv
	movl	$0, -4(%rbp)
LBB16_1:                                ## =>This Inner Loop Header: Depth=1
	cmpl	$2, -4(%rbp)
	jge	LBB16_4
## BB#2:                                ##   in Loop: Header=BB16_1 Depth=1
	leaq	_players(%rip), %rax
	leaq	_map(%rip), %rcx
	movslq	-4(%rbp), %rdx
	imulq	$44, %rdx, %rdx
	movq	%rax, %rsi
	addq	%rdx, %rsi
	movb	8(%rsi), %dil
	movslq	-4(%rbp), %rdx
	imulq	$44, %rdx, %rdx
	movq	%rax, %rsi
	addq	%rdx, %rsi
	movslq	(%rsi), %rdx
	imulq	$57, %rdx, %rdx
	addq	%rdx, %rcx
	movslq	-4(%rbp), %rdx
	imulq	$44, %rdx, %rdx
	addq	%rdx, %rax
	movslq	4(%rax), %rax
	movb	%dil, (%rcx,%rax)
## BB#3:                                ##   in Loop: Header=BB16_1 Depth=1
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -4(%rbp)
	jmp	LBB16_1
LBB16_4:
	movl	$0, -8(%rbp)
LBB16_5:                                ## =>This Inner Loop Header: Depth=1
	cmpl	$58, -8(%rbp)
	jge	LBB16_8
## BB#6:                                ##   in Loop: Header=BB16_5 Depth=1
	leaq	L_.str.98(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -20(%rbp)         ## 4-byte Spill
## BB#7:                                ##   in Loop: Header=BB16_5 Depth=1
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	LBB16_5
LBB16_8:
	leaq	L_.str.99(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	$0, -12(%rbp)
	movl	%eax, -24(%rbp)         ## 4-byte Spill
LBB16_9:                                ## =>This Inner Loop Header: Depth=1
	cmpl	$26, -12(%rbp)
	jge	LBB16_12
## BB#10:                               ##   in Loop: Header=BB16_9 Depth=1
	leaq	L_.str.100(%rip), %rdi
	leaq	_map(%rip), %rax
	movslq	-12(%rbp), %rcx
	imulq	$57, %rcx, %rcx
	addq	%rcx, %rax
	movq	%rax, %rsi
	movb	$0, %al
	callq	_printf
	movl	%eax, -28(%rbp)         ## 4-byte Spill
## BB#11:                               ##   in Loop: Header=BB16_9 Depth=1
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -12(%rbp)
	jmp	LBB16_9
LBB16_12:
	movl	$0, -16(%rbp)
LBB16_13:                               ## =>This Inner Loop Header: Depth=1
	cmpl	$58, -16(%rbp)
	jge	LBB16_16
## BB#14:                               ##   in Loop: Header=BB16_13 Depth=1
	leaq	L_.str.98(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -32(%rbp)         ## 4-byte Spill
## BB#15:                               ##   in Loop: Header=BB16_13 Depth=1
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -16(%rbp)
	jmp	LBB16_13
LBB16_16:
	leaq	L_.str.99(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -36(%rbp)         ## 4-byte Spill
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi60:
	.cfi_def_cfa_offset 16
Lcfi61:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi62:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	callq	__Z5setupv
LBB17_1:                                ## =>This Inner Loop Header: Depth=1
	cmpl	$0, _GAME(%rip)
	je	LBB17_3
## BB#2:                                ##   in Loop: Header=BB17_1 Depth=1
	callq	__Z4drawv
	callq	__Z8getInputv
	callq	__Z7processv
	jmp	LBB17_1
LBB17_3:
	xorl	%eax, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__StaticInit,regular,pure_instructions
	.p2align	4, 0x90
__GLOBAL__sub_I_bankruptgame2.c:        ## @_GLOBAL__sub_I_bankruptgame2.c
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi63:
	.cfi_def_cfa_offset 16
Lcfi64:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi65:
	.cfi_def_cfa_register %rbp
	callq	___cxx_global_var_init
	callq	___cxx_global_var_init.1
	callq	___cxx_global_var_init.2
	callq	___cxx_global_var_init.3
	popq	%rbp
	retq
	.cfi_endproc

	.section	__DATA,__data
	.globl	_GAME                   ## @GAME
	.p2align	2
_GAME:
	.long	1                       ## 0x1

	.globl	_map                    ## @map
.zerofill __DATA,__common,_map,1482,4
	.globl	_menu                   ## @menu
.zerofill __DATA,__common,_menu,399,4
	.globl	_cursor                 ## @cursor
.zerofill __DATA,__common,_cursor,4,2
	.globl	_turn                   ## @turn
.zerofill __DATA,__common,_turn,4,2
	.globl	_tax                    ## @tax
.zerofill __DATA,__common,_tax,4,2
	.globl	_maxTurn                ## @maxTurn
	.p2align	2
_maxTurn:
	.long	1000                    ## 0x3e8

	.globl	_hyunseoPlayer          ## @hyunseoPlayer
	.p2align	2
_hyunseoPlayer:
	.long	18                      ## 0x12
	.long	40                      ## 0x28
	.byte	72                      ## 0x48
	.space	3
	.long	30000                   ## 0x7530
	.long	0                       ## 0x0
	.space	2
	.space	6
	.space	10
	.space	2
	.long	0                       ## 0x0

	.globl	_chanhoPlayer           ## @chanhoPlayer
	.p2align	2
_chanhoPlayer:
	.long	18                      ## 0x12
	.long	41                      ## 0x29
	.byte	67                      ## 0x43
	.space	3
	.long	30000                   ## 0x7530
	.long	0                       ## 0x0
	.space	2
	.space	6
	.space	10
	.space	2
	.long	0                       ## 0x0

	.globl	_players                ## @players
.zerofill __DATA,__common,_players,88,4
	.globl	_land1                  ## @land1
	.p2align	2
_land1:
	.long	7                       ## 0x7
	.long	1                       ## 0x1
	.asciz	"land1\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
	.long	0                       ## 0x0
	.long	10                      ## 0xa
	.long	2                       ## 0x2
	.long	1                       ## 0x1

	.globl	_land2                  ## @land2
	.p2align	2
_land2:
	.long	5                       ## 0x5
	.long	1                       ## 0x1
	.asciz	"land2\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
	.long	0                       ## 0x0
	.long	10                      ## 0xa
	.long	2                       ## 0x2
	.long	1                       ## 0x1

	.globl	_land3                  ## @land3
	.p2align	2
_land3:
	.long	5                       ## 0x5
	.long	3                       ## 0x3
	.asciz	"land3\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
	.long	0                       ## 0x0
	.long	10                      ## 0xa
	.long	2                       ## 0x2
	.long	1                       ## 0x1

	.globl	_land4                  ## @land4
	.p2align	2
_land4:
	.long	3                       ## 0x3
	.long	3                       ## 0x3
	.asciz	"land4\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
	.long	0                       ## 0x0
	.long	10                      ## 0xa
	.long	2                       ## 0x2
	.long	1                       ## 0x1

	.globl	_land5                  ## @land5
	.p2align	2
_land5:
	.long	3                       ## 0x3
	.long	1                       ## 0x1
	.asciz	"land5\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
	.long	0                       ## 0x0
	.long	10                      ## 0xa
	.long	2                       ## 0x2
	.long	1                       ## 0x1

	.globl	_lands                  ## @lands
.zerofill __DATA,__common,_lands,620,4
	.globl	_factory1               ## @factory1
	.p2align	2
_factory1:
	.long	7                       ## 0x7
	.long	8                       ## 0x8
	.asciz	"factory1\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
	.long	0                       ## 0x0
	.long	10                      ## 0xa
	.long	2                       ## 0x2
	.long	2                       ## 0x2

	.globl	_factory2               ## @factory2
	.p2align	2
_factory2:
	.long	7                       ## 0x7
	.long	12                      ## 0xc
	.asciz	"factory2\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
	.long	0                       ## 0x0
	.long	10                      ## 0xa
	.long	2                       ## 0x2
	.long	2                       ## 0x2

	.globl	_factory3               ## @factory3
	.p2align	2
_factory3:
	.long	11                      ## 0xb
	.long	8                       ## 0x8
	.asciz	"factory3\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
	.long	0                       ## 0x0
	.long	10                      ## 0xa
	.long	2                       ## 0x2
	.long	2                       ## 0x2

	.globl	_factory4               ## @factory4
	.p2align	2
_factory4:
	.long	11                      ## 0xb
	.long	12                      ## 0xc
	.asciz	"factory4\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
	.long	0                       ## 0x0
	.long	10                      ## 0xa
	.long	2                       ## 0x2
	.long	2                       ## 0x2

	.globl	_factories              ## @factories
.zerofill __DATA,__common,_factories,496,4
	.globl	_electricFactory1       ## @electricFactory1
	.p2align	2
_electricFactory1:
	.long	7                       ## 0x7
	.long	4                       ## 0x4
	.asciz	"electricFactory1\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
	.long	0                       ## 0x0
	.long	0                       ## 0x0
	.long	0                       ## 0x0
	.long	2                       ## 0x2
	.long	0                       ## 0x0

	.globl	_electricFactory2       ## @electricFactory2
	.p2align	2
_electricFactory2:
	.long	11                      ## 0xb
	.long	4                       ## 0x4
	.asciz	"electricFactory2\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
	.long	0                       ## 0x0
	.long	0                       ## 0x0
	.long	0                       ## 0x0
	.long	2                       ## 0x2
	.long	0                       ## 0x0

	.globl	_electricFactories      ## @electricFactories
.zerofill __DATA,__common,_electricFactories,256,4
	.globl	_prices                 ## @prices
	.p2align	4
_prices:
	.quad	5000                    ## 0x1388
	.quad	10000                   ## 0x2710
	.quad	30000                   ## 0x7530
	.quad	50000                   ## 0xc350
	.quad	100000                  ## 0x186a0
	.quad	300000                  ## 0x493e0
	.quad	500000                  ## 0x7a120
	.quad	1000000                 ## 0xf4240
	.quad	3000000                 ## 0x2dc6c0
	.quad	5000000                 ## 0x4c4b40

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"\353\202\250\354\235\230 \353\225\205\354\236\205\353\213\210\353\213\244.\n"

L_.str.4:                               ## @.str.4
	.asciz	"1. \354\210\230\355\231\225\355\225\230\352\270\260\n"

L_.str.5:                               ## @.str.5
	.asciz	"2. \354\213\254\352\270\260\n"

L_.str.6:                               ## @.str.6
	.asciz	"3. \354\203\235\354\204\261 \352\260\200\354\206\215\355\225\230\352\270\260 cost: 1000000\n"

L_.str.7:                               ## @.str.7
	.asciz	"%d"

L_.str.8:                               ## @.str.8
	.asciz	"\354\204\261\352\263\265\354\240\201\354\234\274\353\241\234 \354\210\230\355\231\225\355\225\230\354\230\200\354\212\265\353\213\210\353\213\244.\n"

L_.str.9:                               ## @.str.9
	.asciz	"\354\213\235\353\254\274\354\235\264 \353\215\234 \354\236\220\353\236\220\354\212\265\353\213\210\353\213\244.\n"

L_.str.10:                              ## @.str.10
	.asciz	"1. \354\224\250\354\225\227\n"

L_.str.11:                              ## @.str.11
	.asciz	"2. \352\260\220\354\236\220\n"

L_.str.12:                              ## @.str.12
	.asciz	"\354\213\254\354\235\204 \354\224\250\354\225\227\354\235\264 \354\227\206\354\212\265\353\213\210\353\213\244\n"

L_.str.13:                              ## @.str.13
	.asciz	"\353\252\250\353\221\220 \354\213\254\354\227\210\354\212\265\353\213\210\353\213\244.\n"

L_.str.14:                              ## @.str.14
	.asciz	"\354\225\275\354\235\204 \354\202\264 \353\217\210\354\235\264 \354\227\206\354\212\265\353\213\210\353\213\244.\n"

L_.str.15:                              ## @.str.15
	.asciz	"\354\225\275\354\235\204 \354\204\261\352\263\265\354\240\201\354\234\274\353\241\234 \354\203\200\354\212\265\353\213\210\353\213\244.\n"

L_.str.16:                              ## @.str.16
	.asciz	"\353\202\250\354\235\230 \354\240\204\352\270\260\352\263\265\354\236\245\354\236\205\353\213\210\353\213\244.\n"

L_.str.17:                              ## @.str.17
	.asciz	"\353\254\264\354\227\207\354\235\204 \355\225\230\354\213\234\352\262\240\354\212\265\353\213\210\352\271\214?\n"

L_.str.18:                              ## @.str.18
	.asciz	"1. \353\260\230\353\217\204\354\262\264 \355\214\220\353\247\244\n"

L_.str.19:                              ## @.str.19
	.asciz	"2. \352\263\265\354\236\245 \353\217\214\353\246\254\352\270\260  \353\260\230\353\217\204\354\262\264 \354\204\270\355\212\270X1\n"

L_.str.20:                              ## @.str.20
	.asciz	"3. \352\270\260\352\263\204 \352\265\254\353\247\244\n"

L_.str.21:                              ## @.str.21
	.asciz	"\353\252\250\353\221\220 \355\214\220\353\247\244\355\225\230\354\230\200\354\212\265\353\213\210\353\213\244.\n"

L_.str.22:                              ## @.str.22
	.asciz	"\353\217\210\354\235\264 \353\266\200\354\241\261\355\225\251\353\213\210\353\213\244.\n"

L_.str.23:                              ## @.str.23
	.asciz	"\353\202\250\354\235\230 \352\263\265\354\236\245\354\236\205\353\213\210\353\213\244.\n"

L_.str.24:                              ## @.str.24
	.asciz	"3. \354\203\235\354\204\261 \352\260\200\354\206\215\355\225\230\352\270\260 cost: 5000000\n"

L_.str.25:                              ## @.str.25
	.asciz	"\353\254\264\354\212\250 \353\225\205\354\235\204 \354\202\254\354\213\234\352\262\240\354\212\265\353\213\210\352\271\214?\n"

L_.str.26:                              ## @.str.26
	.asciz	"%d\353\262\210 \353\225\205 (\354\243\274\354\235\270: hyunseo)\n"

L_.str.27:                              ## @.str.27
	.asciz	"%d\353\262\210 \353\225\205 (\354\243\274\354\235\270: chanho)\n"

L_.str.28:                              ## @.str.28
	.asciz	"%d\353\262\210 \353\225\205 (\354\243\274\354\235\270: \354\227\206\354\235\214)\n"

L_.str.29:                              ## @.str.29
	.asciz	"%d\353\262\210 \354\240\204\352\270\260\352\263\265\354\236\245 (\354\243\274\354\235\270: hyunseo)\n"

L_.str.30:                              ## @.str.30
	.asciz	"%d\353\262\210 \354\240\204\352\270\260\352\263\265\354\236\245 (\354\243\274\354\235\270: chanho)\n"

L_.str.31:                              ## @.str.31
	.asciz	"%d\353\262\210 \354\240\204\352\270\260\352\263\265\354\236\245 (\354\243\274\354\235\270: \354\227\206\354\235\214)\n"

L_.str.32:                              ## @.str.32
	.asciz	"%d\353\262\210 \352\263\265\354\236\245 (\354\243\274\354\235\270: hyunseo)\n"

L_.str.33:                              ## @.str.33
	.asciz	"%d\353\262\210 \352\263\265\354\236\245 (\354\243\274\354\235\270: chanho)\n"

L_.str.34:                              ## @.str.34
	.asciz	"%d\353\262\210 \352\263\265\354\236\245 (\354\243\274\354\235\270: \354\227\206\354\235\214)\n"

L_.str.35:                              ## @.str.35
	.asciz	"\353\254\264\354\227\207\354\235\204 \354\202\254\354\213\234\352\262\240\354\212\265\353\213\210\352\271\214?\n"

L_.str.36:                              ## @.str.36
	.asciz	"1. \353\225\205 (300000\353\247\214\354\233\220)\n"

L_.str.37:                              ## @.str.37
	.asciz	"2. \352\263\265\354\236\245 (2000000\354\233\220)\n"

L_.str.38:                              ## @.str.38
	.asciz	"3. \354\240\204\352\270\260\352\263\265\354\236\245 (30000000\354\233\220)\n"

L_.str.39:                              ## @.str.39
	.asciz	"\354\226\264\353\226\244 \352\262\203\354\235\204 \354\202\254\354\213\234\352\262\240\354\212\265\353\213\210\352\271\214?\n"

L_.str.40:                              ## @.str.40
	.asciz	"\354\243\274\354\235\270\354\235\264 \354\236\210\354\212\265\353\213\210\353\213\244.\n"

L_.str.41:                              ## @.str.41
	.asciz	"\352\262\260\354\240\234\354\231\204\353\243\214 \353\220\230\354\227\210\354\212\265\353\213\210\353\213\244.\n"

L_.str.42:                              ## @.str.42
	.asciz	" \354\262\253 \353\262\210\354\247\270 \354\210\253\354\236\220\353\245\274 \354\240\201\354\226\264\354\243\274\354\204\270\354\232\224\n"

L_.str.43:                              ## @.str.43
	.asciz	"\353\221\220 \353\262\210\354\247\270 \354\210\253\354\236\220\353\245\274 \354\240\201\354\226\264\354\243\274\354\204\270\354\232\224\n"

L_.str.44:                              ## @.str.44
	.asciz	"\354\227\220\353\251\224\353\236\204\353\223\234 \354\236\205\353\213\210\353\213\244\n"

L_.str.45:                              ## @.str.45
	.asciz	"\353\213\244\354\235\264\354\225\204\353\252\254\353\223\234 \354\236\205\353\213\210\353\213\244\n"

L_.str.46:                              ## @.str.46
	.asciz	"\352\270\210 \354\236\205\353\213\210\353\213\244\n"

L_.str.47:                              ## @.str.47
	.asciz	"\354\262\240 \354\236\205\353\213\210\353\213\244\n"

L_.str.48:                              ## @.str.48
	.asciz	"\354\204\235\355\203\204 \354\236\205\353\213\210\353\213\244\n"

L_.str.49:                              ## @.str.49
	.asciz	"\353\217\214 \354\236\205\353\213\210\353\213\244\n"

L_.str.50:                              ## @.str.50
	.asciz	"\352\262\260\354\240\234\354\231\204\353\243\214 \353\220\230\354\227\210\354\212\265\353\213\210\353\213\244. \354\264\235: %d\354\233\220\n"

L_.str.51:                              ## @.str.51
	.asciz	"\355\224\214\353\240\210\354\235\264\354\226\264 %d \354\204\270\352\270\210\353\202\251\353\266\200 \354\231\204\353\243\214\n"

L_.str.52:                              ## @.str.52
	.asciz	"-----------------------------------\n"

L_.str.53:                              ## @.str.53
	.asciz	"0.\352\270\260\353\205\220\354\243\274\355\231\224 \352\260\200\352\262\251: %llu\n"

L_.str.54:                              ## @.str.54
	.asciz	"1.\354\235\200 \352\267\200\352\261\270\354\235\264 \352\260\200\352\262\251: %llu\n"

L_.str.55:                              ## @.str.55
	.asciz	"2.\352\270\210 \355\214\224\354\260\214 \352\260\200\352\262\251: %llu\n"

L_.str.56:                              ## @.str.56
	.asciz	"3.\353\213\244\354\235\264\354\225\204\353\252\254\353\223\234 \353\260\230\354\247\200 \352\260\200\352\262\251: %llu\n"

L_.str.57:                              ## @.str.57
	.asciz	"4.\354\227\220\353\251\224\353\236\204\353\223\234 \353\252\251\352\261\270\354\235\264 \352\260\200\352\262\251: %llu\n"

L_.str.58:                              ## @.str.58
	.asciz	"5.\354\202\254\355\214\214\354\235\264\354\226\264 \353\250\270\353\246\254\355\225\200 \352\260\200\352\262\251: %llu\n"

L_.str.59:                              ## @.str.59
	.asciz	"6.\355\206\240\355\214\214\354\246\210 \353\270\214\353\241\234\354\271\230 \352\260\200\352\262\251: %llu\n"

L_.str.60:                              ## @.str.60
	.asciz	"7.\353\243\250\353\271\204 \355\213\260\354\225\204\353\235\274 \352\260\200\352\262\251: %llu\n"

L_.str.61:                              ## @.str.61
	.asciz	"8.\355\203\200\355\214\214\354\235\264\355\212\270 \355\212\270\353\241\234\355\224\274 \352\260\200\352\262\251: %llu\n"

L_.str.62:                              ## @.str.62
	.asciz	"9.\355\231\224\353\240\244\355\225\234 \352\265\254\354\212\254 \352\260\200\352\262\251: %llu\n\n"

L_.str.63:                              ## @.str.63
	.asciz	"1. \354\202\254\352\270\260\n"

L_.str.64:                              ## @.str.64
	.asciz	"2. \355\214\224\352\270\260\n"

L_.str.65:                              ## @.str.65
	.asciz	"\353\252\207\352\260\234 \354\202\254\354\213\234\352\262\240\354\212\265\353\213\210\352\271\214?\n"

L_.str.66:                              ## @.str.66
	.asciz	"\353\217\210\354\235\264 \354\227\206\354\226\264\354\204\234 \354\253\223\352\262\250\353\202\254\354\212\265\353\213\210\353\213\244.\n"

L_.str.67:                              ## @.str.67
	.asciz	"\354\204\261\352\263\265\354\240\201 \352\265\254\353\247\244\355\225\230\354\230\200\354\212\265\353\213\210\353\213\244.\n"

L_.str.68:                              ## @.str.68
	.asciz	"\353\254\264\354\227\207\354\235\204 \355\214\214\354\213\234\352\262\240\354\212\265\353\213\210\352\271\214?\n"

L_.str.69:                              ## @.str.69
	.asciz	"\354\226\274\353\247\214\355\201\274 \355\214\214\354\213\234\352\262\240\354\212\265\353\213\210\352\271\214?\n"

L_.str.70:                              ## @.str.70
	.asciz	"\353\263\264\354\204\235\354\235\264 \353\266\200\354\241\261\355\225\251\353\213\210\353\213\244.\n"

L_.str.71:                              ## @.str.71
	.asciz	"\354\204\261\352\263\265\354\240\201\354\234\274\353\241\234 \355\214\220\353\247\244\355\225\230\354\230\200\354\212\265\353\213\210\353\213\244.\n"

L_.str.72:                              ## @.str.72
	.asciz	"1. \353\202\230\353\245\274 \354\234\204\355\225\234 \353\217\204\353\260\225\n"

L_.str.73:                              ## @.str.73
	.asciz	"2. \353\204\210\353\247\214\354\235\204 \354\234\204\355\225\234 \353\217\204\353\260\225\n"

L_.str.74:                              ## @.str.74
	.asciz	"3. \354\232\260\353\246\254\353\245\274 \354\234\204\355\225\234 \353\217\204\353\260\225\n"

	.section	__TEXT,__const
	.p2align	2               ## @_ZZ14playerInCasinovE6casino
l__ZZ14playerInCasinovE6casino:
	.long	5000                    ## 0x1388
	.long	300000                  ## 0x493e0
	.long	100000                  ## 0x186a0

	.section	__TEXT,__cstring,cstring_literals
L_.str.75:                              ## @.str.75
	.asciz	"\353\217\210\354\235\204 \354\244\200\353\271\204\355\225\264 \354\230\244\354\213\255\354\213\234\354\230\244...\n"

L_.str.76:                              ## @.str.76
	.asciz	"%c\354\235\230 \353\217\210\354\235\264 %d\353\247\214\355\201\274 \354\266\224\352\260\200\353\220\230\354\227\210\354\212\265\353\213\210\353\213\244.\n"

L_.str.77:                              ## @.str.77
	.asciz	"\354\204\270\352\270\210 \353\202\251\353\266\200\352\271\214\354\247\200: %d\n"

L_.str.78:                              ## @.str.78
	.asciz	"\355\224\214\353\240\210\354\235\264\354\226\2641 %d\354\233\220\n"

L_.str.79:                              ## @.str.79
	.asciz	"\355\224\214\353\240\210\354\235\264\354\226\2642 %d\354\233\220\n"

L_.str.80:                              ## @.str.80
	.asciz	"||||||||||||||||||||||||||||||||||||||||||||||||||||||||"

L_.str.81:                              ## @.str.81
	.asciz	"||||||||||||||||||||||||||||||||        JJJJ        ||||"

L_.str.82:                              ## @.str.82
	.asciz	"||||||||||||||||||||||||||||||||        YYYY        ||||"

L_.str.83:                              ## @.str.83
	.asciz	"||||||||||||||||||||||||||||||||                    ||||"

L_.str.84:                              ## @.str.84
	.asciz	"||||||||||||||||||||||||||||||||BBBBB   GGGGG   222 ||||"

L_.str.85:                              ## @.str.85
	.asciz	"||||LLLL    LLLL||||||||||||||||BB  BB GG      22  2||||"

L_.str.86:                              ## @.str.86
	.asciz	"||||5555    4444||||||||||||||||BBBBB  G   GGG    2 ||||"

L_.str.87:                              ## @.str.87
	.asciz	"||||            ||||||||||||||||BB  BB GG    G  22  ||||"

L_.str.88:                              ## @.str.88
	.asciz	"||||            ||||||||||||||||BBBBB   GGGGGG 22222||||"

L_.str.89:                              ## @.str.89
	.asciz	"||||LLLL    LLLL||||||||||||||||        CCCC        ||||"

L_.str.90:                              ## @.str.90
	.asciz	"||||2222    3333||||||||||||||||        CCCC        ||||"

L_.str.91:                              ## @.str.91
	.asciz	"||||            ||||||||||||||||                    ||||"

L_.str.92:                              ## @.str.92
	.asciz	"||||LLLL    EEEEEEEEEEEEEEEE    FFFF            FFFF||||"

L_.str.93:                              ## @.str.93
	.asciz	"||||1111    1111DDDD11111111    1111            2222||||"

L_.str.94:                              ## @.str.94
	.asciz	"||||                                                ||||"

L_.str.95:                              ## @.str.95
	.asciz	"||||                                            WWWW||||"

L_.str.96:                              ## @.str.96
	.asciz	"||||RRRR    EEEEDDDDEEEEEEEE    FFFF    CCCC    FFFF||||"

L_.str.97:                              ## @.str.97
	.asciz	"||||EEEE    2222222222222222    3333    HHHH    4444||||"

L_.str.98:                              ## @.str.98
	.asciz	"*"

L_.str.99:                              ## @.str.99
	.asciz	"\n"

L_.str.100:                             ## @.str.100
	.asciz	"*%s*\n"

L_.str.101:                             ## @.str.101
	.asciz	"%s"

L_.str.102:                             ## @.str.102
	.asciz	"\354\204\270\352\270\210\354\235\204 \353\202\251\353\266\200\355\225\230\352\270\260 \354\234\204\355\225\264 \354\213\234\354\262\255\354\234\274\353\241\234 \354\235\264\353\217\231\354\213\234\355\202\244\352\262\240\354\212\265\353\213\210\353\213\244.\n"

	.section	__DATA,__mod_init_func,mod_init_funcs
	.p2align	3
	.quad	__GLOBAL__sub_I_bankruptgame2.c

.subsections_via_symbols
