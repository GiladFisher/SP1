CC=gcc
AR=ar
MAIN=main.o
BASIC=basicClassification.o
LOOP=advancedClassificationLoop.o
REC=advancedClassificationRecursion.o
FLAGS=-Wall

# mains:
# 	$(CC) $(FLAGS) -o mains main.c basicClassification.c advancedClassificationRecursion.c -lm

all: mains maindloop maindrec loops recursives recursived loopd
loops: libclassloops.a
recursives:libclassrec.a
recursived: libclassrec.so
loopd:libclassloops.so

mains: $(MAIN) libclassrec.a
	$(CC) $(FLAGS) -o mains $(MAIN) libclassrec.a -lm
maindloop: $(MAIN) libclassloops.so
	$(CC) $(FLAGS) -o maindloop $(MAIN) ./libclassloops.so -lm 
maindrec: $(MAIN) libclassrec.so 
	$(CC) $(FLAGS) -o maindrec $(MAIN) ./libclassrec.so -lm
libclassloops.a: $(BASIC) $(LOOP) 
	$(AR) -rcs libclassloops.a $(BASIC) $(LOOP)
libclassrec.a: $(BASIC) $(REC)
	$(AR) -rcs libclassrec.a $(BASIC) $(REC) 
libclassrec.so: $(BASIC) $(REC)
	$(CC) -shared -o libclassrec.so $(BASIC) $(REC) 
libclassloops.so: $(BASIC) $(LOOP)
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
	rm -f *.o *.a *.so mains maindloop maindrec