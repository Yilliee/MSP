#pragma once
#include <string>

struct credentials {
	std::string username;
	std::string pass;
	std::string name;
};

struct Settings {
	int sections;
};


const int STU = 0, TEACH = 1, ADMIN = 2, SECTION = 3, Absolute_Max_sizes[4] = { 50, 5, 3, 10 };
int student_no, teach_no, admin_no, mode, curr_sec = 0;
const char* Sec_list = new char[Absolute_Max_sizes[SECTION]]{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
const std::string Student_Cred_Folder = "Credentials/Sections/", Teacher_Cred_File = "Credentials/Teacher_Creds.txt", Admin_Cred_File = "Credentials/Admin_Creds.txt", settings_file = "Settings/saved.txt";

credentials Stu_Cred[10][50];
credentials Teach_Cred[5];
credentials Admin_Cred[3];
Settings saved;