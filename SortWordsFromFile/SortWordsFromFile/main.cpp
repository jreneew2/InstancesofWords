#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
int main() {
	std::ifstream fileToRead("we-choose-to-blow-u-the-moon.txt");
	std::string word;
	std::vector<std::string> wordArray;
	std::map<std::string, int> uniqueWords;
	if (fileToRead.is_open()) {
		while (fileToRead >> word) {
			word.erase(std::remove_if(word.begin(), word.end(), &ispunct), word.end());
			std::transform(word.begin(), word.end(), word.begin(), tolower);
			if (uniqueWords.find(word) == uniqueWords.end()) {
				uniqueWords[word] = 1;
			}
			else {
				uniqueWords[word]++;
			}
		}
	}
	for (const auto &currentString : uniqueWords) {
		std::cout << currentString.first << " appeared " << currentString.second << " times." << std::endl;
	}
	fileToRead.close();
	return 0;
}