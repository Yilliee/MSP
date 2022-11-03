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
	/// Summary for Subjects_manager
	/// </summary>
	public ref class Subjects_manager : public System::Windows::Forms::Form
	{
	public:
		Subjects_manager(void)
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
		~Subjects_manager()
		{
			if (components)
			{
				delete components;
			}
		}

	// Subjects_manager
	private: array<System::Windows::Forms::Label^>^ Sr_l = gcnew array<System::Windows::Forms::Label^>(Max_Subjects);
	private: array<System::Windows::Forms::TextBox^>^ Course_code = gcnew array<System::Windows::Forms::TextBox^>(Max_Subjects);
	private: array<System::Windows::Forms::TextBox^>^ Subjects = gcnew array<System::Windows::Forms::TextBox^>(Max_Subjects);

	private: System::Windows::Forms::Label^ Subject_mgmt_header;
	
	private: System::Windows::Forms::Button^ Save_button;
	private: System::Windows::Forms::Button^ Back_from_Submgmt_button;

	private: System::Windows::Forms::Label^ Sr_header;
	private: System::Windows::Forms::Label^ Course_code_header;
	private: System::Windows::Forms::Label^ Subject_header;
    // Subject_manager - end

	private:
		/// <summary>
		/// Required 20designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			for (int i = 0; i < Max_Subjects; i++) {
				this->Sr_l[i] = gcnew System::Windows::Forms::Label();
				this->Course_code[i] = gcnew System::Windows::Forms::TextBox();
				this->Subjects[i] = gcnew System::Windows::Forms::TextBox();
			}
			this->Subject_mgmt_header = gcnew System::Windows::Forms::Label();

			this->Save_button = gcnew System::Windows::Forms::Button();
			this->Back_from_Submgmt_button = gcnew System::Windows::Forms::Button();

			this->Sr_header = gcnew System::Windows::Forms::Label();
			this->Course_code_header = gcnew System::Windows::Forms::Label();
			this->Subject_header = gcnew System::Windows::Forms::Label();
			this->SuspendLayout();

			// 
			// Subject_mgmt_header
			// 
			this->Subject_mgmt_header->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
			this->Subject_mgmt_header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Subject_mgmt_header->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Subject_mgmt_header->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Subject_mgmt_header->Location = System::Drawing::Point(5, 20);
			this->Subject_mgmt_header->Name = L"Subject_mgmt_h";
			this->Subject_mgmt_header->Size = System::Drawing::Size(545, 35);
			this->Subject_mgmt_header->TabIndex = 0;
			this->Subject_mgmt_header->Text = L"Subject Management";
			this->Subject_mgmt_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			
			// 
			// Save_button
			//
			this->Save_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
			this->Save_button->BackColor = System::Drawing::Color::Lavender;
			this->Save_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Save_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Save_button->Location = System::Drawing::Point(450, 61);
			this->Save_button->Name = L"Save_button";
			this->Save_button->Size = System::Drawing::Size(100, 23);
			this->Save_button->TabIndex = 1;
			this->Save_button->Text = L"Save";
			this->Save_button->UseVisualStyleBackColor = false;
			this->Save_button->Click += gcnew System::EventHandler(this, &Subjects_manager::Save_button_Click);
			// 
			// Back_from_cred_button
			//
			this->Back_from_Submgmt_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
			this->Back_from_Submgmt_button->BackColor = System::Drawing::Color::Lavender;
			this->Back_from_Submgmt_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Back_from_Submgmt_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Back_from_Submgmt_button->Location = System::Drawing::Point(5, 61);
			this->Back_from_Submgmt_button->Name = L"Back_button";
			this->Back_from_Submgmt_button->Size = System::Drawing::Size(101, 23);
			this->Back_from_Submgmt_button->TabIndex = 1;
			this->Back_from_Submgmt_button->Text = L"Back";
			this->Back_from_Submgmt_button->UseVisualStyleBackColor = false;
			this->Back_from_Submgmt_button->Click += gcnew System::EventHandler(this, &Subjects_manager::back_to_homepage);

			// 
			// Sr_header
			// 
			this->Sr_header->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
			this->Sr_header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Sr_header->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Sr_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Sr_header->Location = System::Drawing::Point(5, 93);
			this->Sr_header->Name = L"Sr_l_h";
			this->Sr_header->Size = System::Drawing::Size(35, 25);
			this->Sr_header->TabIndex = 2;
			this->Sr_header->Text = L"Sr.";
			this->Sr_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			//
			// Course_code_header
			// 
			this->Course_code_header->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
			this->Course_code_header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Course_code_header->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Course_code_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Course_code_header->Location = System::Drawing::Point(45, 93);
			this->Course_code_header->Name = L"Course_code_h";
			this->Course_code_header->Size = System::Drawing::Size(250, 25);
			this->Course_code_header->TabIndex = 3;
			this->Course_code_header->Text = L"Course code";
			this->Course_code_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			//
			// Subject_header
			// 
			this->Subject_header->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
			this->Subject_header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Subject_header->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Subject_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Subject_header->Location = System::Drawing::Point(300, 93);
			this->Subject_header->Name = L"Subject_h";
			this->Subject_header->Size = System::Drawing::Size(250, 25);
			this->Subject_header->TabIndex = 4;
			this->Subject_header->Text = L"Subject";
			this->Subject_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			
			// 
			// Serial labels
			// 
			int y_pos = 124, inc = 31, tab_index = 5;
			for (int i = 0; i < Max_Subjects; i++) {
				this->Sr_l[i]->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
				this->Sr_l[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Sr_l[i]->Location = System::Drawing::Point(5, y_pos);
				this->Sr_l[i]->Name = std_to_System_string("Sr_" + std::to_string(i + 1));
				this->Sr_l[i]->Size = System::Drawing::Size(35, 25);
				this->Sr_l[i]->TabIndex = tab_index;
				this->Sr_l[i]->Text = std_to_System_string(std::to_string(i + 1) + ')');
				this->Sr_l[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				y_pos += inc;
				tab_index += 3;
			}
			//
			// Course code
			//
			y_pos = 124, inc = 31, tab_index = 6;
			for (int i = 0; i < Max_Subjects; i++) {
				this->Course_code[i]->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
				this->Course_code[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				this->Course_code[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Course_code[i]->Location = System::Drawing::Point(this->Sr_l[i]->Left + this->Sr_l[i]->Width + 5, y_pos);
				this->Course_code[i]->Name = std_to_System_string("Course_code_no" + std::to_string(i + 1));
				this->Course_code[i]->Size = System::Drawing::Size(250, 25);
				this->Course_code[i]->TabIndex = tab_index;
				this->Course_code[i]->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
				y_pos += inc;
				tab_index += 3;
			}
			//
			// Subject name 
			//
			y_pos = 124, inc = 31, tab_index = 7;
			for (int i = 0; i < Max_Subjects; i++) {
				this->Subjects[i]->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
				this->Subjects[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				this->Subjects[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Subjects[i]->Location = System::Drawing::Point(this->Course_code[i]->Left + this->Course_code[i]->Width + 5, y_pos);
				this->Subjects[i]->Name = std_to_System_string("Subject_" + std::to_string(i + 1));
				this->Subjects[i]->Size = System::Drawing::Size(250, 25);
				this->Subjects[i]->TabIndex = tab_index;
				this->Subjects[i]->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
				y_pos += inc;
				tab_index += 3;
			}
			
			// 
			// Subjects_manager
			// 
			this->AutoScroll = true;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight; 
			this->ClientSize = System::Drawing::Size(560, 450);
			
			this->Controls->Add(this->Subject_mgmt_header);
			
			this->Controls->Add(this->Save_button);
			this->Controls->Add(this->Back_from_Submgmt_button);
			
			this->Controls->Add(this->Sr_header);
			this->Controls->Add(this->Course_code_header);
			this->Controls->Add(this->Subject_header);

			for (int i = 0; i < Max_Subjects; i++) {
				this->Controls->Add(this->Sr_l[i]);
				this->Controls->Add(this->Course_code[i]);
				this->Controls->Add(this->Subjects[i]);
			}

			this->Name = L"Subjects_manager";
			this->Text = L"Subjects Manager";
			this->Load += gcnew System::EventHandler(this, &Subjects_manager::Subjects_manager_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Subjects_manager_Load(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < Max_Subjects; i++) {
			this->Course_code[i]->Text = std_to_System_string(subjects_details[curr_sec][i].course_code);
			this->Subjects[i]->Text = std_to_System_string(subjects_details[curr_sec][i].name);
		}
	}
	private: System::Void Save_button_Click(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < Max_Subjects; i++) {
			subjects_details[curr_sec][i].course_code = System_to_std_string(this->Course_code[i]->Text);
			subjects_details[curr_sec][i].name = System_to_std_string(this->Subjects[i]->Text);
			//subjects_details[curr_sec][i].teach_no = i;
		}

		for (int i = 0; i < saved.sections; i++) {
			std::ofstream sub_file(Subject_Folder + "Sec_" + Sec_list[i] + ".txt");
			WriteSubjects(sub_file, subjects_details[i], sizeof(subjects_details) / sizeof(*subjects_details), Max_Subjects);
		}
	}
	private: System::Void back_to_homepage(System::Object^ sender, System::EventArgs^ e) {
	
	}
	};
}
