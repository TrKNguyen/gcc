/* Verify that VRP-derived range info shifts signed /7 from LONG to SHORT codegen.  */
/* { dg-do compile { target { ! ia32 } } } */
/* { dg-options "-O2 -march=x86-64 -mtune=generic -masm=att" } */

int
foo (int a)
{
  if (a > 1000000 || a < -1000000) __builtin_unreachable ();
  return a / 7;
}

/* { dg-final { scan-assembler {\timulq\t\$613567341,} } } */
/* { dg-final { scan-assembler-not {\$-1840700269} } } */
/* { dg-final { scan-assembler-not {\taddl\t%edi, %eax} } } */
