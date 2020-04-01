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

#define IS_REPRESENTIBLE_IN_D_BITS(D, N)                \
    (((unsigned long) N >= (1UL << (D - 1)) && (unsigned long) N < (1UL << D)) ? D : -1)

#define BITS_TO_REPRESENT(N)                            \
    (N == 0 ? 1 : (31                                     \
    + IS_REPRESENTIBLE_IN_D_BITS( 1, N)    \
    + IS_REPRESENTIBLE_IN_D_BITS( 2, N)    \
    + IS_REPRESENTIBLE_IN_D_BITS( 3, N)    \
    + IS_REPRESENTIBLE_IN_D_BITS( 4, N)    \
    + IS_REPRESENTIBLE_IN_D_BITS( 5, N)    \
    + IS_REPRESENTIBLE_IN_D_BITS( 6, N)    \
    + IS_REPRESENTIBLE_IN_D_BITS( 7, N)    \
    + IS_REPRESENTIBLE_IN_D_BITS( 8, N)    \
    + IS_REPRESENTIBLE_IN_D_BITS( 9, N)    \
    + IS_REPRESENTIBLE_IN_D_BITS(10, N)    \
    + IS_REPRESENTIBLE_IN_D_BITS(11, N)    \
    + IS_REPRESENTIBLE_IN_D_BITS(12, N)    \
    + IS_REPRESENTIBLE_IN_D_BITS(13, N)    \
    + IS_REPRESENTIBLE_IN_D_BITS(14, N)    \
    + IS_REPRESENTIBLE_IN_D_BITS(15, N)    \
    + IS_REPRESENTIBLE_IN_D_BITS(16, N)    \
    + IS_REPRESENTIBLE_IN_D_BITS(17, N)    \
    + IS_REPRESENTIBLE_IN_D_BITS(18, N)    \
    + IS_REPRESENTIBLE_IN_D_BITS(19, N)    \
    + IS_REPRESENTIBLE_IN_D_BITS(20, N)    \
    + IS_REPRESENTIBLE_IN_D_BITS(21, N)    \
    + IS_REPRESENTIBLE_IN_D_BITS(22, N)    \
    + IS_REPRESENTIBLE_IN_D_BITS(23, N)    \
    + IS_REPRESENTIBLE_IN_D_BITS(24, N)    \
    + IS_REPRESENTIBLE_IN_D_BITS(25, N)    \
    + IS_REPRESENTIBLE_IN_D_BITS(26, N)    \
    + IS_REPRESENTIBLE_IN_D_BITS(27, N)    \
    + IS_REPRESENTIBLE_IN_D_BITS(28, N)    \
    + IS_REPRESENTIBLE_IN_D_BITS(29, N)    \
    + IS_REPRESENTIBLE_IN_D_BITS(30, N)    \
    + IS_REPRESENTIBLE_IN_D_BITS(31, N)    \
    + IS_REPRESENTIBLE_IN_D_BITS(32, N)    \
    )                                      \
    )

#define IS_BIT_PART_OF_NUMBER(B, N) \
    ((unsigned long) (1UL << B) < N ? (1UL << B) : 0)

#define MASK_FROM_VAL(N) \
    (N == 0 ? 0 : (0UL              \
    | IS_BIT_PART_OF_NUMBER( 0, N)  \
    | IS_BIT_PART_OF_NUMBER( 1, N)  \
    | IS_BIT_PART_OF_NUMBER( 2, N)  \
    | IS_BIT_PART_OF_NUMBER( 3, N)  \
    | IS_BIT_PART_OF_NUMBER( 4, N)  \
    | IS_BIT_PART_OF_NUMBER( 5, N)  \
    | IS_BIT_PART_OF_NUMBER( 6, N)  \
    | IS_BIT_PART_OF_NUMBER( 7, N)  \
    | IS_BIT_PART_OF_NUMBER( 8, N)  \
    | IS_BIT_PART_OF_NUMBER( 9, N)  \
    | IS_BIT_PART_OF_NUMBER(10, N)  \
    | IS_BIT_PART_OF_NUMBER(11, N)  \
    | IS_BIT_PART_OF_NUMBER(12, N)  \
    | IS_BIT_PART_OF_NUMBER(13, N)  \
    | IS_BIT_PART_OF_NUMBER(14, N)  \
    | IS_BIT_PART_OF_NUMBER(15, N)  \
    | IS_BIT_PART_OF_NUMBER(16, N)  \
    | IS_BIT_PART_OF_NUMBER(17, N)  \
    | IS_BIT_PART_OF_NUMBER(18, N)  \
    | IS_BIT_PART_OF_NUMBER(19, N)  \
    | IS_BIT_PART_OF_NUMBER(20, N)  \
    | IS_BIT_PART_OF_NUMBER(21, N)  \
    | IS_BIT_PART_OF_NUMBER(22, N)  \
    | IS_BIT_PART_OF_NUMBER(23, N)  \
    | IS_BIT_PART_OF_NUMBER(24, N)  \
    | IS_BIT_PART_OF_NUMBER(25, N)  \
    | IS_BIT_PART_OF_NUMBER(26, N)  \
    | IS_BIT_PART_OF_NUMBER(27, N)  \
    | IS_BIT_PART_OF_NUMBER(28, N)  \
    | IS_BIT_PART_OF_NUMBER(29, N)  \
    | IS_BIT_PART_OF_NUMBER(30, N)  \
    | IS_BIT_PART_OF_NUMBER(31, N)  \
    )                               \
    )

#define IS_POWER_OF_TWO(x) (x > 0 && (x & (x - 1)) == 0)
