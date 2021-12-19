#include <iostream>

using namespace std;


int main() {
	// no.1
	for (int i = 2; i < 10; ++i) {
		cout << "***구구단 " << i << " 단***" << endl;
		cout << endl;
		for (int j = 1; j < 10; ++j) {
			cout << i << " * " << j << " = " << i * j << endl;
		}
		cout << "*************************" << endl;
	}
	return 0;

}
