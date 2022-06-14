#include <iostream>
#include <string>
#include "vect.h"
using namespace std;


int main(){

	int capacity = 1;
	int n;
    Vector *vector_arr;
    int d;
    	
    
    bool flag =false;
	while(!flag)
	{
    cout<< "\nВведите 0, если хотите завершить программу" <<"\nВведите 1, если хотите создать вектор"<<"\nвведите 2, если хотите удлить точку вектора"<<"\nВведите 3, если хотите сложить векторы"<<"\nВведите 4, если хотите вычесть векторы"<<"\nВведите 5, если хотите присвоить вектору другие значения(переназначить)"<<"\nВведите 6, чтобы произвести операцию унарный минус\n"<<"\nВведите 7, чтобы вывести конкретный вектор\n"<<"\nВведите 8, чтобы вывести все векторы\n"<< "\nВведите 9, чтобы скалярно умножить векторы\n";
	cin >> n;
	cout << "\n";
	
	switch(n)
	{
	case 0:
	flag =true;
	break;
	
	case 1:
	{
	Vector vect;
	int len;
    cout<< "Какой длины будет вектор?\n";
	cin >> len;
	int* vec = new int[len];
	cout << "Введите вектор\n";
	for(int i=0; i<len;i++){
		cin >> vec[i];
		vect.push(vec[i]);
	}
	
	vect.count=capacity;
    Vector *tmp = new Vector[capacity];
	tmp[capacity-1] = vect;
    for (int i = 0; i < capacity-1; i++) {
        tmp[i] = vector_arr[i];
    }

    capacity += 1;
    vector_arr = tmp;

	
	break;
	}
	
	
	case 2:
	{
	int num, index;
	cout << "Введите порядковый номер вектора\n";
	cin >> num;
	if(num>=capacity){
	cout << "Нет вектора с таким индексом\n";
	}
	else{
	cout << "Введите индекс точки\n";
	cin >> index;
	vector_arr[num].remove(index);
	}
	break;
	}
	
	case 3:
	{
	int ind1,ind2;
	cout << "Введите номер первого вектора\n";
	cin >> ind1;
	cout << "Введите номер второго вектора\n";
	cin >> ind2;
	if(ind1>=capacity || ind2>=capacity){
	cout << "Нет векторов с такими индексами\n";
	}
	else
	{
	Vector res = vector_arr[ind1-1]+vector_arr[ind2-1];
	cout << "Сумма равна:\n";
	res.print();
	}
	break;
	}
	
	case 4:
	{
	int ind1,ind2;
	cout << "Введите номер первого вектора\n";
	cin >> ind1;
	cout << "Введите номер второго вектора\n";
	cin >> ind2;
	if(ind1>=capacity || ind2>=capacity){
	cout << "Нет векторов с такими индексами\n";
	}
	else
	{
	Vector res = vector_arr[ind1-1]-vector_arr[ind2-1];
	cout << "Разность равна:\n";
	res.print();
	}
	break;
	}
	

	case 5:
	{
	int index;
	cout << "Введите порядковый номер вектора, который хотите переназначить\n";
	cin >> index;
	if(index>=capacity){
	cout << "Нет вектора с таким индексом\n";
	}
	else
	{
	Vector tmp;
	int len;
    cout<< "Какой длины будет вектор?\n";
	cin >> len;
	int *vec = new int[len];
	cout << "Введите вектор\n";
	for(int i=0; i<len;i++){
		cin >> vec[i];
		tmp.push(vec[i]);
	}
	vector_arr[index-1] = tmp;
	}
	break;
	}
	
	case 6:
	{
	int index;
	cout << "Введите порядковый номер вектора\n";
	cin >> index;
	if(index>=capacity){
	cout << "Нет вектора с таким индексом\n";
	}
	else{
	vector_arr[index-1] = -vector_arr[index-1];
	}
	break;
	}
	
	
	case 7:
	{
	if(vector_arr[capacity-1].count == 0){
	cout << "Нет векторов\n";
	}
	else
	{
	int index;
	cout << "Введите порядковый номер вектора\n";
	cin >> index;	
	vector_arr[index-1].print();
	}
	break;
	}
	
	case 8:
	{
	int num = 1;
	if(vector_arr[capacity-1].count == 0){
	cout << "Нет векторов\n";
	}
	else{
	for(int i = 0; i<vector_arr[0].count;i++){
		cout << num << ". ";
		vector_arr[i].print();
		num++;
	}
	}
	break;
	}
	
	case 9:
	 {
	int ind1,ind2;
	cout << "Введите номер первого вектора\n";
	cin >> ind1;
	cout << "Введите номер второго вектора\n";
	cin >> ind2;
	if(ind1>=capacity || ind2>=capacity){
	cout << "Нет векторов с такими индексами\n";
	}
	 else{
	 cout << "Произведение равно:\n";
	 cout<< vector_arr[ind1-1]*vector_arr[ind2-1]<<endl;
	 }
	 break;
	 }
		
	}
	
	
	}
	
    	

	return 0;
}
