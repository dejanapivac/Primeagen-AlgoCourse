#include <iostream>
using namespace std;

template<typename T>
struct Node {
    T value;
    Node<T> *prev, *next;
};

template<typename T>
class DoublyLinkedList {
private:
    Node<T> *head, *tail;
public:
    int length;

    DoublyLinkedList(){
        length = 0;
        head = tail = NULL;
    }

    void prepend(T value){
        Node<T> *newNode = new Node<T>;
        newNode -> value = value;
        length++;

        if(!head) {
            head = tail = newNode;
        }

        head -> prev = newNode;
        newNode -> next = head;
        head = newNode;
    }

    void append(T value) {
        Node<T> *newNode = new Node<T>;
        newNode -> value = value;
        length++;

        if(!tail) {
            head = tail = newNode;
        }

        tail -> next = newNode;
        newNode -> prev = tail;
        tail = newNode;
    }

    void insertAt(T value, int idx) {
        Node<T> *newNode = new Node<T>;
        newNode -> value = value;

        Node<T> *curr = head;
        for(int i = 0; curr && i < length; ++i) {
            if(i == idx) {
                break;
            }
            curr = curr -> next;
        }

        if(curr == head) {
            prepend(value);
        }

        if(curr == tail) {
            append(value);
        }

        length++;
        if(!curr) {
            head = tail = newNode;
        }

        newNode -> prev = curr -> prev;
        curr -> prev -> next = newNode;
        curr -> prev = newNode;
        newNode -> next = curr;
    }

    T remove (T value) {
        Node<T> *curr = head;
        T out = curr -> value;

        if(!curr) {
            return T();
        }

        while(curr) {
            if(curr -> value == value) {
                break;
            }
            curr = curr -> next;
        }

        length--;
        if(length == 0) {
            head = tail = NULL;
            return T();
        }

        if(curr == head) {
            head = head -> next;
            return out;
        }

        if(curr == tail) {
            tail = curr -> prev;
            return out;
        }

        curr -> prev -> next = curr -> next;
        curr -> next -> prev = curr -> prev;

        return out;
    }

    T removeAt(int idx) {
        Node<T> *curr = head;
        T out = curr -> value;
        if(!curr) {
            return T();
        }

        for(int i = 0; curr && i < length; ++i) {
            if(i == idx) {
                break;
            }
            curr = curr -> next;
        }

        length--;
        if(length == 0) {
            head = tail = NULL;
            return T();
        }

        if(curr == head) {
            head = head -> next;
            return out;
        }

        if(curr == tail) {
            tail = curr -> prev;
            return out;
        }

        curr -> prev -> next = curr -> next;
        curr -> next -> prev = curr -> prev;

        return out;
    }

    void printList() {
        Node<T> *curr = head;
        while (curr) {
            cout << curr -> value <<" ";
            if(curr == tail) {
                break;
            }
            curr = curr -> next;
        }
        cout << endl;
    }
};

int main() {

    DoublyLinkedList<int> dll;

    dll.prepend(1);
    dll.prepend(2);
    dll.prepend(3);
    dll.printList();
    cout<<"--------------------------"<<endl;

    dll.append(4);
    dll.append(5);
    dll.printList();
    cout<<"--------------------------"<<endl;

    dll.insertAt(7, 3);
    dll.printList();
    cout<<"--------------------------"<<endl;

    dll.remove(7);
    dll.printList();
    cout<<"--------------------------"<<endl;

    dll.removeAt(2);
    dll.printList();
    cout<<"--------------------------"<<endl;
    return 0;
}