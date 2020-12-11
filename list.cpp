#include "list.h"

List::List()
{
    Head = Tail = NULL;
    Count = 0;
}

List::List(const List& L)
{
    Head = Tail = NULL;
    Count = 0;

    Elem* temp = L.Head;
    while (temp != 0)
    {
        AddTail(*(temp->data));
        temp = temp->next;
    }
}

List::~List()
{
    while (Count != 0)
        Del(1);
}

void List::AddHead(Matrix& n)
{
    Elem* temp = new Elem;
    temp->prev = 0;
    temp->data = &n;
    temp->next = Head;

    // Если элементы есть?
    if (Head != 0)
        Head->prev = temp;
    // Если элемент первый, то он одновременно и голова и хвост
    if (Count == 0)
        Head = Tail = temp;
    else   // иначе новый элемент - головной
        Head = temp;

    Head->prev = Tail;
    Count++;
}

void List::AddTail(Matrix& n)
{
    Elem* temp = new Elem;
    temp->next = 0;
    temp->data = &n;
    temp->prev = Tail;

    // Если элементы есть?
    if (Tail != 0)
        Tail->next = temp;
    // Если элемент первый, то он одновременно и голова и хвост
    if (Count == 0)
        Head = Tail = temp;
    else // иначе новый элемент - хвостовой
        Tail = temp;

    //Tail->next = Head;
    Count++;
}

void List::Insert(Matrix& n, int pos)
{
    if (pos == 0)
    {
        std::cout << "Input position: ";
        std::cin >> pos;
    }

    if (pos < 1 || pos > Count + 1)
    {
        std::cout << "Incorrect position...\n";
        return;
    }

    if (pos == Count + 1)
    {
        AddTail(n);
        return;
    }
    else if (pos == 1)
    {
        AddHead(n);
        return;
    }

    // Счетчик
    int i = 1;
    Elem* Ins = Head;

    while (i < pos)
    {
        Ins = Ins->next;
        i++;
    }

    Elem* PrevIns = Ins->prev;
    Elem* temp = new Elem;

    temp->data = &n;

    if (PrevIns != 0 && Count != 1)
        PrevIns->next = temp;

    temp->next = Ins;
    temp->prev = PrevIns;
    Ins->prev = temp;

    Count++;
}

void List::Del(int pos)
{
    // если параметр отсутствует или равен 0, то запрашиваем его
    if (pos == 0)
    {
        std::cout << "Input position: ";
        std::cin >> pos;
    }
    if (pos < 1 || pos > Count)
    {
        std::cout << "Incorrect position...\n";
        return;
    }

    // Счетчик
    int i = 1;

    Elem* Del = Head;

    while (i < pos)
    {
        Del = Del->next;
        i++;
    }

    Elem* PrevDel = Del->prev;
    Elem* AfterDel = Del->next;

    if (PrevDel != 0 && Count != 1)
        PrevDel->next = AfterDel;

    if (AfterDel != 0 && Count != 1)
        AfterDel->prev = PrevDel;

    if (pos == 1)
        Head = AfterDel;
    if (pos == Count)
        Tail = PrevDel;

    delete Del;

    Count--;
}

void List::Print(int pos)
{
    if (pos < 1 || pos > Count)
    {
        std::cout << "Incorrect position...\n";
        return;
    }

    Elem* temp;

    if (pos <= Count / 2)
    {
        temp = Head;
        int i = 1;

        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
    }
    else
    {
        temp = Tail;
        int i = 1;

        while (i <= Count - pos)
        {
            temp = temp->prev;
            i++;
        }
    }
    std::cout << pos << " element: " << std::endl;;
    std::cout << *(temp->data) << std::endl;
}

void List::Print()
{
    if (Count != 0)
    {
        Elem* temp = Head;
        while (temp->next != Tail->next)
        {
            std::cout << *(temp->data) << std::endl;
            temp = temp->next;
        }
        std::cout << *(temp->data) << std::endl;
    }
}

int List::GetCount()
{
    return Count;
}

Elem* List::GetElem(int pos)
{
    Elem* temp = Head;

    if (pos < 1 || pos > Count)
    {
        std::cout << "Incorrect position...\n";
        return 0;
    }

    int i = 1;
    // Ищем нужный нам элемент
    while (i < pos && temp != 0)
    {
        temp = temp->next;
        i++;
    }

    if (temp == 0)
        return 0;
    else
        return temp;
}