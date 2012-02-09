GCC = g++
GCC_FLAGS = -w -Wall -Werror -pedantic -ansi
OBJECTS = BigInt.o Primes.o

all: $(OBJECTS)
	$(GCC) $(GCC_FLAGS) -o test_bigint testcases_BigInt.cpp $(OBJECTS)
	$(GCC) $(GCC_FLAGS) -o test_primes testcases_Primes.cpp $(OBJECTS)


%.o: %.cpp %.h
	$(GCC) $(GCC_FLAGS) -c $<

clean:
	rm -rf *~ *.o test_bench test_bigint test_primes