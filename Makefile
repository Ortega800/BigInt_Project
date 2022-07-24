# bigint project

# Type 'make tests' to compile and execute this project

###############################################################
# Variables
CPP  = clang++
OPTS = -g -Werror -W -Wunused -Wuninitialized -Wshadow -std=c++11

TESTS  = test_multiply test_times_10 test_times_digit test_subscript test_add test_equal test_constructor


###############################################################
# The first rule is run if only make is typed
msg:
	@echo 'Targets are:'
	@echo '  tests:'
	@echo '  add:'
	@echo '  multiply:'
	@echo '  clean:'

###############################################################
# Build and run all tests and output demonstration
#
tests: $(TESTS)
	./test_constructor
	./test_equal
	./test_add
	./test_subscript
	./test_times_10
	./test_times_digit
	./test_multiply

add: test_add
	./add

multiply: test_multiply
	./multiply

###############################################################
# Compile bigint
bigint.o: bigint.hpp bigint.cpp
	$(CPP) $(OPTS) -c bigint.cpp

###############################################################
# Compile and run all tests - uses a wild card.
test_%: bigint.o test_%.o
	$(CPP) $(OPTS) -o test_$* bigint.o test_$*.o

test_%.o: bigint.hpp test_%.cpp
	$(CPP) $(OPTS) -c test_$*.cpp



###############################################################
milestone2: add.o bigint.o
	$(CPP) $(OPTS) -o add add.o bigint.o

add.o: bigint.hpp add.cpp
	$(CPP) $(OPTS) -c add.cpp

###############################################################

milestone3: multiply.o bigint.o
	$(CPP) $(OPTS) -o multiply multiply.o bigint.o

multiply.o: bigint.hpp multiply.cpp
	$(CPP) $(OPTS) -c multiply.cpp



###############################################################
clean:
	rm -f *.o
	rm -f $(TESTS)
	rm -f multiply add
