# Matrix Calculation

The project involves creating a C library (matrixLib) with functions for dynamic vector and matrix operations, including calculations such as mean, correlation, covariance, matrix multiplication, and transposition, and testing these functions in a main program (main.c).

### returnVector(int size):
Dynamically allocates memory for a one-dimensional vector of the specified size.
Initializes the vector elements to zero.

### returnMatrix(int row, int col):
Dynamically allocates memory for a two-dimensional matrix with the specified number of rows and columns.
Initializes all matrix elements to zero.

### **freeMatrix(float mat, int row):
Frees the dynamically allocated memory for a matrix.

### *mean(float vec, int size):
Calculates and prints the mean (average) value of the elements in a vector.

### **variance(float vec1, float vec2, int size):
Calculates the variance between two vectors.

### **covariance(float vec1, float vec2, int size):
Calculates and prints the covariance between two vectors.

### **matrixMultiplication(float **mat1, float mat2, int row1, int col1, int row2, int col2):
Performs matrix multiplication of two matrices and returns the result.

### **matrixTranspose(float mat, int row, int col):
Transposes a matrix (switches its rows and columns) and returns the transposed matrix.

### **rowMeans(float mat, int row, int col):
Calculates and prints the mean of each row in a matrix.

### **columnMeans(float mat, int row, int col):
Calculates and prints the mean of each column in a matrix.

### **covarianceMatrix(float mat, int row, int col):
Calculates and prints the covariance matrix of a given matrix.

### **determinant(float mat, int row):
Calculates and prints the determinant of a square matrix.

### *printVector(float vec, int N):
Prints the elements of a vector.

### **printMatrix(float mat, int row, int col):
Prints the elements of a matrix.

Additionally, the project includes functions for filling vectors and matrices with random values (ikiBoyutluDiziDoldur and tekBoyutluDiziyiDoldur) and a main program (main.c) that demonstrates the usage of these functions and tests the implemented operations.
