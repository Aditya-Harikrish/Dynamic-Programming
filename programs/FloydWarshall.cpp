#include <iostream>

void FloydWarshall(int **dist, int v) {
    for (int k = 0; k < v; ++k) {
        for (int i = 0; i < v; ++i)
            for (int j = 0; j < v; ++j)
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
    }
}

int main(void) {
    int v, e;
    std::cout << "Enter number of vertices: ";
    std::cin >> v;

    std::cout << "Enter number of edges: ";
    std::cin >> e;

    int **dist = new int *[v];
    for (int i = 0; i < v; ++i) {
        dist[i] = new int[v];
        for (int j = 0; j < v; ++j) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INT_MAX;
        }
    }

    std::cout << "Enter the edges in this format: `tail head weight`"
              << "\n";
    for (int a = 0; a < e; ++a) {
        int i, j, w;
        std::cin >> i >> j >> w;
        dist[i][j] = w;
    }

    FloydWarshall(dist, v);

    std::cout << "The minimum distance matrix is:\n";
    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j) {
            std::cout << dist[i][j] << " ";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < v; ++i) {
        delete[] dist[i];
    }
    delete[] dist;
    return 0;
}