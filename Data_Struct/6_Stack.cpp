#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>
struct Node {
    T value;
    Node<T> *prev;
};

template<typename T>
class Stack {
private:
    Node<T> *head;
public:
    int length;

    Stack() {
        head = NULL;
        length = 0;
    }

    void push(T item) {
        Node<T> *newNode = new Node<T>;
        newNode->value = item;
        length++;
        if (!head) {
            head = newNode;
            newNode -> prev = nullptr;
        }
        newNode->prev = head;
        head = newNode;
    }

    T pop() {
        length = max(0, length-1);
        if(length == 0) {
            T temp = head -> value;
            head = nullptr;
            return 0;
        }
        T poppedValue = head -> value;
        Node<T>* temp = head;
        head = head -> prev;
        delete temp;
        return poppedValue;
    }

    T peek() {
        return !head ? 0 : head->value;
    }
};

int main() {

    Stack<int> s;
    s.push(11);
    s.push(22);
    s.push(33);
    s.push(44);

    cout<<s.length<<endl;
    cout<<s.peek()<<endl;

    s.pop();
    s.pop();
    s.pop();
    s.pop();


    cout<<s.length<<endl;
    cout<<s.peek()<<endl;

    return 0;
}