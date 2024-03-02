#include "lengthfilesort.h"

void LengthFileSort::load(std::string_view fileName)
{
	std::ifstream file(fileName.data(), std::ios::in);

	if (file.good())
	{
		while (!file.eof())
		{
			std::string newString(this->readLength, ' ');
			file.read(&newString[0], this->readLength);

			if (!newString.empty())
			{
				this->items.push_back(newString);
			}
		}

		file.close();
	}
}