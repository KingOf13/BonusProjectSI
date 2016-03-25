/*
Systemes Informatique LSINF1252
Test unitaires pour les fonctions de poly
AIGRET Julien   8343-13-00
VANVYVE Nicolas 6590-13-00

MARS 2016
*/

#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "student_code.h"

// Variables de test utilisées à travers le code
poly *test1,test2, test3, terst4;
double coeff1[]={10.0, 9.0, 8.0, 7.0, 6.0, 5.0, 4.0, 3.0, 2.0, 1.0};
double coeff2[]={17.59, 13.87, 7.5631, 4.2, 3.55, 12.13, -32.12, 6.87, 22.0, 0.001};
double coeff3[]={1.0, 1.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
double coeff4[]={0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

double tol = 0.01; // Tolerance entre le resultat exact et le resultat renvoye




poly *newpoly(double a[10]) {
  poly *ret = (poly *) malloc(sizeof(poly));
  if (ret == NULL) exit(EXIT_FAILURE);
  for (int i = 0; i < 10; i++) {
    ret->coeff[i] = a[i];
  }
  return ret;
}


/* Test si alloc passe bien à 0 apres myfree */
void test_myfree_desalloc(void)
{
  int* pointeurtest = (int *) mymalloc(sizeof(int));
  block_header *bh_test = (block_header *)(pointeurtest-1);
  myfree(pointeurtest);
  CU_ASSERT_EQUAL((bh_test->alloc),0);
}

/* Test si alloc passe bien à 1 apres mymalloc*/
void test_mymalloc_alloc(void)
{
  int* pointeurtest = (int *) mymalloc(sizeof(int));
  block_header *bh_test = (block_header *) (pointeurtest-4);
  CU_ASSERT_EQUAL(((*bh_test).alloc),1);
}

/* Test si alloc passe bien à 1 apres mycalloc*/
void test_mycalloc_alloc(void)
{
  int* pointeurtest = (int *) mycalloc(sizeof(int));
  block_header *bh_test = (block_header *) (pointeurtest-4);
  CU_ASSERT_EQUAL(((*bh_test).alloc),1);
}

/* Test si la taille demandée et la taille allouée et la meme (ajustée pour etre un multiple de 4)*/
void test_mymalloc_size(void)
{
  size_t ask = (sizeof(int)+3);
  int* pointeurtest = (int *) mymalloc(ask);
  block_header *bh_test = (block_header *) (pointeurtest-4);
  CU_ASSERT_EQUAL(((*bh_test).size),size4(ask));
}

/* Test si deux appel a mymalloc ne revoie pas la meme adresse */
void test_mymalloc_two_alloc(void)
{
  int* pointeurtest = NULL;
  int* pointeurtest2 = NULL;
  pointeurtest = (int *) mymalloc(sizeof(int));
  pointeurtest2 = (int *) mymalloc(sizeof(int));
  CU_ASSERT_NOT_EQUAL(pointeurtest,pointeurtest2);
}

/* Test si quand on demande d'allouer 0 bit mymalloc renvoie bien NULL */
void test_mymalloc_NULL(void)
{
  void* pointeurtest = mymalloc(0);
  CU_ASSERT_EQUAL(pointeurtest,NULL);
}

/* Test si apres mycalloc la valeur est bien 0 */
void test_mycalloc_init(void)
{
  int* pointeurtest = NULL;
  size_t size = 100*sizeof(int);
  pointeurtest = mycalloc(size);
  int i =0;
  while (i < size)
  {
    if (*(pointeurtest+i) == 0)
    {
      i++;
    }
    else
    {
      CU_FAIL();
    }
    CU_PASS();
  }
}


int setup(void)  { return 0; }
int teardown(void) { return 0; }

int main()
{
   CU_pSuite pSuite = NULL;
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   pSuite = CU_add_suite("Projet-Malloc", setup, teardown);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   if ((NULL == CU_add_test(pSuite, "Myfree desalloc",test_myfree_desalloc)) ||
       (NULL == CU_add_test(pSuite, "Mymalloc alloc",test_mymalloc_alloc)) ||
       (NULL == CU_add_test(pSuite, "Mycalloc alloc",test_mycalloc_alloc)) ||
       (NULL == CU_add_test(pSuite, "Mymalloc size",test_mymalloc_size)) ||
       (NULL == CU_add_test(pSuite, "Mymalloc NULL",test_mymalloc_NULL)) ||
       (NULL == CU_add_test(pSuite, "Mymalloc 2 alloc",test_mymalloc_two_alloc)) ||
       (NULL == CU_add_test(pSuite, "Mycalloc initialisation",test_mycalloc_init))
     )
   {
     CU_cleanup_registry();
     return CU_get_error();
   }

   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   printf("\n");
   CU_basic_show_failures(CU_get_failure_list());
   printf("\n\n");

   CU_cleanup_registry();
   return CU_get_error();
}
