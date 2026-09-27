/* Verify that VRP-derived range info reduces the unsigned modulo multiplier.  */
/* { dg-do compile { target { ! ia32 } } } */
/* { dg-options "-O2 -march=x86-64 -mtune=generic -masm=att" } */

unsigned int
foo (unsigned int a)
{
  if (a > 1000000) __builtin_unreachable ();
  return a % 10;
}

/* { dg-final { scan-assembler {\timulq\t\$429497139,} } } */
/* { dg-final { scan-assembler {\tshrq\t\$32,} } } */
/* { dg-final { scan-assembler-not {\$3435973837} } } */
