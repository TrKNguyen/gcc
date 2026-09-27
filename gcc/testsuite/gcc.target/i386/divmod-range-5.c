/* Regression test: dividend with no narrower range must preserve baseline
   codegen.  */
/* { dg-do compile { target { ! ia32 } } } */
/* { dg-options "-O2 -march=x86-64 -mtune=generic -masm=att" } */

unsigned int
foo (unsigned int a)
{
  return a / 10;
}

/* { dg-final { scan-assembler {\$3435973837} } } */
/* { dg-final { scan-assembler {\tshrq\t\$35,} } } */
