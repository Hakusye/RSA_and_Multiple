CC = gcc 
OBJS = main.o my_math.o Wiretap.o output.o Multiple.o
OBJS1 = main.o my_math.o Multiple.o output.o 
OBJS2 = Wiretap.o my_math.o output.o Multiple.o


wiretap: $(OBJS2)
	$(CC) -o wiretap $(OBJS2)

main: $(OBJS1)
	$(CC) -o main $(OBJS1)

Multiple.o:
	$(CC) -c Multiple/Multiple.c

.c.o:
	$(CC) -c $< 

clean:
	rm -f main wiretap $(OBJS)


main.o: my_math.h output.h Multiple/Multiple.h
Wiretap.o: my_math.h output.h
