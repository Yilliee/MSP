#pragma once
#include "Quiz_selector.h"
#include "Marksheet.h"

namespace MSP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Exam_type
	/// </summary>
	public ref class Exam_type : public System::Windows::Forms::Form
	{
	public:
		Exam_type(void)
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
		~Exam_type()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Exam_type_header;
	private: System::Windows::Forms::Button^ Quiz_button;
	private: System::Windows::Forms::Button^ Mid_1_button;
	private: System::Windows::Forms::Button^ Mid_2_button;
	private: System::Windows::Forms::Button^ Finals_button;
	private: System::Windows::Forms::Button^ Back_from_Examtype_button;

	protected:


	protected:

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
			this->Exam_type_header = (gcnew System::Windows::Forms::Label());
			this->Quiz_button = (gcnew System::Windows::Forms::Button());
			this->Mid_1_button = (gcnew System::Windows::Forms::Button());
			this->Mid_2_button = (gcnew System::Windows::Forms::Button());
			this->Finals_button = (gcnew System::Windows::Forms::Button());
			this->Back_from_Examtype_button = (gcnew System::Windows::Forms::Button());

			this->SuspendLayout();
			// 
			// Exam_type_header
			// 
			this->Exam_type_header->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Exam_type_header->Font = (gcnew System::Drawing::Font(L"Times New Roman", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Exam_type_header->ForeColor = System::Drawing::SystemColors::Desktop;
			this->Exam_type_header->Location = System::Drawing::Point(12, 9);
			this->Exam_type_header->Name = L"Exam_type_header";
			this->Exam_type_header->Size = System::Drawing::Size(676, 82);
			this->Exam_type_header->TabIndex = 0;
			this->Exam_type_header->Text = L"Select Exam type:";
			this->Exam_type_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Quiz_button
			// 
			this->Quiz_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Quiz_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Quiz_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Quiz_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold));
			this->Quiz_button->ForeColor = System::Drawing::SystemColors::Desktop;
			this->Quiz_button->Location = System::Drawing::Point(250, 142);
			this->Quiz_button->Name = L"Quiz_button";
			this->Quiz_button->Size = System::Drawing::Size(200, 25);
			this->Quiz_button->TabIndex = 1;
			this->Quiz_button->Text = L"Quiz";
			this->Quiz_button->UseVisualStyleBackColor = false;
			this->Quiz_button->Click += gcnew System::EventHandler(this, &Exam_type::Quiz_button_Click);
			// 
			// Mid_1_button
			// 
			this->Mid_1_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Mid_1_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Mid_1_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Mid_1_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold));
			this->Mid_1_button->ForeColor = System::Drawing::SystemColors::Desktop;
			this->Mid_1_button->Location = System::Drawing::Point(250, 197);
			this->Mid_1_button->Name = L"Mid_1_button";
			this->Mid_1_button->Size = System::Drawing::Size(200, 25);
			this->Mid_1_button->TabIndex = 2;
			this->Mid_1_button->Text = L"Midterm # 1";
			this->Mid_1_button->UseVisualStyleBackColor = false;
			this->Mid_1_button->Click += gcnew System::EventHandler(this, &Exam_type::Mid1_button_Click);
			// 
			// Mid_2_button
			// 
			this->Mid_2_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Mid_2_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Mid_2_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Mid_2_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Mid_2_button->ForeColor = System::Drawing::SystemColors::Desktop;
			this->Mid_2_button->Location = System::Drawing::Point(250, 252);
			this->Mid_2_button->Name = L"Mid_2_button";
			this->Mid_2_button->Size = System::Drawing::Size(200, 25);
			this->Mid_2_button->TabIndex = 3;
			this->Mid_2_button->Text = L"Midterm # 2";
			this->Mid_2_button->UseVisualStyleBackColor = false;
			this->Mid_2_button->Click += gcnew System::EventHandler(this, &Exam_type::Mid2_button_Click);
			// 
			// Finals_button
			// 
			this->Finals_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Finals_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Finals_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Finals_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Finals_button->ForeColor = System::Drawing::SystemColors::Desktop;
			this->Finals_button->Location = System::Drawing::Point(250, 307);
			this->Finals_button->Name = L"Finals_button";
			this->Finals_button->Size = System::Drawing::Size(200, 25);
			this->Finals_button->TabIndex = 4;
			this->Finals_button->Text = L"Finals";
			this->Finals_button->UseVisualStyleBackColor = false;
			this->Finals_button->Click += gcnew System::EventHandler(this, &Exam_type::Finals_button_Click);
			// 
			// Back_from_Secsel_button
			// 
			this->Back_from_Examtype_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Back_from_Examtype_button->BackColor = System::Drawing::Color::Lavender;
			this->Back_from_Examtype_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Back_from_Examtype_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Back_from_Examtype_button->Location = System::Drawing::Point(250, 362);
			this->Back_from_Examtype_button->Name = L"Back_to_home_del";
			this->Back_from_Examtype_button->Size = System::Drawing::Size(200, 25);
			this->Back_from_Examtype_button->Text = L"Go Back to home";
			this->Back_from_Examtype_button->UseVisualStyleBackColor = false;
			this->Back_from_Examtype_button->Visible = true;
			this->Back_from_Examtype_button->Click += gcnew System::EventHandler(this, &Exam_type::back_to_secsel);

			// 
			// Exam_type
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(700, 450);
			this->Controls->Add(this->Exam_type_header);
			this->Controls->Add(this->Quiz_button);
			this->Controls->Add(this->Mid_1_button);
			this->Controls->Add(this->Mid_2_button);
			this->Controls->Add(this->Finals_button);
			this->Controls->Add(this->Back_from_Examtype_button);
			this->Name = L"Exam_type";
			this->Text = L"Exam Type Selector";
			this->Load += gcnew System::EventHandler(this, &Exam_type::Exam_type_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Exam_type_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Quiz_button_Click(System::Object^ sender, System::EventArgs^ e) {
		exam_type = Exam_quiz;
		Quiz_selector qsel;
		this->Hide();
		qsel.ShowDialog();
		this->Close();
	}
	private: System::Void Mid1_button_Click(System::Object^ sender, System::EventArgs^ e) {
		exam_type = Exam_mid1;
		load_marksheet();
	}
	private: System::Void Mid2_button_Click(System::Object^ sender, System::EventArgs^ e) {
		exam_type = Exam_mid2; 
		load_marksheet();
	}
	private: System::Void Finals_button_Click(System::Object^ sender, System::EventArgs^ e) {
		exam_type = Exam_final; 
		load_marksheet();
	}
	private: System::Void back_to_secsel(System::Object^ sender, System::EventArgs^ e) {

	}
	private: void load_marksheet(void) {
		Marksheet ms;
		this->Hide();
		ms.ShowDialog();
		this->Close();
	}
};
}
