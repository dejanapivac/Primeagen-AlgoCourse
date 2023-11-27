#include <iostream>
#include <vector>
#include <iostream>

using namespace std;

// Maze

class Point {
public:
    int x, y;
};

// left, right, down, up
int dir[][2] = {{-1, 0},
                {1,  0},
                {0,  -1},
                {0,  1}};

bool walk(const vector<vector<char>> &maze, char wall, Point curr, Point end, vector<vector<bool>> &seen,
          vector<Point> &path) {
    // 1. Base case
    // off the map
    if (curr.x < 0 || curr.x >= maze[0].size() ||
        curr.y < 0 || curr.y >= maze.size()) {
        return false;
    }

    // on a wall
    if (maze[curr.y][curr.x] == wall) {
        return false;
    }

    // at the end
    if (curr.x == end.x && curr.y == end.y) {
        path.push_back(end); // WHAT???
        return true;
    }

    // have seen it
    if (seen[curr.y][curr.x]) {
        return false;
    }

    // 3 recurse steps
    // pre rec
    seen[curr.y][curr.x] = true;
    path.push_back(curr);

    // recurse
    for (int i = 0; i < sizeof dir; ++i) {
        int x = dir[i][0];
        int y = dir[i][1];
        if (walk(maze, wall, {curr.x + x, curr.y + y}, end, seen, path)) {
            return true;
        }
    }

    // post rec
    path.pop_back();

    return false;
}

vector<Point> solve(const vector<vector<char>> &maze, char wall, Point start, Point end) {
    int rows = maze.size();
    int cols = maze[0].size();

    // vector<bool>(cols, false) - inicializira bool vektor velicine cols i sve postavlja na false
    // ovaj vanjski vektor inicijalizira vektor velicine rows i postavalja vrijednosti ovog unutarnjeg vektora
    vector<vector<bool>> seen(rows, vector<bool>(cols, false));
    vector<Point> path;

    walk(maze, wall, start, end, seen, path);

    return path;
}

int main() {
    // Example usage
    vector<vector<char>> maze = {
            {' ', ' ', ' ', ' ', ' ', ' '},
            {' ', '#', '#', ' ', '#', ' '},
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