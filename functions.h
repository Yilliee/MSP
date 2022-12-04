#pragma once // Only include the file once while compiling

#include <fstream>
#include <string>
#include <iomanip>
#include <filesystem>
#include <sstream>
#include "variables.h"
#include "msclr/marshal_cppstd.h"

using std::filesystem::create_directories;
using std::ofstream;
using std::ifstream;
using std::string;
using System::String;
using msclr::interop::marshal_as;

// Check if the given username and pass match any entry in the Cred array and if they do,
// then return their index
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


// string to int convertor
int stoi_c(string number) {
	int num = 0;
	bool negative = false;

	for (int i = 0; number[i] != '\0'; i++) {
		if (number[i] >= '0' && number[i] <= '9')
			num = (num * 10) + (number[i] - '0');
		else if (num == 0 && number[i] == '-') {
			negative = true;
			continue;
		}
		else if (num == 0)
			continue;
		else
			break;
	}
	if (negative)
		return num * -1;
	else
		return num;

}


// string to double convertor
double stod_c(string number) {
	double num = 0, decimal_part = 0.1;
	bool negative = false, decimal = false;;

	for (int i = 0; number[i] != '\0'; i++) {
		if (number[i] >= '0' && number[i] <= '9') {
			if (!decimal)
				num = (num * 10) + (number[i] - 48);
			else {
				num += (number[i] - 48) * decimal_part;
				decimal_part /= 10;
			}
		}
		else if (number[i] == '.' && !decimal)
			decimal = true;
		else if (num == 0 && number[i] == '-')
			negative = true;
		else
			break;
	}
	if (negative)
		return num * -1;
	else
		return num;

}

float stof_c(string number) {
	return float(stod_c(number));
}

// round off function
int roundoff(float num) {
	if ((num - (int)num) > 0.5)
		return ((int)num + 1);
	else
		return (int)num;
}

// getline overloads - start
void getline(ifstream& ifile, float& var, char delim) {
	string tmp;
	getline(ifile, tmp, delim);
	if (tmp != "") var = stof_c(tmp);
	else var = 0;
}
void getline(ifstream& ifile, int& var, char delim) {
	string tmp;
	getline(ifile, tmp, delim);
	if (tmp != "") var = stoi_c(tmp);
	else var = 0;
}
void getline(ifstream& ifile, bool& var, char delim) {
	string tmp;
	getline(ifile, tmp, delim);
	if (tmp != "") var = stoi_c(tmp);
	else var = 0;
}
// getline overloads - end

// Read / Write credentials to files
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

// Read / Write marks to files
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

			getline(ifile, student[i].final[j], '	');

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

			ofile << student[i].final[j] << '	';

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

// Read / Write attendance to files
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

// Read / Write subjects to files
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

		getline(ifile, sub[i].current_total, '	');

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
		ofile << sub[i].current_total << '	';
		ofile << sub[i].grading_enabled << '	';
		ofile << sub[i].grading << '\n';
	}
}

// Read / Write settings to files
void ReadSettings(ifstream& ifile, Settings& saved) {
	string tmp_input;
	getline(ifile, tmp_input, '\n');
	saved.sections = stoi_c(tmp_input);

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

// Calculate total marks of the student and the grade according to fixed brackets
void Calc_grade_absolute(StuMarks student[], int size_arr, Subjects& sub_details, int curr_sub, int quiz_count, int assignment_count) {
	// Set grade enabled property to true	
	if (!sub_details.grading_enabled)
		sub_details.grading_enabled = true;

	// Grade every student of the given array
	for (int i = 0; i < size_arr; i++) {
		
		if (student[i].total_obtained[curr_sub] >= 0.90 * sub_details.current_total) student[i].grade[curr_sub] = "A+";
		else if (student[i].total_obtained[curr_sub] >= 0.86 * sub_details.current_total) student[i].grade[curr_sub] = "A";
		else if (student[i].total_obtained[curr_sub] >= 0.82 * sub_details.current_total) student[i].grade[curr_sub] = "A-";
		else if (student[i].total_obtained[curr_sub] >= 0.78 * sub_details.current_total) student[i].grade[curr_sub] = "B+";
		else if (student[i].total_obtained[curr_sub] >= 0.74 * sub_details.current_total) student[i].grade[curr_sub] = "B";
		else if (student[i].total_obtained[curr_sub] >= 0.70 * sub_details.current_total) student[i].grade[curr_sub] = "B-";
		else if (student[i].total_obtained[curr_sub] >= 0.66 * sub_details.current_total) student[i].grade[curr_sub] = "C+";
		else if (student[i].total_obtained[curr_sub] >= 0.62 * sub_details.current_total) student[i].grade[curr_sub] = "C";
		else if (student[i].total_obtained[curr_sub] >= 0.58 * sub_details.current_total) student[i].grade[curr_sub] = "C-";
		else if (student[i].total_obtained[curr_sub] >= 0.54 * sub_details.current_total) student[i].grade[curr_sub] = "D+";
		else if (student[i].total_obtained[curr_sub] >= 0.50 * sub_details.current_total) student[i].grade[curr_sub] = "D";
		else student[i].grade[curr_sub] = "F";

	}
}
// Calculate the grade according to class scores
void Calc_grade_relative(StuMarks student[], int size_class, Subjects& sub_details, int curr_sub) {
	// Set grade enabled property to true	
	if (!sub_details.grading_enabled)
		sub_details.grading_enabled = true;

	// Custom bracket limiter to adjust the brackets according to the class marks
	// Bracket limiter is the difference b/w the max and avg marks divided in x number of groups of size of std dev and that divided by the no.
	// of grades + 1
	float bracket_limiter = ((sub_details.class_max - sub_details.class_average) / sub_details.std_dev) / 6; // 6 is half the (no. of grades + 1)

	// Calculate the grade according to the brackets made utilizing the bracket limiter / whole class marks
	for (int i = 0; i < size_class; i++) {
		if (student[i].total_obtained[curr_sub] > (sub_details.class_average + 5 * bracket_limiter * sub_details.std_dev))
			student[i].grade[curr_sub] = "A+";
		else if (student[i].total_obtained[curr_sub] > (sub_details.class_average + 4.25 * bracket_limiter * sub_details.std_dev))
			student[i].grade[curr_sub] = "A";
		else if (student[i].total_obtained[curr_sub] > (sub_details.class_average + 3.25 * bracket_limiter * sub_details.std_dev))
			student[i].grade[curr_sub] = "A-";
		else if (student[i].total_obtained[curr_sub] > (sub_details.class_average + 2 * bracket_limiter * sub_details.std_dev))
			student[i].grade[curr_sub] = "B+";
		else if (student[i].total_obtained[curr_sub] > (sub_details.class_average + 0.5 * bracket_limiter * sub_details.std_dev))
			student[i].grade[curr_sub] = "B";
		else if (student[i].total_obtained[curr_sub] > (sub_details.class_average - 0.5 * bracket_limiter * sub_details.std_dev))
			student[i].grade[curr_sub] = "B-";
		else if (student[i].total_obtained[curr_sub] > (sub_details.class_average - 2 * bracket_limiter * sub_details.std_dev))
			student[i].grade[curr_sub] = "C+";
		else if (student[i].total_obtained[curr_sub] > (sub_details.class_average - 3.25 * bracket_limiter * sub_details.std_dev))
			student[i].grade[curr_sub] = "C";
		else if (student[i].total_obtained[curr_sub] > (sub_details.class_average - 4.25 * bracket_limiter * sub_details.std_dev))
			student[i].grade[curr_sub] = "C-";
		else if (student[i].total_obtained[curr_sub] > (sub_details.class_average - 5 * bracket_limiter * sub_details.std_dev))
			student[i].grade[curr_sub] = "D+";
		else if (student[i].total_obtained[curr_sub] > (sub_details.class_average - 5.5 * bracket_limiter * sub_details.std_dev))
			student[i].grade[curr_sub] = "D";
		else
			student[i].grade[curr_sub] = "F";
	}

}

void Calc_total(StuMarks student[], int size_class, Subjects& sub_details, int curr_sub, int quiz_count, int assignment_count) {
	float class_total = 0, sqr_total = 0;
	
	for (int i = 0; i < size_class; i++) {
		float sum = 0;

		// Weightage of each activity is Total_weightage / no of activities
		// Quiz = 10 ; Assignment = 10 ; Mid 1 = 30 ; Mid 2 = 30 ; Final = 50
		// Marks contribution towards total is given by
		// weightage * (obtained/total * 100)
		// i.e weightage * % marks
		for (int k = 0; k < quiz_count; k++)
			sum += (quiz_total_weightage / quiz_count) * ((student[i].quizzes[curr_sub][k] / quiz_max_marks) * 100);
		for (int k = 0; k < assignment_count; k++)
			sum += (assignment_total_weightage / assignment_count) * ((student[i].assignment[curr_sub][k] / assignment_max_marks) * 100);
		sum += mid_weightage * ((student[i].mid1[curr_sub] / mid_max_marks) * 100);
		sum += mid_weightage * ((student[i].mid2[curr_sub] / mid_max_marks) * 100);
		sum += final_weightage * ((student[i].final[curr_sub] / final_max_marks) * 100);

		student[i].total_obtained[curr_sub] = sum;

		// Add the student's total marks to the class_total
		class_total += student[i].total_obtained[curr_sub];

		// Get the class minimum and maximum marks
		if (i == 0) {
			sub_details.class_max = student[i].total_obtained[curr_sub];
			sub_details.class_min = student[i].total_obtained[curr_sub];
		}
		else if (student[i].total_obtained[curr_sub] > sub_details.class_max)
			sub_details.class_max = student[i].total_obtained[curr_sub];
		else if (student[i].total_obtained[curr_sub] < sub_details.class_min)
			sub_details.class_min = student[i].total_obtained[curr_sub];
	}

	// Store the class average
	sub_details.class_average = class_total / size_class;

	// Calculate the standard deviation
	for (int i = 0; i < size_class; i++)
		sqr_total = sqr_total + float(pow((student[0].total_obtained[curr_sub] - sub_details.class_average), 2.0));
	sub_details.std_dev = sqrt(sqr_total / size_class);


	// Configure the value of sub_details.current_total
	int quiz_to_be_counted = 0, assignment_to_be_counted = 0;
	float tmp_total = 0;
	// Check how many quizzes from amongst the ones set have been marked for atleast 1 student
	for (int i = 0; i < quiz_count; i++) {
		tmp_total = 0;
		for (int j = 0; j < size_class; j++)
			tmp_total += student[j].quizzes[curr_sub][i];
		if (tmp_total > 0)
			quiz_to_be_counted++;
	}
	// Check how many assignments from amongst the ones set have been marked for atleast 1 student
	for (int i = 0; i < assignment_count; i++) {
		tmp_total = 0;
		for (int j = 0; j < size_class; j++)
			tmp_total += student[j].assignment[curr_sub][i];
		if (tmp_total > 0)
			assignment_to_be_counted++;
	}
	// Add the marks weightage to the current total of the subject accordingly
	sub_details.current_total = (quiz_total_weightage / quiz_count) * quiz_to_be_counted * 100 + (assignment_total_weightage / assignment_count) * assignment_to_be_counted * 100;
	// If mid1 has been marked for atleast 1 student add its weightage to the subject total too
	tmp_total = 0;
	for (int j = 0; j < size_class; j++)
		tmp_total += student[j].mid1[curr_sub];
	if (tmp_total > 0)
		sub_details.current_total += mid_weightage * 100;
	// If mid2 has been marked for atleast 1 student add its weightage to the subject total too
	tmp_total = 0;
	for (int j = 0; j < size_class; j++)
		tmp_total += student[j].mid2[curr_sub];
	if (tmp_total > 0)
		sub_details.current_total += mid_weightage * 100;
	// If final has been marked for atleast 1 student add its weightage to the subject total too
	tmp_total = 0;
	for (int j = 0; j < size_class; j++)
		tmp_total += student[j].final[curr_sub];
	if (tmp_total > 0)
		sub_details.current_total += final_weightage * 100;
}

// Marshalling
// Convert managed data types to standard counterparts and vice versa
// System::String to std::string
string Stos(String^ temp) {
	return marshal_as<string>(temp);
}
// std::string to System::String
String^ stoS(string temp) {
	return marshal_as<String^>(temp);
}
// Convert a numerical quantitity to string while specifying the number of digits after decimal point
string to_string_with_precision(const double num, const int n = 2)
{
	std::ostringstream conversion;
	conversion.precision(n);
	conversion << std::fixed << num;
	return conversion.str();
}