#pragma once // Only include the file once while compiling
#include <fstream>
#include <string>
#include "msclr\marshal_cppstd.h"
#include "variables.h"

int authenticate(std::string username, std::string pass, credentials Categ_Cred[], int size_arr) {
	int no = -1;
	for (int i = 0; i < size_arr; i++) {
		if (username == Categ_Cred[i].username && pass == Categ_Cred[i].pass) {
			no = i;
			break;
		}
	}
	return no;
}


void ReadCredentials(std::ifstream& ifile, credentials category[], int size_arr) {
	for (int i = 0; i < size_arr; i++) {
		getline(ifile, category[i].username, '	');
		getline(ifile, category[i].pass, '	');
		getline(ifile, category[i].name, '\n');
	}
}

void WriteCredentials(std::ofstream& ofile, credentials category[], int size_arr) {
	for (int i = 0; i < size_arr; i++) {
		ofile << category[i].username << '	';
		ofile << category[i].pass << '	';
		ofile << category[i].name << '\n';
	}
}

void ReadSettings(std::ifstream& ifile, Settings* saved) {	
	//getline(ifile, saved.sections, '\n');
	ifile >> (*saved).sections;
}

void WriteSettings(std::ofstream& ofile, Settings saved) {
		ofile << saved.sections << '	';
}

std::string System_to_std_string(System::String^ temp) {
	return msclr::interop::marshal_as<std::string>(temp);
}

System::String^ std_to_System_string(std::string temp) {
	return msclr::interop::marshal_as<System::String^>(temp);
}