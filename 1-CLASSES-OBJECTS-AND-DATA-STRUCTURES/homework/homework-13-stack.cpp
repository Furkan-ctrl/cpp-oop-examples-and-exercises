#include "LinkedList.h"
#include "iostream"

using namespace std;

/*
    Definition of Stack:

    A stack is a linear data structure that follows the Last-In-First-Out (LIFO) principle. 
    It is an abstract data type with a collection of elements in which elements are added and removed from only one end, 
    known as the "top" of the stack.

    In a stack, the element that is added last is the first one to be removed. 
    This behavior is similar to a stack of objects, where you can only add or remove items from the top of the stack. 
    Due to its LIFO nature, a stack can be visualized as a vertical stack of items, where you can only access the topmost item.

    The two primary operations performed on a stack are:
    1. Push: Adds an element to the top of the stack.
    2. Pop: Removes and returns the topmost element from the stack.

    Other common operations associated with a stack include:
    - Peek or Top: Retrieves the value of the topmost element without removing it.
    - Size: Returns the number of elements currently in the stack.
    - isEmpty: Checks if the stack is empty.

    Stacks are widely used in various computer science applications, such as expression evaluation, 
    function call management, undo/redo functionality, backtracking algorithms, memory management, and more. 
    The simplicity and efficiency of stacks make them an essential data structure in many programming scenarios.
*/

/*
    Exercise:

    1. Once the "LinkedList" class is implemented and tested, use it to build the "LinkedListStack" class. 

    2. Define a class called "LinkedListStack" that represents the stack using a linked list. 
    The class should have a private member to store the top node pointer.

    3. Implement a constructor for the LinkedListStack class that initializes the top pointer to nullptr, indicating an empty stack.

    4. Implement a member function in the LinkedListStack class called "push", 
    which takes a value as a parameter and pushes (inserts) that value onto the top of the stack.

    5. Add a "getHead" member function to the "LinkedList" class, which returns the head node pointer.

    6. Implement a member function in the LinkedListStack class called "pop", 
    which removes and returns the value from the top of the stack. 
    If the stack is empty, return a special value or throw an exception to indicate an underflow condition.

    7. Implement a member function in the LinkedListStack class called "peek", 
    which returns the value from the top of the stack without removing it. 
    If the stack is empty, return a special value or throw an exception to indicate an underflow condition.

    8. Implement a member function in the LinkedListStack class called "isEmpty", 
    which checks if the stack is empty and returns a boolean value accordingly.

    9. Implement a member function in the LinkedListStack class called "size", which returns the number of elements currently in the stack.
    
    10. Implement a "destructor" for the LinkedListStack class that deletes all the nodes in the stack.

    11. Test your implementation by creating an instance of the LinkedListStack class, pushing several values onto the stack, 
    and then performing pop, peek, isEmpty, size, and destructor operations to verify the correctness of the stack behavior.

    [Stack use cases]: https://www.enjoyalgorithms.com/blog/application-of-stack-data-structure-in-programming
*/


/*  Solution  */
class LinkedListStack {
private:
    LinkedList list; 

public:
    LinkedListStack() {}

    LinkedListStack& push(int value) {
        list.insert(value);
        return *this;
    }

    LinkedListStack& pop() {
        if (isEmpty()) {
            cout << "Nothing to pop" << endl;
            return *this;
        }
        list.removeFirst();
        return *this;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Nothing to peek" << endl;
            return;
        }
        Node* topNode = list.getHead();
        cout << "Peek: [" << topNode->data << " | " << topNode->next << "]" << endl;
    }

    bool isEmpty(){
        return list.getHead() == nullptr;
    }

    int size() const {
        int count = 0;
        Node* current = list.getHead();
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    LinkedListStack& displayStack() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return *this;
        }
        cout << "Display Stack: ";
        Node* current = list.getHead();
        while (current != nullptr) {
            cout << "[" << current->data << " | " << current->next << "]";
            if (current->next != nullptr) {
                cout << " ---> ";
            }
            current = current->next;
        }
        cout << " " << endl;
        return *this;
    }

    ~LinkedListStack() {
        cout << "Start Stack Deallocation:" << endl;
        cout << " -Destructor: " << endl;
        
        int elementsDeleted = 0;
        Node* current = list.getHead();
        while (current != nullptr) {
            elementsDeleted++;
            current = current->next;
        }
        
        for (int i = 0; i < elementsDeleted; i++) {
            cout << "    delete on " << i << endl;
        }
        cout << "End of Stack Deallocation" << endl;
    }
};



int main() {

    /*      Example usage:     */
    LinkedListStack stack;

    stack.peek();

    stack.push(1).push(2).push(3).push(4).push(5);

    cout << "Size: " << stack.size() << endl << endl;

    stack.displayStack();
    stack.pop();
    stack.displayStack();

    cout << endl;
    stack.peek();
    cout << endl;

    stack.pop().pop().pop().pop().pop();

    stack.displayStack();


    /*  
        Example Output: 
        
        Nothing to peek (^_^)
        Size: 5

        Display Stack: [5 | 0x7ff5cf705a70] ---> [4 | 0x7ff5cf705ca0] ---> [3 | 0x7ff5cf705c90] ---> [2 | 0x7ff5cf705c80] ---> [1 | 0x0] 
        Display Stack: [4 | 0x7ff5cf705ca0] ---> [3 | 0x7ff5cf705c90] ---> [2 | 0x7ff5cf705c80] ---> [1 | 0x0] 

        Peek: [4 | 0x7ff5cf705ca0]

        Nothing to pop (^_^)
        Stack is empty!

        Start Stack Deallocation:
         -Destructor: 
            delete on 0
        End of Stack Deallocation
    */

    
    return 0;
}