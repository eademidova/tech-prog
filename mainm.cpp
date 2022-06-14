#include <iostream>
#include <string>
#include "matrix.h"

using namespace std;


int main(){
	int n;
	int count=0;
	Matrix *mx_arr;
	
bool flag =false;
	while(!flag)
	{
    cout<< "\nВведите 0, если хотите завершить программу" <<"\nВведите 1, если хотите создать матрицу"<<"\nВведите 2, если хотите сложить матрицы"<<"\nВведите 3, если хотите вычесть матрицы"<<"\nВведите 4, если хотите присвоить матрице другие значения(переназначить)"<<"\nВведите 5, чтобы произвести операцию унарный минус\n"<< "\nВведите 6, чтобы перемножить две матрицы\n"<< "\nВведите 7, чтобы умножить матрицу на число\n"<< "\nВведите 8, чтобы умножить матрицу на вектор\n"<< "\nВведите 9, чтобы вывести конкретную матрицу\n"<<"\nВведите 10, чтобы вывести все матрицы\n";
	cin >> n;
	cout << "\n";
	
	switch(n)
	{
	case 0:
	flag =true;
	break;
	
	case 1:
	{
	
	cout<< "Введите количество строк матрицы\n";
	int n;
	cin >> n;
    	cout<< "Введите количество столбцов матрицы\n";
    	int m;
	cin >> m;
	Matrix mx(n,m);
	cout<<"Введите значения матрицы построчно\n";
	mx.scan();
	
	count++;
	Matrix *tmp = new Matrix[count];
	tmp[count-1] = mx;
    	for (int i = 0; i < count-1; i++) {
        	tmp[i] = mx_arr[i];
    	}

    	mx_arr = tmp;
	
	
	break;
	}
	
	case 2:
	{
	int ind1,ind2;
	cout << "Введите номер первой матрцы\n";
	cin >> ind1;
	cout << "Введите номер второй матрицы\n";
	cin >> ind2;
	if(ind1>count || ind2>count){
	cout << "Нет матриц с такими индексами\n";
	}
	else
	{
	Matrix res = mx_arr[ind1-1]+mx_arr[ind2-1];
	cout << "Сумма равна:\n";
	res.print();
	}
	break;
	}
	
	case 3:
	{
	int ind1,ind2;
	cout << "Введите номер первой матрицы\n";
	cin >> ind1;
	cout << "Введите номер второй матрицы\n";
	cin >> ind2;
	if(ind1>count || ind2>count){
	cout << "Нет матриц с такими индексами\n";
	}
	else
	{
	Matrix res = mx_arr[ind1-1]-mx_arr[ind2-1];
	cout << "Разность равна:\n";
	res.print();
	}
	break;
	}
	

	case 4:
	{
	int index;
	cout << "Введите порядковый номер матрицы, который хотите переназначить\n";
	cin >> index;
	if(index>count){
	cout << "Нет матрицы с таким индексом\n";
	}
	else
	{
	cout<< "Введите количество строк матрицы\n";
	int n;
	cin >> n;
    	cout<< "Введите количество столбцов матрицы\n";
    	int m;
	cin >> m;
	Matrix mx(n,m);
	cout<<"Введите значения матрицы построчно\n";
	mx.scan();
	mx_arr[index-1] = mx;
	}
	break;
	}
	
	case 5:
	{
	int index;
	cout << "Введите порядковый номер матрицы\n";
	cin >> index;
	if(index>count){
	cout << "Нет матрицы с таким индексом\n";
	}
	else{
	mx_arr[index-1] = -mx_arr[index-1];
	}
	break;
	}
	
	case 6:
	 {
	int ind1,ind2;
	cout << "Введите номер первой матрицы\n";
	cin >> ind1;
	cout << "Введите номер второй матрицы\n";
	cin >> ind2;
	if(ind1>count || ind2>count){
	cout << "Нет матриц с такими индексами\n";
	}
	 else{
	 cout << "Произведение равно:\n";
	 (mx_arr[ind1-1]*mx_arr[ind2-1]).print();
	 }
	 break;
	 }
	 
	 case 7:
	 {
	int ind, num;
	cout << "Введите номер матрицы\n";
	cin >> ind;
	cout << "Введите число, на которое хотите умножить матрицу\n";
	cin >> num;
	if(ind>count){
	cout << "Нет матрицы с таким индексом\n";
	}
	 else{
	 cout << "Произведение равно:\n";
	 (mx_arr[ind-1]*num ).print();
	 }
	 break;
	 }

	 
	 case 8:
	 {
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
	if(ind>count){
	cout << "Нет матрицы с таким индексом\n";
	}
	 else{
	 cout << "Произведение равно:\n";
	 (mx_arr[ind-1]*vect).print();
	 
	 }
	 break;
	 }
	
	case 9:
	{
	if(count == 0){
	cout << "Нет матриц\n";
	}
	else
	{
	int index;
	cout << "Введите порядковый номер матрицы\n";
	cin >> index;	
	mx_arr[index-1].print();
	}
	break;
	}
	
	case 10:
	{
	int num = 1;
	if(count == 0){
	cout << "Нет матриц\n";
	}
	else{
	for(int i = 0; i < count;i++){
		cout << num << endl;
		mx_arr[i].print();
		num++;
	}
	}
	break;
	}	
	}
	}
	
	return 0;
}

