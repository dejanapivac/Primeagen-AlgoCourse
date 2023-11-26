#include <iostream>
#include <vector>
#include <iostream>

using namespace std;

// Maze

class Point {
public:
    int x, y;
};

bool walk(const vector<vector<char>>& maze, char wall, Point curr, Point end) {
    // 1. Base case
    // off the map
    if (curr.x < 0 || curr.x >= maze[0].size() ||
        curr.y < 0 || curr.y >= maze.size()) {
        return false;
    }

    // on a wall

}

char solve(const vector<vector<char>>& maze, char wall, Point start, Point end) {

}

int main() {
    return 0;
}