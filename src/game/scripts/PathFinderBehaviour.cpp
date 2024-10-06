#include "PathFinderBehaviour.h"
#include "../../engine/base/GameObject.h"
#include "TileBehaviour.h"

PathFinderBehaviour::PathFinderBehaviour() : Behaviour("PathFinderBehaviour")
{
}

void PathFinderBehaviour::Start()
{
    auto parentTile = gameObject->Transform->GetParent()->gameObject->GetComponent<TileBehaviour>();
    
    currentPath = FindPath({ parentTile->x , parentTile->y }, { 0,0 });
    currentNodeIndex = 0;
}


std::vector<std::pair<int,int>> PathFinderBehaviour::FindPath(std::pair<int, int> start, std::pair<int, int> goal)
{
    auto parentTile = gameObject->Transform->GetParent()->gameObject->GetComponent<TileBehaviour>();

	return aStar(parentTile, start, goal);
}

using namespace std;

struct Node {
    int x, y;
    int gCost, hCost;
    Node* parent;

    Node(int x, int y, int gCost = 0, int hCost = 0, Node* parent = nullptr)
        : x(x), y(y), gCost(gCost), hCost(hCost), parent(parent) {}

    int fCost() const {
        return gCost + hCost;
    }

    // Custom comparator for priority queue
    bool operator<(const Node& other) const {
        return fCost() > other.fCost();
    }
};

// Manhattan distance heuristic
int manhattanDistance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// Check if a position is within the grid and walkable
bool isValid(int x, int y, TileBehaviour* tileBehaviour) {
    return x >= 0 && x < 11 && y >= 0 && y < 11 && tileBehaviour->IsWalkable() ;
}

// A* algorithm
vector<pair<int, int>> PathFinderBehaviour::aStar( TileBehaviour* startTile, pair<int, int> start, pair<int, int> goal) {
    int rows = 11;
    int cols = 11;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    priority_queue<Node> openList;

    Node* startNode = new Node(start.first, start.second);
    startNode->hCost = manhattanDistance(start.first, start.second, goal.first, goal.second);
    openList.push(*startNode);

    vector<pair<int, int>> directions = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

    while (!openList.empty()) {
        Node currentNode = openList.top();
        openList.pop();

        int x = currentNode.x;
        int y = currentNode.y;

        if (x == goal.first && y == goal.second) {
            vector<pair<int, int>> path;
            Node* temp = &currentNode;
            while (temp) {
                path.emplace_back(temp->x, temp->y);
                temp = temp->parent;
            }
            reverse(path.begin(), path.end());
            return path;
        }

        if (visited[x][y]) continue;
        visited[x][y] = true;

        for (const auto& dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;
            auto currentTile = startTile->GetNeighbour(dir.first, dir.second);

            if (isValid(newX, newY, currentTile) && !visited[newX][newY]) {
                int newGCost = currentNode.gCost + 1;
                int newHCost = manhattanDistance(newX, newY, goal.first, goal.second);
                Node* neighbor = new Node(newX, newY, newGCost, newHCost, new Node(currentNode));
                openList.push(*neighbor);
            }
        }
    }

    // Return an empty path if no path is found
    return {};
}
//
//int main() {
//    vector<vector<int>> grid = {
//        {0, 0, 0, 0, 1},
//        {0, 1, 0, 1, 0},
//        {0, 1, 0, 1, 0},
//        {0, 0, 0, 0, 0}
//    };
//
//    pair<int, int> start = { 0, 0 };
//    pair<int, int> goal = { 3, 4 };
//
//    vector<pair<int, int>> path = aStar(grid, start, goal);
//
//    if (!path.empty()) {
//        cout << "Path found:\n";
//        for (const auto& p : path) {
//            cout << "(" << p.first << ", " << p.second << ") ";
//        }
//        cout << endl;
//    }
//    else {
//        cout << "No path found." << endl;
//    }
//
//    return 0;
//}
