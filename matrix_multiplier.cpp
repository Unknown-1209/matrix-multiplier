#include "matrix_multiplier.h"

// Function for naive matrix multiplication O(n^3)
Matrix multiplyMatrices(const Matrix& A, const Matrix& B) {
    if (A.cols() != B.rows()) {
        throw std::invalid_argument("Matrix dimensions do not allow multiplication");
    }

    Matrix result(A.rows(), B.cols());

    for (size_t i = 0; i < A.rows(); i++) {
        for (size_t j = 0; j < B.cols(); j++) {
            for (size_t k = 0; k < A.cols(); k++) {
                result(i, j) += A(i, k) * B(k, j);
            }
        }
    }

    return result;
}

// Winograd’s algorithm matrix multiplication
Matrix winogradMultiply(const Matrix& A, const Matrix& B) {
    if (A.cols() != B.rows()) {
        throw std::invalid_argument("Matrix dimensions do not allow multiplication");
    }

    size_t m = A.rows(), n = A.cols(), p = B.cols();
    Matrix result(std::vector<std::vector<int>>(m, std::vector<int>(p, 0)));

    // Compute row factors
    std::vector<int> rowFactor(m, 0);
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < n / 2; j++) {
            rowFactor[i] += A(i, 2 * j) * A(i, 2 * j + 1);
        }
    }

    // Compute column factors
    std::vector<int> colFactor(p, 0);
    for (size_t j = 0; j < p; j++) {
        for (size_t i = 0; i < n / 2; i++) {
            colFactor[j] += B(2 * i, j) * B(2 * i + 1, j);
        }
    }

    // Main computation
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < p; j++) {
            result(i, j) = -rowFactor[i] - colFactor[j];
            for (size_t k = 0; k < n / 2; k++) {
                result(i, j) += (A(i, 2 * k) + B(2 * k + 1, j)) * (A(i, 2 * k + 1) + B(2 * k, j));
            }
        }
    }

    // Handle odd case when n is odd
    if (n % 2 == 1) {
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < p; j++) {
                result(i, j) += A(i, n - 1) * B(n - 1, j);
            }
        }
    }

    return result;
}

// Implementation of the equality operator (==)
bool Matrix::operator==(const Matrix& other) const {
    return data == other.data;
}
