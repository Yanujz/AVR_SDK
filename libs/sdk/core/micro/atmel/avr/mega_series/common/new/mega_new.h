#pragma once
#include <core.h>
#if defined (__MEGA_SERIES__)
#include <stdlib.h>

__extension__ typedef int __guard __attribute__((mode (__DI__)));

void * operator new(size_t size);
void operator delete(void *ptr);
void operator delete(void*, unsigned int);

void *operator new[](size_t size);
void operator delete[](void *ptr, size_t i);


__extension__ typedef int __guard __attribute__((mode (__DI__)));

extern "C" int __cxa_guard_acquire(__guard *);
extern "C" void __cxa_guard_release (__guard *);
extern "C" void __cxa_guard_abort (__guard *);
extern "C" void __cxa_pure_virtual(void);

#endif

