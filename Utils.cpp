//Name: Shen Qu
//ID#: 119418192
//Date: Nov 14, 2019
//OOP224 MS1
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Utils.h"
using namespace std;

namespace sdds {
	void readint(unsigned int& val, unsigned int min, unsigned int max, const char* ErrorMess) {
		bool ok;
		char newline;
		do {
			cin >> val;
			newline = cin.get();
			if (cin.fail() || newline != '\n') {
				ok = false;
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else {
				ok = val <= max && val >= min;
			}
		} while (!ok && cout << ErrorMess);
	}

	void readlongint(long long int& val, long long int min, long long int max, const char* ErrorMess) {
		bool ok;
		char newline;
		do {
			cin >> val;
			newline = cin.get();
			if (cin.fail() || newline != '\n') {
				ok = false;
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else {
				ok = val <= max && val >= min;
			}
		} while (!ok && cout << ErrorMess);
	}

	void copystr(char*& dest, const char* src) {

		delete[] dest;

		if (src == nullptr || src[0] == '\0') {
			dest = nullptr;
		}
		else {
			int len = strlen(src) + 1;
			dest = new char[len];
			strcpy(dest, src);
			dest[len - 1] = '\0';
		}

	}

	void readstr(char* str, int len, const char* errorMessage) {
		bool ok;
		len = len + 1;
		do {
			ok = true;
			cin.getline(str, len, '\n');
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				ok = false;
			}
		} while (!ok && cout << errorMessage);
	}
}