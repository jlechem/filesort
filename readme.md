# Release versions

Note that `main` is generally a work in progress, and you probably want to use a
tagged release version.



Welcome to the readme text file for filesort. Filesort is a small utility to sort files into ascending or descending order, either replacging the original file or creating a new one, you can also specify to read the entire line or chunks (characters) at a time. It is lightweight and very fast. Originally written over 10 years ago I have upgraded the source code to use newer standards. I have added code and a makefile in the repository to support GCC as well as Visual Studio.

Building Instructions
	Windows: Open the solution file and build your desired build configuratiin.
	Unix/Linx: In the filesort/filesort directory run the makefile provided. The default compiler is GCC but you can modify as desired.


Detailed Useage Directions

Items are sorted using white space and ascending order by default

White space and sort order can be overriden using the appropriate switches.
		 FILESORT [source file] [output file] [/d] [/cX]
		 [/d] Specifies descending sort order.
		 [/cX] Specifies X number of characters to be read instead of whitespace.


Best regards,

Justin LeCheminant
