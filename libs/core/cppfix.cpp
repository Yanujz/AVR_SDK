#include "cppfix.h"


//int __cxa_guard_acquire(__guard *g) {return !*(char *)(g);}
//void __cxa_guard_release (__guard *g) {*(char *)g = 1;}
//void __cxa_guard_abort (__guard *) {}
//void __cxa_pure_virtual(void) {}



void * operator new(size_t size) throw()
{
				return malloc(size);
}

void operator delete(void * ptr) throw()
{
				free(ptr);
}

void *operator new[](size_t size) throw()
{
				if(size == 0){
								size = 1;
				}
				void * p = malloc(size);
				if(p == 0){
								return nullptr;
				}
				return p;
}

void operator delete[](void *ptr) throw()
{
				free(ptr);
}
