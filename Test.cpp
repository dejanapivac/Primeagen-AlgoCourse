#include <iostream>
#include <vector>

using namespace std;

class Point {
public:
    int x, y;
};

int dir[][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
};

bool walk(vector<vector<char>> &maze, char wall, Point curr, Point end, vector<vector<bool>> &seen, vector<Point> &path) {
    // 1. base case
    // off the map
    if (curr.x < 0 || curr.x > maze[0].size() ||
        curr.y < 0 || curr.y > maze.size()) {
        return false;
    }

    // 2. base
    // wall
    if(maze[curr.x][curr.y] == wall) {
        return false;
    }

    // end
    if(curr.x == end.x && curr.y == end.y) {
        path.push_back(end);
        return true;
    }

    //seen
    if(seen[curr.y][curr.x]) {
        return false;
    }

    for(int i = 0; i < 4; ++i) {
        int x = dir[i][0];
        int y = dir[i][1];

        if(walk(maze, wall, {curr.x + x, curr.y + y}, end, seen, path)) {
            return true;
        }
    }

    path.pop_back();

}


int main() {

    vector<vector<char>> maze = {
            {' ', '#', '#', '#'},
            {' ', ' ', '#', '#'},
            {'#', ' ', '#', '#'},
            {'#', ' ', ' ', 'E'}
    }
}