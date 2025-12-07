#pragma once

#include <cassert>
#include <fstream>
#include <vector>
#include <string>

class Input {
private:
	static std::vector<std::string> getItems(
		const std::string& path, 
		const char delineator = '\n'
	) {
		std::ifstream input_file{ path };
		assert(input_file && "invalid path");

		std::string item{};
		std::vector<std::string> output{};
		
		while (std::getline(input_file, item, delineator)) {
			if (!item.empty()) {
				output.push_back(item);
			}
		}

		assert(output.size() != 0 && "file is empty");
		return output;
	}

public:
	static std::vector<int> getNegatedLStart(
		const std::string& path, const char delineator='\n'
	) {
		std::vector<std::string> items{ getItems(path, delineator) };
		std::vector<int> parsedItems{};

		for (std::string item: items) {
			int parsedItem{ std::stoi(item.substr(1)) };
			if (item[0] == 'L') { parsedItem *= -1; }
			parsedItems.push_back(parsedItem);
		}

		return parsedItems;
	}

	static std::vector<std::tuple<int, int>> getSingleHyphenSplit(
		const std::string& path, const char delineator = '\n'
	) {
		std::vector<std::string> items{ getItems(path, delineator) };
		std::vector<std::tuple<int, int>> parsedItems{};

		for (std::string item : items) {
			size_t i{ item.find('-') };
			assert(i != std::string::npos && "string does not contain hyphen");
			int s{ std::stoi(item.substr(0, i)) };
			int e{ std::stoi(item.substr(i + 1)) };
			std::tuple<int, int> parsedItem{ std::tuple<int, int>{ s, e } };
			parsedItems.push_back(parsedItem);
		}

		return parsedItems;
	}
};