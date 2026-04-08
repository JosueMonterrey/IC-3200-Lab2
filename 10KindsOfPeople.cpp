// https://open.kattis.com/problems/10kindsofpeople

#include <bits/stdc++.h>

using namespace std;

class UnionFind {
	private:
		int C;
		vector<int> G;
	
	public:
		UnionFind(const int r, const int c) : C(c), G(vector<int>(r * c)) {
			for (int i = 0; i < r * c; i++)
				G[i] = i;
		}
		void Union(const int i, const int j, const int x, const int y);
		int Find(const int a);
		int Find(const int i, const int j);
};

int UnionFind::Find(const int i, const int j) {
	int a = i * C + j;
	return Find(a);
}
int UnionFind::Find(const int a) {
	if (G[a] == a)
		return a;

	return G[a] = Find(G[a]);
}
void UnionFind::Union(const int i, const int j, const int y, const int x) {
	int a = i * C + j;
	int b = y * C + x;
	G[Find(a)] = Find(b);
}

int main() {
	int r, c;
	cin >> r >> c;
	
	UnionFind UF(r, c);
	
	vector<vector<bool>> map(r, vector<bool>(c));
	
	// leer valores
	for (int i = 0; i < r; i++) {
		string linea;
		cin >> linea;
		for (int j = 0; j < c; j++)
			map[i][j] = linea[j] == '1';
	}
	
	// Union-Find
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (j < c - 1 && map[i][j] == map[i][j + 1])
				UF.Union(i, j, i, j + 1);
			if (i < r - 1 && map[i][j] == map[i + 1][j])
				UF.Union(i, j, i + 1, j);
		}
	}
	
	// Queries
	int q, r1, c1, r2, c2;
	cin >> q;
	
	while (q--) {
		cin >> r1 >> c1 >> r2 >> c2;
		r1--; c1--; r2--; c2--;
		
		if (UF.Find(r1, c1) == UF.Find(r2, c2))
			cout << (map[r1][c1] ? "decimal" : "binary") << endl;
		else
			cout << "neither" << endl;
	}
	
	return 0;
}
