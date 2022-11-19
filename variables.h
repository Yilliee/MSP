#pragma once
#include <string>
using std::string;

const int Max_Students = 50, Max_Teachers = 10, Max_Admins = 3, Max_Sections = 10, Max_Subjects = 5, Max_Quizzes = 10, Max_Assignments = 10, Max_Weeks = 16;
const int STU = 0, TEACH = 1, ADMIN = 2, SECTION = 3, SUBJECTS = 4, QUIZZES = 5, ASSIGNMENTS = 6,  WEEKS = 7, Max_subject_per_teacher = 5,
			Absolute_Max_sizes[8] = { Max_Students, Max_Teachers, Max_Admins, Max_Sections, Max_Subjects, Max_Quizzes, Max_Assignments, Max_Weeks };
const int Exam_quiz = 0, Exam_assignment = 1, Exam_mid1 = 2, Exam_mid2 = 3, Exam_final = 4;
const float quiz_total_weightage = 0.10f, assignment_total_weightage = 0.10f, mid_weightage = 0.15f, final_weightage = 0.50f;
const float quiz_max_marks = 10, assignment_max_marks = 10, mid_max_marks = 30, final_max_marks = 100,
			Max_marks[5] = {quiz_max_marks, assignment_max_marks, mid_max_marks, mid_max_marks, final_max_marks};
const char Sec_list[Max_Sections]{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };

int student_no = -1, teach_no = -1, admin_no = -1, mode = -1, exam_type = -1, curr_sec = -1, curr_quiz = -1, curr_assignment = -1, curr_subject = -1;

const string Student_Cred_Folder = "Credentials/Sections/", Teacher_Cred_File = "Credentials/Teacher_Creds.txt",
				Admin_Cred_File = "Credentials/Admin_Creds.txt", settings_file = "Settings/saved.txt", Marks_Folder = "Marks/",
				Subject_Folder = "Subjects/Sections/", Attendance_Folder = "Attendance/Sections/";

struct credentials {
	string id;
	string username;
	string pass;
	string name;
};

struct StuMarks {
	string id;
	string name;
	float quizzes[Max_Subjects][Max_Quizzes];
	float assignment[Max_Subjects][Max_Quizzes];
	float mid1[Max_Subjects];
	float mid2[Max_Subjects];
	float finals[Max_Subjects];
	float total_obtained[Max_Subjects];
	string grade[Max_Subjects];
};

struct Attendance {
	string id;
	string name;
	string lec1[Max_Subjects][Max_Weeks];
	string lec2[Max_Subjects][Max_Weeks];
};

struct Subjects {
	string course_code;
	string name;
	int teach_no;
	float class_min;
	float class_max;
	float class_average;
	float std_dev;
	bool grading_enabled = false;
	string grading;
};

struct Settings {
	int sections;
	int quizzes[Max_Subjects][Max_Sections];
	int assignments[Max_Subjects][Max_Sections];
};

credentials Stu_Cred[Max_Sections][Max_Students];
credentials Teach_Cred[Max_Teachers];
credentials Admin_Cred[Max_Admins];
Settings saved;
StuMarks Student_marks[Max_Sections][Max_Students];
Attendance Student_att[Max_Sections][Max_Students];
Subjects subjects_details[Max_Sections][Max_Subjects];