/*

    copyright 2024 Justin LeCheminant

    This file is part of filesort.

    filesort is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    filesort is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with filesort.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef WORDLINEFILESORT_H
#define WORDLINEFILESORT_H

#include "textfilesort.h"

class WordFileSort :
    public TextFileSort
{
public:
    WordFileSort(int readLength, std::string inputFile, std::string outputFile, std::string delimeter, bool descending) : TextFileSort(readLength, inputFile, outputFile, delimeter, descending) {};

    void load();

};

#endif