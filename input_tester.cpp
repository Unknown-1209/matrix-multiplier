#include <iostream>
#include <vector>
#include "matrix_multiplier.h"

using namespace std;

void assertTrue(bool b, string desc);
void testMatrixConstructor();
void testEmptyMatrix();
void testMatrixAssignment();
void testInvalidMatrices();
void testMatrixMult();
void testMatrixMult_1();

int main() {
    cout << "------Running input tester------\n";
	testMatrixConstructor();
	testEmptyMatrix();
	testMatrixAssignment();
	testInvalidMatrices();
	testMatrixMult();
	testMatrixMult_1();

    return 0;
}


void assertTrue(bool b, string desc) {
    if (b) {
        cout << "PASSED: " << desc << endl;
    } else {
        cout << "FAILED: " << desc << endl;
    }
}

void testMatrixConstructor() {
	Matrix A(2,3);
	Matrix B(2,2);
	assertTrue(A.rows() == 2 && A.cols() == 3 && B.rows() == 2 && B.cols() == 2, "Test matrix constructor");

}

void testMatrixVectorInitializer() {
	Matrix A = {{1,2},{3,4},{5,6}};
	vector<vector<int>> expected = {{1,2},{3,4},{5,6}};

	assertTrue(A == expected && A.rows() == 2 & A.cols() == 3, "Test matrix with vector initializer");
}

void testEmptyMatrix() {
	Matrix A;

	assertTrue(A.rows() == 0 && A.cols() == 0, "Test empty matrix");
}

void testMatrixAssignment() {
	Matrix A(2,2);
	A = {{1,2},{1,2}};
	Matrix expected = {{1,2},{1,2}};

	assertTrue(A == expected, "Test matrix assignment");
}

void testInvalidMatrices() {
try {
        Matrix invalidA = {{1, 2, 3}, {4, 5, 6}};  // 2x3 matrix
        Matrix invalidB = {{1, 2}, {3, 4}};        // 2x2 matrix
        
        Matrix invalidResult = multiplyMatrices(invalidA, invalidB);
        
        // If no exception is thrown, fail the test
        assertTrue(false, "Invalid Matrix Multiplication should have thrown an error");

    } catch (const std::invalid_argument& e) {
        assertTrue(true, "Caught expected invalid_argument exception for invalid matrix multiplication");
    } catch (...) {
        assertTrue(false, "Caught an unexpected exception type for invalid matrix multiplication");
    }
}


void testMatrixMult() {
    // Test case 1: 2x2 Matrix Multiplication
    Matrix A = {{1, 2}, {3, 4}};
    Matrix B = {{5, 6}, {7, 8}};
    Matrix expected = {{19, 22}, {43, 50}};

    Matrix resultMatrix = multiplyMatrices(A, B);
    assertTrue(resultMatrix == expected, "2x2 Matrix Multiplication");
}


void testMatrixMult_1() {
    // Test case 2: 2x3 * 3x2 Matrix Multiplication
    Matrix C = {{2, 3, 4}, {1, 0, 2}};
    Matrix D = {{3, 1}, {2, 4}, {5, 6}};
    Matrix expected2 = {{32, 38}, {13, 13}};

    Matrix resultMatrix = multiplyMatrices(C, D);
    assertTrue(resultMatrix == expected2, "2x3 * 3x2 Matrix Multiplication");
}

