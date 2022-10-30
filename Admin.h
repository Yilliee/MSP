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
	/// Summary for Admin
	/// </summary>
	public ref class Admin : public System::Windows::Forms::Form
	{
	public:
		Admin(void)
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
		~Admin()
		{
			if (components)
			{
				delete components;
			}
		}
	// Admin_homepage
	private: System::Windows::Forms::Label^ Admin_hp_header;
	private: System::Windows::Forms::Button^ Stu_button;
	private: System::Windows::Forms::Button^ Teach_button;
	private: System::Windows::Forms::Button^ Sub_button;
	private: System::Windows::Forms::Button^ Logout_button;
	// Admin_homepage - end
	
	// Section_manager
	private: System::Windows::Forms::Label^ Section_manager_header;
	private: System::Windows::Forms::Button^ Sec_del_button;
	private: System::Windows::Forms::Button^ New_Sec_button;
	private: System::Windows::Forms::Button^ Back_from_Sec_button;
	private: int new_sec_button_y = 121 + 31 * (saved.sections - 1);
	private: array<Button^>^ Section = gcnew array<Button^>(Max_Sections);
	// Section_manager - end

	// Credentials_manager
	private: array<Label^>^ Sr_l = gcnew array<Label^>(Absolute_Max_sizes[mode]);
	private: array<TextBox^>^ ID_tb = gcnew array<TextBox^>(Absolute_Max_sizes[mode]);
	private: array<TextBox^>^ Name_tb = gcnew array<TextBox^>(Absolute_Max_sizes[mode]);
	private: array<TextBox^>^ Email_tb = gcnew array<TextBox^>(Absolute_Max_sizes[mode]);
	private: array<TextBox^>^ Pass_tb = gcnew array<TextBox^>(Absolute_Max_sizes[mode]);

	private: System::Windows::Forms::Label^ Mgmt_header;
	private: System::Windows::Forms::Button^ Save_button;
	private: System::Windows::Forms::Button^ Back_from_Cred_button;

	private: System::Windows::Forms::Label^ Sr_header;
	private: System::Windows::Forms::Label^ ID_header;
	private: System::Windows::Forms::Label^ Name_header;
	private: System::Windows::Forms::Label^ Email_header;
	private: System::Windows::Forms::Label^ Pass_header;
	// Credentials_manager - end

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		// Section_manager
		void load_buttons(int sec) {
			for (int i = 0; i < Max_Sections; i++) {
				if (sec > i) this->Section[i]->Visible = true;
				else this->Section[i]->Visible = false;

				if (sec == 1) this->Sec_del_button->Visible = false;
				else this->Sec_del_button->Visible = true;

				if (sec == Max_Sections) this->New_Sec_button->Visible = false;
				else this->New_Sec_button->Visible = true;

			}


		}
		// Section_manager - end

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void) // Admin_homepage
		{
			this->Admin_hp_header = (gcnew System::Windows::Forms::Label());
			this->Stu_button = (gcnew System::Windows::Forms::Button());
			this->Teach_button = (gcnew System::Windows::Forms::Button());
			this->Sub_button = (gcnew System::Windows::Forms::Button());
			this->Logout_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Admin_hp_header
			// 
			this->Admin_hp_header->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Admin_hp_header->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Admin_hp_header->Location = System::Drawing::Point(9, 39);
			this->Admin_hp_header->Name = L"Admin_hp_header";
			this->Admin_hp_header->Size = System::Drawing::Size(701, 31);
			this->Admin_hp_header->TabIndex = 0;
			this->Admin_hp_header->Text = L"Welcome, ";
			this->Admin_hp_header->Text += std_to_System_string(Admin_Cred[admin_no].name + "!");
			this->Admin_hp_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Stu_button
			// 
			this->Stu_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Stu_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Stu_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Stu_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Stu_button->Location = System::Drawing::Point(248, 137);
			this->Stu_button->Name = L"Stu_button";
			this->Stu_button->Size = System::Drawing::Size(229, 31);
			this->Stu_button->TabIndex = 1;
			this->Stu_button->Text = L"Manage Students";
			this->Stu_button->UseVisualStyleBackColor = false;
			this->Stu_button->Click += gcnew System::EventHandler(this, &Admin::Stu_button_Click);
			// 
			// Teach_button
			// 
			this->Teach_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Teach_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Teach_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Teach_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Teach_button->Location = System::Drawing::Point(248, 191);
			this->Teach_button->Name = L"Teach_button";
			this->Teach_button->Size = System::Drawing::Size(229, 31);
			this->Teach_button->TabIndex = 2;
			this->Teach_button->Text = L"Manage Teachers";
			this->Teach_button->UseVisualStyleBackColor = false;
			this->Teach_button->Click += gcnew System::EventHandler(this, &Admin::Teach_button_Click);
			// 
			// Sub_button
			// 
			this->Sub_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Sub_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Sub_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Sub_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Sub_button->Location = System::Drawing::Point(248, 247);
			this->Sub_button->Name = L"Sub_button";
			this->Sub_button->Size = System::Drawing::Size(229, 31);
			this->Sub_button->TabIndex = 3;
			this->Sub_button->Text = L"Manage Subjects";
			this->Sub_button->UseVisualStyleBackColor = false;
			// 
			// Logout_button
			// 
			this->Logout_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Logout_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Logout_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Logout_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Logout_button->Location = System::Drawing::Point(248, 303);
			this->Logout_button->Name = L"Logout_button";
			this->Logout_button->Size = System::Drawing::Size(229, 31);
			this->Logout_button->TabIndex = 4;
			this->Logout_button->Text = L"Logout";
			this->Logout_button->UseVisualStyleBackColor = false;
			this->Logout_button->Click += gcnew System::EventHandler(this, &Admin::Logout_button_Click);
			// 
			// Admin
			// 
			this->AutoScroll = true;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(719, 363);
			this->Controls->Add(this->Logout_button);
			this->Controls->Add(this->Sub_button);
			this->Controls->Add(this->Teach_button);
			this->Controls->Add(this->Stu_button);
			this->Controls->Add(this->Admin_hp_header);
			this->Name = L"Admin";
			this->Text = L"Admin";
			this->Load += gcnew System::EventHandler(this, &Admin::Admin_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		} // Admin_homepage - end

		void Remove_Components_homepage(void) { // Remove_components_homepage
			this->Controls->Remove(this->Sub_button);
			this->Controls->Remove(this->Teach_button);
			this->Controls->Remove(this->Stu_button);
			this->Controls->Remove(this->Admin_hp_header);
			this->Controls->Remove(this->Logout_button);
		} // Remove_components_homepage - end

		// Section_manager
		// InitializeComponent_Section_manager
		void InitializeComponent_Section_manager(void)
		{
			this->Section_manager_header = (gcnew System::Windows::Forms::Label());
			this->Sec_del_button = (gcnew System::Windows::Forms::Button());
			this->New_Sec_button = (gcnew System::Windows::Forms::Button());
			this->Back_from_Sec_button = (gcnew System::Windows::Forms::Button());

			for (int i = 0; i < Max_Sections; i++) {
				this->Section[i] = (gcnew System::Windows::Forms::Button());
			}

			this->SuspendLayout();
			// 
			// Section_manager_header
			// 
			this->Section_manager_header->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Section_manager_header->AutoSize = true;
			this->Section_manager_header->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Section_manager_header->Location = System::Drawing::Point(223, 35);
			this->Section_manager_header->Name = L"Section_manager_header";
			this->Section_manager_header->Size = System::Drawing::Size(200, 31);
			this->Section_manager_header->TabIndex = 0;
			this->Section_manager_header->Text = L"Select a section:";
			// 
			// Section_Array
			// 
			int y_pos = 90;
			for (int i = 0; i < Max_Sections; i++) {
				this->Section[i]->Anchor = System::Windows::Forms::AnchorStyles::Top; //static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Top);// | System::Windows::Forms::AnchorStyles::Right | System::Windows::Forms::AnchorStyles::Left);
				this->Section[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				this->Section[i]->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				this->Section[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Section[i]->Location = System::Drawing::Point(225, y_pos);
				this->Section[i]->Name = std_to_System_string(System_to_std_string("Sec ") + Sec_list[i] + "_button");
				this->Section[i]->Size = System::Drawing::Size(200, 25);
				this->Section[i]->TabIndex = 1;
				this->Section[i]->Text = std_to_System_string(System_to_std_string("Section ") + Sec_list[i]);
				this->Section[i]->UseVisualStyleBackColor = false;
				y_pos += 35;
			}

			this->Section[0]->Click += gcnew System::EventHandler(this, &Admin::Select_Section_A);
			this->Section[1]->Click += gcnew System::EventHandler(this, &Admin::Select_Section_B);
			this->Section[2]->Click += gcnew System::EventHandler(this, &Admin::Select_Section_C);
			this->Section[3]->Click += gcnew System::EventHandler(this, &Admin::Select_Section_D);
			this->Section[4]->Click += gcnew System::EventHandler(this, &Admin::Select_Section_E);
			this->Section[5]->Click += gcnew System::EventHandler(this, &Admin::Select_Section_F);
			this->Section[6]->Click += gcnew System::EventHandler(this, &Admin::Select_Section_G);
			this->Section[7]->Click += gcnew System::EventHandler(this, &Admin::Select_Section_H);
			this->Section[8]->Click += gcnew System::EventHandler(this, &Admin::Select_Section_I);
			this->Section[9]->Click += gcnew System::EventHandler(this, &Admin::Select_Section_J);

			// 
			// Sec_del_button
			// 
			this->Sec_del_button->Anchor = System::Windows::Forms::AnchorStyles::Top; //static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Top);// | System::Windows::Forms::AnchorStyles::Right | System::Windows::Forms::AnchorStyles::Left);
			this->Sec_del_button->BackColor = System::Drawing::Color::Red;
			this->Sec_del_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Sec_del_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Sec_del_button->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->Sec_del_button->Location = System::Drawing::Point(Section[saved.sections - 1]->Left + (Section[saved.sections - 1]->Width-25), Section[saved.sections - 1]->Top);
			this->Sec_del_button->Name = L"Sec_J_del";
			this->Sec_del_button->Size = System::Drawing::Size(25, 25);
			this->Sec_del_button->TabIndex = 11;
			this->Sec_del_button->Text = L"X";
			this->Sec_del_button->UseVisualStyleBackColor = false;
			this->Sec_del_button->Visible = false;
			this->Sec_del_button->Click += gcnew System::EventHandler(this, &Admin::Delete_a_Section);
			
			// 
			// New_Sec_button
			//
			this->New_Sec_button->Anchor = System::Windows::Forms::AnchorStyles::Top; //static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Top);// | System::Windows::Forms::AnchorStyles::Right | System::Windows::Forms::AnchorStyles::Left);
			this->New_Sec_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->New_Sec_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->New_Sec_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->New_Sec_button->Location = System::Drawing::Point(Section[saved.sections - 1]->Left, Sec_del_button->Top+35);
			this->New_Sec_button->Name = L"New_Sec_button";
			this->New_Sec_button->Size = System::Drawing::Size(200, 25);
			this->New_Sec_button->TabIndex = 12;
			this->New_Sec_button->Text = L"Create a New Section";
			this->New_Sec_button->UseVisualStyleBackColor = false;
			this->New_Sec_button->Visible = true;
			this->New_Sec_button->Click += gcnew System::EventHandler(this, &Admin::Create_New_Section);
			
			// 
			// Back_to_home_button
			// 
			this->Back_from_Sec_button->Anchor = System::Windows::Forms::AnchorStyles::Top;//static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Top);// | System::Windows::Forms::AnchorStyles::Right | System::Windows::Forms::AnchorStyles::Left);
			this->Back_from_Sec_button->BackColor = System::Drawing::Color::Lavender;
			this->Back_from_Sec_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Back_from_Sec_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Back_from_Sec_button->Location = System::Drawing::Point(New_Sec_button->Left, New_Sec_button->Top + 35);
			if (saved.sections == Max_Sections)
				this->Back_from_Sec_button->Top -= 35;
			this->Back_from_Sec_button->Name = L"Back_to_home_del";
			this->Back_from_Sec_button->Size = System::Drawing::Size(200, 25);
			this->Back_from_Sec_button->Text = L"Go Back to home";
			this->Back_from_Sec_button->UseVisualStyleBackColor = false;
			this->Back_from_Sec_button->Visible = true;
			this->Back_from_Sec_button->Click += gcnew System::EventHandler(this, &Admin::back_to_homepage);

			// 
			// Section_manager
			// 
			//this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			//this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(684, 412);
			this->Controls->Add(this->Section_manager_header);
			this->Controls->Add(this->New_Sec_button);
			this->Controls->Add(this->Sec_del_button);
			this->Controls->Add(this->Back_from_Sec_button);
			for (int i = 0; i < Max_Sections; i++)
				this->Controls->Add(this->Section[i]);

			this->Name = L"Section_manager";
			this->Text = L"Section Management";
			load_buttons(saved.sections);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		// InitializeComponent_Section_manager - end

		// Remove_Components_Section_manager
		void Remove_Components_Section_manager(void) {
			this->Controls->Remove(this->Section_manager_header);
			this->Controls->Remove(this->New_Sec_button);
			this->Controls->Remove(this->Sec_del_button);
			this->Controls->Remove(this->Back_from_Sec_button);

			for (int i = 0; i < Max_Sections; i++)
				this->Controls->Remove(this->Section[i]);
		}
		// Remove_Components_Section_manager - end 

		// InitializeComponent_Crdentials_manager
		void InitializeComponent_Crdentials_manager(void)
		{
			this->Mgmt_header = (gcnew System::Windows::Forms::Label());
			this->Save_button = (gcnew System::Windows::Forms::Button());
			this->Back_from_Cred_button = (gcnew System::Windows::Forms::Button());
			
			this->Sr_header = (gcnew System::Windows::Forms::Label());
			this->ID_header = (gcnew System::Windows::Forms::Label());
			this->Name_header = (gcnew System::Windows::Forms::Label());
			this->Email_header = (gcnew System::Windows::Forms::Label());
			this->Pass_header = (gcnew System::Windows::Forms::Label());

			for (int i = 0; i < Absolute_Max_sizes[mode]; i++) {
				Sr_l[i] = gcnew Label();
				ID_tb[i] = gcnew TextBox();
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
			if (mode == STU)
				this->Mgmt_header->Text = L"Student Details";
			else if (mode == TEACH)
				this->Mgmt_header->Text = L"Teach Details";
			// 
			// Save_button
			//
			this->Save_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
			this->Save_button->BackColor = System::Drawing::Color::Lavender;
			this->Save_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Save_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Save_button->Location = System::Drawing::Point(660, 61);
			this->Save_button->Name = L"Save_button";
			this->Save_button->Size = System::Drawing::Size(100, 23);
			this->Save_button->TabIndex = 1;
			this->Save_button->Text = L"Save";
			this->Save_button->UseVisualStyleBackColor = false;
			this->Save_button->Click += gcnew System::EventHandler(this, &Admin::Save_button_Click);
			// 
			// Back_from_cred_button
			//
			this->Back_from_Cred_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
			this->Back_from_Cred_button->BackColor = System::Drawing::Color::Lavender;
			this->Back_from_Cred_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Back_from_Cred_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Back_from_Cred_button->Location = System::Drawing::Point(5, 61);
			this->Back_from_Cred_button->Name = L"Back_button";
			this->Back_from_Cred_button->Size = System::Drawing::Size(101, 23);
			this->Back_from_Cred_button->TabIndex = 1;
			this->Back_from_Cred_button->Text = L"Back";
			this->Back_from_Cred_button->UseVisualStyleBackColor = false;
			if (mode == TEACH)
				this->Back_from_Cred_button->Click += gcnew System::EventHandler(this, &Admin::back_to_homepage);
			else if (mode == STU)
				this->Back_from_Cred_button->Click += gcnew System::EventHandler(this, &Admin::back_to_section_manager);
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
			// ID_header
			// 
			this->ID_header->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
			this->ID_header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ID_header->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->ID_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ID_header->Location = System::Drawing::Point(this->Sr_header->Left + this->Sr_header->Width + 5, this->Sr_header->Top);
			this->ID_header->Name = L"ID_header";
			this->ID_header->Size = System::Drawing::Size(100, 25);
			this->ID_header->TabIndex = 3;
			this->ID_header->Text = L"ID";
			this->ID_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Name_header
			// 
			this->Name_header->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
			this->Name_header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Name_header->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Name_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name_header->Location = System::Drawing::Point(this->ID_header->Left + this->ID_header->Width + 5, this->ID_header->Top);
			this->Name_header->Name = L"Name_h";
			this->Name_header->Size = System::Drawing::Size(200, 25);
			this->Name_header->TabIndex = 4;
			if (mode == STU)
				this->Name_header->Text = L"Student Name";
			else if (mode == TEACH)
				this->Name_header->Text = L"Teacher Name";
			this->Name_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			// 
			// Email_header
			// 
			this->Email_header->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
			this->Email_header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Email_header->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Email_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Email_header->Location = System::Drawing::Point(this->Name_header->Left + this->Name_header->Width + 5, this->Name_header->Top);
			this->Email_header->Name = L"Email_h";
			this->Email_header->Size = System::Drawing::Size(200, 25);
			this->Email_header->TabIndex = 5;
			this->Email_header->Text = L"Email";
			this->Email_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Pass_header
			// 
			this->Pass_header->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left);
			this->Pass_header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Pass_header->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Pass_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Pass_header->Location = System::Drawing::Point(this->Email_header->Left + this->Email_header->Width + 5, 93);
			this->Pass_header->Name = L"Pass_h";
			this->Pass_header->Size = System::Drawing::Size(200, 25);
			this->Pass_header->TabIndex = 6;
			this->Pass_header->Text = L"Password";
			this->Pass_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			// 
			// Serial labels
			// 
			int y_pos = 124, inc = 31, tab_index = 7;
			for (int i = 0; i < Absolute_Max_sizes[mode]; i++) {
				Sr_l[i]->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
				Sr_l[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				Sr_l[i]->Location = System::Drawing::Point(5, y_pos);
				Sr_l[i]->Name = std_to_System_string("Sr_" + std::to_string(i + 1));
				Sr_l[i]->Size = System::Drawing::Size(35, 25);
				Sr_l[i]->TabIndex = tab_index;
				Sr_l[i]->Text = std_to_System_string(std::to_string(i + 1) + ')');
				Sr_l[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				y_pos += inc;
				tab_index += 4;
			}
			//
			// Roll no
			//
			y_pos = 124, inc = 31, tab_index = 8;
			for (int i = 0; i < Absolute_Max_sizes[mode]; i++) {
				ID_tb[i]->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
				ID_tb[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				ID_tb[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				ID_tb[i]->Location = System::Drawing::Point(this->Sr_l[i]->Left + this->Sr_l[i]->Width + 5, y_pos);
				ID_tb[i]->Name = std_to_System_string("Name_" + std::to_string(i + 1));
				ID_tb[i]->Size = System::Drawing::Size(100, 25);
				ID_tb[i]->TabIndex = tab_index;
				ID_tb[i]->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
				y_pos += inc;
				tab_index += 4;
			}
			//
			// Student name 
			//
			y_pos = 124, inc = 31, tab_index = 9;
			for (int i = 0; i < Absolute_Max_sizes[mode]; i++) {
				Name_tb[i]->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
				Name_tb[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				Name_tb[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				Name_tb[i]->Location = System::Drawing::Point(this->ID_tb[i]->Left + this->ID_tb[i]->Width + 5, y_pos);
				Name_tb[i]->Name = std_to_System_string("Name_" + std::to_string(i + 1));
				Name_tb[i]->Size = System::Drawing::Size(200, 25);
				Name_tb[i]->TabIndex = tab_index;
				Name_tb[i]->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
				y_pos += inc;
				tab_index += 4;
			}
			//
			// Email
			//
			y_pos = 124, inc = 31, tab_index = 10;
			for (int i = 0; i < Absolute_Max_sizes[mode]; i++) {
				Email_tb[i]->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left);
				Email_tb[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				Email_tb[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				Email_tb[i]->Location = System::Drawing::Point(this->Name_tb[i]->Left + this->Name_tb[i]->Width + 5, y_pos);
				Email_tb[i]->Name = std_to_System_string("Name_" + std::to_string(i + 1));
				Email_tb[i]->Size = System::Drawing::Size(200, 25);
				Email_tb[i]->TabIndex = tab_index;
				Email_tb[i]->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
				y_pos += inc;
				tab_index += 4;
			}
			//
			// Pass
			//
			y_pos = 124, inc = 31, tab_index = 11;
			for (int i = 0; i < Absolute_Max_sizes[mode]; i++) {
				Pass_tb[i]->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
				Pass_tb[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				Pass_tb[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				Pass_tb[i]->Location = System::Drawing::Point(this->Email_tb[i]->Left + this->Email_tb[i]->Width + 5, y_pos);
				Pass_tb[i]->Name = std_to_System_string("Pass_" + std::to_string(i + 1));
				Pass_tb[i]->Size = System::Drawing::Size(200, 25);
				Pass_tb[i]->TabIndex = tab_index;
				Pass_tb[i]->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
				y_pos += inc;
				tab_index += 4;
			}

			// 
			// Credential_management
			// 
			this->AutoScroll = true;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(780, 450);
			for (int i = 0; i < Absolute_Max_sizes[mode]; i++) {
				this->Controls->Add(this->Sr_l[i]);
				this->Controls->Add(this->ID_tb[i]);
				this->Controls->Add(this->Name_tb[i]);
				this->Controls->Add(this->Email_tb[i]);
				this->Controls->Add(this->Pass_tb[i]);
			}
			this->Controls->Add(this->Sr_header);
			this->Controls->Add(this->ID_header);
			this->Controls->Add(this->Name_header);
			this->Controls->Add(this->Email_header);
			this->Controls->Add(this->Pass_header);
			this->Controls->Add(this->Save_button);
			this->Controls->Add(this->Back_from_Cred_button);
			this->Controls->Add(this->Mgmt_header);
			if (mode == STU) {
				this->Name = L"Student_management";
				this->Text = L"Student management";
			}
			else if (mode == TEACH) {
				this->Name = L"Teacher_management";
				this->Text = L"Teacher management";
			}
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		// InitializeComponent_Crdentials_manager - end

		void Remove_Components_Credentials_manager(void) { // Remove_Components_Credentials_manager
			for (int i = 0; i < Absolute_Max_sizes[mode]; i++) {
				this->Controls->Remove(this->Sr_l[i]);
				this->Controls->Remove(this->ID_tb[i]);
				this->Controls->Remove(this->Name_tb[i]);
				this->Controls->Remove(this->Email_tb[i]);
				this->Controls->Remove(this->Pass_tb[i]);
			}
			this->Controls->Remove(this->Sr_header);
			this->Controls->Remove(this->ID_header);
			this->Controls->Remove(this->Name_header);
			this->Controls->Remove(this->Email_header);
			this->Controls->Remove(this->Pass_header);
			this->Controls->Remove(this->Save_button);
			this->Controls->Remove(this->Back_from_Cred_button);
			this->Controls->Remove(this->Mgmt_header);
		} // Remove_Components_Credentials_manager - end 
#pragma endregion
	// Functions - Admin_homepage
	private: System::Void Admin_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Stu_button_Click(System::Object^ sender, System::EventArgs^ e) {
		mode = STU;
		this->Hide();
		Remove_Components_homepage();
		InitializeComponent_Section_manager();
		this->Show();
	}
	private: System::Void Teach_button_Click(System::Object^ sender, System::EventArgs^ e) {
		mode = TEACH;
		open_cred_winform();
	} 
	private: System::Void Logout_button_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	// Functions - Admin_homepage - end

	// Functions - Section_manager
	private: System::Void Select_Section_A(System::Object^ sender, System::EventArgs^ e) {
		curr_sec = 0;
		update_settings();
		open_cred_winform();
	}
	private: System::Void Select_Section_B(System::Object^ sender, System::EventArgs^ e) {
		curr_sec = 1;
		update_settings();
		open_cred_winform();
	}
	private: System::Void Select_Section_C(System::Object^ sender, System::EventArgs^ e) {
		curr_sec = 2;
		update_settings();
		open_cred_winform();
	}
	private: System::Void Select_Section_D(System::Object^ sender, System::EventArgs^ e) {
		curr_sec = 3;
		update_settings();
		open_cred_winform();
	}
	private: System::Void Select_Section_E(System::Object^ sender, System::EventArgs^ e) {
		curr_sec = 4;
		update_settings();
		open_cred_winform();
	}
	private: System::Void Select_Section_F(System::Object^ sender, System::EventArgs^ e) {
		curr_sec = 5;
		update_settings();
		open_cred_winform();
	}
	private: System::Void Select_Section_G(System::Object^ sender, System::EventArgs^ e) {
		curr_sec = 6;
		update_settings();
		open_cred_winform();
	}
	private: System::Void Select_Section_H(System::Object^ sender, System::EventArgs^ e) {
		curr_sec = 7;
		update_settings();
		open_cred_winform();
	}
	private: System::Void Select_Section_I(System::Object^ sender, System::EventArgs^ e) {
		curr_sec = 8;
		update_settings();
		open_cred_winform();
	}
	private: System::Void Select_Section_J(System::Object^ sender, System::EventArgs^ e) {
		curr_sec = 9;
		update_settings();
		open_cred_winform();
	}
	private: System::Void Create_New_Section(System::Object^ sender, System::EventArgs^ e) {
		load_buttons(++saved.sections);
		
		// -1 cause saved.sections start from 1 and array indexes start from 0
		New_Sec_button->Left = Section[saved.sections - 1 ]->Left;
		Sec_del_button->Left = New_Sec_button->Left + 175;
		Back_from_Sec_button->Left = New_Sec_button->Left;

		Sec_del_button->Top = Section[saved.sections - 1]->Top;
		New_Sec_button->Top = Sec_del_button->Top + 35;
		if ( saved.sections != Max_Sections ) Back_from_Sec_button->Top = New_Sec_button->Top + 35;
		
		this->Sec_del_button->BringToFront();
		//new_sec_button_y += 31;
		
	}
	private: System::Void Delete_a_Section(System::Object^ sender, System::EventArgs^ e) {
		load_buttons(--saved.sections);
		// -1 cause saved.sections start from 1 and array indexes start from 0
		New_Sec_button->Left = Section[saved.sections - 1]->Left;
		Sec_del_button->Left = New_Sec_button->Left + 175;
		Back_from_Sec_button->Left = New_Sec_button->Left;

		Sec_del_button->Top = Section[saved.sections - 1 ]->Top;
		New_Sec_button->Top = Sec_del_button->Top + 35;
		Back_from_Sec_button->Top = New_Sec_button->Top + 35;

		
		this->Sec_del_button->BringToFront();
	}
	private: System::Void back_to_homepage(System::Object^ sender, System::EventArgs^ e) {
		back_to_homepage();
	}
	private: System::Void back_to_homepage(Void) {
		this->Hide();
		if (mode == STU)
			Remove_Components_Section_manager();
		else if (mode == TEACH)
			Remove_Components_Credentials_manager();

		InitializeComponent();
		this->Show();
	}
	private: System::Void update_settings(Void) {
		std::ofstream settings(settings_file);
		WriteSettings(settings, saved);
		settings.close();
	}
	private: System::Void open_cred_winform(Void) {

		this->Hide();
		if (mode == TEACH)
			Remove_Components_homepage();
		else if (mode == STU)
			Remove_Components_Section_manager();

		InitializeComponent_Crdentials_manager();
		Credential_manager_init();

		this->Show();
	} // Functions - Section_manager - end

	// Functions - Credential_manager
	private: System::Void Credential_manager_init(Void) {
		for (int i = 0; i < Absolute_Max_sizes[mode]; i++) {
			credentials tmp;
			if (mode == STU)
				tmp = Stu_Cred[curr_sec][i];
			else if (mode == TEACH)
				tmp = Teach_Cred[i];
			ID_tb[i]->Text = std_to_System_string(tmp.id);
			Name_tb[i]->Text = std_to_System_string(tmp.name);
			Email_tb[i]->Text = std_to_System_string(tmp.username);
			Pass_tb[i]->Text = std_to_System_string(tmp.pass);
		}
	}
	private: System::Void Save_button_Click(System::Object^ sender, System::EventArgs^ e) {

		for (int i = 0; i < Absolute_Max_sizes[mode]; i++) {

			if (mode == STU) {
				Stu_Cred[curr_sec][i].id = System_to_std_string(ID_tb[i]->Text);
				Stu_Cred[curr_sec][i].name = System_to_std_string(Name_tb[i]->Text);
				Stu_Cred[curr_sec][i].username = System_to_std_string(Email_tb[i]->Text);
				Stu_Cred[curr_sec][i].pass = System_to_std_string(Pass_tb[i]->Text);
			}
			else if (mode == TEACH) {
				Teach_Cred[i].id = System_to_std_string(ID_tb[i]->Text);
				Teach_Cred[i].name = System_to_std_string(Name_tb[i]->Text);
				Teach_Cred[i].username = System_to_std_string(Email_tb[i]->Text);
				Teach_Cred[i].pass = System_to_std_string(Pass_tb[i]->Text);
			}

		}
		
		if (mode == STU) {
			std::ofstream stu(Student_Cred_Folder + "Sec_" + Sec_list[curr_sec] + ".txt");
			WriteCredentials(stu, Stu_Cred[curr_sec], Max_Students);
			stu.close();
		}
		else if (mode == TEACH) {
			std::ofstream Teach(Teacher_Cred_File);
			WriteCredentials(Teach, Teach_Cred, sizeof(Teach_Cred) / sizeof(*Teach_Cred));
			Teach.close();
		}

		MessageBox::Show("Credentials Updated Successfully !");
	}
	private: System::Void back_to_section_manager(System::Object^ sender, System::EventArgs^ e) {
		back_to_section_manager();
	}
	private: System::Void back_to_section_manager(Void) {
		this->Hide();
		Remove_Components_Credentials_manager();
		InitializeComponent_Section_manager();
		this->Show();
	}
	 // Functions - Credentials_manager - end
};
}
