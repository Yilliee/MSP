#pragma once
#include "variables.h"
#include "functions.h"

namespace MSP {

	using namespace System::Windows::Forms;
	using System::Void;
	using System::String;
	using System::Drawing::Point;
	using System::Collections::Generic::List;

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
	private: Label^ Admin_hp_header;
	private: Button^ Stu_button;
	private: Button^ Teach_button;
	private: Button^ Sub_button;
	private: Button^ SubAllot_button;
	private: Button^ Logout_button;
	// Admin_homepage - items - end
	
	// Section_manager - items - start
	private: Label^ Section_manager_header;
	private: Button^ Sec_del_button;
	private: Button^ New_Sec_button;
	private: Button^ Back_from_Sec_button;
	private: int new_sec_button_y = 121 + 31 * (saved.sections - 1);
	private: array<Button^>^ Section = gcnew array<Button^>(Max_Sections);
	// Section_manager - items - end

	// Credentials_manager - items - start
	private: array<Label^>^ Sr_Cred_l;
	private: array<TextBox^>^ ID_Cred_tb;
	private: array<TextBox^>^ Name_Cred_tb;
	private: array<TextBox^>^ Email_Cred_tb;
	private: array<TextBox^>^ Pass_Cred_tb;

	private: Label^ Mgmt_header;
	private: Button^ Save_button_Cred;
	private: Button^ Back_from_Cred_button;
	private: Label^ Email_Cred_header;
	private: Label^ Pass_Cred_header;
	// Credentials_manager - items - end

	// Credentials_manager + Subject_allotment + Subjects_manager - items - start
	private: Label^ Sr_header;
	private: Label^ ID_header;
	private: Label^ Name_header;
	// Credentials_manager + Subject_allotment + Subjects_manager - items - end
	
	// Subject allotment - items - start
	private: Label^ Sub_allot_header;
	private: array<Label^>^ Subject_SubAllot_header = gcnew array<Label^>(Max_subject_per_teacher);

	private: Button^ Back_from_SubAllot_button;
	private: Button^ Save_button_SubAllot;

	private: array<Label^>^ Sr_SubAllot_l = gcnew array<Label^>(Max_Teachers);
	private: array<Label^>^ ID_SubAllot_l = gcnew array<Label^>(Max_Teachers);
	private: array<Label^>^ Name_SubAllot_l = gcnew array<Label^>(Max_Teachers);
	private: array<ComboBox^>^ Subject_SubAllot_cb = gcnew array<ComboBox^>(Max_Teachers * Max_subject_per_teacher);
	// Subject allotment - items - end

	// Subjects_manager - items - start
	private: Label^ SubMgr_header;
	private: Button^ Save_button_SubMgr;
	private: Button^ Back_from_SubMgr_button;
	private: Label^ GradingSystem_SubMgr_header;
	private: array<Label^>^ Sr_SubMgr_l = gcnew array<Label^>(Max_Subjects);
	private: array<TextBox^>^ CourseCode_SubMgr_tb = gcnew array<TextBox^>(Max_Subjects);
	private: array<TextBox^>^ Subject_SubMgr_tb = gcnew array<TextBox^>(Max_Subjects);
	private: array<ComboBox^>^ GradingSystem_SubMgr_cb = gcnew array<ComboBox^>(Max_Subjects);
	// Subject_manager - items - end

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

				if (mode != SUBJECTS) {
					if (sec == 1) this->Sec_del_button->Visible = false;
					else this->Sec_del_button->Visible = true;
				
					if (sec == Max_Sections) this->New_Sec_button->Visible = false;
					else this->New_Sec_button->Visible = true;
				}
			}


		}
		// Section_manager - end

		// Admin homepage
		void InitializeComponent(void)
		{
			this->Admin_hp_header = (gcnew Label());
			this->Stu_button = (gcnew Button());
			this->Teach_button = (gcnew Button());
			this->Sub_button = (gcnew Button());
			this->SubAllot_button = (gcnew Button());
			this->Logout_button = (gcnew Button());
			
			this->SuspendLayout();
			
			// 
			// Admin_hp_header
			// 
			this->Admin_hp_header->Anchor = AnchorStyles::Top;
			this->Admin_hp_header->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Admin_hp_header->Location = System::Drawing::Point(9, 39);
			this->Admin_hp_header->Name = L"Admin_hp_header";
			this->Admin_hp_header->Size = System::Drawing::Size(701, 31);
			this->Admin_hp_header->TabIndex = 0;
			this->Admin_hp_header->Text = stoS("Welcome, " + Admin_Cred[admin_no].name);
			this->Admin_hp_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Stu_button
			// 
			this->Stu_button->Anchor = AnchorStyles::Top;
			this->Stu_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Stu_button->FlatStyle = FlatStyle::Popup;
			this->Stu_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Stu_button->Location = System::Drawing::Point(248, 120);
			this->Stu_button->Name = L"Stu_button";
			this->Stu_button->Size = System::Drawing::Size(229, 31);
			this->Stu_button->TabIndex = 1;
			this->Stu_button->Text = L"Manage Students";
			this->Stu_button->UseVisualStyleBackColor = false;
			this->Stu_button->Click += gcnew System::EventHandler(this, &Admin::Stu_button_Click);
			// 
			// Teach_button
			// 
			this->Teach_button->Anchor = AnchorStyles::Top;
			this->Teach_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Teach_button->FlatStyle = FlatStyle::Popup;
			this->Teach_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Teach_button->Location = System::Drawing::Point(248, 166);
			this->Teach_button->Name = L"Teach_button";
			this->Teach_button->Size = System::Drawing::Size(229, 31);
			this->Teach_button->TabIndex = 2;
			this->Teach_button->Text = L"Manage Teachers";
			this->Teach_button->UseVisualStyleBackColor = false;
			this->Teach_button->Click += gcnew System::EventHandler(this, &Admin::Teach_button_Click);
			// 
			// Sub_button
			// 
			this->Sub_button->Anchor = AnchorStyles::Top;
			this->Sub_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Sub_button->FlatStyle = FlatStyle::Popup;
			this->Sub_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Sub_button->Location = System::Drawing::Point(248, 212);
			this->Sub_button->Name = L"Sub_button";
			this->Sub_button->Size = System::Drawing::Size(229, 31);
			this->Sub_button->TabIndex = 3;
			this->Sub_button->Text = L"Manage Subjects";
			this->Sub_button->UseVisualStyleBackColor = false;
			this->Sub_button->Click += gcnew System::EventHandler(this, &Admin::Sub_button_Click);
			// 
			// Logout_button
			// 
			this->Logout_button->Anchor = AnchorStyles::Top;
			this->Logout_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Logout_button->FlatStyle = FlatStyle::Popup;
			this->Logout_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Logout_button->Location = System::Drawing::Point(248, 303);
			this->Logout_button->Name = L"Logout_button";
			this->Logout_button->Size = System::Drawing::Size(229, 31);
			this->Logout_button->TabIndex = 5;
			this->Logout_button->Text = L"Logout";
			this->Logout_button->UseVisualStyleBackColor = false;
			this->Logout_button->Click += gcnew System::EventHandler(this, &Admin::Logout_button_Click);
			// 
			// SubAllot_button
			// 
			this->SubAllot_button->Anchor = AnchorStyles::Top;
			this->SubAllot_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->SubAllot_button->FlatStyle = FlatStyle::Popup;
			this->SubAllot_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SubAllot_button->Location = System::Drawing::Point(248, 258);
			this->SubAllot_button->Name = L"SubAllot_button";
			this->SubAllot_button->Size = System::Drawing::Size(229, 31);
			this->SubAllot_button->TabIndex = 4;
			this->SubAllot_button->Text = L"Subject Allotment";
			this->SubAllot_button->UseVisualStyleBackColor = false;
			this->SubAllot_button->Click += gcnew System::EventHandler(this, &Admin::SubAllot_button_Click);

			// 
			// Admin
			// 
			this->AutoScroll = true;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(719, 363);
			this->Controls->Add(this->Admin_hp_header);
			this->Controls->Add(this->Stu_button);
			this->Controls->Add(this->Teach_button);
			this->Controls->Add(this->Sub_button);
			this->Controls->Add(this->SubAllot_button);
			this->Controls->Add(this->Logout_button);
			this->Name = L"Admin";
			this->Text = L"Admin";
			this->Load += gcnew System::EventHandler(this, &Admin::Admin_Load);
			this->ResumeLayout(false);

		} // Admin_homepage - end
		// Admin homepage - end

		// Section Manager
		void InitializeComponent_SectionManager(void)
		{
			this->Section_manager_header = (gcnew Label());
			this->Sec_del_button = (gcnew Button());
			this->New_Sec_button = (gcnew Button());
			this->Back_from_Sec_button = (gcnew Button());

			for (int i = 0; i < Max_Sections; i++) {
				this->Section[i] = (gcnew Button());
			}

			this->SuspendLayout();
			// 
			// Section_manager_header
			// 
			this->Section_manager_header->Anchor = AnchorStyles::Top;
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
			int y_pos = 90, tab_index = 1;
			for (int i = 0; i < Max_Sections; i++) {
				this->Section[i]->Anchor = AnchorStyles::Top; //static_cast<AnchorStyles>(AnchorStyles::Top);// | AnchorStyles::Right | AnchorStyles::Left);
				this->Section[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				this->Section[i]->FlatStyle = FlatStyle::Popup;
				this->Section[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Section[i]->Location = System::Drawing::Point(225, y_pos);
				this->Section[i]->Name = stoS(Stos("Sec ") + Sec_list[i] + "_button");
				this->Section[i]->Size = System::Drawing::Size(200, 25);
				this->Section[i]->TabIndex = tab_index++;
				this->Section[i]->Text = stoS(Stos("Section ") + Sec_list[i]);
				this->Section[i]->UseVisualStyleBackColor = false;
				this->Section[i]->Tag = i;
				this->Section[i]->Click += gcnew System::EventHandler(this, &Admin::Select_Section);
				y_pos += 35;
			}


			// 
			// Sec_del_button
			// 
			this->Sec_del_button->Anchor = AnchorStyles::Top; //static_cast<AnchorStyles>(AnchorStyles::Top);// | AnchorStyles::Right | AnchorStyles::Left);
			this->Sec_del_button->BackColor = System::Drawing::Color::Red;
			this->Sec_del_button->FlatStyle = FlatStyle::Popup;
			this->Sec_del_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Sec_del_button->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->Sec_del_button->Location = System::Drawing::Point(Section[saved.sections - 1]->Left + (Section[saved.sections - 1]->Width-25), Section[saved.sections - 1]->Top);
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
			this->New_Sec_button->Anchor = AnchorStyles::Top; //static_cast<AnchorStyles>(AnchorStyles::Top);// | AnchorStyles::Right | AnchorStyles::Left);
			this->New_Sec_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->New_Sec_button->FlatStyle = FlatStyle::Popup;
			this->New_Sec_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->New_Sec_button->Location = System::Drawing::Point(Section[saved.sections - 1]->Left, Sec_del_button->Top+35);
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
			this->Back_from_Sec_button->Anchor = AnchorStyles::Top;//static_cast<AnchorStyles>(AnchorStyles::Top);// | AnchorStyles::Right | AnchorStyles::Left);
			this->Back_from_Sec_button->BackColor = System::Drawing::Color::Lavender;
			this->Back_from_Sec_button->FlatStyle = FlatStyle::Popup;
			this->Back_from_Sec_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			if (mode != SUBJECTS)
				this->Back_from_Sec_button->Location = System::Drawing::Point(New_Sec_button->Left, New_Sec_button->Top + 35);
			else
				this->Back_from_Sec_button->Location = System::Drawing::Point((Section[saved.sections - 1]->Left), Section[saved.sections - 1]->Top + 35);
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
			for (int i = 0; i < Max_Sections; i++)
				this->Controls->Add(this->Section[i]);

			this->Name = L"Section_manager";
			this->Text = L"Section Management";
			load_buttons(saved.sections);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		// InitializeComponent_Section_manager - end

		// Credentials Manager
		void InitializeComponent_CredentialsManager(void)
		{
			this->Mgmt_header = (gcnew Label());
			this->Save_button_Cred = (gcnew Button());
			this->Back_from_Cred_button = (gcnew Button());
			
			this->Sr_header = (gcnew Label());
			this->ID_header = (gcnew Label());
			this->Name_header = (gcnew Label());
			this->Email_Cred_header = (gcnew Label());
			this->Pass_Cred_header = (gcnew Label());

			this->Sr_Cred_l = gcnew array<Label^>(Absolute_Max_sizes[mode]);
			this->ID_Cred_tb = gcnew array<TextBox^>(Absolute_Max_sizes[mode]);;
			this->Name_Cred_tb = gcnew array<TextBox^>(Absolute_Max_sizes[mode]);;
			this->Email_Cred_tb = gcnew array<TextBox^>(Absolute_Max_sizes[mode]);;
			this->Pass_Cred_tb = gcnew array<TextBox^>(Absolute_Max_sizes[mode]);;

			for (int i = 0; i < Absolute_Max_sizes[mode]; i++) {
				this->Sr_Cred_l[i] = gcnew Label();
				this->ID_Cred_tb[i] = gcnew TextBox();
				this->Name_Cred_tb[i] = gcnew TextBox();
				this->Email_Cred_tb[i] = gcnew TextBox();
				this->Pass_Cred_tb[i] = gcnew TextBox();
			}

			this->SuspendLayout();
			
			// 
			// Mgmt_header
			// 
			this->Mgmt_header->Anchor = AnchorStyles::Top;
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
			this->Save_button_Cred->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
			this->Save_button_Cred->BackColor = System::Drawing::Color::Lavender;
			this->Save_button_Cred->FlatStyle = FlatStyle::Popup;
			this->Save_button_Cred->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Save_button_Cred->Location = System::Drawing::Point(660, 61);
			this->Save_button_Cred->Name = L"Save_button";
			this->Save_button_Cred->Size = System::Drawing::Size(100, 23);
			this->Save_button_Cred->TabIndex = 1;
			this->Save_button_Cred->Text = L"Save";
			this->Save_button_Cred->UseVisualStyleBackColor = false;
			this->Save_button_Cred->Click += gcnew System::EventHandler(this, &Admin::Save_button_Cred_Click);
			// 
			// Back_from_cred_button
			//
			this->Back_from_Cred_button->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
			this->Back_from_Cred_button->BackColor = System::Drawing::Color::Lavender;
			this->Back_from_Cred_button->FlatStyle = FlatStyle::Popup;
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
			this->Sr_header->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
			this->Sr_header->BorderStyle = BorderStyle::FixedSingle;
			this->Sr_header->FlatStyle = FlatStyle::Popup;
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
			this->ID_header->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
			this->ID_header->BorderStyle = BorderStyle::FixedSingle;
			this->ID_header->FlatStyle = FlatStyle::Popup;
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
			this->Name_header->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
			this->Name_header->BorderStyle = BorderStyle::FixedSingle;
			this->Name_header->FlatStyle = FlatStyle::Popup;
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
			this->Email_Cred_header->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
			this->Email_Cred_header->BorderStyle = BorderStyle::FixedSingle;
			this->Email_Cred_header->FlatStyle = FlatStyle::Popup;
			this->Email_Cred_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Email_Cred_header->Location = System::Drawing::Point(this->Name_header->Left + this->Name_header->Width + 5, this->Name_header->Top);
			this->Email_Cred_header->Name = L"Email_h";
			this->Email_Cred_header->Size = System::Drawing::Size(200, 25);
			this->Email_Cred_header->TabIndex = 5;
			this->Email_Cred_header->Text = L"Email";
			this->Email_Cred_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Pass_header
			// 
			this->Pass_Cred_header->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left);
			this->Pass_Cred_header->BorderStyle = BorderStyle::FixedSingle;
			this->Pass_Cred_header->FlatStyle = FlatStyle::Popup;
			this->Pass_Cred_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Pass_Cred_header->Location = System::Drawing::Point(this->Email_Cred_header->Left + this->Email_Cred_header->Width + 5, 93);
			this->Pass_Cred_header->Name = L"Pass_h";
			this->Pass_Cred_header->Size = System::Drawing::Size(200, 25);
			this->Pass_Cred_header->TabIndex = 6;
			this->Pass_Cred_header->Text = L"Password";
			this->Pass_Cred_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			// 
			// Serial labels
			// 
			int y_pos = 124, inc = 31, tab_index = 7;
			for (int i = 0; i < Absolute_Max_sizes[mode]; i++) {
				this->Sr_Cred_l[i]->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
				this->Sr_Cred_l[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Sr_Cred_l[i]->Location = System::Drawing::Point(5, y_pos);
				this->Sr_Cred_l[i]->Name = stoS("Sr_" + std::to_string(i + 1));
				this->Sr_Cred_l[i]->Size = System::Drawing::Size(35, 25);
				this->Sr_Cred_l[i]->TabIndex = tab_index;
				this->Sr_Cred_l[i]->Text = stoS(std::to_string(i + 1) + ')');
				this->Sr_Cred_l[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				y_pos += inc;
				tab_index += 4;
			}
			//
			// Roll no
			//
			y_pos = 124, inc = 31, tab_index = 8;
			for (int i = 0; i < Absolute_Max_sizes[mode]; i++) {
				this->ID_Cred_tb[i]->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
				this->ID_Cred_tb[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				this->ID_Cred_tb[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->ID_Cred_tb[i]->Location = System::Drawing::Point(this->Sr_Cred_l[i]->Left + this->Sr_Cred_l[i]->Width + 5, y_pos);
				this->ID_Cred_tb[i]->Name = stoS("Name_" + std::to_string(i + 1));
				this->ID_Cred_tb[i]->Size = System::Drawing::Size(100, 25);
				this->ID_Cred_tb[i]->TabIndex = tab_index;
				this->ID_Cred_tb[i]->TextAlign = HorizontalAlignment::Center;
				y_pos += inc;
				tab_index += 4;
			}
			//
			// Student name 
			//
			y_pos = 124, inc = 31, tab_index = 9;
			for (int i = 0; i < Absolute_Max_sizes[mode]; i++) {
				this->Name_Cred_tb[i]->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
				this->Name_Cred_tb[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				this->Name_Cred_tb[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Name_Cred_tb[i]->Location = System::Drawing::Point(this->ID_Cred_tb[i]->Left + this->ID_Cred_tb[i]->Width + 5, y_pos);
				this->Name_Cred_tb[i]->Name = stoS("Name_" + std::to_string(i + 1));
				this->Name_Cred_tb[i]->Size = System::Drawing::Size(200, 25);
				this->Name_Cred_tb[i]->TabIndex = tab_index;
				this->Name_Cred_tb[i]->TextAlign = HorizontalAlignment::Center;
				y_pos += inc;
				tab_index += 4;
			}
			//
			// Email
			//
			y_pos = 124, inc = 31, tab_index = 10;
			for (int i = 0; i < Absolute_Max_sizes[mode]; i++) {
				this->Email_Cred_tb[i]->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left);
				this->Email_Cred_tb[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				this->Email_Cred_tb[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Email_Cred_tb[i]->Location = System::Drawing::Point(this->Name_Cred_tb[i]->Left + this->Name_Cred_tb[i]->Width + 5, y_pos);
				this->Email_Cred_tb[i]->Name = stoS("Name_" + std::to_string(i + 1));
				this->Email_Cred_tb[i]->Size = System::Drawing::Size(200, 25);
				this->Email_Cred_tb[i]->TabIndex = tab_index;
				this->Email_Cred_tb[i]->TextAlign = HorizontalAlignment::Center;
				y_pos += inc;
				tab_index += 4;
			}
			//
			// Pass
			//
			y_pos = 124, inc = 31, tab_index = 11;
			for (int i = 0; i < Absolute_Max_sizes[mode]; i++) {
				this->Pass_Cred_tb[i]->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
				this->Pass_Cred_tb[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				this->Pass_Cred_tb[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Pass_Cred_tb[i]->Location = System::Drawing::Point(this->Email_Cred_tb[i]->Left + this->Email_Cred_tb[i]->Width + 5, y_pos);
				this->Pass_Cred_tb[i]->Name = stoS("Pass_" + std::to_string(i + 1));
				this->Pass_Cred_tb[i]->Size = System::Drawing::Size(200, 25);
				this->Pass_Cred_tb[i]->TabIndex = tab_index;
				this->Pass_Cred_tb[i]->TextAlign = HorizontalAlignment::Center;
				y_pos += inc;
				tab_index += 4;
			}

			// 
			// Credential_management
			// 
			this->AutoScroll = true;
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
			else if (mode == SUBJECTS) {
				this->Name = L"Subjects_management";
				this->Text = L"Subjects management";
			}
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		// Credentials Manager - end

		// Subject allotment
		void InitializeComponent_SubjectAllotment(void)
		{
			this->Sub_allot_header = (gcnew Label());
			this->Sr_header = (gcnew Label());
			this->ID_header = (gcnew Label());
			this->Name_header = (gcnew Label());

			for (int i = 0; i < Max_subject_per_teacher; i++) {
				this->Subject_SubAllot_header[i] = (gcnew Label());
			}

			this->Back_from_SubAllot_button = (gcnew Button());
			this->Save_button_SubAllot = (gcnew Button());

			for (int i = 0; i < Max_Teachers; i++) {
				this->Sr_SubAllot_l[i] = (gcnew Label());
				this->ID_SubAllot_l[i] = (gcnew Label());
				this->Name_SubAllot_l[i] = (gcnew Label());
			}

			for (int i = 0; i < Max_Teachers; i++) {
				for (int j = 0; j < Max_subject_per_teacher; j++) {
					this->Subject_SubAllot_cb[i * Max_subject_per_teacher + j] = (gcnew ComboBox());
				}
			}

			this->SuspendLayout();

			// 
			// Sub_allot header
			// 
			this->Sub_allot_header->Anchor = AnchorStyles::Top;
			this->Sub_allot_header->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->Sub_allot_header->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Sub_allot_header->Location = System::Drawing::Point(10, 20);
			this->Sub_allot_header->Name = L"SubAllot_header";
			this->Sub_allot_header->Size = System::Drawing::Size(1210, 31);
			this->Sub_allot_header->TabIndex = 0;
			this->Sub_allot_header->Text = L"Subject Allotment";
			this->Sub_allot_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			// 
			// Back button
			//
			this->Back_from_SubAllot_button->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
			this->Back_from_SubAllot_button->BackColor = System::Drawing::Color::Lavender;
			this->Back_from_SubAllot_button->FlatStyle = FlatStyle::Popup;
			this->Back_from_SubAllot_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Back_from_SubAllot_button->Location = System::Drawing::Point(5, 61);
			this->Back_from_SubAllot_button->Name = L"Back_button";
			this->Back_from_SubAllot_button->Size = System::Drawing::Size(100, 23);
			this->Back_from_SubAllot_button->TabIndex = 1;
			this->Back_from_SubAllot_button->Text = L"Back";
			this->Back_from_SubAllot_button->UseVisualStyleBackColor = false;
			this->Back_from_SubAllot_button->Click += gcnew System::EventHandler(this, &Admin::back_to_homepage);
			// 
			// Save button
			//
			this->Save_button_SubAllot->Anchor = static_cast<AnchorStyles>(AnchorStyles::Right | AnchorStyles::Top);
			this->Save_button_SubAllot->BackColor = System::Drawing::Color::Lavender;
			this->Save_button_SubAllot->FlatStyle = FlatStyle::Popup;
			this->Save_button_SubAllot->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Save_button_SubAllot->Location = System::Drawing::Point(1225, 61);
			this->Save_button_SubAllot->Name = L"Save_button";
			this->Save_button_SubAllot->Size = System::Drawing::Size(100, 23);
			this->Save_button_SubAllot->TabIndex = 1;
			this->Save_button_SubAllot->Text = L"Save";
			this->Save_button_SubAllot->UseVisualStyleBackColor = false;
			this->Save_button_SubAllot->Click += gcnew System::EventHandler(this, &Admin::Save_button_SubAllot_Click);

			//
			// Sr header
			// 
			this->Sr_header->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
			this->Sr_header->BorderStyle = BorderStyle::FixedSingle;
			this->Sr_header->FlatStyle = FlatStyle::Popup;
			this->Sr_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Sr_header->Location = System::Drawing::Point(5, 93);
			this->Sr_header->Name = L"Sr_l_h";
			this->Sr_header->Size = System::Drawing::Size(35, 25);
			this->Sr_header->TabIndex = 2;
			this->Sr_header->Text = L"Sr.";
			this->Sr_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			//
			// ID header
			// 
			this->ID_header->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
			this->ID_header->BorderStyle = BorderStyle::FixedSingle;
			this->ID_header->FlatStyle = FlatStyle::Popup;
			this->ID_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ID_header->Location = System::Drawing::Point(this->Sr_header->Left + this->Sr_header->Width + 5, this->Sr_header->Top);
			this->ID_header->Name = L"ID_header";
			this->ID_header->Size = System::Drawing::Size(75, 25);
			this->ID_header->TabIndex = 3;
			this->ID_header->Text = L"ID";
			this->ID_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Name header
			// 
			this->Name_header->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
			this->Name_header->BorderStyle = BorderStyle::FixedSingle;
			this->Name_header->FlatStyle = FlatStyle::Popup;
			this->Name_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name_header->Location = System::Drawing::Point(this->ID_header->Left + this->ID_header->Width + 5, this->ID_header->Top);
			this->Name_header->Name = L"Name_h";
			this->Name_header->Size = System::Drawing::Size(175, 25);
			this->Name_header->TabIndex = 4;
			this->Name_header->Text = L"Teacher Name";
			this->Name_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Subject header(s)
			// 
			int x_pos_sub = this->Name_header->Left + this->Name_header->Width + 5, tab_index = 5;
			for (int i = 0; i < Max_subject_per_teacher; i++) {
				this->Subject_SubAllot_header[i]->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
				this->Subject_SubAllot_header[i]->BorderStyle = BorderStyle::FixedSingle;
				this->Subject_SubAllot_header[i]->FlatStyle = FlatStyle::Popup;
				this->Subject_SubAllot_header[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Subject_SubAllot_header[i]->Location = System::Drawing::Point(x_pos_sub, this->ID_header->Top);
				this->Subject_SubAllot_header[i]->Name = stoS("Subject_header_" + std::to_string(i + 1));
				this->Subject_SubAllot_header[i]->Size = System::Drawing::Size(200, 25);
				this->Subject_SubAllot_header[i]->TabIndex = tab_index;
				this->Subject_SubAllot_header[i]->Text = stoS("Subject " + std::to_string(i + 1));
				this->Subject_SubAllot_header[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				x_pos_sub += this->Subject_SubAllot_header[i]->Width + 5;
				tab_index++;
			}

			// 
			// Sr label 
			// 
			int y_pos = 124;
			tab_index = 5 + Max_subject_per_teacher;
			for (int i = 0; i < Max_Teachers; i++) {
				this->Sr_SubAllot_l[i]->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
				this->Sr_SubAllot_l[i]->BorderStyle = BorderStyle::FixedSingle;
				this->Sr_SubAllot_l[i]->FlatStyle = FlatStyle::Popup;
				this->Sr_SubAllot_l[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Sr_SubAllot_l[i]->Location = System::Drawing::Point(5, y_pos);
				this->Sr_SubAllot_l[i]->Name = stoS("Sr_l_" + std::to_string(i + 1));
				this->Sr_SubAllot_l[i]->Size = System::Drawing::Size(35, 25);
				this->Sr_SubAllot_l[i]->TabIndex = tab_index;
				this->Sr_SubAllot_l[i]->Text = stoS(std::to_string(i + 1) + ")");
				this->Sr_SubAllot_l[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				y_pos += this->Sr_SubAllot_l[i]->Height + 6;
				tab_index += 3 + Max_subject_per_teacher;
			}
			//
			// ID label
			//
			y_pos = 124, tab_index = 6 + Max_subject_per_teacher;
			for (int i = 0; i < Max_Teachers; i++) {
				this->ID_SubAllot_l[i]->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
				this->ID_SubAllot_l[i]->BorderStyle = BorderStyle::FixedSingle;
				this->ID_SubAllot_l[i]->FlatStyle = FlatStyle::Popup;
				this->ID_SubAllot_l[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->ID_SubAllot_l[i]->Location = System::Drawing::Point(this->Sr_SubAllot_l[i]->Right + 5, y_pos);
				this->ID_SubAllot_l[i]->Name = stoS("ID_l_" + std::to_string(i + 1));
				this->ID_SubAllot_l[i]->Size = System::Drawing::Size(75, this->Sr_SubAllot_l[i]->Height);
				this->ID_SubAllot_l[i]->TabIndex = tab_index;
				this->ID_SubAllot_l[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				y_pos += this->ID_SubAllot_l[i]->Height + 6;
				tab_index += 3 + Max_subject_per_teacher;
			}
			//
			// Name label
			//
			y_pos = 124, tab_index = 7 + Max_subject_per_teacher;
			for (int i = 0; i < Max_Teachers; i++) {
				this->Name_SubAllot_l[i]->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
				this->Name_SubAllot_l[i]->BorderStyle = BorderStyle::FixedSingle;
				this->Name_SubAllot_l[i]->FlatStyle = FlatStyle::Popup;
				this->Name_SubAllot_l[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Name_SubAllot_l[i]->Location = System::Drawing::Point(this->ID_SubAllot_l[i]->Right + 5, y_pos);
				this->Name_SubAllot_l[i]->Name = stoS("Name_l_" + std::to_string(i + 1));
				this->Name_SubAllot_l[i]->Size = System::Drawing::Size(175, this->ID_SubAllot_l[i]->Height);
				this->Name_SubAllot_l[i]->TabIndex = tab_index;
				this->Name_SubAllot_l[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				y_pos += this->Name_SubAllot_l[i]->Height + 6;
				tab_index += 3 + Max_subject_per_teacher;
			}
			//
			// Subject ComboBox
			//
			y_pos = 124, tab_index = 8 + Max_subject_per_teacher;
			for (int i = 0; i < Max_Teachers; i++) {
				int x_pos_cb = this->Name_SubAllot_l[i]->Right + 5;
				for (int j = 0; j < Max_subject_per_teacher; j++) {
					this->Subject_SubAllot_cb[(i * Max_subject_per_teacher) + j]->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
					this->Subject_SubAllot_cb[(i * Max_subject_per_teacher) + j]->BackColor = System::Drawing::Color::WhiteSmoke;
					this->Subject_SubAllot_cb[(i * Max_subject_per_teacher) + j]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(0)));
					this->Subject_SubAllot_cb[(i * Max_subject_per_teacher) + j]->DropDownStyle = ComboBoxStyle::DropDownList;
					this->Subject_SubAllot_cb[(i * Max_subject_per_teacher) + j]->Location = System::Drawing::Point(x_pos_cb, y_pos);
					this->Subject_SubAllot_cb[(i * Max_subject_per_teacher) + j]->Name = stoS("Week_" + std::to_string(i + 1) + "_lec1_h");
					this->Subject_SubAllot_cb[(i * Max_subject_per_teacher) + j]->Size = System::Drawing::Size(200, this->ID_SubAllot_l[i]->Height);
					this->Subject_SubAllot_cb[(i * Max_subject_per_teacher) + j]->TabIndex = tab_index;
					this->Subject_SubAllot_cb[(i * Max_subject_per_teacher) + j]->SelectedIndexChanged += gcnew System::EventHandler(this, &Admin::ComboBox_value_changed);;
					x_pos_cb += this->Subject_SubAllot_cb[(i * Max_subject_per_teacher) + j]->Width + 5;
					tab_index++;
				}
				tab_index += 3;
				y_pos += this->Subject_SubAllot_cb[i * Max_subject_per_teacher]->Height + 6; // The first entry in the current line
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
			this->Controls->AddRange(Subject_SubAllot_header);
			this->Controls->AddRange(this->Sr_SubAllot_l);
			this->Controls->AddRange(this->ID_SubAllot_l);
			this->Controls->AddRange(this->Name_SubAllot_l);
			this->Controls->AddRange(this->Subject_SubAllot_cb);


			this->Name = L"Subject_allotment";
			this->Text = L"Subject_allotment";
			Subject_allotment_Load();
			this->ResumeLayout(false);

		}
		// Subject allotment - end

		void InitializeComponent_SubjectManager(void)
		{
			for (int i = 0; i < Max_Subjects; i++) {
				this->Sr_SubMgr_l[i] = gcnew Label();
				this->CourseCode_SubMgr_tb[i] = gcnew TextBox();
				this->Subject_SubMgr_tb[i] = gcnew TextBox();
				this->GradingSystem_SubMgr_cb[i] = gcnew ComboBox();
			}
			this->SubMgr_header = gcnew Label();

			this->Save_button_SubMgr = gcnew Button();
			this->Back_from_SubMgr_button = gcnew Button();

			this->Sr_header = gcnew Label();
			this->ID_header = gcnew Label();
			this->Name_header = gcnew Label();
			this->GradingSystem_SubMgr_header = gcnew Label();
			this->SuspendLayout();

			// 
			// Subject_mgmt_header
			// 
			this->SubMgr_header->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
			this->SubMgr_header->BorderStyle = BorderStyle::FixedSingle;
			this->SubMgr_header->FlatStyle = FlatStyle::Popup;
			this->SubMgr_header->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SubMgr_header->Location = System::Drawing::Point(5, 20);
			this->SubMgr_header->Name = L"Subject_mgmt_h";
			this->SubMgr_header->Size = System::Drawing::Size(745, 35);
			this->SubMgr_header->TabIndex = 0;
			this->SubMgr_header->Text = L"Subject Management";
			this->SubMgr_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			// 
			// Save_button
			//
			this->Save_button_SubMgr->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
			this->Save_button_SubMgr->BackColor = System::Drawing::Color::Lavender;
			this->Save_button_SubMgr->FlatStyle = FlatStyle::Popup;
			this->Save_button_SubMgr->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Save_button_SubMgr->Location = System::Drawing::Point(650, 61);
			this->Save_button_SubMgr->Name = L"Save_button";
			this->Save_button_SubMgr->Size = System::Drawing::Size(100, 23);
			this->Save_button_SubMgr->TabIndex = 1;
			this->Save_button_SubMgr->Text = L"Save";
			this->Save_button_SubMgr->UseVisualStyleBackColor = false;
			this->Save_button_SubMgr->Click += gcnew System::EventHandler(this, &Admin::Save_SubMgr_button_Click);
			// 
			// Back_from_cred_button
			//
			this->Back_from_SubMgr_button->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
			this->Back_from_SubMgr_button->BackColor = System::Drawing::Color::Lavender;
			this->Back_from_SubMgr_button->FlatStyle = FlatStyle::Popup;
			this->Back_from_SubMgr_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Back_from_SubMgr_button->Location = System::Drawing::Point(5, 61);
			this->Back_from_SubMgr_button->Name = L"Back_button";
			this->Back_from_SubMgr_button->Size = System::Drawing::Size(101, 23);
			this->Back_from_SubMgr_button->TabIndex = 1;
			this->Back_from_SubMgr_button->Text = L"Back";
			this->Back_from_SubMgr_button->UseVisualStyleBackColor = false;
			this->Back_from_SubMgr_button->Click += gcnew System::EventHandler(this, &Admin::back_to_section_manager);

			// 
			// Sr_header
			// 
			this->Sr_header->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
			this->Sr_header->BorderStyle = BorderStyle::FixedSingle;
			this->Sr_header->FlatStyle = FlatStyle::Popup;
			this->Sr_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Sr_header->Location = System::Drawing::Point(5, 93);
			this->Sr_header->Name = L"Sr_l_h";
			this->Sr_header->Size = System::Drawing::Size(35, 25);
			this->Sr_header->TabIndex = 2;
			this->Sr_header->Text = L"Sr.";
			this->Sr_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			//
			// ID_header (Course Code)
			// 
			this->ID_header->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
			this->ID_header->BorderStyle = BorderStyle::FixedSingle;
			this->ID_header->FlatStyle = FlatStyle::Popup;
			this->ID_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ID_header->Location = System::Drawing::Point(45, 93);
			this->ID_header->Name = L"Course_code_h";
			this->ID_header->Size = System::Drawing::Size(250, 25);
			this->ID_header->TabIndex = 3;
			this->ID_header->Text = L"Course code";
			this->ID_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			//
			// (Subject_)Name_header
			// 
			this->Name_header->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
			this->Name_header->BorderStyle = BorderStyle::FixedSingle;
			this->Name_header->FlatStyle = FlatStyle::Popup;
			this->Name_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name_header->Location = System::Drawing::Point(300, 93);
			this->Name_header->Name = L"Subject_h";
			this->Name_header->Size = System::Drawing::Size(250, 25);
			this->Name_header->TabIndex = 4;
			this->Name_header->Text = L"Subject";
			this->Name_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			//
			// Grading_system_h
			// 
			this->GradingSystem_SubMgr_header->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
			this->GradingSystem_SubMgr_header->BorderStyle = BorderStyle::FixedSingle;
			this->GradingSystem_SubMgr_header->FlatStyle = FlatStyle::Popup;
			this->GradingSystem_SubMgr_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GradingSystem_SubMgr_header->Location = System::Drawing::Point(555, 93);
			this->GradingSystem_SubMgr_header->Name = L"Grading_h";
			this->GradingSystem_SubMgr_header->Size = System::Drawing::Size(200, 25);
			this->GradingSystem_SubMgr_header->TabIndex = 5;
			this->GradingSystem_SubMgr_header->Text = L"Grading System";
			this->GradingSystem_SubMgr_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			// 
			// Serial labels
			// 
			int y_pos = 124, inc = 31, tab_index = 6;
			for (int i = 0; i < Max_Subjects; i++) {
				this->Sr_SubMgr_l[i]->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
				this->Sr_SubMgr_l[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Sr_SubMgr_l[i]->Location = System::Drawing::Point(5, y_pos);
				this->Sr_SubMgr_l[i]->Name = stoS("Sr_" + std::to_string(i + 1));
				this->Sr_SubMgr_l[i]->Size = System::Drawing::Size(35, 25);
				this->Sr_SubMgr_l[i]->TabIndex = tab_index;
				this->Sr_SubMgr_l[i]->Text = stoS(std::to_string(i + 1) + ')');
				this->Sr_SubMgr_l[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				y_pos += inc;
				tab_index += 4;
			}
			//
			// Course code
			//
			y_pos = 124, inc = 31, tab_index = 7;
			for (int i = 0; i < Max_Subjects; i++) {
				this->CourseCode_SubMgr_tb[i]->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
				this->CourseCode_SubMgr_tb[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				this->CourseCode_SubMgr_tb[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->CourseCode_SubMgr_tb[i]->Location = System::Drawing::Point(this->Sr_SubMgr_l[i]->Left + this->Sr_SubMgr_l[i]->Width + 5, y_pos);
				this->CourseCode_SubMgr_tb[i]->Name = stoS("Course_code_no" + std::to_string(i + 1));
				this->CourseCode_SubMgr_tb[i]->Size = System::Drawing::Size(250, 25);
				this->CourseCode_SubMgr_tb[i]->TabIndex = tab_index;
				this->CourseCode_SubMgr_tb[i]->TextAlign = HorizontalAlignment::Center;
				y_pos += inc;
				tab_index += 4;
			}
			//
			// Subject name 
			//
			y_pos = 124, inc = 31, tab_index = 8;
			for (int i = 0; i < Max_Subjects; i++) {
				this->Subject_SubMgr_tb[i]->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
				this->Subject_SubMgr_tb[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				this->Subject_SubMgr_tb[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Subject_SubMgr_tb[i]->Location = System::Drawing::Point(this->CourseCode_SubMgr_tb[i]->Left + this->CourseCode_SubMgr_tb[i]->Width + 5, y_pos);
				this->Subject_SubMgr_tb[i]->Name = stoS("Subject_" + std::to_string(i + 1));
				this->Subject_SubMgr_tb[i]->Size = System::Drawing::Size(250, 25);
				this->Subject_SubMgr_tb[i]->TabIndex = tab_index;
				this->Subject_SubMgr_tb[i]->TextAlign = HorizontalAlignment::Center;
				y_pos += inc;
				tab_index += 4;
			}
			//
			// Grading system
			//
			y_pos = 124, inc = 31, tab_index = 9;
			for (int i = 0; i < Max_Subjects; i++) {
				this->GradingSystem_SubMgr_cb[i]->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
				this->GradingSystem_SubMgr_cb[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				this->GradingSystem_SubMgr_cb[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->GradingSystem_SubMgr_cb[i]->DropDownStyle = ComboBoxStyle::DropDownList;
				this->GradingSystem_SubMgr_cb[i]->Location = System::Drawing::Point(this->Subject_SubMgr_tb[i]->Left + this->Subject_SubMgr_tb[i]->Width + 5, y_pos);
				this->GradingSystem_SubMgr_cb[i]->Name = stoS("Grading_" + std::to_string(i + 1));
				this->GradingSystem_SubMgr_cb[i]->Size = System::Drawing::Size(200, 25);
				this->GradingSystem_SubMgr_cb[i]->TabIndex = tab_index;
				this->GradingSystem_SubMgr_cb[i]->Items->AddRange(gcnew array<String^> {" ", "Absolute", "Relative"});
				y_pos += inc;
				tab_index += 4;
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

		}

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

		pin_ptr <credentials> Cred;
		if (mode == STU)
			Cred = &Stu_Cred[curr_sec][0];
		else if (mode == TEACH)
			Cred = &Teach_Cred[0];


		for (int i = 0; i < Absolute_Max_sizes[mode]; i++) {
			Cred[i].id = Stos(this->ID_Cred_tb[i]->Text);
			Cred[i].name = Stos(this->Name_Cred_tb[i]->Text);
			Cred[i].username = Stos(this->Email_Cred_tb[i]->Text);
			Cred[i].pass = Stos(this->Pass_Cred_tb[i]->Text);
			if (mode == STU) {
				Student_marks[curr_sec][i].id = Stu_Cred[curr_sec][i].id;
				Student_marks[curr_sec][i].name = Stu_Cred[curr_sec][i].name;
				Student_att[curr_sec][i].id = Stu_Cred[curr_sec][i].id;
				Student_att[curr_sec][i].name = Stu_Cred[curr_sec][i].name;
			}
		}
		
		if (mode == STU) {
			std::ofstream stu(Student_Cred_Folder + "Sec_" + Sec_list[curr_sec] + ".txt");
			WriteCredentials(stu, Stu_Cred[curr_sec], Max_Students);
			stu.close();

			stu.open(Marks_Folder + "Sec_" + Sec_list[curr_sec] + ".txt");
			WriteMarks(stu, Student_marks[curr_sec], Max_Students, subjects_details[curr_sec][curr_subject], Max_Subjects, Max_Quizzes, Max_Assignments);
			stu.close();

			stu.open(Attendance_Folder + "Sec_" + Sec_list[curr_sec] + ".txt");
			WriteAttendence(stu, Student_att[curr_sec], Max_Students, Max_Subjects, Max_Weeks);
			stu.close();
		}
		else if (mode == TEACH) {
			std::ofstream Teach(Teacher_Cred_File);
			WriteCredentials(Teach, Teach_Cred, sizeof(Teach_Cred) / sizeof(*Teach_Cred));
			Teach.close();
		}

		MessageBox::Show("Credentials Updated Successfully !");
	}
	private: System::Void Save_button_SubAllot_Click(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < Max_Teachers; i++) {
			for (int j = 0; j < Max_subject_per_teacher; j++) {
				// If the current ComboBox is selected:
				if (Subject_SubAllot_cb[i * Max_subject_per_teacher + j]->SelectedIndex != -1) {
					std::string course_and_section = Stos(Subject_SubAllot_cb[i * Max_subject_per_teacher + j]->SelectedItem->ToString());
					int section = -1, course = -1;
					for (int i = 0; i < saved.sections; i++) {
						// If the current section is the one which is present in the selected option of the ComboBox then store it
						if (course_and_section.find(Stos("Section ") + Sec_list[i]) != -1) {
							section = i;
							break;
						}
					}
					if (section == -1) // Handle the error if any
						MessageBox::Show("Selection : " + stoS(course_and_section) + " - section is -1");
					for (int i = 0; i < Max_Subjects; i++) {
						// If the current section is the one which is present in the selected option of the ComboBox then store it
						if (course_and_section.find(subjects_details[section][i].course_code) != -1) {
							course = i;
							break;
						}
					}
					if (course == -1) // Handle the error if any
						MessageBox::Show("Selection : " + stoS(course_and_section) + " - Section: " + Sec_list[section] + " - Course is -1");
					// If we have gotten both the section and subject indexes, then update the teacher no.
					subjects_details[section][course].teach_no = i;
				}
			} // End inner - for (int j = 0; j < Max_subject_per_teacher; j++)
		} // End inner - for (int i = 0; i < Max_Teachers; i++)

		// Update the Subject data in files
		for (int i = 0; i < saved.sections; i++) {
			std::ofstream sub_file(Subject_Folder + "Sec_" + Sec_list[i] + ".txt");
			WriteSubjects(sub_file, subjects_details[i], Max_Subjects);
		}

		MessageBox::Show("Subject allotment updated successfully !");
	}
	private: System::Void Save_SubMgr_button_Click(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < Max_Subjects; i++) {
			subjects_details[curr_sec][i].course_code = Stos(this->CourseCode_SubMgr_tb[i]->Text);
			subjects_details[curr_sec][i].name = Stos(this->Subject_SubMgr_tb[i]->Text);
			subjects_details[curr_sec][i].grading = Stos(this->GradingSystem_SubMgr_cb[i]->SelectedItem->ToString());
		}

		for (int i = 0; i < saved.sections; i++) {
			std::ofstream sub_file(Subject_Folder + "Sec_" + Sec_list[i] + ".txt");
			WriteSubjects(sub_file, subjects_details[i], Max_Subjects);
		}

		MessageBox::Show("Subject data updated successfully !");
	}
	// Save functions - end
	
	// Functions - Admin_homepage
	private: System::Void Admin_Load(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < saved.sections; i++) {
			std::ifstream sub_file(Subject_Folder + "Sec_" + Sec_list[i] + ".txt");
			ReadSubjects(sub_file, subjects_details[i], Max_Subjects);
		}
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
		if (MessageBox::Show(L"Do you want to logout?", L"Login Confirmation", MessageBoxButtons::YesNo)
				== System::Windows::Forms::DialogResult::Yes)
					this->Close();
	}
	// Functions - Admin_homepage - end

	// Functions - Section_manager
	private: System::Void Select_Section(System::Object^ sender, System::EventArgs^ e) {
		curr_sec = stoi( Stos( static_cast<Control^>(sender)->Tag->ToString() ) );
		update_settings();
		if (mode == SUBJECTS)
			open_subject_manager();
		else
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
	private: System::Void update_settings(Void) {
		std::ofstream settings(settings_file);
		WriteSettings(settings, saved);
		settings.close();
	}
	private: System::Void open_cred_winform(Void) {
		this->Hide();
		this->Controls->Clear();

		InitializeComponent_CredentialsManager();
		Credential_manager_init();

		this->Show();
	}
	private: System::Void open_subject_manager(Void) {
		this->Hide();
		this->Controls->Clear();
		InitializeComponent_SubjectManager();
		this->Show();
	}
	// Functions - Section_manager - end

	// Functions - Credential_manager
	private: System::Void Credential_manager_init(Void) {
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
		List<System::String^>^ All_classes = gcnew List<System::String^>();
		All_classes->Add(" ");
		for (int i = 0; i < Max_Subjects; i++) {
			for (int j = 0; j < saved.sections; j++) {
				All_classes->Add(stoS(Stos("Section ") + Sec_list[j] + " - " + subjects_details[j][i].course_code + " - " + subjects_details[j][i].name));
			}
		}

		// Add all the possible drop-down menu options to each ComboBox seperately.
		for (int i = 0; i < Max_Teachers; i++) {
			for (int j = 0; j < Max_subject_per_teacher; j++) {
				this->Subject_SubAllot_cb[(i * Max_subject_per_teacher) + j]->Items->AddRange(All_classes->ToArray());
			}
		}

		int box_no[Max_Teachers] = { 0 }; // The current box number horizintally that we are dealing with
		for (int i = 0; i < saved.sections; i++) {
			for (int j = 0; j < Max_Subjects; j++) {
				int teacher = subjects_details[i][j].teach_no;
				// Create the string that is part of the ComboBox items from using the subject details struct and set that as the selected item.
				String^ item = stoS(Stos("Section ") + Sec_list[i] + " - " + subjects_details[i][j].course_code + " - " + subjects_details[i][j].name);
				this->Subject_SubAllot_cb[teacher * Max_subject_per_teacher + box_no[teacher]]->SelectedItem = item;
				box_no[teacher]++;
			}
		}
	}
	private: System::Void ComboBox_value_changed(System::Object^ sender, System::EventArgs^ e) {

		List<System::String^>^ Available_classes = gcnew List<System::String^>();

		// Create a list having all the possible drop-down options
		for (int i = 0; i < Max_Subjects; i++) {
			for (int j = 0; j < saved.sections; j++) {
				Available_classes->Add(stoS(Stos("Section ") + Sec_list[j] + " - " + subjects_details[j][i].course_code + " - " + subjects_details[j][i].name));
			}
		}

		// Cycle thorugh all the comboboxes
		for (int i = 0; i < Max_Teachers; i++) {
			for (int j = 0; j < Max_subject_per_teacher; j++) {
				// Create a copy of available classes for modification within this loop
				List<System::String^>^ Selected_classes = gcnew List<System::String^>();
				Selected_classes->AddRange(Available_classes);

				// Store the index of the current combobox
				int curr_index = (i * Max_subject_per_teacher) + j;

				// Remove all those items from Selected_classes list which are present in the item list of the current ComboBox
				for (int k = 0; k < Subject_SubAllot_cb[curr_index]->Items->Count; k++)
					Selected_classes->Remove(Subject_SubAllot_cb[curr_index]->Items[k]->ToString());

				// From the first ComboBox till the last, recheck for all Selected boxes and remove those selected items from
				// the selected_classes list.
				for (int i = 0; i < Max_Teachers; i++) {
					for (int j = 0; j < Max_subject_per_teacher; j++) {
						if (Subject_SubAllot_cb[i * Max_subject_per_teacher + j]->SelectedIndex != -1)
							Selected_classes->Remove(Subject_SubAllot_cb[i * Max_subject_per_teacher + j]->SelectedItem->ToString());
					}
				}

				// Add all the missing entries i.e. those who haven't been selected in any combobox and are missing from current list.
				Subject_SubAllot_cb[curr_index]->Items->AddRange(Selected_classes->ToArray());

				// If the current box has a value selected:
				if (this->Subject_SubAllot_cb[curr_index]->SelectedIndex != -1 && this->Subject_SubAllot_cb[(i * Max_subject_per_teacher) + j]->SelectedItem->ToString() != " ") {
					String^ selection = this->Subject_SubAllot_cb[curr_index]->SelectedItem->ToString();

					// Remove the entry that is selected in the current ComboBox from all the ComboBoxes except the current one.
					for (int i = 0; i < Max_Teachers; i++) {
						for (int j = 0; j < Max_subject_per_teacher; j++) {
							if (i * Max_subject_per_teacher + j != curr_index)
								this->Subject_SubAllot_cb[(i * Max_subject_per_teacher) + j]->Items->Remove(selection);
						} // End inner - for (int j = 0; j < Max_subject_per_teacher; j++)
					} // End inner - for (int i = 0; i < Max_Teachers; i++)

				} // End - if (this->Subject_cb[curr_index]->SelectedIndex != -1

			} // End outer - for (int j = 0; j < Max_subject_per_teacher; j++)
		} // End outer - for (int i = 0; i < Max_Teachers; i++)

	} // End - ComboBox_value_changed
	// Functions = Subject Allotment - end

	// Functions - Subject Manager - start
	private: void Subjects_manager_Load() {
		for (int i = 0; i < Max_Subjects; i++) {
			this->CourseCode_SubMgr_tb[i]->Text = stoS(subjects_details[curr_sec][i].course_code);
			this->Subject_SubMgr_tb[i]->Text = stoS(subjects_details[curr_sec][i].name);
			this->GradingSystem_SubMgr_cb[i]->SelectedItem = stoS(subjects_details[curr_sec][i].grading);
		}
	}
	// Functions - Subject Manager - end
};
}
