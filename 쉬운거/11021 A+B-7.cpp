#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int test = 1; test <= T; test++) {
		int a, b;
		cin >> a >> b;

		cout << "Case #" << test << ": " << a + b << endl;
	}

	return 0;
}