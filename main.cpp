#include <iostream>
#include <stack>
#include <set>
#include <ctime>
#include <iterator>
#include "matrix.h"
using namespace std;


int main() {
    setlocale(LC_ALL, "rus");

    unsigned start_t, end_t;
    unsigned int n = 1024;

    Matrix* p;
    p = new Matrix[n];

    //----------------------------------------------------------//

    stack <Matrix> matrixStack;

    cout << "--------------- Стек с матрицами(matrix) ---------------" << endl;

    start_t = clock();
    cout << "Добавление случайных значений(matrix) в стек " << n << endl;
    for (int i = 0; i < n; i++) {
        matrixStack.push(p[i]);
    }
    end_t = clock() - start_t;
    cout << "Время добавление в стек: " << end_t << endl << endl;

    cout << "Удаление последнего элемента(matirx) в стеке" << endl;
    start_t = clock();
    matrixStack.pop();
    end_t = clock() - start_t;
    cout << "Время удаления элемента: " << end_t << endl << endl;

    //----------------------------------------------------------//

    stack <int> intStack;

    cout << "--------------- Стек с числами(int) ---------------" << endl;

    start_t = clock();
    cout << "Добавление случайных значений(int) в стек " << n << endl;
    for (int i = 0; i < n; i++) {
        int random = rand() % 10 + 1;
        intStack.push(random);
    }
    end_t = clock() - start_t;
    cout << "Время добавление в стек: " << end_t << endl << endl;

    cout << "Удаление последнего элемента в стеке" << endl;
    start_t = clock();
    intStack.pop();
    end_t = clock() - start_t;
    cout << "Время удаления элемента: " << end_t << endl << endl;

    //----------------------------------------------------------//

    multiset <int> Multiset;
    multiset <int> ::iterator it1;

    cout << "--------------- Мультимножество с числами(int) ---------------" << endl;

    start_t = clock();
    cout << "Добавление случайных значений " << n <<endl;
    for (int i = 0; i < n; i++) {
        int random = rand() % 10 + 1;
        Multiset.insert(random);
    }
    end_t = clock() - start_t;
    cout << "Время добавление элементов: " << end_t << endl << endl;

    cout << "Удаление всех элементов с ключом '10'" << endl;
    start_t = clock();
    Multiset.erase(10);
    end_t = clock() - start_t;
    cout << "Время удаления элементов: " << end_t << endl << endl;

    cout << "Поиск элемента с ключом '5'" << endl;
    start_t = clock();
    it1 = Multiset.find(5);
    end_t = clock() - start_t;
    cout << "Время поиска элемента с ключом '5': " << end_t << endl << endl;

    //----------------------------------------------------------//

    multiset <float> floatMultiset;
    multiset <float> ::iterator it2;

    cout << "--------------- Мультимножество с числами(float) ---------------" << endl;

    start_t = clock();
    cout << "Добавление случайных значений " << n << endl;
    for (int i = 0; i < n; i++) {
        int random = rand() % 10 + 1;
        floatMultiset.insert(random);
    }
    end_t = clock() - start_t;
    cout << "Время добавление элементов: " << end_t << endl << endl;

    cout << "Удаление всех элементов с ключом '10'" << endl;
    start_t = clock();
    floatMultiset.erase(10);
    end_t = clock() - start_t;
    cout << "Время удаления элементов: " << end_t << endl << endl;

    cout << "Поиск элемента с ключом '5'" << endl;
    start_t = clock();
    it2 = floatMultiset.find(5);
    end_t = clock() - start_t;
    cout << "Время поиска элемента с ключом '5': " << end_t << endl << endl;

    //----------------------------------------------------------//

    start_t = clock();
    while (!matrixStack.empty()) {
        matrixStack.pop();
    }
    end_t = clock() - start_t;
    cout << "Удаление стека с матрицами: " << end_t << endl;

    start_t = clock();
    while (!intStack.empty()) {
        intStack.pop();
    }
    end_t = clock() - start_t;
    cout << "Удаление стека с числами: " << end_t << endl;

    start_t = clock();
    Multiset.clear();
    end_t = clock() - start_t;
    cout << "Удаление мультимножества c числами: " << end_t << endl;

    start_t = clock();
    floatMultiset.clear();
    end_t = clock() - start_t;
    cout << "Удаление мультимножества c вещественными числами: " << end_t << endl;

    system("pause");
    return 0;
}