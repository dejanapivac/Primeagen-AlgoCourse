#include <iostream>
#include <queue>

using namespace std;

// koristi se kada ne znamo tocno tip podatka koji cemo koristit
template<typename T>
struct Node {
    T value;
    Node<T>* next;
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

    void enqueue(T item) {
        length++;
        Node<T> *newNode = new Node<T>();
        newNode -> value = item;
        newNode -> next = NULL;
        if(head == NULL){
            head = tail = newNode;
        } else {
            tail -> next = newNode;
            tail = newNode;
        };
    }

    T deque() {
        if(!head) {
            return 0;
        }
        length--;

        Node<T>* temp = head;
        head = head -> next;
        //T value = temp ->value; ako zelim sacuvati prijasnju vrijednost heada
        delete(temp); // moram jer nemam GC
        return head -> value;
    }

    T peek() {
        if(!head) {
            return 0;
        }
        // Ako head nije null vrati mi vrijednost koju on ima u sebi
        return head -> value;
    }

};