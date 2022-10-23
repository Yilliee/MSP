#pragma once
#include "variables.h"
#include "functions.h"
#include "Cred_Management.h"

namespace MSP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Admin_homepage
	/// </summary>
	public ref class Admin_homepage : public System::Windows::Forms::Form
	{
	public:
		Admin_homepage(void)
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
		~Admin_homepage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Admin_hp_header;
	private: System::Windows::Forms::Button^ Stu_button;
	private: System::Windows::Forms::Button^ Teach_button;
	private: System::Windows::Forms::Button^ Sub_button;
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
			this->Admin_hp_header = (gcnew System::Windows::Forms::Label());
			this->Stu_button = (gcnew System::Windows::Forms::Button());
			this->Teach_button = (gcnew System::Windows::Forms::Button());
			this->Sub_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Admin_hp_header
			// 
			this->Admin_hp_header->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Admin_hp_header->AutoSize = true;
			this->Admin_hp_header->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Admin_hp_header->Location = System::Drawing::Point(219, 39);
			this->Admin_hp_header->Name = L"Admin_hp_header";
			this->Admin_hp_header->Size = System::Drawing::Size(135, 31);
			this->Admin_hp_header->TabIndex = 0;
			this->Admin_hp_header->Text = L"Welcome, ";
			// 
			// Stu_button
			// 
			this->Stu_button->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Stu_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Stu_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Stu_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Stu_button->Location = System::Drawing::Point(240, 137);
			this->Stu_button->Name = L"Stu_button";
			this->Stu_button->Size = System::Drawing::Size(229, 31);
			this->Stu_button->TabIndex = 1;
			this->Stu_button->Text = L"Manage Students";
			this->Stu_button->UseVisualStyleBackColor = false;
			this->Stu_button->Click += gcnew System::EventHandler(this, &Admin_homepage::Stu_button_Click);
			// 
			// Teach_button
			// 
			this->Teach_button->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Teach_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Teach_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Teach_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Teach_button->Location = System::Drawing::Point(240, 191);
			this->Teach_button->Name = L"Teach_button";
			this->Teach_button->Size = System::Drawing::Size(229, 31);
			this->Teach_button->TabIndex = 2;
			this->Teach_button->Text = L"Manage Teachers";
			this->Teach_button->UseVisualStyleBackColor = false;
			this->Teach_button->Click += gcnew System::EventHandler(this, &Admin_homepage::Teach_button_Click);
			// 
			// Sub_button
			// 
			this->Sub_button->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Sub_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Sub_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Sub_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Sub_button->Location = System::Drawing::Point(240, 247);
			this->Sub_button->Name = L"Sub_button";
			this->Sub_button->Size = System::Drawing::Size(229, 31);
			this->Sub_button->TabIndex = 3;
			this->Sub_button->Text = L"Manage Subjects";
			this->Sub_button->UseVisualStyleBackColor = false;
			// 
			// Admin_homepage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(719, 363);
			this->Controls->Add(this->Sub_button);
			this->Controls->Add(this->Teach_button);
			this->Controls->Add(this->Stu_button);
			this->Controls->Add(this->Admin_hp_header);
			this->Name = L"Admin_homepage";
			this->Text = L"Admin_homepage";
			this->Load += gcnew System::EventHandler(this, &Admin_homepage::Admin_homepage_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Admin_homepage_Load(System::Object^ sender, System::EventArgs^ e) {
		Admin_hp_header->Text = Admin_hp_header->Text + std_to_System_string(Admin_Cred[admin_no].name + '!');
	}
	private: System::Void Stu_button_Click(System::Object^ sender, System::EventArgs^ e) {
		mode = STU_mode; // Student
		open_cred_winform();
	}
	private: System::Void Teach_button_Click(System::Object^ sender, System::EventArgs^ e) {
		mode = TEACH_mode;
		open_cred_winform();
	}
	private: System::Void open_cred_winform(Void) {
		Cred_Management cred_mg_winfrom;
		this->Hide();
		cred_mg_winfrom.ShowDialog();
		this->Close();
	}
};
}
