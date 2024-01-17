#include <iostream>
using namespace std;

template<class T>
class Node
{
public:
    T Data;
    Node<T>* pNext;
    Node<T>* pPrev;

    Node<T>()
    {
        Data = T();
        pNext = nullptr;
        pPrev = nullptr;
    }

    Node<T>(T d)
    {
        Data = d;
        pNext = nullptr;
        pPrev = nullptr;
    }

    ~Node<T>() {}
};

template<class T>
class LinkedList
{
public:
    Node<T>* pHead;
    Node<T>* pTail;
    int listSize;

    LinkedList()
    {
        pHead = nullptr;
        pTail = nullptr;
        listSize = 0;
    }

    LinkedList(const LinkedList &oldList)
    {
        pHead = pTail = nullptr;
        listSize = 0;

        Node<T>* current = oldList.pHead;
        while (current != nullptr)
        {
            AddLast(current->Data);
            current = current->pNext;
        }
    }

    ~LinkedList()
    {
        ClearList();
    }

    void AddFirst(T data)
    {
        Node<T>* newNode = new Node<T>(data);

        if (pHead == nullptr)
        {
            pHead = pTail = newNode;
        }
        else
        {
            newNode->pNext = pHead;
            pHead->pPrev = newNode;
            pHead = newNode;
        }

        listSize++;
    }

    void AddLast(T data)
    {
        Node<T>* newNode = new Node<T>(data);

        if (pHead == nullptr)
        {
            pHead = pTail = newNode;
        }
        else
        {
            newNode->pPrev = pTail;
            pTail->pNext = newNode;
            pTail = newNode;
        }

        listSize++;
    }

    void InsertAtPosition(T data, int position)
    {
        if (position < 0 || position > listSize)
        {
            cout << "Invalid position.\n";
            return;
        }

        Node<T>* newNode = new Node<T>(data);

        if (position == 0)
        {
            newNode->pNext = pHead;
            if (pHead != nullptr)
            {
                pHead->pPrev = newNode;
            }
            pHead = newNode;
        }
        else
        {
            Node<T>* current = pHead;
            for (int i = 0; i < position - 1; ++i)
            {
                current = current->pNext;
            }

            newNode->pNext = current->pNext;
            newNode->pPrev = current;
            if (current->pNext != nullptr)
            {
                current->pNext->pPrev = newNode;
            }
            else
            {
                pTail = newNode;
            }

            current->pNext = newNode;
        }

        listSize++;
    }

    void Display()
    {
        Node<T>* current = pHead;

        while (current != nullptr)
        {
            cout << current->Data << " ";
            current = current->pNext;
        }

        cout << endl;
    }

    void ClearList()
    {
        Node<T>* current = pHead;
        Node<T>* next;

        while (current != nullptr)
        {
            next = current->pNext;
            delete current;
            current = next;
        }

        pHead = pTail = nullptr;
        listSize = 0;
    }

    bool IsEmpty() const
    {
        return listSize == 0;
    }

    Node<T>* Search(T target)
    {
        Node<T>* current = pHead;

        while (current != nullptr)
        {
            if (current->Data == target)
            {
                return current;
            }
            current = current->pNext;
        }

        return nullptr;
    }

void DeleteNode(int position)
{
    if (position < 0 || position >= listSize)
    {
        cout << "Invalid position.\n";
        return;
    }

    Node<T>* current = pHead;

    for (int i = 0; i < position; ++i)
    {
        current = current->pNext;
    }

    if (current->pPrev != nullptr)
    {
        current->pPrev->pNext = current->pNext;
    }
    else
    {
        pHead = current->pNext;
    }

    if (current->pNext != nullptr)
    {
        current->pNext->pPrev = current->pPrev;
    }
    else
    {
        pTail = current->pPrev;
    }

    delete current;
    listSize--;
}

    void DeleteFirst()
    {
        if (pHead != nullptr)
        {
            Node<T>* temp = pHead;
            pHead = pHead->pNext;

            if (pHead != nullptr)
            {
                pHead->pPrev = nullptr;
            }
            else
            {
                pTail = nullptr;
            }

            delete temp;
            listSize--;
        }
    }

    void DeleteLast()
    {
        if (pTail != nullptr)
        {
            Node<T>* temp = pTail;
            pTail = pTail->pPrev;

            if (pTail != nullptr)
            {
                pTail->pNext = nullptr;
            }
            else
            {
                pHead = nullptr;
            }

            delete temp;
            listSize--;
        }
    }
};

int main()
{
    LinkedList<int> myList;

    myList.AddFirst(1);
    myList.AddLast(2);
    myList.AddLast(3);

    cout << "List after adding elements: ";
    myList.Display();

    cout << "Is the list empty? " << (myList.IsEmpty() ? "Yes" : "No") << endl;

    int searchValue = 2;
    Node<int>* searchResult = myList.Search(searchValue);
    if(searchResult)
    {
        cout << "Search result for " << searchValue << ": " << (searchResult->Data) << endl;
    }
    else
    {
        cout << "Search result for " << searchValue << ": " << "not found" << endl;
    }
    int deletePosition = 2;
    cout << "Deleting " << deletePosition << " from the list." << endl;
    myList.DeleteNode(deletePosition);
    cout << "List after deletion: ";
    myList.Display();

    int insertValue = 5;
    cout << "Inserting " << insertValue << " at the beginning of the list." << endl;
    myList.AddFirst(insertValue);
    cout << "List after insertion at the beginning: ";
    myList.Display();

    insertValue = 8;
    cout << "Inserting " << insertValue << " at the end of the list." << endl;
    myList.AddLast(insertValue);
    cout << "List after insertion at the end: ";
    myList.Display();

    cout << "Deleting the first node." << endl;
    myList.DeleteFirst();
    cout << "List after deleting the first node: ";
    myList.Display();

    cout << "Deleting the last node." << endl;
    myList.DeleteLast();
    cout << "List after deleting the last node: ";
    myList.Display();

    // Creating a new list using the copy constructor
    LinkedList<int> newList(myList);
    cout << "New list created using the copy constructor: ";
    newList.Display();

    myList.ClearList();
    cout << "Is the list empty now? " << (myList.IsEmpty() ? "Yes" : "No") << endl;

    return 0;
}
