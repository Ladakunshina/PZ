#include <iostream>
#include <vector>

void complection(std::vector<int>& n_vctr)
{	
	for (unsigned int i = 0; i < n_vctr.size(); ++i)
	{
		n_vctr[i] = rand()%201 - 100;
		std::cout << n_vctr[i] << ' ';
	}
}

void average(std::vector<int>& vctr)
{
	double result = 0;
	for(unsigned int i = 0; i < vctr.size(); ++i)
	{
		result += static_cast<double>(vctr[i]);
	}

	result /= static_cast<double>(vctr.size());
	std::cout << result << ' ';
}

void adjacent(std::vector<int>& V1, std::vector<int>& V2)
{
	for(unsigned int i = 0; i < V2.size(); ++i)
	{
		for(unsigned int j = 0; j < V1.size(); ++j)
		{
			if(V2[i] == V1[j])
			{
				std::cout << V2[i] << ' ';
				break;
			}
		}
	}
}

int main()
{
	int razmer_v1, razmer_v2;
	std::cin >> razmer_v1 >> razmer_v2;
	std::cout << '\n';

	std::vector<int> V1(razmer_v1);
	std::vector<int> V2(razmer_v2);

	complection(V1);
	std::cout << '\n';

	complection(V2);
	std::cout << '\n';


	average(V1);
	std::cout << '\n';

	average(V2);

	std::cout << '\n';

	adjacent(V1, V2);

	return 0;
}
