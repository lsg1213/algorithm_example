#include <iostream>

using namespace std;

int main() {
	int h, m, t;
	cin >> h >> m;
	cin >> t;
	m = m + t;
	while (m >= 60) {
		m -= 60;
		h++;
	}
	while (h >= 24) {
		h -= 24;
	}
	cout << h << ' ' << m << endl;

	return 0;
}