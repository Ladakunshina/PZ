#include <iostream>
#include <string>


template <typename T>
class listok
{
private:
	item<T>* glavptr = nullptr;

	item<T>* poisk(int position);
	void change(item<T>* u1, item<T>* u2);
	void sort(int left, int right);

public:
	void additem(T n_element);
	void get_item(int position);

	void all_list();
	int check_size();

	~listok();
};

template <typename T>
class item {
public:
	item* next_ptr;
	item* back_ptr;
	T data;
	unsigned int read;
};

template <typename T>
int listok<T>::check_size()
{
	item<T>* cur = glavptr;
	int i = 0;

	while (cur != nullptr)
	{
		++i;
		cur = cur->next_ptr;
	}

	return i;
}

template <typename T>
void listok<T>::additem(T n_element)
{
	item<T>* n_item = new item<T>;

	if (glavptr == nullptr)
	{
		n_item->next_ptr = nullptr;
		n_item->back_ptr = nullptr;

		glavptr = n_item;
	}
	else
	{
		item<T>* cur = glavptr;
		while (cur->next_ptr != nullptr)
		{
			cur = cur->next_ptr;
		}
		n_item->next_ptr = nullptr;
		n_item->back_ptr = cur;

		cur->next_ptr = n_item;
	}

	n_item->data = n_element;
	n_item->read = 0;
}

template <typename T>
item<T>* listok<T>::poisk(int position)
{
	item<T>* cur = glavptr;
	while (cur->next_ptr != nullptr && position - 1 > 0)
	{
		cur = cur->next_ptr;
		position--;
	}

	return cur;
}

template <typename T>
void listok<T>::change(item<T>* u1, item<T>* u2)
{
	T pdata = u1->data;
	unsigned int appeals = u1->read;

	u1->data = u2->data;
	u1->read = u2->read;

	u2->data = pdata;
	u2->read = appeals;
}

template <typename T>
void listok<T>::sort(int left, int right)
{
	int l_hold = left;
	int r_hold = right;
	int pivot = poisk(left)->read;

	while (left < right) {

		while ((poisk(right)->read <= pivot) && (left < right)) right--;

		if (left != right)
		{
			change(poisk(right), poisk(left));
			left++;
		}

		while ((poisk(left)->read) && (left < right)) left++;

		if (left != right)
		{
			change(poisk(left), poisk(right));
			right--;
		}
	}

	poisk(left)->read = pivot;
	if (l_hold < right) sort(l_hold, right - 1);
	if (r_hold > right) sort(right + 1, r_hold);

}

template <typename T>
void listok<T>::get_item(int position)
{
	item<T>* cur = glavptr;
	while (cur->next_ptr != nullptr && position - 1 > 0)
	{
		cur = cur->next_ptr;
		position--;
	}

	std::cout << '\t' << cur->data << " number of requests: " << cur->read << '\n';

	cur->read += 1;
	sort(0, check_size());
}


template <typename T>
void listok<T>::all_list()
{
	item<T>* cur = glavptr;

	while (cur != nullptr)
	{
		std::cout << "#" << '\t' << cur->data << " " << " number of requests: " << cur->read << '\n';
		cur = cur->next_ptr;
	}
}

template <typename T>
listok<T>::~listok()
{
	if (glavptr == nullptr) return;

	item<T>* cur = glavptr;
	while (cur->next_ptr != nullptr)
	{
		cur = cur->next_ptr;
		delete[] cur->back_ptr;
	}

	delete[] cur;
}

int main()
{
	listok<std::string> obj;
	obj.additem("vozdux");
	obj.additem("sun");
	obj.additem("sea");
	obj.additem("grib");

	obj.get_item(1);
	obj.get_item(1);
	obj.get_item(2);
	obj.get_item(1);
	obj.get_item(3);

	obj.all_list();

	return 0;
}
