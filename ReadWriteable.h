//Name: Shen Qu
//ID#: 119418192
//Date: Nov 19, 2019
//OOP224 MS2
#ifndef SDDS_READWRITEABLE_H
#define SDDS_READWRITEABLE_H
#include <iostream>
namespace sdds {
	class ReadWriteable {
	public:
		virtual std::istream& read(std::istream& is = std::cin) = 0;
		virtual std::ostream& write(std::ostream& os = std::cout) const = 0;
	};
	std::istream& operator>>(std::istream&, ReadWriteable&);
	std::ostream& operator<<(std::ostream&, const ReadWriteable&);
}
#endif // !SDDS_READWRITEABLE_H

