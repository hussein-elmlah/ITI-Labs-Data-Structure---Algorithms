#include <iostream>
using namespace std;

template<class T>
class Node
{
public:
    T Data;
    Node<T>* pNext;

    Node<T>()
    {
        Data = T();
        pNext = nullptr;
    }

    Node<T>(T d)
    {
        Data = d;
        pNext = nullptr;
    }

    ~Node<T>() {}
};

template<class T>
class Queue
{
private:
    Node<T>* pHead;
    Node<T>* pTail;

public:
    Queue()
    {
        pHead = pTail = nullptr;
    }

    // Copy constructor
    Queue(const Queue& oldQueue)
    {
        pHead = pTail = nullptr;
        Node<T>* current = oldQueue.pHead;

        while (current != nullptr)
        {
            Enqueue(current->Data);
            current = current->pNext;
        }
    }

    ~Queue()
    {
        ClearQueue();
    }
    void Enqueue(T data)
    {
        Node<T>* newNode = new Node<T>(data);

        if (IsEmpty())
        {
            pHead = pTail = newNode;
        }
        else
        {
            pTail->pNext = newNode;
            pTail = newNode;
        }
    }

    T Dequeue()
    {
        if (IsEmpty())
        {
            cout << "Queue is empty. Cannot dequeue.\n";
            return T(); // Return a default value for simplicity
        }

        T frontData = pHead->Data;
        Node<T>* temp = pHead;

        if (pHead == pTail)
        {
            // Only one element in the queue
            pHead = pTail = nullptr;
        }
        else
        {
            pHead = pHead->pNext;
        }

        delete temp;
        return frontData;
    }


    bool IsEmpty() const
    {
        return pHead == nullptr;
    }

    void ClearQueue()
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
    }

    void Display() const
    {
        Node<T>* current = pHead;

        while (current != nullptr)
        {
            cout << current->Data << " ";
            current = current->pNext;
        }

        cout << endl;
    }
};

int main()
{
    Queue<int> myQueue;

    myQueue.Enqueue(1);
    myQueue.Enqueue(2);
    myQueue.Enqueue(3);

    cout << "Queue after enqueue operations: ";
    myQueue.Display();

    // Creating a new queue using the copy constructor
    Queue<int> newQueue(myQueue);
    cout << "New queue created using the copy constructor: ";
    newQueue.Display();

    cout << "Dequeue operation. Dequeued element: " << myQueue.Dequeue() << endl;
    cout << "Queue after dequeue operation: ";
    myQueue.Display();

    myQueue.Enqueue(4);
    cout << "Enqueue operation. Queue after enqueue: ";
    myQueue.Display();

    return 0;
}
