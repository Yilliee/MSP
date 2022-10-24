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
	/// Summary for Sec_mgmt
	/// </summary>
	public ref class Sec_mgmt : public System::Windows::Forms::Form
	{
	public:
		Sec_mgmt(void)
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
		~Sec_mgmt()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Sec_mgmt_header;
	private: System::Windows::Forms::Button^ Sec_del_button;
	private: System::Windows::Forms::Button^ New_Sec_button;

	private: array<Button^>^ Section = gcnew array<Button^>(Max_sections);
	/*
	private: System::Windows::Forms::Button^ Sec_A_button;
	private: System::Windows::Forms::Button^ Sec_B_button;
	private: System::Windows::Forms::Button^ Sec_C_button;
	private: System::Windows::Forms::Button^ Sec_D_button;
	private: System::Windows::Forms::Button^ Sec_E_button;
	private: System::Windows::Forms::Button^ Sec_F_button;
	private: System::Windows::Forms::Button^ Sec_G_button;
	private: System::Windows::Forms::Button^ Sec_H_button;
	private: System::Windows::Forms::Button^ Sec_I_button;
	private: System::Windows::Forms::Button^ Sec_J_button;
	*/
	
	private: int new_sec_button_y = 121 + 31*(saved.sections-1);

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

		void load_buttons(int sec) {
			for (int i = 0; i < Max_sections; i++) {
				if (sec > i) this->Section[i]->Visible = true;
				else this->Section[i]->Visible = false;

				if (sec == 1) this->Sec_del_button->Visible = false;
				else this->Sec_del_button->Visible = true;
				
				if (sec == Max_sections) this->New_Sec_button->Visible = false;
				else this->New_Sec_button->Visible = true;

			}
			
		}

#pragma region Windows Form Designer generated code
		
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Sec_mgmt_header = (gcnew System::Windows::Forms::Label());
			this->Sec_del_button = (gcnew System::Windows::Forms::Button());
			this->New_Sec_button = (gcnew System::Windows::Forms::Button());
			
			for (int i =0; i < Max_sections; i++){
				this->Section[i] = (gcnew System::Windows::Forms::Button());
			}
			
			this->SuspendLayout();
			// 
			// Sec_mgmt_header
			// 
			this->Sec_mgmt_header->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Sec_mgmt_header->AutoSize = true;
			this->Sec_mgmt_header->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Sec_mgmt_header->Location = System::Drawing::Point(223, 43);
			this->Sec_mgmt_header->Name = L"Sec_mgmt_header";
			this->Sec_mgmt_header->Size = System::Drawing::Size(200, 31);
			this->Sec_mgmt_header->TabIndex = 0;
			this->Sec_mgmt_header->Text = L"Select a section:";
			// 
			// Section_Array
			// 
			int y_pos = 90;
			for ( int i = 0; i < Max_sections; i++){
				this->Section[i]->Anchor = System::Windows::Forms::AnchorStyles::Top;
				this->Section[i]->BackColor = System::Drawing::Color::WhiteSmoke;
				this->Section[i]->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				this->Section[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Section[i]->Location = System::Drawing::Point(225, y_pos);
				this->Section[i]->Name = std_to_System_string(System_to_std_string("Sec ") + Sec_list[i] + "_button");
				this->Section[i]->Size = System::Drawing::Size(200, 25);
				this->Section[i]->TabIndex = 1;
				this->Section[i]->Text = std_to_System_string(System_to_std_string("Section ")  +Sec_list[i]);
				this->Section[i]->UseVisualStyleBackColor = false;
				y_pos += 31;
			}

			this->Section[0]->Click += gcnew System::EventHandler(this, &Sec_mgmt::Select_Section_A);
			this->Section[1]->Click += gcnew System::EventHandler(this, &Sec_mgmt::Select_Section_B);
			this->Section[2]->Click += gcnew System::EventHandler(this, &Sec_mgmt::Select_Section_C);
			this->Section[3]->Click += gcnew System::EventHandler(this, &Sec_mgmt::Select_Section_D);
			this->Section[4]->Click += gcnew System::EventHandler(this, &Sec_mgmt::Select_Section_E);
			this->Section[5]->Click += gcnew System::EventHandler(this, &Sec_mgmt::Select_Section_F);
			this->Section[6]->Click += gcnew System::EventHandler(this, &Sec_mgmt::Select_Section_G);
			this->Section[7]->Click += gcnew System::EventHandler(this, &Sec_mgmt::Select_Section_H);
			this->Section[8]->Click += gcnew System::EventHandler(this, &Sec_mgmt::Select_Section_I);
			this->Section[9]->Click += gcnew System::EventHandler(this, &Sec_mgmt::Select_Section_J);
			
			// 
			// Sec_del_button
			// 
			this->Sec_del_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Sec_del_button->BackColor = System::Drawing::Color::Red;
			this->Sec_del_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Sec_del_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Sec_del_button->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->Sec_del_button->Location = System::Drawing::Point(400, new_sec_button_y-31);
			this->Sec_del_button->Name = L"Sec_J_del";
			this->Sec_del_button->Size = System::Drawing::Size(25, 25);
			this->Sec_del_button->TabIndex = 11;
			this->Sec_del_button->Text = L"X";
			this->Sec_del_button->UseVisualStyleBackColor = false;
			this->Sec_del_button->Visible = false;
			this->Sec_del_button->Click += gcnew System::EventHandler(this, &Sec_mgmt::Delete_a_Section);
			// 
			// New_Sec_button
			//
			this->New_Sec_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->New_Sec_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->New_Sec_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->New_Sec_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->New_Sec_button->Location = System::Drawing::Point(225, new_sec_button_y);
			this->New_Sec_button->Name = L"New_Sec_button";
			this->New_Sec_button->Size = System::Drawing::Size(200, 25);
			this->New_Sec_button->TabIndex = 12;
			this->New_Sec_button->Text = L"Create a New Section";
			this->New_Sec_button->UseVisualStyleBackColor = false;
			this->New_Sec_button->Visible = true;
			this->New_Sec_button->Click += gcnew System::EventHandler(this, &Sec_mgmt::Create_New_Section);
			// 
			// Sec_mgmt
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(684, 412);
			this->Controls->Add(this->Sec_mgmt_header);
			this->Controls->Add(this->New_Sec_button);
			this->Controls->Add(this->Sec_del_button);
			
			for ( int i = 0; i < Max_sections; i++)
				this->Controls->Add(this->Section[i]);
			
			this->Name = L"Sec_mgmt";
			this->Text = L"Section Management";
			this->Load += gcnew System::EventHandler(this, &Sec_mgmt::Sec_mgmt_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Sec_mgmt_Load(System::Object^ sender, System::EventArgs^ e) {
		load_buttons(saved.sections);
	}
	private: System::Void Select_Section_A(System::Object^ sender, System::EventArgs^ e) {
		curr_sec = 0;
		open_cred_winform();
	}
	private: System::Void Select_Section_B(System::Object^ sender, System::EventArgs^ e) {
		curr_sec = 1;
		open_cred_winform();
	}
	private: System::Void Select_Section_C(System::Object^ sender, System::EventArgs^ e) {
		curr_sec = 2;
		open_cred_winform();
	}
	private: System::Void Select_Section_D(System::Object^ sender, System::EventArgs^ e) {
		curr_sec = 3;
		open_cred_winform();
	}
	private: System::Void Select_Section_E(System::Object^ sender, System::EventArgs^ e) {
		curr_sec = 4;
		open_cred_winform();
	}
	private: System::Void Select_Section_F(System::Object^ sender, System::EventArgs^ e) {
		curr_sec = 5;
		open_cred_winform();
	}
	private: System::Void Select_Section_G(System::Object^ sender, System::EventArgs^ e) {
		curr_sec = 6;
		open_cred_winform();
	}
	private: System::Void Select_Section_H(System::Object^ sender, System::EventArgs^ e) {
		curr_sec = 7;
		open_cred_winform();
	}
	private: System::Void Select_Section_I(System::Object^ sender, System::EventArgs^ e) {
		curr_sec = 8;
		open_cred_winform();
	}
	private: System::Void Select_Section_J(System::Object^ sender, System::EventArgs^ e) {
		curr_sec = 9;
		open_cred_winform();
	}
	private: System::Void Create_New_Section(System::Object^ sender, System::EventArgs^ e) {
		load_buttons(++saved.sections);
		new_sec_button_y += 31;
		this->New_Sec_button->Location = System::Drawing::Point(223, new_sec_button_y);
		this->Sec_del_button->Location = System::Drawing::Point(398, new_sec_button_y - 31);
		this->Sec_del_button->BringToFront();
	}
	private: System::Void Delete_a_Section(System::Object^ sender, System::EventArgs^ e) {
		load_buttons(--saved.sections);
		new_sec_button_y -= 31; 
		this->New_Sec_button->Location = System::Drawing::Point(223, new_sec_button_y);
		this->Sec_del_button->Location = System::Drawing::Point(398, new_sec_button_y - 31);
		this->Sec_del_button->BringToFront();
	}
	private: System::Void open_cred_winform(Void) {
		std::ofstream settings(settings_file);
		WriteSettings(settings, saved);
		settings.close();
		Cred_Management cred_mg_winfrom;
		this->Hide();
		cred_mg_winfrom.ShowDialog();
		this->Close();
	}
};
}
