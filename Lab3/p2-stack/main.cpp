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
class Stack
{
private:
    Node<T>* pHead;

public:
    Stack()
    {
        pHead = nullptr;
    }

    // Copy constructor
    Stack(const Stack& oldStack)
    {
        pHead = nullptr;

        // Create a temporary stack to reverse the order
        Stack<T> tempStack;

        Node<T>* current = oldStack.pHead;
        while (current != nullptr)
        {
            tempStack.Push(current->Data);
            current = current->pNext;
        }

        // Pop elements from the temporary stack to create a reversed copy
        while (!tempStack.IsEmpty())
        {
            Push(tempStack.Pop());
        }
    }

    ~Stack()
    {
        ClearStack();
    }

    void Push(T data)
    {
        Node<T>* newNode = new Node<T>(data);

        if (pHead == nullptr)
        {
            pHead = newNode;
        }
        else
        {
            newNode->pNext = pHead;
            pHead = newNode;
        }
    }

    T Pop()
    {
        if (IsEmpty())
        {
            cout << "Stack is empty. Cannot pop.\n";
            return T(); // Return a default value for simplicity
        }

        T topData = pHead->Data;
        Node<T>* temp = pHead;
        pHead = pHead->pNext;
        delete temp;

        return topData;
    }

    bool IsEmpty()
    {
        return pHead == nullptr;
    }

    void ClearStack()
    {
        Node<T>* current = pHead;
        Node<T>* next;

        while (current != nullptr)
        {
            next = current->pNext;
            delete current;
            current = next;
        }

        pHead = nullptr;
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
};

int main()
{
    Stack<int> myStack;

    myStack.Push(1);
    myStack.Push(2);
    myStack.Push(3);

    cout << "Stack after push operations: ";
    myStack.Display();

    cout << "Pop operation. Popped element: " << myStack.Pop() << endl;
    cout << "Stack after pop operation: ";
    myStack.Display();

    myStack.Push(4);
    cout << "Push operation. Stack after push: ";
    myStack.Display();

    // Creating a new stack using the copy constructor
    Stack<int> newStack(myStack);
    cout << "New stack created using the copy constructor: ";
    newStack.Display();

    return 0;
}
