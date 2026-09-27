/* Verify that VRP-derived range info reduces the signed FLOOR_DIV multiplier.
   Uses __GIMPLE FE because FLOOR_DIV_EXPR cannot be produced from C source.  */
/* { dg-do compile { target { ! ia32 } } } */
/* { dg-options "-O2 -fgimple -march=x86-64 -mtune=generic -masm=att" } */

int __GIMPLE (ssa)
foo (int a)
{
  int t_2;
  unsigned int au_4;
  unsigned int range_5;

__BB(2):
  au_4 = (unsigned int) a_3(D);
  range_5 = au_4 + 1000000u;
  if (range_5 > 2000000u)
    goto __BB3;
  else
    goto __BB4;

__BB(3):
  __builtin_unreachable ();

__BB(4):
  t_2 = a_3(D) __FLOOR_DIV 7;
  return t_2;
}

/* { dg-final { scan-assembler {\timulq\t\$613567341,} } } */
/* { dg-final { scan-assembler {\tshrq\t\$32,} } } */
/* { dg-final { scan-assembler {\tsarl\t\$31,} } } */
/* { dg-final { scan-assembler-times {\txorl\t} 2 } } */
/* { dg-final { scan-assembler-not {\$2454267027} } } */
/* { dg-final { scan-assembler-not {\tshrq\t\$34,} } } */
