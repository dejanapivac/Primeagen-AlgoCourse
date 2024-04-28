#include <iostream>
#include <vector>
using namespace std;

// MIN HEAP - najmanji je root, svi ispod su veci

class MinHeap{
public:
    int length;
private:
    vector<int>* data;

    MinHeap() {
        data = nullptr;
        length = 0;
    }

    void insert(int value) {

    }

    int deleteValue() {

    }

    void heapifyUp(int idx) {
        if(idx == 0) {
            return;
        }

        int p = parent(idx);
        int v = data[p];

    }

    int parent(int idx) {
        return (idx - 1) / 2;
    }

    int leftChild(int idx) {
        return idx * 2 + 1;
    }

    int rightChild(int idx) {
        return idx * 2 + 2;
    }
};

int main() {



    return 0;
}