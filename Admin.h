#pragma once
#include "variables.h"
#include "functions.h"
#include <string>

namespace MSP {

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

	// Admin_homepage - items - start
	private: System::Windows::Forms::Label ^Admin_hp_header, ^New_pass_message_label;
	private: System::Windows::Forms::Button ^Stu_button, ^Teach_button, ^Admin_button, ^Sub_button, ^SubAllot_button, ^Logout_button, ^New_pass_update_button;
	
	private: System::Windows::Forms::Form ^New_Pass_prompt;
	private: System::Windows::Forms::TextBox ^New_Pass_tb, ^New_Pass_Confirmation_tb;
	// Admin_homepage - items - end
	
	// Section_manager - items - start
	private: System::Windows::Forms::Label ^Section_manager_header;
	private: System::Windows::Forms::Button ^New_Sec_button, ^Back_from_Sec_button, ^ Sec_del_button;
	private: array<System::Windows::Forms::Button^> ^Section;
	// Section_manager - items - end

	// Credentials_manager - items - start
	private: array<System::Windows::Forms::Label^> ^Sr_Cred_l;
	private: array<System::Windows::Forms::TextBox^> ^ID_Cred_tb, ^Name_Cred_tb, ^Email_Cred_tb, ^Pass_Cred_tb;

	private: System::Windows::Forms::Label ^Mgmt_header, ^Email_Cred_header, ^Pass_Cred_header;
	private: System::Windows::Forms::Button ^Save_button_Cred, ^Back_from_Cred_button;
	// Credentials_manager - items - end

	// Credentials_manager + Subject_allotment + Subjects_manager - items - start
	private: System::Windows::Forms::Label^ Sr_header, ^ID_header, ^Name_header;
	// Credentials_manager + Subject_allotment + Subjects_manager - items - end
	
	// Subject allotment - items - start
	private: System::Windows::Forms::Label^ Sub_allot_header;
	private: array<System::Windows::Forms::Label^> ^Subject_SubAllot_header, ^Sr_SubAllot_l, ^ID_SubAllot_l, ^Name_SubAllot_l;
	private: System::Windows::Forms::Button^ Back_from_SubAllot_button, ^Save_button_SubAllot;
	private: array<array<System::Windows::Forms::ComboBox^>^>^ Subject_SubAllot_cb;
	// Subject allotment - items - end

	// Subjects_manager - items - start
	private: System::Windows::Forms::Label^ SubMgr_header, ^GradingSystem_SubMgr_header;;
	private: System::Windows::Forms::Button^ Save_button_SubMgr, ^Back_from_SubMgr_button;
	private: array<System::Windows::Forms::Label^>^ Sr_SubMgr_l;
	private: array<System::Windows::Forms::TextBox^>^ CourseCode_SubMgr_tb, ^Subject_SubMgr_tb;
	private: array<System::Windows::Forms::ComboBox^>^ GradingSystem_SubMgr_cb;
	// Subject_manager - items - end

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		// Admin homepage
		void InitializeComponent(void)
		{
			// Keep track of the tab index
			int tab_index = 0;

			// Initialize components with thehelp of their default constructors
			this->Admin_hp_header = (gcnew System::Windows::Forms::Label());
			this->Stu_button = (gcnew System::Windows::Forms::Button());
			this->Teach_button = (gcnew System::Windows::Forms::Button());
			this->Admin_button = (gcnew System::Windows::Forms::Button());
			this->Sub_button = (gcnew System::Windows::Forms::Button());
			this->SubAllot_button = (gcnew System::Windows::Forms::Button());
			this->Logout_button = (gcnew System::Windows::Forms::Button());
			
			this->SuspendLayout();
			
			// 
			// Admin_hp_header
			// 
			this->Admin_hp_header->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Admin_hp_header->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Admin_hp_header->Location = System::Drawing::Point(10, 40);
			this->Admin_hp_header->Name = L"Admin_hp_header";
			this->Admin_hp_header->Size = System::Drawing::Size(700, 30);
			if (!No_Admin_Cred_available)
				this->Admin_hp_header->Text = stoS("Welcome, " + Admin_Cred[admin_no].name);
			else
				this->Admin_hp_header->Text = L"Default Admin Account";
			this->Admin_hp_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Stu_button
			// 
			this->Stu_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Stu_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Stu_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Stu_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Stu_button->Location = System::Drawing::Point(250, 120);
			this->Stu_button->Name = L"Stu_button";
			this->Stu_button->Size = System::Drawing::Size(220, 30);
			this->Stu_button->TabIndex = tab_index++;
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
			this->Teach_button->Location = System::Drawing::Point(250, 160);
			this->Teach_button->Name = L"Teach_button";
			this->Teach_button->Size = System::Drawing::Size(220, 30);
			this->Teach_button->TabIndex = tab_index++;
			this->Teach_button->Text = L"Manage Teachers";
			this->Teach_button->UseVisualStyleBackColor = false;
			this->Teach_button->Click += gcnew System::EventHandler(this, &Admin::Teach_button_Click);
			// 
			// Admin_button
			// 
			this->Admin_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Admin_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Admin_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Admin_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Admin_button->Location = System::Drawing::Point(250, 200);
			this->Admin_button->Name = L"Admin_button";
			this->Admin_button->Size = System::Drawing::Size(220, 30);
			this->Admin_button->TabIndex = tab_index++;
			if (No_Admin_Cred_available)
				this->Admin_button->Text = L"Manage Admins";
			else 
				this->Admin_button->Text = L"Reset password";
			this->Admin_button->UseVisualStyleBackColor = false;
			this->Admin_button->Click += gcnew System::EventHandler(this, &Admin::Admin_button_Click);
			// 
			// Sub_button
			// 
			this->Sub_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Sub_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Sub_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Sub_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Sub_button->Location = System::Drawing::Point(250, 240);
			this->Sub_button->Name = L"Sub_button";
			this->Sub_button->Size = System::Drawing::Size(220, 30);
			this->Sub_button->TabIndex = tab_index++;
			this->Sub_button->Text = L"Manage Subjects";
			this->Sub_button->UseVisualStyleBackColor = false;
			this->Sub_button->Click += gcnew System::EventHandler(this, &Admin::Sub_button_Click);
			// 
			// SubAllot_button
			// 
			this->SubAllot_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->SubAllot_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->SubAllot_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->SubAllot_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SubAllot_button->Location = System::Drawing::Point(250, 280);
			this->SubAllot_button->Name = L"SubAllot_button";
			this->SubAllot_button->Size = System::Drawing::Size(220, 30);
			this->SubAllot_button->TabIndex = tab_index++;
			this->SubAllot_button->Text = L"Subject Allotment";
			this->SubAllot_button->UseVisualStyleBackColor = false;
			this->SubAllot_button->Click += gcnew System::EventHandler(this, &Admin::SubAllot_button_Click);
			// 
			// Logout_button
			// 
			this->Logout_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Logout_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Logout_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Logout_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Logout_button->Location = System::Drawing::Point(250, 320);
			this->Logout_button->Name = L"Logout_button";
			this->Logout_button->Size = System::Drawing::Size(220, 30);
			this->Logout_button->TabIndex = tab_index++;
			this->Logout_button->Text = L"Logout";
			this->Logout_button->UseVisualStyleBackColor = false;
			this->Logout_button->Click += gcnew System::EventHandler(this, &Admin::Logout_button_Click);
			
			// 
			// Admin
			// 
			this->AutoScroll = true;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(720, 450);
			this->Controls->Add(this->Admin_hp_header);
			this->Controls->Add(this->Stu_button);
			this->Controls->Add(this->Teach_button);
			this->Controls->Add(this->Admin_button);
			this->Controls->Add(this->Sub_button);
			this->Controls->Add(this->SubAllot_button);
			this->Controls->Add(this->Logout_button);
			this->Name = L"Admin";
			this->Text = L"Homepage";
			this->ResumeLayout(false);

		} // Admin_homepage - end
		// Admin homepage - end

		// Section Manager
		void InitializeComponent_SectionManager(void)
		{
			// Keep track of the tab index
			int tab_index = 0;

			// Initialize components with thehelp of their default constructors
			this->Section_manager_header = (gcnew System::Windows::Forms::Label());
			this->Sec_del_button = (gcnew System::Windows::Forms::Button());
			this->New_Sec_button = (gcnew System::Windows::Forms::Button());
			this->Back_from_Sec_button = (gcnew System::Windows::Forms::Button());

			this->Section = gcnew array<System::Windows::Forms::Button^>(Max_Sections);
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
			this->Section_manager_header->Text = L"Select a section:";
			// 
			// Section_Array
			// 
			for (int i = 0; i < Max_Sections; i++) {
				this->Section[i]->Anchor = System::Windows::Forms::AnchorStyles::Top;
				this->Section[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				this->Section[i]->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				this->Section[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				if ( i  == 0 )
					this->Section[i]->Location = System::Drawing::Point(225, 90);
				else 
					this->Section[i]->Location = System::Drawing::Point(225, this->Section[i-1]->Bottom + 6);
				this->Section[i]->Name = stoS(string("Sec ") + Sec_list[i] + "_button");
				this->Section[i]->Size = System::Drawing::Size(200, 25);
				this->Section[i]->TabIndex = tab_index++;
				this->Section[i]->Text = stoS(string("Section ") + Sec_list[i]);
				this->Section[i]->UseVisualStyleBackColor = false;
				this->Section[i]->Tag = i;
				this->Section[i]->Click += gcnew System::EventHandler(this, &Admin::Select_Section);
			}


			// 
			// Sec_del_button
			// 
			this->Sec_del_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Sec_del_button->BackColor = System::Drawing::Color::Red;
			this->Sec_del_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Sec_del_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Sec_del_button->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->Sec_del_button->Location = System::Drawing::Point(this->Section[saved.sections - 1]->Left + (this->Section[saved.sections - 1]->Width-25), this->Section[saved.sections - 1]->Top);
			this->Sec_del_button->Name = L"Sec_J_del";
			this->Sec_del_button->Size = System::Drawing::Size(25, 25);
			this->Sec_del_button->TabIndex = tab_index++;
			this->Sec_del_button->Text = L"X";
			this->Sec_del_button->UseVisualStyleBackColor = false;
			this->Sec_del_button->Visible = false;
			this->Sec_del_button->Click += gcnew System::EventHandler(this, &Admin::Delete_a_Section);
			
			// 
			// New_Sec_button
			//
			this->New_Sec_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->New_Sec_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->New_Sec_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->New_Sec_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->New_Sec_button->Location = System::Drawing::Point(this->Section[saved.sections - 1]->Left, this->Sec_del_button->Top+35);
			this->New_Sec_button->Name = L"New_Sec_button";
			this->New_Sec_button->Size = System::Drawing::Size(200, 25);
			this->New_Sec_button->TabIndex = tab_index++;
			this->New_Sec_button->Text = L"Create a New Section";
			this->New_Sec_button->UseVisualStyleBackColor = false;
			this->New_Sec_button->Visible = true;
			this->New_Sec_button->Click += gcnew System::EventHandler(this, &Admin::Create_New_Section);
			
			// 
			// Back_to_home_button
			// 
			this->Back_from_Sec_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Back_from_Sec_button->BackColor = System::Drawing::Color::Lavender;
			this->Back_from_Sec_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Back_from_Sec_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			if (mode != SUBJECTS)
				this->Back_from_Sec_button->Location = System::Drawing::Point(this->New_Sec_button->Left, this->New_Sec_button->Top + 35);
			else
				this->Back_from_Sec_button->Location = System::Drawing::Point(this->Section[saved.sections - 1]->Left, this->Section[saved.sections - 1]->Top + 35);
			if (saved.sections == Max_Sections && mode != SUBJECTS)
				this->Back_from_Sec_button->Top -= 35;
			this->Back_from_Sec_button->Name = L"Back_to_home_del";
			this->Back_from_Sec_button->Size = System::Drawing::Size(200, 25);
			this->Back_from_Sec_button->Text = L"Go Back to home";
			this->Back_from_Sec_button->UseVisualStyleBackColor = false;
			this->Back_from_Sec_button->TabIndex = tab_index++;
			this->Back_from_Sec_button->Visible = true;
			this->Back_from_Sec_button->Click += gcnew System::EventHandler(this, &Admin::back_to_homepage);

			// 
			// Section_manager
			// 
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(684, 412);
			this->Controls->Add(this->Section_manager_header);
			if ( mode != SUBJECTS){
				this->Controls->Add(this->New_Sec_button);
				this->Controls->Add(this->Sec_del_button);
			}
			this->Controls->Add(this->Back_from_Sec_button);
			this->Controls->AddRange(this->Section);

			this->Name = L"Section_manager";
			this->Text = L"Section Management";
			load_buttons(saved.sections);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		// Section Manager - end

		// Credentials Manager
		void InitializeComponent_CredentialsManager(void)
		{
			// Keep track of the tab index
			int tab_index = 0;

			// Initialize components with thehelp of their default constructors
			this->Mgmt_header = (gcnew System::Windows::Forms::Label());
			this->Save_button_Cred = (gcnew System::Windows::Forms::Button());
			this->Back_from_Cred_button = (gcnew System::Windows::Forms::Button());
			
			this->Sr_header = (gcnew System::Windows::Forms::Label());
			this->ID_header = (gcnew System::Windows::Forms::Label());
			this->Name_header = (gcnew System::Windows::Forms::Label());
			this->Email_Cred_header = (gcnew System::Windows::Forms::Label());
			this->Pass_Cred_header = (gcnew System::Windows::Forms::Label());

			this->Sr_Cred_l = gcnew array<System::Windows::Forms::Label^>(Absolute_Max_sizes[mode]);
			this->ID_Cred_tb = gcnew array<System::Windows::Forms::TextBox^>(Absolute_Max_sizes[mode]);;
			this->Name_Cred_tb = gcnew array<System::Windows::Forms::TextBox^>(Absolute_Max_sizes[mode]);;
			this->Email_Cred_tb = gcnew array<System::Windows::Forms::TextBox^>(Absolute_Max_sizes[mode]);;
			this->Pass_Cred_tb = gcnew array<System::Windows::Forms::TextBox^>(Absolute_Max_sizes[mode]);;

			for (int i = 0; i < Absolute_Max_sizes[mode]; i++) {
				this->Sr_Cred_l[i] = gcnew System::Windows::Forms::Label();
				this->ID_Cred_tb[i] = gcnew System::Windows::Forms::TextBox();
				this->Name_Cred_tb[i] = gcnew System::Windows::Forms::TextBox();
				this->Email_Cred_tb[i] = gcnew System::Windows::Forms::TextBox();
				this->Pass_Cred_tb[i] = gcnew System::Windows::Forms::TextBox();
			}

			this->SuspendLayout();
			
			// 
			// Mgmt_header
			// 
			this->Mgmt_header->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Mgmt_header->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->Mgmt_header->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Mgmt_header->Location = System::Drawing::Point(35, 20);
			this->Mgmt_header->Name = L"Mgmt_header";
			this->Mgmt_header->Size = System::Drawing::Size(700, 31);
			this->Mgmt_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			if (mode == STU)
				this->Mgmt_header->Text = L"Student Credentials";
			else if (mode == TEACH)
				this->Mgmt_header->Text = L"Teacher Credentials";
			else if (mode == ADMIN)
				this->Mgmt_header->Text = L"Admin Credentials";

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
			this->Back_from_Cred_button->TabIndex = tab_index++;
			this->Back_from_Cred_button->Text = L"Back";
			this->Back_from_Cred_button->UseVisualStyleBackColor = false;
			if (mode == TEACH || mode == ADMIN)
				this->Back_from_Cred_button->Click += gcnew System::EventHandler(this, &Admin::back_to_homepage);
			else if (mode == STU)
				this->Back_from_Cred_button->Click += gcnew System::EventHandler(this, &Admin::back_to_section_manager);
			// 
			// Save_button
			//
			this->Save_button_Cred->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Right | System::Windows::Forms::AnchorStyles::Top);
			this->Save_button_Cred->BackColor = System::Drawing::Color::Lavender;
			this->Save_button_Cred->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Save_button_Cred->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Save_button_Cred->Location = System::Drawing::Point(660, 61);
			this->Save_button_Cred->Name = L"Save_button";
			this->Save_button_Cred->Size = System::Drawing::Size(100, 23);
			this->Save_button_Cred->TabIndex = tab_index++;
			this->Save_button_Cred->Text = L"Save";
			this->Save_button_Cred->UseVisualStyleBackColor = false;
			this->Save_button_Cred->Click += gcnew System::EventHandler(this, &Admin::Save_button_Cred_Click);

			// 
			// Sr_header
			// 
			this->Sr_header->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Sr_header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Sr_header->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Sr_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Sr_header->Location = System::Drawing::Point(5, 93);
			this->Sr_header->Name = L"Sr_l_h";
			this->Sr_header->Size = System::Drawing::Size(35, 25);
			this->Sr_header->Text = L"Sr.";
			this->Sr_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			
			// 
			// ID_header
			// 
			this->ID_header->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->ID_header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ID_header->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->ID_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ID_header->Location = System::Drawing::Point(this->Sr_header->Left + this->Sr_header->Width + 5, this->Sr_header->Top);
			this->ID_header->Name = L"ID_header";
			this->ID_header->Size = System::Drawing::Size(100, 25);
			this->ID_header->Text = L"ID";
			this->ID_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Name_header
			// 
			this->Name_header->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Name_header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Name_header->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Name_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name_header->Location = System::Drawing::Point(this->ID_header->Left + this->ID_header->Width + 5, this->ID_header->Top);
			this->Name_header->Name = L"Name_h";
			this->Name_header->Size = System::Drawing::Size(200, 25);
			if (mode == STU)
				this->Name_header->Text = L"Student Name";
			else if (mode == TEACH)
				this->Name_header->Text = L"Teacher Name";
			else if (mode == ADMIN)
				this->Name_header->Text = L"Admin Name";
			this->Name_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			// 
			// Email_header
			// 
			this->Email_Cred_header->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Email_Cred_header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Email_Cred_header->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Email_Cred_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Email_Cred_header->Location = System::Drawing::Point(this->Name_header->Left + this->Name_header->Width + 5, this->Name_header->Top);
			this->Email_Cred_header->Name = L"Email_h";
			this->Email_Cred_header->Size = System::Drawing::Size(200, 25);
			this->Email_Cred_header->Text = L"Email";
			this->Email_Cred_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Pass_header
			// 
			this->Pass_Cred_header->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Pass_Cred_header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Pass_Cred_header->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Pass_Cred_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Pass_Cred_header->Location = System::Drawing::Point(this->Email_Cred_header->Left + this->Email_Cred_header->Width + 5, 93);
			this->Pass_Cred_header->Name = L"Pass_h";
			this->Pass_Cred_header->Size = System::Drawing::Size(200, 25);
			this->Pass_Cred_header->Text = L"Password";
			this->Pass_Cred_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			// 
			// Serial labels
			// 
			for (int i = 0; i < Absolute_Max_sizes[mode]; i++) {
				this->Sr_Cred_l[i]->Anchor = System::Windows::Forms::AnchorStyles::Top;
				this->Sr_Cred_l[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				if ( i == 0 )
					this->Sr_Cred_l[i]->Location = System::Drawing::Point(5, 124);
				else
					this->Sr_Cred_l[i]->Location = System::Drawing::Point(5, this->Sr_Cred_l[i-1]->Bottom + 6);
				this->Sr_Cred_l[i]->Name = "Sr_" + (i + 1).ToString();
				this->Sr_Cred_l[i]->Size = System::Drawing::Size(35, 25);
				this->Sr_Cred_l[i]->Text = (i + 1).ToString() + ")";
				this->Sr_Cred_l[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			}
			//
			// Roll no
			//
			for (int i = 0; i < Absolute_Max_sizes[mode]; i++) {
				this->ID_Cred_tb[i]->Anchor = System::Windows::Forms::AnchorStyles::Top;
				this->ID_Cred_tb[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				this->ID_Cred_tb[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->ID_Cred_tb[i]->Left = this->Sr_Cred_l[i]->Left + this->Sr_Cred_l[i]->Width + 5;
				if (i == 0)
					this->ID_Cred_tb[i]->Top = 124;
				else
					this->ID_Cred_tb[i]->Top = this->ID_Cred_tb[i-1]->Bottom + 6;
				this->ID_Cred_tb[i]->Name = "Name_" + (i + 1).ToString();
				this->ID_Cred_tb[i]->Size = System::Drawing::Size(100, 25);
				this->ID_Cred_tb[i]->TabIndex = tab_index++;
				this->ID_Cred_tb[i]->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			}
			//
			// Student name 
			//
			for (int i = 0; i < Absolute_Max_sizes[mode]; i++) {
				this->Name_Cred_tb[i]->Anchor = System::Windows::Forms::AnchorStyles::Top;
				this->Name_Cred_tb[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				this->Name_Cred_tb[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Name_Cred_tb[i]->Left = this->ID_Cred_tb[i]->Left + this->ID_Cred_tb[i]->Width + 5;
				if ( i == 0 )
					this->Name_Cred_tb[i]->Top = 124;
				else
					this->Name_Cred_tb[i]->Top = this->Name_Cred_tb[i-1]->Bottom + 6;
				this->Name_Cred_tb[i]->Name = "Name_" + (i + 1).ToString();
				this->Name_Cred_tb[i]->Size = System::Drawing::Size(200, 25);
				this->Name_Cred_tb[i]->TabIndex = tab_index++;
				this->Name_Cred_tb[i]->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			}
			//
			// Email
			//
			for (int i = 0; i < Absolute_Max_sizes[mode]; i++) {
				this->Email_Cred_tb[i]->Anchor = System::Windows::Forms::AnchorStyles::Top;
				this->Email_Cred_tb[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				this->Email_Cred_tb[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Email_Cred_tb[i]->Left = this->Name_Cred_tb[i]->Left + this->Name_Cred_tb[i]->Width + 5;
				if ( i == 0 )
					this->Email_Cred_tb[i]->Top = 124;
				else
					this->Email_Cred_tb[i]->Top = this->Email_Cred_tb[i-1]->Bottom + 6;
				this->Email_Cred_tb[i]->Name = "Name_" + (i + 1).ToString();
				this->Email_Cred_tb[i]->Size = System::Drawing::Size(200, 25);
				this->Email_Cred_tb[i]->TabIndex = tab_index++;
				this->Email_Cred_tb[i]->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			}
			//
			// Pass
			//
			for (int i = 0; i < Absolute_Max_sizes[mode]; i++) {
				this->Pass_Cred_tb[i]->Anchor = System::Windows::Forms::AnchorStyles::Top;
				this->Pass_Cred_tb[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				this->Pass_Cred_tb[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Pass_Cred_tb[i]->Left = this->Email_Cred_tb[i]->Left + this->Email_Cred_tb[i]->Width + 5;
				if (i == 0)
					this->Pass_Cred_tb[i]->Top = 124;
				else
					this->Pass_Cred_tb[i]->Top = this->Pass_Cred_tb[i - 1]->Bottom + 6;
				this->Pass_Cred_tb[i]->Name = "Pass_" + (i + 1).ToString();
				this->Pass_Cred_tb[i]->UseSystemPasswordChar = true;
				this->Pass_Cred_tb[i]->Size = System::Drawing::Size(200, 25);
				this->Pass_Cred_tb[i]->TabIndex = tab_index++;
				this->Pass_Cred_tb[i]->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			}

			// 
			// Credential_management
			// 
			this->AutoScroll = true;
			this->AcceptButton = this->Save_button_Cred;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(780, 450);
			this->Controls->Add(this->Mgmt_header);
			this->Controls->Add(this->Sr_header);
			this->Controls->Add(this->ID_header);
			this->Controls->Add(this->Name_header);
			this->Controls->Add(this->Email_Cred_header);
			this->Controls->Add(this->Pass_Cred_header);
			this->Controls->Add(this->Save_button_Cred);
			this->Controls->Add(this->Back_from_Cred_button);
			this->Controls->AddRange(this->Sr_Cred_l);
			this->Controls->AddRange(this->ID_Cred_tb);
			this->Controls->AddRange(this->Name_Cred_tb);
			this->Controls->AddRange(this->Email_Cred_tb);
			this->Controls->AddRange(this->Pass_Cred_tb);
			if (mode == STU) {
				this->Name = L"Student_management";
				this->Text = L"Student management";
			}
			else if (mode == TEACH) {
				this->Name = L"Teacher_management";
				this->Text = L"Teacher management";
			}
			else if (mode == ADMIN) {
				this->Name = L"admin_management";
				this->Text = L"Admin management";
			}
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		// Credentials Manager - end

		// Subject allotment
		void InitializeComponent_SubjectAllotment(void)
		{
			// Keep track of the tab index
			int tab_index = 0;

			// Initialize components with thehelp of their default constructors
			this->Sub_allot_header = (gcnew System::Windows::Forms::Label());
			this->Sr_header = (gcnew System::Windows::Forms::Label());
			this->ID_header = (gcnew System::Windows::Forms::Label());
			this->Name_header = (gcnew System::Windows::Forms::Label());

			this->Subject_SubAllot_header = gcnew array<System::Windows::Forms::Label^>(Max_subject_per_teacher);
			for (int i = 0; i < Max_subject_per_teacher; i++) {
				this->Subject_SubAllot_header[i] = (gcnew System::Windows::Forms::Label());
			}

			this->Back_from_SubAllot_button = (gcnew System::Windows::Forms::Button());
			this->Save_button_SubAllot = (gcnew System::Windows::Forms::Button());

			this->Sr_SubAllot_l = gcnew array<System::Windows::Forms::Label^>(Max_Teachers);
			this->ID_SubAllot_l = gcnew array<System::Windows::Forms::Label^>(Max_Teachers);
			this->Name_SubAllot_l = gcnew array<System::Windows::Forms::Label^>(Max_Teachers);
			for (int i = 0; i < Max_Teachers; i++) {
				this->Sr_SubAllot_l[i] = (gcnew System::Windows::Forms::Label());
				this->ID_SubAllot_l[i] = (gcnew System::Windows::Forms::Label());
				this->Name_SubAllot_l[i] = (gcnew System::Windows::Forms::Label());
			}

			this->Subject_SubAllot_cb = gcnew array<array<System::Windows::Forms::ComboBox^>^>(Max_Teachers);
			for (int i = 0; i < Max_Teachers; i++) {
				this->Subject_SubAllot_cb[i] = gcnew array<System::Windows::Forms::ComboBox^>(Max_subject_per_teacher);
				for (int j = 0; j < Max_subject_per_teacher; j++) {
					this->Subject_SubAllot_cb[i][j] = (gcnew System::Windows::Forms::ComboBox());
				}
			}

			this->SuspendLayout();

			// 
			// Sub_allot header
			// 
			this->Sub_allot_header->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Sub_allot_header->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->Sub_allot_header->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Sub_allot_header->Location = System::Drawing::Point(10, 20);
			this->Sub_allot_header->Name = L"SubAllot_header";
			this->Sub_allot_header->Size = System::Drawing::Size(1310, 31);
			this->Sub_allot_header->Text = L"Subject Allotment";
			this->Sub_allot_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			// 
			// Back button
			//
			this->Back_from_SubAllot_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
			this->Back_from_SubAllot_button->BackColor = System::Drawing::Color::Lavender;
			this->Back_from_SubAllot_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Back_from_SubAllot_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Back_from_SubAllot_button->Location = System::Drawing::Point(5, 61);
			this->Back_from_SubAllot_button->Name = L"Back_button";
			this->Back_from_SubAllot_button->Size = System::Drawing::Size(100, 23);
			this->Back_from_SubAllot_button->TabIndex = tab_index++;
			this->Back_from_SubAllot_button->Text = L"Back";
			this->Back_from_SubAllot_button->UseVisualStyleBackColor = false;
			this->Back_from_SubAllot_button->Click += gcnew System::EventHandler(this, &Admin::back_to_homepage);
			// 
			// Save button
			//
			this->Save_button_SubAllot->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Right | System::Windows::Forms::AnchorStyles::Top);
			this->Save_button_SubAllot->BackColor = System::Drawing::Color::Lavender;
			this->Save_button_SubAllot->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Save_button_SubAllot->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Save_button_SubAllot->Location = System::Drawing::Point(1225, 61);
			this->Save_button_SubAllot->Name = L"Save_button";
			this->Save_button_SubAllot->Size = System::Drawing::Size(100, 23);
			this->Save_button_SubAllot->TabIndex = tab_index++;
			this->Save_button_SubAllot->Text = L"Save";
			this->Save_button_SubAllot->UseVisualStyleBackColor = false;
			this->Save_button_SubAllot->Click += gcnew System::EventHandler(this, &Admin::Save_button_SubAllot_Click);

			//
			// Sr header
			// 
			this->Sr_header->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Sr_header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Sr_header->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Sr_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Sr_header->Location = System::Drawing::Point(5, 93);
			this->Sr_header->Name = L"Sr_l_h";
			this->Sr_header->Size = System::Drawing::Size(35, 25);
			this->Sr_header->Text = L"Sr.";
			this->Sr_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			//
			// ID header
			// 
			this->ID_header->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->ID_header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ID_header->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->ID_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ID_header->Location = System::Drawing::Point(this->Sr_header->Left + this->Sr_header->Width + 5, this->Sr_header->Top);
			this->ID_header->Name = L"ID_header";
			this->ID_header->Size = System::Drawing::Size(75, 25);
			this->ID_header->Text = L"ID";
			this->ID_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Name header
			// 
			this->Name_header->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Name_header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Name_header->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Name_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name_header->Location = System::Drawing::Point(this->ID_header->Left + this->ID_header->Width + 5, this->ID_header->Top);
			this->Name_header->Name = L"Name_h";
			this->Name_header->Size = System::Drawing::Size(175, 25);
			this->Name_header->Text = L"Teacher Name";
			this->Name_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Subject header(s)
			// 
			for (int i = 0; i < Max_subject_per_teacher; i++) {
				this->Subject_SubAllot_header[i]->Anchor = System::Windows::Forms::AnchorStyles::Top;
				this->Subject_SubAllot_header[i]->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				this->Subject_SubAllot_header[i]->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				this->Subject_SubAllot_header[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Subject_SubAllot_header[i]->Top = this->ID_header->Top;
				if ( i == 0 )
					this->Subject_SubAllot_header[i]->Left = this->Name_header->Left + this->Name_header->Width + 5;
				else
					this->Subject_SubAllot_header[i]->Left = this->Subject_SubAllot_header[i-1]->Right + 5;
				this->Subject_SubAllot_header[i]->Name = "Subject_header_" + (i + 1).ToString();
				this->Subject_SubAllot_header[i]->Size = System::Drawing::Size(200, 25);
				this->Subject_SubAllot_header[i]->Text = "Subject " + (i + 1).ToString();
				this->Subject_SubAllot_header[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			}

			// 
			// Sr label 
			// 
			for (int i = 0; i < Max_Teachers; i++) {
				this->Sr_SubAllot_l[i]->Anchor = System::Windows::Forms::AnchorStyles::Top;
				this->Sr_SubAllot_l[i]->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				this->Sr_SubAllot_l[i]->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				this->Sr_SubAllot_l[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				if ( i == 0 )
					this->Sr_SubAllot_l[i]->Location = System::Drawing::Point(5, 124);
				else
					this->Sr_SubAllot_l[i]->Location = System::Drawing::Point(5, this->Sr_SubAllot_l[i-1]->Bottom + 6);
				this->Sr_SubAllot_l[i]->Name = "Sr_l_" + (i + 1).ToString();
				this->Sr_SubAllot_l[i]->Size = System::Drawing::Size(35, 25);
				this->Sr_SubAllot_l[i]->Text = (i + 1).ToString() + ")";
				this->Sr_SubAllot_l[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			}
			//
			// ID label
			//
			for (int i = 0; i < Max_Teachers; i++) {
				this->ID_SubAllot_l[i]->Anchor = System::Windows::Forms::AnchorStyles::Top;
				this->ID_SubAllot_l[i]->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				this->ID_SubAllot_l[i]->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				this->ID_SubAllot_l[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				if (i == 0)
					this->ID_SubAllot_l[i]->Location = System::Drawing::Point(this->Sr_SubAllot_l[i]->Right + 5, 124);
				else
					this->ID_SubAllot_l[i]->Location = System::Drawing::Point(this->Sr_SubAllot_l[i]->Right + 5, this->ID_SubAllot_l[i - 1]->Bottom + 6);
				this->ID_SubAllot_l[i]->Name = "ID_l_" + (i + 1).ToString();
				this->ID_SubAllot_l[i]->Size = System::Drawing::Size(75, this->Sr_SubAllot_l[i]->Height);
				this->ID_SubAllot_l[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			}
			//
			// Name label
			//
			for (int i = 0; i < Max_Teachers; i++) {
				this->Name_SubAllot_l[i]->Anchor = System::Windows::Forms::AnchorStyles::Top;
				this->Name_SubAllot_l[i]->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				this->Name_SubAllot_l[i]->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				this->Name_SubAllot_l[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				if ( i == 0 )
					this->Name_SubAllot_l[i]->Location = System::Drawing::Point(this->ID_SubAllot_l[i]->Right + 5, 124);
				else
					this->Name_SubAllot_l[i]->Location = System::Drawing::Point(this->ID_SubAllot_l[i]->Right + 5, this->Name_SubAllot_l[i-1]->Bottom + 6);
				this->Name_SubAllot_l[i]->Name = "Name_l_" + (i + 1).ToString();
				this->Name_SubAllot_l[i]->Size = System::Drawing::Size(175, this->ID_SubAllot_l[i]->Height);
				this->Name_SubAllot_l[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			}
			//
			// Subject ComboBox
			//
			for (int i = 0; i < Max_Teachers; i++) {
				for (int j = 0; j < Max_subject_per_teacher; j++) {
					this->Subject_SubAllot_cb[i][j]->Anchor = System::Windows::Forms::AnchorStyles::Top;
					this->Subject_SubAllot_cb[i][j]->BackColor = System::Drawing::Color::WhiteSmoke;
					this->Subject_SubAllot_cb[i][j]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(0)));
					this->Subject_SubAllot_cb[i][j]->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
					if (i == 0)
						this->Subject_SubAllot_cb[i][j]->Top = 124;
					else
						this->Subject_SubAllot_cb[i][j]->Top = this->Subject_SubAllot_cb[i - 1][j]->Bottom + 6;
					if ( j == 0 )
						this->Subject_SubAllot_cb[i][j]->Left = this->Name_SubAllot_l[i]->Right + 5;
					else
						this->Subject_SubAllot_cb[i][j]->Left = this->Subject_SubAllot_cb[i][j-1]->Right + 5;
					this->Subject_SubAllot_cb[i][j]->Name = "Week_" + (i + 1).ToString() + "_lec1_h";
					this->Subject_SubAllot_cb[i][j]->Size = System::Drawing::Size(200, this->ID_SubAllot_l[i]->Height);
					this->Subject_SubAllot_cb[i][j]->TabIndex = tab_index++;
					this->Subject_SubAllot_cb[i][j]->SelectedIndexChanged += gcnew System::EventHandler(this, &Admin::ComboBox_value_changed);;
				}
			}

			// 
			// Subject_allotment
			// 
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(1330, 450);
			this->BackColor = System::Drawing::Color::White;
			this->Controls->Add(this->Sub_allot_header);
			this->Controls->Add(this->Back_from_SubAllot_button);
			this->Controls->Add(this->Save_button_SubAllot);
			this->Controls->Add(this->Sr_header);
			this->Controls->Add(this->ID_header);
			this->Controls->Add(this->Name_header);
			this->Controls->AddRange(this->Subject_SubAllot_header);
			this->Controls->AddRange(this->Sr_SubAllot_l);
			this->Controls->AddRange(this->ID_SubAllot_l);
			this->Controls->AddRange(this->Name_SubAllot_l);
			for ( int i = 0; i < Max_Teachers; i++)
				this->Controls->AddRange(this->Subject_SubAllot_cb[i]);

			this->Name = L"Subject_allotment";
			this->Text = L"Subject Allotment";
			Subject_allotment_Load();
			this->ResumeLayout(false);

		}
		// Subject allotment - end

		// Subject management
		void InitializeComponent_SubjectManager(void)
		{
			// Keep track of the tab index
			int tab_index = 0;

			// Initialize components with thehelp of their default constructors
			this->Sr_SubMgr_l = gcnew array<System::Windows::Forms::Label^>(Max_Subjects);
			this->CourseCode_SubMgr_tb = gcnew array<System::Windows::Forms::TextBox^>(Max_Subjects);
			this->Subject_SubMgr_tb = gcnew array<System::Windows::Forms::TextBox^>(Max_Subjects);
			this->GradingSystem_SubMgr_cb = gcnew array<System::Windows::Forms::ComboBox^>(Max_Subjects);
			for (int i = 0; i < Max_Subjects; i++) {
				this->Sr_SubMgr_l[i] = gcnew System::Windows::Forms::Label();
				this->CourseCode_SubMgr_tb[i] = gcnew System::Windows::Forms::TextBox();
				this->Subject_SubMgr_tb[i] = gcnew System::Windows::Forms::TextBox();
				this->GradingSystem_SubMgr_cb[i] = gcnew System::Windows::Forms::ComboBox();
			}
			this->SubMgr_header = gcnew System::Windows::Forms::Label();

			this->Save_button_SubMgr = gcnew System::Windows::Forms::Button();
			this->Back_from_SubMgr_button = gcnew System::Windows::Forms::Button();

			this->Sr_header = gcnew System::Windows::Forms::Label();
			this->ID_header = gcnew System::Windows::Forms::Label();
			this->Name_header = gcnew System::Windows::Forms::Label();
			this->GradingSystem_SubMgr_header = gcnew System::Windows::Forms::Label();
			this->SuspendLayout();

			// 
			// Subject_mgmt_header
			// 
			this->SubMgr_header->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->SubMgr_header->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->SubMgr_header->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SubMgr_header->Location = System::Drawing::Point(5, 20);
			this->SubMgr_header->Name = L"Subject_mgmt_h";
			this->SubMgr_header->Size = System::Drawing::Size(745, 35);
			this->SubMgr_header->Text = L"Subject Management";
			this->SubMgr_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			// 
			// Back_from_cred_button
			//
			this->Back_from_SubMgr_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
			this->Back_from_SubMgr_button->BackColor = System::Drawing::Color::Lavender;
			this->Back_from_SubMgr_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Back_from_SubMgr_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Back_from_SubMgr_button->Location = System::Drawing::Point(5, 61);
			this->Back_from_SubMgr_button->Name = L"Back_button";
			this->Back_from_SubMgr_button->Size = System::Drawing::Size(101, 23);
			this->Back_from_SubMgr_button->TabIndex = tab_index++;
			this->Back_from_SubMgr_button->Text = L"Back";
			this->Back_from_SubMgr_button->UseVisualStyleBackColor = false;
			this->Back_from_SubMgr_button->Click += gcnew System::EventHandler(this, &Admin::back_to_section_manager);
			// 
			// Save_button
			//
			this->Save_button_SubMgr->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Right | System::Windows::Forms::AnchorStyles::Top);
			this->Save_button_SubMgr->BackColor = System::Drawing::Color::Lavender;
			this->Save_button_SubMgr->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Save_button_SubMgr->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Save_button_SubMgr->Location = System::Drawing::Point(650, 61);
			this->Save_button_SubMgr->Name = L"Save_button";
			this->Save_button_SubMgr->Size = System::Drawing::Size(100, 23);
			this->Save_button_SubMgr->TabIndex = tab_index++;
			this->Save_button_SubMgr->Text = L"Save";
			this->Save_button_SubMgr->UseVisualStyleBackColor = false;
			this->Save_button_SubMgr->Click += gcnew System::EventHandler(this, &Admin::Save_SubMgr_button_Click);

			// 
			// Sr_header
			// 
			this->Sr_header->Anchor =  System::Windows::Forms::AnchorStyles::Top;
			this->Sr_header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Sr_header->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Sr_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Sr_header->Location = System::Drawing::Point(5, 93);
			this->Sr_header->Name = L"Sr_l_h";
			this->Sr_header->Size = System::Drawing::Size(35, 25);
			this->Sr_header->Text = L"Sr.";
			this->Sr_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			//
			// ID_header (Course Code)
			// 
			this->ID_header->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->ID_header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ID_header->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->ID_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ID_header->Location = System::Drawing::Point(45, 93);
			this->ID_header->Name = L"Course_code_h";
			this->ID_header->Size = System::Drawing::Size(250, 25);
			this->ID_header->Text = L"Course code";
			this->ID_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			//
			// (Subject_)Name_header
			// 
			this->Name_header->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Name_header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Name_header->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Name_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name_header->Location = System::Drawing::Point(300, 93);
			this->Name_header->Name = L"Subject_h";
			this->Name_header->Size = System::Drawing::Size(250, 25);
			this->Name_header->Text = L"Subject";
			this->Name_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			//
			// Grading_system_h
			// 
			this->GradingSystem_SubMgr_header->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->GradingSystem_SubMgr_header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->GradingSystem_SubMgr_header->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->GradingSystem_SubMgr_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GradingSystem_SubMgr_header->Location = System::Drawing::Point(555, 93);
			this->GradingSystem_SubMgr_header->Name = L"Grading_h";
			this->GradingSystem_SubMgr_header->Size = System::Drawing::Size(200, 25);
			this->GradingSystem_SubMgr_header->Text = L"Grading System";
			this->GradingSystem_SubMgr_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			// 
			// Serial labels
			// 
			for (int i = 0; i < Max_Subjects; i++) {
				this->Sr_SubMgr_l[i]->Anchor = System::Windows::Forms::AnchorStyles::Top;
				this->Sr_SubMgr_l[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				if ( i == 0 )
					this->Sr_SubMgr_l[i]->Location = System::Drawing::Point(5, 124);
				else
					this->Sr_SubMgr_l[i]->Location = System::Drawing::Point(5, this->Sr_SubMgr_l[i-1]->Bottom + 6);
				this->Sr_SubMgr_l[i]->Name = "Sr_" + (i + 1).ToString();
				this->Sr_SubMgr_l[i]->Size = System::Drawing::Size(35, 25);
				this->Sr_SubMgr_l[i]->Text = (i + 1).ToString() + ")";
				this->Sr_SubMgr_l[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			}
			//
			// Course code
			//
			for (int i = 0; i < Max_Subjects; i++) {
				this->CourseCode_SubMgr_tb[i]->Anchor = System::Windows::Forms::AnchorStyles::Top;
				this->CourseCode_SubMgr_tb[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				this->CourseCode_SubMgr_tb[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->CourseCode_SubMgr_tb[i]->Left = this->Sr_SubMgr_l[i]->Left + this->Sr_SubMgr_l[i]->Width + 5;
				if (i == 0)
					this->CourseCode_SubMgr_tb[i]->Top = 124;
				else
					this->CourseCode_SubMgr_tb[i]->Top = this->CourseCode_SubMgr_tb[i - 1]->Bottom + 6;
				this->CourseCode_SubMgr_tb[i]->Name = "Course_code_no" + (i + 1).ToString();
				this->CourseCode_SubMgr_tb[i]->Size = System::Drawing::Size(250, 25);
				this->CourseCode_SubMgr_tb[i]->TabIndex = tab_index++;
				this->CourseCode_SubMgr_tb[i]->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			}
			//
			// Subject name 
			//
			for (int i = 0; i < Max_Subjects; i++) {
				this->Subject_SubMgr_tb[i]->Anchor = System::Windows::Forms::AnchorStyles::Top;
				this->Subject_SubMgr_tb[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				this->Subject_SubMgr_tb[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Subject_SubMgr_tb[i]->Left = this->CourseCode_SubMgr_tb[i]->Left + this->CourseCode_SubMgr_tb[i]->Width + 5;
				if (i == 0)
					this->Subject_SubMgr_tb[i]->Top = 124;
				else
					this->Subject_SubMgr_tb[i]->Top = this->Subject_SubMgr_tb[i - 1]->Bottom + 6;
				this->Subject_SubMgr_tb[i]->Name = "Subject_" + (i + 1).ToString();
				this->Subject_SubMgr_tb[i]->Size = System::Drawing::Size(250, 25);
				this->Subject_SubMgr_tb[i]->TabIndex = tab_index++;
				this->Subject_SubMgr_tb[i]->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			}
			//
			// Grading system
			//
			for (int i = 0; i < Max_Subjects; i++) {
				this->GradingSystem_SubMgr_cb[i]->Anchor = System::Windows::Forms::AnchorStyles::Top;
				this->GradingSystem_SubMgr_cb[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				this->GradingSystem_SubMgr_cb[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->GradingSystem_SubMgr_cb[i]->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
				this->GradingSystem_SubMgr_cb[i]->Left = this->Subject_SubMgr_tb[i]->Left + this->Subject_SubMgr_tb[i]->Width + 5;
				if (i == 0)
					this->GradingSystem_SubMgr_cb[i]->Top = 124;
				else
					this->GradingSystem_SubMgr_cb[i]->Top = this->GradingSystem_SubMgr_cb[i - 1]->Bottom + 6;
				this->GradingSystem_SubMgr_cb[i]->Name = "Grading_" + (i + 1).ToString();
				this->GradingSystem_SubMgr_cb[i]->Size = System::Drawing::Size(200, 25);
				this->GradingSystem_SubMgr_cb[i]->TabIndex = tab_index++;
				this->GradingSystem_SubMgr_cb[i]->Items->AddRange(gcnew array<String^> {" ", "Absolute", "Relative"});
			}

			// 
			// Subjects_manager
			// 
			this->AutoScroll = true;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(760, 450);

			this->Controls->Add(this->SubMgr_header);

			this->Controls->Add(this->Save_button_SubMgr);
			this->Controls->Add(this->Back_from_SubMgr_button);

			this->Controls->Add(this->Sr_header);
			this->Controls->Add(this->ID_header);
			this->Controls->Add(this->Name_header);
			this->Controls->Add(this->GradingSystem_SubMgr_header);

			this->Controls->AddRange(this->Sr_SubMgr_l);
			this->Controls->AddRange(this->CourseCode_SubMgr_tb);
			this->Controls->AddRange(this->Subject_SubMgr_tb);
			this->Controls->AddRange(this->GradingSystem_SubMgr_cb);

			this->Name = L"Subjects_manager";
			this->Text = L"Subjects Manager";

			Subjects_manager_Load();
			
			this->ResumeLayout(false);
			this->PerformLayout();
		}
		// Subject management - end

	// Back functions
	private: System::Void back_to_homepage(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		this->Controls->Clear();
		InitializeComponent();
		this->Show();
	}
	private: System::Void back_to_section_manager(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		this->Controls->Clear();
		InitializeComponent_SectionManager();
		this->Show();
	}
	// Back functions - end
	
	// Save functions
	private: System::Void Save_button_Cred_Click(System::Object^ sender, System::EventArgs^ e) {
		// Create a pointer to the appropraite credential array so we don't have to add tons of if checks
		credentials* Cred;
		if (mode == STU)
			Cred = &Stu_Cred[curr_sec][0];
		else if (mode == TEACH)
			Cred = &Teach_Cred[0];
		else if (mode == ADMIN)
			Cred = &Admin_Cred[0];
		for (int i = 0; i < Absolute_Max_sizes[mode]; i++) {
			// Make sure that the password is atleast 4 characters or let the user know and abort the saving process
			if (this->Pass_Cred_tb[i]->TextLength < 4) {
				System::Windows::Forms::MessageBox::Show("Passwords should be atleast 4 characters each. Aborting the saving process...\nFirst offending entry : Sr." + i.ToString());
				return;
			}
			Cred[i].id = Stos(this->ID_Cred_tb[i]->Text);
			Cred[i].name = Stos(this->Name_Cred_tb[i]->Text);
			Cred[i].username = Stos(this->Email_Cred_tb[i]->Text);
			Cred[i].pass = Stos(this->Pass_Cred_tb[i]->Text);
			if (mode == STU) {
				Student_marks[curr_sec][i].id = Cred[i].id;
				Student_marks[curr_sec][i].name = Cred[i].name;
				Student_att[curr_sec][i].id = Cred[i].id;
				Student_att[curr_sec][i].name = Cred[i].name;
			}
		}
		
		// Update the files accordingly
		if (mode == STU) {
			WriteCredentials(Student_Cred_Folder, string("Sec_") + Sec_list[curr_sec] + ".txt", Stu_Cred[curr_sec], Max_Students);

			WriteMarks(Marks_Folder, string("Sec_") + Sec_list[curr_sec] + ".txt", Student_marks[curr_sec], Max_Students, subjects_details[curr_sec][curr_subject], Max_Subjects, Max_Quizzes, Max_Assignments);

			WriteAttendence(Attendance_Folder, string("Sec_") + Sec_list[curr_sec] + ".txt", Student_att[curr_sec], Max_Students, Max_Subjects, Max_Weeks, Lec_per_Week);
		}
		else if (mode == TEACH)
			WriteCredentials(Cred_Folder, Teacher_Cred_File, Teach_Cred, Max_Teachers);
		else if (mode == ADMIN)
			WriteCredentials(Cred_Folder, Admin_Cred_File, Admin_Cred, Max_Admins);

		// If there haven't been any errors, let the user know that the operation has completed successfully
		System::Windows::Forms::MessageBox::Show("Credentials Updated Successfully !");
	}
	private: System::Void Save_button_SubAllot_Click(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < Max_Teachers; i++) {
			for (int j = 0; j < Max_subject_per_teacher; j++) {
				// If the current ComboBox is selected:
				if (this->Subject_SubAllot_cb[i][j]->SelectedIndex > 0) {
					std::string course_and_section = Stos(this->Subject_SubAllot_cb[i][j]->SelectedItem->ToString());
					int section = -1, course = -1;
					for (int i = 0; i < saved.sections; i++) {
						// If the current section is the one which is present in the selected option of the ComboBox then store it
						if (course_and_section.find(string("Section ") + Sec_list[i]) != -1) {
							section = i;
							break;
						}
					}
					
					for (int i = 0; i < Max_Subjects; i++) {
						// If the current section is the one which is present in the selected option of the ComboBox then store it
						if (course_and_section.find(subjects_details[section][i].course_code) != -1) {
							course = i;
							break;
						}
					}
					
					// If we have gotten both the section and subject indexes, then update the teacher no.
					subjects_details[section][course].teach_no = i;
				}
			} // End inner - for (int j = 0; j < Max_subject_per_teacher; j++)
		} // End inner - for (int i = 0; i < Max_Teachers; i++)

		// Update the Subject data in files
		for (int i = 0; i < saved.sections; i++){
			bool all_empty = true;
			// Don't write tothe file if no subjects exist
			for ( int j = 0; j < Max_Subjects; j++ ){
				if ( ! subjects_details[i][j].course_code.empty() &&  ! subjects_details[i][j].name.empty() ) {
					all_empty = false;
					break;
				}
			}
			if ( ! all_empty )
				WriteSubjects(Subject_Folder, string("Sec_") + Sec_list[i] + ".txt", subjects_details[i], Max_Subjects);
		}

		// If there haven't been any errors, let the user know that the operation has completed successfully
		System::Windows::Forms::MessageBox::Show("Subject allotment updated successfully !");
	}
	private: System::Void Save_SubMgr_button_Click(System::Object^ sender, System::EventArgs^ e) {
		// Get the data from the items
		for (int i = 0; i < Max_Subjects; i++) {
			subjects_details[curr_sec][i].course_code = Stos(this->CourseCode_SubMgr_tb[i]->Text);
			subjects_details[curr_sec][i].name = Stos(this->Subject_SubMgr_tb[i]->Text);
			subjects_details[curr_sec][i].grading = Stos(this->GradingSystem_SubMgr_cb[i]->SelectedItem->ToString());
		}

		// Update the file accordingly
		WriteSubjects(Subject_Folder, string("Sec_") + Sec_list[curr_sec] + ".txt", subjects_details[curr_sec], Max_Subjects);

		// If there haven't been any errors, let the user know that the operation has completed successfully
		System::Windows::Forms::MessageBox::Show("Subject data updated successfully !");
	}
	// Save functions - end
	
	// Functions - Admin_homepage
	private: System::Void Update_admin_creds(System::Object^ sender, System::EventArgs^ e) {
		// If the passwords match and their length is greater than 4 characters, update the password,
		// otherwise let the user know which check failed
		if (this->New_Pass_tb->Text == this->New_Pass_Confirmation_tb->Text && (this->New_Pass_tb->TextLength >= 4)) {
			Admin_Cred[admin_no].pass = Stos(this->New_Pass_tb->Text);

			WriteCredentials(Cred_Folder, Admin_Cred_File, Admin_Cred, Max_Admins);

			this->New_Pass_prompt->Close();
		}
		else if (this->New_Pass_tb->TextLength < 4)
			System::Windows::Forms::MessageBox::Show("Pasword must be atleast 4 characters!");
		else if (this->New_Pass_tb->Text != this->New_Pass_Confirmation_tb->Text)
			System::Windows::Forms::MessageBox::Show("Paswords do not match. Please try again!");
	}
	private: System::Void Stu_button_Click(System::Object^ sender, System::EventArgs^ e) {
		mode = STU;
		this->Hide();
		this->Controls->Clear();
		InitializeComponent_SectionManager();
		this->Show();
	}
	private: System::Void Teach_button_Click(System::Object^ sender, System::EventArgs^ e) {
		mode = TEACH;
		open_cred_winform();
	}
	private: System::Void Admin_button_Click(System::Object^ sender, System::EventArgs^ e) {
		// If we do not have any credentials of admin available the the current button corresponds to "Manage admin"
		// otherwise it corresponds to the "Reset Password" button
		if (No_Admin_Cred_available) {
			mode = ADMIN;
			open_cred_winform();
		}
		else {
			this->New_Pass_prompt = (gcnew System::Windows::Forms::Form());
			this->New_pass_message_label = (gcnew System::Windows::Forms::Label());
			this->New_Pass_tb = (gcnew System::Windows::Forms::TextBox());
			this->New_Pass_Confirmation_tb = (gcnew System::Windows::Forms::TextBox());
			this->New_pass_update_button = (gcnew System::Windows::Forms::Button());

			this->New_Pass_prompt->Size = System::Drawing::Size(250, 200);
			this->New_Pass_prompt->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->New_Pass_prompt->Text = "Reset Password";
			this->New_Pass_prompt->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->New_Pass_prompt->MaximizeBox = false;
			this->New_Pass_prompt->MinimizeBox = false;

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
			this->New_pass_update_button->Click += gcnew System::EventHandler(this, &MSP::Admin::Update_admin_creds);

			this->New_Pass_prompt->Controls->Add(this->New_pass_message_label);
			this->New_Pass_prompt->Controls->Add(this->New_Pass_tb);
			this->New_Pass_prompt->Controls->Add(this->New_Pass_Confirmation_tb);
			this->New_Pass_prompt->Controls->Add(this->New_pass_update_button);
			this->New_Pass_prompt->ShowDialog();
		}
	}
	private: System::Void Sub_button_Click(System::Object^ sender, System::EventArgs^ e) {
		mode = SUBJECTS;
		this->Hide();
		this->Controls->Clear();
		InitializeComponent_SectionManager();
		this->Show();
	}
	private: System::Void SubAllot_button_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		this->Controls->Clear();
		InitializeComponent_SubjectAllotment();
		this->Show();
	}
	private: System::Void Logout_button_Click(System::Object^ sender, System::EventArgs^ e) {
		// Only logout if the user selects yes on the confirmation box
		if (System::Windows::Forms::MessageBox::Show(L"Do you want to logout?", L"Login Confirmation", System::Windows::Forms::MessageBoxButtons::YesNo)
			== System::Windows::Forms::DialogResult::Yes)
			this->Close();
	}
	// Functions - Admin_homepage - end

	// Functions - Section_manager
	private: void load_buttons(int sec) {
		// Set visibility of section button to the given no of sections
		for (int i = 0; i < Max_Sections; i++) {
			if (sec > i) this->Section[i]->Visible = true;
			else this->Section[i]->Visible = false;

			if (mode != SUBJECTS) {
				if (sec == 1) this->Sec_del_button->Visible = false;
				else this->Sec_del_button->Visible = true;

				if (sec == Max_Sections) this->New_Sec_button->Visible = false;
				else this->New_Sec_button->Visible = true;
			}
		}

	}
	private: System::Void Select_Section(System::Object^ sender, System::EventArgs^ e) {
		// Set the index of the selected section button as the curr_sec
		curr_sec = stoi_c( Stos( static_cast<Control^>(sender)->Tag->ToString() ) );
		
		// Update settings file accordingly for saved.sections
		WriteSettings(Settings_Folder, Settings_File, saved);

		if (mode == SUBJECTS)
			open_subject_manager();
		else
			open_cred_winform();
	}
	private: System::Void Create_New_Section(System::Object^ sender, System::EventArgs^ e) {
		// Update the visibility and positions of the section buttons
		load_buttons(++saved.sections);
		
		// -1 cause saved.sections start from 1 and array indexes start from 0
		this->New_Sec_button->Left = this->Section[saved.sections - 1 ]->Left;
		this->Sec_del_button->Left = this->New_Sec_button->Left + 175;
		this->Back_from_Sec_button->Left = this->New_Sec_button->Left;

		this->Sec_del_button->Top = this->Section[saved.sections - 1]->Top;
		this->New_Sec_button->Top = this->Sec_del_button->Top + 35;
		if ( saved.sections != Max_Sections ) this->Back_from_Sec_button->Top = this->New_Sec_button->Top + 35;
		
		this->Sec_del_button->BringToFront();
		
	}
	private: System::Void Delete_a_Section(System::Object^ sender, System::EventArgs^ e) {
		// Update the visibility and positions of the section buttons
		load_buttons(--saved.sections);
		// -1 cause saved.sections start from 1 and array indexes start from 0
		this->New_Sec_button->Left = this->Section[saved.sections - 1]->Left;
		this->Sec_del_button->Left = this->New_Sec_button->Left + 175;
		this->Back_from_Sec_button->Left = this->New_Sec_button->Left;

		this->Sec_del_button->Top = this->Section[saved.sections - 1 ]->Top;
		this->New_Sec_button->Top = this->Sec_del_button->Top + 35;
		this->Back_from_Sec_button->Top = this->New_Sec_button->Top + 35;

		
		this->Sec_del_button->BringToFront();
	}
	private: System::Void open_cred_winform(System::Void) {
		this->Hide();
		this->Controls->Clear();

		InitializeComponent_CredentialsManager();
		Credential_manager_init();

		this->Show();
	}
	private: System::Void open_subject_manager(System::Void) {
		this->Hide();
		this->Controls->Clear();
		InitializeComponent_SubjectManager();
		this->Show();
	}
	// Functions - Section_manager - end

	// Functions - Credential_manager
	private: System::Void Credential_manager_init(System::Void) {
		// Load credential data from the arrays into the items
		for (int i = 0; i < Absolute_Max_sizes[mode]; i++) {
			credentials tmp;
			if (mode == STU)
				tmp = Stu_Cred[curr_sec][i];
			else if (mode == TEACH)
				tmp = Teach_Cred[i];
			this->ID_Cred_tb[i]->Text = stoS(tmp.id);
			this->Name_Cred_tb[i]->Text = stoS(tmp.name);
			this->Email_Cred_tb[i]->Text = stoS(tmp.username);
			this->Pass_Cred_tb[i]->Text = stoS(tmp.pass);
		}
	}
	// Functions - Credentials_manager - end

	// Functions = Subject Allotment
	private: void Subject_allotment_Load() {
		// Setup the labels according to teacher credentials
		for (int i = 0; i < Max_Teachers; i++) {
			this->ID_SubAllot_l[i]->Text = stoS(Teach_Cred[i].id);
			this->Name_SubAllot_l[i]->Text = stoS(Teach_Cred[i].name);
		}
		// Create a list of all possible selections / all currently existing classes.
		System::Collections::Generic::List<System::String^>^ All_classes = gcnew System::Collections::Generic::List<System::String^>();
		All_classes->Add(" ");
		for (int i = 0; i < Max_Subjects; i++) {
			for (int j = 0; j < saved.sections; j++) {
				if ( ! subjects_details[j][i].course_code.empty() && ! subjects_details[j][i].name.empty() )
					All_classes->Add(stoS(string("Section ") + Sec_list[j] + " - " + subjects_details[j][i].course_code + " - " + subjects_details[j][i].name));
			}
		}

		// Add all the possible drop-down menu options to each ComboBox seperately.
		for (int i = 0; i < Max_Teachers; i++) {
			for (int j = 0; j < Max_subject_per_teacher; j++) {
				this->Subject_SubAllot_cb[i][j]->Items->AddRange(All_classes->ToArray());
			}
		}

		int box_no[Max_Teachers] = { 0 }; // The current box number horizintally that we are dealing with
		for (int i = 0; i < saved.sections; i++) {
			for (int j = 0; j < Max_Subjects; j++) {
				int teacher = subjects_details[i][j].teach_no;
				// Create the string that is part of the ComboBox items from using the subject details struct and set that as the selected item.
				if (teacher != -1 && ! subjects_details[i][j].course_code.empty() && ! subjects_details[i][j].name.empty() ){
					String^ item = stoS(string("Section ") + Sec_list[i] + " - " + subjects_details[i][j].course_code + " - " + subjects_details[i][j].name);
					this->Subject_SubAllot_cb[teacher][box_no[teacher]]->SelectedItem = item;
					box_no[teacher]++;
				}
			}
		}
	}
	private: System::Void ComboBox_value_changed(System::Object^ sender, System::EventArgs^ e) {

		// Create a list having all the possible drop-down options
		System::Collections::Generic::List<System::String^>^ Available_classes = gcnew System::Collections::Generic::List<System::String^>();

		for (int i = 0; i < Max_Subjects; i++) {
			for (int j = 0; j < saved.sections; j++) {
				if ( ! subjects_details[j][i].course_code.empty()  && ! subjects_details[j][i].name.empty() )
					Available_classes->Add(stoS(string("Section ") + Sec_list[j] + " - " + subjects_details[j][i].course_code + " - " + subjects_details[j][i].name));
			}
		}

		// Cycle thorugh all the comboboxes
		for (int i = 0; i < Max_Teachers; i++) {
			for (int j = 0; j < Max_subject_per_teacher; j++) {
				// Create a copy of available classes for modification within this loop
				System::Collections::Generic::List<System::String^>^ Selected_classes = gcnew System::Collections::Generic::List<System::String^>();
				Selected_classes->AddRange(Available_classes);

				// Store the index of the current combobox
				int curr_teach = i, curr_sub = j;

				// Remove all those items from Selected_classes list which are present in the item list of the current ComboBox
				for (int k = 0; k < this->Subject_SubAllot_cb[curr_teach][curr_sub]->Items->Count; k++)
					Selected_classes->Remove(this->Subject_SubAllot_cb[curr_teach][curr_sub]->Items[k]->ToString());

				// From the first ComboBox till the last, recheck for all Selected boxes and remove those selected items from
				// the selected_classes list.
				for (int i = 0; i < Max_Teachers; i++) {
					for (int j = 0; j < Max_subject_per_teacher; j++) {
						if (this->Subject_SubAllot_cb[i][j]->SelectedIndex != -1)
							Selected_classes->Remove(this->Subject_SubAllot_cb[i][j]->SelectedItem->ToString());
					}
				}

				// Add all the missing entries i.e. those who haven't been selected in any combobox and are missing from current list.
				this->Subject_SubAllot_cb[curr_teach][curr_sub]->Items->AddRange(Selected_classes->ToArray());

				// If the current box has a value selected:
				if (this->Subject_SubAllot_cb[curr_teach][curr_sub]->SelectedIndex > 0) {
					String^ selection = this->Subject_SubAllot_cb[curr_teach][curr_sub]->SelectedItem->ToString();

					// Remove the entry that is selected in the current ComboBox from all the ComboBoxes except the current one.
					for (int i = 0; i < Max_Teachers; i++) {
						for (int j = 0; j < Max_subject_per_teacher; j++) {
							if (i != curr_teach || j != curr_sub)
								this->Subject_SubAllot_cb[i][j]->Items->Remove(selection);
						} // End inner - for (int j = 0; j < Max_subject_per_teacher; j++)
					} // End inner - for (int i = 0; i < Max_Teachers; i++)

				} // End - if (this->Subject_cb[curr_index]->SelectedIndex != -1

			} // End outer - for (int j = 0; j < Max_subject_per_teacher; j++)
		} // End outer - for (int i = 0; i < Max_Teachers; i++)

	} // End - ComboBox_value_changed
	// Functions = Subject Allotment - end

	// Functions - Subject Manager - start
	private: void Subjects_manager_Load() {
		// Load the data saved in the arrays into the items
		for (int i = 0; i < Max_Subjects; i++) {
			this->CourseCode_SubMgr_tb[i]->Text = stoS(subjects_details[curr_sec][i].course_code);
			this->Subject_SubMgr_tb[i]->Text = stoS(subjects_details[curr_sec][i].name);
			this->GradingSystem_SubMgr_cb[i]->SelectedItem = stoS(subjects_details[curr_sec][i].grading);
		}
	}
	// Functions - Subject Manager - end
	};
}
