//Name: Shen Qu
//ID#: 119418192
//Date: Nov 26, 2019
//OOP224 MS4
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include "Book.h"
#include "Utils.h"
using namespace std;
namespace sdds {
	Book::Book() {
		ISBN = 0;
		memID = 0;
	}
	Book::Book(const Book& b) : PubRecord(b){
		ISBN = b.ISBN;
		memID = 0;
		due = b.due;
	}
	Book& Book::operator=(const Book& b) {
		if (this != &b) {
			(PubRecord&)* this = b;
			ISBN = b.ISBN;
			memID = 0;
			due = b.due;
		}
		return *this;
	}
	char Book::recID() const {
		return 'B';
	}
	int Book::memberID() const {
		return memID;
	}
	void Book::checkIn() {
		memID = 0;
		write() << " checked in!" << endl;
	}
	void Book::checkOut() {
		unsigned int id;
		cout << "Enter Member id: ";
		sdds::readint(id, 10000, 99999, "Invalid Member ID, Enter again: ");
		memID = id;
		Date today;
		do {
			do {
				do {
					cout << "Enter return date: ";
					due.read();
				} while (due.errCode() != 0 && cout << due.dateStatus() << "." << endl);
			} while (due <= today && cout << "Please enter a future date." << endl);
		} while (due - today > 30 && cout << "The return date must be earlier than 30 days away from today." << endl);
	}
	istream& Book::read(istream& is) {
		char bookName[41];
		long long int i;
		int s;
		int mem,y,m,d;
		if (mediaType() == SDDS_CONSOLE) {
			memID = 0;
			cout << "Book Name: ";
			sdds::readstr(bookName, 40, "Book name too long, Enter again: ");
			PubRecord::name(bookName);
			cout << "ISBN: ";
			sdds::readlongint(i, 1000000000000, 9999999999999, "Invalid ISBN, Enter again: ");
			ISBN = i;
			cout << "Shelf Number: ";
			readShelfNo();
		}
		else if (mediaType() == SDDS_FILE) {
			is.getline(bookName, 41, '\t');
			is >> i;
			is.ignore();
			is >> s;
			is.ignore();
			is >> mem;
			if (is.fail()) {
				is.clear();
				is.ignore(1000, '\n');
			}
			else {
				if (mem == 0) {
					is.ignore();
					PubRecord::name(bookName);
					ISBN = i;
					PubRecord::shelfNo(s);
					memID = mem;
				}
				else {
					is.ignore();
					is >> y;
					is.ignore();
					is >> m;
					is.ignore();
					is >> d;
					if (is.fail()) {
						is.clear();
						is.ignore(1000, '\n');
					}
					else {
						is.ignore();
						PubRecord::name(bookName);
						ISBN = i;
						PubRecord::shelfNo(s);
						memID = mem;
						due = Date(y, m, d);
					}
				}
			}
		}
		return is;
	}
	ostream& Book::write(ostream& os) const {
		if (mediaType() == SDDS_CONSOLE) {
			os << setw(41) << left << PubRecord::name();
			os << ISBN << "  " << shelfNo();
			if (memberID() != 0) {
				os << " " << memberID() << "   " << due;
			}
		}
		else if (mediaType() == SDDS_FILE) {
			os << recID() << PubRecord::name() << '\t';
			os << ISBN << '\t' << shelfNo() << '\t' << memberID();
			if (memberID() != 0) {
				os << '\t' << due;
			}
			os << endl;

		}
		return os;
	}
}