#include "Matrix.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;


int main(int argc, char* argv[]) {
  int Am, An, Bn;
  Am = atoi(argv[1]);
  An = atoi(argv[2]);
  Bn = atoi(argv[3]);
  Matrix A(Am, An);
  Matrix B(An, Bn);
  A.randomInit();
  B.randomInit();
  
  Matrix C(A * B);

  cout << Am << " " << An << " " << Bn << "\n\n";
  A.printMatrix();
  cout << "\n\n";
  B.printMatrix();
  cout << "\n\n";
  C.printMatrix();
  return 0;
}
