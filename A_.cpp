#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Structure pour représenter les nœuds du graphe
struct Node {
    int x, y;
    double g, h, f;
    Node *parent;

    Node(int x, int y) {
        this->x = x;
        this->y = y;
        parent = NULL;
        g = h = f = 0;
    }

    // Calculer la distance de Manhattan
    double distance(Node *node) {
        return abs(x - node->x) + abs(y - node->y);
    }
};

// Fonction de comparaison pour la file de priorité
struct CompareNodes {
    bool operator()(Node *node1, Node *node2) {
        return node1->f > node2->f;
    }
};

// Fonction pour vérifier si un nœud est dans la liste fermée
bool isInClosedList(Node *node, vector<Node *> &closedList) {
    for (int i = 0; i < closedList.size(); i++) {
        if (node->x == closedList[i]->x && node->y == closedList[i]->y) {
            return true;
        }
    }
    return false;
}

// Fonction pour vérifier si un nœud est dans la liste ouverte
bool isInOpenList(Node *node, priority_queue<Node *, vector<Node *>, CompareNodes> &openList) {
    priority_queue<Node *, vector<Node *>, CompareNodes> temp = openList;
    while (!temp.empty()) {
        Node *current = temp.top();
        if (node->x == current->x && node->y == current->y) {
            return true;
        }
        temp.pop();
    }
    return false;
}

// Fonction pour récupérer un nœud dans la liste ouverte
Node *getNodeFromOpenList(Node *node, priority_queue<Node *, vector<Node *>, CompareNodes> &openList) {
    priority_queue<Node *, vector<Node *>, CompareNodes> temp = openList;
    while (!temp.empty()) {
        Node *current = temp.top();
        if (node->x == current->x && node->y == current->y) {
            return current;
        }
        temp.pop();
    }
    return NULL;
}

// Fonction pour trouver le chemin optimal avec l'algorithme A*
void findPath(Node *start, Node *goal, vector<vector<int>> &grid) {
    // Initialisation des listes ouverte et fermée
    priority_queue<Node *, vector<Node *>, CompareNodes> openList;
    vector<Node *> closedList;

    // Ajouter le nœud de départ à la liste ouverte
    start->g = 0;
    start->h = start->distance(goal);
    start->f = start->g + start->h;
    openList.push(start);

    while (!openList.empty()) {
        // Récupérer le nœud ayant la plus petite valeur f
        Node *current = openList.top();

        // Si le nœud courant est le nœud objectif, terminer la recherche
        if (current->x == goal->x && current->y == goal->y) {
            // Reconstruire le chemin optimal
            vector<Node *> path;
            while (current != NULL) {
                path.push_back(current);
                current = current->parent;
            }
            reverse(path.begin(), path.end());

            // Aff
        }
    }