#include "Login.h"
#include <Windows.h>
#include <string>
#include "variables.h"
#include "functions.h"

using namespace MSP;

using std::ifstream;
using System::Windows::Forms::Application;

void read_data_from_files(void);
void fix_exceptions(void);

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	read_data_from_files();
	fix_exceptions();

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Login());
	return 0;
}

void read_data_from_files(void) {
	ifstream settings(Settings_Folder + Settings_File);
	if (settings.is_open())
		ReadSettings(settings, saved);
	settings.close();

	ifstream stucred, stumarks;
	for (int i = 0; i < saved.sections; i++) {
		stucred.open(Student_Cred_Folder + "Sec_" + Sec_list[i] + ".txt");
		if (stucred.is_open())
			ReadCredentials(stucred, Stu_Cred[i], sizeof(Stu_Cred[i]) / sizeof(*Stu_Cred[i]));
		stucred.close();

		stumarks.open(Marks_Folder + "Sec_" + Sec_list[i] + ".txt");
		if (stumarks.is_open())
			ReadMarks(stumarks, Student_marks[i], sizeof(Student_marks[i]) / sizeof(*Student_marks[i]), Max_Subjects, Max_Quizzes, Max_Assignments);
		stumarks.close();
	}
	ifstream teach(Cred_Folder + Teacher_Cred_File);
	if (teach.is_open())
		ReadCredentials(teach, Teach_Cred, sizeof(Teach_Cred) / sizeof(*Teach_Cred));
	teach.close();
	ifstream admin(Cred_Folder + Admin_Cred_File);
	if (admin.is_open())
		ReadCredentials(admin, Admin_Cred, sizeof(Admin_Cred) / sizeof(*Admin_Cred));
	admin.close();

	ifstream sub_file;
	for (int i = 0; i < saved.sections; i++) {
		sub_file.open(Subject_Folder + "Sec_" + Sec_list[i] + ".txt");
		if (sub_file.is_open())
			ReadSubjects(sub_file, subjects_details[i], Max_Subjects);
		sub_file.close();
	}

	ifstream att_file;
	for (int i = 0; i < saved.sections; i++) {
		att_file.open(Attendance_Folder + "Sec_" + Sec_list[i] + ".txt");
		if (att_file.is_open())
			ReadAttendence(att_file, Student_att[i], Max_Students, Max_Subjects, Max_Weeks, Lec_per_Week);
		att_file.close();
	}
}

void fix_exceptions(void) {
	// Set default values for Settings struct if the current values are less than default ones.
	for (int i = 0; i < Max_Subjects; i++) {
		for (int j = 0; j < Max_Sections; j++) {
			if (saved.quizzes[i][j] < 1)
				saved.quizzes[i][j] = 1;
			if (saved.assignments[i][j] < 1)
				saved.assignments[i][j] = 1;
		}
	}
	// Default Values Settings struct - end

	// Default pass - Admin_cred
	No_Admin_Cred_available = true;
	for (int i = 0; i < sizeof(Admin_Cred) / sizeof(*Admin_Cred); i++) {
		if (Admin_Cred[i].username != "" && Admin_Cred[i].pass != "")
			No_Admin_Cred_available = false;
	}
	if (No_Admin_Cred_available) {
		Default_Admin_Cred.id = "NaN";
		Default_Admin_Cred.name = "NaN";
		Default_Admin_Cred.username = "admin";
		Default_Admin_Cred.pass = "admin";
	}
	// Default pass - Admin_cred - end
}