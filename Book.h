//Name: Shen Qu
//ID#: 119418192
//Date: Nov 26, 2019
//OOP224 MS4
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include "PubRecord.h"
namespace sdds {
	class Book : public PubRecord {
		long long int ISBN;
		int memID;
		Date due;
	public:
		Book();
		Book(const Book&);
		Book& operator=(const Book&);
		char recID() const;
		int memberID() const;
		void checkIn();
		void checkOut();
		std::istream& read(std::istream& is = std::cin);
		std::ostream& write(std::ostream& os = std::cout) const;
	};
}
#endif // !SDDS_BOOK_H

