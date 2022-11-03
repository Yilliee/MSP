#pragma once
#include "variables.h"
#include "functions.h"

namespace MSP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for Subject_allotment
	/// </summary>
	public ref class Subject_allotment : public System::Windows::Forms::Form
	{
	public:
		Subject_allotment(void)
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
		~Subject_allotment()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ Sub_allot_header;
	private: System::Windows::Forms::Label^ Sr_header;
	private: System::Windows::Forms::Label^ ID_header;
	private: System::Windows::Forms::Label^ Name_header;
	private: array<System::Windows::Forms::Label^>^ Subject_header = gcnew array<System::Windows::Forms::Label^>(Max_subject_per_teacher);
	
	private: System::Windows::Forms::Button^ Back_button;
	private: System::Windows::Forms::Button^ Save_button;

	private: array<System::Windows::Forms::Label^>^ Sr_l = gcnew array<System::Windows::Forms::Label^>(Max_Teachers);
	private: array<System::Windows::Forms::Label^>^ ID_l = gcnew array<System::Windows::Forms::Label^>(Max_Teachers);
	private: array<System::Windows::Forms::Label^>^ Name_l = gcnew array<System::Windows::Forms::Label^>(Max_Teachers);
	private: array<System::Windows::Forms::ComboBox^>^ Subject_cb = gcnew array<System::Windows::Forms::ComboBox^>(Max_Teachers * Max_subject_per_teacher);

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
			this->Sub_allot_header = (gcnew System::Windows::Forms::Label());
			this->Sr_header = (gcnew System::Windows::Forms::Label());
			this->ID_header = (gcnew System::Windows::Forms::Label());
			this->Name_header = (gcnew System::Windows::Forms::Label());
			
			for (int i = 0; i < Max_subject_per_teacher; i++) {
				this->Subject_header[i] = (gcnew System::Windows::Forms::Label());
			}
			
			this->Back_button = (gcnew System::Windows::Forms::Button());
			this->Save_button = (gcnew System::Windows::Forms::Button());
			
			for (int i = 0; i < Max_Teachers; i++) {
				this->Sr_l[i] = (gcnew System::Windows::Forms::Label());
				this->ID_l[i] = (gcnew System::Windows::Forms::Label());
				this->Name_l[i] = (gcnew System::Windows::Forms::Label());
			}

			for (int i = 0; i < Max_Teachers; i++) {
				for (int j = 0; j < Max_subject_per_teacher; j++ ){
					this->Subject_cb[i*Max_subject_per_teacher + j] = (gcnew System::Windows::Forms::ComboBox());
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
			this->Sub_allot_header->Size = System::Drawing::Size(1210, 31);
			this->Sub_allot_header->TabIndex = 0;
			this->Sub_allot_header->Text = L"Subject Allotment";
			this->Sub_allot_header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			// 
			// Back button
			//
			this->Back_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
			this->Back_button->BackColor = System::Drawing::Color::Lavender;
			this->Back_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Back_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Back_button->Location = System::Drawing::Point(5, 61);
			this->Back_button->Name = L"Back_button";
			this->Back_button->Size = System::Drawing::Size(100, 23);
			this->Back_button->TabIndex = 1;
			this->Back_button->Text = L"Back";
			this->Back_button->UseVisualStyleBackColor = false;
			this->Back_button->Click += gcnew System::EventHandler(this, &Subject_allotment::Back_button_Click);
			// 
			// Save button
			//
			this->Save_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Right | System::Windows::Forms::AnchorStyles::Top);
			this->Save_button->BackColor = System::Drawing::Color::Lavender;
			this->Save_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Save_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Save_button->Location = System::Drawing::Point(1225, 61);
			this->Save_button->Name = L"Save_button";
			this->Save_button->Size = System::Drawing::Size(100, 23);
			this->Save_button->TabIndex = 1;
			this->Save_button->Text = L"Save";
			this->Save_button->UseVisualStyleBackColor = false;
			this->Save_button->Click += gcnew System::EventHandler(this, &Subject_allotment::Save_button_Click);
			
			//
			// Sr header
			// 
			this->Sr_header->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
			this->Sr_header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Sr_header->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
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
			this->ID_header->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
			this->ID_header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ID_header->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
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
			this->Name_header->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
			this->Name_header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Name_header->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
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
				this->Subject_header[i]->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
				this->Subject_header[i]->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				this->Subject_header[i]->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				this->Subject_header[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Subject_header[i]->Location = System::Drawing::Point(x_pos_sub, this->ID_header->Top);
				this->Subject_header[i]->Name = std_to_System_string("Subject_header_" + std::to_string(i + 1));
				this->Subject_header[i]->Size = System::Drawing::Size(200, 25);
				this->Subject_header[i]->TabIndex = tab_index;
				this->Subject_header[i]->Text = std_to_System_string("Subject " + std::to_string(i+1));
				this->Subject_header[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				x_pos_sub += this->Subject_header[i]->Width + 5;
				tab_index ++;
			}

			// 
			// Sr label 
			// 
			int y_pos = 124;
			tab_index = 5 + Max_subject_per_teacher;
			for ( int i = 0; i < Max_Teachers; i++ ){
				this->Sr_l[i]->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
				this->Sr_l[i]->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				this->Sr_l[i]->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				this->Sr_l[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Sr_l[i]->Location = System::Drawing::Point(5, y_pos);
				this->Sr_l[i]->Name = std_to_System_string("Sr_l_" + std::to_string(i+1));
				this->Sr_l[i]->Size = System::Drawing::Size(35, 25);
				this->Sr_l[i]->TabIndex = tab_index;
				this->Sr_l[i]->Text = std_to_System_string(std::to_string(i+1) + ")");
				this->Sr_l[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				y_pos += this->Sr_l[i]->Height + 6;
				tab_index += 3 + Max_subject_per_teacher;
			}
			//
			// ID label
			//
			y_pos = 124, tab_index = 6 + Max_subject_per_teacher;
			for (int i = 0; i < Max_Teachers; i++) {
				this->ID_l[i]->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
				this->ID_l[i]->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				this->ID_l[i]->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				this->ID_l[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->ID_l[i]->Location = System::Drawing::Point(this->Sr_l[i]->Right + 5, y_pos);
				this->ID_l[i]->Name = std_to_System_string("ID_l_" + std::to_string(i + 1));
				this->ID_l[i]->Size = System::Drawing::Size(75, this->Sr_l[i]->Height);
				this->ID_l[i]->TabIndex = tab_index;
				this->ID_l[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				y_pos += this->ID_l[i]->Height + 6;
				tab_index += 3 + Max_subject_per_teacher;
			}
			//
			// Name label
			//
			y_pos = 124, tab_index = 7 + Max_subject_per_teacher;
			for (int i = 0; i < Max_Teachers; i++) {
				this->Name_l[i]->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
				this->Name_l[i]->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				this->Name_l[i]->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				this->Name_l[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Name_l[i]->Location = System::Drawing::Point(this->ID_l[i]->Right + 5, y_pos);
				this->Name_l[i]->Name = std_to_System_string("Name_l_" + std::to_string(i + 1));
				this->Name_l[i]->Size = System::Drawing::Size(175, this->ID_l[i]->Height);
				this->Name_l[i]->TabIndex = tab_index;
				this->Name_l[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				y_pos += this->Name_l[i]->Height + 6;
				tab_index += 3 + Max_subject_per_teacher;
			}
			//
			// Subject ComboBox
			//
			y_pos = 124, tab_index = 8 + Max_subject_per_teacher;
			for (int i = 0; i < Max_Teachers; i++) {
				int x_pos_cb = this->Name_l[i]->Right + 5;
				for (int j = 0; j < Max_subject_per_teacher; j++){
					this->Subject_cb[(i * Max_subject_per_teacher) + j]->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top);
					this->Subject_cb[(i * Max_subject_per_teacher) + j]->BackColor = System::Drawing::Color::WhiteSmoke;
					this->Subject_cb[(i * Max_subject_per_teacher) + j]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(0)));
					this->Subject_cb[(i * Max_subject_per_teacher) + j]->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
					this->Subject_cb[(i * Max_subject_per_teacher) + j]->Location = System::Drawing::Point(x_pos_cb, y_pos);
					this->Subject_cb[(i * Max_subject_per_teacher) + j]->Name = std_to_System_string("Week_" + std::to_string(i + 1) + "_lec1_h");
					this->Subject_cb[(i * Max_subject_per_teacher) + j]->Size = System::Drawing::Size(200, this->Name_l[i]->Height);
					this->Subject_cb[(i * Max_subject_per_teacher) + j]->TabIndex = tab_index;
					this->Subject_cb[(i * Max_subject_per_teacher) + j]->SelectedIndexChanged += gcnew System::EventHandler(this, &MSP::Subject_allotment::ComboBox_value_changed);;
					x_pos_cb += this->Subject_cb[(i * Max_subject_per_teacher) + j]->Width + 5;
					tab_index++;
				}
				tab_index += 3;
				y_pos += this->Subject_cb[i * Max_subject_per_teacher]->Height + 6; // The first entry in the current line
			}
			
			// 
			// Subject_allotment
			// 
			
			// Kone futari wa na no yo?
			//this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			//this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(1330, 450);
			this->BackColor = System::Drawing::Color::White;
			this->Controls->Add(this->Sub_allot_header);
			this->Controls->Add(this->Back_button);
			this->Controls->Add(this->Save_button);
			this->Controls->Add(this->Sr_header);
			this->Controls->Add(this->ID_header);
			this->Controls->Add(this->Name_header);
			for (int i = 0; i < Max_subject_per_teacher; i++) {
				this->Controls->Add(Subject_header[i]);
			}
			for (int i = 0; i < Max_Teachers; i++) {
				this->Controls->Add(this->Sr_l[i]);
				this->Controls->Add(this->ID_l[i]);
				this->Controls->Add(this->Name_l[i]);
			}
			for (int i = 0; i < Max_Teachers; i++) {
				for (int j = 0; j < Max_subject_per_teacher; j++) {
					this->Controls->Add(this->Subject_cb[i * Max_subject_per_teacher + j]);
				}
			}

			this->Name = L"Subject_allotment";
			this->Text = L"Subject_allotment";
			this->Load += gcnew System::EventHandler(this, &Subject_allotment::Subject_allotment_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Subject_allotment_Load(System::Object^ sender, System::EventArgs^ e) {
		// Setup the labels according to teacher credentials
		for (int i = 0; i < Max_Teachers; i++) {
			this->ID_l[i]->Text = std_to_System_string(Teach_Cred[i].id);
			this->Name_l[i]->Text = std_to_System_string(Teach_Cred[i].name);
		}
		// Create a list of all possible selections / all currently existing classes.
		List<System::String^>^ All_classes = gcnew List<System::String^>();
		for (int i = 0; i < Max_Subjects; i++) {
			for (int j = 0; j < saved.sections; j++) {
				All_classes->Add(std_to_System_string(System_to_std_string("Section ") + Sec_list[j] + " - " + subjects_details[j][i].course_code + " - " + subjects_details[j][i].name));
			}
		}
		// Add all the possible drop-down menu options to each ComboBox seperately.
		for (int i = 0; i < Max_Teachers; i++) {
			for (int j = 0; j < Max_subject_per_teacher; j++) {
					this->Subject_cb[(i * Max_subject_per_teacher) + j]->Items->AddRange(All_classes->ToArray());
			}
		}
		
		int box_no[Max_Teachers] = { 0 }; // The current box number horizintally that we are dealing with
		for (int i = 0; i < saved.sections; i++) {
			for (int j = 0; j < Max_Subjects; j++) {
				int teacher = subjects_details[i][j].teach_no;
				// Create the string that is part of the ComboBox items from using the subject details struct and set that as the selected item.
				String^ item = std_to_System_string(System_to_std_string("Section ") + Sec_list[i] + " - " + subjects_details[i][j].course_code + " - " + subjects_details[i][j].name);
				this->Subject_cb[teacher * Max_subject_per_teacher + box_no[teacher]]->SelectedItem = item;
				box_no[teacher]++;
			}
		}
	}
	private: System::Void ComboBox_value_changed(System::Object^ sender, System::EventArgs^ e) {
		
		List<System::String^>^ Available_classes = gcnew List<System::String^>();

		// Create a list having all the possible drop-down options
		for (int i = 0; i < Max_Subjects; i++) {
			for (int j = 0; j < saved.sections; j++) {
				Available_classes->Add(std_to_System_string(System_to_std_string("Section ") + Sec_list[j] + " - " + subjects_details[j][i].course_code + " - " + subjects_details[j][i].name));
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
				for (int k = 0; k < Subject_cb[curr_index]->Items->Count; k++)
					Selected_classes->Remove(Subject_cb[curr_index]->Items[k]->ToString());
				
				// From the first ComboBox till the last, recheck for all Selected boxes and remove those selected items from
				// the selected_classes list.
				for (int i = 0; i < Max_Teachers; i++) {
					for (int j = 0; j < Max_subject_per_teacher; j++) {
						if (Subject_cb[i * Max_subject_per_teacher + j]->SelectedIndex != -1)
							Selected_classes->Remove(Subject_cb[i * Max_subject_per_teacher + j]->SelectedItem->ToString());
					}
				}
				
				// Add all the missing entries i.e. those who haven't been selected in any combobox and are missing from current list.
				Subject_cb[curr_index]->Items->AddRange(Selected_classes->ToArray());
				
				// If the current box has a value selected:
				if (this->Subject_cb[curr_index]->SelectedIndex != -1) {
					String^ selection = this->Subject_cb[curr_index]->SelectedItem->ToString();
				
					// Remove the entry that is selected in the current ComboBox from all the ComboBoxes except the current one.
					for (int i = 0; i < Max_Teachers; i++) {
						for (int j = 0; j < Max_subject_per_teacher; j++) {
							if (i * Max_subject_per_teacher + j != curr_index)
								this->Subject_cb[(i * Max_subject_per_teacher) + j]->Items->Remove(selection);
						} // End inner - for (int j = 0; j < Max_subject_per_teacher; j++)
					} // End inner - for (int i = 0; i < Max_Teachers; i++)

				} // End - if (this->Subject_cb[curr_index]->SelectedIndex != -1

			} // End outer - for (int j = 0; j < Max_subject_per_teacher; j++)
		} // End outer - for (int i = 0; i < Max_Teachers; i++)

	} // End - ComboBox_value_changed
	private: System::Void Save_button_Click(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < Max_Teachers; i++) {
			for (int j = 0; j < Max_subject_per_teacher; j++) {
				// If the current ComboBox is selected:
				if (Subject_cb[i * Max_subject_per_teacher + j]->SelectedIndex != -1) {
					std::string course_and_section = System_to_std_string(Subject_cb[i * Max_subject_per_teacher + j]->SelectedItem->ToString());
					int section = -1, course = -1;
					for (int i = 0; i < saved.sections; i++){
						// If the current section is the one which is present in the selected option of the ComboBox then store it
						if (course_and_section.find(System_to_std_string("Section ") + Sec_list[i]) != -1) {
							section = i;
							break;
						}
					}
					if (section == -1) // Handle the error if any
						MessageBox::Show("Selection : " + std_to_System_string(course_and_section) + " - section is -1");
					for (int i = 0; i < Max_Subjects; i++) {
						// If the current section is the one which is present in the selected option of the ComboBox then store it
						if (course_and_section.find(subjects_details[section][i].course_code) != -1) {
							course = i;
							break;
						}
					}
					if (course == -1) // Handle the error if any
						MessageBox::Show("Selection : " + std_to_System_string(course_and_section) + " - Section: " + Sec_list[section] + " - Course is -1");
					// If we have gotten both the section and subject indexes, then update the teacher no.
					subjects_details[section][course].teach_no = i;
				}
			} // End inner - for (int j = 0; j < Max_subject_per_teacher; j++)
		} // End inner - for (int i = 0; i < Max_Teachers; i++)

		// Update the Subject data in files
		for (int i = 0; i < saved.sections; i++) {
			std::ofstream sub_file(Subject_Folder + "Sec_" + Sec_list[i] + ".txt");
			WriteSubjects(sub_file, subjects_details[i], sizeof(subjects_details) / sizeof(*subjects_details), Max_Subjects);
		}
	}
	private: System::Void Back_button_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	};
}
