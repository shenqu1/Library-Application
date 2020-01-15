//Name: Shen Qu
//ID#: 119418192
//Date: Nov 26, 2019
//OOP224 MS4
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include "Magazine.h"
#include "Utils.h"
using namespace std;
namespace sdds {
	Magazine::Magazine() {
		volume = 0;
		issueNum = 0;
	}
	Magazine::Magazine(const Magazine& m) : PubRecord(m){
		volume = m.volume;
		issueNum = m.issueNum;
	}
	Magazine& Magazine::operator=(const Magazine& m) {
		if (this != &m) {
			(PubRecord&)* this = m;
			volume = m.volume;
			issueNum = m.issueNum;
		}
		return *this;
	}
	char Magazine::recID() const {
		return 'M';
	}
	void Magazine::checkIn() {
		cout << "Magazines cannot be checked in or out!" << endl;
	}
	void Magazine::checkOut() {
		cout << "Magazines cannot be checked in or out!" << endl;
	}
	istream& Magazine::read(istream& is) {
		char MagName[41];
		unsigned int v;
		unsigned int i;
		int s;
		if (mediaType() == SDDS_CONSOLE) {
			cout << "Magazine Name: ";
			sdds::readstr(MagName, 40, "Magazine name too long, Enter again: ");
			PubRecord::name(MagName);
			cout << "Volume: ";
			sdds::readint(v, 1, 99, "Invalid Volume number, Enter again: ");
			volume = v;
			cout << "Issue: ";
			sdds::readint(i, 1, 99, "Invalid Issue number, Enter again: ");
			issueNum = i;
			cout << "Shelf Number: ";
			readShelfNo();
		}
		else if (mediaType() == SDDS_FILE) {
			is.getline(MagName, 41, '\t');
			is >> v;
			is.ignore();
			is >> i;
			is.ignore();
			is >> s;
			if (is.fail()) {
				is.clear();
				is.ignore(1000, '\n');
			}
			else {
				is.ignore();
				PubRecord::name(MagName);
				volume = v;
				issueNum = i;
				PubRecord::shelfNo(s);
			}
		}
		return is;
	}
	ostream& Magazine::write(ostream& os) const {
		if (mediaType() == SDDS_CONSOLE) {
			os << setw(41) << left << PubRecord::name();
			os << "       " << setw(2) << right << setfill('0') << volume;
			os << "(" << setw(2) << right << setfill('0') << issueNum << ")";
			os << "  " << shelfNo() << setfill(' ');
		}
		else if (mediaType() == SDDS_FILE) {
			os << recID() << PubRecord::name() << '\t';
			os << volume << '\t' << issueNum << '\t' << shelfNo() << endl;
		}
		return os;
	}
}