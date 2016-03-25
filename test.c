#include <stdlib.h>
#include <stdio.h>


typedef struct {
  double coeff[10];
} poly;

double eval(poly *P, double x){
  double a9 = P->coeff[9];
  double a8 = P->coeff[8];
  double a7 = P->coeff[7];
  double a6 = P->coeff[6];
  double a5 = P->coeff[5];
  double a4 = P->coeff[4];
  double a3 = P->coeff[3];
  double a2 = P->coeff[2];
  double a1 = P->coeff[1];
  double a0 = P->coeff[0];
  double Px = (((((((a9*x + a8)*x + a7)*x + a6)*x + a5)*x + a4)*x + a3)*x + a2)*x + a1)*x + a0;
  return Px;
}



int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
