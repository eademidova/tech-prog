#include <iostream>
#include <string>
#include "matrix.h"

using namespace std;


int main(){

	Matrix m1(3, 4);
	Vector v1;
	v1.push(1);
	v1.push(1);
	v1.push(1);
	v1.push(1);

	m1.scan();


	int ind;
	Vector vect;
	cout << "Введите номер матрицы\n";
	cin >> ind;
	int len;
    	cout<< "Какой длины будет вектор?\n";
	cin >> len;
	int* vec = new int[len];
	cout << "Введите вектор\n";
	for(int i=0; i<len;i++){
		cin >> vec[i];
		vect.push(vec[i]);
	}

	 cout << "Произведение равно:\n";
	 (m1*vect).print();
	 

	
	return 0;
}


	
