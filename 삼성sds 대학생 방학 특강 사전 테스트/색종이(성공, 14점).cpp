#include <iostream>
#include <queue>

using namespace std;
int T, N, K, paper[10001] = { 0 ,}, cnt[10001] = { 0 ,};
int pr[10001] = { 0 , };
queue<int> q;
void search(bool right, int tmp, int origin, int pr[10001]) {
	if (right) {
		if (tmp != N - 1) {
			if (paper[tmp + 1] == 0) {
				cnt[paper[origin]]++;
				pr[tmp + 1] = paper[origin];
				search(true, tmp + 1, origin, pr);
			}
			else {
				if (paper[origin] != paper[tmp + 1]) {	//숫자가 다른 경우
					cnt[paper[origin]] -= abs(paper[origin] - paper[tmp + 1]) - 1;
				}
			}
		}
		else {
			if (paper[tmp] != K) {	//K보다 현재 카드 숫자가 작은 경우
				cnt[paper[origin]] -= K - paper[origin];
			}
		}
	}
	else {
		if (tmp != 0) {
			if (paper[tmp - 1] == 0) {
				cnt[paper[origin]]++;
				pr[tmp - 1] = paper[origin];
				search(false, tmp - 1, origin, pr);
			}
			else {
				if (paper[origin] != paper[tmp - 1]) {	//숫자가 다른 경우
					cnt[paper[origin]] -= abs(paper[origin] - paper[tmp - 1]) - 1;
				}
				else {
					cnt[paper[origin]] -= origin - tmp;
				}
			}
		}
		else {
			cnt[paper[origin]] -= paper[origin] - 1;
		}
	}
}
void search() {
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();

		if (tmp != 0) {
			search(false, tmp, tmp, pr);
		}
		if (tmp != N - 1) {
			search(true, tmp, tmp, pr);
		}
		for (int i = 0; i < N; i++) {
			cout << pr[i] << ' ';
		}
		cout << endl;
	}
}


int main() {
	cin >> T;
	for (int test = 0; test < T; test++) {
		int max = 0;

		//input
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			cin >> paper[i];
			pr[i] = paper[i];
			if (paper[i] != 0) {
				cnt[paper[i]]++;
				q.push(i);
			}
		}
		

		//searching
		if (!q.empty()) {
			search();
			for (int i = 1; i <= K; i++) {
				if (max < cnt[i]) max = cnt[i];
			}
		}
		else {
			max = N - K + 1;
		}

		//print output
		cout << '#' << test + 1 << ' ' << max << endl;
		


		// initializing
		if (true) {
			int tmp_paper[10001] = { 0 };
			swap(tmp_paper, paper);
			int tmp_cnt[10001] = { 0 };
			swap(tmp_cnt, cnt);
		}
		queue<int> _q;
		swap(q, _q);
	}

	return 0;
}