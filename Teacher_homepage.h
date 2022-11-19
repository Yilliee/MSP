#pragma once
#include "variables.h"	
#include "functions.h"
#include "Sec_selector.h"
#include "Attendance_layout.h"

namespace MSP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Teacher_homepage
	/// </summary>
	public ref class Teacher_homepage : public System::Windows::Forms::Form
	{
	public:
		Teacher_homepage(void)
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
		~Teacher_homepage()
		{
			if (components)
			{
				delete components;
			}
		}

	
	// Teacher_homepage
	private: System::Windows::Forms::Label^ Teacher_hp_header;
	private: System::Windows::Forms::Button^ Manage_marks_button;
	private: System::Windows::Forms::Button^ Manage_attendance_button;
	private: System::Windows::Forms::Button^ Logout_button;
	// Teacher_homepage - end
	
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
		void InitializeComponent(void)
		{
			this->Teacher_hp_header = (gcnew System::Windows::Forms::Label());
			this->Manage_marks_button = (gcnew System::Windows::Forms::Button());
			this->Manage_attendance_button = (gcnew System::Windows::Forms::Button());
			this->Logout_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Teacher_hp_header
			// 
			this->Teacher_hp_header->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Teacher_hp_header->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Teacher_hp_header->Location = System::Drawing::Point(12, 9);
			this->Teacher_hp_header->Name = L"Teacher_hp_header";
			this->Teacher_hp_header->Size = System::Drawing::Size(698, 80);
			this->Teacher_hp_header->TabIndex = 0;
			this->Teacher_hp_header->Text = L"Welcome, ";
			this->Teacher_hp_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Manage_marks_button
			// 
			this->Manage_marks_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Manage_marks_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Manage_marks_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Manage_marks_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Manage_marks_button->Location = System::Drawing::Point(261, 150);
			this->Manage_marks_button->Name = L"Manage_marks_button";
			this->Manage_marks_button->Size = System::Drawing::Size(200, 31);
			this->Manage_marks_button->TabIndex = 1;
			this->Manage_marks_button->Text = L"Manage Marks";
			this->Manage_marks_button->UseVisualStyleBackColor = false;
			this->Manage_marks_button->Click += gcnew System::EventHandler(this, &Teacher_homepage::Manage_marks_button_Click);
			// 
			// Manage_attendance_button
			// 
			this->Manage_attendance_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Manage_attendance_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Manage_attendance_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Manage_attendance_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Manage_attendance_button->Location = System::Drawing::Point(261, 250);
			this->Manage_attendance_button->Name = L"Manage_attendance_button";
			this->Manage_attendance_button->Size = System::Drawing::Size(200, 31);
			this->Manage_attendance_button->TabIndex = 1;
			this->Manage_attendance_button->Text = L"Manage Attendance";
			this->Manage_attendance_button->UseVisualStyleBackColor = false;
			this->Manage_attendance_button->Click += gcnew System::EventHandler(this, &Teacher_homepage::Manage_attendance_button_Click);
			// 
			// Logout_button
			// 
			this->Logout_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Logout_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Logout_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Logout_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Logout_button->Location = System::Drawing::Point(261, 350);
			this->Logout_button->Name = L"Logout_button";
			this->Logout_button->Size = System::Drawing::Size(200, 31);
			this->Logout_button->TabIndex = 4;
			this->Logout_button->Text = L"Logout";
			this->Logout_button->UseVisualStyleBackColor = false;
			this->Logout_button->Click += gcnew System::EventHandler(this, &Teacher_homepage::Logout_button_Click);
			// 
			// Teacher_homepage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(722, 450);
			this->Controls->Add(this->Manage_attendance_button);
			this->Controls->Add(this->Manage_marks_button);
			this->Controls->Add(this->Teacher_hp_header);
			this->Controls->Add(this->Logout_button);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::SystemColors::Desktop;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Teacher_homepage";
			this->Text = L"Teacher_homepage";
			this->Load += gcnew System::EventHandler(this, &Teacher_homepage::Teacher_hp_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Teacher_hp_Load(System::Object^ sender, System::EventArgs^ e) {
		this->Teacher_hp_header->Text += std_to_System_string(Teach_Cred[teach_no].name + "!");
		//tmp
		curr_subject = teach_no;
	}
	private: System::Void Manage_marks_button_Click(System::Object^ sender, System::EventArgs^ e) {
		Sec_selector sec_sel;
		this->Hide();
		sec_sel.ShowDialog();
		this->Close();
	}
	private: System::Void Manage_attendance_button_Click(System::Object^ sender, System::EventArgs^ e) {
		Attendance_layout att;
		this->Hide();
		att.ShowDialog();
		this->Close();
	}
	private: System::Void Logout_button_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
