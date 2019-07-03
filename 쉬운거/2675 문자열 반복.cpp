#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int test = 1; test <= t; test++) {
		int k;
		cin >> k;
		string a;
		cin >> a;

		for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j < k; j++) {
				cout << a.at(i);
			}
		}
		cout << endl;
	}


	return 0;
}