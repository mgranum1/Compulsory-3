#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <vector>
#include "ctime"
using namespace std;

//random number generator
int rNumber() {

	srand(time(0));

	int r_Number = (rand() % 100) + 1;
	
	return r_Number;
}

 
class File {

private:
	string fileName;
	string date;
	int size;

	void updateDate() {
		time_t now = time(0);
		date = ctime(&now);
	}

public:

	File() {}


	File(string n) {

		fileName = n;
		updateDate();
		size = rNumber();
		
	}
	
	void setFileName(const string& newName) {
		fileName = newName;
	}

	string getFileName() const {
		return fileName;

	}

	void printFileInfo() {

		cout << " * " << fileName << " " << size << " " << "MB" << " " << date << '\n';

	}

	
};


class Folder  { //Max 5 folders, with each of them containing 10 files

	private:
		File files[10];
		int fileCount = 0;
		int subFolderCount = 0;
		string folderName;
		string date;
		string fileName;
        Folder* subFolders[5];
		Folder* parentFolder = nullptr;
		File* listFiles;


		void updateDate() {
			time_t now = time(0);
			date = ctime(&now);
		}

    public:
		Folder(string name) {	
			folderName = name;
		}

		void setName(string name) {

			folderName = name;

	    }


		string getNameFolder() {

			return folderName;
		}

		string getNameFile() {

			return fileName;
		}

		Folder* ListFolder() { 

			int choice;

			cout << "1" << " - " <<  "Folder : "  << folderName << "  " << " | You are currently here |" << '\n';

		
			for (int i = 0; i < subFolderCount; i++) { //Lists all the subfolders

				cout << i + 2 << " - " << "Folder : " << subFolders[i]->getNameFolder() << '\n';
				
			}

			cin >> choice;
			if (choice == 1)
				return this;

			else if (choice != 1)
				return subFolders[choice-2];
		}

		File* ListFiles() {

			int choice;

			cout << "1" << " - " << "File : " << folderName << "  " << '\n';


			for (int i = 0; i < subFolderCount; i++) { //Lists all the subfolders

				cout << i + 2 << " - " << "File : " << subFolders[i]->getNameFile() << '\n';

			}

			cin >> choice;
			if (choice == 1)
				return 0;

		}

		void reNameFile() {
			string name;

			cout << "********************************************\n";
			cout << "Which file would you like to rename: \n";

			int choice;

			for (int i = 0; i < fileCount; i++) {
				cout << i + 1 << " - " << "File : " << files[i].getFileName() << '\n';
			}

			cin >> choice;

			if (choice >= 1 && choice <= fileCount) {
				cout << "Enter the new name for the file: ";
				cin >> name;
				files[choice - 1].setFileName(name);
			}
			else {
				cout << "Invalid choice for the file.\n";
			}
		}


		

		void printFolderInfo(){
		
			cout << " - This folder is named: " << folderName << '\n';

			for (int i = 0; i < fileCount; i++) {
			
				files[i].printFileInfo();
			}

			for (int i = 0; i < subFolderCount; i++) {

				subFolders[i]->printFolderInfo();
			}

		}

		void addFile(const File& F) {

			files[fileCount] = F;

			fileCount++;

		}

		Folder* getParent() {

			return parentFolder;

		}

		void setParent(Folder* folder) {

			parentFolder = folder;

		}

		void addFolder(Folder* FR) {

			subFolders[subFolderCount++] = FR;
			
			FR->setParent(this);

			
		}

};		









