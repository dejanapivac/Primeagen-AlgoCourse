#include <iostream>
#include <vector>

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

    DoublyLinkedList() {
        length = 0;
        head = tail = NULL;
    }

    void prepend(T item) {
        Node<T> *newNode = new Node<T>;
        newNode->value = item;
        length++;
        if (!head) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAt(T item, int idx) {
        if (idx > length) {
            return; //OVO MOZDA NIJE BAS DOBRO
        } else if (idx == length) {
            append(item);
        } else if (idx == 0) {
            prepend(item);
        }

        length++;
        Node<T> *curr = head;
        for (int i = 0; curr && i < idx; ++i) {
            cout << curr->value << endl;
            curr = curr->next;
        }

//        Node<T>* curr = getAt(idx);

        //curr = curr as Node<T> nest tako je on napisao
        Node<T> *insertedNode = new Node<T>;
        insertedNode->value = item;
        insertedNode->next = curr;
        insertedNode->prev = curr->prev;
        curr->prev->next = insertedNode;
        curr->prev = insertedNode;
    }

    void append(T value) {
        length++;
        Node<T> *newNode = new Node<T>;
        newNode->value = value;
        if (!tail) {
            head = tail = newNode;
            return;
        }

        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    T remove(T value) {
        Node<T> *curr = head;

        if (!curr) {
            return T();
        }

        while (curr) {
            if (curr->value == value) {
                break;
            } else if (curr == tail && curr->value == value) {
                break;
            } else if (curr == tail && curr->value != value) {
                return T();
            } else {
                curr = curr->next;
            }
        }


        length--;
        T out = curr->value;
        if (length == 0) {
            out = head->value;
            head = tail = nullptr;
            return out;
        }

        if (curr == head) {
            out = head -> value;
            head = curr->next;
            return out;
        }

        if (curr == tail) {
            out = tail -> value;
            tail = curr->prev;
            return out;
        }

        if (curr->prev) {
            out = curr -> value;
            curr->prev->next = curr->next;
        }

        if (curr->next) {
            out = curr -> value;
            curr->next->prev = curr->prev;
        }

//        curr->prev = curr->next = nullptr;
        delete curr;

        return out;
    }

    T get(int idx) {
        Node<T> node = getAt(idx);
        return getAt(idx) ? node->value : T();
    }

    Node<T> getAt(int idx) {
        Node<T> *curr = head;
        for(int i = 0; curr && i < idx; ++i) {
            curr = curr -> next;
        }

        return *curr;
    }

    void printList() {
        Node<T> *curr = head;
        while (curr) {
            cout << curr->value << endl;
            if (curr == tail) {
                break;
            }
            curr = curr->next;
        }
    }
};


int main() {

    DoublyLinkedList<int> dLL;

    dLL.append(1);
    dLL.append(2);
    dLL.append(3);
    dLL.append(4);
    dLL.append(5);

    cout << dLL.length << endl;
    dLL.printList();
    cout << "------------------------" << endl;

    dLL.insertAt(7, 2);
    cout << "ovde" << endl;
    dLL.printList();
    cout << "------------------------" << endl;
    dLL.insertAt(9, 3);
    dLL.printList();
    cout << "------------------------" << endl;


    dLL.remove(1);
    dLL.printList();
    dLL.getAt(2);

//    cout << dLL.length;
//    cout << endl;

    return 0;
}