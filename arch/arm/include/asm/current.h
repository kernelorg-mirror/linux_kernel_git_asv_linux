/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2021 Keith Packard <keithp@keithp.com>
 * Copyright (c) 2021 Google, LLC <ardb@kernel.org>
 */

#ifndef _ASM_ARM_CURRENT_H
#define _ASM_ARM_CURRENT_H

#ifndef __ASSEMBLY__
#include <asm/insn.h>

struct task_struct;

extern struct task_struct *__current;

static inline __attribute_const__ struct task_struct *get_current(void)
{
	return __current;
}

#define current get_current()

#endif /* __ASSEMBLY__ */

#endif /* _ASM_ARM_CURRENT_H */
