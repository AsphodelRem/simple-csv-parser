#include "CSVParser.hpp"

int main()
{
	std::ifstream fin("input.csv");
	CSVParser<int, std::string, double, int, int, int, double, int, double, int, std::string> p(fin, 3, ',', '/');

	for (auto x : p)
	{
		std::cout << x;
		std::cout << std::endl;
	}

	std::cout << p[3];

	return 0;
}

