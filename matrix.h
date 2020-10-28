#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
public:

	// Constructors and destructor

	Matrix(int size);

	Matrix(const Matrix& other);

	~Matrix();

	friend std::ostream& operator << (std::ostream& os, Matrix& cc);

	friend std::ofstream& operator << (std::ofstream& ofs, Matrix& cc);

	friend std::istream& operator >> (std::istream& is, Matrix& cc);

	friend std::ifstream& operator >> (std::ifstream& ifs, Matrix& cc);

	friend void WriteToFile(Matrix& obj); // Writing from file

	friend void ReadFromFile(Matrix& obj,const int objPosition); // Reading from file

	friend void WriteToBinFile(Matrix& obj); // Writing from binary file

	friend void ReadFromBinFile(Matrix& obj, const int objPosition); // Reading from binary file

	void PushMatrix(); // Function that fills a matrix with random numbers

	char* ToString(Matrix& cc); // Friendly function that returns a matrix as a string

	int& operator()(int x, int y); // Getter

	int GetSize(); // Getter of size

	void operator()(int x, int y, int data); // Setter

	Matrix& operator=(const Matrix& other); // Operator for assigning

	friend Matrix& operator+(Matrix& first, const Matrix& second); // Friendly operator for addition

	friend Matrix& operator-(Matrix& first, const Matrix& second); // Friendly operator for subtraction

private:
	int ID;
	int size;
	int** matrix;
};

#endif