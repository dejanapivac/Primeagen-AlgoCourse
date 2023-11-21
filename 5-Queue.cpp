#include <iostream>

using namespace std;

template<typename T>
struct Node {
    T value;
    Node<T> *next;
};

template<typename T>
class Queue {
private:
    Node<T> *head, *tail;
public:
    int length;

    Queue() {
        head = tail = NULL;
        length = 0;
    }

    void enqueue(T input) {
        length++;
        Node<T> newNode = new Node<T>();
        newNode -> value = input;
        newNode . next = NULL;
        if(!head) {
            head = tail = newNode;
        } else {
            tail -> next = newNode;
            tail = newNode;
        }
    }

    T dequeue() {
        if(!head) {
            return 0;
        }

        length--;
        Node<T> *temp = head;
        head = head -> next;
        T value = temp->value;
        delete temp;
        return value;
    }

    //vrati element na pocetku reda
    T peek() {
        return !head ? 0 : head -> value;
    }
};

int main() {

    return 0;
}