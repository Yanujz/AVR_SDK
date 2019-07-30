#ifndef CPPFIX_H
#define CPPFIX_H
#include <stdlib.h>

__extension__ typedef int __guard __attribute__((mode (__DI__)));

void * operator new(size_t size) throw();
void operator delete(void *ptr) throw();

void *operator new[](size_t size)throw();
void operator delete[](void *ptr, size_t i)throw();



__extension__ typedef int __guard __attribute__((mode (__DI__)));

extern "C" int __cxa_guard_acquire(__guard *);
extern "C" void __cxa_guard_release (__guard *);
extern "C" void __cxa_guard_abort (__guard *);
extern "C" void __cxa_pure_virtual(void);


#endif //CPPFIX_H

