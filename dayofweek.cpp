// Author: Edison Suen

#include <iostream>
#include <string>
#include <map>
#include <cmath>

// Century term lookup
std::map<int,int> century_map =
	{
		{1799, 4},
		{1899, 2},
		{1999, 0},
		{2099, 6},
		{2199, 4}
	};

// Month term lookup
std::map<std::string, int> month_map = 
	{
		{"January", 0},
		{"February", 3},
		{"March", 3},
		{"April", 6},
		{"May", 1},
		{"June", 4},
		{"July", 6},
		{"August", 2},
		{"September", 5},
		{"October", 0},
		{"November", 3},
		{"December", 5}
	};

// Day term lookup
std::map<int, std::string> day_map = 
	{
		{0, "Sunday"},
		{1, "Monday"},
		{2, "Tuesday"},
		{3, "Wednesday"},
		{4, "Thursday"},
		{5, "Friday"},
		{6, "Saturday"}
	};

// Determine if the year is a leap year and act appropriately if so
bool leap_year(int year){
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
		return true;
	}else{
		return false;
	}
}

// Determine the century term 
int century_term(int year){
	auto x = std::lower_bound(century_map.begin(), century_map.end(),std::pair<const int, int>(year,0));
	return x->second;
}

int main(){

	std::string user_input;
	std::cout << "Enter date (format: Month Day, Year): ";
	getline(std::cin, user_input);

	// Delimiters for parsing of user input
	std::string delimiter_space = " ";
	std::string delimiter_comma = ",";

	// Parse user input to determine month, year, and day
	std::string month = user_input.substr(0, user_input.find(delimiter_space));
	std::string year = user_input.substr(user_input.find(delimiter_comma) + 2);
	std::string day = user_input.substr(user_input.find(delimiter_space) + 1, user_input.find(delimiter_comma) - user_input.find(delimiter_space));
	
	// Determine the last two digits of the year
	std::string last_two_digits_year;
	last_two_digits_year = year[2];
	last_two_digits_year += year[3];

	// Convert the year, day, and last_two_digits_year to integers
	int year_int = std::stoi(year);
	int day_int = std::stoi(day);
	int last_two_digits_year_int = std::stoi(last_two_digits_year);

	int div = std::floor(last_two_digits_year_int/4);

	if (leap_year(year_int)){
		month_map["January"] = 6;
		month_map["February"] = 2;
	}

	int calculate = century_term(year_int) + last_two_digits_year_int + div + month_map[month] + day_int;
	int calculate_mod = calculate%7;

	std::cout << day_map[calculate_mod] << std::endl;

	return 0;
}

