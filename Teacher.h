#pragma once
#include "functions.h"
#include "variables.h"

namespace MSP {

	using namespace System::Windows::Forms;
	using System::Void;
	using System::String;
	using System::Drawing::Point;

	/// <summary>
	/// Summary for Teacher
	/// </summary>
	public ref class Teacher : public Form
	{
	public:
		Teacher(void)
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
		~Teacher()
		{
			if (components)
			{
				delete components;
			}
		}

	// Teacher - items - start
	private: Label^ Teacher_hp_header;
	private: Label^ Teacher_hp_subheader;
	private: array<Button^>^ Classes = gcnew array<Button^>(Max_subject_per_teacher);
	private: Button^ Reset_pass_button;
	private: Button^ Logout_button;
	private: List<int>^ section = gcnew List<int>();
	private: List<int>^ subject = gcnew List<int>();

	private: Form^ New_Pass_prompt = gcnew Form();
	private: Label^ New_pass_message_label = gcnew Label();
	private: TextBox^ New_Pass_tb = gcnew TextBox();
	private: TextBox^ New_Pass_Confirmation_tb = gcnew TextBox();
	private: Button^ New_pass_update_button = gcnew Button();
	// Teacher - items - end

	// Operation_selector - items - start
	private: Label^ Operation_sel_header;
	private: Label^ Operation_sel_subheader;
	private: Button^ Manage_marks_button;
	private: Button^ Manage_attendance_button;
	private: Button^ Calculate_Grades_button;
	private: Button^ Back_from_opsel_button;
	// Operation_selector - items - end

	// Exam_type - items - start
	private: Label^ Exam_type_header;
	private: Button^ Quiz_button;
	private: Button^ Assignment_button;
	private: Button^ Mid_1_button;
	private: Button^ Mid_2_button;
	private: Button^ Finals_button;
	private: Button^ Back_from_Examtype_button;
	// Exam_type - items - end

	// Activity_number_selector - items - start
	private: Label^ Activity_number_selector_header;
	private: Button^ Activity_del_button;
	private: Button^ New_Activity_button;
	private: Button^ Back_from_Activity_sel_button;
	private: array<Button^>^ Activities;
	private: int Max_activity, activity = -1, quiz = 1, assignment = 2;
	// Activity_number_selector - items - end

	// Marksheet - items - start
	private: array<Label^>^ Sr_marksheet_l = gcnew array<Label^>(Max_Students);
	private: array<Label^>^ Name_marksheet_l = gcnew array<Label^>(Max_Students);
	private: array<Label^>^ ID_marksheet_l = gcnew array<Label^>(Max_Students);
	private: array<TextBox^>^ Marks_marksheet_tb = gcnew array<TextBox^>(Max_Students);
	private: Label^ Marksheet_header;
	private: Button^ Save_marksheet_button;
	private: Button^ Back_from_marksheet_button;
	private: Label^ Marks_header;
	// Marksheet - items - end

	// Marksheet + Attendance - items - start
	private: Label^ Sr_header;
	private: Label^ ID_header;
	private: Label^ Name_header;
	// Marksheet + Attendance - items - end

	// Attendance - items - start
	private: Label^ Attendance_header;
	private: Button^ Save_att_button;
	private: Button^ Back_from_att_button;
	private: array<Button^>^ Page_sel_att_button;

	private: array<Label^>^ Att_lec_header;

	private: array<Label^>^ Sr_att_l = gcnew array<Label^>(Max_Students);
	private: array<Label^>^ Name_att_l = gcnew array<Label^>(Max_Students);
	private: array<Label^>^ ID_att_l = gcnew array<Label^>(Max_Students);
	
	private: array<array<ComboBox^>^>^ Att_cb;
	// Attendance - items - end

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		// Teacher homepage - start
		void InitializeComponent(void)
		{
			int tab_index = 0;

			this->Teacher_hp_header = (gcnew Label());
			this->Teacher_hp_subheader = (gcnew Label());
			for (int i = 0; i < Max_subject_per_teacher; i++) {
				this->Classes[i] = (gcnew Button());
			}
			this->Reset_pass_button = (gcnew Button());
			this->Logout_button = (gcnew Button());

			this->SuspendLayout();

			// 
			// Teacher_hp_header
			// 
			this->Teacher_hp_header->Anchor = AnchorStyles::Top;
			this->Teacher_hp_header->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Teacher_hp_header->Location = System::Drawing::Point(12, 9);
			this->Teacher_hp_header->Name = L"Teacher_hp_header";
			this->Teacher_hp_header->Size = System::Drawing::Size(698, 40);
			this->Teacher_hp_header->Text = L"Welcome,  ";
			this->Teacher_hp_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Teacher_hp_subheader
			// 
			this->Teacher_hp_subheader->Anchor = AnchorStyles::Top;
			this->Teacher_hp_subheader->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Teacher_hp_subheader->Location = System::Drawing::Point(12, 55);
			this->Teacher_hp_subheader->Name = L"Teacher_hp_subheader";
			this->Teacher_hp_subheader->Size = System::Drawing::Size(698, 45);
			this->Teacher_hp_subheader->Text = L"Select a class / operation : ";
			this->Teacher_hp_subheader->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			// 
			// Classes_button
			// 
			for (int i = 0; i < Max_subject_per_teacher; i++) {
				this->Classes[i]->Anchor = AnchorStyles::Top;
				this->Classes[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI SemiBold", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Classes[i]->Left = 150;
				this->Classes[i]->Name = "Classes_button_" + stoS(std::to_string(i + 1));
				this->Classes[i]->Size = System::Drawing::Size(400, 30);
				this->Classes[i]->TabIndex = tab_index++;
				this->Classes[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				this->Classes[i]->Visible = false;
				this->Classes[i]->Tag = i;
				this->Classes[i]->Click += gcnew System::EventHandler(this, &MSP::Teacher::Select_class);
			}
			// 
			// Reset_pass_button
			// 
			this->Reset_pass_button->Anchor = AnchorStyles::Top;
			this->Reset_pass_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Reset_pass_button->FlatStyle = FlatStyle::Popup;
			this->Reset_pass_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Reset_pass_button->Location = System::Drawing::Point(150, 124);
			this->Reset_pass_button->Name = L"Reset_Pass_button";
			this->Reset_pass_button->Size = System::Drawing::Size(400, 30);
			this->Reset_pass_button->TabIndex = tab_index++;
			this->Reset_pass_button->Text = L"Reset Password";
			this->Reset_pass_button->UseVisualStyleBackColor = false;
			this->Reset_pass_button->Click += gcnew System::EventHandler(this, &Teacher::Reset_pass_button_click);
			// 
			// Logout_button
			// 
			this->Logout_button->Anchor = AnchorStyles::Top;
			this->Logout_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Logout_button->FlatStyle = FlatStyle::Popup;
			this->Logout_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Logout_button->Location = System::Drawing::Point(150, 164);
			this->Logout_button->Name = L"Logout_button";
			this->Logout_button->Size = System::Drawing::Size(400, 30);
			this->Logout_button->TabIndex = tab_index++;
			this->Logout_button->Text = L"Logout";
			this->Logout_button->UseVisualStyleBackColor = false;
			this->Logout_button->Click += gcnew System::EventHandler(this, &Teacher::Logout_button_Click);
			// 
			// Teacher
			// 
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(720, 450);
			this->Controls->Add(this->Teacher_hp_header);
			this->Controls->Add(this->Teacher_hp_subheader);
			this->Controls->AddRange(this->Classes);
			this->Controls->Add(this->Reset_pass_button);
			this->Controls->Add(this->Logout_button);
			this->Name = L"Teacher";
			this->Text = L"Teacher homepage";
			Teacher_Load();
			this->ResumeLayout(false);

		}
		// Teacher homepage - end

		// Operation Selector - start
		void InitializeComponent_OperationSelector(void)
		{
			this->Operation_sel_header = (gcnew Label());
			this->Operation_sel_subheader = (gcnew Label());
			this->Manage_marks_button = (gcnew Button());
			this->Manage_attendance_button = (gcnew Button());
			this->Calculate_Grades_button = (gcnew Button());
			this->Back_from_opsel_button = (gcnew Button());

			this->SuspendLayout();

			// 
			// Operation_sel_header
			// 
			this->Operation_sel_header->Anchor = AnchorStyles::Top;
			this->Operation_sel_header->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Operation_sel_header->Location = System::Drawing::Point(10, 20);
			this->Operation_sel_header->Name = L"Operation_sel_header";
			this->Operation_sel_header->Size = System::Drawing::Size(700, 40);
			this->Operation_sel_header->TabIndex = 0;
			this->Operation_sel_header->Text = stoS(subjects_details[curr_sec][curr_subject].course_code + " - "
				+ subjects_details[curr_sec][curr_subject].name + " - " + "Section " + Sec_list[curr_sec]);
			this->Operation_sel_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Operation_sel_subheader
			// 
			this->Operation_sel_subheader->Anchor = AnchorStyles::Top;
			this->Operation_sel_subheader->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Operation_sel_subheader->Location = System::Drawing::Point(10, 85);
			this->Operation_sel_subheader->Name = L"Operation_sel_subheader";
			this->Operation_sel_subheader->Size = System::Drawing::Size(700, 40);
			this->Operation_sel_subheader->TabIndex = 1;
			this->Operation_sel_subheader->Text = L"Select an Operation : ";
			this->Operation_sel_subheader->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			// 
			// Manage_marks_button
			// 
			this->Manage_marks_button->Anchor = AnchorStyles::Top;
			this->Manage_marks_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Manage_marks_button->FlatStyle = FlatStyle::Popup;
			this->Manage_marks_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Manage_marks_button->Location = System::Drawing::Point(250, 150);
			this->Manage_marks_button->Name = L"Manage_marks_button";
			this->Manage_marks_button->Size = System::Drawing::Size(200, 30);
			this->Manage_marks_button->TabIndex = 2;
			this->Manage_marks_button->Text = L"Manage Marks";
			this->Manage_marks_button->UseVisualStyleBackColor = false;
			this->Manage_marks_button->Click += gcnew System::EventHandler(this, &Teacher::Manage_marks_button_Click);
			// 
			// Manage_attendance_button
			// 
			this->Manage_attendance_button->Anchor = AnchorStyles::Top;
			this->Manage_attendance_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Manage_attendance_button->FlatStyle = FlatStyle::Popup;
			this->Manage_attendance_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Manage_attendance_button->Location = System::Drawing::Point(250, 220);
			this->Manage_attendance_button->Name = L"Manage_attendance_button";
			this->Manage_attendance_button->Size = System::Drawing::Size(200, 30);
			this->Manage_attendance_button->TabIndex = 3;
			this->Manage_attendance_button->Text = L"Manage Attendance";
			this->Manage_attendance_button->UseVisualStyleBackColor = false;
			this->Manage_attendance_button->Click += gcnew System::EventHandler(this, &Teacher::Manage_attendance_button_Click);
			// 
			// Calculate_Grades_button
			// 
			this->Calculate_Grades_button->Anchor = AnchorStyles::Top;
			this->Calculate_Grades_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Calculate_Grades_button->FlatStyle = FlatStyle::Popup;
			this->Calculate_Grades_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Calculate_Grades_button->Location = System::Drawing::Point(250, 290);
			this->Calculate_Grades_button->Name = L"Calculate_Grades_button";
			this->Calculate_Grades_button->Size = System::Drawing::Size(200, 30);
			this->Calculate_Grades_button->TabIndex = 4;
			this->Calculate_Grades_button->Text = L"Calculate Grades";
			this->Calculate_Grades_button->UseVisualStyleBackColor = false;
			this->Calculate_Grades_button->Click += gcnew System::EventHandler(this, &Teacher::Calculate_Grades_button_Click);
			// 
			// Back_button
			// 
			this->Back_from_opsel_button->Anchor = AnchorStyles::Top;
			this->Back_from_opsel_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Back_from_opsel_button->FlatStyle = FlatStyle::Popup;
			this->Back_from_opsel_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Back_from_opsel_button->Location = System::Drawing::Point(250, 350);
			this->Back_from_opsel_button->Name = L"Back_button";
			this->Back_from_opsel_button->Size = System::Drawing::Size(200, 31);
			this->Back_from_opsel_button->TabIndex = 5;
			this->Back_from_opsel_button->Text = L"Back";
			this->Back_from_opsel_button->UseVisualStyleBackColor = false;
			this->Back_from_opsel_button->Click += gcnew System::EventHandler(this, &Teacher::Back_from_opsel_button_Click);

			// 
			// Operation_selector
			// 
			//this->AutoScaleDimensions = System::Drawing::SizeF(8, 17);
			//this->AutoScaleMode = AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(720, 450);
			this->Controls->Add(this->Operation_sel_header);
			this->Controls->Add(this->Operation_sel_subheader);
			this->Controls->Add(this->Manage_marks_button);
			this->Controls->Add(this->Manage_attendance_button);
			this->Controls->Add(this->Calculate_Grades_button);
			this->Controls->Add(this->Back_from_opsel_button);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::SystemColors::Desktop;
			this->Name = L"Operation_selector";
			this->Text = L"Operation selector";
			this->ResumeLayout(false);

		}
		// Operation Selector - end

		// Exam Type - start
		void InitializeComponent_ExamType(void)
		{
			this->Exam_type_header = (gcnew Label());
			this->Quiz_button = (gcnew Button());
			this->Assignment_button = (gcnew Button());
			this->Mid_1_button = (gcnew Button());
			this->Mid_2_button = (gcnew Button());
			this->Finals_button = (gcnew Button());
			this->Back_from_Examtype_button = (gcnew Button());

			this->SuspendLayout();
			// 
			// Exam_type_header
			// 
			this->Exam_type_header->Anchor = AnchorStyles::Top;
			this->Exam_type_header->Font = (gcnew System::Drawing::Font(L"Times New Roman", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Exam_type_header->ForeColor = System::Drawing::SystemColors::Desktop;
			this->Exam_type_header->Location = System::Drawing::Point(12, 9);
			this->Exam_type_header->Name = L"Exam_type_header";
			this->Exam_type_header->Size = System::Drawing::Size(676, 82);
			this->Exam_type_header->TabIndex = 0;
			this->Exam_type_header->Text = L"Select Exam type:";
			this->Exam_type_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Quiz_button
			// 
			this->Quiz_button->Anchor = AnchorStyles::Top;
			this->Quiz_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Quiz_button->FlatStyle = FlatStyle::Popup;
			this->Quiz_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold));
			this->Quiz_button->ForeColor = System::Drawing::SystemColors::Desktop;
			this->Quiz_button->Location = System::Drawing::Point(250, 142);
			this->Quiz_button->Name = L"Quiz_button";
			this->Quiz_button->Size = System::Drawing::Size(200, 25);
			this->Quiz_button->TabIndex = 1;
			this->Quiz_button->Text = L"Quiz";
			this->Quiz_button->UseVisualStyleBackColor = false;
			this->Quiz_button->Click += gcnew System::EventHandler(this, &Teacher::Quiz_button_Click);
			// 
			// Assignment_button
			// 
			this->Assignment_button->Anchor = AnchorStyles::Top;
			this->Assignment_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Assignment_button->FlatStyle = FlatStyle::Popup;
			this->Assignment_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold));
			this->Assignment_button->ForeColor = System::Drawing::SystemColors::Desktop;
			this->Assignment_button->Location = System::Drawing::Point(250, 197);
			this->Assignment_button->Name = L"Assigment_button";
			this->Assignment_button->Size = System::Drawing::Size(200, 25);
			this->Assignment_button->TabIndex = 1;
			this->Assignment_button->Text = L"Assignment";
			this->Assignment_button->UseVisualStyleBackColor = false;
			this->Assignment_button->Click += gcnew System::EventHandler(this, &Teacher::Assignment_button_Click);
			// 
			// Mid_1_button
			// 
			this->Mid_1_button->Anchor = AnchorStyles::Top;
			this->Mid_1_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Mid_1_button->FlatStyle = FlatStyle::Popup;
			this->Mid_1_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold));
			this->Mid_1_button->ForeColor = System::Drawing::SystemColors::Desktop;
			this->Mid_1_button->Location = System::Drawing::Point(250, 252);
			this->Mid_1_button->Name = L"Mid_1_button";
			this->Mid_1_button->Size = System::Drawing::Size(200, 25);
			this->Mid_1_button->TabIndex = 2;
			this->Mid_1_button->Text = L"Midterm # 1";
			this->Mid_1_button->UseVisualStyleBackColor = false;
			this->Mid_1_button->Click += gcnew System::EventHandler(this, &Teacher::Mid1_button_Click);
			// 
			// Mid_2_button
			// 
			this->Mid_2_button->Anchor = AnchorStyles::Top;
			this->Mid_2_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Mid_2_button->FlatStyle = FlatStyle::Popup;
			this->Mid_2_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Mid_2_button->ForeColor = System::Drawing::SystemColors::Desktop;
			this->Mid_2_button->Location = System::Drawing::Point(250, 307);
			this->Mid_2_button->Name = L"Mid_2_button";
			this->Mid_2_button->Size = System::Drawing::Size(200, 25);
			this->Mid_2_button->TabIndex = 3;
			this->Mid_2_button->Text = L"Midterm # 2";
			this->Mid_2_button->UseVisualStyleBackColor = false;
			this->Mid_2_button->Click += gcnew System::EventHandler(this, &Teacher::Mid2_button_Click);
			// 
			// Finals_button
			// 
			this->Finals_button->Anchor = AnchorStyles::Top;
			this->Finals_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Finals_button->FlatStyle = FlatStyle::Popup;
			this->Finals_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Finals_button->ForeColor = System::Drawing::SystemColors::Desktop;
			this->Finals_button->Location = System::Drawing::Point(250, 362);
			this->Finals_button->Name = L"Finals_button";
			this->Finals_button->Size = System::Drawing::Size(200, 25);
			this->Finals_button->TabIndex = 4;
			this->Finals_button->Text = L"Finals";
			this->Finals_button->UseVisualStyleBackColor = false;
			this->Finals_button->Click += gcnew System::EventHandler(this, &Teacher::Finals_button_Click);
			// 
			// Back_from_ExamType_button
			// 
			this->Back_from_Examtype_button->Anchor = AnchorStyles::Top;
			this->Back_from_Examtype_button->BackColor = System::Drawing::Color::Lavender;
			this->Back_from_Examtype_button->FlatStyle = FlatStyle::Popup;
			this->Back_from_Examtype_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Back_from_Examtype_button->Location = System::Drawing::Point(250, 417);
			this->Back_from_Examtype_button->Name = L"Back_to_home_del";
			this->Back_from_Examtype_button->Size = System::Drawing::Size(200, 25);
			this->Back_from_Examtype_button->Text = L"Go Back to home";
			this->Back_from_Examtype_button->UseVisualStyleBackColor = false;
			this->Back_from_Examtype_button->Visible = true;
			this->Back_from_Examtype_button->Click += gcnew System::EventHandler(this, &Teacher::back_to_opsel);

			// 
			// Exam_type
			// 
			this->AutoScroll = true;

			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(720, 450);
			this->Controls->Add(this->Exam_type_header);
			this->Controls->Add(this->Quiz_button);
			this->Controls->Add(this->Assignment_button);
			this->Controls->Add(this->Mid_1_button);
			this->Controls->Add(this->Mid_2_button);
			this->Controls->Add(this->Finals_button);
			this->Controls->Add(this->Back_from_Examtype_button);
			this->Name = L"Exam_type";
			this->Text = L"Exam Type Selector";
			this->ResumeLayout(false);

		}
		// Exam Type - end

		// Assignment selector - start
		void InitializeComponent_ActivitySelector(void)
		{
			int New_Activity_button_y;
			if (exam_type == Exam_quiz) {
				Max_activity = Max_Quizzes;
				New_Activity_button_y = 121 + 31 * (saved.quizzes[curr_subject][curr_sec] - 1);
			}
			else if (exam_type == Exam_assignment) {
				Max_activity = Max_Assignments;
				New_Activity_button_y = 121 + 31 * (saved.assignments[curr_subject][curr_sec] - 1);
			}

			Activities = gcnew array<Button^>(Max_activity);

			this->Activity_number_selector_header = (gcnew Label());
			this->Activity_del_button = (gcnew Button());
			this->New_Activity_button = (gcnew Button());
			this->Back_from_Activity_sel_button = (gcnew Button());

			for (int i = 0; i < Max_activity; i++) {
				this->Activities[i] = (gcnew Button());
			}

			this->SuspendLayout();

			// 
			// Assignment_selector_header
			// 
			this->Activity_number_selector_header->Anchor = AnchorStyles::Top;
			this->Activity_number_selector_header->AutoSize = true;
			this->Activity_number_selector_header->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Activity_number_selector_header->Location = System::Drawing::Point(223, 43);
			if (exam_type == Exam_quiz) {
				this->Activity_number_selector_header->Name = L"Quiz_selector_header";
				this->Activity_number_selector_header->Text = "Select a Quiz : ";
			}
			else if (exam_type == Exam_assignment) {
				this->Activity_number_selector_header->Name = L"Assignment_selector_header";
				this->Activity_number_selector_header->Text = "Select a Assignment : ";
			}
			this->Activity_number_selector_header->Size = System::Drawing::Size(200, 31);
			this->Activity_number_selector_header->TabIndex = 0;

			// 
			// Assignments_Array
			// 
			int y_pos = 90;
			for (int i = 0; i < Max_Assignments; i++) {
				this->Activities[i]->Anchor = AnchorStyles::Top;
				this->Activities[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				this->Activities[i]->FlatStyle = FlatStyle::Popup;
				this->Activities[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Activities[i]->Location = System::Drawing::Point(225, y_pos);
				if (exam_type == Exam_quiz) {
					this->Activities[i]->Name = "Quiz_";
					this->Activities[i]->Text = "Quiz ";
				}
				else if (exam_type == Exam_assignment) {
					this->Activities[i]->Name = "Assignment_";
					this->Activities[i]->Text = "Assignment ";
				}
				this->Activities[i]->Name += stoS(std::to_string(i + 1) + "_button");
				this->Activities[i]->Size = System::Drawing::Size(200, 25);
				this->Activities[i]->TabIndex = 1;
				this->Activities[i]->Text += stoS("no. " + std::to_string(i + 1));
				this->Activities[i]->UseVisualStyleBackColor = false;
				this->Activities[i]->Tag = i;
				this->Activities[i]->Click += gcnew System::EventHandler(this, &Teacher::Select_activity);
				y_pos += 31;
			}

			// 
			// Assignment_del_button
			// 
			this->Activity_del_button->Anchor = AnchorStyles::Top;
			this->Activity_del_button->BackColor = System::Drawing::Color::Red;
			this->Activity_del_button->FlatStyle = FlatStyle::Popup;
			this->Activity_del_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Activity_del_button->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->Activity_del_button->Location = System::Drawing::Point(400, New_Activity_button_y - 31);
			if (exam_type == Exam_quiz) this->Activity_del_button->Name = L"Quiz_del_button";
			else if (exam_type == Exam_assignment) this->Activity_del_button->Name = L"Assignment_del_button";
			this->Activity_del_button->Size = System::Drawing::Size(25, 25);
			this->Activity_del_button->TabIndex = 11;
			this->Activity_del_button->Text = L"X";
			this->Activity_del_button->UseVisualStyleBackColor = false;
			this->Activity_del_button->Visible = false;
			this->Activity_del_button->Click += gcnew System::EventHandler(this, &Teacher::Delete_a_Activity);
			// 
			// New_Assignment_button
			//
			this->New_Activity_button->Anchor = AnchorStyles::Top;
			this->New_Activity_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->New_Activity_button->FlatStyle = FlatStyle::Popup;
			this->New_Activity_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->New_Activity_button->Location = System::Drawing::Point(225, New_Activity_button_y);
			this->New_Activity_button->Text = L"Create a New ";
			if (exam_type == Exam_quiz) {
				this->New_Activity_button->Name = L"New_Quiz_button";
				this->New_Activity_button->Text += L"Quiz";
			}
			else if (exam_type == Exam_assignment) {
				this->New_Activity_button->Name = L"New_Assignment_button";
				this->New_Activity_button->Text += L"Assignment";
			}
			this->New_Activity_button->Size = System::Drawing::Size(200, 25);
			this->New_Activity_button->TabIndex = 12;
			this->New_Activity_button->UseVisualStyleBackColor = false;
			this->New_Activity_button->Visible = true;
			this->New_Activity_button->Click += gcnew System::EventHandler(this, &Teacher::Create_New_Activity);

			// 
			// Back_to_home_button
			// 
			this->Back_from_Activity_sel_button->Anchor = AnchorStyles::Top;
			this->Back_from_Activity_sel_button->BackColor = System::Drawing::Color::Lavender;
			this->Back_from_Activity_sel_button->FlatStyle = FlatStyle::Popup;
			this->Back_from_Activity_sel_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Back_from_Activity_sel_button->Location = System::Drawing::Point(New_Activity_button->Left, New_Activity_button->Top + 31);
			if ((exam_type == Exam_assignment && saved.assignments[curr_subject][curr_sec] == Max_Assignments) ||
				(exam_type == Exam_quiz && saved.quizzes[curr_subject][curr_sec] == Max_Quizzes))
				this->Back_from_Activity_sel_button->Top -= 35;
			this->Back_from_Activity_sel_button->Name = L"Back_from_ActivitySel_button";
			this->Back_from_Activity_sel_button->Size = System::Drawing::Size(200, 25);
			this->Back_from_Activity_sel_button->Text = L"Go Back to Exam Type Selector";
			this->Back_from_Activity_sel_button->UseVisualStyleBackColor = false;
			this->Back_from_Activity_sel_button->Visible = true;
			this->Back_from_Activity_sel_button->Click += gcnew System::EventHandler(this, &Teacher::back_to_exam_type);

			// 
			// Assignment_selector
			//
			this->AutoScroll = true;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(720, 450);
			this->Controls->Add(this->Activity_number_selector_header);
			this->Controls->Add(this->New_Activity_button);
			this->Controls->Add(this->Activity_del_button);
			this->Controls->Add(this->Back_from_Activity_sel_button);
			this->Controls->AddRange(this->Activities);
			this->Name = L"Activity_selector";
			this->Text = L"Activity Management";
			if (exam_type == Exam_quiz)
				load_activity_buttons(saved.quizzes[curr_subject][curr_sec], Max_activity);
			else
				load_activity_buttons(saved.assignments[curr_subject][curr_sec], Max_activity);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		// Assignment selector - end

		// Marksheet  - start
		void InitializeComponent_Marksheet(void)
		{
			this->Marksheet_header = (gcnew Label());
			this->Save_marksheet_button = (gcnew Button());
			this->Back_from_marksheet_button = (gcnew Button());

			this->Sr_header = (gcnew Label());
			this->Name_header = (gcnew Label());
			this->ID_header = (gcnew Label());
			this->Marks_header = (gcnew Label());

			for (int i = 0; i < Max_Students; i++) {
				Sr_marksheet_l[i] = gcnew Label();
				Name_marksheet_l[i] = gcnew Label();
				ID_marksheet_l[i] = gcnew Label();
				Marks_marksheet_tb[i] = gcnew TextBox();
			}

			this->SuspendLayout();
			// 
			// Marksheet_header
			// 
			this->Marksheet_header->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left);
			this->Marksheet_header->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->Marksheet_header->Font = (gcnew System::Drawing::Font(L"Times new Roman", 20.25f, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Marksheet_header->Location = System::Drawing::Point(10, 20);
			this->Marksheet_header->Name = L"Marksheet_header";
			this->Marksheet_header->Size = System::Drawing::Size(750, 31);
			this->Marksheet_header->TabIndex = 0;
			this->Marksheet_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			// 
			// Save_marksheet_button
			//
			this->Save_marksheet_button->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left);
			this->Save_marksheet_button->BackColor = System::Drawing::Color::Lavender;
			this->Save_marksheet_button->FlatStyle = FlatStyle::Popup;
			this->Save_marksheet_button->Font = (gcnew System::Drawing::Font(L"Segoe UI semiBold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Save_marksheet_button->Location = System::Drawing::Point(655, 61);
			this->Save_marksheet_button->Name = L"Save_marksheet_button";
			this->Save_marksheet_button->Size = System::Drawing::Size(100, 23);
			this->Save_marksheet_button->TabIndex = 1;
			this->Save_marksheet_button->Text = L"Save";
			this->Save_marksheet_button->UseVisualStyleBackColor = false;
			this->Save_marksheet_button->Click += gcnew System::EventHandler(this, &Teacher::Save_marksheet_button_click);
			// 
			// Back_button
			//
			this->Back_from_marksheet_button->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
			this->Back_from_marksheet_button->BackColor = System::Drawing::Color::Lavender;
			this->Back_from_marksheet_button->FlatStyle = FlatStyle::Popup;
			this->Back_from_marksheet_button->Font = (gcnew System::Drawing::Font(L"Segoe UI semiBold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Back_from_marksheet_button->Location = System::Drawing::Point(5, 61);
			this->Back_from_marksheet_button->Name = L"Back_button";
			this->Back_from_marksheet_button->Size = System::Drawing::Size(101, 23);
			this->Back_from_marksheet_button->TabIndex = 0;
			this->Back_from_marksheet_button->Text = L"Back";
			this->Back_from_marksheet_button->UseVisualStyleBackColor = false;
			this->Back_from_marksheet_button->Click += gcnew System::EventHandler(this, &Teacher::back_from_marksheet_button_click);

			// 
			// Sr_header
			// 
			this->Sr_header->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
			this->Sr_header->BorderStyle = BorderStyle::FixedSingle;
			this->Sr_header->FlatStyle = FlatStyle::Popup;
			this->Sr_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Sr_header->Location = System::Drawing::Point(5, 93);
			this->Sr_header->Name = L"Serialno_header";
			this->Sr_header->Size = System::Drawing::Size(35, 25);
			this->Sr_header->TabIndex = 2;
			this->Sr_header->Text = L"Sr.";
			this->Sr_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ID_header
			// 
			this->ID_header->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
			this->ID_header->BorderStyle = BorderStyle::FixedSingle;
			this->ID_header->FlatStyle = FlatStyle::Popup;
			this->ID_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ID_header->Location = System::Drawing::Point(45, 93);
			this->ID_header->Name = L"ID_header";
			this->ID_header->Size = System::Drawing::Size(200, 25);
			this->ID_header->TabIndex = 3;
			this->ID_header->Text = L"ID";
			this->ID_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Name_header
			// 
			this->Name_header->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
			this->Name_header->BorderStyle = BorderStyle::FixedSingle;
			this->Name_header->FlatStyle = FlatStyle::Popup;
			this->Name_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name_header->Location = System::Drawing::Point(250, 93);
			this->Name_header->Name = L"Name_header";
			this->Name_header->Size = System::Drawing::Size(300, 25);
			this->Name_header->TabIndex = 4;
			this->Name_header->Text = L"Student Name";
			this->Name_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Marks_headers
			// 
			this->Marks_header->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left);
			this->Marks_header->BorderStyle = BorderStyle::FixedSingle;
			this->Marks_header->FlatStyle = FlatStyle::Popup;
			this->Marks_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Marks_header->Location = System::Drawing::Point(555, 93);
			this->Marks_header->Name = L"Marks_header";
			this->Marks_header->Size = System::Drawing::Size(200, 25);
			this->Marks_header->TabIndex = 5;
			this->Marks_header->Text = L"Marks";
			this->Marks_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			// 
			// Serial Labels
			// 
			int y_pos = 124, tab_index = 6;
			for (int i = 0; i < Max_Students; i++) {
				Sr_marksheet_l[i]->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
				Sr_marksheet_l[i]->BorderStyle = BorderStyle::FixedSingle;
				Sr_marksheet_l[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				Sr_marksheet_l[i]->Location = System::Drawing::Point(5, y_pos);
				Sr_marksheet_l[i]->Name = stoS("Sr_" + std::to_string(i + 1));
				Sr_marksheet_l[i]->Size = System::Drawing::Size(35, 25);
				Sr_marksheet_l[i]->TabIndex = tab_index;
				Sr_marksheet_l[i]->Text = stoS(std::to_string(i + 1) + ')');
				Sr_marksheet_l[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				y_pos += 31;
				tab_index += 4;
			}
			//
			// ID numbers
			//
			y_pos = 124, tab_index = 7;
			for (int i = 0; i < Max_Students; i++) {
				ID_marksheet_l[i]->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
				ID_marksheet_l[i]->BorderStyle = BorderStyle::FixedSingle;
				ID_marksheet_l[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75f, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				ID_marksheet_l[i]->Location = System::Drawing::Point(45, y_pos);
				ID_marksheet_l[i]->Name = stoS("Name_" + std::to_string(i + 1));
				ID_marksheet_l[i]->Size = System::Drawing::Size(200, 25);
				ID_marksheet_l[i]->TabIndex = tab_index;
				ID_marksheet_l[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				y_pos += 31;
				tab_index += 4;
			}
			//
			// Student Name 
			//
			y_pos = 124, tab_index = 8;
			for (int i = 0; i < Max_Students; i++) {
				Name_marksheet_l[i]->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
				Name_marksheet_l[i]->BorderStyle = BorderStyle::FixedSingle;
				Name_marksheet_l[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75f, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				Name_marksheet_l[i]->Location = System::Drawing::Point(250, y_pos);
				Name_marksheet_l[i]->Name = stoS("Name_" + std::to_string(i + 1));
				Name_marksheet_l[i]->Size = System::Drawing::Size(300, 25);
				Name_marksheet_l[i]->TabIndex = tab_index;
				Name_marksheet_l[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				y_pos += 31;
				tab_index += 4;
			}


			y_pos = 124, tab_index = 9;
			for (int i = 0; i < Max_Students; i++) {
				Marks_marksheet_tb[i]->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
				Marks_marksheet_tb[i]->BorderStyle = BorderStyle::FixedSingle;
				Marks_marksheet_tb[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				Marks_marksheet_tb[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75f, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				Marks_marksheet_tb[i]->Location = System::Drawing::Point(555, y_pos);
				Marks_marksheet_tb[i]->Name = stoS("pass_" + std::to_string(i + 1));
				Marks_marksheet_tb[i]->Size = System::Drawing::Size(200, 25);
				Marks_marksheet_tb[i]->TabIndex = tab_index;
				Marks_marksheet_tb[i]->TextAlign = HorizontalAlignment::Center;
				y_pos += 31;
				tab_index += 4;
			}

			// 
			// Marksheet
			// 
			this->AutoScroll = true;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(770, 450);
			for (int i = 0; i < Max_Students; i++) {
				this->Controls->Add(this->Sr_marksheet_l[i]);
				this->Controls->Add(this->Name_marksheet_l[i]);
				this->Controls->Add(this->ID_marksheet_l[i]);
				this->Controls->Add(this->Marks_marksheet_tb[i]);
			}
			this->Controls->Add(this->Sr_header);
			this->Controls->Add(this->Name_header);
			this->Controls->Add(this->ID_header);
			this->Controls->Add(this->Marks_header);
			this->Controls->Add(this->Save_marksheet_button);
			this->Controls->Add(this->Back_from_marksheet_button);
			this->Controls->Add(this->Marksheet_header);
			this->Name = L"Marksheet";
			this->Text = L"Marksheet";
			load_marksheet();
			this->ResumeLayout(false);

			this->PerformLayout();

		}
		// Marksheet - end

		// Attendance Manager - start
		void InitializeComponent_AttendanceManager(void)
		{
			int tab_index = 0;
			
			this->Attendance_header = (gcnew Label());

			this->Save_att_button = (gcnew Button());
			this->Back_from_att_button = (gcnew Button());
			this->Page_sel_att_button = gcnew array<Button^>(Max_Weeks);
			for (int i = 0; i < Max_Weeks; i++)
				this->Page_sel_att_button[i] = (gcnew Button());

			this->Sr_header = (gcnew Label());
			this->ID_header = (gcnew Label());
			this->Name_header = (gcnew Label());

			this->Att_lec_header = gcnew array<Label^>(Lec_per_Week);
			for (int i = 0; i < Lec_per_Week; i++) {
				this->Att_lec_header[i] = (gcnew Label());
			}

			
			this->Att_cb = gcnew array<array<ComboBox^>^>(Max_Students);
			for (int i = 0; i < Max_Students; i++) {
				this->Sr_att_l[i] = (gcnew Label());
				this->ID_att_l[i] = (gcnew Label());
				this->Name_att_l[i] = (gcnew Label());

				this->Att_cb[i] = gcnew array<ComboBox^>(Lec_per_Week);
				for (int j = 0; j < Lec_per_Week; j++) {
					this->Att_cb[i][j] = (gcnew ComboBox());
				}
			}

			this->SuspendLayout();

			// 
			// Attendance_header
			// 
			this->Attendance_header->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
			this->Attendance_header->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->Attendance_header->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Attendance_header->Location = System::Drawing::Point(10, 20);
			this->Attendance_header->Name = L"Attendance_header";
			this->Attendance_header->Size = System::Drawing::Size(680, 31);
			this->Attendance_header->Text = L"Manage Attendence";
			this->Attendance_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			//
			// Save_marksheet_button
			// 
			this->Save_att_button->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
			this->Save_att_button->BackColor = System::Drawing::Color::Lavender;
			this->Save_att_button->FlatStyle = FlatStyle::Popup;
			this->Save_att_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Save_att_button->Location = System::Drawing::Point(660, 61);
			this->Save_att_button->Name = L"Save_marksheet_button";
			this->Save_att_button->Size = System::Drawing::Size(100, 25);
			this->Save_att_button->TabIndex = tab_index++;
			this->Save_att_button->Text = L"Save";
			this->Save_att_button->UseVisualStyleBackColor = false;
			this->Save_att_button->Click += gcnew System::EventHandler(this, &Teacher::Save_att_button_Click);
			// 
			// Back_button
			//
			this->Back_from_att_button->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
			this->Back_from_att_button->BackColor = System::Drawing::Color::Lavender;
			this->Back_from_att_button->FlatStyle = FlatStyle::Popup;
			this->Back_from_att_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Back_from_att_button->Location = System::Drawing::Point(5, 61);
			this->Back_from_att_button->Name = L"Back_button";
			this->Back_from_att_button->Size = System::Drawing::Size(100, 25);
			this->Back_from_att_button->TabIndex = tab_index++;
			this->Back_from_att_button->Text = L"Back";
			this->Back_from_att_button->UseVisualStyleBackColor = false;
			this->Back_from_att_button->Click += gcnew System::EventHandler(this, &Teacher::Back_from_att_button_Click);

			//
			// Page_sel_button
			for (int i = 0; i < Max_Weeks; i++) {
				this->Page_sel_att_button[i]->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
				this->Page_sel_att_button[i]->BackColor = System::Drawing::Color::Lavender;
				this->Page_sel_att_button[i]->FlatStyle = FlatStyle::Popup;
				this->Page_sel_att_button[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Page_sel_att_button[i]->Top = 93;
				if (i == 0)
					this->Page_sel_att_button[i]->Left = 250;
				else
					this->Page_sel_att_button[i]->Left = this->Page_sel_att_button[i-1]->Right + 2;
				this->Page_sel_att_button[i]->Name = L"Page_sel_button";
				this->Page_sel_att_button[i]->Size = System::Drawing::Size(30, 25);
				this->Page_sel_att_button[i]->TabIndex = tab_index++;
				this->Page_sel_att_button[i]->Text = (i + 1).ToString();
				this->Page_sel_att_button[i]->UseVisualStyleBackColor = false;
				this->Page_sel_att_button[i]->Tag = i + 1;
				this->Page_sel_att_button[i]->Click += gcnew System::EventHandler(this, &Teacher::Load_page);
			}
			//
			// Sr_header
			//
			this->Sr_header->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
			this->Sr_header->BorderStyle = BorderStyle::FixedSingle;
			this->Sr_header->FlatStyle = FlatStyle::Popup;
			this->Sr_header->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->Sr_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Sr_header->Location = System::Drawing::Point(5, 124);
			this->Sr_header->Name = L"Sr_marksheet_l_h";
			this->Sr_header->Size = System::Drawing::Size(35, 25);
			this->Sr_header->Text = L"Sr.";
			this->Sr_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ID_header
			// 
			this->ID_header->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
			this->ID_header->BorderStyle = BorderStyle::FixedSingle;
			this->ID_header->FlatStyle = FlatStyle::Popup;
			this->ID_header->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ID_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ID_header->Location = System::Drawing::Point(this->Sr_header->Right + 5, 124);
			this->ID_header->Name = L"ID_h";
			this->ID_header->Size = System::Drawing::Size(100, 25);
			this->ID_header->Text = L"Roll no.";
			this->ID_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Name_header
			// 
			this->Name_header->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
			this->Name_header->BorderStyle = BorderStyle::FixedSingle;
			this->Name_header->FlatStyle = FlatStyle::Popup;
			this->Name_header->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->Name_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name_header->Location = System::Drawing::Point(this->ID_header->Right + 5, 124);
			this->Name_header->Name = L"Name_h";
			this->Name_header->Size = System::Drawing::Size(200, 25);
			this->Name_header->Text = L"Student Name";
			this->Name_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			//
			// Att_lec_header
			//
			for (int i = 0; i < Lec_per_Week; i++) {
				this->Att_lec_header[i]->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
				this->Att_lec_header[i]->BorderStyle = BorderStyle::FixedSingle;
				this->Att_lec_header[i]->FlatStyle = FlatStyle::Popup;
				this->Att_lec_header[i]->BackColor = System::Drawing::SystemColors::ControlLightLight;
				this->Att_lec_header[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Att_lec_header[i]->Top = this->Name_header->Top;
				if (i == 0)
					this->Att_lec_header[i]->Left = 355;
				else
					this->Att_lec_header[i]->Left = this->Att_lec_header[i - 1]->Right + 5;
				this->Att_lec_header[i]->Name = L"Att_lec" + (i+1).ToString() + "_h";
				this->Att_lec_header[i]->Size = System::Drawing::Size(200, 25);
				this->Att_lec_header[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			}
			// 
			// Serial labels
			//
			for (int i = 0; i < Max_Students; i++) {
				this->Sr_att_l[i]->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
				this->Sr_att_l[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Sr_att_l[i]->Left = 5;
				if (i == 0)
					this->Sr_att_l[i]->Top = 155;
				else
					this->Sr_att_l[i]->Top = this->Sr_att_l[i-1]->Bottom + 6;
				this->Sr_att_l[i]->Name = "Sr_" + (i + 1).ToString();
				this->Sr_att_l[i]->Size = System::Drawing::Size(35, 25);
				this->Sr_att_l[i]->Text = (i + 1).ToString() + L')';
				this->Sr_att_l[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			}
			//
			// ID 
			//  
			for (int i = 0; i < Max_Students; i++) {
				this->ID_att_l[i]->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
				this->ID_att_l[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				this->ID_att_l[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->ID_att_l[i]->Location = System::Drawing::Point(this->Sr_att_l[i]->Right + 5, this->Sr_att_l[i]->Top);
				this->ID_att_l[i]->Name = "ID_" + (i + 1).ToString();
				this->ID_att_l[i]->Size = System::Drawing::Size(100, 25);
				this->ID_att_l[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			}
			//
			// Name_att_l
			//
			for (int i = 0; i < Max_Students; i++) {
				this->Name_att_l[i]->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
				this->Name_att_l[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				this->Name_att_l[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Name_att_l[i]->Location = System::Drawing::Point(this->ID_att_l[i]->Right + 5, this->ID_att_l[i]->Top);
				this->Name_att_l[i]->Name = "Name_" + (i + 1).ToString();
				this->Name_att_l[i]->Size = System::Drawing::Size(200, 25);
				this->Name_att_l[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			}
			//
			// Combo boxes
			//
			for (int i = 0; i < Max_Students; i++) {
				for (int j = 0; j < Lec_per_Week; j++) {
					this->Att_cb[i][j]->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left);
					this->Att_cb[i][j]->BackColor = System::Drawing::Color::WhiteSmoke;
					this->Att_cb[i][j]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(0)));
					this->Att_cb[i][j]->DropDownStyle = ComboBoxStyle::DropDownList;
					this->Att_cb[i][j]->Items->AddRange(gcnew array<Object^>(4) { L" ", L"Present", L"Absent", L"Leave" });
					
					if (j == 0)
						this->Att_cb[i][j]->Left = 355;
					else
						this->Att_cb[i][j]->Left = this->Att_cb[i][j-1]->Right + 5;
					if ( i == 0 )
						this->Att_cb[i][j]->Top = this->Att_lec_header[j]->Bottom + 6;
					else
						this->Att_cb[i][j]->Top = this->Att_cb[i-1][j]->Bottom + 6;

					this->Att_cb[i][j]->Name = "Sr." + (i + 1).ToString() + "_lec" + (j + 1).ToString();
					this->Att_cb[i][j]->Size = System::Drawing::Size(200, 25);
					this->Att_cb[i][j]->TabIndex = tab_index++;
					this->Att_cb[i][j]->SelectedIndex = 0;
				}
			}

			this->AutoScroll = true;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(780, 313);
			this->Name = L"Attendance_manager";
			this->Text = L"Attendence Manager";
			this->Controls->Add(this->Attendance_header);
			this->Controls->Add(this->Save_att_button);
			this->Controls->Add(this->Back_from_att_button);

			this->Controls->Add(this->Sr_header);
			this->Controls->Add(this->ID_header);
			this->Controls->Add(this->Name_header);

			this->Controls->AddRange(this->Att_lec_header);

			this->Controls->AddRange(this->Page_sel_att_button);
			this->Controls->AddRange(this->Sr_att_l);
			this->Controls->AddRange(this->Name_att_l);
			this->Controls->AddRange(this->ID_att_l);
			for (int i = 0; i < Max_Students; i++)
				this->Controls->AddRange(this->Att_cb[i]);

			load_att();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
		// Attendance Manager - end

	// Back - functions - start
	private: System::Void Back_from_att_button_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		this->Controls->Clear();
		InitializeComponent_OperationSelector();
		this->Show();
	}
	private: System::Void Back_from_opsel_button_Click(System::Object^ sender, System::EventArgs^ e) {
		// Remove all the controls
		this->Controls->Clear();

		this->Hide();
		InitializeComponent();
		this->Show();
	}
	private: System::Void back_from_marksheet_button_click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		this->Controls->Clear();
		if (exam_type == Exam_quiz || exam_type == Exam_assignment) {
			InitializeComponent_ActivitySelector();
		}
		else {
			InitializeComponent_ExamType();
		}
		this->Show();
	}
	private: System::Void back_to_opsel(System::Object^ sender, System::EventArgs^ e) {
		// Remove all the controls
		this->Controls->Clear();

		this->Hide();
		InitializeComponent_OperationSelector();
		this->Show();
	}
	private: System::Void back_to_exam_type(System::Object^ sender, System::EventArgs^ e) {
		// Remove all the controls
		this->Controls->Clear();

		this->Hide();
		InitializeComponent_ExamType();
		this->Show();
	}
	// Back - functions - end

	// Save - functions - start
	private: System::Void Save_marksheet_button_click(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < Max_Students; i++) {
			if ((ceil(stof(Stos(this->Marks_marksheet_tb[i]->Text)) * 100) / 100.0f) > Max_marks[exam_type]) {
				MessageBox::Show("Marks of student no. " + stoS(std::to_string(i + 1)) + " exceed the max limit!\nSkipping saving marks...");
				return;
			}
			else if ((ceil(stof(Stos(this->Marks_marksheet_tb[i]->Text)) * 100) / 100.0f) < 0) {
				MessageBox::Show("Marks of student no. " + stoS(std::to_string(i + 1)) + " cannot be negative!\nSkipping saving marks...");
				return;
			}
		}

		for (int i = 0; i < Max_Students; i++) {
			if (exam_type == Exam_quiz)
				Student_marks[curr_sec][i].quizzes[curr_subject][curr_quiz] = ceil(stof(Stos(this->Marks_marksheet_tb[i]->Text)) * 100) / 100.0f;
			else if (exam_type == Exam_assignment)
				Student_marks[curr_sec][i].assignment[curr_subject][curr_assignment] = ceil(stof(Stos(this->Marks_marksheet_tb[i]->Text)) * 100) / 100.0f;
			else if (exam_type == Exam_mid1)
				Student_marks[curr_sec][i].mid1[curr_subject] = ceil(stof(Stos(this->Marks_marksheet_tb[i]->Text)) * 100) / 100.0f;
			else if (exam_type == Exam_mid2)
				Student_marks[curr_sec][i].mid2[curr_subject] = ceil(stof(Stos(this->Marks_marksheet_tb[i]->Text)) * 100) / 100.0f;
			else if (exam_type == Exam_final)
				Student_marks[curr_sec][i].finals[curr_subject] = ceil(stof(Stos(this->Marks_marksheet_tb[i]->Text)) * 100) / 100.0f;
		}

		Calc_total(Student_marks[curr_sec], Max_Students, curr_subject, saved.quizzes[curr_sec][curr_subject], saved.assignments[curr_sec][curr_subject]);

		WriteMarks(Marks_Folder, string("Sec_") + Sec_list[curr_sec] + ".txt", Student_marks[curr_sec], sizeof(Student_marks[curr_sec]) / sizeof(*Student_marks[curr_sec]), subjects_details[curr_sec][curr_subject], Max_Subjects, Max_Quizzes, Max_Assignments);
		MessageBox::Show("Marks updated successfully !");
	}
	private: System::Void Save_att_button_Click(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < Max_Students; i++) {
			Student_att[curr_sec][i].name = Stos(this->Name_att_l[i]->Text);
			Student_att[curr_sec][i].id = Stos(this->ID_att_l[i]->Text);
			for ( int j = 0; j < Lec_per_Week; j++)
				Student_att[curr_sec][i].lec[curr_subject][curr_week][j] = Stos(this->Att_cb[i][j]->SelectedItem->ToString());
		}

		WriteAttendence(Attendance_Folder, string("Sec_") + Sec_list[curr_sec] + ".txt", Student_att[curr_sec], Max_Students, Max_Subjects, Max_Weeks, Lec_per_Week);

		MessageBox::Show("Attendance updated successfully !");
	}
	// Save - functions - end

	// Teacher - functions - start
	private: void configure_button(std::string course_code, std::string subject_name, int section_no, int button_no) {
		this->Classes[button_no]->Text = stoS(course_code + " - " + subject_name + " - Section " + Sec_list[section_no]);
		if (button_no == 0)
			this->Classes[button_no]->Top = 125;
		else
			this->Classes[button_no]->Top = this->Classes[button_no-1]->Bottom + 10;
		this->Classes[button_no]->Visible = true;
		
		this->Reset_pass_button->Location = Point(this->Classes[button_no]->Left, this->Classes[button_no]->Bottom + 10);
		this->Logout_button->Location = Point(this->Reset_pass_button->Left, this->Reset_pass_button->Bottom + 10);
	}
	private: void Teacher_Load(void) {
		int button_no = 0;
		this->Teacher_hp_header->Text += stoS(Teach_Cred[teach_no].name + "!");

		for (int i = 0; i < saved.sections; i++) {
			for (int j = 0; j < Max_Subjects; j++) {
				if (subjects_details[i][j].teach_no == teach_no && subjects_details[i][j].course_code != "" && subjects_details[i][j].name != "") {
					section->Add(i);
					subject->Add(j);
					configure_button(subjects_details[i][j].course_code, subjects_details[i][j].name, i, button_no++);
				}
			}
		}
	}
	private: System::Void Update_teacher_creds(System::Object^ sender, System::EventArgs^ e) {
		if (this->New_Pass_tb->Text == this->New_Pass_Confirmation_tb->Text && (this->New_Pass_tb->TextLength >= 4)) {
			Teach_Cred[teach_no].pass = Stos(this->New_Pass_tb->Text);

			WriteCredentials(Cred_Folder, Teacher_Cred_File, Teach_Cred, Max_Teachers);

			this->New_Pass_prompt->Close();
		}
		else if (this->New_Pass_tb->TextLength < 4)
			MessageBox::Show("Pasword must be atleast 4 characters!");
		else if (this->New_Pass_tb->Text != this->New_Pass_Confirmation_tb->Text)
			MessageBox::Show("Paswords do not match. Please try again!");
	}
	private: System::Void Select_class(System::Object^ sender, System::EventArgs^ e) {
		int class_no = stoi(Stos(static_cast<Control^>(sender)->Tag->ToString()));
		curr_sec = section[class_no];
		curr_subject = subject[class_no];
		open_operation_selector();
	}
	private: System::Void Reset_pass_button_click(System::Object^ sender, System::EventArgs^ e) {
		this->New_Pass_prompt->Size = System::Drawing::Size(250, 200);
		this->New_Pass_prompt->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
		this->New_Pass_prompt->Text = "Reset Password";
		this->New_Pass_prompt->StartPosition = FormStartPosition::CenterParent;

		this->New_pass_message_label->Size = System::Drawing::Size(200, 30);
		this->New_pass_message_label->Location = System::Drawing::Point(25, 10);
		this->New_pass_message_label->Text = "Enter new password : ";
		this->New_pass_message_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));

		this->New_Pass_tb->Size = System::Drawing::Size(200, 30);;
		this->New_Pass_tb->Location = System::Drawing::Point(25, 50);
		this->New_Pass_tb->UseSystemPasswordChar = true;
		this->New_Pass_tb->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));

		this->New_Pass_Confirmation_tb->Size = System::Drawing::Size(200, 30);;
		this->New_Pass_Confirmation_tb->Location = System::Drawing::Point(25, 90);
		this->New_Pass_Confirmation_tb->UseSystemPasswordChar = true;
		this->New_Pass_Confirmation_tb->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));

		this->New_pass_update_button->Text = "Update";
		this->New_pass_update_button->Location = System::Drawing::Point(175, 120);
		this->New_pass_update_button->Size = System::Drawing::Size(50, 20);
		this->New_Pass_prompt->AcceptButton = this->New_pass_update_button;
		this->New_pass_update_button->Click += gcnew System::EventHandler(this, &Teacher::Update_teacher_creds);

		this->New_Pass_prompt->Controls->Add(this->New_pass_message_label);
		this->New_Pass_prompt->Controls->Add(this->New_Pass_tb);
		this->New_Pass_prompt->Controls->Add(this->New_Pass_Confirmation_tb);
		this->New_Pass_prompt->Controls->Add(this->New_pass_update_button);
		this->New_Pass_prompt->ShowDialog();
	}
	private: System::Void Logout_button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (MessageBox::Show(L"Do you want to logout?", L"Login Confirmation", MessageBoxButtons::YesNo)
			== System::Windows::Forms::DialogResult::Yes)
			this->Close();
	}
	private: void open_operation_selector(void) {
		// Remove all the controls
		this->Controls->Clear();

		this->Hide();
		InitializeComponent_OperationSelector();
		this->Show();
	}
	// Teacher - functions - end

	// Operation_selector - functions - start
	private: System::Void Manage_marks_button_Click(System::Object^ sender, System::EventArgs^ e) {
		// Remove all the controls
		this->Controls->Clear();

		this->Hide();
		InitializeComponent_ExamType();
		this->Show();
	}
	private: System::Void Manage_attendance_button_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Controls->Clear();

		this->Hide();
		InitializeComponent_AttendanceManager();
		this->Show();
	}
	private: System::Void Calculate_Grades_button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (subjects_details[curr_sec][curr_subject].grading == "Relative") {
			Calc_grade_relative(Student_marks[curr_sec], Max_Students, subjects_details[curr_sec][curr_subject], curr_subject,
				saved.quizzes[curr_sec][curr_subject], saved.assignments[curr_sec][curr_subject]);

			MessageBox::Show(stoS(subjects_details[curr_sec][curr_subject].name + " - Section " + Sec_list[curr_sec] + " graded relatively!"));

			WriteMarks(Marks_Folder, string("Sec_") + Sec_list[curr_sec] + ".txt", Student_marks[curr_sec], Max_Students, subjects_details[curr_sec][curr_subject], Max_Subjects, Max_Quizzes, Max_Assignments);

			WriteSubjects(Subject_Folder, string("Sec_") + Sec_list[curr_sec] + ".txt", subjects_details[curr_sec], Max_Sections);

		}
		else if (subjects_details[curr_sec][curr_subject].grading == "Absolute") {
			Calc_grade_absolute(Student_marks[curr_sec], Max_Students, subjects_details[curr_sec][curr_subject], curr_subject, saved.quizzes[curr_sec][curr_subject],
				saved.assignments[curr_sec][curr_subject]);

			MessageBox::Show(stoS(subjects_details[curr_sec][curr_subject].name + " - Section " + Sec_list[curr_sec] + " graded absolutely!"));
			WriteMarks(Marks_Folder, string("Sec_") + Sec_list[curr_sec] + ".txt", Student_marks[curr_sec], Max_Students, subjects_details[curr_sec][curr_subject], Max_Subjects, Max_Quizzes, Max_Assignments);

			WriteSubjects(Subject_Folder, string("Sec_") + Sec_list[curr_sec] + ".txt", subjects_details[curr_sec], Max_Subjects);
		}
		else
			MessageBox::Show("Grading type not selected. Please contact an administrator!");

	}
	// Operation_selector - functions - end 

	// Exam_type - functions - start
	private: System::Void Quiz_button_Click(System::Object^ sender, System::EventArgs^ e) {
		exam_type = Exam_quiz;
		// Remove all the controls
		this->Controls->Clear();
		this->Hide();
		InitializeComponent_ActivitySelector();
		this->Show();
	}
	private: System::Void Assignment_button_Click(System::Object^ sender, System::EventArgs^ e) {
		exam_type = Exam_assignment;

		this->Controls->Clear();
		this->Hide();
		InitializeComponent_ActivitySelector();
		this->Show();

	}
	private: System::Void Mid1_button_Click(System::Object^ sender, System::EventArgs^ e) {
		exam_type = Exam_mid1;
		open_marksheet();
	}
	private: System::Void Mid2_button_Click(System::Object^ sender, System::EventArgs^ e) {
		exam_type = Exam_mid2;
		open_marksheet();
	}
	private: System::Void Finals_button_Click(System::Object^ sender, System::EventArgs^ e) {
		exam_type = Exam_final;
		open_marksheet();
	}
	private: System::Void open_marksheet(Void) {
		WriteSettings(Settings_Folder, Settings_File, saved);

		this->Hide();
		this->Controls->Clear();
		InitializeComponent_Marksheet();
		this->Show();
	}
	// Exam_type - functions - end


	// Activity_selector - functions - start
	private: void load_activity_buttons(int sec, int Max_activity) {
		for (int i = 0; i < Max_activity; i++) {
			if (sec > i) this->Activities[i]->Visible = true;
			else this->Activities[i]->Visible = false;

			if (sec == 1) this->Activity_del_button->Visible = false;
			else this->Activity_del_button->Visible = true;

			if (sec == Max_activity) this->New_Activity_button->Visible = false;
			else this->New_Activity_button->Visible = true;
		}
	}
	private: System::Void Select_activity(System::Object^ sender, System::EventArgs^ e) {
		if (exam_type == Exam_quiz)
			curr_quiz = stoi(Stos((static_cast<Control^>(sender)->Tag->ToString())));
		else if (exam_type == Exam_assignment)
			curr_assignment = stoi(Stos((static_cast<Control^>(sender)->Tag->ToString())));
		open_marksheet();
	}
	private: System::Void Create_New_Activity(System::Object^ sender, System::EventArgs^ e) {
		int saved_activity;
		if (exam_type == Exam_quiz) {
			load_activity_buttons(++saved.quizzes[curr_subject][curr_sec], Max_activity);
			saved_activity = saved.quizzes[curr_subject][curr_sec];
		}
		else if (exam_type == Exam_assignment) {
			load_activity_buttons(++saved.assignments[curr_subject][curr_sec], Max_activity);
			saved_activity = saved.assignments[curr_subject][curr_sec];
		}
		// -1 cause saved.quizzes[*] start from 1 and array indexes start from 0
		this->New_Activity_button->Left = this->Activities[saved_activity - 1]->Left;
		this->Activity_del_button->Left = this->Activities[saved_activity - 1]->Left + 175;
		this->Back_from_Activity_sel_button->Left = this->New_Activity_button->Left;

		this->Activity_del_button->Top = this->Activities[saved_activity - 1]->Top;
		this->New_Activity_button->Top = this->Activity_del_button->Top + 31;
		if (saved_activity != Max_activity)
			this->Back_from_Activity_sel_button->Top = this->New_Activity_button->Top + 31;
		this->Activity_del_button->BringToFront();
	}
	private: System::Void Delete_a_Activity(System::Object^ sender, System::EventArgs^ e) {
		int saved_activity;
		if (exam_type == Exam_quiz) {
			load_activity_buttons(--saved.quizzes[curr_subject][curr_sec], Max_activity);
			saved_activity = saved.quizzes[curr_subject][curr_sec];
		}
		else if (exam_type == Exam_assignment) {
			load_activity_buttons(--saved.assignments[curr_subject][curr_sec], Max_activity);
			saved_activity = saved.assignments[curr_subject][curr_sec];
		}
		// -1 cause saved.quizzes[*] start from 1 and array indexes start from 0
		this->New_Activity_button->Left = this->Activities[saved_activity - 1]->Left;
		this->Activity_del_button->Left = this->Activities[saved_activity - 1]->Left + 175;
		this->Back_from_Activity_sel_button->Left = this->New_Activity_button->Left;

		this->Activity_del_button->Top = this->Activities[saved_activity - 1]->Top;
		this->New_Activity_button->Top = this->Activity_del_button->Top + 31;
		this->Back_from_Activity_sel_button->Top = this->New_Activity_button->Top + 31;
		this->Activity_del_button->BringToFront();

	}
	// Activity_selector - functions - end

	// Marksheet - functions - start
	private: void load_marksheet() {

		this->Marksheet_header->Text = stoS(string("Section : ") + Sec_list[curr_sec] + " - ");
		if (exam_type == Exam_quiz)
			this->Marksheet_header->Text += stoS("Quiz no. " + std::to_string(curr_quiz + 1));
		else if (exam_type == Exam_assignment)
			this->Marksheet_header->Text += stoS("Assignment no. " + std::to_string(curr_assignment + 1));
		else if (exam_type == Exam_mid1)
			this->Marksheet_header->Text += L"Midterm no. 1";
		else if (exam_type == Exam_mid2)
			this->Marksheet_header->Text += L"Midterm no. 2";
		else if (exam_type == Exam_final)
			this->Marksheet_header->Text += L"Final";

		for (int i = 0; i < Max_Students; i++) {
			this->ID_marksheet_l[i]->Text = stoS(Student_marks[curr_sec][i].id);
			this->Name_marksheet_l[i]->Text = stoS(Student_marks[curr_sec][i].name);
			if (exam_type == Exam_quiz)
				this->Marks_marksheet_tb[i]->Text = stoS(to_string_with_precision(Student_marks[curr_sec][i].quizzes[curr_subject][curr_quiz]));
			else if (exam_type == Exam_assignment)
				this->Marks_marksheet_tb[i]->Text = stoS(to_string_with_precision(Student_marks[curr_sec][i].assignment[curr_subject][curr_assignment]));
			else if (exam_type == Exam_mid1)
				this->Marks_marksheet_tb[i]->Text = stoS(to_string_with_precision(Student_marks[curr_sec][i].mid1[curr_subject]));
			else if (exam_type == Exam_mid2)
				this->Marks_marksheet_tb[i]->Text = stoS(to_string_with_precision(Student_marks[curr_sec][i].mid2[curr_subject]));
			else if (exam_type == Exam_final)
				this->Marks_marksheet_tb[i]->Text = stoS(to_string_with_precision(Student_marks[curr_sec][i].finals[curr_subject]));
		}
	}
	// Marksheet - functions - end

	// Attendance - functions - start
	private: void load_att(void) {
		curr_week = 0;
		for (int i = 0; i < Max_Students; i++) {
			this->ID_att_l[i]->Text = stoS(Student_att[curr_sec][i].id);
			this->Name_att_l[i]->Text = stoS(Student_att[curr_sec][i].name);
			for (int j = 0; j < Lec_per_Week; j++)
				this->Att_cb[i][j]->SelectedItem = stoS(Student_att[curr_sec][i].lec[curr_subject][curr_week][j]);
		}
		load_att_page(curr_week+1);
	}
	private: void load_att_page(int page_no) {

		for ( int i = 0; i < Lec_per_Week; i++ )
			this->Att_lec_header[i]->Text = "Week no." + page_no.ToString() + " Lec. " + (i+1).ToString();
	
		for (int i = 0; i < Max_Students; i++) {
			for (int j = 0; j < Lec_per_Week; j++) {
				if ( !Student_att[curr_sec][i].lec[curr_subject][page_no-1][j].empty() )
					this->Att_cb[i][j]->SelectedItem = stoS(Student_att[curr_sec][i].lec[curr_subject][page_no-1][j]);
				else 
					this->Att_cb[i][j]->SelectedItem = " ";
			}
		}

		curr_week = page_no-1;
	}
	private: System::Void Load_page(System::Object^ sender, System::EventArgs^ e) {
		// Save the current week's data in the array
		for (int i = 0; i < Max_Students; i++) {
			for (int j = 0; j < Lec_per_Week; j++) {
				Student_att[curr_sec][i].lec[curr_subject][curr_week][j] = Stos(this->Att_cb[i][j]->SelectedItem->ToString());
			}
		}

		load_att_page(stoi(Stos(static_cast<Control^>(sender)->Tag->ToString())));
	}
	// Attendance - functions - end
	};
}
