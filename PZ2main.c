#include <iostream>
#include <execution>
#include <cmath>



template<typename T>
class massiv
{
private:

	int size;
	T* arr;

public:

	massiv(int count);
	massiv(const  massiv<T>& array);
	~massiv();

	void print();
	void add(int value);
	void summ(massiv<T>& array);
	void subt(massiv<T>& array);
	void distance(massiv<T>& arr1 , massiv<T>& arr2);

};

template<typename T>
massiv<T>::massiv(int count) : size(count)
{
	arr = new T[size];
	if (size == NULL)
		throw std::bad_alloc();
	if (size > 10000)
		throw std::out_of_range("Out of range");
	for (int i = 0; i < size; i++)
		arr[i] = i;
}	

template<typename T>
massiv<T>::massiv(const massiv<T>& array) : size(array.size), arr(nullptr)
{
	arr = new T[size];
	if (size == NULL)
		throw std::bad_alloc();
	for (int i = 0; i < size; i++)
		arr[i] = array.arr[i];
	if (size > 10000)
		throw std::out_of_range("Out of range");
}

template<typename T>
massiv<T>::~massiv()
{
	delete[] arr;
}

template<typename T>
void massiv<T>::print()
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

template<typename T>
void massiv<T>::add(int value)
{

	if (value >= 101 || value <= -101)
		throw std::invalid_argument("SCATEMAN_WORLD");

	int* massiv = new int[size + 1];
	if (size == NULL)
		throw std::bad_alloc();
	for (int i = 0; i < size; i++)
	{
		massiv[i] = arr[i];
	}
	massiv[size] = value;
	delete[] arr;
	arr = massiv;
	if (size > 10000)
		throw std::out_of_range("Out of range");
	size++;
}

template<typename T>
void massiv<T>::summ(massiv<T>& array)
{
	int sum1 = 0; int sum2 = 0;
	for (int i = 0; i < size; i++)
	{
		sum1 += arr[i];
	}

	for (int i = 0; i < array.size; i++)
	{
		sum2 += array.arr[i];
	}

	std::cout << "Summ 2 dinamic massives: " << sum1 + sum2 << std::endl;
}

template<typename T>
void massiv<T>::subt(massiv<T>& array)
{
	int sum1 = 0; int sum2 = 0;
	for (int i = 0; i < size; i++)
	{
		sum1 += arr[i];
	}

	for (int i = 0; i < array.size; i++)
	{
		sum2 += array.arr[i];
	}

	std::cout << "Substraction 2 dinamic massives: " << sum1 - sum2 << std::endl;
}

template<typename T>
void massiv<T>::distance(massiv<T>& arr1, massiv<T>& arr2)
{
	int i = 0;

	int ret = 0;
	while (arr1.arr[i] != arr1.arr[arr1.size])
	{
		int dist = arr1.arr[i] - arr2.arr[i];
		i++;
		ret += dist * dist;
	}

	if (ret > 0)
		sqrt(ret);
	else
		ret = 0;
	std::cout << "Distance between 2 massivs: " << ret << std::endl;
}

int main()
{
	massiv<int> arr(100);
	arr.add(15);
	arr.print();

	massiv<int> arr2 = arr;
	arr2.print();

	std::cout << std::endl;
	arr.summ(arr2); 
	arr.subt(arr2); 
	arr.distance(arr, arr2); 

	return 0;
}
