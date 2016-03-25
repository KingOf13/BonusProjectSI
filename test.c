#include <stdlib.h>
#include <stdio.h>


typedef struct {
  double coeff[10];
} poly;

double eval(poly *P, double x){
  double a_9 = P->coeff[9] ;
  double a_8 = P->coeff[8] ;
  double a_7 = P->coeff[7] ;
  double a_6 = P->coeff[6] ;
  double a_5 = P->coeff[5] ;
  double a_4 = P->coeff[4] ;
  double a_3 = P->coeff[3] ;
  double a_2 = P->coeff[2] ;
  double a_1 = P->coeff[1] ;
  double a_0 = P->coeff[0] ;
  return ((((((((a_9 * x + a_8) * x + a_7) * x + a_6) * x + a_5) * x + a_4) * x + a_3) * x + a_2) * x + a_1) * x + a_0) ;
}

poly *derivee(poly *P) {
  poly *ret = (poly *) malloc(sizeof(poly));
  for (int i = 0; i < 9; i ++) {
    ret->coeff[i] = (i+1) * P->coeff[i+1];
  }
  ret->coeff[9]=0;
  return ret;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
