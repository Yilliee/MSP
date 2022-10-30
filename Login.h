#pragma once
#include "variables.h"
#include "functions.h"
#include "Admin.h"
#include "Teacher_homepage.h"

namespace MSP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Login
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		Login(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Login_Header;
	private: System::Windows::Forms::Label^ Username_label;
	private: System::Windows::Forms::Label^ Password_label;
	private: System::Windows::Forms::TextBox^ Username_textbox;

	private: System::Windows::Forms::TextBox^ Password_textbox;
	private: System::Windows::Forms::Button^ Login_button;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Login::typeid));
			this->Login_Header = (gcnew System::Windows::Forms::Label());
			this->Username_label = (gcnew System::Windows::Forms::Label());
			this->Password_label = (gcnew System::Windows::Forms::Label());
			this->Username_textbox = (gcnew System::Windows::Forms::TextBox());
			this->Password_textbox = (gcnew System::Windows::Forms::TextBox());
			this->Login_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Login_Header
			// 
			this->Login_Header->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Login_Header->AutoSize = true;
			this->Login_Header->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->Login_Header->CausesValidation = false;
			this->Login_Header->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Login_Header->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->Login_Header->Location = System::Drawing::Point(191, 47);
			this->Login_Header->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Login_Header->Name = L"Login_Header";
			this->Login_Header->Padding = System::Windows::Forms::Padding(27, 7, 27, 7);
			this->Login_Header->Size = System::Drawing::Size(367, 45);
			this->Login_Header->TabIndex = 0;
			this->Login_Header->Text = L"Minature Student Project";
			this->Login_Header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Username_label
			// 
			this->Username_label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Username_label->AutoSize = true;
			this->Username_label->CausesValidation = false;
			this->Username_label->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Username_label->Location = System::Drawing::Point(182, 187);
			this->Username_label->Name = L"Username_label";
			this->Username_label->Size = System::Drawing::Size(90, 19);
			this->Username_label->TabIndex = 1;
			this->Username_label->Text = L"Username : ";
			// 
			// Password_label
			// 
			this->Password_label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Password_label->AutoSize = true;
			this->Password_label->CausesValidation = false;
			this->Password_label->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Password_label->Location = System::Drawing::Point(187, 229);
			this->Password_label->Name = L"Password_label";
			this->Password_label->Size = System::Drawing::Size(85, 19);
			this->Password_label->TabIndex = 2;
			this->Password_label->Text = L"Password : ";
			// 
			// Username_textbox
			// 
			this->Username_textbox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Username_textbox->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Username_textbox->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->Username_textbox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Username_textbox->Location = System::Drawing::Point(278, 185);
			this->Username_textbox->MaxLength = 500;
			this->Username_textbox->Name = L"Username_textbox";
			this->Username_textbox->Size = System::Drawing::Size(230, 25);
			this->Username_textbox->TabIndex = 3;
			this->Username_textbox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// Password_textbox
			// 
			this->Password_textbox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Password_textbox->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Password_textbox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Password_textbox->Location = System::Drawing::Point(278, 227);
			this->Password_textbox->MaxLength = 500;
			this->Password_textbox->Name = L"Password_textbox";
			this->Password_textbox->Size = System::Drawing::Size(230, 25);
			this->Password_textbox->TabIndex = 4;
			this->Password_textbox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->Password_textbox->UseSystemPasswordChar = true;
			// 
			// Login_button
			// 
			this->Login_button->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Login_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Login_button->Location = System::Drawing::Point(278, 280);
			this->Login_button->Name = L"Login_button";
			this->Login_button->Size = System::Drawing::Size(230, 30);
			this->Login_button->TabIndex = 5;
			this->Login_button->Text = L"Login";
			this->Login_button->UseVisualStyleBackColor = true;
			this->Login_button->Click += gcnew System::EventHandler(this, &Login::Login_button_Click);
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(764, 445);
			this->Controls->Add(this->Login_button);
			this->Controls->Add(this->Password_textbox);
			this->Controls->Add(this->Username_textbox);
			this->Controls->Add(this->Password_label);
			this->Controls->Add(this->Username_label);
			this->Controls->Add(this->Login_Header);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::SystemColors::Desktop;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Login";
			this->Text = L"Signin";
			this->Load += gcnew System::EventHandler(this, &Login::Login_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Login_Load(System::Object^ sender, System::EventArgs^ e) {
			std::ifstream settings(settings_file);
			ReadSettings(settings, saved);
			settings.close();

			for ( int i = 0; i < saved.sections; i++){
				std::ifstream stucred(Student_Cred_Folder + "Sec_" + Sec_list[i] + ".txt");
				ReadCredentials(stucred, Stu_Cred[i], sizeof(Stu_Cred[i]) / sizeof(*Stu_Cred[i]));
				stucred.close();
				
				std::ifstream stumarks(Marks_Folder + "Sec_" + Sec_list[i] + ".txt");
				ReadMarks(stumarks, Student_marks[i], sizeof(Student_marks[i]) / sizeof(*Student_marks[i]), Max_Subjects, Max_Quizzes);
				stumarks.close();
			}
			std::ifstream teach(Teacher_Cred_File);
			ReadCredentials(teach, Teach_Cred, sizeof(Teach_Cred) / sizeof(*Teach_Cred));
			teach.close();
			std::ifstream admin(Admin_Cred_File);
			ReadCredentials(admin, Admin_Cred, sizeof(Admin_Cred) / sizeof(*Admin_Cred));
			admin.close();

		}
	private: System::Void Login_button_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string username = System_to_std_string(Username_textbox->Text);
		std::string pass = System_to_std_string(Password_textbox->Text);

		for (int i = 0; i < saved.sections; i++) {
			if (username != "" && pass != "") student_no = authenticate(username, pass, Stu_Cred[i], sizeof(Stu_Cred[i]) / sizeof(*Stu_Cred[i]));
			
			if (student_no != -1) {
				curr_sec = i;
				break;
			}
		}
		teach_no = authenticate(username, pass, Teach_Cred, sizeof(Teach_Cred) / sizeof(*Teach_Cred));
		admin_no = authenticate(username, pass, Admin_Cred, sizeof(Admin_Cred) / sizeof(*Admin_Cred));
		if (student_no != -1) {
			MessageBox::Show(std_to_System_string(Stu_Cred[curr_sec][student_no].name) + " (no. " + student_no + ") successfully logged on.");
			// Open stu home page
		}
		else if (teach_no != -1) {
			MessageBox::Show(std_to_System_string(Teach_Cred[teach_no].name) + " (no. " + teach_no + ") successfully logged on.");
			// Open teach home page
			Teacher_homepage thp;
			// Hide the currrent winform, open the new one and then close the old one.
			this->Hide();
			thp.ShowDialog();
			this->Close();

		}
		else if (admin_no != -1) {
			MessageBox::Show(std_to_System_string(Admin_Cred[admin_no].name) + " (no. " + admin_no + ") successfully logged on.");
			// Open admin home page
			Admin ahp;
			// Hide the currrent winform, open the new one and then close the old one.
			this->Hide();
			ahp.ShowDialog();
			this->Close();
		}
		else MessageBox::Show("Incorrect Email or Password.");
	}
};
}
