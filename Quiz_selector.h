#pragma once
#include "variables.h"
#include "functions.h"
#include "Marksheet.h"

namespace MSP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Quiz_selector
	/// </summary>
	public ref class Quiz_selector : public System::Windows::Forms::Form
	{
	public:
		Quiz_selector(void)
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
		~Quiz_selector()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Quiz_selector_header;
	private: System::Windows::Forms::Button^ Quiz_del_button;
	private: System::Windows::Forms::Button^ New_Quiz_button;
	private: System::Windows::Forms::Button^ Back_from_Quizsel_button;

	private: array<Button^>^ Quizzes = gcnew array<Button^>(Max_Quizzes);


	private: int New_Quiz_button_y = 121 + 31 * (saved.quizzes[curr_subject][curr_sec ]- 1);

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

		void load_buttons(int sec) {
			for (int i = 0; i < Max_Quizzes; i++) {
				if (sec > i) this->Quizzes[i]->Visible = true;
				else this->Quizzes[i]->Visible = false;

				if (sec == 1) this->Quiz_del_button->Visible = false;
				else this->Quiz_del_button->Visible = true;

				if (sec == Max_Quizzes) this->New_Quiz_button->Visible = false;
				else this->New_Quiz_button->Visible = true;

			}

		}

#pragma region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Quiz_selector_header = (gcnew System::Windows::Forms::Label());
			this->Quiz_del_button = (gcnew System::Windows::Forms::Button());
			this->New_Quiz_button = (gcnew System::Windows::Forms::Button());
			this->Back_from_Quizsel_button = (gcnew System::Windows::Forms::Button());

			for (int i = 0; i < Max_Quizzes; i++) {
				this->Quizzes[i] = (gcnew System::Windows::Forms::Button());
			}

			this->SuspendLayout();
			
			// 
			// Quiz_selector_header
			// 
			this->Quiz_selector_header->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Quiz_selector_header->AutoSize = true;
			this->Quiz_selector_header->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Quiz_selector_header->Location = System::Drawing::Point(223, 43);
			this->Quiz_selector_header->Name = L"Quiz_selector_header";
			this->Quiz_selector_header->Size = System::Drawing::Size(200, 31);
			this->Quiz_selector_header->TabIndex = 0;
			this->Quiz_selector_header->Text = L"Select a Quiz:";
			// 
			// Quizzes_Array
			// 
			int y_pos = 90;
			for (int i = 0; i < Max_Quizzes; i++) {
				this->Quizzes[i]->Anchor = System::Windows::Forms::AnchorStyles::Top;
				this->Quizzes[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				this->Quizzes[i]->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				this->Quizzes[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Quizzes[i]->Location = System::Drawing::Point(225, y_pos);
				this->Quizzes[i]->Name = std_to_System_string(System_to_std_string("Quiz_ ") + std::to_string(i + 1) + "_button");
				this->Quizzes[i]->Size = System::Drawing::Size(200, 25);
				this->Quizzes[i]->TabIndex = 1;
				this->Quizzes[i]->Text = std_to_System_string(System_to_std_string("Quiz no. ") + std::to_string(i + 1));
				this->Quizzes[i]->UseVisualStyleBackColor = false;
				y_pos += 31;
			}
			// Currently max_quizzes is 10 ( 0 - 9 )
			this->Quizzes[0]->Click += gcnew System::EventHandler(this, &Quiz_selector::Select_quiz_1);
			this->Quizzes[1]->Click += gcnew System::EventHandler(this, &Quiz_selector::Select_quiz_2);
			this->Quizzes[2]->Click += gcnew System::EventHandler(this, &Quiz_selector::Select_quiz_3);
			this->Quizzes[3]->Click += gcnew System::EventHandler(this, &Quiz_selector::Select_quiz_4);
			this->Quizzes[4]->Click += gcnew System::EventHandler(this, &Quiz_selector::Select_quiz_5);
			this->Quizzes[5]->Click += gcnew System::EventHandler(this, &Quiz_selector::Select_quiz_6);
			this->Quizzes[6]->Click += gcnew System::EventHandler(this, &Quiz_selector::Select_quiz_7);
			this->Quizzes[7]->Click += gcnew System::EventHandler(this, &Quiz_selector::Select_quiz_8);
			this->Quizzes[8]->Click += gcnew System::EventHandler(this, &Quiz_selector::Select_quiz_9);
			this->Quizzes[9]->Click += gcnew System::EventHandler(this, &Quiz_selector::Select_quiz_10);

			// 
			// Quiz_del_button
			// 
			this->Quiz_del_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Quiz_del_button->BackColor = System::Drawing::Color::Red;
			this->Quiz_del_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Quiz_del_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Quiz_del_button->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->Quiz_del_button->Location = System::Drawing::Point(400, New_Quiz_button_y - 31);
			this->Quiz_del_button->Name = L"Quiz_del_button";
			this->Quiz_del_button->Size = System::Drawing::Size(25, 25);
			this->Quiz_del_button->TabIndex = 11;
			this->Quiz_del_button->Text = L"X";
			this->Quiz_del_button->UseVisualStyleBackColor = false;
			this->Quiz_del_button->Visible = false;
			this->Quiz_del_button->Click += gcnew System::EventHandler(this, &Quiz_selector::Delete_a_Quizzes);
			// 
			// New_Quiz_button
			//
			this->New_Quiz_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->New_Quiz_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->New_Quiz_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->New_Quiz_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->New_Quiz_button->Location = System::Drawing::Point(225, New_Quiz_button_y);
			this->New_Quiz_button->Name = L"New_Quiz_button";
			this->New_Quiz_button->Size = System::Drawing::Size(200, 25);
			this->New_Quiz_button->TabIndex = 12;
			this->New_Quiz_button->Text = L"Create a New Quiz";
			this->New_Quiz_button->UseVisualStyleBackColor = false;
			this->New_Quiz_button->Visible = true;
			this->New_Quiz_button->Click += gcnew System::EventHandler(this, &Quiz_selector::Create_New_Quizzes);

			// 
			// Back_to_home_button
			// 
			this->Back_from_Quizsel_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Back_from_Quizsel_button->BackColor = System::Drawing::Color::Lavender;
			this->Back_from_Quizsel_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Back_from_Quizsel_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Back_from_Quizsel_button->Location = System::Drawing::Point(New_Quiz_button->Left, New_Quiz_button->Top + 31);
			if (saved.quizzes[curr_subject][curr_quiz] == Max_Sections)
				this->Back_from_Quizsel_button->Top -= 35;
			this->Back_from_Quizsel_button->Name = L"Back_from_secsel_button";
			this->Back_from_Quizsel_button->Size = System::Drawing::Size(200, 25);
			this->Back_from_Quizsel_button->Text = L"Go Back to exam selector";
			this->Back_from_Quizsel_button->UseVisualStyleBackColor = false;
			this->Back_from_Quizsel_button->Visible = true;
			this->Back_from_Quizsel_button->Click += gcnew System::EventHandler(this, &Quiz_selector::back_to_exam_type);

			// 
			// Quiz_selector
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(684, 412);
			this->Controls->Add(this->Quiz_selector_header);
			this->Controls->Add(this->New_Quiz_button);
			this->Controls->Add(this->Quiz_del_button);
			this->Controls->Add(this->Back_from_Quizsel_button);
			for (int i = 0; i < Max_Quizzes; i++)
				this->Controls->Add(this->Quizzes[i]);

			this->Name = L"Quiz_selector";
			this->Text = L"Quizzes Management";
			this->Load += gcnew System::EventHandler(this, &Quiz_selector::Quiz_selector_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Quiz_selector_Load(System::Object^ sender, System::EventArgs^ e) {
		load_buttons(saved.quizzes[curr_subject][curr_sec]);
	}
	private: System::Void Select_quiz_1(System::Object^ sender, System::EventArgs^ e) {
		curr_quiz = 0;
		open_marksheet();
	}
	private: System::Void Select_quiz_2(System::Object^ sender, System::EventArgs^ e) {
		curr_quiz = 1;
		open_marksheet();
	}
	private: System::Void Select_quiz_3(System::Object^ sender, System::EventArgs^ e) {
		curr_quiz = 2;
		open_marksheet();
	}
	private: System::Void Select_quiz_4(System::Object^ sender, System::EventArgs^ e) {
		curr_quiz = 3;
		open_marksheet();
	}
	private: System::Void Select_quiz_5(System::Object^ sender, System::EventArgs^ e) {
		curr_quiz = 4;
		open_marksheet();
	}
	private: System::Void Select_quiz_6(System::Object^ sender, System::EventArgs^ e) {
		curr_quiz = 5;
		open_marksheet();
	}
	private: System::Void Select_quiz_7(System::Object^ sender, System::EventArgs^ e) {
		curr_quiz = 6;
		open_marksheet();
	}
	private: System::Void Select_quiz_8(System::Object^ sender, System::EventArgs^ e) {
		curr_quiz = 7;
		open_marksheet();
	}
	private: System::Void Select_quiz_9(System::Object^ sender, System::EventArgs^ e) {
		curr_quiz = 8;
		open_marksheet();
	}
	private: System::Void Select_quiz_10(System::Object^ sender, System::EventArgs^ e) {
		curr_quiz = 9;
		open_marksheet();
	}
	private: System::Void Create_New_Quizzes(System::Object^ sender, System::EventArgs^ e) {
		load_buttons(++saved.quizzes[curr_subject][curr_sec]);

		// -1 cause saved.quizzes[*] start from 1 and array indexes start from 0
		this->New_Quiz_button->Left = this->Quizzes[saved.quizzes[curr_subject][curr_sec] - 1]->Left;
		this->Quiz_del_button->Left = this->Quizzes[saved.quizzes[curr_subject][curr_sec] - 1]->Left + 175;
		this->Back_from_Quizsel_button->Left = this->New_Quiz_button->Left;

		this->Quiz_del_button->Top = this->Quizzes[saved.quizzes[curr_subject][curr_sec] - 1]->Top;
		this->New_Quiz_button->Top = this->Quiz_del_button->Top + 31;
		if (saved.quizzes[curr_subject][curr_sec] != Max_Quizzes)
			this->Back_from_Quizsel_button->Top = this->New_Quiz_button->Top + 31;

		this->Quiz_del_button->BringToFront();
	}
	private: System::Void Delete_a_Quizzes(System::Object^ sender, System::EventArgs^ e) {
		load_buttons(--saved.quizzes[curr_subject][curr_sec]);
		// -1 cause saved.quizzes[*] start from 1 and array indexes start from 0
		this->New_Quiz_button->Left = this->Quizzes[saved.quizzes[curr_subject][curr_sec] - 1]->Left;
		this->Quiz_del_button->Left = this->Quizzes[saved.quizzes[curr_subject][curr_sec] - 1]->Left + 175;
		this->Back_from_Quizsel_button->Left = this->New_Quiz_button->Left;

		this->Quiz_del_button->Top = this->Quizzes[saved.quizzes[curr_subject][curr_sec] - 1]->Top;
		this->New_Quiz_button->Top = this->Quiz_del_button->Top + 31;
		this->Back_from_Quizsel_button->Top = this->New_Quiz_button->Top + 31;
		
		this->Quiz_del_button->BringToFront();

	}
	private: System::Void back_to_exam_type(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void open_marksheet(Void) {
		std::ofstream settings(settings_file);
		WriteSettings(settings, saved);
		settings.close();

		Marksheet ms;
		this->Hide();
		ms.ShowDialog();
		this->Close();
	}
};
}
