#include "wordfilesort.h"

void WordFileSort::load(std::string_view fileName)
{
	std::ifstream file(fileName.data(), std::ios::in);

	if (file.good())
	{
		std::string item;

		while (file >> item)
		{
			this->items.push_back(item);
		}

		file.close();
	}
}