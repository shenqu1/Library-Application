//Name: Shen Qu
//ID#: 119418192
//Date: Nov 14, 2019
//OOP224 MS1
#ifndef SDDS_UTLLS_H
#define SDDS_UTILS_H
namespace sdds {
	void readint(unsigned int& val, unsigned int min, unsigned int max, const char* errorMessage = "");
	void readlongint(long long int& val, long long int min, long long int max, const char* errorMessage = "");
	void copystr(char*& dest, const char* src);
	void readstr(char* str, int len, const char* errorMessage = "");
}
#endif // !SDDS_UTLLS_H
