/* Verify that VRP-derived range info reduces the signed-divide-by-10 multiplier.  */
/* { dg-do compile { target { ! ia32 } } } */
/* { dg-options "-O2 -march=x86-64 -mtune=generic -masm=att" } */

int
foo (int a)
{
  if (a > 1000000 || a < -1000000) __builtin_unreachable ();
  return a / 10;
}

/* { dg-final { scan-assembler {\timulq\t\$429497139,} } } */
/* { dg-final { scan-assembler-not {\$1717986919} } } */
/* { dg-final { scan-assembler-not {\tsarq\t\$34,} } } */
