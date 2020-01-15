//Name: Shen Qu
//ID#: 119418192
//Date: Nov 19, 2019
//OOP224 MS2
#include "ReadWriteable.h"
using namespace std;
namespace sdds {
	istream& operator>>(istream& is, ReadWriteable& r) {
		r.read(is);
		return is;
	}
	ostream& operator<<(ostream& os, const ReadWriteable& r) {
		r.write(os);
		return os;
	}
}