#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int test = 1; test <= t; test++) {
		double v;
		cin >> v;
		char tmp[201] = { 0 };
		fgets(tmp, 201, stdin);
		for (int i = 1; i < sizeof(tmp); i+=2) {
			if (tmp[i] == '#') {
				v -= 7;
			}
			else if (tmp[i] == '@') {
				v *= 3;
			}
			else if (tmp[i] == '%') {
				v += 5;
			}
		}
		
		printf("%.2lf\n", v);
	}

	return 0;
}