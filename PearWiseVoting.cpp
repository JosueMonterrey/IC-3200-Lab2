// https://open.kattis.com/problems/pearwise

#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>

using namespace std;

// armar grafo con diferencia de votos de cada candidato_x vs candidato_y
vvi ArmarGrafo(const int N, const int M) {

	vvi G(N, vi(N));
	
	for (int i = 0; i < M; i++) {
	
		string boleta;
		int votos;
		cin >> votos >> boleta;
		
		for (int x = 0; x < N; x++) {
			int candidato = boleta[x] - 'A';
			
			for (int y = x + 1; y < N; y++) {
				int oponente = boleta[y] - 'A';
				
				G[candidato][oponente] += votos;
				G[oponente][candidato] -= votos;
			}
		}
	}
	
	return G;
}

int DFS(vvi& G, vi& visitados, const int N, const int i) {
	int cuenta = 0;
	
	visitados[i] = 1;
	
	for (int j = 0; j < N; j++) {
		if (!visitados[j] && G[i][j] > 0) {
			cuenta += 1 + DFS(G, visitados, N, j);
		}
	}
	
	return cuenta;
}

int main() {

	int N, M;
	cin >> N >> M;

	vvi G = ArmarGrafo(N, M);
	
	for (int i = 0; i < N; i++) {
	
		vi visitados(N);
		int cantAlcanzables = DFS(G, visitados, N, i);
		
		cout << char('A' + i) << ": ";
		if (cantAlcanzables == N - 1)
			cout << "can win" << endl;
		else
			cout << "can't win" << endl;
	}
		
	return 0;
}
