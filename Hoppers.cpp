// https://open.kattis.com/problems/hoppers

#include <bits/stdc++.h>
#include <queue>

#define vi vector<int>
#define vvi vector<vi>

using namespace std;

bool bipartito(vvi& G, vi& colores, int u) {
	
	bool esBipartito = true;
	
	queue<int> cola;
	cola.push(u);
	
	colores[u] = 1;
	
	while (!cola.empty()) {
		
		u = cola.front(); cola.pop();
		
		for (const int v : G[u]) {
			if (!colores[v]) {
				cola.push(v);
				colores[v] = (colores[u] == 1) ? 2 : 1;
			}
			else if (colores[v] == colores[u])
				esBipartito = false;			
		}
	}
				
	return esBipartito;
}

int main() {
	int N, M;
	cin >> N >> M;
	
	vvi G(N + 1, vi());
	vi colores(N + 1);
	
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	int CCs = 0;
	bool hayNoBipartito = false;
	for (int u = 1; u <= N; u++) {
		if (!colores[u]) {
			CCs++;
			
			hayNoBipartito |= !bipartito(G, colores, u);
		}
	}
	
	int r = CCs - 1;
	if (!hayNoBipartito)
		r++;
	
	cout << r << endl;

	return 0;
}	
