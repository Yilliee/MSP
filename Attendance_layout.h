#pragma once
#include "functions.h"
#include "variables.h"

namespace MSP {

	using namespace System::Windows::Forms;
	using System::Void;
	using System::String;
	using System::Drawing::Point;

	/// <summary>
	/// Summary for Attendance_layout
	/// </summary>
	public ref class Attendance_layout : public Form
	{
	public:
		Attendance_layout(void)
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
		~Attendance_layout()
		{
			if (components)
			{
				delete components;
			}
		}

	// Attendance - items - start
	private: Label^ Attendance_header;
	private: Button^ Save_button;
	private: Button^ Back_button;
	private: array<Button^>^ Page_sel_button = gcnew array<Button^>(Max_Weeks);

	private: Label^ Week_lec1_header;
	private: Label^ Week_lec2_header;

	private: array<Label^>^ Sr_l = gcnew array<Label^>(Max_Students);
	private: array<Label^>^ Name_l = gcnew array<Label^>(Max_Students);
	private: array<Label^>^ ID_l = gcnew array<Label^>(Max_Students);
	// Since we can't make a 2D array, multiply the 2 indexes to get an array of similar size.
	// To access the entries use [ (i+1)*(j+1) - 1 ] where i and j are the 2 indexes you'd use with a normal 2D array.
	private: array<ComboBox^>^ Week_lec1_cb = gcnew array <ComboBox^>(Max_Weeks * Max_Students);
	private: array<ComboBox^>^ Week_lec2_cb = gcnew array<ComboBox^>(Max_Weeks * Max_Students);
	// Attendance - items - end

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		void InitializeComponent(void)
		{
			this->Attendance_header = (gcnew Label());

			this->Save_button = (gcnew Button());
			this->Back_button = (gcnew Button());
			for (int i = 0; i < Max_Weeks; i++)
				this->Page_sel_button[i] = (gcnew Button());

			this->Sr_header = (gcnew Label());
			this->ID_header = (gcnew Label());
			this->Name_header = (gcnew Label());

			for (int i = 0; i < Max_Students; i++) {
				this->Sr_l[i] = (gcnew Label());
				this->ID_l[i] = (gcnew Label());
				this->Name_l[i] = (gcnew Label());

			}

			this->Week_lec1_header = (gcnew Label());
			this->Week_lec2_header = (gcnew Label());
			for (int i = 0; i < Max_Weeks; i++) {
				for (int j = 0; j < Max_Students; j++) {
					this->Week_lec1_cb[(i * Max_Students) + j] = (gcnew ComboBox());
					this->Week_lec2_cb[(i * Max_Students) + j] = (gcnew ComboBox());
				}
			}

			this->SuspendLayout();

			//
			// Attendance_header
			//
			this->Attendance_header->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
			this->Attendance_header->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->Attendance_header->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Attendance_header->Location = System::Drawing::Point(10, 20);
			this->Attendance_header->Name = L"Attendance_header";
			this->Attendance_header->Size = System::Drawing::Size(680, 31);
			this->Attendance_header->TabIndex = 0;
			this->Attendance_header->Text = L"Manage Attendence";
			this->Attendance_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			//
			// Save_marksheet_button
			//
			this->Save_button->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
			this->Save_button->BackColor = System::Drawing::Color::Lavender;
			this->Save_button->FlatStyle = FlatStyle::Popup;
			this->Save_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Save_button->Location = System::Drawing::Point(660, 61);
			this->Save_button->Name = L"Save_marksheet_button";
			this->Save_button->Size = System::Drawing::Size(100, 25);
			this->Save_button->TabIndex = 1;
			this->Save_button->Text = L"Save";
			this->Save_button->UseVisualStyleBackColor = false;
			this->Save_button->Click += gcnew System::EventHandler(this, &Attendance_layout::Save_button_Click);
			//
			// Back_button
			//
			this->Back_button->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
			this->Back_button->BackColor = System::Drawing::Color::Lavender;
			this->Back_button->FlatStyle = FlatStyle::Popup;
			this->Back_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Back_button->Location = System::Drawing::Point(5, 61);
			this->Back_button->Name = L"Back_button";
			this->Back_button->Size = System::Drawing::Size(100, 25);
			this->Back_button->TabIndex = 1;
			this->Back_button->Text = L"Back";
			this->Back_button->UseVisualStyleBackColor = false;
			this->Back_button->Click += gcnew System::EventHandler(this, &Attendance_layout::Back_button_Click);

			//
			// Page_sel_button
			int x_pos = 205;
			for (int i = 0; i < Max_Weeks; i++) {
				this->Page_sel_button[i]->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
				this->Page_sel_button[i]->BackColor = System::Drawing::Color::Lavender;
				this->Page_sel_button[i]->FlatStyle = FlatStyle::Popup;
				this->Page_sel_button[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Page_sel_button[i]->Location = System::Drawing::Point(x_pos, 93);
				this->Page_sel_button[i]->Name = L"Page_sel_button";
				this->Page_sel_button[i]->Size = System::Drawing::Size(30, 25);
				this->Page_sel_button[i]->TabIndex = 1;
				this->Page_sel_button[i]->Text = stoS(std::to_string(i + 1));
				this->Page_sel_button[i]->UseVisualStyleBackColor = false;
				this->Page_sel_button[i]->Tag = i + 1;
				this->Page_sel_button[i]->Click += gcnew System::EventHandler(this, &Attendance_layout::Load_page);
				x_pos += 35;
			}
			//
			// Sr_header
			//
			this->Sr_header->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
			this->Sr_header->BorderStyle = BorderStyle::FixedSingle;
			this->Sr_header->FlatStyle = FlatStyle::Popup;
			this->Sr_header->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->Sr_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Sr_header->Location = System::Drawing::Point(5, 124);
			this->Sr_header->Name = L"Sr_marksheet_l_h";
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
			this->ID_header->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ID_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ID_header->Location = System::Drawing::Point(45, 124);
			this->ID_header->Name = L"ID_h";
			this->ID_header->Size = System::Drawing::Size(100, 25);
			this->ID_header->TabIndex = 3;
			this->ID_header->Text = L"Roll no.";
			this->ID_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			//
			// Name_header
			//
			this->Name_header->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
			this->Name_header->BorderStyle = BorderStyle::FixedSingle;
			this->Name_header->FlatStyle = FlatStyle::Popup;
			this->Name_header->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->Name_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name_header->Location = System::Drawing::Point(150, 124);
			this->Name_header->Name = L"Name_h";
			this->Name_header->Size = System::Drawing::Size(200, 25);
			this->Name_header->TabIndex = 4;
			this->Name_header->Text = L"Student Name";
			this->Name_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			//
			// Week_lec1_header
			//
			this->Week_lec1_header->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
			this->Week_lec1_header->BorderStyle = BorderStyle::FixedSingle;
			this->Week_lec1_header->FlatStyle = FlatStyle::Popup;
			this->Week_lec1_header->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->Week_lec1_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Week_lec1_header->Location = System::Drawing::Point(355, 124);
			this->Week_lec1_header->Name = L"Week_lec1_h";
			this->Week_lec1_header->Size = System::Drawing::Size(200, 25);
			this->Week_lec1_header->TabIndex = 5;
			this->Week_lec1_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			//
			// Week_lec2_header
			//
			this->Week_lec2_header->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
			this->Week_lec2_header->BorderStyle = BorderStyle::FixedSingle;
			this->Week_lec2_header->FlatStyle = FlatStyle::Popup;
			this->Week_lec2_header->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->Week_lec2_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Week_lec2_header->Location = System::Drawing::Point(560, 124);
			this->Week_lec2_header->Name = L"Week_lec2_h";
			this->Week_lec2_header->Size = System::Drawing::Size(200, 25);
			this->Week_lec2_header->TabIndex = 6;
			this->Week_lec2_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			//
			// Serial labels
			//
			int y_pos = 155, tab_index = 7;
			for (int i = 0; i < Max_Students; i++) {
				Sr_l[i]->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
				Sr_l[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				Sr_l[i]->Location = System::Drawing::Point(5, y_pos);
				Sr_l[i]->Name = stoS("Sr_" + std::to_string(i + 1));
				Sr_l[i]->Size = System::Drawing::Size(35, 25);
				Sr_l[i]->TabIndex = tab_index;
				Sr_l[i]->Text = stoS(std::to_string(i + 1) + ')');
				Sr_l[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				y_pos += 31;
				tab_index += 5;
			}
			//
			// ID
			//
			y_pos = 155, tab_index = 8;
			for (int i = 0; i < Max_Students; i++) {
				this->ID_l[i]->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
				this->ID_l[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				this->ID_l[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->ID_l[i]->Location = System::Drawing::Point(45, y_pos);
				this->ID_l[i]->Name = stoS("ID_" + std::to_string(i + 1));
				this->ID_l[i]->Size = System::Drawing::Size(100, 25);
				this->ID_l[i]->TabIndex = tab_index;
				this->ID_l[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				y_pos += 31;
				tab_index += 5;
			}
			//
			// Name_marksheet_l
			//
			y_pos = 155, tab_index = 9;
			for (int i = 0; i < Max_Students; i++) {
				this->Name_l[i]->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
				this->Name_l[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				this->Name_l[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Name_l[i]->Location = System::Drawing::Point(150, y_pos);
				this->Name_l[i]->Name = stoS("Name_" + std::to_string(i + 1));
				this->Name_l[i]->Size = System::Drawing::Size(200, 25);
				this->Name_l[i]->TabIndex = tab_index;
				this->Name_l[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				y_pos += 31;
				tab_index += 5;
			}
			//
			// Combo boxes
			//
			tab_index = 10;
			for (int i = 0; i < Max_Weeks; i++) {
				y_pos = 155;
				for (int j = 0; j < Max_Students; j++) {
					// lec1
					this->Week_lec1_cb[(i * Max_Students) + j]->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
					this->Week_lec1_cb[(i * Max_Students) + j]->BackColor = System::Drawing::Color::WhiteSmoke;
					this->Week_lec1_cb[(i * Max_Students) + j]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(0)));
					this->Week_lec1_cb[(i * Max_Students) + j]->Items->AddRange(gcnew array<Object^>(3) { L"Present", L"Absent", L"Leave" });
					this->Week_lec1_cb[(i * Max_Students) + j]->DropDownStyle = ComboBoxStyle::DropDownList;
					this->Week_lec1_cb[(i * Max_Students) + j]->Location = System::Drawing::Point(355, y_pos);
					this->Week_lec1_cb[(i * Max_Students) + j]->Name = stoS("Week_" + std::to_string(i + 1) + "_lec1");
					this->Week_lec1_cb[(i * Max_Students) + j]->Size = System::Drawing::Size(200, 25);
					this->Week_lec1_cb[(i * Max_Students) + j]->TabIndex = tab_index;
					this->Week_lec1_cb[(i * Max_Students) + j]->SelectedIndex = 0;
					tab_index++;
					// lec2
					this->Week_lec2_cb[(i * Max_Students) + j]->Anchor = static_cast<AnchorStyles>(AnchorStyles::Left | AnchorStyles::Top);
					this->Week_lec2_cb[(i * Max_Students) + j]->BackColor = System::Drawing::Color::WhiteSmoke;
					this->Week_lec2_cb[(i * Max_Students) + j]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(0)));
					this->Week_lec2_cb[(i * Max_Students) + j]->Items->AddRange(gcnew array<Object^>(3) { L"Present", L"Absent", L"Leave" });
					this->Week_lec2_cb[(i * Max_Students) + j]->DropDownStyle = ComboBoxStyle::DropDownList;
					this->Week_lec2_cb[(i * Max_Students) + j]->Location = System::Drawing::Point(560, y_pos);
					this->Week_lec2_cb[(i * Max_Students) + j]->Name = stoS("Week_" + std::to_string(i + 1) + "_lec2");
					this->Week_lec2_cb[(i * Max_Students) + j]->Size = System::Drawing::Size(200, 25);
					this->Week_lec2_cb[(i * Max_Students) + j]->TabIndex = tab_index;
					this->Week_lec2_cb[(i * Max_Students) + j]->SelectedIndex = 0;
					y_pos += 31;
					tab_index += 4;
				}
			}

			this->AutoScroll = true;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(780, 313);
			this->Name = L"Attendance_manager";
			this->Text = L"Attendence Manager";
			this->Controls->Add(this->Attendance_header);
			this->Controls->Add(this->Save_button);
			this->Controls->Add(this->Back_button);

			this->Controls->Add(this->Sr_header);
			this->Controls->Add(this->ID_header);
			this->Controls->Add(this->Name_header);

			this->Controls->Add(this->Week_lec1_header);
			this->Controls->Add(this->Week_lec2_header);

			this->Controls->AddRange(this->Page_sel_button);
			this->Controls->AddRange(this->Sr_l);
			this->Controls->AddRange(this->Name_l);
			this->Controls->AddRange(this->ID_l);
			this->Controls->AddRange(this->Week_lec1_cb);
			this->Controls->AddRange(this->Week_lec2_cb);
			this->Load += gcnew System::EventHandler(this, &Attendance_layout::Attendance_layout_Load);
			this->ResumeLayout(false);
			this->PerformLayout();
		}

	// Attendance - functions - start
	private: System::Void Attendance_layout_Load(System::Object^ sender, System::EventArgs^ e) {
		load_att_page(1);
	}
	private: void load_att_page(int page_no) {
		this->Week_lec1_header->Text = stoS("Week no." + std::to_string(page_no) + " Lec. 1");
		this->Week_lec2_header->Text = stoS("Week no." + std::to_string(page_no) + " Lec. 2");

		for (int j = 0; j < Max_Students; j++) {
			this->Week_lec1_cb[((page_no - 1) * Max_Students) + j]->BringToFront();
			this->Week_lec2_l_cb[((page_no - 1) * Max_Students) + j]->BringToFront();
		}
	}
	private: System::Void Load_page(System::Object^ sender, System::EventArgs^ e) {
		load_att_page(stoi(Stos(static_cast<Control^>(sender)->Tag->ToString())));
	}
	private: System::Void Save_button_Click(System::Object^ sender, System::EventArgs^ e) {
		load_att_page(stoi(Stos(static_cast<Control^>(sender)->Tag->ToString())));
	}
	// Attendance - functions - end
};
}
