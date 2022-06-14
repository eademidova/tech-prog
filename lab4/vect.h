#include <iostream>
#include <string>
using namespace std;

class Vector
{
public:
	

	friend class Matrix;
	static int count;
	Vector(){
	arr = new int[1];
	capacity = 1;
	n = 0;
	
	}
	
	Vector operator + (Vector &r);
	Vector operator - ();
	Vector& operator = (const Vector &r);
	int operator * (Vector &r);
	Vector operator - (Vector &r);
	
    	~Vector() {
		delete[] arr;
	}

	
	void push(int data){

        if (n == capacity){

            int* tmp = new int[2*capacity];

            for (int i = 0; i < capacity; i++) {
                tmp[i] = arr[i];
            }
            
            delete[] arr;
            capacity *= 2;
            arr = tmp;
            }
            arr[n] = data;
            n++; 

        } 

	void print()
        {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
	}
	
	void remove(int index) {
		for (int i = index + 1; i < n; ++i) {
    		arr[i - 1] = arr[i];
               }
    	--n;
    	}
    	
    	int operator [] (int index)
   {
      return this->arr[index];
   }

private:
	int n;
	int capacity;
	int *arr;


	
};


int Vector::count=0;

Vector Vector::operator - ()
{ Vector res;
  for(int i = 0; i < this->n; i++){
    res.push((-(this->arr[i])));
  }
  return res;
}

Vector& Vector::operator = (const Vector &r)
{ delete [] arr;
  this->n = r.n;
  arr=new int[n];
  for (int i = 0; i < n; i++) this->arr[i] = r.arr[i];
  return *this;
}

Vector Vector::operator + (Vector &r)
{ Vector res;
  if(this->n != r.n) 
  {
  exit(1);
  }
  else{	
  for(int i = 0; i < r.n; i++){
    res.push(r.arr[i] + this->arr[i]);
  }
  }
  return res;
}

Vector Vector::operator - (Vector &r)
{ Vector res;
  if(this->n != r.n) 
  {
  exit(1);
  }
  else{
  for(int i = 0; i < r.n; i++){
    res.push(this->arr[i]-r.arr[i]);
  }
  }
  return res;
}

int Vector::operator * (Vector &r){
	int res=0;
	for(int i =0; i< r.n; i++){
	res += (this->arr[i])*r.arr[i];
	}
	return res;
}


