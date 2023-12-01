#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <vector>
#include <ctype.h>

std::string FindDigits(std::string inputline){
	int i;
	std::vector<char> digits_in_line;
	std::string num_as_string;
	for (i=0; i<inputline.length(); i++) {
        if(std::isdigit(inputline[i])){
			digits_in_line.push_back(inputline[i]);
		}
	}
	num_as_string+=digits_in_line.front();
	num_as_string+=digits_in_line.back();
	return num_as_string;
}

int main() {
	//read in the input file and init as ifstream object
	std::ifstream inputlist("input.csv");
	std::string line;
	std::string text;
	std::vector<std::string> all_numbers_str; 
	std::vector<int> all_numbers_int;
	int total=0;
	//open input.csv file
	//inputlist.open(inputpath);
	while (getline(inputlist,text)){
		all_numbers_str.push_back(FindDigits(text));
	}
	for (std::string x: all_numbers_str){
		std::cout<<x<<std::endl;
		int num_as_int = stoi(x);
		all_numbers_int.push_back(num_as_int);
	}
	for (int x: all_numbers_int){
		std::cout<<total;
		total+=x;
		std::cout<<"+"<<x<<"="<<total<<std::endl;
	}
	std::cout<<total<<std::endl;
	inputlist.close();
	return 0;
}
