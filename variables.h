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


const int STU_mode = 0, TEACH_mode = 1, ADMIN_mode = 2, Max_sections = 10, Max_size[3] = { 50, 5, 3 };
int student_no, teach_no, admin_no, mode, curr_sec = 0;
const char Sec_list[Max_sections] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
const std::string Student_Cred_Folder = "Credentials/Sections/", Teacher_Cred_File = "Credentials/Teacher_Creds.txt", Admin_Cred_File = "Credentials/Admin_Creds.txt", settings_file = "Settings/saved.txt";

credentials Stu_Cred[Max_sections][50];
credentials Teach_Cred[5];
credentials Admin_Cred[3];
Settings saved;