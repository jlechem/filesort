#include "TextFileSort.h"

TextFileSort::~TextFileSort(void)
{
}

void TextFileSort::sort(bool isAscending)
{
	if (isAscending)
	{
		std::sort(std::execution::par_unseq, this->items.begin(), this->items.end());
	}
	else
	{
		std::sort(std::execution::par_unseq, this->items.rbegin(), this->items.rend());
	}
}

void TextFileSort::save(std::string_view fileName)
{
	std::ofstream file(fileName.data(), std::ios::out | std::ios::trunc);

	std::ostream_iterator<std::string> it(file, this->delimeter.data());

	std::copy(this->items.begin(), this->items.end(), it);

	file.close();
}
