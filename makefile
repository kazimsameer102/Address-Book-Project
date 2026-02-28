book.exe:main.o file.o contact.o populate.o validate.o
	gcc -o book.exe main.o file.o contact.o populate.o validate.o
main.o:main.c
	gcc -c main.c
contact.o:contact.c
	gcc -c contact.c
populate.o:populate.c
	gcc -c populate.c
file.o:file.c
	gcc -c file.c
validate.o: validate.c
	gcc -c validate.c
clear:
	rm*.exe*.o