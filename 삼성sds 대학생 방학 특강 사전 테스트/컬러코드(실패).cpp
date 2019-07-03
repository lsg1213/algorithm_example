#include <iostream>
#include <queue>

using namespace std;

int T, N, Q;
typedef struct board {
	int color[8][8];
}board;

void rotate() {

}

void matching() {

}

int main() {
	cin >> T;
	for (int test = 1; test <= T; test++) {
		queue<int>q;
		cin >> N;
		board ex[10] = { 0, };

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 8; j++) {
				for (int k = 0; k < 8; k++) {
					cin >> ex[i].color[j][k];
				}
			}
		}

		for (int i = 0; i < N; i++) {
			bool ok = false;
			rotate();
			matching();
			rotate();
			matching();
			rotate();
			matching();
			rotate();
			matching();
		}

		

		//output part
		cout << '#' << test;
		int num = q.front();
		q.pop();
		cout << ' ' << num;
		while (!q.empty()) {
			num = q.front();
			q.pop();
			cout << ' ' << num;
		}
		cout << endl;
	}

	return 0;
}