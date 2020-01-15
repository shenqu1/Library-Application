//Name: Shen Qu
//ID#: 119418192
//Date: Nov 26, 2019
//OOP224 MS4
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "PubRecord.h"
#include "Utils.h"
using namespace std;
namespace sdds {
	void PubRecord::name(const char* n) {
		copystr(pubName, n);
	}
	char* PubRecord::name() const{
		return pubName;
	}
	PubRecord::PubRecord() {
		pubName = nullptr;
		shelfNumber = 0;
		type = SDDS_CONSOLE;
	}
	PubRecord::PubRecord(const PubRecord& p) {
		pubName = nullptr;
		copystr(pubName, p.pubName);
		shelfNumber = p.shelfNumber;
		type = p.type;
	}
	PubRecord::~PubRecord() {
		delete[] pubName;
	}
	PubRecord& PubRecord::operator=(const PubRecord& source) {
		if (this != &source) {
			if (source.type != 0) {
				copystr(pubName, source.pubName);
				shelfNumber = source.shelfNumber;
				type = source.type;
			}
		}
		return *this;
	}
	void PubRecord::mediaType(int m) {
		type = m;
	}
	int PubRecord::mediaType() const {
		return type;
	}
	int PubRecord::shelfNo() const {
		return shelfNumber;
	}
	void PubRecord::readShelfNo() {
		unsigned int num;
		sdds::readint(num, 100, 999, "Invalid Shelf Number, Enter again: ");
		shelfNumber = int(num);
	}
	bool PubRecord::operator==(char c) const {
		return recID() == c;
	}
	bool PubRecord::operator==(const char* c) const {
		return strstr(pubName, c) != nullptr;
	}
	PubRecord::operator bool() const {
		return pubName != nullptr;
	}
	void PubRecord::shelfNo(int vale) {
		shelfNumber = vale;
	}
}