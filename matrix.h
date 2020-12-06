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

	void WriteToFile(char* path, std::fstream& file); // Writing from file

	void ReadFromFile(char* path, std::fstream& file); // Reading from file

	void WriteToBinFile(char* path, std::fstream& file); // Writing from binary file

	void ReadFromBinFile(char* path, std::fstream& file); // Reading from binary file

	void PushMatrix(); // Function that fills a matrix with random numbers

	char* ToString(Matrix& cc); // Friendly function that returns a matrix as a string

	int& operator()(int x, int y); // Getter

	int GetSize(); // Getter of size

	void operator()(int x, int y, int data); // Setter

	Matrix& operator=(const Matrix& other); // Operator for assigning

	friend Matrix& operator+(Matrix& first, const Matrix& second); // Friendly operator for addition

	friend Matrix& operator-(Matrix& first, const Matrix& second); // Friendly operator for subtraction

private:
	int size;
	int** matrix;
};

#endif