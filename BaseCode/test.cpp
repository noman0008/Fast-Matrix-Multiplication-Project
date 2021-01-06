#include "Product.h"
#include "Matrix.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <exception>
#include <ctime>
using namespace std;



string runtest(string testfile) {

  // open file, make sure the file exist
  ifstream fin;  
  fin.open(testfile.c_str(), ifstream::in);
  
  if (!fin.is_open()) {
    return testfile + " can not be open!";
  }

  int Am, An, Bn; 


  // read data from test file
  fin >> Am >> An >> Bn;


  Matrix A(Am, An);
  Matrix B(An, Bn);
  Matrix C(Am, Bn);
  Matrix Ans(Am, Bn);
  

  // Read A, B, ans
  
  for (int i = 0; i < Am; ++i)
    for (int j = 0; j < An; ++j)
      fin >> A.index(i, j);
    
  for (int i = 0; i < An; ++i)
    for (int j = 0; j < Bn; ++j) 
      fin >> B.index(i, j);

  for (int i = 0; i < Am; ++i)
    for (int j = 0; j < Bn; ++j)
      fin >> Ans.index(i, j);

  fin.close();
  


  // max # of iterations
  // at least 1
  // calculate the average time among max_iter
  int max_iter = max(100000000 / Am / An / Bn, 1); 

 

  // calculate the running time
  clock_t start;
  double duration;
  start = clock();
  try {
    for (int i = 0; i < max_iter; ++i) {
      Product_basic(A.getData(), A.n, A.m, B.getData(), B.m, C.getData());
    }
  }
  catch (exception& e) {
    return testfile + ": " + string(e.what());
  }
  duration = (clock() - start) / (double) CLOCKS_PER_SEC;


  // check if get the correct answer
  if (C != Ans)
	return testfile + ": Wrong Result!";

  // return running time
  stringstream ss;
  ss << testfile + ": "<< setprecision(8) << duration / max_iter << " secs";
  return ss.str();
}



int main(int argc, char *argv[]) {  
  if (argc < 2) {
    cerr << "Wrong arguments, check your input!" << endl;
  }
  for (int i = 1; i < argc; ++i)
    cout << runtest(argv[i]) << endl;
  return 0;
}










