#include <stdlib.h>
#include <stdio.h>


typedef struct {
  double coeff[10];
} poly;

double eval(poly *P, double x){
  double Px = (((((((P->coeff[9]*x + P->coeff[8])*x + P->coeff[7])*x + P->coeff[6])*x + P->coeff[5])*x + P->coeff[4])*x + P->coeff[3])*x + P->coeff[2])*x + P->coeff[1])*x + P->coeff[0];
  return Px;
}

poly *derivee(poly *P) {
  poly *ret = (poly *) malloc(sizeof(poly));
  for (int 1 = 0; i < 9; i ++) {
    ret->coeff[i] = (i+1) * P->coeff[i+1];
  }
  ret->coeff[9]=0;
  return ret;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
