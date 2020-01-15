//Name: Shen Qu
//ID#: 119418192
//Date: Nov 14, 2019
//OOP224 MS1
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
#include "Menu.h"
#include "Utils.h"
namespace sdds {
	MenuItem::MenuItem() {
		description = nullptr;
	}
	MenuItem::MenuItem(const char* des) {
		description = nullptr;
		copystr(description, des);	
	}
	MenuItem::~MenuItem() {
		delete[] description;
	}
	MenuItem::operator bool() const {
		return description && description[0] != '\0';
	}
	MenuItem::operator const char* () const {
		return (const char*)description;
	}
	ostream& MenuItem::display(ostream& os) const {
		os << description;
		return os;
	}
	Menu::Menu() {
		for (int i = 0; i < MAX_MENU_ITEMS; i++) {
			menuitems[i] = nullptr;
		}
		
		numOfItem = 0;
	}
	Menu::Menu(const char* t) {
		for (int i = 0; i < MAX_MENU_ITEMS; i++) {
			menuitems[i] = nullptr;
		}
		numOfItem = 0;
		copystr(title.description, t);
	}
	Menu::~Menu() {
		for (int i = 0; i < MAX_MENU_ITEMS; i++) {
			delete menuitems[i];
		}
	}
	ostream& Menu::displayTitle(ostream& os) const {
		if (*this) {
			title.display(os);
		}
		return os;
	}
	ostream& Menu::display(ostream& os) const {
	
			if (title != nullptr) {
				displayTitle(os) << ":" << endl;
			}
			for (int i = 0; i < numOfItem; i++) {
				os << " " << i + 1 << "- ";
				menuitems[i]->display(os) << endl;
			}
			os << " 0- Exit" << "\n" << "> ";
		
		return os;
	}
	Menu& Menu::operator<<(const char* mi){
		if (mi && mi[0] != '\0') {
			if (numOfItem < MAX_MENU_ITEMS) {
				menuitems[numOfItem] = new MenuItem(mi);
				//copystr(menuitems[numOfItem]->description, mi);
				numOfItem += 1;								
			}
		}
		return *this;
	}
	unsigned int Menu::getSelection() const {
		display();
		unsigned int selection;
		readint(selection, 0, (unsigned int)numOfItem, "Invalid Selection, try again: ");
		return selection;
	}
	unsigned int Menu::operator~() const {
		return getSelection();
	}
	Menu::operator unsigned int() const {
		return numOfItem;
	}
	Menu::operator int() const {
		return numOfItem;
	}
	Menu::operator bool() const {
		return numOfItem != 0;
	}
	ostream& operator<<(ostream& os, Menu& m){
		m.displayTitle();
		return os;
	}
	const char* Menu::operator[](int n) const {
		n = n >= numOfItem ? 0 : n;
		return menuitems[n]->description;
	}
}