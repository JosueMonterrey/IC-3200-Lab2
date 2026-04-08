// https://open.kattis.com/problems/wheresmyinternet

#include <bits/stdc++.h>

using namespace std;


class UnionFind {
	private:
		vector<int> G;
	
	public:
		UnionFind(const int N) : G(vector<int>(N + 1)) {
			for (int i = 0; i <= N; i++)
				G[i] = i;
		}
		void Union(const int a, const int b);
		int Find(const int a);
};

int UnionFind::Find(const int a) {
	if (G[a] == a)
		return a;
	
	return G[a] = Find(G[a]);
}
void UnionFind::Union(const int a, const int b) {
	G[Find(a)] = Find(b);
}


int main() {
	int N, M, a, b;
	cin >> N >> M;
	
	UnionFind UF(N);

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		UF.Union(a, b);
	}
	
	int cc1 = UF.Find(1);
	bool allConnected = true;
	
	for (int i = 2; i <= N; i++) {
		if (UF.Find(i) != cc1) {
			cout << i << endl;
			allConnected = false;
		}
	}
	
	if (allConnected)
		cout << "Connected" << endl;
	
	return 0;
}
