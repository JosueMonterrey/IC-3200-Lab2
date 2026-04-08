// https://open.kattis.com/problems/gold

#include <bits/stdc++.h>

using namespace std;

int MovePlayer(vector<vector<char>>& map, const int i, const int j) {
	
	int gold = 0;
		
	if (map[i][j] == 'G')
		gold++;
		
	map[i][j] = '#';
		
	char mapUp = map[i - 1][j];
	char mapDown = map[i + 1][j];
	char mapLeft = map[i][j - 1];
	char mapRight = map[i][j + 1];
	
	// hay trampa cerca
	if (mapUp == 'T' || mapDown == 'T' || mapLeft == 'T' || mapRight == 'T')
		return gold;
	
	if (mapUp != '#')
		gold += MovePlayer(map, i - 1, j);
	
	if (mapDown != '#')
		gold += MovePlayer(map, i + 1, j);

	if (mapLeft != '#')
		gold += MovePlayer(map, i, j - 1);
	
	if (mapRight != '#')
		gold += MovePlayer(map, i, j + 1);
	
	return gold;
}

int main() {
	
	int W, H;
	cin >> W >> H;
	
	vector<vector<char>> map(H, vector<char>(W));
	int playerPosI, playerPosJ;
	
	for (int i = 0; i < H; i++) {
		string linea;
		cin >> linea;
		
		for (int j = 0; j < W; j++) {
			if (linea[j] == 'P') {
				playerPosI = i;
				playerPosJ = j;
			}
			else {
				map[i][j] = linea[j];
			}
		}
	}
	
	cout << MovePlayer(map, playerPosI, playerPosJ) << endl;

	return 0;
}
