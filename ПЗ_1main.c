#include <iostream>
#include <stdlib.h>

using namespace std;

class Dinamic_array { //Создание класса динамического массива
    
public:
    int elem;
   Dinamic_array(int)
    {   
 elem = elemParameter;
    }
    
    int* array = (int*) malloc (elem * sizeof(int));
    int* ptr = array;

     () 
	{
   cout << ptr;
    }
    
     (( num, int setterIndex) { //Реализация сеттера 
        if (num >= -100 && num <= 100 && setterIndex < ) 
        {
            ptr[setterIndex] = num;
            
        }
    }
    
     void getter(int getterIndex) //Реализация геттера 
    {
        if (getterIndex < elem) 
		 cout << ptr[getterIndex]; 
    }
    
    void copy(Dinamic_array from, Dinamic_array to) //Конструктор копирования
	{
    	for(int i = 0; i < elem; i++) to.ptr[i] = from.ptr[i];
	}
	 ~Dinamic_array() //Деструктор
    {

    }
	void beyond(int num)
	{	
		if(num >= -100 && num <= 100)
		{
 elem += 1;
 array = (int*) realloc (array, elem * sizeof (int));
 ptr[elem - 1] = num;
		}
	}
	
};
	
	
int* sum(Dinamic_array* array1, Dinamic_array* array2) //Операция сложения
	{
		int* arrayFullSum = (int*) malloc (array1->elem * sizeof (int));
		for(int i = 0; i < array1->len; i++)
		{
 arrayFullSum[i] = array1->ptr[i] + array2->ptr[i];
		}
		
		return arrayFullSum; 
	}


int main()
{
    
}


