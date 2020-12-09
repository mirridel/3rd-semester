#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
public:

	// Constructors and destructor

	Matrix(int size);
	Matrix(const Matrix& other);
	~Matrix();

	friend std::ostream& operator << (std::ostream& os, Matrix& cc);
	friend std::fstream& operator << (std::fstream& ofs, Matrix& cc);
	friend std::istream& operator >> (std::istream& is, Matrix& cc);
	friend std::fstream& operator >> (std::fstream& ifs, Matrix& cc);

	void ReadFromFile(std::fstream& file);

	void WriteToBinFile(std::fstream& file); // Writing from binary file

	void ReadFromBinFile(std::fstream& file); // Reading from binary file

	void PushMatrix(); // Function that fills a matrix with random numbers

	char* ToString(); // Friendly function that returns a matrix as a string

	void operator()(int x, int y, int data);
	int GetSize(); // Getter of size

	int* operator[](int i) { return matrix[i]; };
	int*& operator[](int i) const { return matrix[i]; };

	Matrix& operator=(const Matrix& other); // Operator for assigning
	friend Matrix& operator+(Matrix& first, const Matrix& second); // Friendly operator for addition
	friend Matrix& operator-(Matrix& first, const Matrix& second); // Friendly operator for subtraction

private:
	int size;
	int** matrix;
};

#endif