//Name: Shen Qu
//ID#: 119418192
//Date: Nov 14, 2019
//OOP224 MS1
#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
namespace sdds {
#define MAX_MENU_ITEMS 20
	class Menu;
	
	class MenuItem {
		char* description;
		friend class Menu;
		MenuItem();
		MenuItem(const char*);
		~MenuItem();
		MenuItem(const MenuItem&) = delete;
		MenuItem& operator=(const MenuItem&) = delete;
		operator bool() const;
		operator const char* () const;
		std::ostream& display(std::ostream& os = std::cout) const;
	};

	class Menu {
		MenuItem title;
		MenuItem* menuitems[MAX_MENU_ITEMS];
		int numOfItem;

		Menu(const Menu& source) = delete;
		Menu& operator=(const Menu& source) = delete;

	public:
		Menu();
		Menu(const char*);
		~Menu();
		std::ostream& displayTitle(std::ostream& os = std::cout) const;
		std::ostream& display(std::ostream& os = std::cout) const;
		Menu& operator<<(const char*);
		unsigned int getSelection() const;
		unsigned int operator~() const;
		operator unsigned int() const;
		operator int() const;
		operator bool() const;
		
		const char* operator[](int) const;
	};
	std::ostream& operator<<(std::ostream&, Menu&);
}
#endif // !SDDS_MENU_H
