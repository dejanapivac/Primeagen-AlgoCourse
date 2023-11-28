#include <iostream>
#include <vector>

using namespace std;

// Maze

class Point {
public:
    int x, y;
};

int dir[][2] = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
};


bool walk(vector<vector<char>> &maze, char wall, Point curr, Point end, vector<vector<bool>> &seen, vector<Point>& path) {
    //BASE CASES
    // off the map
    if (curr.x < 0 || curr.x >= maze[0].size() ||
        curr.y < 0 || curr.y >= maze.size()) {
        return false;
    }

    // it's a wall
    if (maze[curr.y][curr.x] == wall) {
        return false;
    }

    // at the end
    if (curr.x == end.x && curr.y == end.y) {
        path.push_back(end);
        return true;
    }

    // seen
    if (seen[curr.y][curr.x]) {
        return false;
    }

    // RECURSION
    // pre rec
    path.push_back(curr);

    // recurse
    for(int i = 0; i < sizeof(dir); ++i) {
        int x = dir[i][0];
        int y = dir[0][i];

        // zasto curr.x + x, curr.y + y
        if(walk(maze, wall, {curr.x + x, curr.y + y}, end, seen, path)) {
            return true;
        }
    }

    // post rec
    path.pop_back();
}

// moram vratiti listu pointova
vector<Point> solve(vector<vector<char>> maze, char wall, Point start, Point end) {

}

int main() {

    vector<vector<char>> maze = {
            {' ', ' ', ' ', ' ', ' ', ' '},
            {' ', '#', '#', ' ', '#', ' '},
            {' ', ' ', ' ', ' ', ' ', ' '},
            {'#', '#', '#', '#', '#', ' '},
            {' ', ' ', ' ', ' ', ' ', 'E'},
    };



    return 0;
}