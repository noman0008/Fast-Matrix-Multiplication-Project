
#include "Product.h"
#include "Matrix.h"
#include <cstring>


void matrixAdd(Matrix &A1, Matrix &B1, Matrix &C1)
{
	
	int *a = A1.getData();
	int *b = B1.getData();
	int *c = C1.getData();
	
	for (int i = 0; i < A1.n; ++i){
	for (int j = 0; j < A1.m; ++j) {
		
		*c = *a + *b;
		c++;
		a++;
		b++;

	}
	} 
}

void matrixSub(Matrix &A1, Matrix &B1, Matrix &C1)
{
	
	int *a = A1.getData();
	int *b = B1.getData();
	int *c = C1.getData();
	for (int i = 0; i < A1.n; ++i){
		for (int j = 0; j < A1.m; ++j) {
			
			*c = *a - *b;
			c++;
			a++;
			b++;
		}
	}

}

void matrixMult(Matrix &A1, Matrix &B1, Matrix &C1)
{
	
	int *a = A1.getData();
	int *b = B1.getData();
	int *c = C1.getData();
	for (int i = 0; i < A1.n; ++i)
	{
		
		for (int j = 0; j < B1.m; ++j)
		{
			*c = 0;
			
			for (int k = 0; k < A1.m; k++)
			{
				
				*c += *a**b;
				
				a++;
				b += B1.m;
			}
			
			
			b = B1.getData() + j+1;
			
			++c;
			a = A1.getData()+i*A1.m;
		}

		
		a=A1.getData()+(i+1)*A1.m;
		
		
		b = B1.getData();
	}

}



void Product_basic(int *A, int Am, int An, int *B, int Bn, int *C) {

	for (int i = 0; i < Am; i++)
	{
		for (int k = 0; k < Bn; k++)
		{
			*(C + (i * Bn + k)) = 0;
			for (int j = 0; j < An; j++)
			{
				*(C + (i * Bn + k)) += *(A + (i * An + j))**(B + (j * Bn + k));
			}
		}
	}
}

void recur_mat(unsigned int n, Matrix &mat1, Matrix &mat2, Matrix &result)
{
	int i, j, k;
	unsigned int t;


	//base case
	if (n <= 256){
		{

			matrixMult(mat1, mat2, result);

		}

	}
	//recursive step

	else {

		if (n % 2 == 0)
		{
			t = n / 2;
		}

		else
		{
			t = (n + 1) / 2;
		}
		//creating submatrices A and B

		unsigned int x = ((n % 2) == 0 ? n : n + 1);
		Matrix a11(t, t), a12(t, t), a21(t, t), a22(t, t), b11(t, t), b12(t, t), b21(t, t), b22(t, t), m1(t, t), m2(t, t), m3(t, t), m4(t, t), m5(t, t), m6(t, t), m7(t, t), w(x, x), p1(t, t), p2(t, t);

		//dynamic padding

		if (n % 2 == 0){
			matrixCopy(mat1, a11, 0, 0);
			matrixCopy(mat1, a12, 0, mat1.m / 2);
			matrixCopy(mat1, a21, mat1.n / 2, 0);
			matrixCopy(mat1, a22, mat1.n / 2, mat1.m / 2);

			matrixCopy(mat2, b11, 0, 0);
			matrixCopy(mat2, b12, 0, mat2.m / 2);
			matrixCopy(mat2, b21, mat2.n / 2, 0);
			matrixCopy(mat2, b22, mat2.n / 2, mat2.m / 2);
		}

		else
		{
			Matrix temp1(n + 1, n + 1);
			Matrix temp2(n + 1, n + 1);

			
			for (unsigned int i = 0; i < n + 1; i++){
				for (unsigned int j = 0; j < n + 1; j++){
					if (i<n && j<n){
						temp1.index(i, j) = *(mat1.getData() + (i * n + j));

						temp2.index(i, j) = *(mat2.getData() + (i * n + j));
					}
					if (j>n - 1 || i > n - 1){
						
						temp1.index(i, j) = 0;

						temp2.index(i, j) = 0;
					}
				}
			}



			matrixCopy(temp1, a11, 0, 0);
			matrixCopy(temp1, a12, 0, temp1.m / 2);
			matrixCopy(temp1, a21, temp1.n / 2, 0);
			matrixCopy(temp1, a22, temp1.n / 2, temp1.m / 2);

			matrixCopy(temp2, b11, 0, 0);
			matrixCopy(temp2, b12, 0, temp2.m / 2);
			matrixCopy(temp2, b21, temp2.n / 2, 0);
			matrixCopy(temp2, b22, temp2.n / 2, temp2.m / 2);

		}



		//precalculation
		

		matrixAdd(a11, a22, p1);
		matrixAdd(b11, b22, p2);
		recur_mat(t, p1, p2, m1);
		

		matrixAdd(a21, a22, p1);
		recur_mat(t, p1, b11, m2);
		

		matrixSub(b12, b22, p1);
		recur_mat(t, a11, p1, m3);
		

		matrixSub(b21, b11, p1);
		recur_mat(t, a22, p1, m4);
		

		matrixAdd(a11, a12, p1);
		recur_mat(t, p1, b22, m5);
		
		matrixSub(a21, a11, p1);
		matrixAdd(b11, b12, p2);
		recur_mat(t, p1, p2, m6);
		

		matrixSub(a12, a22, p1);
		matrixAdd(b21, b22, p2);
		recur_mat(t, p1, p2, m7);
		

		matrixAdd(m1, m4, p1);
		matrixSub(p1, m5, p2);

		matrixAdd(p2, m7, p2);

		int *ptr1 = p2.getData();
		int *ptr2 = w.getData();
		for (i = 0; i < t; i++){
			for (j = 0; j < t; j++){
				
				*ptr2 = *ptr1;
				ptr2++;
				ptr1++;
			}
			ptr2 = w.getData() + (i + 1)*w.m;
		}

		
		matrixAdd(m3, m5, p1);

		int *ptr3 = p1.getData();
		int *ptr4 = w.getData();
		ptr4 = ptr4 + t;
		for (i = 0; i < t; i++){
			for (j = 0; j < t; j++){
				

				*ptr4 = *ptr3;
				ptr4++;
				ptr3++;
			}
			ptr4 = w.getData() + t + (i + 1)*w.m;
		}

		matrixAdd(m2, m4, p1);

		

		for (i = 0; i < t; i++){
			for (j = 0; j < t; j++){
				w.index(i + t, j) = p1.get(i, j);
				
			}
			
		}

		matrixAdd(m1, m3, p1);
		matrixSub(p1, m2, p2);
		matrixAdd(p2, m6, p2);

		
		for (i = 0; i < t; i++){
			for (j = 0; j < t; j++){
				w.index(i + t, j + t) = p2.get(i, j);
				

			}
			
		}
		matrixCopy(w, result, 0, 0);

	}
}


void Strassen(int *A, unsigned int Am, unsigned int An, int *B, unsigned int Bn, int *C)
{

	int max = (Am>An ? Am : An) > Bn ? (Am > An ? Am : An) : Bn;

	int num = ceil(log(max) / log(2));

	unsigned int pad = pow(2, num);


	Matrix a(max, max);
	Matrix b(max, max);
	Matrix c(max, max);

	//padding with extra zeroes to make it square matrice of size 2^k
	int *p1 = a.getData();
	int *p2 = b.getData();
	for (unsigned int i = 0; i < max; i++){
		for (unsigned int j = 0; j < max; j++){
			if (i<Am && j<An)
				
				*p1 = *(A + (i * An + j));
			if (i<An && j<Bn)
				
				*p2 = *(B + (i * Bn + j));
			if (j>An - 1 || i>Am - 1)
				
				*p1 = 0;
			if (j>Bn - 1 || i>An - 1)
				*p2 = 0;

			p1++;
			p2++;
		}
		
	}


	recur_mat(max, a, b, c);

	int *ptr = c.getData();
	for (unsigned int i = 0; i < Am; i++){
	for (unsigned int j = 0; j < Bn; j++){
		
		*C = *ptr;
		C++;
		ptr++;
	}
	ptr = c.getData() + (i+1)*c.m;
	}

}

void Product(int *A, int Am, int An, int *B, int Bn, int *C) {

	//decide which function to call and when
	if ((An < 100) && (Bn < 100) && (Am < 100))
		Product_basic(A, Am, An, B, Bn, C);

	else if ((Am == An) && (An == Bn) && (Am >= 100))
		Strassen(A, Am, An, B, Bn, C);
	else if (Am >= 1000 && Bn <= 100 && An <= 100)
		Product_basic(A, Am, An, B, Bn, C);
	else if (An >= 1000 && Bn <= 100 && Am <= 100)
		Product_basic(A, Am, An, B, Bn, C);
	else if (Bn >= 1000 && Am <= 100 && An <= 100)
		Product_basic(A, Am, An, B, Bn, C);
	else
	{
		if (An >= 1000 && Bn >= 1000 && Am <= 100)
			Product_basic(A, Am, An, B, Bn, C);

		else if (Am >= 1000 && Bn >= 1000 && An <= 100)
			Product_basic(A, Am, An, B, Bn, C);

		else if (Am >= 1000 && An >= 1000 && Bn <= 100)
			Product_basic(A, Am, An, B, Bn, C);

		else
			Strassen(A, Am, An, B, Bn, C);
	}

}
