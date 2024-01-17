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

    LinkedList(LinkedList &OldList)
    {
        Node<T>* current = OldList.pHead;
        while(current != nullptr)
        {
            this.Add(current->Data);
            current = current->pNext;
        }
    }


    ~LinkedList()
    {
        ClearList();
    }

    void Add(T data)
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

    void Delete(T value)
    {
        Node<T>* current = pHead;

        while (current != nullptr)
        {
            if (current->Data == value)
            {
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
                return;
            }
            current = current->pNext;
        }
    }

};

int main()
{
    LinkedList<int> myList;

    myList.Add(1);
    myList.Add(2);
    myList.Add(3);

    cout << "List after adding elements: ";
    myList.Display();

    cout << "Is the list empty? " << (myList.IsEmpty() ? "Yes" : "No") << endl;

    int searchValue = 2;
    cout << "Is " << searchValue << " in the list? " << (myList.Search(searchValue) ? "Yes" : "No") << endl;

    int deleteValue = 2;
    cout << "Deleting " << deleteValue << " from the list." << endl;
    myList.Delete(deleteValue);
    cout << "List after deletion: ";
    myList.Display();

    Node<int>* afterNode = myList.pHead;
    int insertValue = 5;
    cout << "Inserting " << insertValue << " after the first node." << endl;

    myList.Display();

    int insertPosition = 1;
    insertValue = 8;
    cout << "Inserting " << insertValue << " at position " << insertPosition << "." << endl;
    myList.InsertAtPosition(insertValue, insertPosition);
    cout << "List after insertion at position: ";
    myList.Display();

    myList.ClearList();
    cout << "Is the list empty now? " << (myList.IsEmpty() ? "Yes" : "No") << endl;

    return 0;
}
