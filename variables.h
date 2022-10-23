#pragma once
#include <string>

struct credentials {
	std::string username;
	std::string pass;
	std::string name;
};

credentials Stu_Cred[50];
credentials Teach_Cred[5];
credentials Admin_Cred[3];

const int STU_mode = 0, TEACH_mode = 1, ADMIN_mode = 2;
int Max_size[3] = { 50, 5, 3 };
int student_no, teach_no, admin_no, mode;
std::string Student_Cred_File = "Credentials/Student_Creds.txt", Teacher_Cred_File = "Credentials/Teacher_Creds.txt", Admin_Cred_File = "Credentials/Admin_Creds.txt";
