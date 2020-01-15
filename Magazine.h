//Name: Shen Qu
//ID#: 119418192
//Date: Nov 26, 2019
//OOP224 MS4
#ifndef SDDS_MAGAZINE_H
#define SDDS_MAGAZINE_H
#include "PubRecord.h"
namespace sdds {
	class Magazine : public PubRecord {
		int volume;
		int issueNum;
	public:
		Magazine();
		Magazine(const Magazine&);
		Magazine& operator=(const Magazine& m);
		char recID() const;
		void checkIn();
		void checkOut();
		std::istream& read(std::istream& is = std::cin);
		std::ostream& write(std::ostream& os = std::cout) const;
	};
}
#endif // !SDDS_MAGAZINE_H

