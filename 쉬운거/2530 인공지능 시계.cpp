#include <iostream>

using namespace std;

int main() {
	int h, m, s, t;
	cin >> h >> m >> s;
	cin >> t;
	s = s + t;
	while (s >= 60) {
		s -= 60;
		m++;
	}
	while (m >= 60) {
		m -= 60;
		h++;
	}
	while (h >= 24) {
		h -= 24;
	}
	cout << h << ' ' << m << ' ' << s << endl;

	return 0;
}