#ifndef _KAM_REQUIRE_KALLSYMS_H_

#define PRIV_KSYM_TABLE(_)   \
  _(can_probe)               \
  _(text_mutex)              \
  _(text_poke)               \
  _(module_alloc)            \


#ifdef _once
#include <asm/pgtable_types.h>     // for __vmalloc_node_range types
#include <linux/mutex.h>
#include <linux/types.h>           // others

_once void* (*KPRIV(module_alloc))(unsigned long size);
_once int (*KPRIV(can_probe))(unsigned long paddr);
_once struct mutex *KPRIV(text_mutex);
_once void* (*KPRIV(text_poke))(void *addr, const void *opcode, size_t len);
#endif

#endif
