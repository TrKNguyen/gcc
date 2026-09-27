/* Regression test: dividend with no narrower range must preserve LONG-path
   codegen.  */
/* { dg-do compile { target { ! ia32 } } } */
/* { dg-options "-O2 -march=x86-64 -mtune=generic -masm=att" } */

int
foo (int a)
{
  return a / 7;
}

/* { dg-final { scan-assembler {\$-1840700269} } } */
/* { dg-final { scan-assembler {\taddl\t%edi, %eax} } } */
