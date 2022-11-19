#pragma once // Only include the file once while compiling
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include "msclr/marshal_cppstd.h"
#include "variables.h"

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


void ReadMarks(ifstream& ifile, StuMarks student[], int size_arr, int subject_count, int quiz_count, int assignment_count) {
	for (int i = 0; i < size_arr; i++) {
		getline(ifile, student[i].id, '	');
		getline(ifile, student[i].name, '\n');
		for ( int j = 0; j < subject_count; j++){
			string tmp;
			
			for ( int k = 0; k < quiz_count; k++){
				getline(ifile, tmp, '	');
				if (tmp != "") student[i].quizzes[j][k] = stof(tmp);
				else student[i].quizzes[j][k] = 0;
			}

			getline(ifile, tmp, '	'); // extra seperator
			
			for (int k = 0; k < assignment_count; k++) {
				getline(ifile, tmp, '	');
				if (tmp != "") student[i].assignment[j][k] = stof(tmp);
				else student[i].assignment[j][k] = 0;
			}

			getline(ifile, tmp, '	'); // extra seperator
			
			getline(ifile, tmp, '	');
			if (tmp != "") student[i].mid1[j] = stof(tmp);
			else student[i].mid1[j] = 0;
			
			getline(ifile, tmp, '	');
			if (tmp != "") student[i].mid2[j] = stof(tmp);
			else student[i].mid2[j] = 0; 

			getline(ifile, tmp, '	'); // extra seperator
			
			getline(ifile, tmp, '	');
			if (tmp != "") student[i].finals[j] = stof(tmp);
			else student[i].finals[j] = 0;

			getline(ifile, tmp, '	'); // extra seperator

			getline(ifile, tmp, '	');
			if (tmp != "") student[i].total_obtained[j] = stof(tmp);
			else student[i].total_obtained[j] = 0;

			getline(ifile, tmp, '	'); // extra seperator
			
			getline(ifile, student[i].grade[j], '\n');

		}
	}
}

void WriteMarks(ofstream& ofile, StuMarks student[], int size_arr, Subjects& sub_details, int subject_count, int quiz_count, int assignment_count) {
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

			if ( sub_details.grading_enabled )
				ofile << student[i].grade[j] << '\n';
			else
				ofile << "NaN" << '\n';
			
		}
	}

}

void ReadAttendence(ifstream& ifile, Attendance student[], int max_students, int max_subjects, int max_weeks) {
	for (int i = 0; i < max_students; i++) {
		getline(ifile, student[i].id, '	');
		getline(ifile, student[i].name, '\n');
		for (int j = 0; j < max_subjects; j++) {
			for (int k = 0; k < max_weeks; k++) {
				getline(ifile, student[i].lec1[j][k], '	');
				;
				if (k == (max_weeks - 1))
					getline(ifile, student[i].lec2[j][k], '\n');
				else
					getline(ifile, student[i].lec2[j][k], '	');
			}
		}
	}
}

void WriteAttendence(ofstream& ofile, Attendance student[], int max_students,  int max_subjects, int max_weeks) {
	for (int i = 0; i < max_students; i++) {
		ofile << student[i].id << '	';
		ofile << student[i].name << '\n';
		for (int j = 0; j < max_subjects; j++) {


			for (int k = 0; k < max_weeks; k++) {
				ofile << student[i].lec1[j][k] << '	';
				ofile << student[i].lec2[j][k];
				if (k == (max_weeks - 1))
					ofile << '\n';
				else
					ofile << '	';
			}
		}
	}
}
void ReadSubjects(ifstream& ifile, Subjects sub[], int max_sub) {
	string tmp;
	for (int i = 0; i < max_sub; i++) {
		getline(ifile, sub[i].course_code, '	');
		getline(ifile, sub[i].name, '	');

		getline(ifile, tmp, '	');
		if ( tmp != "" ) sub[i].teach_no = stoi(tmp);
		else sub[i].teach_no = 0;

		getline(ifile, tmp, '	');
		if (tmp != "") sub[i].class_min = stof(tmp);
		else sub[i].class_min = 0;

		getline(ifile, tmp, '	');
		if (tmp != "") sub[i].class_max = stof(tmp);
		else sub[i].class_max = 0;

		getline(ifile, tmp, '	');
		if (tmp != "") sub[i].class_average = stof(tmp);
		else sub[i].class_average = 0;

		getline(ifile, tmp, '	');
		if (tmp != "") sub[i].std_dev = stof(tmp);
		else sub[i].std_dev = 0;

		getline(ifile, tmp, '	');
		if (tmp != "") sub[i].grading_enabled = stoi(tmp);
		else sub[i].grading_enabled = 0;

		getline(ifile, sub[i].grading, '\n');
	}
}

void WriteSubjects(ofstream& ofile, Subjects sub[], int max_sub) {
	for (int i = 0; i < max_sub; i++){
		ofile	<<	sub[i].course_code		<< '	';
		ofile	<<	sub[i].name				<< '	';
		ofile	<<	sub[i].teach_no			<< '	';
		ofile	<<	sub[i].class_min		<< '	';
		ofile	<<	sub[i].class_max		<< '	';
		ofile	<<	sub[i].class_average	<< '	';
		ofile	<<	sub[i].std_dev			<< '	';
		ofile	<<	sub[i].grading_enabled	<< '	';
		ofile	<<	sub[i].grading			<< '\n';
	}
}


void ReadSettings(ifstream& ifile, Settings &saved) {
	string tmp_input;
	getline(ifile, tmp_input, '\n');
	saved.sections = stoi(tmp_input);
	getline(ifile, tmp_input, '\n'); // Extra new line seperating everything
	for ( int i = 0; i < Max_Subjects; i++ ){
		for (int j = 0; j < Max_Quizzes; j++){
			if ( j == Max_Quizzes - 1) getline(ifile, tmp_input, '\n'); // the last value has an endl after it
			else getline(ifile, tmp_input, '	');
			if ( tmp_input != "" ) saved.quizzes[i][j] = stoi(tmp_input);
			else saved.quizzes[i][j] = 0;
		}
	}
	getline(ifile, tmp_input, '\n'); // Extra new line seperating everything
	for (int i = 0; i < Max_Subjects; i++) {
		for (int j = 0; j < Max_Assignments; j++) {
			if (j == Max_Assignments - 1) getline(ifile, tmp_input, '\n'); // the last value has an endl after it
			else getline(ifile, tmp_input, '	');
			if (tmp_input != "") saved.assignments[i][j] = stoi(tmp_input);
			else saved.assignments[i][j] = 0;
		}
	}
}

void WriteSettings(ofstream& ofile, Settings &saved) {
		ofile << saved.sections << '\n' << '\n';
		for ( int i = 0; i < Max_Subjects; i++ ){
			for (int j = 0; j < Max_Quizzes; j++){
				ofile << saved.quizzes[i][j];
				if (j == Max_Quizzes - 1) ofile << '\n';
				else ofile << '	';
			}
		}
		ofile << '\n';
		for (int i = 0; i < Max_Subjects; i++) {
			for (int j = 0; j < Max_Assignments; j++) {
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
		
		for (int k = 0; k < quiz_count; k++){
			sum += (quiz_total_weightage / quiz_count) * ((student[i].quizzes[curr_sub][k] / quiz_max_marks) * 100.0f);
		}
		for (int k = 0; k < assignment_count; k++){
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

void Calc_grade_relative(StuMarks student[], int size_class, Subjects &sub_details, int curr_sub, int quiz_count, int assignment_count) {
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
		} else if (sum > sub_details.class_max)
			sub_details.class_max = sum;
		else if (sum < sub_details.class_min)
			sub_details.class_min = sum;
	}

	sub_details.class_average = class_total / size_class;

	for (int i = 0; i < size_class; i++)
		sqr_total = sqr_total + float(pow((student[0].total_obtained[curr_sub] - sub_details.class_average), 2.0));
	
	sub_details.std_dev = sqrt(sqr_total / size_class);

	float bracket_limiter = ( (sub_details.class_max - sub_details.class_average) / sub_details.std_dev ) / 6; // 6 is half the (no. of grades + 1)

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