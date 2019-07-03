#include <iostream>
#include <vector>

using namespace std;

int t, maxx = 0, n = 0;
struct _card {
	bool left, up, down, right;
};
_card card[500][500];
int relate[500][500] = { 0, };
int map[500][500] = { 0, };
vector<int>st;

void search(int x, int y, int origin_x, int origin_y, int num, int max[500][500]) {
	if (y != 0) {	//╩С
		if (map[y - 1][x] > map[y][x]) {
			if (card[y - 1][x].up == true && card[y - 1][x].left == true && card[y - 1][x].right == true) {
				max[origin_y][origin_x] = num + relate[y - 1][x];
			}
			else {
				card[y][x].up = true;
				int tmp = max[origin_y][origin_x];
				if (max[origin_y][origin_x] < num + 1) {
					max[origin_y][origin_x] = num + 1;
				}
				search(x, y - 1, origin_x, origin_y, num + 1, max);
				max[origin_y][origin_x] = tmp;
			}
		}
		else {
			card[y][x].up = true;
		}
	}
	if (y != n - 1) {	// го
		if (map[y + 1][x] > map[y][x]) {
			if (card[y + 1][x].left == true && card[y + 1][x].down == true && card[y + 1][x].right == true) {
				max[origin_y][origin_x] = num + relate[y + 1][x];
			}
			else {
				card[y][x].down = true;
				int tmp = max[origin_y][origin_x];
				if (max[origin_y][origin_x] < num + 1) {
					max[origin_y][origin_x] = num + 1;
				}
				search(x, y + 1, origin_x, origin_y, num + 1, max);
				max[origin_y][origin_x] = tmp;
			}
		}
		else {
			card[y][x].down = true;
		}
	}
	if (x != 0) {	// аб
		if (map[y][x - 1] > map[y][x]) {
			if (card[y][x - 1].up == true && card[y][x - 1].down == true && card[y][x - 1].left == true) {
				max[origin_y][origin_x] = num + relate[y][x - 1];
			}
			else {
				card[y][x].left = true;
				int tmp = max[origin_y][origin_x];
				if (max[origin_y][origin_x] < num + 1) {
					max[origin_y][origin_x] = num + 1;
				}
				search(x - 1, y, origin_x, origin_y, num + 1, max);
				max[origin_y][origin_x] = tmp;
			}
		}
		else {
			card[y][x].left = true;
		}
	}
	if (x != n - 1) {	// ©Л
		if (map[y][x + 1] > map[y][x]) {
			if (card[y][x + 1].up == true && card[y][x + 1].down == true && card[y][x + 1].right == true) {
				max[origin_y][origin_x] = num + relate[y][x + 1];
			}
			else {
				card[y][x].right = true;
				int tmp = max[origin_y][origin_x];
				if (max[origin_y][origin_x] < num + 1) {
					max[origin_y][origin_x] = num + 1;
				}
				search(x + 1, y, origin_x, origin_y, num + 1, max);
				max[origin_y][origin_x] = tmp;
			}
		}
		else {
			card[y][x].right = true;
		}
	}

	if (max[origin_y][origin_x] > relate[origin_y][origin_x]) {
		relate[origin_y][origin_x] = max[origin_y][origin_x];
	}
}


int main() {

	cin >> t;
	for (int test = 1; test <= t; test++) {
		maxx = 0;
		cin >> n;
		int max[500][500];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				card[i][j].up = false;
				card[i][j].down = false;
				card[i][j].left = false;
				card[i][j].right = false;
				relate[i][j] = 1;
				max[i][j] = 1;
				if (i == 0) {
					card[i][j].up = true;
				}
				if (i == n - 1) {
					card[i][j].down = true;
				}
				if (j == 0) {
					card[i][j].left = true;
				}
				if (j == n - 1) {
					card[i][j].right = true;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				search(j, i, j, i, 1, max);

				if (y != 0) {	//╩С
					if (map[y - 1][x] > map[y][x]) {
						if (card[y - 1][x].up == true && card[y - 1][x].left == true && card[y - 1][x].right == true) {
							max[origin_y][origin_x] = num + relate[y - 1][x];
						}
						else {
							card[y][x].up = true;
							int tmp = max[origin_y][origin_x];
							if (max[origin_y][origin_x] < num + 1) {
								max[origin_y][origin_x] = num + 1;
							}
							search(x, y - 1, origin_x, origin_y, num + 1, max);
							max[origin_y][origin_x] = tmp;
						}
					}
					else {
						card[y][x].up = true;
					}
				}
				if (y != n - 1) {	// го
					if (map[y + 1][x] > map[y][x]) {
						if (card[y + 1][x].left == true && card[y + 1][x].down == true && card[y + 1][x].right == true) {
							max[origin_y][origin_x] = num + relate[y + 1][x];
						}
						else {
							card[y][x].down = true;
							int tmp = max[origin_y][origin_x];
							if (max[origin_y][origin_x] < num + 1) {
								max[origin_y][origin_x] = num + 1;
							}
							search(x, y + 1, origin_x, origin_y, num + 1, max);
							max[origin_y][origin_x] = tmp;
						}
					}
					else {
						card[y][x].down = true;
					}
				}
				if (x != 0) {	// аб
					if (map[y][x - 1] > map[y][x]) {
						if (card[y][x - 1].up == true && card[y][x - 1].down == true && card[y][x - 1].left == true) {
							max[origin_y][origin_x] = num + relate[y][x - 1];
						}
						else {
							card[y][x].left = true;
							int tmp = max[origin_y][origin_x];
							if (max[origin_y][origin_x] < num + 1) {
								max[origin_y][origin_x] = num + 1;
							}
							search(x - 1, y, origin_x, origin_y, num + 1, max);
							max[origin_y][origin_x] = tmp;
						}
					}
					else {
						card[y][x].left = true;
					}
				}
				if (x != n - 1) {	// ©Л
					if (map[y][x + 1] > map[y][x]) {
						if (card[y][x + 1].up == true && card[y][x + 1].down == true && card[y][x + 1].right == true) {
							max[origin_y][origin_x] = num + relate[y][x + 1];
						}
						else {
							card[y][x].right = true;
							int tmp = max[origin_y][origin_x];
							if (max[origin_y][origin_x] < num + 1) {
								max[origin_y][origin_x] = num + 1;
							}
							search(x + 1, y, origin_x, origin_y, num + 1, max);
							max[origin_y][origin_x] = tmp;
						}
					}
					else {
						card[y][x].right = true;
					}
				}

				if (max[origin_y][origin_x] > relate[origin_y][origin_x]) {
					relate[origin_y][origin_x] = max[origin_y][origin_x];
				}
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (maxx < relate[i][j]) maxx = relate[i][j];
			}
		}

		cout << '#' << test << ' ' << maxx << endl;
	}

	return 0;
}