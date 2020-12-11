#include "list.h"

template <class DataT>
List<DataT>::List() {
    Head = Tail = NULL;
    Count = 0;
};

template <class DataT>
List<DataT>::List(const List& L)
{
    Head = Tail = NULL;
    Count = 0;

    Elem<DataT>* temp = L.Head;
    while (temp != 0)
    {
        AddTail(*(temp->data));
        temp = temp->next;
    }
}

template <class DataT>
List<DataT>::~List()
{
    while (Count != 0)
        Del(1);
}

template<class DataT>
void List<DataT>::AddHead(DataT& n)
{
    Elem<DataT>* temp = new Elem<DataT>;
    temp->prev = 0;
    temp->data = &n;
    temp->next = Head;

    // ���� �������� ����?
    if (Head != 0)
        Head->prev = temp;
    // ���� ������� ������, �� �� ������������ � ������ � �����
    if (Count == 0)
        Head = Tail = temp;
    else   // ����� ����� ������� - ��������
        Head = temp;

    Head->prev = Tail;
    Count++;
}

template<class DataT>
void List<DataT>::AddTail(DataT& n)
{
    Elem<DataT>* temp = new Elem<DataT>;
    temp->next = 0;
    temp->data = &n;
    temp->prev = Tail;

    // ���� �������� ����?
    if (Tail != 0)
        Tail->next = temp;
    // ���� ������� ������, �� �� ������������ � ������ � �����
    if (Count == 0)
        Head = Tail = temp;
    else // ����� ����� ������� - ���������
        Tail = temp;

    //Tail->next = Head;
    Count++;
}

template<class DataT>
void List<DataT>::Insert(DataT& n, int pos)
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

    // �������
    int i = 1;
    Elem<DataT>* Ins = Head;

    while (i < pos)
    {
        Ins = Ins->next;
        i++;
    }

    Elem<DataT>* PrevIns = Ins->prev;
    Elem<DataT>* temp = new Elem<DataT>;

    temp->data = &n;

    if (PrevIns != 0 && Count != 1)
        PrevIns->next = temp;

    temp->next = Ins;
    temp->prev = PrevIns;
    Ins->prev = temp;

    Count++;
}

template<class DataT>
void List<DataT>::Del(int pos)
{
    // ���� �������� ����������� ��� ����� 0, �� ����������� ���
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

    // �������
    int i = 1;

    Elem<DataT>* Del = Head;

    while (i < pos)
    {
        Del = Del->next;
        i++;
    }

    Elem<DataT>* PrevDel = Del->prev;
    Elem<DataT>* AfterDel = Del->next;

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

template<class DataT>
void List<DataT>::Print(int pos)
{
    if (pos < 1 || pos > Count)
    {
        std::cout << "Incorrect position...\n";
        return;
    }

    Elem<DataT>* temp;

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

template<class DataT>
void List<DataT>::Print()
{
    if (Count != 0)
    {
        Elem<DataT>* temp = Head;
        while (temp->next != Tail->next)
        {
            std::cout << *(temp->data) << std::endl;
            temp = temp->next;
        }
        std::cout << *(temp->data) << std::endl;
    }
}

template<class DataT>
int List<DataT>::GetCount()
{
    return Count;
}

