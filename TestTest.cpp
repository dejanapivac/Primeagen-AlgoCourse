#include <iostream>
#include <vector>

using namespace std;



int main() {
    vector<vector<char>> maze = {
            {' ', ' ', '#', ' ', ' ', ' '},
            {' ', '#', '#', ' ', '#', ' '},
            {' ', ' ', ' ', ' ', ' ', ' '},
            {'#', '#', '#', '#', '#', ' '},
            {' ', ' ', ' ', ' ', ' ', 'E'},
    };

    cout<<maze[0].size()<<endl;
    cout<<maze.size()<<endl;
}