#Makefile

dlist:	main.o dlist.o
	gcc main.c dlist.c -o dlist

clean:
	rm *.o dlist