#include <iostream>
#include <string>

using namespace std;

int main() {
	string a;
	while (getline(cin, a)) {
		string b(a);
		cout << b << endl;
	}
}