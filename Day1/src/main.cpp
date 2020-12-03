#include <iostream>
#include <fstream>
#include <vector>

int main(){
	std::ifstream input("../input.txt");

	std::string line;
	std::vector<unsigned> entries;

	while(input >> line){
		entries.push_back(std::stoi(line));
	}

	// oh boy, n^2 complexity here I come
	for(int i = 0; i < entries.size(); i++){
		bool done = false;

		for(int j = 0; j < entries.size(); j++){
			if(entries[i] + entries[j] != 2020) continue;

			std::cout << entries[i] << " + " << entries[j] << " = 2020" << std::endl;
			std::cout << entries[i] << " * " << entries[j] << " = " << entries[i] * entries[j] << std::endl;

			done = true;
			break;
		}

		if(done) break;
	}

	// Part 2, n^3, *minecraft oof sound*
	for(int i = 0; i < entries.size(); i++){
		for(int j = 0; j < entries.size(); j++){
			for(int k = 0; k < entries.size(); k++){
				if(entries[i] + entries[j] + entries[k] != 2020) continue;

				std::cout << entries[i] << " + " << entries[j] << " + " << entries[k] << " = 2020" << std::endl;
				std::cout << entries[i] << " * " << entries[j] << " * " << entries[k] << " = " << entries[i] * entries[j] * entries[k] << std::endl;

				return 0;
			}
		}
	}

	return 0;
}
