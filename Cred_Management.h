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
	/// Summary for Student_management
	/// </summary>
	public ref class Cred_Management : public System::Windows::Forms::Form
	{
	public:
		Cred_Management(void)
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
		~Cred_Management()
		{
			if (components)
			{
				//delete components;
			}
		}

	protected:
	protected:
	protected:


	private: array<Label^>^ Sr_l = gcnew array<Label^>(Max_size[mode]);
	private: array<TextBox^>^ Name_tb = gcnew array<TextBox^>(Max_size[mode]);
	private: array<TextBox^>^ Email_tb = gcnew array<TextBox^>(Max_size[mode]);
	private: array<TextBox^>^ Pass_tb = gcnew array<TextBox^>(Max_size[mode]);

	private: System::Windows::Forms::Label^ Mgmt_header;
	private: System::Windows::Forms::Button^ Save_button;
	private: System::Windows::Forms::Button^ Back_button;

	private: System::Windows::Forms::Label^ Sr_header;
	private: System::Windows::Forms::Label^ Name_header;
	private: System::Windows::Forms::Label^ Email_header;
	private: System::Windows::Forms::Label^ Pass_header;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		/// 
		void InitializeComponent(void)
		{
			this->Mgmt_header = (gcnew System::Windows::Forms::Label());
			this->Save_button = (gcnew System::Windows::Forms::Button());
			this->Back_button = (gcnew System::Windows::Forms::Button());

			this->Sr_header = (gcnew System::Windows::Forms::Label());
			this->Name_header = (gcnew System::Windows::Forms::Label());
			this->Email_header = (gcnew System::Windows::Forms::Label());
			this->Pass_header = (gcnew System::Windows::Forms::Label());

			for (int i = 0; i < Max_size[mode]; i++) {
				Sr_l[i] = gcnew Label();
				Name_tb[i] = gcnew TextBox();
				Email_tb[i] = gcnew TextBox();
				Pass_tb[i] = gcnew TextBox();
			}

			this->SuspendLayout();
			// 
			// Mgmt_header
			// 
			this->Mgmt_header->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Mgmt_header->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->Mgmt_header->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Mgmt_header->Location = System::Drawing::Point(247, 20);
			this->Mgmt_header->Name = L"Mgmt_header";
			this->Mgmt_header->Size = System::Drawing::Size(195, 31);
			this->Mgmt_header->TabIndex = 0;
			if (mode == STU_mode)
				this->Mgmt_header->Text = L"Student Details";
			else if (mode == TEACH_mode)
				this->Mgmt_header->Text = L"Teach Details";
			// 
			// Save_button
			//
			this->Save_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Right | System::Windows::Forms::AnchorStyles::Top);
			this->Save_button->BackColor = System::Drawing::Color::Lavender;
			this->Save_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Save_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Save_button->Location = System::Drawing::Point(542, 61);
			this->Save_button->Name = L"Save_button";
			this->Save_button->Size = System::Drawing::Size(101, 23);
			this->Save_button->TabIndex = 1;
			this->Save_button->Text = L"Save";
			this->Save_button->UseVisualStyleBackColor = false;
			this->Save_button->Click += gcnew System::EventHandler(this, &Cred_Management::Save_button_Click);
			// 
			// Back_button
			//
			this->Back_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
			this->Back_button->BackColor = System::Drawing::Color::Lavender;
			this->Back_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Back_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Back_button->Location = System::Drawing::Point(5, 61);
			this->Back_button->Name = L"Back_button";
			this->Back_button->Size = System::Drawing::Size(101, 23);
			this->Back_button->TabIndex = 1;
			this->Back_button->Text = L"Back";
			this->Back_button->UseVisualStyleBackColor = false;
			this->Back_button->Click += gcnew System::EventHandler(this, &Cred_Management::Back_button_Click);
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
			// Name_header
			// 
			this->Name_header->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
			this->Name_header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Name_header->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Name_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name_header->Location = System::Drawing::Point(45, 93);
			this->Name_header->Name = L"Name_h";
			this->Name_header->Size = System::Drawing::Size(200, 25);
			this->Name_header->TabIndex = 4;
			if (mode == STU_mode)
				this->Name_header->Text = L"Student Name";
			else if (mode == TEACH_mode)
				this->Name_header->Text = L"Teacher Name";
			this->Name_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			// 
			// Email_header
			// 
			this->Email_header->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right);
			this->Email_header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Email_header->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Email_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Email_header->Location = System::Drawing::Point(250, 93);
			this->Email_header->Name = L"Email_h";
			this->Email_header->Size = System::Drawing::Size(200, 25);
			this->Email_header->TabIndex = 5;
			this->Email_header->Text = L"Email";
			this->Email_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Pass_header
			// 
			this->Pass_header->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right);
			this->Pass_header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Pass_header->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Pass_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Pass_header->Location = System::Drawing::Point(455, 93);
			this->Pass_header->Name = L"Pass_h";
			this->Pass_header->Size = System::Drawing::Size(200, 25);
			this->Pass_header->TabIndex = 6;
			this->Pass_header->Text = L"Password";
			this->Pass_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			// 
			// Serial labels
			// 
			int y_pos = 124, tab_index = 9;
			for (int i = 0; i < Max_size[mode]; i++) {
				Sr_l[i]->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
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
			// Student name 
			//
			y_pos = 124, tab_index = 93;
			for (int i = 0; i < Max_size[mode]; i++) {
				Name_tb[i]->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
				Name_tb[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				Name_tb[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				Name_tb[i]->Location = System::Drawing::Point(45, y_pos);
				Name_tb[i]->Name = std_to_System_string("Name_" + std::to_string(i + 1));
				Name_tb[i]->Size = System::Drawing::Size(200, 25);
				Name_tb[i]->TabIndex = tab_index;
				Name_tb[i]->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
				y_pos += 31;
				if (tab_index == 3) tab_index += 8;
				else tab_index += 4;
			}
			//
			// Email
			//
			y_pos = 124, tab_index = 7;
			for (int i = 0; i < Max_size[mode]; i++) {
				Email_tb[i]->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Right | System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left);
				Email_tb[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				Email_tb[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				Email_tb[i]->Location = System::Drawing::Point(250, y_pos);
				Email_tb[i]->Name = std_to_System_string("Name_" + std::to_string(i + 1));
				Email_tb[i]->Size = System::Drawing::Size(200, 25);
				Email_tb[i]->TabIndex = tab_index;
				Email_tb[i]->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
				y_pos += 31;
				if (tab_index == 7) tab_index += 8;
				else tab_index += 4;
			}


			y_pos = 124, tab_index = 8;
			for (int i = 0; i < Max_size[mode]; i++) {
				Pass_tb[i]->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Right | System::Windows::Forms::AnchorStyles::Top);
				Pass_tb[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				Pass_tb[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				Pass_tb[i]->Location = System::Drawing::Point(455, y_pos);
				Pass_tb[i]->Name = std_to_System_string("Pass_" + std::to_string(i + 1));
				Pass_tb[i]->Size = System::Drawing::Size(200, 25);
				Pass_tb[i]->TabIndex = tab_index;
				Pass_tb[i]->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
				y_pos += 31;
				if (tab_index == 8) tab_index += 8;
				else tab_index += 4;
			}

			// 
			// Credential_management
			// 
			this->AutoScroll = true;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(655, 313);
			for (int i = 0; i < Max_size[mode]; i++) {
				this->Controls->Add(this->Sr_l[i]);
				this->Controls->Add(this->Name_tb[i]);
				this->Controls->Add(this->Email_tb[i]);
				this->Controls->Add(this->Pass_tb[i]);
			}
			this->Controls->Add(this->Sr_header);
			this->Controls->Add(this->Name_header);
			this->Controls->Add(this->Email_header);
			this->Controls->Add(this->Pass_header);
			this->Controls->Add(this->Save_button);
			this->Controls->Add(this->Back_button);
			this->Controls->Add(this->Mgmt_header);
			if (mode == STU_mode) {
				this->Name = L"Student_management";
				this->Text = L"Student management";
			}
			else if (mode == TEACH_mode) {
				this->Name = L"Teacher_management";
				this->Text = L"Teacher management";
			}
			this->Load += gcnew System::EventHandler(this, &Cred_Management::Student_management_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Student_management_Load(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < Max_size[mode]; i++) {
			credentials tmp;
			if (mode == STU_mode)
				tmp = Stu_Cred[curr_sec][i];
			else if (mode == TEACH_mode)
				tmp = Teach_Cred[i];

			Name_tb[i]->Text = std_to_System_string(tmp.name);
			Email_tb[i]->Text = std_to_System_string(tmp.username);
			Pass_tb[i]->Text = std_to_System_string(tmp.pass);
		}
	}
	private: System::Void Save_button_Click(System::Object^ sender, System::EventArgs^ e) {

		for (int i = 0; i < Max_size[mode]; i++) {

			if (mode == STU_mode) {
				Stu_Cred[curr_sec][i].name = System_to_std_string(Name_tb[i]->Text);
				Stu_Cred[curr_sec][i].username = System_to_std_string(Email_tb[i]->Text);
				Stu_Cred[curr_sec][i].pass = System_to_std_string(Pass_tb[i]->Text);
			}
			else if (mode == TEACH_mode) {
				Teach_Cred[i].name = System_to_std_string(Name_tb[i]->Text);
				Teach_Cred[i].username = System_to_std_string(Email_tb[i]->Text);
				Teach_Cred[i].pass = System_to_std_string(Pass_tb[i]->Text);
			}
		}

		if (mode == STU_mode) {
			for ( int i = 0; i < saved.sections; i++){
				std::ofstream stu(Student_Cred_Folder + "Sec_" + Sec_list[i] + ".txt");
				
				WriteCredentials(stu, Stu_Cred[i], sizeof(Stu_Cred[i]) / sizeof(*Stu_Cred[i]));
				stu.close();
			}
		}
		else if (mode == TEACH_mode) {
			std::ofstream Teach(Teacher_Cred_File);
			WriteCredentials(Teach, Teach_Cred, sizeof(Teach_Cred) / sizeof(*Teach_Cred));
			Teach.close();
		}

		MessageBox::Show("Credentials Updated Successfully !");
		/*
		// The issue 
			// error C2065: 'Admin_homepage': undeclared identifier
			this->Hide();
			Admin_homepage obj;
			obj.ShowDialog();
			this->Close();
		*/

	}
	private: System::Void Back_button_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}

