#ifndef __MATRIX__
#define __MATRIX__
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <ctime>

class Matrix {
public:
  // initialize an n by m matrix
  Matrix(int n, int m);
  Matrix(const Matrix &A);
  ~Matrix() {
    delete[] data;
  }
  // get entry at (i, j)
  int get(int i, int j) const { return data[i * m + j]; }
  // return the indexed entry
  int& index(int i, int j) { return data[i * m + j]; }
  void printMatrix(); // print the matrix to stdout
  void randomInit(); // randomly initialize the matrix
  int *getData() { return data; } // return the data block
  int n;
  int m;
private:
  int *data;
};


Matrix::Matrix(int n, int m) {
  srand(time(NULL));
  this-> n = n;
  this-> m = m;
  data = new int[n * m];
}

Matrix::Matrix(const Matrix &A) {
  srand(time(NULL));
  this->n = A.n;
  this->m = A.m;
  this->data = new int[n * m];
  std::memcpy(this->data, A.data, n * m * sizeof(int));
}

void Matrix::printMatrix() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++ j)
      std::cout << std::setw(9) << *(data + i * m + j);
    std::cout << '\n';
  }
  std::cout << '\n';
}

void Matrix::randomInit() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      *(data + i * m + j) = rand() % 33 - 16;
}



// compare two matrices
bool operator==(const Matrix &A, const Matrix &B) {
  if (A.n != B.n || A.m != B.m)
    return false;
  for (int i = 0; i < A.n; ++i)
    for (int j = 0; j < A.m; ++j)
      if (A.get(i, j) != B.get(i, j))
	return false;
  return true;
}


bool operator!=(const Matrix &A, const Matrix &B) {
  return !(A == B);
}


Matrix operator*(const Matrix &A, const Matrix &B) {
  if (A.m != B.n)
    throw "Matrices are not compatible!";
  Matrix C(A.n, B.m);
  for (int i = 0; i < A.n; ++i)
    for (int j = 0; j < B.m; ++j) {
      int sum = 0;
      for (int k = 0; k < A.m; ++k)
	sum += A.get(i, k) * B.get(k, j);
      C.index(i, j) = sum;
    }
  return C;
}

#endif
