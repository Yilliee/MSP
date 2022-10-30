#pragma once
#include "variables.h"
#include "functions.h"

namespace MSP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// summary for student_management
	/// </summary>
	public ref class Marksheet : public System::Windows::Forms::Form
	{
	public:
		Marksheet(void)
		{
			initializecomponent();
			//
			//todo: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// clean up any resources being used.
		/// </summary>
		~Marksheet()
		{
			if (components)
			{
				//delete components;
			}
		}

	protected:

	private: array<Label^>^ Sr_l = gcnew array<Label^>(Max_Students);
	private: array<Label^>^ Name_l = gcnew array<Label^>(Max_Students);
	private: array<Label^>^ ID_l = gcnew array<Label^>(Max_Students);
	private: array<TextBox^>^ Marks_tb = gcnew array<TextBox^>(Max_Students);

	private: System::Windows::Forms::Label^ Marksheet_header;
	private: System::Windows::Forms::Button^ Save_button;
	private: System::Windows::Forms::Button^ Back_button;

	private: System::Windows::Forms::Label^ Sr_header;
	private: System::Windows::Forms::Label^ Name_header;
	private: System::Windows::Forms::Label^ ID_header;
	private: System::Windows::Forms::Label^ Marks_header;

	private:
		/// <summary>
		/// required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form designer generated code
		/// <summary>
		/// required method for designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		/// 
		void initializecomponent(void)
		{
			this->Marksheet_header = (gcnew System::Windows::Forms::Label());
			this->Save_button = (gcnew System::Windows::Forms::Button());
			this->Back_button = (gcnew System::Windows::Forms::Button());

			this->Sr_header = (gcnew System::Windows::Forms::Label());
			this->Name_header = (gcnew System::Windows::Forms::Label());
			this->ID_header = (gcnew System::Windows::Forms::Label());
			this->Marks_header = (gcnew System::Windows::Forms::Label());

			for (int i = 0; i < Max_Students; i++) {
				Sr_l[i] = gcnew Label();
				Name_l[i] = gcnew Label();
				ID_l[i] = gcnew Label();
				Marks_tb[i] = gcnew TextBox();
			}

			this->SuspendLayout();
			// 
			// Marksheet_header
			// 
			this->Marksheet_header->Anchor = static_cast< System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left);
			this->Marksheet_header->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->Marksheet_header->Font = (gcnew System::Drawing::Font(L"Times new Roman", 20.25f, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Marksheet_header->Location = System::Drawing::Point(10, 20);
			this->Marksheet_header->Name = L"Marksheet_header";
			this->Marksheet_header->Size = System::Drawing::Size(750, 31);
			this->Marksheet_header->TabIndex = 0;
			this->Marksheet_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			// 
			// Save_button
			//
			this->Save_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left);
			this->Save_button->BackColor = System::Drawing::Color::Lavender;
			this->Save_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Save_button->Font = (gcnew System::Drawing::Font(L"Segoe UI semiBold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Save_button->Location = System::Drawing::Point(655, 61);
			this->Save_button->Name = L"Save_button";
			this->Save_button->Size = System::Drawing::Size(100, 23);
			this->Save_button->TabIndex = 1;
			this->Save_button->Text = L"Save";
			this->Save_button->UseVisualStyleBackColor = false;
			this->Save_button->Click += gcnew System::EventHandler(this, &Marksheet::Save_button_click);
			// 
			// Back_button
			//
			this->Back_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
			this->Back_button->BackColor = System::Drawing::Color::Lavender;
			this->Back_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Back_button->Font = (gcnew System::Drawing::Font(L"Segoe UI semiBold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Back_button->Location = System::Drawing::Point(5, 61);
			this->Back_button->Name = L"Back_button";
			this->Back_button->Size = System::Drawing::Size(101, 23);
			this->Back_button->TabIndex = 1;
			this->Back_button->Text = L"Back";
			this->Back_button->UseVisualStyleBackColor = false;
			this->Back_button->Click += gcnew System::EventHandler(this, &Marksheet::back_button_click);
			
			// 
			// Sr_header
			// 
			this->Sr_header->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
			this->Sr_header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Sr_header->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
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
			this->ID_header->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
			this->ID_header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ID_header->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->ID_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ID_header->Location = System::Drawing::Point(45, 93);
			this->ID_header->Name = L"ID_header";
			this->ID_header->Size = System::Drawing::Size(200, 25);
			this->ID_header->TabIndex = 3;
			this->ID_header->Text = L"ID.";
			this->ID_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Name_header
			// 
			this->Name_header->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
			this->Name_header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Name_header->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
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
			this->Marks_header->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left);
			this->Marks_header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Marks_header->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
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
				Sr_l[i]->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
				Sr_l[i]->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				Sr_l[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				Sr_l[i]->Location = System::Drawing::Point(5, y_pos);
				Sr_l[i]->Name = std_to_System_string("Sr_" + std::to_string(i + 1));
				Sr_l[i]->Size = System::Drawing::Size(35, 25);
				Sr_l[i]->TabIndex = tab_index;
				Sr_l[i]->Text = std_to_System_string(std::to_string(i + 1) + ')');
				Sr_l[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				y_pos += 31;
				tab_index += 4;
			}
			//
			// ID numbers
			//
			y_pos = 124, tab_index = 7;
			for (int i = 0; i < Max_Students; i++) {
				ID_l[i]->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
				ID_l[i]->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				ID_l[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75f, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				ID_l[i]->Location = System::Drawing::Point(45, y_pos);
				ID_l[i]->Name = std_to_System_string("Name_" + std::to_string(i + 1));
				ID_l[i]->Size = System::Drawing::Size(200, 25);
				ID_l[i]->TabIndex = tab_index;
				ID_l[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				y_pos += 31;
				tab_index += 4;
			}
			//
			// Student Name 
			//
			y_pos = 124, tab_index = 8;
			for (int i = 0; i < Max_Students; i++) {
				Name_l[i]->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
				Name_l[i]->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				Name_l[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75f, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				Name_l[i]->Location = System::Drawing::Point(250, y_pos);
				Name_l[i]->Name = std_to_System_string("Name_" + std::to_string(i + 1));
				Name_l[i]->Size = System::Drawing::Size(300, 25);
				Name_l[i]->TabIndex = tab_index;
				Name_l[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				y_pos += 31;
				tab_index += 4;
			}


			y_pos = 124, tab_index = 9;
			for (int i = 0; i < Max_Students; i++) {
				Marks_tb[i]->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
				Marks_tb[i]->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle; 
				Marks_tb[i]->BackColor = System::Drawing::Color::WhiteSmoke; 
				Marks_tb[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75f, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				Marks_tb[i]->Location = System::Drawing::Point(555, y_pos);
				Marks_tb[i]->Name = std_to_System_string("pass_" + std::to_string(i + 1));
				Marks_tb[i]->Size = System::Drawing::Size(200, 25);
				Marks_tb[i]->TabIndex = tab_index;
				Marks_tb[i]->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
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
				this->Controls->Add(this->Sr_l[i]);
				this->Controls->Add(this->Name_l[i]);
				this->Controls->Add(this->ID_l[i]);
				this->Controls->Add(this->Marks_tb[i]);
			}
			this->Controls->Add(this->Sr_header);
			this->Controls->Add(this->Name_header);
			this->Controls->Add(this->ID_header);
			this->Controls->Add(this->Marks_header);
			this->Controls->Add(this->Save_button);
			this->Controls->Add(this->Back_button);
			this->Controls->Add(this->Marksheet_header);
			this->Name = L"Marksheet";
			this->Text = L"Marksheet";
			this->Load += gcnew System::EventHandler(this, &Marksheet::Marksheet_Load);
			this->ResumeLayout(false);
			
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Marksheet_Load(System::Object^ sender, System::EventArgs^ e) {

		this->Marksheet_header->Text = std_to_System_string(System_to_std_string("Section : ") + Sec_list[curr_sec] + " - ");
		if (exam_type == Exam_quiz)
			this->Marksheet_header->Text += std_to_System_string("Quiz no. " + std::to_string(curr_quiz+1));
		else if (exam_type == Exam_mid1)
			this->Marksheet_header->Text += L"Midterm no. 1";
		else if (exam_type == Exam_mid2)
			this->Marksheet_header->Text += L"Midterm no. 2";
		else if (exam_type == Exam_final)
			this->Marksheet_header->Text += L"Final";
		
		for (int i = 0; i < Max_Students; i++) {
			this->ID_l[i]->Text = std_to_System_string(Student_marks[curr_sec][i].id);
			this->Name_l[i]->Text = std_to_System_string(Student_marks[curr_sec][i].name);
			if ( exam_type == Exam_quiz )
				this->Marks_tb[i]->Text = std_to_System_string(std::to_string(Student_marks[curr_sec][i].quizzes[curr_subject][curr_quiz]));
			else if (exam_type == Exam_mid1)
				this->Marks_tb[i]->Text = std_to_System_string(std::to_string(Student_marks[curr_sec][i].mid1[curr_subject]));
			else if (exam_type == Exam_mid2)
				this->Marks_tb[i]->Text = std_to_System_string(std::to_string(Student_marks[curr_sec][i].mid2[curr_subject]));
			else if (exam_type == Exam_final)
				this->Marks_tb[i]->Text = std_to_System_string(std::to_string(Student_marks[curr_sec][i].finals[curr_subject]));
		}
	}
	private: System::Void Save_button_click(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < Max_Students; i++) {
			if (exam_type == Exam_quiz)
				Student_marks[curr_sec][i].quizzes[curr_subject][curr_quiz] = stoi(System_to_std_string(this->Marks_tb[i]->Text));
			else if (exam_type == Exam_mid1)
				Student_marks[curr_sec][i].mid1[curr_subject] = stoi(System_to_std_string(this->Marks_tb[i]->Text));
			else if (exam_type == Exam_mid2)
				Student_marks[curr_sec][i].mid2[curr_subject] = stoi(System_to_std_string(this->Marks_tb[i]->Text));
			else if (exam_type == Exam_final)
				Student_marks[curr_sec][i].finals[curr_subject] = stoi(System_to_std_string(this->Marks_tb[i]->Text));
		}
		std::ofstream stumarks(Marks_Folder + "Sec_" + Sec_list[curr_sec] + ".txt");
		WriteMarks(stumarks, Student_marks[curr_sec], sizeof(Student_marks[curr_sec]) / sizeof(*Student_marks[curr_sec]), Max_Subjects, Max_Quizzes);
	}
	private: System::Void back_button_click(System::Object^ sender, System::EventArgs^ e) {
	
	}
	};
}
