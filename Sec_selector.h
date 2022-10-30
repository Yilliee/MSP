#pragma once
#include "Exam_type.h"

namespace MSP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Sec_selector
	/// </summary>
	public ref class Sec_selector : public System::Windows::Forms::Form
	{
	public:
		Sec_selector(void)
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
		~Sec_selector()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ Sec_selector_header;
	private: array<Button^>^ Section = gcnew array<Button^>(Max_Sections);
	private: System::Windows::Forms::Button^ Back_from_Secsel_button;

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
			this->Sec_selector_header = (gcnew System::Windows::Forms::Label());
			this->Back_from_Secsel_button = (gcnew System::Windows::Forms::Button());

			for (int i = 0; i < Max_Sections; i++) {
				this->Section[i] = (gcnew System::Windows::Forms::Button());
			}

			this->SuspendLayout();
			// 
			// Sec_selector_header
			// 
			this->Sec_selector_header->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Sec_selector_header->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Sec_selector_header->Location = System::Drawing::Point(10, 43);
			this->Sec_selector_header->Name = L"Sec_selector_header";
			this->Sec_selector_header->Size = System::Drawing::Size(680, 35);
			this->Sec_selector_header->TabIndex = 0;
			this->Sec_selector_header->Text = L"Select a section:";
			this->Sec_selector_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Section_Array
			// 
			int y_pos = 90;
			for (int i = 0; i < Max_Sections; i++) {
				this->Section[i]->Anchor = System::Windows::Forms::AnchorStyles::Top;
				this->Section[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				this->Section[i]->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				this->Section[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Section[i]->Location = System::Drawing::Point(250, y_pos);
				this->Section[i]->Name = std_to_System_string(System_to_std_string("Sec ") + Sec_list[i] + "_button");
				this->Section[i]->Size = System::Drawing::Size(200, 25);
				this->Section[i]->TabIndex = 1;
				this->Section[i]->Text = std_to_System_string(System_to_std_string("Section ") + Sec_list[i]);
				this->Section[i]->UseVisualStyleBackColor = false;
				this->Section[i]->Visible = true;
				y_pos += 40;
			}

			this->Section[0]->Click += gcnew System::EventHandler(this, &Sec_selector::Select_Section_A);
			this->Section[1]->Click += gcnew System::EventHandler(this, &Sec_selector::Select_Section_B);
			this->Section[2]->Click += gcnew System::EventHandler(this, &Sec_selector::Select_Section_C);
			this->Section[3]->Click += gcnew System::EventHandler(this, &Sec_selector::Select_Section_D);
			this->Section[4]->Click += gcnew System::EventHandler(this, &Sec_selector::Select_Section_E);
			this->Section[5]->Click += gcnew System::EventHandler(this, &Sec_selector::Select_Section_F);
			this->Section[6]->Click += gcnew System::EventHandler(this, &Sec_selector::Select_Section_G);
			this->Section[7]->Click += gcnew System::EventHandler(this, &Sec_selector::Select_Section_H);
			this->Section[8]->Click += gcnew System::EventHandler(this, &Sec_selector::Select_Section_I);
			this->Section[9]->Click += gcnew System::EventHandler(this, &Sec_selector::Select_Section_J);


			// 
			// Back_from_Secsel_button
			// 
			this->Back_from_Secsel_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Back_from_Secsel_button->BackColor = System::Drawing::Color::Lavender;
			this->Back_from_Secsel_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Back_from_Secsel_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Back_from_Secsel_button->Location = System::Drawing::Point(Section[saved.sections - 1]->Left, Section[saved.sections - 1]->Top + 40);
			this->Back_from_Secsel_button->Name = L"Back_to_home_del";
			this->Back_from_Secsel_button->Size = System::Drawing::Size(200, 25);
			this->Back_from_Secsel_button->Text = L"Go Back to home";
			this->Back_from_Secsel_button->UseVisualStyleBackColor = false;
			this->Back_from_Secsel_button->Visible = true;
			this->Back_from_Secsel_button->Click += gcnew System::EventHandler(this, &Sec_selector::back_to_homepage);

			// 
			// Sec_selector
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(700, 450);
			this->Controls->Add(this->Sec_selector_header);
			
			for (int i = 0; i < Max_Sections; i++)
				this->Controls->Add(this->Section[i]);

			this->Controls->Add(this->Back_from_Secsel_button);
			this->Name = L"Sec_selector";
			this->Text = L"Section Selector";
			this->Load += gcnew System::EventHandler(this, &Sec_selector::Sec_selector_Load);
			this->ResumeLayout(false);
			this->PerformLayout();


			this->SuspendLayout();


		}
#pragma endregion
	private: System::Void Sec_selector_Load(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < Max_Sections; i++) {
			if (saved.sections > i) this->Section[i]->Visible = true;
			else this->Section[i]->Visible = false;
		}
	}
	private: System::Void back_to_homepage(System::Object^ sender, System::EventArgs^ e) {
	
	}
	private: System::Void Select_Section_A(System::Object^ sender, System::EventArgs^ e) {
		curr_sec = 0;
		open_exam_selector();
	}
	private: System::Void Select_Section_B(System::Object^ sender, System::EventArgs^ e) {
		curr_sec = 1;
		open_exam_selector();
	}
	private: System::Void Select_Section_C(System::Object^ sender, System::EventArgs^ e) {
		curr_sec = 2;
		open_exam_selector();
	}
	private: System::Void Select_Section_D(System::Object^ sender, System::EventArgs^ e) {
		curr_sec = 3;
		open_exam_selector();
	}
	private: System::Void Select_Section_E(System::Object^ sender, System::EventArgs^ e) {
		curr_sec = 4;
		open_exam_selector();
	}
	private: System::Void Select_Section_F(System::Object^ sender, System::EventArgs^ e) {
		curr_sec = 5;
		open_exam_selector();
	}
	private: System::Void Select_Section_G(System::Object^ sender, System::EventArgs^ e) {
		curr_sec = 6;
		open_exam_selector();
	}
	private: System::Void Select_Section_H(System::Object^ sender, System::EventArgs^ e) {
		curr_sec = 7;
		open_exam_selector();
	}
	private: System::Void Select_Section_I(System::Object^ sender, System::EventArgs^ e) {
		curr_sec = 8;
		open_exam_selector();
	}
	private: System::Void Select_Section_J(System::Object^ sender, System::EventArgs^ e) {
		curr_sec = 9;
		open_exam_selector();
	}
	private: void open_exam_selector(void) {
		Exam_type et;
		this->Hide();
		et.ShowDialog();
		this->Close();
	}
	};
}
