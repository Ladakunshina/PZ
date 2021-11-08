#include <iostream>
#include <stdlib.h>
class Dinamic_array { //Создание класса динамического массива
    
public:
    int len;
   Dinamic_array(int)
    {   
 len = lenParameter;
    }
    ~Dinamic_array()
    {

    }
    
    int* array = (int*) malloc (len * 
    int* ptr = array;

     () 
	{
 std::cout << ptr;
    }
    
     (( num, int setterIndex) { //Реализация сеттера 
        if (num >= -100 && num <= 100 && setterIndex < len) 
        {
            ptr[setterIndex] = num;
            
        }
    }
    
     void getter(int getterIndex) //Реализация геттера 
    {
        if (getterIndex < len) std::cout << ptr[getterIndex]; 
    }
    
    void copy(Dinamic_array from, Dinamic_array to)
	{
    	for(int i = 0; i < len; i++) to.ptr[i] = from.ptr[i];
	}
	void beyond(int num)
	{	
		if(num >= -100 && num <= 100)
		{
 len += 1;
 array = (int*) realloc (array, len * sizeof (int));
 ptr[len - 1] = num;
		}
	}
	
};
	
	
int* sum(Dinamic_array* array1, Dinamic_array* array2) 
	{
		int* arrayFullSum = (int*) malloc (array1->len * sizeof (int));
		for(int i = 0; i < array1->len; i++)
		{
 arrayFullSum[i] = array1->ptr[i] + array2->ptr[i];
		}
		
		return arrayFullSum; 
	}


int main()
{
    
}


