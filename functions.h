#pragma once // Only include the file once while compiling
#include <fstream>
#include <string>
#include "msclr\marshal_cppstd.h"
#include "variables.h"

using std::ofstream;
using std::ifstream;
using std::string;
using System::String;

int authenticate(string username, string pass, credentials Categ_Cred[], int size_arr) {
	int no = -1;
	for (int i = 0; i < size_arr; i++) {
		if (username == Categ_Cred[i].username && pass == Categ_Cred[i].pass) {
			no = i;
			break;
		}
	}
	return no;
}


void ReadCredentials(ifstream& ifile, credentials category[], int size_arr) {
	for (int i = 0; i < size_arr; i++) {
		getline(ifile, category[i].id, '	');
		getline(ifile, category[i].username, '	');
		getline(ifile, category[i].pass, '	');
		getline(ifile, category[i].name, '\n');
	}
}

void WriteCredentials(ofstream& ofile, credentials category[], int size_arr) {
	for (int i = 0; i < size_arr; i++) {
		ofile << category[i].id << '	';
		ofile << category[i].username << '	';
		ofile << category[i].pass << '	';
		ofile << category[i].name << '\n';
	}
}

void ReadMarks(ifstream& ifile, StuMarks student[], int size_arr, int subject_count, int quiz_count) {
	for (int i = 0; i < size_arr; i++) {
		getline(ifile, student[i].id, '	');
		getline(ifile, student[i].name, '\n');
		for ( int j = 0; j < subject_count; j++){
			string tmp;
			for ( int k = 0; k < quiz_count; k++){
				getline(ifile, tmp, '	');
				if (tmp != "") student[i].quizzes[j][k] = stoi(tmp);
				else student[i].quizzes[j][k] = 0;
			}
			getline(ifile, tmp, '	');
			if (tmp != "") student[i].mid1[j] = stoi(tmp);
			else student[i].mid1[j] = 0;
			getline(ifile, tmp, '	');
			if (tmp != "") student[i].mid2[j] = stoi(tmp);
			else student[i].mid2[j] = 0; 
			getline(ifile, tmp, '\n');
			if (tmp != "") student[i].finals[j] = stoi(tmp);
			else student[i].finals[j] = 0;
		}
	}
}

void WriteMarks(ofstream& ofile, StuMarks student[], int size_arr, int subject_count, int quiz_count) {
	for (int i = 0; i < size_arr; i++) {
		ofile << student[i].id << '	';
		ofile << student[i].name << '\n';
		for (int j = 0; j < subject_count; j++) {
			for (int k = 0; k < quiz_count; k++)
				ofile << student[i].quizzes[j][k] << '	';

			ofile << student[i].mid1[j] << '	';
			ofile << student[i].mid2[j] << '	';
			ofile << student[i].finals[j] << '\n';
		}
	}

}
void ReadSettings(ifstream& ifile, Settings &saved) {	
	string tmp_input;
	getline(ifile, tmp_input, '\n');
	saved.sections = stoi(tmp_input);
	for ( int i = 0; i < Max_Subjects; i++ ){
		for (int j = 0; j < Max_Quizzes; j++){
			if ( j == Max_Quizzes - 1) getline(ifile, tmp_input, '\n'); // the last value has an endl after it
			else getline(ifile, tmp_input, '	');
			if ( tmp_input != "" ) saved.quizzes[i][j] = stoi(tmp_input);
			else saved.quizzes[i][j] = 0;
		}
	}
}

void WriteSettings(ofstream& ofile, Settings &saved) {
		ofile << saved.sections << '\n';
		for ( int i = 0; i < Max_Subjects; i++ ){
			for (int j = 0; j < Max_Quizzes; j++){
				ofile << saved.quizzes[i][j];
				if (j == Max_Quizzes - 1) ofile << '\n';
				else ofile << '	';
			}
		}
}

string System_to_std_string(String^ temp) {
	return msclr::interop::marshal_as<string>(temp);
}

String^ std_to_System_string(string temp) {
	return msclr::interop::marshal_as<String^>(temp);
}