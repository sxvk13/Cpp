﻿#include <iostream>

using namespace std;


int main() {
	cout << "homework no.1" << endl;
	// no.1
	for (int i = 2; i < 10; ++i) {
		cout << "***구구단 " << i << " 단***" << endl;
		cout << endl;
		for (int j = 1; j < 10; ++j) {
			cout << i << " * " << j << " = " << i * j << endl;
		}
		cout << "*************************" << endl;
	}
	
	cout << endl;

	cout << "homework no.2" << endl;
	// no.2

	for (int i = 1; i < 6; ++i) {
		for (int j = 0; j < i; ++j) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

	cout << "homework no.3" << endl;
	// no.3

	for (int i = 5; i > 0; --i) {
		for (int j = 0; j < i; ++j) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

	cout << "homework no.4" << endl;
	// no.4

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 3-i;++j) {
			cout << " ";
		}
		for (int j = 0; j < i*2+1; ++j) {
			cout << "*" ;
		}
		for (int j = 0; j < 3-i; ++j) {
			cout << " ";
		}
		cout << endl;
	}


	return 0;
}
