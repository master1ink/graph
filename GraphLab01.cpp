#include<iostream>
#include<list>
using namespace std;

int adj_mtx[20][20];
int inc_mtx[20][20];
int count = 0;

void displayIncMatrix(int v, int e) {
    int i, j;
    cout << "\nIncidence Matrix" << endl;
    cout << "  ";
    for (int k = 1; k < e; ++k) {
        cout << "e" << k << " ";
    }
    cout << endl;
    for(i = 1; i < v; i++) {
        cout << i << "|";
        for(j = 1; j < e; j++) {
            cout << inc_mtx[i][j-1] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

void displayAdjMatrix(int v) {
    int i, j;
    cout << "\nAdjacency Matrix" << endl;
    cout << "  ";
    for (int k = 1; k < v; ++k) {
        cout << k << " ";
    }
    cout << endl;
    for(i = 1; i < v; i++) {
        cout << i << "|";
        for(j = 1; j < v; j++) {
            cout << adj_mtx[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void displayAdjList(list<int> adj_list[], int v) {
    cout << "\nAdjacency List" << endl;
    for(int i = 1; i<v; i++) {
        cout << i << "->";
        list<int> :: iterator it;
        for(it = adj_list[i].begin(); it != adj_list[i].end(); ++it) {
            cout << *it << " ";
        }
        cout << "0" << endl;
    }
    cout << endl;
}

void add_adj_edge(int u, int v) {
    adj_mtx[u][v] = 1;
    adj_mtx[v][u] = 1;
}

void add_inc_edge(int u, int v) {
    inc_mtx[u][count] = 1;
    inc_mtx[v][count] = 1;
    count++;
}

void add_list_edge(list<int> adj_list[], int u, int v) {
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
}

void add_edge(list<int> adj_list[], int u, int v) {
    add_adj_edge(u, v);
    add_inc_edge(u, v);
    add_list_edge(adj_list, u, v);
}

void displayMtx(list<int> adj_list[], int e, int v) {
    int choose, loop = 1;
    while (loop) {
        cout << "\nChoose representation"
                "\n1. Adjacency Matrix"
                "\n2. Incidence Matrix"
                "\n3. Adjacency List"
                "\n0. Exit"
                "\nInput: ";
        cin >> choose;
        switch (choose) {
            case 1:
                displayAdjMatrix(v);
                break;
            case 2:
                displayIncMatrix(v, e);
                break;
            case 3:
                displayAdjList(adj_list, v);
                break;
            default:
                loop=false;
        }
    }
}

int main() {
    int v, e;
    cout << "Enter number of nodes: ";
    cin >> v;
    v++;
    list<int> adj_list[v];
    for (e = 1; e>-1; e++) {
        int u, g;
        cout << "\nEnter edge ex.1 2 (-1 -1 to exit): ";
        cin >> u >> g;
        if ((u==-1) && (g==-1)) {
            break;
        }
        add_edge(adj_list, u, g);
    }
    displayMtx(adj_list, e, v);
}