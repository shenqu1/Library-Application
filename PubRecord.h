//Name: Shen Qu
//ID#: 119418192
//Date: Nov 26, 2019
//OOP224 MS4
#ifndef SDDS_PUBRECORD_H
#define SDDS_PUBRECORD_H
#include <iostream>
#include "ReadWriteable.h"
#include "Date.h"
namespace sdds {
#define SDDS_CONSOLE 1
#define SDDS_FILE 2
	class PubRecord : public ReadWriteable {
		char* pubName;
		int shelfNumber;
		int type;
	protected:
		void name(const char*);
		char* name() const;
		void shelfNo(int);
	public:
		virtual char recID() const = 0;
		virtual void checkIn() = 0;
		virtual void checkOut() = 0;
		PubRecord();
		PubRecord(const PubRecord&);
		virtual ~PubRecord();
		PubRecord& operator=(const PubRecord& source);
		void mediaType(int);
		int mediaType() const;
		int shelfNo() const;
		void readShelfNo();
		bool operator==(char) const;
		bool operator==(const char*) const;
		operator bool() const;
		
	};
}
#endif // !SDDS_PUBRECORD_H

