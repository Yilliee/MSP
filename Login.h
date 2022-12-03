#pragma once
#include "variables.h"
#include "functions.h"
#include "Admin.h"
#include "Teacher.h"
#include "Student.h"

namespace MSP {

	/// <summary>
	/// Summary for Login
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		Login(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}

	private: Label^ Login_Header;
	private: Label^ Username_label;
	private: Label^ Password_label;
	private: TextBox^ Username_textbox;

	private: TextBox^ Password_textbox;
	private: Button^ Login_button;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Login::typeid));
			this->Login_Header = (gcnew Label());
			this->Username_label = (gcnew Label());
			this->Password_label = (gcnew Label());
			this->Username_textbox = (gcnew TextBox());
			this->Password_textbox = (gcnew TextBox());
			this->Login_button = (gcnew Button());
			
			this->SuspendLayout();
			
			// 
			// Login_Header
			// 
			this->Login_Header->Anchor = AnchorStyles::Top;
			this->Login_Header->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->Login_Header->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Login_Header->Location = System::Drawing::Point(10, 47);
			this->Login_Header->Name = L"Login_Header";
			this->Login_Header->Size = System::Drawing::Size(700, 45);
			this->Login_Header->TabIndex = 0;
			this->Login_Header->Text = L"Miniature Student Portal";
			this->Login_Header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Username_label
			// 
			this->Username_label->Anchor = AnchorStyles::None;
			this->Username_label->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Username_label->Location = System::Drawing::Point(180, 185);
			this->Username_label->Name = L"Username_label";
			this->Username_label->Size = System::Drawing::Size(100, 25);
			this->Username_label->TextAlign = ContentAlignment::MiddleLeft;
			this->Username_label->Text = L"Username : ";
			// 
			// Password_label
			// 
			this->Password_label->Anchor = AnchorStyles::None;
			this->Password_label->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Password_label->Location = System::Drawing::Point(180, 225);
			this->Password_label->Name = L"Password_label";
			this->Password_label->Size = System::Drawing::Size(100, 25);
			this->Password_label->TextAlign = ContentAlignment::MiddleLeft;
			this->Password_label->Text = L"Password : ";
			// 
			// Username_textbox
			// 
			this->Username_textbox->Anchor = AnchorStyles::None;
			this->Username_textbox->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Username_textbox->Cursor = Cursors::IBeam;
			this->Username_textbox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Username_textbox->Location = System::Drawing::Point(290, 185);
			this->Username_textbox->MaxLength = 500;
			this->Username_textbox->Name = L"Username_textbox";
			this->Username_textbox->Size = System::Drawing::Size(250, 25);
			this->Username_textbox->TabIndex = 3;
			this->Username_textbox->TextAlign = HorizontalAlignment::Center;
			// 
			// Password_textbox
			// 
			this->Password_textbox->Anchor = AnchorStyles::None;
			this->Password_textbox->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Password_textbox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Password_textbox->Location = System::Drawing::Point(290, 225);
			this->Password_textbox->MaxLength = 500;
			this->Password_textbox->Name = L"Password_textbox";
			this->Password_textbox->Size = System::Drawing::Size(250, 25);
			this->Password_textbox->TabIndex = 4;
			this->Password_textbox->TextAlign = HorizontalAlignment::Center;
			this->Password_textbox->UseSystemPasswordChar = true;
			// 
			// Login_button
			// 
			this->Login_button->Anchor = AnchorStyles::None;
			this->Login_button->FlatStyle = FlatStyle::Popup;
			this->Login_button->Font = (gcnew System::Drawing::Font(L"Segoe UI SemiBold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Login_button->Location = System::Drawing::Point(290, 265);
			this->Login_button->Name = L"Login_button";
			this->Login_button->Size = System::Drawing::Size(250, 30);
			this->Login_button->TabIndex = 5;
			this->Login_button->Text = L"Login";
			this->Login_button->UseVisualStyleBackColor = true;
			this->Login_button->Click += gcnew System::EventHandler(this, &Login::Login_button_Click);
			// 
			// Login
			// 
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(720, 450);
			this->Controls->Add(this->Login_button);
			this->Controls->Add(this->Password_textbox);
			this->Controls->Add(this->Username_textbox);
			this->Controls->Add(this->Password_label);
			this->Controls->Add(this->Username_label);
			this->Controls->Add(this->Login_Header);
			this->ForeColor = System::Drawing::SystemColors::Desktop;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Login";
			this->Text = L"Signin";
			this->AcceptButton = this->Login_button;
			this->ResumeLayout(false);
			this->PerformLayout();
		}

	private: System::Void Login_button_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string username = Stos(Username_textbox->Text);
		std::string pass = Stos(Password_textbox->Text);

		for (int i = 0; i < saved.sections; i++) {
			if (username != "" && pass != "") student_no = authenticate(username, pass, Stu_Cred[i], sizeof(Stu_Cred[i]) / sizeof(*Stu_Cred[i]));
			
			if (student_no != -1) {
				curr_sec = i;
				break;
			}
		}
		teach_no = authenticate(username, pass, Teach_Cred, sizeof(Teach_Cred) / sizeof(*Teach_Cred));
		admin_no = authenticate(username, pass, Admin_Cred, sizeof(Admin_Cred) / sizeof(*Admin_Cred));
		if (admin_no != -1 || (No_Admin_Cred_available && username == Default_Admin_Cred.username && pass == Default_Admin_Cred.pass) ){
			// Open admin home page
			Admin ahp;
			// Hide the currrent winform, open the new one and then close the old one.
			this->Hide();
			ahp.ShowDialog();
			this->Close();
		}
		if (student_no != -1) {
			// Open stu home page
			Student shp;
			// Hide the currrent winform, open the new one and then close the old one.
			this->Hide();
			shp.ShowDialog();
			this->Close();
		}
		else if (teach_no != -1) {
			// Open teach home page
			Teacher thp;
			// Hide the currrent winform, open the new one and then close the old one.
			this->Hide();
			thp.ShowDialog();
			this->Close();

		}
		
		else MessageBox::Show("Incorrect Email or Password.");
	}
};
}
