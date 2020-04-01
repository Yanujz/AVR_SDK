#include "math_utils.h"

int divide(signed int a1, signed int a2)
{
  signed int sign_a1;
  signed int sign_a2;
  int result;
  sign_a1 = 0;
  sign_a2 = 0;
  if ( a1 < 0 )
  {
    sign_a1 = 1;
    a1 = -a1;
  }
  if ( a2 < 0 )
  {
    sign_a2 = 1;
    a2 = -a2;
  }
  result = positive_divide(a1, a2);
  if ( sign_a1 != sign_a2 )
    result = -result;
  return result;
}

int positive_divide(unsigned int a1, unsigned int a2)
{
  int result;
  signed int i;
  signed int v6;
  result = 0;
  i = 32;
  while ( 1 )
  {
    v6 = i--;
    if ( v6 <= 0 )
      break;
    if ( a1 >> i >= a2 )
    {
      a1 -= a2 << i;
      result += 1 << i;
    }
  }
  return result;
}
