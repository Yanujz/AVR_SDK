#include <core.h>
#if defined (__MEGA_SERIES__)

#include "mega_new.h"


int __cxa_guard_acquire(__guard *g) {return !*(char *)(g);}
void __cxa_guard_release (__guard *g) {*(char *)g = 1;}
void __cxa_guard_abort (__guard *) {}
void __cxa_pure_virtual(void) {}



void * operator new(size_t size)
{
    return malloc(size);
}

void operator delete(void * ptr)
{
    free(ptr);
}

void operator delete(void *ptr, unsigned int){
    free(ptr);
}


void *operator new[](size_t size)
{
    if(size == 0){
	size = 1;
    }
    void * p = malloc(size);
    //if(p == nullptr){
	//return nullptr;
    //}
    return p;
}

void operator delete[](void *ptr)
{
    free(ptr);
}



void operator delete[](void *ptr, size_t i)
{
    free(ptr);
}
#endif


