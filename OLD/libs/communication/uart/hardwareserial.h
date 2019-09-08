#pragma once
#include <core.h>

#if defined(__SERIAL0_SUPPORT__)
#include <asyncserial0.h>
#endif

#if defined(__SERIAL1_SUPPORT__)
#include <asyncserial1.h>
#endif

#if defined(__SERIAL2_SUPPORT__)
#include <asyncserial2.h>
#endif

#if defined(__SERIAL3_SUPPORT__)
#include <asyncserial3.h>
#endif

