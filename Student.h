#pragma once
#include"functions.h"
#include"variables.h"

namespace MSP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	///<summary>
	///Summary for Homepage
	///</summary>
	public ref class Student : public Form
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
	private: System::Windows::Forms::Label^ Student_hp_header;

	private: System::Windows::Forms::Label^ Background_info_hp;
	private: System::Windows::Forms::Label^ Student_hp_subheader;
	private: System::Windows::Forms::Label^ Name_subheader;
	private: System::Windows::Forms::Label^ Name_l;
	private: System::Windows::Forms::Label^ ID_subheader;
	private: System::Windows::Forms::Label^ ID_l;
	private: System::Windows::Forms::Label^ Sec_subheader;
	private: System::Windows::Forms::Label^ Sec_l;
	private: System::Windows::Forms::Label^ Email_subheader;
	private: System::Windows::Forms::Label^ Email_l;
	// Student_homepage - items - end

	// Menu - items - start
	private: System::Windows::Forms::PictureBox^ Menu_button_closed;
	private: System::Windows::Forms::PictureBox^ Menu_button_open;

	private: System::Windows::Forms::Label^ Homescreen_menu_label;
	private: System::Windows::Forms::PictureBox^ Homescreen_menu_button;

	private: System::Windows::Forms::PictureBox^ Marks_menu_button;
	private: System::Windows::Forms::Label^ Marks_menu_label;

	private: System::Windows::Forms::Label^ Attendance_menu_label;
	private: System::Windows::Forms::PictureBox^ Attendance_menu_button;
	// Menu - items - end

	// Student attendance - items - start
	private: Label^ Student_attendance_header;
	private: ComboBox^ Subject_selector_cb;

	private: Label^ Progress_bar_background;
	private: Label^ Progress_bar_foreground;

	private: array<array<Label^>^>^ Attendance_labels;
	private: array<Label^>^ Serial_labels = gcnew array<System::Windows::Forms::Label^>(Max_Weeks + 1);
	// Student attendance - items - end

	// Student marks - items - start
	private: Label^ Student_Marks_header;
	private: ComboBox^ Subject_db;
	private: array<Label^>^ Exam_headers;

	private: array<array<array<Label^>^>^>^ Exam_labels; // 3D array [exam][column][number]
	private: Label^ Grade_label;
	private: int sr_column = 0, obtained_column = 1, total_column = 2, average_column = 3, std_dev_column = 4, min_column = 5, max_column = 6, no_of_columns = 7;
	private: array<int>^ Exam_sizes = gcnew array<int>(5);
	private: array<bool>^ Exam_header_shown = gcnew array<bool>(5);
	// Student marks - items - end

	private:
		///<summary>
		///Required designer variable.
		///</summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		///<summary>
		///Required method for Designer support - do not modify
		///the contents of this method with the code editor.
		///</summary>
		// InitializeComponent_homepage
		void InitializeComponent(void)
		{
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
			this->Student_hp_header->TabIndex = 1;
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
			this->Background_info_hp->TabIndex = 11;
			// 
			// Student_hp_subheader
			// 
			this->Student_hp_subheader->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.25F, System::Drawing::FontStyle::Bold));
			this->Student_hp_subheader->Location = System::Drawing::Point(34, 145);
			this->Student_hp_subheader->Name = L"Student_hp_subheader";
			this->Student_hp_subheader->Size = System::Drawing::Size(195, 35);
			this->Student_hp_subheader->TabIndex = 2;
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
			this->Name_subheader->TabIndex = 3;
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
			this->Name_l->TabIndex = 4;
			this->Name_l->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ID_subheader
			// 
			this->ID_subheader->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ID_subheader->Location = System::Drawing::Point(159, 243);
			this->ID_subheader->Name = L"ID_subheader";
			this->ID_subheader->Size = System::Drawing::Size(106, 23);
			this->ID_subheader->TabIndex = 5;
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
			this->ID_l->TabIndex = 6;
			this->ID_l->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Sec_subheader
			// 
			this->Sec_subheader->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Sec_subheader->Location = System::Drawing::Point(159, 286);
			this->Sec_subheader->Name = L"Sec_subheader";
			this->Sec_subheader->Size = System::Drawing::Size(106, 23);
			this->Sec_subheader->TabIndex = 7;
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
			this->Sec_l->TabIndex = 8;
			this->Sec_l->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Email_subheader
			// 
			this->Email_subheader->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Email_subheader->Location = System::Drawing::Point(159, 327);
			this->Email_subheader->Name = L"Email_subheader";
			this->Email_subheader->Size = System::Drawing::Size(106, 23);
			this->Email_subheader->TabIndex = 9;
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
			this->Email_l->TabIndex = 10;
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
			
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Menu_button_closed))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Menu_button_open))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Marks_menu_button))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Attendance_menu_button))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Homescreen_menu_button))->BeginInit();

			this->SuspendLayout();

			// 
			// Menu_button_closed
			// 
			this->Menu_button_closed->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Menu_button_closed->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Menu_button_closed->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Menu_closed_button_Image")));
			this->Menu_button_closed->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Menu_button_closed->Location = System::Drawing::Point(15, this->ClientSize.Height - 47);
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
			this->Menu_button_open->Location = System::Drawing::Point(15, this->ClientSize.Height - 47);
			this->Menu_button_open->Name = L"Menu_button_open";
			this->Menu_button_open->Size = System::Drawing::Size(35, 35);
			this->Menu_button_open->Click += gcnew System::EventHandler(this, &Student::Menu_open_button_Click);
			this->Menu_button_open->Visible = false;
			
			// 
			// Homescreen_menu_button
			// 
			this->Homescreen_menu_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Homescreen_menu_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Homescreen_menu_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Homescreen_menu_Image")));
			this->Homescreen_menu_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->Homescreen_menu_button->Location = System::Drawing::Point(15, this->ClientSize.Height - 164);
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
			this->Homescreen_menu_label->Location = System::Drawing::Point(50, this->ClientSize.Height - 164);
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
			this->Attendance_menu_button->BackColor = System::Drawing::Color::LavenderBlush;
			this->Attendance_menu_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Attendance_menu_Image")));
			this->Attendance_menu_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->Attendance_menu_button->Location = System::Drawing::Point(15, this->ClientSize.Height - 126);
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
			this->Attendance_menu_label->Location = System::Drawing::Point(50, this->ClientSize.Height - 126);
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
			this->Marks_menu_button->Location = System::Drawing::Point(15, this->ClientSize.Height - 88);
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
			this->Marks_menu_label->Location = System::Drawing::Point(50, this->ClientSize.Height - 88);
			this->Marks_menu_label->Name = L"Marks_menu_label";
			this->Marks_menu_label->Size = System::Drawing::Size(120, 35);
			this->Marks_menu_label->Text = L"View Marks";
			this->Marks_menu_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->Marks_menu_label->Click += gcnew System::EventHandler(this, &Student::Marks_menu_click);
			this->Marks_menu_label->Visible = false;
			
			// 
			// Menu
			// 
			this->Controls->Add(this->Menu_button_closed);
			this->Controls->Add(this->Menu_button_open);

			this->Controls->Add(this->Homescreen_menu_label);
			this->Controls->Add(this->Homescreen_menu_button);
			
			this->Controls->Add(this->Attendance_menu_label);
			this->Controls->Add(this->Attendance_menu_button);
			
			this->Controls->Add(this->Marks_menu_label);
			this->Controls->Add(this->Marks_menu_button);

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Menu_button_closed))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Menu_button_open))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Marks_menu_button))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Attendance_menu_button))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Homescreen_menu_button))->EndInit();

			this->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MSP::Student::OnScroll);
			this->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &MSP::Student::OnScroll);
			this->ClientSizeChanged += gcnew System::EventHandler(this, &MSP::Student::OnClientSizeChanged);

			this->ResumeLayout(false);
			this->PerformLayout();

		}

		void InitializeComponent_Attendance(void) {
			int Lec_per_week = 2;

			// Setup current subject variable incase the subject drop-down menu is unselected
			if (curr_subject == -1)
				curr_subject = 0;

			this->Student_attendance_header = (gcnew System::Windows::Forms::Label());
			this->Subject_selector_cb = (gcnew System::Windows::Forms::ComboBox());

			this->Progress_bar_background = (gcnew System::Windows::Forms::Label());
			this->Progress_bar_foreground = (gcnew System::Windows::Forms::Label());

			for (int i = 0; i < Max_Weeks + 1; i++) {
				this->Serial_labels[i] = gcnew Label();
			}

			this->Attendance_labels = gcnew array<array<Label^>^>(Lec_per_week);
			for (int i = 0; i < Lec_per_week; i++) {
				this->Attendance_labels[i] = gcnew array<Label^>(Max_Weeks + 1);
				for (int j = 0; j < Max_Weeks + 1; j++)
					this->Attendance_labels[i][j] = gcnew Label();
			}

			// 
			// Student_attendance_header
			// 
			this->Student_attendance_header->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left | AnchorStyles::Right);
			this->Student_attendance_header->BorderStyle = BorderStyle::FixedSingle;
			this->Student_attendance_header->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Student_attendance_header->ForeColor = Color::Black;
			this->Student_attendance_header->BackColor = Color::White;
			this->Student_attendance_header->Location = System::Drawing::Point(10, 30);
			this->Student_attendance_header->Name = L"Student_attendance_header";
			this->Student_attendance_header->Size = System::Drawing::Size(700, 35);
			this->Student_attendance_header->Text = L"Student Attendance";
			this->Student_attendance_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			// 
			// Subject_selector_cb
			// 
			this->Subject_selector_cb->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Right);
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
			this->Progress_bar_background->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left | AnchorStyles::Right);
			this->Progress_bar_background->BorderStyle = BorderStyle::Fixed3D;
			this->Progress_bar_background->BackColor = Color::LightGray;
			this->Progress_bar_background->Location = System::Drawing::Point(10, this->Subject_selector_cb->Bottom + 15);
			this->Progress_bar_background->Name = L"Progress_bar_backround";
			this->Progress_bar_background->Size = System::Drawing::Size(704, 34);
			// 
			// Progress_bar_foreground
			// 
			this->Progress_bar_foreground->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left);
			this->Progress_bar_foreground->BorderStyle = BorderStyle::Fixed3D;
			this->Progress_bar_foreground->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Progress_bar_foreground->ForeColor = Color::White;
			this->Progress_bar_foreground->BackColor = Color::RoyalBlue;
			this->Progress_bar_foreground->Location = System::Drawing::Point(12, this->Progress_bar_background->Top + 2);
			this->Progress_bar_foreground->Name = L"Progress_bar_backround";
			this->Progress_bar_foreground->Size = System::Drawing::Size(0, 30);
			this->Progress_bar_foreground->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;


			//
			// Serial_labels
			// 
			for (int i = 0; i < Max_Weeks + 1; i++) {
				this->Serial_labels[i]->Anchor = AnchorStyles::Top;
				this->Serial_labels[i]->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				this->Serial_labels[i]->ForeColor = Color::Black;
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
					this->Serial_labels[i]->Left = this->Serial_labels[i - 1]->Left;
					this->Serial_labels[i]->Top = this->Serial_labels[i - 1]->Bottom + 5;
				}

			}
			//
			// Lecture_labels
			//
			for (int lec_no = 0; lec_no < Lec_per_week; lec_no++) {
				for (int week_no = 0; week_no < Max_Weeks + 1; week_no++)
				{
					this->Attendance_labels[lec_no][week_no]->Anchor = AnchorStyles::Top;
					this->Attendance_labels[lec_no][week_no]->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
					this->Attendance_labels[lec_no][week_no]->ForeColor = Color::Black;
					if (lec_no == 0)
						this->Attendance_labels[lec_no][week_no]->Location = System::Drawing::Point(this->Serial_labels[week_no]->Right + 5, this->Serial_labels[week_no]->Top);
					else
						this->Attendance_labels[lec_no][week_no]->Location = System::Drawing::Point(this->Attendance_labels[lec_no - 1][week_no]->Right + 5, this->Attendance_labels[lec_no - 1][week_no]->Top);
					this->Attendance_labels[lec_no][week_no]->Name = stoS("Att_label_Lec" + std::to_string(lec_no + 1) + "_Week_" + std::to_string(week_no));
					this->Attendance_labels[lec_no][week_no]->Size = System::Drawing::Size(250, 30);
					this->Attendance_labels[lec_no][week_no]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
					if (week_no == 0) {
						this->Attendance_labels[lec_no][week_no]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
							static_cast<System::Byte>(0)));
						this->Attendance_labels[lec_no][week_no]->Text = stoS("Lecture " + std::to_string(lec_no + 1));
					}
					else {
						this->Attendance_labels[lec_no][week_no]->BackColor = Color::WhiteSmoke;
						this->Attendance_labels[lec_no][week_no]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
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
			for (int i = 0; i < Lec_per_week; i++)
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
			const int Total_exams = 5;
			this->Exam_sizes[0] = saved.quizzes[curr_subject][curr_sec];
			this->Exam_sizes[1] = saved.assignments[curr_subject][curr_sec];
			this->Exam_sizes[2] = 1;
			this->Exam_sizes[3] = 1;
			this->Exam_sizes[4] = 1;
			std::string Exam_name[Total_exams] = { "Quiz(zes)", "Assignment(s)", "Sessional 1", "Sessional 2", "Final" };
			for (int i = 0; i < 5; i++)
				this->Exam_header_shown[i] = false;
			// Extra localvariables - end

			// Setup current subject variable incase the subject drop-down menu is unselected
			if (curr_subject == -1)
				curr_subject = 0;

			// Main winform header
			this->Student_Marks_header = gcnew Label();

			// Subject selector
			this->Subject_selector_cb = gcnew ComboBox();

			// Exam headers
			this->Exam_headers = gcnew array<Label^>(Total_exams);
			for (int i = 0; i < Total_exams; i++)
				this->Exam_headers[i] = gcnew Label();

			// Exam subheaders/labels
			this->Exam_labels = gcnew array<array<array<Label^>^>^>(Total_exams);
			for (int i = 0; i < Total_exams; i++) {
				this->Exam_labels[i] = gcnew array<array<Label^>^>(no_of_columns);
				for (int j = 0; j < no_of_columns; j++)
					this->Exam_labels[i][j] = gcnew array<Label^>(Exam_sizes[i] + 1);
			}
			for (int i = 0; i < Total_exams; i++)
				for (int j = 0; j < no_of_columns; j++)
					for (int k = 0; k < Exam_sizes[i] + 1; k++)
						this->Exam_labels[i][j][k] = (gcnew Label());

			// Grade label (to be displayed at the end)
			this->Grade_label = (gcnew Label());

			// 
			// Student_Marks_header
			// 
			this->Student_Marks_header->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left | AnchorStyles::Right);
			this->Student_Marks_header->BorderStyle = BorderStyle::FixedSingle;
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
			this->Subject_selector_cb->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left);
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
			// Exam_headers
			// 
			for (int i = 0; i < Total_exams; i++) {
				this->Exam_headers[i]->Anchor = AnchorStyles::Top;
				this->Exam_headers[i]->BackColor = System::Drawing::SystemColors::AppWorkspace;
				this->Exam_headers[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Exam_headers[i]->Location = System::Drawing::Point(20, 80);
				for (int j = 0; j < i; j++)
					this->Exam_headers[i]->Top += (Exam_sizes[j] + 1) * 30 + 60;
				this->Exam_headers[i]->Name = stoS(Exam_name[i] + "_header");
				this->Exam_headers[i]->Size = System::Drawing::Size(680, 30);
				this->Exam_headers[i]->Text = stoS(Exam_name[i]);
				this->Exam_headers[i]->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
				this->Exam_headers[i]->Tag = i;
				this->Exam_headers[i]->Click += gcnew EventHandler(this, &Student::Exam_header_click);
			}
			//
			// Assignment_labels
			//
			for (int i = 0; i < Total_exams; i++) {
				for (int j = 0; j < no_of_columns; j++) {
					for (int k = 0; k < Exam_sizes[i] + 1; k++) {
						this->Exam_labels[i][j][k]->Anchor = AnchorStyles::Top;
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
							this->Exam_labels[i][j][k]->BackColor = Color::RoyalBlue;
							this->Exam_labels[i][j][k]->ForeColor = Color::White;
						}
						else {
							this->Exam_labels[i][j][k]->BackColor = Color::LightGray;
							this->Exam_labels[i][j][k]->ForeColor = Color::Black;
						}

						// Visibility
						this->Exam_labels[i][j][k]->Visible = this->Exam_header_shown[i];
					}
				}
			}

			// Grade_label
			this->Grade_label->Anchor = AnchorStyles::Top;
			this->Grade_label->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->Grade_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Grade_label->Left = 20;
			this->Grade_label->Name = L"Grade_label";
			this->Grade_label->Size = System::Drawing::Size(680, 30);

			this->Grade_label->Text = stoS("Grade : " + Student_marks[curr_sec][student_no].grade[curr_subject]);
			if (Student_marks[curr_sec][student_no].grade[curr_subject] != "NaN")
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
			
			this->Controls->AddRange(this->Exam_headers);
			this->Controls->Add(this->Grade_label);

			for (int i = 0; i < Total_exams; i++)
				for (int j = 0; j < no_of_columns; j++)
					this->Controls->AddRange(this->Exam_labels[i][j]);

			this->Name = L"Student_Marks";
			this->Text = L"Student Marks";

			load_data();
			reload_button();

			this->ResumeLayout(false);
			this->PerformLayout();
		}
	
	// Student_homepage - functions
	private: void Student_Load() {
		this->Name_l->Text = stoS(Stu_Cred[curr_sec][student_no].name);
		this->ID_l->Text = stoS(Stu_Cred[curr_sec][student_no].id);
		this->Sec_l->Text = stoS(string("Section ") + Sec_list[curr_sec]);
		this->Email_l->Text = stoS(Stu_Cred[curr_sec][student_no].username);

		InitializeComponent_Menu();
	}
	// Student_homepage - functions	 - end
	
	// Menu - functions	
	private: System::Void OnClientSizeChanged(Object^ sender, EventArgs^ e) {
		reposition_menu_items();
		if (this->Controls->Contains(this->Progress_bar_foreground))
			attendance_reload();
	}
	private: System::Void OnScroll(Object^ sender, ScrollEventArgs^ e) {
		reposition_menu_items();
	}
	private: System::Void OnScroll(Object^ sender, MouseEventArgs^ e) {
		reposition_menu_items();
	}
	private: void reposition_menu_items(void) {
		this->Homescreen_menu_button->Top = this->ClientSize.Height - 164;
		this->Homescreen_menu_label->Top = this->ClientSize.Height - 164;
		this->Attendance_menu_button->Top = this->ClientSize.Height - 126;
		this->Attendance_menu_label->Top = this->ClientSize.Height - 126;
		this->Marks_menu_button->Top = this->ClientSize.Height - 88;
		this->Marks_menu_label->Top = this->ClientSize.Height - 88;
		this->Menu_button_closed->Top = this->ClientSize.Height - 47;
		this->Menu_button_open->Top = this->ClientSize.Height - 47;
	}
	private: System::Void Menu_closed_button_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Menu_button_closed->Visible = false;
		this->Menu_button_open->Visible = true;
		this->Marks_menu_label->Visible = true;
		this->Marks_menu_button->Visible = true;
		this->Attendance_menu_label->Visible = true;
		this->Attendance_menu_button->Visible = true;
		this->Attendance_menu_label->Visible = true;
		this->Homescreen_menu_button->Visible = true;
		this->Homescreen_menu_label->Visible = true;
		this->Menu_button_open->BringToFront();
		this->Marks_menu_label->BringToFront();
		this->Marks_menu_button->BringToFront();
		this->Attendance_menu_label->BringToFront();
		this->Attendance_menu_button->BringToFront();
		this->Attendance_menu_label->BringToFront();
		this->Homescreen_menu_button->BringToFront();
		this->Homescreen_menu_label->BringToFront();
	}
	private: System::Void Menu_open_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Menu_button_closed->Visible = true;
		this->Menu_button_closed->BringToFront();
		this->Menu_button_open->Visible = false;
		this->Marks_menu_label->Visible = false;
		this->Marks_menu_button->Visible = false;
		this->Attendance_menu_label->Visible = false;
		this->Attendance_menu_button->Visible = false;
		this->Attendance_menu_label->Visible = false;
		this->Homescreen_menu_button->Visible = false;
		this->Homescreen_menu_label->Visible = false;
	}
	private: System::Void Homescreen_menu_click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		this->Controls->Clear();
		this->InitializeComponent();
		this->InitializeComponent_Menu();
		this->Show();
	}
	private: System::Void Attendence_menu_click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		this->Controls->Clear();
		this->InitializeComponent_Attendance();
		this->InitializeComponent_Menu();
		this->Show();
	}
	private: System::Void Marks_menu_click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		this->Controls->Clear();
		this->InitializeComponent_Marks();
		this->InitializeComponent_Menu();
		this->Show();
	}
	// Menu - functions - end

	// Student_marks - functions
	private: void load_data(void) {
		float tmp_sum = 0, tmp_sq_sum = 0, min, max;
		// Quiz
		for (int i = 0; i < saved.quizzes[curr_subject][curr_sec]; i++) {
			tmp_sum = 0, tmp_sq_sum = 0, min, max;
			Exam_labels[Exam_quiz][obtained_column][i + 1]->Text = stoS(to_string_with_precision(Student_marks[curr_sec][student_no].quizzes[curr_subject][i], 2));
			Exam_labels[Exam_quiz][total_column][i + 1]->Text = stoS(to_string_with_precision(Max_marks[Exam_quiz], 2));
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
			if (tmp_sum == 0) {
				Exam_labels[Exam_quiz][obtained_column][i + 1]->Text = L"-";
				Exam_labels[Exam_quiz][average_column][i + 1]->Text = L"-";
				Exam_labels[Exam_quiz][std_dev_column][i + 1]->Text = L"-";
				Exam_labels[Exam_quiz][min_column][i + 1]->Text = L"-";
				Exam_labels[Exam_quiz][max_column][i + 1]->Text = L"-";
			}
			else {
				Exam_labels[Exam_quiz][average_column][i + 1]->Text = stoS(to_string_with_precision(tmp_sum / Max_Students, 2));
				Exam_labels[Exam_quiz][std_dev_column][i + 1]->Text = stoS(to_string_with_precision(sqrt(tmp_sq_sum / Max_Students), 2));
				Exam_labels[Exam_quiz][min_column][i + 1]->Text = stoS(to_string_with_precision(min, 2));
				Exam_labels[Exam_quiz][max_column][i + 1]->Text = stoS(to_string_with_precision(max, 2));
			}
		}
		
		// Assignment
		for (int i = 0; i < saved.assignments[curr_subject][curr_sec]; i++) {
			tmp_sum = 0, tmp_sq_sum = 0, min, max;
			Exam_labels[Exam_assignment][obtained_column][i + 1]->Text = stoS(to_string_with_precision(Student_marks[curr_sec][student_no].assignment[curr_subject][i], 2));
			Exam_labels[Exam_assignment][total_column][i + 1]->Text = stoS(to_string_with_precision(Max_marks[Exam_assignment], 2));
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
			if (tmp_sum == 0) {
				Exam_labels[Exam_assignment][obtained_column][i + 1]->Text = L"-";
				Exam_labels[Exam_assignment][average_column][i + 1]->Text = L"-";
				Exam_labels[Exam_assignment][std_dev_column][i + 1]->Text = L"-";
				Exam_labels[Exam_assignment][min_column][i + 1]->Text = L"-";
				Exam_labels[Exam_assignment][max_column][i + 1]->Text = L"-";
			}
			else {
				Exam_labels[Exam_assignment][average_column][i + 1]->Text = stoS(to_string_with_precision(tmp_sum / Max_Students, 2));
				Exam_labels[Exam_assignment][std_dev_column][i + 1]->Text = stoS(to_string_with_precision(sqrt(tmp_sq_sum / Max_Students), 2));
				Exam_labels[Exam_assignment][min_column][i + 1]->Text = stoS(to_string_with_precision(min, 2));
				Exam_labels[Exam_assignment][max_column][i + 1]->Text = stoS(to_string_with_precision(max, 2));
			}
		}
		
		// Sessional 1
		Exam_labels[Exam_mid1][obtained_column][1]->Text = stoS(to_string_with_precision(Student_marks[curr_sec][student_no].mid1[curr_subject], 2));
		Exam_labels[Exam_mid1][total_column][1]->Text = stoS(to_string_with_precision(Max_marks[Exam_mid1], 2));
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
		if (tmp_sum == 0) {
			Exam_labels[Exam_mid1][obtained_column][1]->Text = L"-";
			Exam_labels[Exam_mid1][average_column][1]->Text = L"-";
			Exam_labels[Exam_mid1][std_dev_column][1]->Text = L"-";
			Exam_labels[Exam_mid1][min_column][1]->Text = L"-";
			Exam_labels[Exam_mid1][max_column][1]->Text = L"-";
		}
		else {
			Exam_labels[Exam_mid1][average_column][1]->Text = stoS(to_string_with_precision(tmp_sum / Max_Students, 2));
			Exam_labels[Exam_mid1][std_dev_column][1]->Text = stoS(to_string_with_precision(sqrt(tmp_sq_sum / Max_Students), 2));
			Exam_labels[Exam_mid1][min_column][1]->Text = stoS(to_string_with_precision(min, 2));
			Exam_labels[Exam_mid1][max_column][1]->Text = stoS(to_string_with_precision(max, 2));
		}
		
		// Sessional 2
		Exam_labels[Exam_mid2][obtained_column][1]->Text = stoS(to_string_with_precision(Student_marks[curr_sec][student_no].mid2[curr_subject], 2));
		Exam_labels[Exam_mid2][total_column][1]->Text = stoS(to_string_with_precision(Max_marks[Exam_mid2], 2));
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
		if (tmp_sum == 0) {
			Exam_labels[Exam_mid2][obtained_column][1]->Text = L"-";
			Exam_labels[Exam_mid2][average_column][1]->Text = L"-";
			Exam_labels[Exam_mid2][std_dev_column][1]->Text = L"-";
			Exam_labels[Exam_mid2][min_column][1]->Text = L"-";
			Exam_labels[Exam_mid2][max_column][1]->Text = L"-";
		}
		else {
			Exam_labels[Exam_mid2][average_column][1]->Text = stoS(to_string_with_precision(tmp_sum / Max_Students, 2));
			Exam_labels[Exam_mid2][std_dev_column][1]->Text = stoS(to_string_with_precision(sqrt(tmp_sq_sum / Max_Students), 2));
			Exam_labels[Exam_mid2][min_column][1]->Text = stoS(to_string_with_precision(min, 2));
			Exam_labels[Exam_mid2][max_column][1]->Text = stoS(to_string_with_precision(max, 2));
		}
		
		// Finals
		Exam_labels[Exam_final][obtained_column][1]->Text = stoS(to_string_with_precision(Student_marks[curr_sec][student_no].finals[curr_subject], 2));
		Exam_labels[Exam_final][total_column][1]->Text = stoS(to_string_with_precision(Max_marks[Exam_final], 2));
		tmp_sum = 0, tmp_sq_sum = 0, min, max;
		for (int j = 0; j < Max_Students; j++) {
			if (j == 0) {
				min = Student_marks[curr_sec][j].finals[curr_subject];
				max = Student_marks[curr_sec][j].finals[curr_subject];
			}
			else {
				if (min > Student_marks[curr_sec][j].finals[curr_subject])
					min = Student_marks[curr_sec][j].finals[curr_subject];
				else if (max < Student_marks[curr_sec][j].finals[curr_subject])
					max = Student_marks[curr_sec][j].finals[curr_subject];
			}
			tmp_sum += Student_marks[curr_sec][j].finals[curr_subject];
			tmp_sq_sum += Student_marks[curr_sec][j].finals[curr_subject] * Student_marks[curr_sec][j].finals[curr_subject];
		}
		if (tmp_sum == 0) {
			Exam_labels[Exam_final][obtained_column][1]->Text = L"-";
			Exam_labels[Exam_final][average_column][1]->Text = L"-";
			Exam_labels[Exam_final][std_dev_column][1]->Text = L"-";
			Exam_labels[Exam_final][min_column][1]->Text = L"-";
			Exam_labels[Exam_final][max_column][1]->Text = L"-";
		}
		else {
			Exam_labels[Exam_final][average_column][1]->Text = stoS(to_string_with_precision(tmp_sum / Max_Students, 2));
			Exam_labels[Exam_final][std_dev_column][1]->Text = stoS(to_string_with_precision(sqrt(tmp_sq_sum / Max_Students), 2));
			Exam_labels[Exam_final][min_column][1]->Text = stoS(to_string_with_precision(min, 2));
			Exam_labels[Exam_final][max_column][1]->Text = stoS(to_string_with_precision(max, 2));
		}

	}
	private: void reload_button(void) {

		for (int i = 0; i < 5; i++) {
			this->Exam_headers[i]->Top = 120;
			bool first = true;
			for (int j = 0; j < i; j++) {
				if (this->Exam_header_shown[j]) {
					this->Exam_headers[i]->Top += (Exam_sizes[j] + 1) * 30 + 60;
					first = false;
				}
				else {
					this->Exam_headers[i]->Top += 60;
					first = false;
				}
			}
		}

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < no_of_columns; j++) {
				for (int k = 0; k < Exam_sizes[i] + 1; k++) {
					if (j == 0)
						this->Exam_labels[i][j][k]->Left = this->Exam_headers[i]->Left + 20;
					else
						this->Exam_labels[i][j][k]->Left = this->Exam_labels[i][j - 1][k]->Right;

					if (k == 0)
						this->Exam_labels[i][j][k]->Top = this->Exam_headers[i]->Bottom;
					else
						this->Exam_labels[i][j][k]->Top = this->Exam_labels[i][j][k - 1]->Bottom + 5;
				}
			}
		}
		
		if (Exam_header_shown[Exam_final])
			this->Grade_label->Top = this->Exam_labels[Exam_final][no_of_columns - 1][Exam_sizes[Exam_final]]->Bottom + 30;
		else
			this->Grade_label->Top = this->Exam_headers[Exam_final]->Bottom + 30;

	}
	private: System::Void Exam_header_click(System::Object^ sender, System::EventArgs^ e) {
		this->VerticalScroll->Value = 0;
		int exam_no = stoi(Stos(static_cast<Control^>(sender)->Tag->ToString()));
		this->Exam_header_shown[exam_no] = !(this->Exam_header_shown[exam_no]);
		for (int j = 0; j < no_of_columns; j++) {
			for (int k = 0; k < Exam_sizes[exam_no] + 1; k++) {
				this->Exam_labels[exam_no][j][k]->Visible = !(this->Exam_labels[exam_no][j][k]->Visible);
			}
		}
		reload_button();
		reposition_menu_items();
		if (this->Menu_button_closed->Visible)
			this->Menu_button_closed->BringToFront();
		else {
			this->Menu_button_open->BringToFront();
			this->Homescreen_menu_button->BringToFront();
			this->Attendance_menu_button->BringToFront();
			this->Marks_menu_button->BringToFront();
		}

	}
	// Student_marks - functions - end

	// Student_attendance - functions
	private: void attendance_reload() {
		int presences = 0, absences = 0;
		curr_subject = this->Subject_selector_cb->SelectedIndex;

		for (int i = 0; i < Max_Weeks; i++)
		{
			if (Student_att[curr_sec][student_no].lec1[curr_subject][i] == "Present") {
				presences++;
				this->Attendance_labels[0][i + 1]->ForeColor = Color::Black;
			}
			else if (Student_att[curr_sec][student_no].lec1[curr_subject][i] == "Absent") {
				absences++;
				this->Attendance_labels[0][i + 1]->ForeColor = Color::Red;
			}
			if (Student_att[curr_sec][student_no].lec2[curr_subject][i] == "Present") {
				presences++;
				this->Attendance_labels[1][i + 1]->ForeColor = Color::Black;
			}
			else if (Student_att[curr_sec][student_no].lec2[curr_subject][i] == "Absent") {
				absences++;
				this->Attendance_labels[1][i + 1]->ForeColor = Color::Red;
			}

			this->Attendance_labels[0][i + 1]->Text = stoS(Student_att[curr_sec][student_no].lec1[curr_subject][i]);
			this->Attendance_labels[0][i + 1]->Left = this->Serial_labels[i + 1]->Right + 5;
			this->Attendance_labels[1][i + 1]->Text = stoS(Student_att[curr_sec][student_no].lec2[curr_subject][i]);
			this->Attendance_labels[1][i + 1]->Left = this->Attendance_labels[0][i + 1]->Right + 5;
		}
		this->Attendance_labels[0][0]->Left = this->Serial_labels[0]->Right + 5;
		this->Attendance_labels[1][0]->Left = this->Attendance_labels[0][0]->Right + 5;

		float percentage = float(presences) / (presences + absences);
		this->Progress_bar_foreground->Width = int(percentage * (this->Progress_bar_background->Width - 2 * (this->Progress_bar_foreground->Left - this->Progress_bar_background->Left)));
		this->Progress_bar_foreground->Text = stoS(to_string_with_precision(percentage * 100, 2));
		this->Progress_bar_foreground->BringToFront();

	}
	// Student_attendance - functions - end

	private: System::Void Change_subject(System::Object^ sender, System::EventArgs^ e) {
		curr_subject = this->Subject_selector_cb->SelectedIndex;
		
		this->Hide();

		this->Controls->Clear();
		
		String^ page = static_cast<Control^>(sender)->Tag->ToString();
		if (page == "Attendance")
			this->InitializeComponent_Attendance();
		else if (page == "Marks")
			this->InitializeComponent_Marks();
		
		this->InitializeComponent_Menu();

		this->Show();
		reposition_menu_items();
	}
};
}
