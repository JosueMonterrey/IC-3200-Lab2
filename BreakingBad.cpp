// https://open.kattis.com/problems/breakingbad

#include <bits/stdc++.h>
#include <queue>

#define vi vector<int>
#define vvi vector<vi>

#define WALTER 1
#define JESSE 2

using namespace std;

bool bipartito(vvi& G, vi& colores, int u, vi& W, vi& J) {
	
	bool esBipartito = true;
	
	queue<int> cola;
	cola.push(u);
	
	colores[u] = WALTER;
    W.push_back(u);
	
	while (!cola.empty()) {
		
		u = cola.front(); cola.pop();
		
		for (const int v : G[u]) {
			if (!colores[v]) {
				cola.push(v);

                if (colores[u] == WALTER) {
                    colores[v] = JESSE;
                    J.push_back(v);
                }
                else {
                    colores[v] = WALTER;
                    W.push_back(v);
                }
			}
			else if (colores[v] == colores[u])
				esBipartito = false;
		}
	}
				
	return esBipartito;
}

int main() {
	int N;
    cin >> N;

    vector<string> nombres(N);
    map<string, int> indices;
    for (int i = 0; i < N; i++) {
        string n;
        cin >> n;
        nombres[i] = n;
        indices[n] = i;
    }

    vvi G(N, vi());
	vi colores(N);

    int M;
	cin >> M;

    while (M--) {
		string item1, item2;
		cin >> item1 >> item2;

        int index1 = indices[item1];
        int index2 = indices[item2];

		G[index1].push_back(index2);
		G[index2].push_back(index1);
	}

    vi W, J;

    for (int i = 0; i < N; i++) {
        if (!colores[i]) {
            if (!bipartito(G, colores, i, W, J)) {
                cout << "impossible" << endl;
                return 0;
            }
        }
    }

    for (int w = 0; w < W.size(); w++) {
        cout << nombres[W[w]];
        if (w == W.size() - 1)
            cout << endl;
        else
            cout << " ";
    }
    for (int j = 0; j < J.size(); j++) {
        cout << nombres[J[j]];
        if (j == J.size() - 1)
            cout << endl;
        else
            cout << " ";
    }

	return 0;
}