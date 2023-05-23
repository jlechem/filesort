Welcome to the readme text file for filesort. Filesort is a small utility to sort files into ascending or descending order, either replacging the original file or creating a new one, you can also specify to read the entire line or chunks (characters) at a time. It is lightweight and very fast. Originally written over 10 years ago I have upgraded the source code to use newer standards and is compiled against the Windows 10 SDK and using Visual Studio 2017.

I have tried to write nothing but ANSI C++ for this project.  So while the solution is windows centric the source code should be able to be compiled for multiple other OSes with little effort.  I haven't actually compiled the code using gcc, minGW, etc but it should be able to work.

Detailed Useage Directions

Items are sorted using white space and ascending order by default

White space and sort order can be overriden using the appropriate switches.
		 FILESORT [source file] [output file] [/d] [/cX]
		 [/d] Specifies descending sort order.
		 [/cX] Specifies X number of characters to be read instead of whitespace.


Best regards,

Justin LeCheminant
