#include "filesortfactory.h"

std::unique_ptr<FileSort> FileSortFactory::CreateFileSort(cxxopts::ParseResult& parseResult)
{
	std::string sourceFile;
	std::string destinationFile;
	std::string delimeter = "\n";

	bool isAscending = true;
	bool isWordMode = false;

	int readLength = 0;

	if (parseResult.count("input"))
	{
		sourceFile = parseResult["input"].as<std::string>();
	}
	else
	{
		std::cout << std::endl << "No input file specified" << std::endl;
		return 0;
	}

	if (parseResult.count("output"))
	{
		destinationFile = parseResult["output"].as<std::string>();
	}
	else
	{
		destinationFile = sourceFile;
	}

	if (parseResult.count("descending"))
	{
		isAscending = false;
	}

	if (parseResult.count("length"))
	{
		readLength = parseResult["length"].as<int>();
	}

	if (parseResult.count("word"))
	{
		isWordMode = true;
	}

	if (parseResult.count("delimeter"))
	{
		delimeter = parseResult["delimeter"].as<std::string>();

		if (delimeter == "\\t")
		{
			delimeter = "\t";
		}
		else if (delimeter == "\\n")
		{
			delimeter = "\n";
		}
	}

	std::unique_ptr<FileSort> fileSort  = nullptr;
	
	if (readLength == 0)
	{
		fileSort = isWordMode ?
			std::unique_ptr<FileSort>(new WordFileSort(readLength, sourceFile, destinationFile, delimeter, isAscending)) :
			std::unique_ptr<FileSort>(new LineFileSort(readLength, sourceFile, destinationFile, delimeter, isAscending));
	}
	else
	{
		fileSort = std::unique_ptr<FileSort>(new LengthFileSort(readLength, sourceFile, destinationFile, delimeter, isAscending));
	}

	return std::move(fileSort);

}
