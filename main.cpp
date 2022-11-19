#include "Login.h"

using namespace MSP;
using std::ifstream;

void read_data_from_files(void);

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	read_data_from_files();
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Login());
	return 0;
}

void read_data_from_files(void) {
	ifstream settings(settings_file);
	ReadSettings(settings, saved);
	settings.close();

	for (int i = 0; i < saved.sections; i++) {
		ifstream stucred(Student_Cred_Folder + "Sec_" + Sec_list[i] + ".txt");
		ReadCredentials(stucred, Stu_Cred[i], sizeof(Stu_Cred[i]) / sizeof(*Stu_Cred[i]));
		stucred.close();

		ifstream stumarks(Marks_Folder + "Sec_" + Sec_list[i] + ".txt");
		ReadMarks(stumarks, Student_marks[i], sizeof(Student_marks[i]) / sizeof(*Student_marks[i]), Max_Subjects, Max_Quizzes, Max_Assignments);
		stumarks.close();
	}
	ifstream teach(Teacher_Cred_File);
	ReadCredentials(teach, Teach_Cred, sizeof(Teach_Cred) / sizeof(*Teach_Cred));
	teach.close();
	ifstream admin(Admin_Cred_File);
	ReadCredentials(admin, Admin_Cred, sizeof(Admin_Cred) / sizeof(*Admin_Cred));
	admin.close();

	ifstream sub_file;
	for (int i = 0; i < saved.sections; i++) {
		sub_file.open(Subject_Folder + "Sec_" + Sec_list[i] + ".txt");
		ReadSubjects(sub_file, subjects_details[i], Max_Subjects);
		sub_file.close();
	}

	ifstream att_file;
	for (int i = 0; i < saved.sections; i++) {
		att_file.open(Attendance_Folder + "Sec_" + Sec_list[i] + ".txt");
		ReadAttendence(att_file, Student_att[i], Max_Students, Max_Subjects, Max_Weeks);
		att_file.close();
	}
}