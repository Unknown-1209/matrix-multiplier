#include "matrix_multiplier.h"

// Function for matrix multiplication
Matrix multiplyMatrices(const Matrix& A, const Matrix& B) {
    if (A.cols() != B.rows()) {
        throw std::invalid_argument("Matrix dimensions do not allow multiplication");
    }

	// Create new matrix with the appropriate size and set all elements to 0
    Matrix result(std::vector<std::vector<int>>(A.rows(), std::vector<int>(B.cols(), 0)));

    for (size_t i = 0; i < A.rows(); i++) {
        for (size_t j = 0; j < B.cols(); j++) {
            for (size_t k = 0; k < A.cols(); k++) {
                result(i, j) += A(i, k) * B(k, j);
            }
        }
    }

    return result;
}

// Implementation of the equality operator (==)
bool Matrix::operator==(const Matrix& other) const {
    return data == other.data;
}

