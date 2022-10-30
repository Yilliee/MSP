#pragma once
#include <string>
using std::string;

const int Max_Students = 50, Max_Teachers = 5, Max_Admins = 3, Max_Sections = 10, Max_Subjects = 5, Max_Quizzes = 10;
const int STU = 0, TEACH = 1, ADMIN = 2, SECTION = 3, SUBJECTS = 4, QUIZZES = 5,
			Absolute_Max_sizes[6] = { Max_Students, Max_Teachers, Max_Admins, Max_Sections, Max_Subjects, Max_Quizzes };
const int Exam_quiz = 0, Exam_mid1 = 1, Exam_mid2 = 2, Exam_final = 4;
const char Sec_list[Max_Sections]{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };

int student_no = -1, teach_no = -1, admin_no = -1, mode = -1, exam_type = -1, curr_sec = -1, curr_quiz = -1, curr_subject = -1;

const string Student_Cred_Folder = "Credentials/Sections/", Teacher_Cred_File = "Credentials/Teacher_Creds.txt", Admin_Cred_File = "Credentials/Admin_Creds.txt", settings_file = "Settings/saved.txt", Marks_Folder = "Marks/";

struct credentials {
	string id;
	string username;
	string pass;
	string name;
};

struct StuMarks {
	string id;
	string name;
	int quizzes[Max_Subjects][Max_Quizzes];
	int mid1[Max_Subjects];
	int mid2[Max_Subjects];
	int finals[Max_Subjects];
};



struct Settings {
	int sections;
	int quizzes[Max_Subjects][Max_Sections];
};

credentials Stu_Cred[Max_Sections][Max_Students];
credentials Teach_Cred[Max_Teachers];
credentials Admin_Cred[Max_Admins];
Settings saved;
StuMarks Student_marks[Max_Sections][Max_Students];