#ifndef __PRODUCT_H__
#define __PRODUCT_H__


/*
  Product of two matrices 
  + Product_basic(...) should implement Algorithm 1.9 of our textbook
  + Product(...) should make use of Algorithm 1.9 and 5.3 to maximize speed

  @input
  A: pointer of int, the starting address of an Am * An matrix
  B: pointer of int, the starting address of an An * Bn matrix
  C: pointer of int, the starting address of an Am * Bn matrix
  
  @output 
  void. the matrix C keeps the result of the product AB

  @other info
  - Each entry of A or B is an integer with value between -16 and +16

  @hints
  - Take A as an example, (A + i * An  + j) will be the address of A[i][j]
*/


void Product_basic(int *A, int Am, int An, int *B, int Bn,  int *C);
void Product(int *A, int Am, int An, int *B, int Bn,  int *C);




#endif












