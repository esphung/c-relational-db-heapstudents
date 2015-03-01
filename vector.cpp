// vector.cpp
#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

// class to stream info into the student constructor
class TextInfo
{
private:
	// vector is private member or TextInfo
	std::vector<std::string> new_data;
public:
	std::string const& operator[](std::size_t index) const
	{
		return new_data[index];
	}
	std::size_t size() const{
		return new_data.size();
	}


	void readNextLine(std::istream& str)
	{
		std::string 			line;
		std::getline(str,line);

		std::stringstream	lineStream(line);
		std::string 			cell;

		new_data.clear();
		while(std::getline(lineStream,cell,','))
		{
			new_data.push_back(cell);
		}
	}

// remove these egyption bracks for definiton elsewhere
	TextInfo(){};
	~TextInfo(){};

};// end TextInfo class

std::istream& operator >> (std::istream& str, TextInfo& data)
{
	data.readNextLine(str);
	return str;
} // end input stream



int main()
{
	string databaseFile			=	"data.dat";

	std::ifstream							file("data.dat");

	TextInfo									row;
	while(file >> row)
	{
		std::cout 	<< 	"Requested Entry : "	<<	row[1]	<< std::endl;
	}// end while

	/*
	last_name 		=  	row[0];
	first_name		=		row[1];
	first_address	=		row[2];
	second_address=		row[3];
	city					=		row[4];
	state					=		row[5];
	zipcode				=		row[6];
	birthday_date	=		row[7];
	completion_date =	row[8];
	gpa 					=		row[9];
	credit_hours	=		row[10];

	*/

	return 0;
}// end main
