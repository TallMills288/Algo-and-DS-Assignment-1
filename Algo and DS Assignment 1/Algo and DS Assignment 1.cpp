#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

int main() {
	std::ifstream infile("Algo and DS Assignment 1\\product_data.txt");
	std::string line;

	if (!infile) {
		std::cerr << "Error opening file." << std::endl;
		return 1;
	}

	int currentSize = 50;
	std::string id[50]; //vectorize everything
	std::string name[50];
	std::string price[50];
	std::string category[50];
	
	int row = 0;
	int whatToDo;
	std::string newID;
	std::string newNAME;
	std::string newPRICE;
	std::string newCATEGORY;
	std::string searchData;

	while (std::getline(infile, line)) {
		std::stringstream ss(line);
		std::string dataPoint;
		int column = 0;

		while (std::getline(ss, dataPoint, ',')) {
			switch (column) {
			case 0:
				id[row] = dataPoint;
				break;
			case 1:
				name[row] = dataPoint;
				break;
			case 2:
				price[row] = dataPoint;
				break;
			case 3:
				category[row] = dataPoint;
				break;
			}
			column++;
		}

		row++;
	}

	infile.close();
	
	newcase:
	std::cout << "Enter 1 to add a new item, 2 to update an item, 3 to delete an item, 4 to search for an item, 5 to sort the dataset, or 6 to end the program." << std::endl;
	std::cin >> whatToDo;

	if (whatToDo > 5 || whatToDo < 1) {
		std::cout << "Invalid input." << std::endl;
		goto newcase;
	}

	switch (whatToDo) {
	case 1:
		currentSize++;

		std::string* newId = new std::string[currentSize];
		std::string* newName = new std::string[currentSize];
		std::string* newPrice = new std::string[currentSize];
		std::string* newCategory = new std::string[currentSize];

		std::cout << "Please enter the new item's ID number" << std::endl;
		std::cin >> newId[currentSize-1];
		std::cout << "Please enter the new item's name" << std::endl;
		std::cin >> newName[currentSize-1];
		std::cout << "Please enter the new item's price" << std::endl;
		std::cin >> newPrice[currentSize-1];
		std::cout << "Please enter the new item's category" << std::endl;
		std::cin >> newCategory[currentSize-1];

		for (int i = 0; i < currentSize - 1; i++) {
			newId[i] = id[i];
			newName[i] = name[i];
			newPrice[i] = price[i];
			newCategory[i] = category[i];
		}

		delete[] id;
		delete[] name;
		delete[] price;
		delete[] category;

		id = new std::string [51];
		name = newName;
		price = newPrice;
		category = newCategory;

		for (int i = 0; i < currentSize; i++) {
			id[i] = newId[i];
			name[i] = newName[i];
			price[i] = newPrice[i];
			category[i] = newCategory[i];
		}

		delete[] newId;
		delete[] newName;
		delete[] newPrice;
		delete[] newCategory;

		break;
	case 2:
		int search;
		int index;
		int edit;
		bool found = false;

		std::cout << "What is the ID of the product you would like to edit?" << std::endl;
		std::cin >> search;

		for (int i = 0; i < currentSize-1 || found == true; i++) {
			if (id[i] == std::to_string(search)) {
				index = i;
				found = true;
			}
		}

		std::cout << id[index] << ", " << name[index] << ", " << price[index] << ", " << category[index] << std::endl;

		badinput:
		std::cout << "What would you like to update? Enter 1 for the ID, 2 for the name, 3 for the price, and 4 for the category" << std::endl;
		std::cin >> edit;

		if (edit < 1 || edit > 4) {
			std::cout << "Invalid input." << std::endl;
			goto badinput;
		}

		switch (edit) {
		case 1:
			std::cout << "What would you like the new ID to be?" << std::endl;
			std::cin >> newID;

			id[index] = newID;
			break;
		case 2:
			std::cout << "What would you like the new name to be?" << std::endl;
			std::cin >> newNAME;

			name[index] = newNAME;
			break;
		case 3:
			std::cout << "What would you like the new price to be?" << std::endl;
			std::cin >> newPRICE;

			price[index] = newPRICE;
			break;
		case 4:
			std::cout << "What would you like the new category to be?" << std::endl;
			std::cin >> newCATEGORY;

			category[index] = newCATEGORY;
			break;
		}
		
		break;
	case 3:


		break;
	case 4:
		int choice;
		int index;
		int indices[50];
		int indicesIndex;
		int printNum;
		bool found = false;

		errorinput:
		std::cout << "How are you searching? Enter 1 for ID, 2 for name, 3 for price, or 4 for category." << std::endl;
		std::cin >> choice;

		if (choice < 1 || choice > 5) {
			goto errorinput;
		}

		switch (choice) {
		case 1:
			std::cout << "Please enter the ID of the item you are looking for." << std::endl;
			std::cin >> searchData;
			
			for (int i = 0; i < currentSize - 1 || found == true; i++) {
				if (id[i] == searchData) {
					index = i;
					found = true;
				}
			}

			if (found == false) {
				std::cout << "There is no item with that ID in the dataset. Please try again." << std::endl;
			}
			else {
				std::cout << "Item: " << id[index] << ", " << name[index] << ", " << price[index] << ", " << category[index] << std::endl;
			}

			break;
		case 2:
			std::cout << "Please enter the name of the item you are looking for." << std::endl;
			std::cin >> searchData;

			for (int i = 0; i < currentSize - 1 || found == true; i++) {
				if (name[i] == searchData) {
					index = i;
					found = true;
				}
			}

			if (found == false) {
				std::cout << "There is no item with that name in the dataset. Please try again." << std::endl;
			}
			else {
				std::cout << "Item: " << id[index] << ", " << name[index] << ", " << price[index] << ", " << category[index] << std::endl;
			}

			break;
		case 3:
			std::cout << "Please enter the price of the item you are looking for." << std::endl;
			std::cin >> searchData;

			for (int i = 0; i < currentSize - 1 || found == true; i++) {
				if (price[i] == searchData) {
					index = i;
					found = true;
				}
			}

			if (found == false) {
				std::cout << "There is no item with that price in the dataset. Please try again." << std::endl;
			}
			else {
				std::cout << "Item: " << id[index] << ", " << name[index] << ", " << price[index] << ", " << category[index] << std::endl;
			}

			break;
		case 4:
			std::cout << "Please enter the category of the item you are looking for." << std::endl;
			std::cin >> searchData;

			for (int i = 0; i < currentSize - 1 || found == true; i++) {
				if (id[i] == searchData) {
					indices[indicesIndex] = i;
					found = true;
					indicesIndex++;
					printNum++;
				}
			}

			if (found == false) {
				std::cout << "There is no item with that ID in the dataset. Please try again." << std::endl;
			}
			else {
				std::cout << "We found the following items in that category: " << std::endl;
				for (int i = 0; i < printNum - 1; i++) {
					std::cout << "Item: " << id[indices[i]] << ", " << name[indices[i]] << ", " << price[indices[i]] << ", " << category[indices[i]] << std::endl;
				}
			}

			break;
		}

		break;
	case 5:

		break;
	case 6:
		return 0;
	}
	//insertion sort is one line apparently? Joey lied, it's more
}