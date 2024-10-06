#include "PathFinderBehaviour.h"
#include "../../engine/base/GameObject.h"
#include "TileBehaviour.h"
#include "GridBehaviour.h"

PathFinderBehaviour::PathFinderBehaviour() : Behaviour("PathFinderBehaviour")
{
}

void PathFinderBehaviour::Start()
{

}

void PathFinderBehaviour::OnGridChanged()
{
}

std::vector<std::pair<int,int>> PathFinderBehaviour::FindPath(std::pair<int, int> start, std::pair<int, int> goal)
{
    currentNodeIndex = 0;
    auto parentTile = gameObject->Transform->GetParent()->gameObject->GetComponent<TileBehaviour>();

	currentPath = aStar(parentTile, start, goal);
    return currentPath;
}

using namespace std;

struct Node {
    int x, y;
    int gCost, hCost;
    Node* parent;

    Node(int x, int y, vector<Node*>& nodes, int gCost = 0, int hCost = 0, Node* parent = nullptr)
        : x(x), y(y), gCost(gCost), hCost(hCost), parent(parent) 
    {
        nodes.push_back(this);
    }

    int fCost() const {
        return gCost + hCost;
    }
};

class Compare {
    public:
       bool operator()(Node *a, Node *b){
            return a->fCost() > b->fCost();
      }
};

// Manhattan distance heuristic
int manhattanDistance(int x1, int y1, int x2, int y2) {
    return 0;
}

// Check if a position is within the grid and walkable
bool isValid(TileBehaviour* tileBehaviour) {
    return tileBehaviour != nullptr && tileBehaviour->IsWalkable();
}

// A* algorithm
vector<pair<int, int>> PathFinderBehaviour::aStar( TileBehaviour* startTile, pair<int, int> start, pair<int, int> goal) {
    int rows = 11;
    int cols = 11;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    priority_queue<Node*, std::vector<Node*>, Compare> openList;

    vector<Node*> nodes;
    Node* startNode = new Node(start.first, start.second, nodes);
    startNode->hCost = manhattanDistance(start.first, start.second, goal.first, goal.second);
    openList.push(startNode);

    vector<pair<int, int>> directions = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    while (!openList.empty()) {

        Node* currentNode = openList.top();
        openList.pop();

        int x = currentNode->x;
        int y = currentNode->y;

        if (x == goal.first && y == goal.second) {
            vector<pair<int, int>> path;
            Node* temp = currentNode;
            while (temp) {
                path.emplace_back(temp->x, temp->y);
                auto t = temp;
                temp = temp->parent;
                delete t;
            }
            reverse(path.begin(), path.end());
            
            return path;
        }

        visited[x][y] = true;

        for (const auto& dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;
            
            if(newX < 0 || newY < 0 || newX >= 11 || newY >= 11)
				continue;

            auto currentTile = startTile->gridBehaviour->GetTileAt(newX, newY);
            
            if (isValid(currentTile) && !visited[newX][newY]) {
                int newGCost = currentNode->gCost + 1;
                int newHCost = manhattanDistance(newX, newY, goal.first, goal.second);
                Node* neighbor = new Node(newX, newY, nodes, newGCost, newHCost, currentNode);
                
                openList.push(neighbor);
            }
        }
    }
    for (auto node : nodes) delete node;
    // Return an empty path if no path is found
    return {};
}
std::pair<int, int> PathFinderBehaviour::GetNextNode()
{
    if(currentNodeIndex < currentPath.size())
    return currentPath[currentNodeIndex++];
    return { -1,-1 };
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
