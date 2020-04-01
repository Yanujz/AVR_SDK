/*
	

	Author : Yanujz

	Created in : 01/09/2020

    Copyright (C) 2020  Yanujz

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

	You may contact the author by:
		e-mail: yanujz@live.it
*/
#pragma once


//-------- Casting types --------//
#ifndef toU8
#ifdef __cplusplus
#define toU8(x) (static_cast<uint8_t> (x))
#else
#define toU8(x) ((uint8_t)(x))
#endif
#endif

#ifndef toU16
#ifdef __cplusplus
#define toU16(x) (static_cast<uint16_t> (x))
#else
#define toU16(x) ((uint16_t)(x))
#endif
#endif

#ifndef toU32
#ifdef __cplusplus
#define toU32(x) (static_cast<uint32_t>(x))
#else
#define toU32(x) ((uint32_t)(x))
#endif
#endif

#ifndef toU64
#ifdef __cplusplus
#define toU64(x) (static_cast<uint64_t>(x))
#else
#define toU64(x) ((uint64_t)(x))
#endif
#endif

#ifndef toChar
#ifdef __cplusplus
#define toChar(x) (static_cast<char>(x))
#else
#define toChar(x) ((char)(x))
#endif
#endif

#ifndef toUChar
#ifdef __cplusplus
#define toUChar(x) (static_cast<uchar>(x))
#else
#define toUChar(x) ((uchar)(x))
#endif
#endif

#ifndef toUInt
#ifdef __cplusplus
#define toUInt(x) (static_cast<uint>(x))
#else
#define toUInt(x) ((uint)(x))
#endif
#endif

#ifndef toShort
#ifdef __cplusplus
#define toShort(x) (static_cast<short>(x))
#else
#define toShort(x) ((short)(x))
#endif
#endif

#ifndef toInt
#ifdef __cplusplus
#define toInt(x) (static_cast<int>(x))
#else
#define toInt(x) ((int)(x))
#endif
#endif

#ifndef toFloat
#ifdef __cplusplus
#define toFloat(x) (static_cast<float>(x))
#else
#define toFloat(x) ((float)(x))
#endif
#endif

#ifndef toDouble
#ifdef __cplusplus
#define toDouble(x) (static_cast<double>(x))
#else
#define toDouble(x) ((double)(x))
#endif
#endif

