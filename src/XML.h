#ifndef XML_H_
#define XML_H_
#include <iostream>
#include "pugixml.hpp"
#include <fstream>


class XML {
	public:
		//Constructor
		XML();

		//Write in XML receive Credits(int), FlagsForPosition(int [][]);
		void Save_XML();
		void Read_XML();
	private:
		//Utility function
		std::string IntToString(int) const;
		std::string FloatToString(float number) const;
		//Documents
		pugi::xml_document doc;	
};

#endif
