#include <iostream>
#include "matrix.h"
#include "test.h"

using std::cout;
using std::cin;
using std::endl;

//------ Вариант #4 ------

int main()
{
	bool T = test();
	if (T)
		cout << "Test passed...\n" << endl;
	else cout << "Test failed...\n" << endl;

	Matrix m1(3), m2(3);

	cout << "Original matrices x1:" << endl;
	m1.PushMatrix();
	cout << m1 << endl;
	m2.PushMatrix();
	cout << m2 << endl;

	//WriteToFile(m1);
	//WriteToFile(m2);
	//WriteToBinFile(m1);
	//WriteToBinFile(m2);

	cout << "Enter an arbitrary matrix:" << endl;
	cin >> m2;
	cout << m2 << endl;

	m1 = m1 + m2;
	cout << "m1 = m1 + m2:" << endl;
	cout << m1 << endl;

	cout << "Reading from file:" << endl;
	ReadFromFile(m1, 1);
	ReadFromFile(m2, 2);
	cout << endl;

	cout << "Original matrices x2:" << endl;
	cout << m1 << endl;
	cout << m2 << endl;

	m2 = m2 - m1;
	cout << "m2 = m2 - m1:" << endl;
	cout << m2 << endl;

	cout << "Reading from binary file:" << endl;
	ReadFromBinFile(m1, 1);
	ReadFromBinFile(m2, 2);
	cout << endl;

	cout << "Original matrices x3:" << endl;
	cout << m1 << endl;
	cout << m2 << endl;

	return 0;
};