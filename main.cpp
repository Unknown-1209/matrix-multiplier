#include "matrix_multiplier.h"
#include <iostream>
#include <chrono>
#include <cstdlib> // For rand()
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    // Create two matrices
    Matrix A(500, 500);
    Matrix B(500, 500);

	
	cout << "Generating dummy data for matrices...\n";
    for (size_t i = 0; i < A.rows(); ++i) {
        for (size_t j = 0; j < A.cols(); ++j) {
            A(i, j) = rand() % 10;
            B(i, j) = rand() % 10;
        }
    }
	

	// Start timer
    auto start = std::chrono::high_resolution_clock::now();
	
	cout << "Multiplying matrices...\n";
	Matrix result = winogradMultiply(A,B);

    // Stop timer
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate duration in milliseconds
    chrono::duration<double, std::milli> duration = end - start;

    cout << "Matrix multiplication took " << duration.count() << " ms." << std::endl;

    return 0;
}

