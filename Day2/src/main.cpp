#include <iostream>
#include <fstream>

struct Entry {
	unsigned min;
	unsigned max;
	char letter;
	std::string password;
};

bool passValid1(const Entry& entry){
	unsigned occurences = 0;

	for(const char& letter : entry.password){
		occurences += letter == entry.letter;
	}

	return occurences >= entry.min && occurences <= entry.max;
}

bool passValid2(const Entry& entry){
	char a = entry.password[entry.min-1];
	char b = entry.password[entry.max-1];

	return (a == entry.letter || b == entry.letter) && a != b;
}

int main(){
	std::ifstream input("../input.txt");

	std::string part;
	unsigned valid1 = 0;
	unsigned valid2 = 0;
	while(input >> part){
		Entry entry;

		unsigned index = part.find('-');
		entry.min = std::stoi(part.substr(0, index));
		entry.max = std::stoi(part.substr(index+1));

		input >> part;
		entry.letter = part[0];

		input >> entry.password;

		valid1 += passValid1(entry);
		valid2 += passValid2(entry);
	}

	std::cout << "Valid passwords, part 1: " << valid1 << std::endl;
	std::cout << "Valid passwords, part 2: " << valid2 << std::endl;

	return 0;
}
