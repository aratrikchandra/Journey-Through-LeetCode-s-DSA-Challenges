#include <bits/stdc++.h>
using namespace std;

// for adjacency matrix

// int main() {
//     ifstream inputFile("input.txt");
//     if (!inputFile.is_open()) {
//         cerr << "Could not open the file - '"
//              << "input.txt" << "'" << endl;
//         return EXIT_FAILURE;
//     }

//     int n, m;
//     inputFile >> n >> m;

//     // Initialize adjacency matrix with 0s
//     int adj[n+1][n+1] = {}; // for 1 based indexing

//     for(int i = 0; i < m; i++) {
//         int u, v;
//         inputFile >> u >> v;
//         adj[u][v] = 1;
//         adj[v][u] = 1; // This statement will be removed in case of directed graph
//     }

//     inputFile.close();

//     // Optional: Print the adjacency matrix
//     for(int i = 1; i <= n; i++) {
//         for(int j = 1; j <= n; j++) {
//             cout << adj[i][j] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

// for adjacency list
int main() {
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Could not open the file - '"
             << "input.txt" << "'" << endl;
        return EXIT_FAILURE;
    }

    int n, m; // number of vertices and edges
    inputFile >> n >> m;

   // adjacency list
   vector<int> adj[n+1];

   for(int i=0;i<m;i++){
    int u,v;
    inputFile>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u); // for directed graph skip this line
   }

    inputFile.close();

    // Optional: Print the adjacency list
    for(int i = 1; i <= n; i++) {
        cout<<i<<": { ";
        for(auto it: adj[i]) {
            cout << it << " ";
        }
        cout<<"}" << endl;
    }

    return 0;
}