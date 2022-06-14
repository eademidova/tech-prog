#include <iostream>
#include <string>
using namespace std;

struct Product{
	string name;
	float price;
	int amount;
	Product *next;
};


void add_first (Product *&p_product, string new_name, float p, int a){
	Product *new_product = new Product;
	new_product ->name = new_name; 
	new_product ->price = p;
	new_product ->amount = a;
	new_product ->next = p_product;
	p_product = new_product;
};

void add_last (Product *&p_product, string new_name, float p, int a){
	Product *tmp = p_product;
	if (p_product == NULL){
		add_first(p_product, new_name, p, a);
		return;
		}
	while (tmp ->next) tmp = tmp->next;
	Product *new_product = new Product;
	new_product->name = new_name;
	new_product->price = p;
	new_product->amount = a;
	new_product->next = NULL;
	tmp->next = new_product;
	return;
};

int add_after (Product *p_product, string new_name, float p, int a, string name_after){
	if (p_product == NULL) return 1;
	Product *tmp = p_product;
	while (tmp != NULL && tmp->name != name_after){
		tmp = tmp->next;
	}
	if (tmp == NULL) return 1;
	Product *new_product = new Product;
	new_product->name = new_name;
	new_product->price = p;
	new_product->amount = a;
	new_product->next = tmp->next;
	tmp->next = new_product;
	return 0;
};

int add_before(Product *&p_product, string new_name, float p, int a, string name_before){

	if (p_product == NULL) return 1;
	if (p_product->name == name_before){
		add_first(p_product, new_name, p, a);
		return 0;
	}
	if (p_product->next == NULL) return 1;
	Product *prev = p_product, *tmp = p_product->next;
	while (tmp != NULL && tmp->name != name_before){
		prev = prev->next; 
		tmp = tmp->next;
	}
	if (tmp->next == NULL && tmp -> name!=name_before) return 1;
	Product *new_product = new Product;
	new_product->name = new_name;
	new_product->price = p;
	new_product->amount = a;
	new_product->next = tmp;
	prev->next = new_product;
	return 0;
};

int del_product(Product *&p_product, string del_name){
	if (p_product = NULL) return 1;
	Product *tmp = p_product;
	if (p_product->name == del_name){
		p_product = p_product->next; 
		delete tmp; 
		return 0;
	}
	if (p_product->next == NULL) return 1;
	Product *prev = p_product; tmp = p_product->next;
	while (tmp->next != NULL && tmp->name != del_name){
		prev = prev->next; 
		tmp = tmp->next;
	}
	if (tmp->next == NULL && tmp->name!=del_name) return 1;	
	prev->next = tmp->next;
	delete tmp;
	return 0;
};

void print_list(Product *p_product){
	if(p_product == NULL){
		cout << "The list is empty"; return;
	};
	Product *tmp = p_product;
	while (tmp != NULL){
		cout << "Product: "<< tmp->name <<"\nPrice:"<< tmp->price <<"\nAmount:"<<tmp->amount<<"\n\n";
		tmp = tmp->next;
	};
	return;
};

void print(int &outN){
cin >> outN;
};



int main(){
    int n;
    int amount;
	float price;
	string name;
	string name_after;
	string name_before;
	Product *p_product = NULL;
	bool flag =false;
		while(!flag)
	{
	cout<< "\nВведите 0, если хотите завершить программу" <<"\nВведите 1, если хотите добавить элемент в начало"<<"\nвведите 2, если хотите добавить элемент в конец"<<"\nВведите 3, если хотите добавит элемент после другого"<<"\nВведите 4, если хотите добавить элемент до другого"<<"\nВведите 5, если хотите удалить элемент"<<"\nВведите 6, чтобы вывести список\n";
	print(n);
	cout << "\n";
	
	switch(n)
	{
	case 0:
	flag =true;
	break;
	case 1:
	cout << "Введите имя нового продукта\n";
	cin >> name;
	cout << "Введите его цену\n";
	cin >> price;
	cout << "Введите количество\n";
	cin >> amount;
	add_first(p_product, name, price, amount);
	break;
	case 2:
	cout << "Введите имя нового продукта\n";
	cin >> name;
	cout << "Введите его цену\n";
	cin >> price;
	cout << "Введите количество\n";
	cin >> amount;
	add_last(p_product, name, price, amount);
	break;
	case 3:
	cout << "Введите имя нового продукта\n";
	cin >> name;
	cout << "Введите его цену\n";
	cin >> price;
	cout << "Введите количество\n";
	cin >> amount;
	cout << "Введите имя продукта после которого добавить новый\n";
	cin >> name_after;
	add_after(p_product, name, price, amount, name_after);
	break;
	case 4:
	cout << "Введите имя нового продукта\n";
	cin >> name;
	cout << "Введите его цену\n";
	cin >> price;
	cout << "Введите количество\n";
	cin >> amount;
	cout<< "Введите имя продукта до которого добавить новый\n";
	cin >> name_before;
	add_before(p_product, name, price, amount, name_before);
	break;
	case 5:
	cout << "Введите имя продукта, который нужно удалить\n";
	cin >> name;
	del_product(p_product, name);
	break;
	case 6:
	print_list(p_product);
	}
	}
	
	return 0;
}

