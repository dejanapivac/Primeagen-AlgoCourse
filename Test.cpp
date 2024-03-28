#include <iostream>
#include <vector>

using namespace std;

class Point {
public:
    int x, y;
};

int dir[][2] = {{1, 0},
                {-1, 0},
                {0, 1},
                {0, -1}};

bool walk( vector<vector<char>> &maze, char wall, Point curr, Point end, vector<vector<bool>> &seen,
          vector<Point> &path) {
    // base case
    // off the map
    if (curr.x < 0 || curr.x >= maze[0].size() ||
        curr.y < 0 || curr.y >= maze.size()) {
        return false;
    }

    // if wall
    if (maze[curr.x][curr.y] == wall) {
        return false;
    }

    // if end
    if (curr.x == end.x && curr.y == end.y) {
        path.push_back(end);
        return true;
    }

    // if seen
    if(maze[curr.y][curr.x]) {
        return false;
    }

    seen[curr.x][curr.y] = true;
    path.push_back(curr);

    for(int i = 0; i < 4; ++i) {
        int x = dir[i][0];  // u polju prvi stupac
        int y = dir[i][1];

        if(walk(maze, wall, {curr.x + x, curr.y + y},  end, seen, path)) {
            return true;
        }
    }

    path.pop_back();
    return false;
}

vector<Point> solve(vector<vector<char>> &maze, char wall, Point start, Point end) {
    int rows = maze.size();
    int cols = maze[0].size();

    vector<vector<bool>> seen(rows, vector<bool>(cols, false));
    vector<Point> path;

    walk(maze, wall, start, end, seen, path);

    return path;
}

int main() {

    vector<vector<char>> maze = {
            {' ', ' ', '#', ' ', ' ', ' '},
            {' ', '#', '#', ' ', '#', '#'},
            {' ', ' ', ' ', ' ', ' ', ' '},
            {'#', '#', '#', '#', '#', ' '},
            {' ', ' ', ' ', ' ', ' ', 'E'},
    };

    Point start = {0, 0};
    Point end = {5, 4};

    vector<Point> result = solve(maze, '#', start, end);

    if (!result.empty()) {
        cout << "Path found!" << endl;
        cout << "Path: ";
        for (const auto &p: result) {
            cout << "(" << p.x << ", " << p.y << ") ";
        }
        cout << endl;
    } else {
        cout << "No path found." << endl;
    }

    return 0;
}