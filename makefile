# Macros ------------------------------------------------
CC=gcc # for c
AR=ar # for static libraries 
MAIN=main.o
BASIC=basicClassification.o
LOOP=advancedClassificationLoop.o
REC=advancedClassificationRecursion.o
FLAGS=-Wall
# End Macros ---------------------------------------------

loops: libclassloops.a
recursives:libclassrec.a
recursived: libclassrec.so
loopd:libclassloops.so
all: mains maindloop maindrec loops recursives recursived loopd

mains: $(MAIN) libclassrec.a # the main file. using static recursion liabrary
	$(CC) $(FLAGS) -o mains $(MAIN) libclassrec.a -lm

maindloop: $(MAIN) libclassloops.so # the main file. using dynamic loops liabrary
	$(CC) $(FLAGS) -o maindloop $(MAIN) ./libclassloops.so -lm 

maindrec: $(MAIN) libclassrec.so # the main file. using dynamic recursion liabrary
	$(CC) $(FLAGS) -o maindrec $(MAIN) ./libclassrec.so -lm

libclassloops.a: $(BASIC) $(LOOP) # makes the static liabrary for loops
	$(AR) -rcs libclassloops.a $(BASIC) $(LOOP)

libclassrec.a: $(BASIC) $(REC) # makes the static liabrary for recursion
	$(AR) -rcs libclassrec.a $(BASIC) $(REC) 

libclassrec.so: $(BASIC) $(REC) # makes the dynamic liabrary for recursion
	$(CC) -shared -o libclassrec.so $(BASIC) $(REC) 

libclassloops.so: $(BASIC) $(LOOP) # makes the dynamic liabrary for loops
	$(CC) -shared -o libclassloops.so $(BASIC) $(LOOP) 

$(MAIN): main.c NumClass.h
	$(CC) $(FLAGS) -c main.c -lm

$(BASIC): basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c basicClassification.c -lm

$(LOOP): advancedClassificationLoop.c NumClass.h 
	$(CC) $(FLAGS) -c advancedClassificationLoop.c -o $(LOOP) -lm 

$(REC): advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c -o $(REC) -lm  

.PHONY: clean all

clean:
	rm -f *.a *.so *.o mains maindrec maindloop