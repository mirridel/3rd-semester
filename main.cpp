#include <iostream>
#include <fstream>
#include "matrix.h"
#include "test.h"

using std::cout;
using std::cin;
using std::endl;

//------ Вариант #4 ------

void test();

int main()
{
	test();

	Matrix m1(3), m2(3);

	std::fstream File("text.txt", std::ios_base::out | std::ios_base::in);
	std::fstream BinFile("file.dat", std::ios_base::out | std::ios_base::in | std::ios_base::binary);

	cout << "Original matrices x1:" << endl;
	m1.PushMatrix();
	cout << m1 << endl;
	m2.PushMatrix();
	cout << m2 << endl;

	File << m1;
    m2.WriteToBinFile(BinFile);

	m1 = m1 + m2;
	cout << "m1 = m1 + m2:" << endl;
	cout << m1 << endl;

	cout << "Reading from file:" << endl;
	File >> m1;
	m2.ReadFromBinFile(BinFile);

	cout << "Original matrices x2:" << endl;
	cout << m1 << endl;
	cout << m2 << endl;

	m2 = m2 - m1;
	cout << "m2 = m2 - m1:" << endl;
	cout << m2 << endl;

	cout << "Reading from file:" << endl;
	File >> m1;
	m2.ReadFromBinFile(BinFile);

	cout << "Original matrices x3:" << endl;
	cout << m1 << endl;
	cout << m2 << endl;

	return 0;
};

void test()
{
	if (test1())
		cout << "Test passed #1 (+)..." << endl;
	else cout << "Test failed #1 (+)..." << endl;
	if (test2())
		cout << "Test passed #2 (-)..." << endl;
	else cout << "Test failed #2 (-)..." << endl;
	if (test3())
		cout << "Test passed #3 (=)..." << endl;
	else cout << "Test failed #3 (=)..." << endl;
}