/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright 2012 Calxeda, Inc.
 */
#ifndef _ASM_ARM_PERCPU_H_
#define _ASM_ARM_PERCPU_H_

#include <asm/insn.h>

register unsigned long current_stack_pointer asm ("sp");

/*
 * Same as asm-generic/percpu.h, except that we store the per cpu offset
 * in the TPIDRPRW. TPIDRPRW only exists on V6K and V7
 */
#ifdef CONFIG_SMP
static inline void set_my_cpu_offset(unsigned long off)
{
	extern unsigned int smp_on_up;

	if (IS_ENABLED(CONFIG_CPU_V6) && !smp_on_up)
		return;

	/* Set TPIDRPRW */
	asm volatile("mcr p15, 0, %0, c13, c0, 4" : : "r" (off) : "memory");
}

extern unsigned long __per_cpu_offset[];
static __always_inline unsigned long __my_cpu_offset(void)
{
	return __per_cpu_offset[0];
}
#define __my_cpu_offset __my_cpu_offset()
#else
#define set_my_cpu_offset(x)	do {} while(0)

#endif /* CONFIG_SMP */

#include <asm-generic/percpu.h>

#endif /* _ASM_ARM_PERCPU_H_ */
