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

#ifndef FILESORTFACTORY_H
#define FILESORTFACTORY_H

#include "filesort.h"
#include "cxxopts.h"
#include "filesort.h"
#include "linefilesort.h"
#include "lengthfilesort.h"
#include "wordfilesort.h"

class FileSortFactory
{
public:
    static std::unique_ptr<FileSort> CreateFileSort(const cxxopts::ParseResult& parseResult);
};

#endif