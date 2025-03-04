CXX = \g++
CXXFLAGS = -fprofile-arcs -ftest-coverage -fprofile-values -fPIC -g

# Targets for the executables
all: main input_tester

# Build the input_tester executable
input_tester: input_tester.o matrix_multiplier.o
	$(CXX) $(CXXFLAGS) -o input_tester input_tester.o matrix_multiplier.o

# Build the main executable
main: main.o matrix_multiplier.o
	$(CXX) $(CXXFLAGS) -o main main.o matrix_multiplier.o

# Benchmark command
benchmark: main.cpp matrix_multiplier.cpp
	$(CXX) $(OPTFLAGS) -o main_bench main.cpp matrix_multiplier.cpp
	./main_bench


# Compile the object file for input_tester
input_tester.o: input_tester.cpp
	$(CXX) $(CXXFLAGS) -c input_tester.cpp -o input_tester.o

# Compile the object file for main
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

# Compile the object file for matrix_multiplier
matrix_multiplier.o: matrix_multiplier.cpp
	$(CXX) $(CXXFLAGS) -c matrix_multiplier.cpp -o matrix_multiplier.o

# Clean up object files and executables
clean:
	rm -f *.o *.gcov *.gcda *.gcno main main_bench input_tester

# Generate a code coverage report
report: main
	./main  # Run input_tester
	gcov -r main.cpp # Generate gcov report
	gcov -r matrix_multiplier.cpp

