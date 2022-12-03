#pragma once // Only include the file once while compiling
#include <fstream>
#include <string>
#include <iomanip>
#include <filesystem>
#include <sstream>
#include "msclr/marshal_cppstd.h"
#include "variables.h"

using std::filesystem::create_directories;
using std::ofstream;
using std::ifstream;
using std::string;
using System::String;
using msclr::interop::marshal_as;

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


void getline(ifstream& ifile, float& var, char delim) {
	string tmp;
	getline(ifile, tmp, delim);
	if (tmp != "") var = stof(tmp);
	else var = 0;
}
void getline(ifstream& ifile, int& var, char delim) {
	string tmp;
	getline(ifile, tmp, delim);
	if (tmp != "") var = stoi(tmp);
	else var = 0;
}
void getline(ifstream& ifile, bool& var, char delim) {
	string tmp;
	getline(ifile, tmp, delim);
	if (tmp != "") var = stoi(tmp);
	else var = 0;
}


void ReadCredentials(ifstream& ifile, credentials category[], int size_arr) {
	for (int i = 0; i < size_arr; i++) {
		getline(ifile, category[i].id, '	');
		getline(ifile, category[i].username, '	');
		getline(ifile, category[i].pass, '	');
		getline(ifile, category[i].name, '\n');
	}
}
void WriteCredentials(string Folder, string File, credentials category[], int size_arr) {
	ofstream ofile;

	// Create the directory if it doesn't exist
	create_directories(Folder.c_str());

	ofile.open(Folder + File);

	for (int i = 0; i < size_arr; i++) {
		ofile << category[i].id << '	';
		ofile << category[i].username << '	';
		ofile << category[i].pass << '	';
		ofile << category[i].name << '\n';
	}

	ofile.close();
}


void ReadMarks(ifstream& ifile, StuMarks student[], int size_arr, int subject_count, int quiz_count, int assignment_count) {
	for (int i = 0; i < size_arr; i++) {
		getline(ifile, student[i].id, '	');
		getline(ifile, student[i].name, '\n');
		for (int j = 0; j < subject_count; j++) {
			string tmp;

			for (int k = 0; k < quiz_count; k++) {
				getline(ifile, student[i].quizzes[j][k], '	');
			}

			getline(ifile, tmp, '	'); // extra seperator

			for (int k = 0; k < assignment_count; k++) {
				getline(ifile, student[i].assignment[j][k], '	');
			}

			getline(ifile, tmp, '	'); // extra seperator

			getline(ifile, student[i].mid1[j], '	');

			getline(ifile, student[i].mid2[j], '	');

			getline(ifile, tmp, '	'); // extra seperator

			getline(ifile, student[i].finals[j], '	');

			getline(ifile, tmp, '	'); // extra seperator

			getline(ifile, student[i].total_obtained[j], '	');

			getline(ifile, tmp, '	'); // extra seperator

			getline(ifile, student[i].grade[j], '\n');

		}
	}
}
void WriteMarks(string Folder, string File, StuMarks student[], int size_arr, Subjects& sub_details, int subject_count, int quiz_count, int assignment_count) {
	ofstream ofile;

	// Create the directory if it doesn't exist
	create_directories(Folder.c_str());

	ofile.open(Folder + File);

	ofile << std::fixed << std::setprecision(2);
	for (int i = 0; i < size_arr; i++) {
		ofile << student[i].id << '	';
		ofile << student[i].name << '\n';
		for (int j = 0; j < subject_count; j++) {
			for (int k = 0; k < quiz_count; k++)
				ofile << student[i].quizzes[j][k] << '	';
							ofile << '	'; // Seperator

			for (int k = 0; k < assignment_count; k++)
				ofile << student[i].assignment[j][k] << '	';
			
			ofile << '	'; // Seperator
			
			ofile << student[i].mid1[j] << '	';
			ofile << student[i].mid2[j] << '	';

			ofile << '	'; // Seperator

			ofile << student[i].finals[j] << '	';

			ofile << '	'; // Seperator

			ofile << student[i].total_obtained[j] << '	';

			ofile << '	'; // Seperator

			if (sub_details.grading_enabled)
				ofile << student[i].grade[j] << '\n';
			else
				ofile << "NaN" << '\n';

		}
	}
	ofile.close();
}

void ReadAttendence(ifstream& ifile, Attendance student[], int max_students, int max_subjects, int max_weeks, int Lec_per_Week) {
	for (int i = 0; i < max_students; i++) {
		getline(ifile, student[i].id, '	');
		getline(ifile, student[i].name, '\n');
		for (int j = 0; j < max_subjects; j++) {
			for (int k = 0; k < max_weeks; k++) {
				for (int l = 0; l < Lec_per_Week; l++){
					if ( (l == Lec_per_Week - 1) && (k == max_weeks - 1) )
						getline(ifile, student[i].lec[j][k][l], '\n');
					else
						getline(ifile, student[i].lec[j][k][l], '	');
				}
			}
		}
	}
}
void WriteAttendence(string Folder, string File, Attendance student[], int max_students, int max_subjects, int max_weeks, int Lec_per_Week) {
	ofstream ofile;

	// Create the directory if it doesn't exist
	create_directories(Folder.c_str());

	ofile.open(Folder + File);

	for (int i = 0; i < max_students; i++) {
		ofile << student[i].id << '	';
		ofile << student[i].name << '\n';
		for (int j = 0; j < max_subjects; j++) {
			for (int k = 0; k < max_weeks; k++) {
				for ( int l = 0; l < Lec_per_Week; l++ ){
					ofile << student[i].lec[j][k][l];
					if ( (l == Lec_per_Week - 1) && (k == max_weeks - 1) )
						ofile << '\n';
					else
						ofile << '	';

				}
							}
		}
	}

	ofile.close();

}


void ReadSubjects(ifstream& ifile, Subjects sub[], int max_sub) {
	string tmp;
	for (int i = 0; i < max_sub; i++) {
		getline(ifile, sub[i].course_code, '	');
		getline(ifile, sub[i].name, '	');

		getline(ifile, sub[i].teach_no, '	');

		getline(ifile, sub[i].class_min, '	');

		getline(ifile, sub[i].class_max, '	');

		getline(ifile, sub[i].class_average, '	');

		getline(ifile, sub[i].std_dev, '	');

		getline(ifile, sub[i].grading_enabled, '	');

		getline(ifile, sub[i].grading, '\n');
	}
}
void WriteSubjects(string Folder, string File, Subjects sub[], int max_sub) {
	ofstream ofile;

	// Create the directory if it doesn't exist
	create_directories(Folder.c_str());

	ofile.open(Folder + File);

	for (int i = 0; i < max_sub; i++) {
		ofile << sub[i].course_code << '	';
		ofile << sub[i].name << '	';
		ofile << sub[i].teach_no << '	';
		ofile << sub[i].class_min << '	';
		ofile << sub[i].class_max << '	';
		ofile << sub[i].class_average << '	';
		ofile << sub[i].std_dev << '	';
		ofile << sub[i].grading_enabled << '	';
		ofile << sub[i].grading << '\n';
	}
}

void ReadSettings(ifstream& ifile, Settings& saved) {
	string tmp_input;
	getline(ifile, tmp_input, '\n');
	saved.sections = stoi(tmp_input);

	getline(ifile, tmp_input, '\n'); // Extra new line seperating everything

	for (int i = 0; i < Max_Subjects; i++) {
		for (int j = 0; j < Max_Sections; j++) {

			if (j == Max_Sections - 1) {
				getline(ifile, saved.quizzes[i][j], '\n'); // the last value has an endl after it
			}
			else {
				getline(ifile, saved.quizzes[i][j], '	');
			}
		}
	}
	getline(ifile, tmp_input, '\n'); // Extra new line seperating everything

	for (int i = 0; i < Max_Subjects; i++) {
		for (int j = 0; j < Max_Sections; j++) {
			if (j == Max_Sections - 1) getline(ifile, saved.assignments[i][j], '\n'); // the last value has an endl after it
			else getline(ifile, saved.assignments[i][j], '	');
		}
	}
}
void WriteSettings(string Folder, string File, Settings& saved) {
	ofstream ofile;

	// Create the directory if it doesn't exist
	create_directories(Folder.c_str());

	ofile.open(Folder + File);

	ofile << saved.sections << '\n' << '\n';
	for (int i = 0; i < Max_Subjects; i++) {
		for (int j = 0; j < Max_Sections; j++) {
			ofile << saved.quizzes[i][j];
			if (j == Max_Sections - 1) ofile << '\n';
			else ofile << '	';
		}
	}
	ofile << '\n';
	for (int i = 0; i < Max_Subjects; i++) {
		for (int j = 0; j < Max_Sections; j++) {
			ofile << saved.assignments[i][j];
			if (j == Max_Assignments - 1) ofile << '\n';
			else ofile << '	';
		}
	}

}


void Calc_grade_absolute(StuMarks student[], int size_arr, Subjects& sub_details, int curr_sub, int quiz_count, int assignment_count) {
	if (!sub_details.grading_enabled)
		sub_details.grading_enabled = true;

	for (int i = 0; i < size_arr; i++) {
		float sum = 0;
		string grade;

		for (int k = 0; k < quiz_count; k++) {
			sum += (quiz_total_weightage / quiz_count) * ((student[i].quizzes[curr_sub][k] / quiz_max_marks) * 100.0f);
		}
		for (int k = 0; k < assignment_count; k++) {
			sum += (assignment_total_weightage / assignment_count) * ((student[i].assignment[curr_sub][k] / assignment_max_marks) * 100.0f);
		}
		sum += mid_weightage * ((student[i].mid1[curr_sub] / mid_max_marks) * 100.0f);
		sum += mid_weightage * ((student[i].mid2[curr_sub] / mid_max_marks) * 100.0f);
		sum += final_weightage * ((student[i].finals[curr_sub] / final_max_marks) * 100.0f);

		if (sum >= 90) grade = "A+";
		else if (sum >= 86) grade = "A";
		else if (sum >= 82) grade = "A-";
		else if (sum >= 78) grade = "B+";
		else if (sum >= 74) grade = "B";
		else if (sum >= 70) grade = "B-";
		else if (sum >= 66) grade = "C+";
		else if (sum >= 62) grade = "C";
		else if (sum >= 58) grade = "C-";
		else if (sum >= 54) grade = "D+";
		else if (sum >= 50) grade = "D";
		else grade = "F";

		student[i].total_obtained[curr_sub] = sum;
		student[i].grade[curr_sub] = grade;
	}
}
void Calc_grade_relative(StuMarks student[], int size_class, Subjects& sub_details, int curr_sub, int quiz_count, int assignment_count) {
	if (!sub_details.grading_enabled)
		sub_details.grading_enabled = true;

	float class_total = 0, sqr_total = 0;

	sub_details.class_min = -1;
	sub_details.class_max = -1;

	for (int i = 0; i < size_class; i++) {
		float sum = 0;
		string grade;

		for (int k = 0; k < quiz_count; k++)
			sum += (quiz_total_weightage / quiz_count) * ((student[i].quizzes[curr_sub][k] / quiz_max_marks) * 100);
		for (int k = 0; k < assignment_count; k++)
			sum += (assignment_total_weightage / assignment_count) * ((student[i].assignment[curr_sub][k] / assignment_max_marks) * 100);
		sum += mid_weightage * ((student[i].mid1[curr_sub] / mid_max_marks) * 100);
		sum += mid_weightage * ((student[i].mid2[curr_sub] / mid_max_marks) * 100);
		sum += final_weightage * ((student[i].finals[curr_sub] / final_max_marks) * 100);

		student[i].total_obtained[curr_sub] = sum;
		class_total += sum;

		if (i == 0) {
			sub_details.class_max = sum;
			sub_details.class_min = sum;
		}
		else if (sum > sub_details.class_max)
			sub_details.class_max = sum;
		else if (sum < sub_details.class_min)
			sub_details.class_min = sum;
	}

	sub_details.class_average = class_total / size_class;

	for (int i = 0; i < size_class; i++)
		sqr_total = sqr_total + float(pow((student[0].total_obtained[curr_sub] - sub_details.class_average), 2.0));

	sub_details.std_dev = sqrt(sqr_total / size_class);

	float bracket_limiter = ((sub_details.class_max - sub_details.class_average) / sub_details.std_dev) / 6; // 6 is half the (no. of grades + 1)

	for (int i = 0; i < size_class; i++) {
		if (student[i].total_obtained[curr_sub] > (sub_details.class_average + 6 * bracket_limiter * sub_details.std_dev))
			student[i].grade[curr_sub] = "A+";
		else if (student[i].total_obtained[curr_sub] > (sub_details.class_average + 5 * bracket_limiter * sub_details.std_dev))
			student[i].grade[curr_sub] = "A";
		else if (student[i].total_obtained[curr_sub] > (sub_details.class_average + 4 * bracket_limiter * sub_details.std_dev))
			student[i].grade[curr_sub] = "A-";
		else if (student[i].total_obtained[curr_sub] > (sub_details.class_average + 2.75 * bracket_limiter * sub_details.std_dev))
			student[i].grade[curr_sub] = "B+";
		else if (student[i].total_obtained[curr_sub] > (sub_details.class_average + 1.5 * bracket_limiter * sub_details.std_dev))
			student[i].grade[curr_sub] = "B";
		else if (student[i].total_obtained[curr_sub] > (sub_details.class_average - 0.5 * bracket_limiter * sub_details.std_dev))
			student[i].grade[curr_sub] = "B-";
		else if (student[i].total_obtained[curr_sub] > (sub_details.class_average - 1.5 * bracket_limiter * sub_details.std_dev))
			student[i].grade[curr_sub] = "C+";
		else if (student[i].total_obtained[curr_sub] > (sub_details.class_average - 2.25 * bracket_limiter * sub_details.std_dev))
			student[i].grade[curr_sub] = "C";
		else if (student[i].total_obtained[curr_sub] > (sub_details.class_average - 3 * bracket_limiter * sub_details.std_dev))
			student[i].grade[curr_sub] = "C-";
		else if (student[i].total_obtained[curr_sub] > (sub_details.class_average - 4 * bracket_limiter * sub_details.std_dev))
			student[i].grade[curr_sub] = "D+";
		else if (student[i].total_obtained[curr_sub] > (sub_details.class_average - 5 * bracket_limiter * sub_details.std_dev))
			student[i].grade[curr_sub] = "D";
		else
			student[i].grade[curr_sub] = "F";
	}

}

void Calc_total(StuMarks student[], int size_class, int curr_sub, int quiz_count, int assignment_count) {
	for (int i = 0; i < size_class; i++) {
		float sum = 0;

		for (int k = 0; k < quiz_count; k++)
			sum += (quiz_total_weightage / quiz_count) * ((student[i].quizzes[curr_sub][k] / quiz_max_marks) * 100);
		for (int k = 0; k < assignment_count; k++)
			sum += (assignment_total_weightage / assignment_count) * ((student[i].assignment[curr_sub][k] / assignment_max_marks) * 100);
		sum += mid_weightage * ((student[i].mid1[curr_sub] / mid_max_marks) * 100);
		sum += mid_weightage * ((student[i].mid2[curr_sub] / mid_max_marks) * 100);
		sum += final_weightage * ((student[i].finals[curr_sub] / final_max_marks) * 100);

		student[i].total_obtained[curr_sub] = sum;
	}
}


string Stos(String^ temp) {
	return marshal_as<string>(temp);
}

String^ stoS(string temp) {
	return marshal_as<String^>(temp);
}

string to_string_with_precision(const double num, const int n = 2)
{
	std::ostringstream conversion;
	conversion.precision(n);
	conversion << std::fixed << num;
	return conversion.str();
}