# Linked List (Doubly-linked)

### Files included
* main.c
* dlist.c
* dlist.h
* Makefile

### Compilation

If you are using UNIX/Linux, use `make` to compile and `make clean` to clean up after running the program.

Please use `gcc main.c dlist.c -o dlist` if you are using gcc compiler

Run with ./dlist

### Program Menu

The program offers a context menu in the beginning. Press 1 to start a new linked list. Then use the other options to operate on it. Press 9 in the menu to quit the program. Press 7 at any  point to view the linked list representation. The double arrows represent double-links between nodes and single arrows point to X represent NULL pointers.

### Functions implemented

* create()
* displayNode()
* deleteNode()
* insertBeginning()
* insertEnding()
* insertAfter()
* insertBefore()
* searchNode()