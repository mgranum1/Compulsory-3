#include <iostream>
#include "header.h"
using namespace std;


Folder root("Archive");

Folder* CurrentlyIn = &root;

File* ListFiles;

void upFolder() {

	if (CurrentlyIn->getParent() != nullptr)

	CurrentlyIn = CurrentlyIn->getParent();

}

void changeFolder() {

	Folder* parentFolder = CurrentlyIn->ListFolder();
	
	if (parentFolder != nullptr) {
		CurrentlyIn = parentFolder;
	}
	else {
		cout << "Invalid choice for the parent folder.\n";
	}

}

void createFile() {

	string name;
	

	cout << "********************************************\n";

	cout << "Give the file a name: ";

	cin >> name;

	cout << '\n';

	cout << "Where would you like to store it: ";

	cout << '\n' ;

	Folder* parentFolder = CurrentlyIn->ListFolder();

	if (parentFolder != nullptr) {
	
		parentFolder->addFile(File(name)); //Adds file to the folder you picked
	}
	else {
		cout << "Invalid choice for the parent folder.\n";
	}
	

}


void createFolder() {
	string name;

	cout << "********************************************\n";
	cout << "Give the folder a name: ";
	cin >> name;

	cout << "Where would you like to store it: ";
	cout << "\n";

	Folder* parentFolder = CurrentlyIn->ListFolder();

	if (parentFolder != nullptr) {
		Folder* newFolder = new Folder(name);
		parentFolder->addFolder(newFolder);
	}
	else {
		cout << "Invalid choice for the parent folder.\n";
	}
}

void reNameFile() {

	string name;

	cout << "********************************************\n";

	cout << "Which file would you like to rename: \n";

	Folder* parentFolder = CurrentlyIn->ListFolder();

	cout << "Enter the new name for the folder: " << '\n';

	cin >> name;

	parentFolder->setName(name);

	
}

void reNameFolder() {

	string name;

	cout << "********************************************\n";

	cout << "Which folder would you like to rename: \n";

	Folder* parentFolder = CurrentlyIn->ListFolder();
	
	cout << "Enter the new name for the folder: " << '\n';

	cin >> name;

	parentFolder->setName(name);

}






int main()

{
	int choice;
	
	while (true) {
		cout << "********************************************\n";
		cout << " [1] - Check contents of a folder\n";
		cout << " [2] - Go out a folder\n";
		cout << " [3] - Go into a folder\n";
		cout << " [4] - Create a Folder\n";
		cout << " [5] - Create a File\n";
		cout << " [6] - Change the name of a Folder\n";
		cout << " [7] - Change the name of a File\n";
		cout << " [8] - Exit program\n";
		cout << "********************************************\n";
		cout << "Choose an option: ";
		cin >> choice;
		

		switch (choice) {

		case 1: 
			cout << "********************************************\n";
			cout << '\n';
			CurrentlyIn->printFolderInfo();
			cout << '\n';
			continue;

		case 2:
			upFolder();
			cout << '\n';
			continue;

		case 3:
			changeFolder();
			cout << '\n';
			continue;

		case 4: 
			createFolder();
			cout << '\n';
			continue;

		case 5: 
			createFile();
			cout << '\n';
			continue;

		case 6: 
			reNameFolder();
			cout << '\n';
			continue;


		case 7:
			reNameFile();
			cout << '\n';
			continue;

		case 8:

	    return 0;


		default:
			std::cout << "**************************************\n";
			std::cout << "Unvalid input, please try again.\n";

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		break;
	}
	return 0;
	
}


