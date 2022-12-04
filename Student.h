#pragma once
#include"functions.h"
#include"variables.h"

namespace MSP {

	///<summary>
	///Summary for Homepage
	///</summary>
	public ref class Student : public System::Windows::Forms::Form
	{
	public:
		Student(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		///<summary>
		///Clean up any resources being used.
		///</summary>
		~Student()
		{
			if (components)
			{
				delete components;
			}
		}

	// Student_homepage - items - start
	private: System::Windows::Forms::Label ^Student_hp_header, ^Background_info_hp, ^Student_hp_subheader, ^Name_subheader, 
											^Name_l, ^ID_subheader, ^ID_l, ^Sec_subheader, ^Sec_l, ^Email_subheader, ^Email_l;
	// Student_homepage - items - end

	// Menu - items - start
	private: System::Windows::Forms::PictureBox ^Menu_button_closed, ^Menu_button_open, ^Homescreen_menu_button, ^Attendance_menu_button,
												^Marks_menu_button, ^Resetpass_menu_button, ^Logout_menu_button;
	private: System::Windows::Forms::Label ^Homescreen_menu_label, ^Marks_menu_label, ^Attendance_menu_label, ^Resetpass_menu_label,
											^Logout_menu_label, ^New_pass_message_label;
	private: System::Windows::Forms::Form^ New_Pass_prompt;
	private: System::Windows::Forms::TextBox^ New_Pass_tb, ^New_Pass_Confirmation_tb;
	private: System::Windows::Forms::Button^ New_pass_update_button;

	// Menu - items - end

	// Student attendance - items - start
	private: System::Windows::Forms::Label^ Student_attendance_header, ^Progress_bar_background, ^Progress_bar_foreground;
	private: System::Windows::Forms::ComboBox^ Subject_selector_cb;

	private: array<array<System::Windows::Forms::Label^>^>^ Attendance_labels;
	private: array<System::Windows::Forms::Label^>^ Serial_labels = gcnew array<System::Windows::Forms::Label^>(Max_Weeks + 1);
	// Student attendance - items - end

	// Student marks - items - start
	private: System::Windows::Forms::Label^ Student_Marks_header, ^Grade_label;
	private: array<System::Windows::Forms::Label^>^ Marks_Headers;

	private: array<array<array<System::Windows::Forms::Label^>^>^>^ Exam_labels; // 3D array [exam][column][number]
	private: int sr_column = 0, obtained_column = 1, total_column = 2, average_column = 3, std_dev_column = 4, min_column = 5, max_column = 6, no_of_columns  = 7;
	private: array<int>^ Subheader_sizes = gcnew array<int>(6);
	private: array<bool>^ Subheaders_shown = gcnew array<bool>(6);
	// Student marks - items - end

	private:
		///<summary>
		///Required designer variable.
		///</summary>
		System::ComponentModel::Container^ components;

		// InitializeComponent_homepage
		void InitializeComponent(void)
		{
			// Initialize components with thehelp of their default constructors
			this->Student_hp_header = (gcnew System::Windows::Forms::Label());
			
			this->Background_info_hp = (gcnew System::Windows::Forms::Label());
			this->Student_hp_subheader = (gcnew System::Windows::Forms::Label());

			this->Name_subheader = (gcnew System::Windows::Forms::Label());
			this->Name_l = (gcnew System::Windows::Forms::Label());
			this->ID_subheader = (gcnew System::Windows::Forms::Label());
			this->ID_l = (gcnew System::Windows::Forms::Label());
			this->Sec_subheader = (gcnew System::Windows::Forms::Label());
			this->Sec_l = (gcnew System::Windows::Forms::Label());
			this->Email_subheader = (gcnew System::Windows::Forms::Label());
			this->Email_l = (gcnew System::Windows::Forms::Label());

			this->SuspendLayout();

			// 
			// Student_hp_header
			// 
			this->Student_hp_header->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Student_hp_header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Student_hp_header->Font = (gcnew System::Drawing::Font(L"Times New Roman", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Student_hp_header->Location = System::Drawing::Point(10, 20);
			this->Student_hp_header->Name = L"Student_hp_header";
			this->Student_hp_header->Size = System::Drawing::Size(700, 50);
			this->Student_hp_header->Text = L"Student Portal";
			this->Student_hp_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Background_info_hp
			// 
			this->Background_info_hp->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Background_info_hp->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->Background_info_hp->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Background_info_hp->Location = System::Drawing::Point(10, 125);
			this->Background_info_hp->Name = L"Background_info_hp";
			this->Background_info_hp->Size = System::Drawing::Size(700, 250);
			// 
			// Student_hp_subheader
			// 
			this->Student_hp_subheader->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.25F, System::Drawing::FontStyle::Bold));
			this->Student_hp_subheader->Location = System::Drawing::Point(34, 145);
			this->Student_hp_subheader->Name = L"Student_hp_subheader";
			this->Student_hp_subheader->Size = System::Drawing::Size(195, 35);
			this->Student_hp_subheader->Text = L"Personal Information : ";
			this->Student_hp_subheader->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;

			// 
			// Name_subheader
			// 
			this->Name_subheader->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name_subheader->Location = System::Drawing::Point(159, 205);
			this->Name_subheader->Name = L"Name_subheader";
			this->Name_subheader->Size = System::Drawing::Size(106, 23);
			this->Name_subheader->Text = L"Name :";
			this->Name_subheader->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Name_l
			// 
			this->Name_l->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Name_l->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name_l->Location = System::Drawing::Point(289, 205);
			this->Name_l->Name = L"Name_l";
			this->Name_l->Size = System::Drawing::Size(288, 23);
			this->Name_l->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ID_subheader
			// 
			this->ID_subheader->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ID_subheader->Location = System::Drawing::Point(159, 243);
			this->ID_subheader->Name = L"ID_subheader";
			this->ID_subheader->Size = System::Drawing::Size(106, 23);
			this->ID_subheader->Text = L"Roll no. :";
			this->ID_subheader->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ID_l
			// 
			this->ID_l->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->ID_l->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ID_l->Location = System::Drawing::Point(289, 243);
			this->ID_l->Name = L"ID_l";
			this->ID_l->Size = System::Drawing::Size(288, 23);
			this->ID_l->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Sec_subheader
			// 
			this->Sec_subheader->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Sec_subheader->Location = System::Drawing::Point(159, 286);
			this->Sec_subheader->Name = L"Sec_subheader";
			this->Sec_subheader->Size = System::Drawing::Size(106, 23);
			this->Sec_subheader->Text = L"Section :";
			this->Sec_subheader->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Sec_l
			// 
			this->Sec_l->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Sec_l->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Sec_l->Location = System::Drawing::Point(289, 286);
			this->Sec_l->Name = L"Sec_l";
			this->Sec_l->Size = System::Drawing::Size(288, 23);
			this->Sec_l->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Email_subheader
			// 
			this->Email_subheader->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Email_subheader->Location = System::Drawing::Point(159, 327);
			this->Email_subheader->Name = L"Email_subheader";
			this->Email_subheader->Size = System::Drawing::Size(106, 23);
			this->Email_subheader->Text = L"Email :";
			this->Email_subheader->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Email_l
			// 
			this->Email_l->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Email_l->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Email_l->Location = System::Drawing::Point(289, 327);
			this->Email_l->Name = L"Email_l";
			this->Email_l->Size = System::Drawing::Size(288, 23);
			this->Email_l->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			// 
			// Student
			// 
			this->AutoScroll = true;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(720, 450);
			
			this->Controls->Add(this->Student_hp_header);
			this->Controls->Add(this->Student_hp_subheader);
			this->Controls->Add(this->Name_subheader);
			this->Controls->Add(this->Name_l);
			this->Controls->Add(this->ID_subheader);
			this->Controls->Add(this->ID_l);
			this->Controls->Add(this->Sec_subheader);
			this->Controls->Add(this->Sec_l);
			this->Controls->Add(this->Email_l);
			this->Controls->Add(this->Email_subheader);
			this->Controls->Add(this->Background_info_hp);
			
			this->Name = L"Student";
			this->Text = L"Student menu";

			this->Student_Load();

			this->ResumeLayout(false);
			this->PerformLayout();
		}

		void InitializeComponent_Menu(void) {
			
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Student::typeid));

			this->Menu_button_closed = (gcnew System::Windows::Forms::PictureBox());
			this->Menu_button_open = (gcnew System::Windows::Forms::PictureBox());
			
			this->Homescreen_menu_label = (gcnew System::Windows::Forms::Label());
			this->Homescreen_menu_button = (gcnew System::Windows::Forms::PictureBox());
			
			this->Attendance_menu_button = (gcnew System::Windows::Forms::PictureBox());
			this->Attendance_menu_label = (gcnew System::Windows::Forms::Label());
			
			this->Marks_menu_button = (gcnew System::Windows::Forms::PictureBox());
			this->Marks_menu_label = (gcnew System::Windows::Forms::Label());
			
			this->Resetpass_menu_label = (gcnew System::Windows::Forms::Label());
			this->Resetpass_menu_button = (gcnew System::Windows::Forms::PictureBox());

			this->Logout_menu_label = (gcnew System::Windows::Forms::Label());
			this->Logout_menu_button = (gcnew System::Windows::Forms::PictureBox());

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Menu_button_closed))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Menu_button_open))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Homescreen_menu_button))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Attendance_menu_button))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Marks_menu_button))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Resetpass_menu_button))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Logout_menu_button))->BeginInit();

			this->SuspendLayout();

			// 
			// Homescreen_menu_button
			// 
			this->Homescreen_menu_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Homescreen_menu_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Homescreen_menu_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Homescreen_menu_Image")));
			this->Homescreen_menu_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->Homescreen_menu_button->Location = System::Drawing::Point(15, this->ClientSize.Height - 245);
			this->Homescreen_menu_button->Name = L"Homescreen_menu_button";
			this->Homescreen_menu_button->Size = System::Drawing::Size(35, 35);
			this->Homescreen_menu_button->Click += gcnew System::EventHandler(this, &Student::Homescreen_menu_click);
			this->Homescreen_menu_button->Visible = false;
			// 
			// Homescreen_menu_label
			// 
			this->Homescreen_menu_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Homescreen_menu_label->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Homescreen_menu_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.25F, System::Drawing::FontStyle::Bold));
			this->Homescreen_menu_label->Location = System::Drawing::Point(50, this->Homescreen_menu_button->Top);
			this->Homescreen_menu_label->Name = L"Homescreen_menu_label";
			this->Homescreen_menu_label->Size = System::Drawing::Size(120, 35);
			this->Homescreen_menu_label->Text = L"View Homescreen";
			this->Homescreen_menu_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->Homescreen_menu_label->Click += gcnew System::EventHandler(this, &Student::Homescreen_menu_click);
			this->Homescreen_menu_label->Visible = false;
			
			// 
			// Attendance_menu_button
			// 
			this->Attendance_menu_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Attendance_menu_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Attendance_menu_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Attendance_menu_Image")));
			this->Attendance_menu_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->Attendance_menu_button->Location = System::Drawing::Point(15, this->Homescreen_menu_button->Bottom + 5);
			this->Attendance_menu_button->Name = L"Attendance_menu_button";
			this->Attendance_menu_button->Size = System::Drawing::Size(35, 35);
			this->Attendance_menu_button->Click += gcnew System::EventHandler(this, &Student::Attendence_menu_click);
			this->Attendance_menu_button->Visible = false;
			// 
			// Attendance_menu_label
			// 
			this->Attendance_menu_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Attendance_menu_label->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Attendance_menu_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.25F, System::Drawing::FontStyle::Bold));
			this->Attendance_menu_label->Location = System::Drawing::Point(50, this->Attendance_menu_button->Top);
			this->Attendance_menu_label->Name = L"Attendance_menu_label";
			this->Attendance_menu_label->Size = System::Drawing::Size(120, 35);
			this->Attendance_menu_label->Text = L"View Attendance";
			this->Attendance_menu_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->Attendance_menu_label->Click += gcnew System::EventHandler(this, &Student::Attendence_menu_click);
			this->Attendance_menu_label->Visible = false;
			
			// 
			// Marks_menu_button
			// 
			this->Marks_menu_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Marks_menu_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Marks_menu_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Marks_menu_Image")));
			this->Marks_menu_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->Marks_menu_button->Location = System::Drawing::Point(15, this->Attendance_menu_button->Bottom + 5);
			this->Marks_menu_button->Name = L"Marks_menu_button";
			this->Marks_menu_button->Size = System::Drawing::Size(35, 35);
			this->Marks_menu_button->Click += gcnew System::EventHandler(this, &Student::Marks_menu_click);
			this->Marks_menu_button->Visible = false;
			// 
			// Marks_menu_label
			// 
			this->Marks_menu_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Marks_menu_label->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Marks_menu_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.25F, System::Drawing::FontStyle::Bold));
			this->Marks_menu_label->Location = System::Drawing::Point(50, this->Marks_menu_button->Top);
			this->Marks_menu_label->Name = L"Marks_menu_label";
			this->Marks_menu_label->Size = System::Drawing::Size(120, 35);
			this->Marks_menu_label->Text = L"View Marks";
			this->Marks_menu_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->Marks_menu_label->Click += gcnew System::EventHandler(this, &Student::Marks_menu_click);
			this->Marks_menu_label->Visible = false;
			
			// 
			// Resetpass_menu_button
			// 
			this->Resetpass_menu_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Resetpass_menu_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Resetpass_menu_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Resetpass_menu_Image")));
			this->Resetpass_menu_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->Resetpass_menu_button->Location = System::Drawing::Point(15, this->Marks_menu_button->Bottom + 5);
			this->Resetpass_menu_button->Name = L"Resetpass_menu_button";
			this->Resetpass_menu_button->Size = System::Drawing::Size(35, 35);
			this->Resetpass_menu_button->Click += gcnew System::EventHandler(this, &Student::Resetpass_menu_click);
			this->Resetpass_menu_button->Visible = false;
			// 
			// Resetpass_menu_label
			// 
			this->Resetpass_menu_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Resetpass_menu_label->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Resetpass_menu_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.25F, System::Drawing::FontStyle::Bold));
			this->Resetpass_menu_label->Location = System::Drawing::Point(50, this->Resetpass_menu_button->Top);
			this->Resetpass_menu_label->Name = L"Resetpass_menu_label";
			this->Resetpass_menu_label->Size = System::Drawing::Size(120, 35);
			this->Resetpass_menu_label->Text = L"Reset Password";
			this->Resetpass_menu_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->Resetpass_menu_label->Click += gcnew System::EventHandler(this, &Student::Resetpass_menu_click);
			this->Resetpass_menu_label->Visible = false;

			// 
			// Logout_menu_button
			// 
			this->Logout_menu_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Logout_menu_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Logout_menu_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Logout_menu_Image")));
			this->Logout_menu_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->Logout_menu_button->Location = System::Drawing::Point(15, this->Resetpass_menu_button->Bottom + 5);
			this->Logout_menu_button->Name = L"Logout_menu_button";
			this->Logout_menu_button->Size = System::Drawing::Size(35, 35);
			this->Logout_menu_button->Click += gcnew System::EventHandler(this, &Student::Logout_menu_click);
			this->Logout_menu_button->Visible = false;
			// 
			// Logout_menu_label
			// 
			this->Logout_menu_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Logout_menu_label->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Logout_menu_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.25F, System::Drawing::FontStyle::Bold));
			this->Logout_menu_label->Location = System::Drawing::Point(50, this->Logout_menu_button->Top);
			this->Logout_menu_label->Name = L"Logout_menu_label";
			this->Logout_menu_label->Size = System::Drawing::Size(120, 35);
			this->Logout_menu_label->Text = L"Logout";
			this->Logout_menu_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->Logout_menu_label->Click += gcnew System::EventHandler(this, &Student::Logout_menu_click);
			this->Logout_menu_label->Visible = false;
			
			// 
			// Menu_button_closed
			// 
			this->Menu_button_closed->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Menu_button_closed->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Menu_button_closed->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Menu_closed_button_Image")));
			this->Menu_button_closed->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Menu_button_closed->Location = System::Drawing::Point(15, this->Logout_menu_button->Bottom + 5);
			this->Menu_button_closed->Name = L"Menu_button_closed";
			this->Menu_button_closed->Size = System::Drawing::Size(35, 35);
			this->Menu_button_closed->TabStop = false;
			this->Menu_button_closed->Click += gcnew System::EventHandler(this, &Student::Menu_closed_button_Click);
			// 
			// Menu_button_open
			// 
			this->Menu_button_open->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Menu_button_open->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Menu_button_open->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Menu_open_button_Image")));
			this->Menu_button_open->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Menu_button_open->Location = System::Drawing::Point(15, this->Logout_menu_button->Bottom + 5);
			this->Menu_button_open->Name = L"Menu_button_open";
			this->Menu_button_open->Size = System::Drawing::Size(35, 35);
			this->Menu_button_open->Click += gcnew System::EventHandler(this, &Student::Menu_open_button_Click);
			this->Menu_button_open->Visible = false;
			
			// 
			// Menu
			// 
			this->Controls->Add(this->Homescreen_menu_label);
			this->Controls->Add(this->Homescreen_menu_button);
			
			this->Controls->Add(this->Attendance_menu_label);
			this->Controls->Add(this->Attendance_menu_button);
			
			this->Controls->Add(this->Marks_menu_label);
			this->Controls->Add(this->Marks_menu_button);

			this->Controls->Add(this->Resetpass_menu_button);
			this->Controls->Add(this->Resetpass_menu_label);

			this->Controls->Add(this->Logout_menu_button);
			this->Controls->Add(this->Logout_menu_label);

			this->Controls->Add(this->Menu_button_closed);
			this->Controls->Add(this->Menu_button_open);

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Homescreen_menu_button))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Attendance_menu_button))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Marks_menu_button))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Resetpass_menu_button))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Logout_menu_button))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Menu_button_closed))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Menu_button_open))->EndInit();

			this->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MSP::Student::OnScroll);
			this->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &MSP::Student::OnScroll);
			this->ClientSizeChanged += gcnew System::EventHandler(this, &MSP::Student::OnClientSizeChanged);

			this->ResumeLayout(false);
			this->PerformLayout();

			this->Menu_button_closed->BringToFront();
		}

		void InitializeComponent_Attendance(void) {
			// Setup current subject variable incase the subject drop-down menu is unselected
			if (curr_subject == -1)
				curr_subject = 0;

			this->Student_attendance_header = (gcnew System::Windows::Forms::Label());
			this->Subject_selector_cb = (gcnew System::Windows::Forms::ComboBox());

			this->Progress_bar_background = (gcnew System::Windows::Forms::Label());
			this->Progress_bar_foreground = (gcnew System::Windows::Forms::Label());

			for (int i = 0; i < Max_Weeks + 1; i++) {
				this->Serial_labels[i] = gcnew System::Windows::Forms::Label();
			}

			this->Attendance_labels = gcnew array<array<System::Windows::Forms::Label^>^>(Max_Weeks + 1);
			for (int i = 0; i < Max_Weeks + 1; i++) {
				this->Attendance_labels[i] = gcnew array<System::Windows::Forms::Label^>(Lec_per_Week);
				for (int j = 0; j < Lec_per_Week; j++)
					this->Attendance_labels[i][j] = gcnew System::Windows::Forms::Label();
			}

			// 
			// Student_attendance_header
			// 
			this->Student_attendance_header->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right);
			this->Student_attendance_header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Student_attendance_header->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Student_attendance_header->ForeColor = System::Drawing::Color::Black;
			this->Student_attendance_header->BackColor = System::Drawing::Color::White;
			this->Student_attendance_header->Location = System::Drawing::Point(10, 30);
			this->Student_attendance_header->Name = L"Student_attendance_header";
			this->Student_attendance_header->Size = System::Drawing::Size(700, 35);
			this->Student_attendance_header->Text = L"Student Attendance";
			this->Student_attendance_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			// 
			// Subject_selector_cb
			// 
			this->Subject_selector_cb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right);
			this->Subject_selector_cb->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->Subject_selector_cb->FormattingEnabled = true;
			this->Subject_selector_cb->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Subject_selector_cb->Location = System::Drawing::Point(410, this->Student_attendance_header->Bottom + 15);
			this->Subject_selector_cb->Name = L"Subject_selector_cb";
			this->Subject_selector_cb->Size = System::Drawing::Size(300, 30);
			this->Subject_selector_cb->TabStop = false;
			for (int i = 0; i < Max_Subjects; i++)
				if (subjects_details[curr_sec][i].course_code != "" && subjects_details[curr_sec][i].name != "")
					this->Subject_selector_cb->Items->Add(stoS(subjects_details[curr_sec][i].course_code + " - " + subjects_details[curr_sec][i].name));
			this->Subject_selector_cb->SelectedItem = stoS(subjects_details[curr_sec][curr_subject].course_code + " - " + subjects_details[curr_sec][curr_subject].name);
			this->Subject_selector_cb->Tag = "Attendance";
			this->Subject_selector_cb->SelectedIndexChanged += gcnew System::EventHandler(this, &Student::Change_subject);

			// 
			// Progress_bar_background
			// 
			this->Progress_bar_background->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right);
			this->Progress_bar_background->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->Progress_bar_background->BackColor = System::Drawing::Color::LightGray;
			this->Progress_bar_background->Location = System::Drawing::Point(10, this->Subject_selector_cb->Bottom + 15);
			this->Progress_bar_background->Name = L"Progress_bar_backround";
			this->Progress_bar_background->Size = System::Drawing::Size(704, 34);
			// 
			// Progress_bar_foreground
			// 
			this->Progress_bar_foreground->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left);
			this->Progress_bar_foreground->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->Progress_bar_foreground->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Progress_bar_foreground->ForeColor = System::Drawing::Color::White;
			this->Progress_bar_foreground->BackColor = System::Drawing::Color::RoyalBlue;
			this->Progress_bar_foreground->Location = System::Drawing::Point(12, this->Progress_bar_background->Top + 2);
			this->Progress_bar_foreground->Name = L"Progress_bar_backround";
			this->Progress_bar_foreground->Size = System::Drawing::Size(0, 30);
			this->Progress_bar_foreground->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;


			//
			// Serial_labels
			// 
			for (int i = 0; i < Max_Weeks + 1; i++) {
				this->Serial_labels[i]->Anchor = System::Windows::Forms::AnchorStyles::Top;
				this->Serial_labels[i]->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				this->Serial_labels[i]->ForeColor = System::Drawing::Color::Black;
				this->Serial_labels[i]->Name = stoS("Serial_label" + std::to_string(i));
				this->Serial_labels[i]->Size = System::Drawing::Size(100, 30);
				this->Serial_labels[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

				if (i == 0) {
					this->Serial_labels[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(0)));
					this->Serial_labels[i]->Text = L"Week no.";;
					this->Serial_labels[i]->Location = System::Drawing::Point(60, this->Progress_bar_background->Bottom + 15);
				}
				else {
					this->Serial_labels[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(0)));
					this->Serial_labels[i]->Text = stoS(std::to_string(i) + ")");
					this->Serial_labels[i]->Location = System::Drawing::Point(this->Serial_labels[i - 1]->Left, this->Serial_labels[i - 1]->Bottom + 5);
				}

			}
			//
			// Lecture_labels
			//
			for (int week_no = 0; week_no < Max_Weeks + 1; week_no++) {
				for (int lec_no = 0; lec_no < Lec_per_Week; lec_no++) {
					this->Attendance_labels[week_no][lec_no]->Anchor = System::Windows::Forms::AnchorStyles::Top;
					this->Attendance_labels[week_no][lec_no]->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
					this->Attendance_labels[week_no][lec_no]->ForeColor = System::Drawing::Color::Black;
					if (lec_no == 0)
						this->Attendance_labels[week_no][lec_no]->Location = System::Drawing::Point(this->Serial_labels[week_no]->Right + 5, this->Serial_labels[week_no]->Top);
					else
						this->Attendance_labels[week_no][lec_no]->Location = System::Drawing::Point(this->Attendance_labels[week_no][lec_no - 1]->Right + 5, this->Attendance_labels[week_no][lec_no - 1]->Top);
					this->Attendance_labels[week_no][lec_no]->Name = stoS("Att_label_Lec" + std::to_string(lec_no + 1) + "_Week_" + std::to_string(week_no));
					this->Attendance_labels[week_no][lec_no]->Size = System::Drawing::Size(250, 30);
					this->Attendance_labels[week_no][lec_no]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
					if (week_no == 0) {
						this->Attendance_labels[week_no][lec_no]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
							static_cast<System::Byte>(0)));
						this->Attendance_labels[week_no][lec_no]->Text = stoS("Lecture " + std::to_string(lec_no + 1));
					}
					else {
						this->Attendance_labels[week_no][lec_no]->BackColor = System::Drawing::Color::WhiteSmoke;
						this->Attendance_labels[week_no][lec_no]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
							static_cast<System::Byte>(0)));
					}
				}
			}
			
			//
			// Student Attendance
			//
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(720, 450);
			
			this->Controls->Add(this->Student_attendance_header);
			this->Controls->Add(this->Subject_selector_cb);
			this->Controls->Add(this->Progress_bar_background);
			this->Controls->Add(this->Progress_bar_foreground);
			this->Controls->AddRange(this->Serial_labels);
			for (int i = 0; i < Max_Weeks + 1; i++)
				this->Controls->AddRange(this->Attendance_labels[i]);
			this->Name = L"Student_attendance";
			this->Text = L"Student Attendance";
			attendance_reload();

			this->ResumeLayout(false);
			this->PerformLayout();
		}

		void InitializeComponent_Marks(void) {
			if (curr_subject < 0)
				curr_subject = 0;
			// Extra local variables
			const int Total_headers = 6;
			this->Subheader_sizes[0] = saved.quizzes[curr_subject][curr_sec];
			this->Subheader_sizes[1] = saved.assignments[curr_subject][curr_sec];
			this->Subheader_sizes[2] = 1;
			this->Subheader_sizes[3] = 1;
			this->Subheader_sizes[4] = 1;
			this->Subheader_sizes[5] = 1;
			
			std::string Header_Text[Total_headers] = { "Quiz(zes)", "Assignment(s)", "Sessional 1", "Sessional 2", "Final", "Total"};
			
			for (int i = 0; i < 6; i++)
				this->Subheaders_shown[i] = false;
			// Extra localvariables - end

			// Setup current subject variable incase the subject drop-down menu is unselected
			if (curr_subject == -1)
				curr_subject = 0;

			// Main winform header
			this->Student_Marks_header = gcnew System::Windows::Forms::Label();

			// Subject selector
			this->Subject_selector_cb = gcnew System::Windows::Forms::ComboBox();

			// Exam headers
			this->Marks_Headers = gcnew array<System::Windows::Forms::Label^>(Total_headers);
			for (int i = 0; i < Total_headers; i++)
				this->Marks_Headers[i] = gcnew System::Windows::Forms::Label();

			// Exam subheaders/labels
			this->Exam_labels = gcnew array<array<array<System::Windows::Forms::Label^>^>^>(Total_headers);
			for (int i = 0; i < Total_headers; i++) {
				this->Exam_labels[i] = gcnew array<array<System::Windows::Forms::Label^>^>(this->no_of_columns );
				for (int j = 0; j < this->no_of_columns ; j++)
					this->Exam_labels[i][j] = gcnew array<System::Windows::Forms::Label^>(Subheader_sizes[i] + 1);
			}
			for (int i = 0; i < Total_headers; i++)
				for (int j = 0; j < this->no_of_columns ; j++)
					for (int k = 0; k < Subheader_sizes[i] + 1; k++)
						this->Exam_labels[i][j][k] = (gcnew System::Windows::Forms::Label());

			// Grade label (to be displayed at the end)
			this->Grade_label = (gcnew System::Windows::Forms::Label());

			// 
			// Student_Marks_header
			// 
			this->Student_Marks_header->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right);
			this->Student_Marks_header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Student_Marks_header->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Student_Marks_header->Location = System::Drawing::Point(10, 15);
			this->Student_Marks_header->Name = L"Student_Marks_header";
			this->Student_Marks_header->Size = System::Drawing::Size(700, 30);
			this->Student_Marks_header->Text = L"Student Marks";
			this->Student_Marks_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			// 
			// Subject_selector_cb
			// 
			this->Subject_selector_cb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right);
			this->Subject_selector_cb->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->Subject_selector_cb->FormattingEnabled = true;
			this->Subject_selector_cb->Location = System::Drawing::Point(450, 70);
			this->Subject_selector_cb->Name = L"Subject_selector_cb";
			this->Subject_selector_cb->TabStop = false;
			this->Subject_selector_cb->Size = System::Drawing::Size(250, 25);
			for (int i = 0; i < Max_Subjects; i++)
				if (subjects_details[curr_sec][i].course_code != "" && subjects_details[curr_sec][i].name != "")
					this->Subject_selector_cb->Items->Add(stoS(subjects_details[curr_sec][i].course_code + " - " + subjects_details[curr_sec][i].name));
			this->Subject_selector_cb->Tag = "Marks";
			this->Subject_selector_cb->SelectedItem = stoS(subjects_details[curr_sec][curr_subject].course_code + " - " + subjects_details[curr_sec][curr_subject].name);
			this->Subject_selector_cb->SelectedIndexChanged += gcnew System::EventHandler(this, &Student::Change_subject);

			// 
			// Marks_Headers
			// 
			for (int i = 0; i < Total_headers; i++) {
				this->Marks_Headers[i]->Anchor = System::Windows::Forms::AnchorStyles::Top;
				this->Marks_Headers[i]->BackColor = System::Drawing::SystemColors::AppWorkspace;
				this->Marks_Headers[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Marks_Headers[i]->Location = System::Drawing::Point(20, 80);
				for (int j = 0; j < i; j++)
					this->Marks_Headers[i]->Top += (Subheader_sizes[j] + 1) * 30 + 60;
				this->Marks_Headers[i]->Name = stoS(Header_Text[i] + "_header");
				this->Marks_Headers[i]->Size = System::Drawing::Size(680, 30);
				this->Marks_Headers[i]->Text = stoS(Header_Text[i]);
				this->Marks_Headers[i]->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
				this->Marks_Headers[i]->Tag = i;
				this->Marks_Headers[i]->Click += gcnew System::EventHandler(this, &Student::Exam_header_click);
			}
			//
			// Assignment_labels
			//
			for (int i = 0; i < Total_headers; i++) {
				for (int j = 0; j < this->no_of_columns ; j++) {
					for (int k = 0; k < Subheader_sizes[i] + 1; k++) {
						this->Exam_labels[i][j][k]->Anchor = System::Windows::Forms::AnchorStyles::Top;
						this->Exam_labels[i][j][k]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.7F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
							static_cast<System::Byte>(0)));
						this->Exam_labels[i][j][k]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

						// Item's text + size
						if (j == 0) {
							this->Exam_labels[i][j][k]->Size = System::Drawing::Size(40, 25);
							if (k == 0)
								this->Exam_labels[i][j][k]->Text = L"Sr.";
							else
								this->Exam_labels[i][j][k]->Text = stoS(std::to_string(k) + ')');
						}
						else {
							this->Exam_labels[i][j][k]->Size = System::Drawing::Size(100, 25);
							if (k == 0) {
								if (j == 1)
									this->Exam_labels[i][j][k]->Text = L"Obtained";
								else if (j == 2)
									this->Exam_labels[i][j][k]->Text = L"Total";
								else if (j == 3)
									this->Exam_labels[i][j][k]->Text = L"Average";
								else if (j == 4)
									this->Exam_labels[i][j][k]->Text = L"Std dev";
								else if (j == 5)
									this->Exam_labels[i][j][k]->Text = L"Minimum";
								else if (j == 6)
									this->Exam_labels[i][j][k]->Text = L"Maximum";
							}
						}

						// Item's color
						if (k == 0) {
							this->Exam_labels[i][j][k]->BackColor = System::Drawing::Color::RoyalBlue;
							this->Exam_labels[i][j][k]->ForeColor = System::Drawing::Color::White;
						}
						else {
							this->Exam_labels[i][j][k]->BackColor = System::Drawing::Color::LightGray;
							this->Exam_labels[i][j][k]->ForeColor = System::Drawing::Color::Black;
						}

						// Visibility
						this->Exam_labels[i][j][k]->Visible = this->Subheaders_shown[i];
					}
				}
			}

			// Grade_label
			this->Grade_label->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Grade_label->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->Grade_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Grade_label->Left = this->Marks_Headers[Total_headers - 1]->Left;
			this->Grade_label->Name = L"Grade_label";
			this->Grade_label->Size = System::Drawing::Size(680, 30);

			this->Grade_label->Text = stoS("Grade : " + Student_marks[curr_sec][student_no].grade[curr_subject]);
			if (subjects_details[curr_sec][curr_subject].grading_enabled && subjects_details[curr_sec][curr_subject].course_code != "" && subjects_details[curr_sec][curr_subject].name != "")
				this->Grade_label->Visible = true;
			else
				this->Grade_label->Visible = false;
			this->Grade_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			// 
			// Student_marks
			// 
			this->AutoScroll = true;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(720, 450);
			this->Controls->Add(this->Student_Marks_header);
			
			this->Controls->Add(this->Subject_selector_cb);
			
			this->Controls->AddRange(this->Marks_Headers);
			this->Controls->Add(this->Grade_label);

			for (int i = 0; i < Total_headers; i++)
				for (int j = 0; j < this->no_of_columns ; j++)
					this->Controls->AddRange(this->Exam_labels[i][j]);

			this->Name = L"Student_Marks";
			this->Text = L"Student Marks";

			if (this->Subject_selector_cb->SelectedIndex != -1 )
				load_data();

			reload_button();

			this->ResumeLayout(false);
			this->PerformLayout();
		}
	
	// Student_homepage - functions
	private: void Student_Load() {
		// Load the appropriate data from thr arrays and initialize the floating menu
		this->Name_l->Text = stoS(Stu_Cred[curr_sec][student_no].name);
		this->ID_l->Text = stoS(Stu_Cred[curr_sec][student_no].id);
		this->Sec_l->Text = stoS(string("Section ") + Sec_list[curr_sec]);
		this->Email_l->Text = stoS(Stu_Cred[curr_sec][student_no].username);

		InitializeComponent_Menu();
	}
	// Student_homepage - functions	 - end
	
	// Menu - functions	
	private: System::Void OnClientSizeChanged(Object^ sender, System::EventArgs^ e) {
		reposition_menu_items();
		if (this->Controls->Contains(this->Progress_bar_foreground))
			attendance_reload();
	}
	private: System::Void OnScroll(Object^ sender, System::Windows::Forms::ScrollEventArgs^ e) {
		reposition_menu_items();
	}
	private: System::Void OnScroll(Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		reposition_menu_items();
	}
	private: void reposition_menu_items(void) {
		// Reset the vertical position of the menu icons to make sure they appear docked to the bottom-left corner
		this->Homescreen_menu_button->Top = this->ClientSize.Height - 245;
		this->Homescreen_menu_label->Top = this->Homescreen_menu_button->Top;
		this->Attendance_menu_button->Top = this->Homescreen_menu_button->Bottom + 5;
		this->Attendance_menu_label->Top = this->Attendance_menu_button->Top;
		this->Marks_menu_button->Top = this->Attendance_menu_button->Bottom + 5;
		this->Marks_menu_label->Top = this->Marks_menu_button->Top;
		this->Resetpass_menu_button->Top = this->Marks_menu_button->Bottom + 5;
		this->Resetpass_menu_label->Top = this->Resetpass_menu_button->Top;
		this->Logout_menu_button->Top = this->Resetpass_menu_button->Bottom + 5;
		this->Logout_menu_label->Top = this->Logout_menu_button->Top;
		this->Menu_button_closed->Top = this->Logout_menu_button->Bottom + 5;
		this->Menu_button_open->Top = this->Menu_button_closed->Top;
	}
	private: System::Void Update_student_creds(System::Object^ sender, System::EventArgs^ e) {
		// If the password in the 2 boxes match and the length is atleast 4 characters then update the password accordingly,
		// Otherwise let the user know, which check failed
		if (this->New_Pass_tb->Text == this->New_Pass_Confirmation_tb->Text && (this->New_Pass_tb->TextLength >= 4)) {
			Stu_Cred[curr_sec][student_no].pass = Stos(this->New_Pass_tb->Text);

			WriteCredentials(Student_Cred_Folder, string("Sec_") + Sec_list[curr_sec] + ".txt", Stu_Cred[curr_sec], Max_Students);

			this->New_Pass_prompt->Close();
		}
		else if (this->New_Pass_tb->TextLength < 4)
			System::Windows::Forms::MessageBox::Show("Pasword must be atleast 4 characters!");
		else if (this->New_Pass_tb->Text != this->New_Pass_Confirmation_tb->Text)
			System::Windows::Forms::MessageBox::Show("Paswords do not match. Please try again!");
	}
	private: System::Void Menu_closed_button_Click(System::Object^ sender, System::EventArgs^ e) {
		// Make all the items except the Menu_button_closed visible and bring then to front
		this->Homescreen_menu_button->Visible = true;
		this->Homescreen_menu_label->Visible = true;
		this->Attendance_menu_button->Visible = true;
		this->Attendance_menu_label->Visible = true;
		this->Marks_menu_button->Visible = true;
		this->Marks_menu_label->Visible = true;
		this->Resetpass_menu_button->Visible = true;
		this->Resetpass_menu_label->Visible = true;
		this->Logout_menu_button->Visible = true;
		this->Logout_menu_label->Visible = true;
		this->Menu_button_open->Visible = true;
		
		this->Menu_button_closed->Visible = false;
		
		this->Homescreen_menu_button->BringToFront();
		this->Homescreen_menu_label->BringToFront();
		this->Attendance_menu_button->BringToFront();
		this->Attendance_menu_label->BringToFront();
		this->Marks_menu_button->BringToFront();
		this->Marks_menu_label->BringToFront();
		this->Resetpass_menu_button->BringToFront();
		this->Resetpass_menu_label->BringToFront();
		this->Logout_menu_button->BringToFront();
		this->Logout_menu_label->BringToFront();
		this->Menu_button_open->BringToFront();
	}
	private: System::Void Menu_open_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Hide all the items except the Menu_button_closed and bring it to front
		this->Menu_button_closed->Visible = true;
		
		this->Menu_button_closed->BringToFront();
		
		this->Homescreen_menu_button->Visible = false;
		this->Homescreen_menu_label->Visible = false;
		this->Attendance_menu_button->Visible = false;
		this->Attendance_menu_label->Visible = false;
		this->Marks_menu_label->Visible = false;
		this->Marks_menu_button->Visible = false;
		this->Resetpass_menu_button->Visible = false;
		this->Resetpass_menu_label->Visible = false;
		this->Logout_menu_button->Visible = false;
		this->Logout_menu_label->Visible = false;
		this->Menu_button_open->Visible = false;
	}
	private: System::Void Homescreen_menu_click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		this->Controls->Clear();
		this->InitializeComponent();
		this->InitializeComponent_Menu();
		this->Show();
	}
	private: System::Void Attendence_menu_click(System::Object^ sender, System::EventArgs^ e) {
		// If the form is maximized. then temporarily return it to normal state for inititializing the componenets
		bool is_maximized = false;
		this->Hide();
		if (this->WindowState == System::Windows::Forms::FormWindowState::Maximized) {
			this->WindowState = System::Windows::Forms::FormWindowState::Normal;
			is_maximized = true;
		}
		this->Controls->Clear();
		this->InitializeComponent_Attendance();
		this->InitializeComponent_Menu();
		if ( is_maximized )
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
		this->Show();
	}
	private: System::Void Marks_menu_click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		this->Controls->Clear();
		this->InitializeComponent_Marks();
		this->InitializeComponent_Menu();
		this->Show();
	}
	private: System::Void Resetpass_menu_click(System::Object^ sender, System::EventArgs^ e) {
		// Initialize the components of the reset password sub form
		this->New_Pass_prompt = (gcnew System::Windows::Forms::Form());
		this->New_pass_message_label = (gcnew System::Windows::Forms::Label());
		this->New_Pass_tb = (gcnew System::Windows::Forms::TextBox());
		this->New_Pass_Confirmation_tb = (gcnew System::Windows::Forms::TextBox());
		this->New_pass_update_button = (gcnew System::Windows::Forms::Button());

		this->New_Pass_prompt->Size = System::Drawing::Size(250, 200);
		this->New_Pass_prompt->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
		this->New_Pass_prompt->Text = "Reset Password";
		this->New_Pass_prompt->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
		this->New_Pass_prompt->MinimizeBox = false; // Don't show the Minimize button on it
		this->New_Pass_prompt->MaximizeBox = false; // Don't show the Maximize button on it

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
		this->New_Pass_tb->Clear();

		this->New_Pass_Confirmation_tb->Size = System::Drawing::Size(200, 30);;
		this->New_Pass_Confirmation_tb->Location = System::Drawing::Point(25, 90);
		this->New_Pass_Confirmation_tb->UseSystemPasswordChar = true;
		this->New_Pass_Confirmation_tb->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->New_Pass_Confirmation_tb->Clear();

		this->New_pass_update_button->Text = "Update";
		this->New_pass_update_button->Location = System::Drawing::Point(175, 130);
		this->New_pass_update_button->Size = System::Drawing::Size(50, 20);
		this->New_pass_update_button->Click += gcnew System::EventHandler(this, &Student::Update_student_creds);
		this->New_Pass_prompt->AcceptButton = this->New_pass_update_button;

		this->New_Pass_prompt->Controls->Add(this->New_pass_message_label);
		this->New_Pass_prompt->Controls->Add(this->New_Pass_tb);
		this->New_Pass_prompt->Controls->Add(this->New_Pass_Confirmation_tb);
		this->New_Pass_prompt->Controls->Add(this->New_pass_update_button);
		this->New_Pass_prompt->ShowDialog();
	}
	private: System::Void Logout_menu_click(System::Object^ sender, System::EventArgs^ e) {
		if (System::Windows::Forms::MessageBox::Show(L"Do you want to logout?", L"Login Confirmation", System::Windows::Forms::MessageBoxButtons::YesNo)
			== System::Windows::Forms::DialogResult::Yes)
			this->Close();
	}
	// Menu - functions - end

	// Student_marks - functions
	private: void load_data(void) {
		// Sum up the marks of each activity for the whole class and calculate the Average, Std dev, min and max marks of each activity within this function
		float tmp_sum = 0, tmp_sq_sum = 0, min, max;
		
		// Quiz
		for (int i = 0; i < saved.quizzes[curr_subject][curr_sec]; i++) {
			tmp_sum = 0, tmp_sq_sum = 0, min, max;
			this->Exam_labels[Exam_quiz][this->obtained_column][i + 1]->Text = stoS(to_string_with_precision(Student_marks[curr_sec][student_no].quizzes[curr_subject][i], 2));
			this->Exam_labels[Exam_quiz][this->total_column][i + 1]->Text = stoS(to_string_with_precision(Max_marks[Exam_quiz], 2));
			for (int j = 0; j < Max_Students; j++) {
				if (j == 0) {
					min = Student_marks[curr_sec][j].quizzes[curr_subject][i];
					max = Student_marks[curr_sec][j].quizzes[curr_subject][i];
				}
				else {
					if (min > Student_marks[curr_sec][j].quizzes[curr_subject][i])
						min = Student_marks[curr_sec][j].quizzes[curr_subject][i];
					else if (max < Student_marks[curr_sec][j].quizzes[curr_subject][i])
						max = Student_marks[curr_sec][j].quizzes[curr_subject][i];
				}
				tmp_sum += Student_marks[curr_sec][j].quizzes[curr_subject][i];
				tmp_sq_sum += Student_marks[curr_sec][j].quizzes[curr_subject][i] * Student_marks[curr_sec][j].quizzes[curr_subject][i];
			}
			// If the activity hasn't been marked for any student then show '-' otherwise show the correct marks
			if (tmp_sum == 0) {
				this->Exam_labels[Exam_quiz][this->obtained_column][i + 1]->Text = L"-";
				this->Exam_labels[Exam_quiz][this->average_column][i + 1]->Text = L"-";
				this->Exam_labels[Exam_quiz][this->std_dev_column][i + 1]->Text = L"-";
				this->Exam_labels[Exam_quiz][this->min_column][i + 1]->Text = L"-";
				this->Exam_labels[Exam_quiz][this->max_column][i + 1]->Text = L"-";
			}
			else {
				this->Exam_labels[Exam_quiz][this->average_column][i + 1]->Text = stoS(to_string_with_precision(tmp_sum / Max_Students, 2));
				this->Exam_labels[Exam_quiz][this->std_dev_column][i + 1]->Text = stoS(to_string_with_precision(sqrt(tmp_sq_sum / Max_Students), 2));
				this->Exam_labels[Exam_quiz][this->min_column][i + 1]->Text = stoS(to_string_with_precision(min, 2));
				this->Exam_labels[Exam_quiz][this->max_column][i + 1]->Text = stoS(to_string_with_precision(max, 2));
			}
		}
		
		// Assignment
		for (int i = 0; i < saved.assignments[curr_subject][curr_sec]; i++) {
			tmp_sum = 0, tmp_sq_sum = 0, min, max;
			this->Exam_labels[Exam_assignment][this->obtained_column][i + 1]->Text = stoS(to_string_with_precision(Student_marks[curr_sec][student_no].assignment[curr_subject][i], 2));
			this->Exam_labels[Exam_assignment][this->total_column][i + 1]->Text = stoS(to_string_with_precision(Max_marks[Exam_assignment], 2));
			for (int j = 0; j < Max_Students; j++) {
				if (j == 0) {
					min = Student_marks[curr_sec][j].assignment[curr_subject][i];
					max = Student_marks[curr_sec][j].assignment[curr_subject][i];
				}
				else {
					if (min > Student_marks[curr_sec][j].assignment[curr_subject][i])
						min = Student_marks[curr_sec][j].assignment[curr_subject][i];
					else if (max < Student_marks[curr_sec][j].assignment[curr_subject][i])
						max = Student_marks[curr_sec][j].assignment[curr_subject][i];
				}
				tmp_sum += Student_marks[curr_sec][j].assignment[curr_subject][i];
				tmp_sq_sum += Student_marks[curr_sec][j].assignment[curr_subject][i] * Student_marks[curr_sec][j].assignment[curr_subject][i];
			}
			// If the activity hasn't been marked for any student then show '-' otherwise show the correct marks
			if (tmp_sum == 0) {
				this->Exam_labels[Exam_assignment][this->obtained_column][i + 1]->Text = L"-";
				this->Exam_labels[Exam_assignment][this->average_column][i + 1]->Text = L"-";
				this->Exam_labels[Exam_assignment][this->std_dev_column][i + 1]->Text = L"-";
				this->Exam_labels[Exam_assignment][this->min_column][i + 1]->Text = L"-";
				this->Exam_labels[Exam_assignment][this->max_column][i + 1]->Text = L"-";
			}
			else {
				this->Exam_labels[Exam_assignment][this->average_column][i + 1]->Text = stoS(to_string_with_precision(tmp_sum / Max_Students, 2));
				this->Exam_labels[Exam_assignment][this->std_dev_column][i + 1]->Text = stoS(to_string_with_precision(sqrt(tmp_sq_sum / Max_Students), 2));
				this->Exam_labels[Exam_assignment][this->min_column][i + 1]->Text = stoS(to_string_with_precision(min, 2));
				this->Exam_labels[Exam_assignment][this->max_column][i + 1]->Text = stoS(to_string_with_precision(max, 2));
			}
		}
		
		// Sessional 1
		this->Exam_labels[Exam_mid1][this->obtained_column][1]->Text = stoS(to_string_with_precision(Student_marks[curr_sec][student_no].mid1[curr_subject], 2));
		this->Exam_labels[Exam_mid1][this->total_column][1]->Text = stoS(to_string_with_precision(Max_marks[Exam_mid1], 2));
		tmp_sum = 0, tmp_sq_sum = 0, min, max;
		for (int j = 0; j < Max_Students; j++) {
			if (j == 0) {
				min = Student_marks[curr_sec][j].mid1[curr_subject];
				max = Student_marks[curr_sec][j].mid1[curr_subject];
			}
			else {
				if (min > Student_marks[curr_sec][j].mid1[curr_subject])
					min = Student_marks[curr_sec][j].mid1[curr_subject];
				else if (max < Student_marks[curr_sec][j].mid1[curr_subject])
					max = Student_marks[curr_sec][j].mid1[curr_subject];
			}
			tmp_sum += Student_marks[curr_sec][j].mid1[curr_subject];
			tmp_sq_sum += Student_marks[curr_sec][j].mid1[curr_subject] * Student_marks[curr_sec][j].mid1[curr_subject];
		}
		// If the activity hasn't been marked for any student then show '-' otherwise show the correct marks
		if (tmp_sum == 0) {
			this->Exam_labels[Exam_mid1][this->obtained_column][1]->Text = L"-";
			this->Exam_labels[Exam_mid1][this->average_column][1]->Text = L"-";
			this->Exam_labels[Exam_mid1][this->std_dev_column][1]->Text = L"-";
			this->Exam_labels[Exam_mid1][this->min_column][1]->Text = L"-";
			this->Exam_labels[Exam_mid1][this->max_column][1]->Text = L"-";
		}
		else {
			this->Exam_labels[Exam_mid1][this->average_column][1]->Text = stoS(to_string_with_precision(tmp_sum / Max_Students, 2));
			this->Exam_labels[Exam_mid1][this->std_dev_column][1]->Text = stoS(to_string_with_precision(sqrt(tmp_sq_sum / Max_Students), 2));
			this->Exam_labels[Exam_mid1][this->min_column][1]->Text = stoS(to_string_with_precision(min, 2));
			this->Exam_labels[Exam_mid1][this->max_column][1]->Text = stoS(to_string_with_precision(max, 2));
		}
		
		// Sessional 2
		this->Exam_labels[Exam_mid2][this->obtained_column][1]->Text = stoS(to_string_with_precision(Student_marks[curr_sec][student_no].mid2[curr_subject], 2));
		this->Exam_labels[Exam_mid2][this->total_column][1]->Text = stoS(to_string_with_precision(Max_marks[Exam_mid2], 2));
		tmp_sum = 0, tmp_sq_sum = 0, min, max;
		for (int j = 0; j < Max_Students; j++) {
			if (j == 0) {
				min = Student_marks[curr_sec][j].mid2[curr_subject];
				max = Student_marks[curr_sec][j].mid2[curr_subject];
			}
			else {
				if (min > Student_marks[curr_sec][j].mid2[curr_subject])
					min = Student_marks[curr_sec][j].mid2[curr_subject];
				else if (max < Student_marks[curr_sec][j].mid2[curr_subject])
					max = Student_marks[curr_sec][j].mid2[curr_subject];
			}
			tmp_sum += Student_marks[curr_sec][j].mid2[curr_subject];
			tmp_sq_sum += Student_marks[curr_sec][j].mid2[curr_subject] * Student_marks[curr_sec][j].mid2[curr_subject];
		}
		// If the activity hasn't been marked for any student then show '-' otherwise show the correct marks
		if (tmp_sum == 0) {
			this->Exam_labels[Exam_mid2][this->obtained_column][1]->Text = L"-";
			this->Exam_labels[Exam_mid2][this->average_column][1]->Text = L"-";
			this->Exam_labels[Exam_mid2][this->std_dev_column][1]->Text = L"-";
			this->Exam_labels[Exam_mid2][this->min_column][1]->Text = L"-";
			this->Exam_labels[Exam_mid2][this->max_column][1]->Text = L"-";
		}
		else {
			this->Exam_labels[Exam_mid2][this->average_column][1]->Text = stoS(to_string_with_precision(tmp_sum / Max_Students, 2));
			this->Exam_labels[Exam_mid2][this->std_dev_column][1]->Text = stoS(to_string_with_precision(sqrt(tmp_sq_sum / Max_Students), 2));
			this->Exam_labels[Exam_mid2][this->min_column][1]->Text = stoS(to_string_with_precision(min, 2));
			this->Exam_labels[Exam_mid2][this->max_column][1]->Text = stoS(to_string_with_precision(max, 2));
		}
		
		// Final
		this->Exam_labels[Exam_final][this->obtained_column][1]->Text = stoS(to_string_with_precision(Student_marks[curr_sec][student_no].final[curr_subject], 2));
		this->Exam_labels[Exam_final][this->total_column][1]->Text = stoS(to_string_with_precision(Max_marks[Exam_final], 2));
		tmp_sum = 0, tmp_sq_sum = 0, min, max;
		for (int j = 0; j < Max_Students; j++) {
			if (j == 0) {
				min = Student_marks[curr_sec][j].final[curr_subject];
				max = Student_marks[curr_sec][j].final[curr_subject];
			}
			else {
				if (min > Student_marks[curr_sec][j].final[curr_subject])
					min = Student_marks[curr_sec][j].final[curr_subject];
				else if (max < Student_marks[curr_sec][j].final[curr_subject])
					max = Student_marks[curr_sec][j].final[curr_subject];
			}
			tmp_sum += Student_marks[curr_sec][j].final[curr_subject];
			tmp_sq_sum += Student_marks[curr_sec][j].final[curr_subject] * Student_marks[curr_sec][j].final[curr_subject];
		}
		// If the activity hasn't been marked for any student then show '-' otherwise show the correct marks
		if (tmp_sum == 0) {
			this->Exam_labels[Exam_final][this->obtained_column][1]->Text = L"-";
			this->Exam_labels[Exam_final][this->average_column][1]->Text = L"-";
			this->Exam_labels[Exam_final][this->std_dev_column][1]->Text = L"-";
			this->Exam_labels[Exam_final][this->min_column][1]->Text = L"-";
			this->Exam_labels[Exam_final][this->max_column][1]->Text = L"-";
		}
		else {
			this->Exam_labels[Exam_final][this->average_column][1]->Text = stoS(to_string_with_precision(tmp_sum / Max_Students, 2));
			this->Exam_labels[Exam_final][this->std_dev_column][1]->Text = stoS(to_string_with_precision(sqrt(tmp_sq_sum / Max_Students), 2));
			this->Exam_labels[Exam_final][this->min_column][1]->Text = stoS(to_string_with_precision(min, 2));
			this->Exam_labels[Exam_final][this->max_column][1]->Text = stoS(to_string_with_precision(max, 2));
		}

		// Total
		this->Exam_labels[Exam_final+1][this->obtained_column][1]->Text = stoS(to_string_with_precision(Student_marks[curr_sec][student_no].total_obtained[curr_subject], 2));
		this->Exam_labels[Exam_final+1][this->total_column][1]->Text = stoS(to_string_with_precision(subjects_details[curr_sec][curr_subject].current_total, 2));
		tmp_sum = 0;
		for (int j = 0; j < Max_Students; j++)
			tmp_sum += Student_marks[curr_sec][j].total_obtained[curr_subject];

		// If no activity hasn been marked for any student then show '-' otherwise show the correct marks
		if (tmp_sum == 0) {
			this->Exam_labels[Exam_final+1][this->obtained_column][1]->Text = L"-";
			this->Exam_labels[Exam_final+1][this->average_column][1]->Text = L"-";
			this->Exam_labels[Exam_final+1][this->std_dev_column][1]->Text = L"-";
			this->Exam_labels[Exam_final+1][this->min_column][1]->Text = L"-";
			this->Exam_labels[Exam_final+1][this->max_column][1]->Text = L"-";
		}
		else {
			this->Exam_labels[Exam_final+1][this->average_column][1]->Text = stoS(to_string_with_precision(subjects_details[curr_sec][curr_subject].class_average, 2));
			this->Exam_labels[Exam_final+1][this->std_dev_column][1]->Text = stoS(to_string_with_precision(subjects_details[curr_sec][curr_subject].std_dev, 2));
			this->Exam_labels[Exam_final+1][this->min_column][1]->Text = stoS(to_string_with_precision(subjects_details[curr_sec][curr_subject].class_min, 2));
			this->Exam_labels[Exam_final+1][this->max_column][1]->Text = stoS(to_string_with_precision(subjects_details[curr_sec][curr_subject].class_max, 2));
		}
	}
	private: void reload_button(void) {

		// Set the correct postitions of the main headers and the subheaders
		// 0 : Quiz ; 1 : Assignment ; 2 : Mid1 ; 3 : Mid 2 ; 4 : Final ; 5 : Total
		for (int i = 0; i < 6; i++) {
			// Starting point of the first header is 120
			this->Marks_Headers[i]->Top = 120;
			//bool first = true;
			// From 0 till the current element number, check if the subheader / subtable is shown or not and adjust the position of the next tables accordingly
			for (int j = 0; j < i; j++) {
				if (this->Subheaders_shown[j]) //{
					this->Marks_Headers[i]->Top += (Subheader_sizes[j] + 1) * 30 + 60;
					//first = false;
				//}
				else //{
					this->Marks_Headers[i]->Top += 60;
					//first = false;
				//}
			}
		}

		// Set the correct postitions of the subheaders / subtable
		// 0 : Quiz ; 1 : Assignment ; 2 : Mid1 ; 3 : Mid 2 ; 4 : Final ; 5 : Total
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < this->no_of_columns ; j++) {
				for (int k = 0; k < Subheader_sizes[i] + 1; k++) {
					// If the current column is the first one then the x-position would be the starting point of the main header + 20
					// Otherwise it's the ending point of the prev column
					if (j == 0)
						this->Exam_labels[i][j][k]->Left = this->Marks_Headers[i]->Left + 20;
					else
						this->Exam_labels[i][j][k]->Left = this->Exam_labels[i][j - 1][k]->Right;

					// If the current row is the first one then the y-position would be the ending point of the main header
					// Otherwise it's the ending point of the prev row = 5
					if (k == 0)
						this->Exam_labels[i][j][k]->Top = this->Marks_Headers[i]->Bottom;
					else
						this->Exam_labels[i][j][k]->Top = this->Exam_labels[i][j][k - 1]->Bottom + 5;
				}
			}
		}
		
		// If the Total header is ecpanded then the y-pos for the grade label would be the ending of the subtable + 30
		// Otherwise, it will be the ending of the Total header + 30
		if (Subheaders_shown[Exam_final+1])
			this->Grade_label->Top = this->Exam_labels[Exam_final+1][this->no_of_columns  - 1][Subheader_sizes[Exam_final+1]]->Bottom + 30;
		else
			this->Grade_label->Top = this->Marks_Headers[Exam_final+1]->Bottom + 30;
		this->Grade_label->Left = this->Marks_Headers[5]->Left;

	}
	private: System::Void Exam_header_click(System::Object^ sender, System::EventArgs^ e) {
		// TODO: Can't we just store the vertical scroll and then reassign that ??
		// Reset the vertical position of the winform so as to not cause issues with placements
		this->VerticalScroll->Value = 0;

		// The index of the sender stored as the tag lets us know which one is to be expanded
		int exam_no = stoi_c(Stos(static_cast<System::Windows::Forms::Control^>(sender)->Tag->ToString()));
		// Toggle the visibility of the subtable/subheaders of the current control
		this->Subheaders_shown[exam_no] = !(this->Subheaders_shown[exam_no]);
		for (int j = 0; j < this->no_of_columns ; j++) {
			for (int k = 0; k < Subheader_sizes[exam_no] + 1; k++) {
				this->Exam_labels[exam_no][j][k]->Visible = !(this->Exam_labels[exam_no][j][k]->Visible);
			}
		}
		// Re-configure the position of the menus
		reload_button();

		// Adjust the position of menu items accordingly
		reposition_menu_items();

		// Bring the menu items to front accordingly
		if (this->Menu_button_closed->Visible)
			this->Menu_button_closed->BringToFront();
		else {
			this->Menu_button_open->BringToFront();
			this->Homescreen_menu_button->BringToFront();
			this->Attendance_menu_button->BringToFront();
			this->Marks_menu_button->BringToFront();
			this->Resetpass_menu_button->BringToFront();
			this->Logout_menu_button->BringToFront();
		}

	}
	// Student_marks - functions - end

	// Student_attendance - functions
	private: void attendance_reload() {
		// Only reload items if an item is selected in the subject selector combobox
		if (this->Subject_selector_cb->SelectedIndex != -1 ) {
			int presences = 0, absences = 0;
			curr_subject = this->Subject_selector_cb->SelectedIndex;

			// Position of the headers i.e. the 0th indexes of the columns
			for (int i = 0; i < Lec_per_Week; i++)
				if (i == 0) this->Attendance_labels[0][i]->Left = this->Serial_labels[0]->Right + 5;
				else this->Attendance_labels[0][i]->Left = this->Attendance_labels[0][i - 1]->Right + 5;

			for (int i = 0; i < Max_Weeks; i++)
			{
				// i+1 is used as the index for week because the 0th index is the header
				for (int j = 0; j < Lec_per_Week; j++) {
					// Calculate the no of absenses anf presences for % attendance
					// Change the color of the text according to whether it the state is present or absent
					if (Student_att[curr_sec][student_no].lec[curr_subject][i][j] == "Present") {
						presences++;
						this->Attendance_labels[i + 1][j]->ForeColor = System::Drawing::Color::Black;
					}
					else if (Student_att[curr_sec][student_no].lec[curr_subject][i][j] == "Absent") {
						absences++;
						this->Attendance_labels[i + 1][j]->ForeColor = System::Drawing::Color::Red;
					}
					else
						this->Attendance_labels[i + 1][j]->ForeColor = System::Drawing::Color::Black;

					this->Attendance_labels[i + 1][j]->Text = stoS(Student_att[curr_sec][student_no].lec[curr_subject][i][j]);
					// If the current box is the first lecture of the week then the x-position is 
					// linked to serial label otherwise it's linked to the prev label
					if (j == 0)
						this->Attendance_labels[i + 1][j]->Left = this->Serial_labels[i + 1]->Right + 5;
					else
						this->Attendance_labels[i + 1][j]->Left = this->Attendance_labels[i + 1][j - 1]->Right + 5;
				}
			}

			float percentage = float(presences) / (presences + absences);
			// Set the width of the foreground progress bar label accordingly
			this->Progress_bar_foreground->Width = int(percentage * (this->Progress_bar_background->Width - 2 * (this->Progress_bar_foreground->Left - this->Progress_bar_background->Left)));
			this->Progress_bar_foreground->Text = stoS(to_string_with_precision(percentage * 100, 2) + "%");
			this->Progress_bar_foreground->BringToFront();
		}
	}
	// Student_attendance - functions - end

	private: System::Void Change_subject(System::Object^ sender, System::EventArgs^ e) {
		// Only perform operations if an item is selected in the subject selector combobox
		if (this->Subject_selector_cb->SelectedIndex != -1 ) {
			int counter = -1;
			// Use a counter to keep track of the index the current subject is at in the combobox list
			for (int i = 0; i < Max_Subjects; i++)
				if (subjects_details[curr_sec][i].course_code != "" && subjects_details[curr_sec][i].name != "") {
					counter++;
					if (counter == this->Subject_selector_cb->SelectedIndex) {
						curr_subject = i;
						break;
					}
				}

			this->Hide();

			this->Controls->Clear();
			// Check which page are we currently working with and reinitialize that
			String^ page = static_cast<Control^>(sender)->Tag->ToString();
			if (page == "Attendance")
				this->InitializeComponent_Attendance();
			else if (page == "Marks")
				this->InitializeComponent_Marks();

			this->InitializeComponent_Menu();

			this->Show();

			reposition_menu_items();
		}
	}
	};
}
