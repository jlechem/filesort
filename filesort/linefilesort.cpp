#include "linefilesort.h"

void LineFileSort::load(std::string_view fileName)
{
	std::ifstream file(fileName.data(), std::ios::in);

	if (file.good())
	{
		std::string line;

		while (std::getline(file, line))
		{
			if (!line.empty())
			{
				this->items.push_back(line);
			}
		}

		file.close();
	}
}