#include <iostream>
#include <string>
#include "stdio.h"
#include "vect.h"

using namespace std;

class Matrix
{
public:
	
	friend class Vector;
	static int count; //счетчик матриц
	Matrix& operator = (const Matrix &r);
	Matrix operator + (Matrix &r);
	Matrix operator - (Matrix &r);
	Matrix operator - ();
	Matrix operator * (int k);
	Matrix operator * (Matrix &r);
	Matrix operator * (Vector &r);
	

	//диструктор
	
    	~Matrix() {
		delete[] matrix;
	}
	
	//конструктор
	
	Matrix(int N=1, int M=1)
	   {
	      n = N;
	      m = M;
	      matrix = new int *[n];
	      
	      for (int i = 0; i < n; ++ i)
	      {
		 matrix[i] = new int[m];
		 for (int j = 0; j < m; ++ j)
		    matrix[i][j] = 0;
	      }
	      
	      
	   }
	   
	   // оператор для обращения к элементами матрицы по индексу
	   int* operator [] (int index)
	   {
	      return getRow (index);
	   }
	   // строка матрицы
	   int* getRow (int index)
	   {
	      if (index >= 0 && index < n)
		 return matrix[index];
	      return 0;
	   }


	// функция для считывания матрицы с консоли  	
   	void scan()
	{
   	//int n, m;
   	//scanf ("%d%d", & n, & m);
   	Matrix matrix = Matrix (this->n, this->m);
   	for (int i = 0; i < n; ++ i){
     		for (int j = 0; j < m; ++ j){
        		cin >> this->matrix[i][j];
        	}
        }
   	
	}

	// функция для печати матрицы
	
	void print()
	{
   	for (int i = 0; i < this->n; ++ i)
   	{
      	for (int j = 0; j < this->m; ++ j){
        	cout << this->matrix[i][j]<< " ";
        	}
        	cout << endl;

  	}
  	
	}





private:

	int m, n; //количество строк и столбцов соотвественно
	int **matrix;
	
};




Matrix &Matrix::operator=(const Matrix& r) // оператор присваивания
      {  
        if (this != &r) 
        { 
           for ( int i = 0; i < this->n; i++ )
            {
                delete []matrix[i];
            }
            delete []matrix;
            this->n = r.n;
            this->m = r.m;

            matrix = new int*[n];
            for ( int i = 0; i < this->n; i++ )
            {
                matrix[i] = new int[this->m];
            }
            for (int i= 0; i < r.n; ++i) {
            for (int j = 0; j < r.m; ++j) {
               matrix[i][j] = r.matrix[i][j]; 
            }
            }
        }
   
       return *this;
       
       }
       
       


Matrix Matrix::operator + (Matrix &r)
{  
   if (r.n != this->n || r.m != this->m){
      cout<< "Разные размеры матриц";
      exit(1);
   }
   Matrix res = Matrix (r.n, r.m);
   for (int i = 0; i < r.n; ++ i){
      for (int j = 0; j < r.m; ++ j){
         res[i][j] = r.matrix[i][j] + this->matrix[i][j];
         }
   
   }
   return res;
}

Matrix Matrix::operator - (Matrix &r)
{  
   if (r.n != this->n || r.m != this->m){
      cout<< "Разные размеры матриц";
      exit(1);
   }
   Matrix res = Matrix (r.n, r.m);
   for (int i = 0; i < r.n; ++ i){
      for (int j = 0; j < r.m; ++ j){
         res[i][j] = this->matrix[i][j] - r.matrix[i][j];
   }
   }
   return res;
}

Matrix Matrix::operator - ()
{ Matrix res = Matrix (this->n, this->m);
  for(int i = 0; i < this->n; i++){
  	for(int j = 0; j < this->m; j++){
    		res.matrix[i][j] = -(this->matrix[i][j]);
  }
  }
  return res;
}



Matrix Matrix::operator * (int k){
	Matrix res = Matrix (this->n, this->m);
	for (int i = 0; i < this->n; ++i){
     	 	for (int j = 0; j < this->m; ++j){
         		res[i][j] = this->matrix[i][j] * k;
		}
	}
	return res;
}

Matrix Matrix::operator * (Matrix &r){
	if (this->m != r.n){
	     exit(1);
	}
	Matrix res = Matrix (this->n, r.m);
	for (int i = 0; i < this->n; ++ i){
	    for (int j = 0; j < r.m; ++ j){
			for (int k = 0; k < this->m; ++ k){
		    res[i][j] += this->matrix[i][k] * r.matrix[k][j];
			}
		}
	}
	   return res;

}


Matrix Matrix::operator * (Vector &r){
	Matrix res = Matrix(this->n, 1);
	if(r.n!=this->m){
	cout << "Невозможно перемножить";
	    exit(1);
	}
	else{
	for (int i = 0; i < this->n; ++ i){
		for (int j = 0; j < this->m; ++ j){
		    	res[i][0] += this->matrix[i][j] * r.arr[j];
			}
		}
	}
	return res;
	
}

























