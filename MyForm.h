#pragma once
#include "list.h"
#include <string>
#include <msclr/marshal_cppstd.h>
#include <iostream>
namespace KPV11 {
	LIST mylist;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ ButtonAdd;
	private: System::Windows::Forms::Button^ buttonEdit;
	private: System::Windows::Forms::Button^ buttonDelete;
	protected:

	protected:


	private: System::Windows::Forms::TextBox^ textBoxName;

	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Speed;




	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->ButtonAdd = (gcnew System::Windows::Forms::Button());
			this->buttonEdit = (gcnew System::Windows::Forms::Button());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Speed = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// ButtonAdd
			// 
			this->ButtonAdd->Location = System::Drawing::Point(7, 151);
			this->ButtonAdd->Name = L"ButtonAdd";
			this->ButtonAdd->Size = System::Drawing::Size(96, 23);
			this->ButtonAdd->TabIndex = 0;
			this->ButtonAdd->Text = L"Добавить";
			this->ButtonAdd->UseVisualStyleBackColor = true;
			this->ButtonAdd->Click += gcnew System::EventHandler(this, &MyForm::buttonAdd_Click);
			// 
			// buttonEdit
			// 
			this->buttonEdit->Location = System::Drawing::Point(109, 151);
			this->buttonEdit->Name = L"buttonEdit";
			this->buttonEdit->Size = System::Drawing::Size(85, 23);
			this->buttonEdit->TabIndex = 1;
			this->buttonEdit->Text = L"Изменить";
			this->buttonEdit->UseVisualStyleBackColor = true;
			this->buttonEdit->Click += gcnew System::EventHandler(this, &MyForm::buttonEdit_Click);
			// 
			// buttonDelete
			// 
			this->buttonDelete->Location = System::Drawing::Point(200, 151);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(87, 23);
			this->buttonDelete->TabIndex = 2;
			this->buttonDelete->Text = L"Удалить";
			this->buttonDelete->UseVisualStyleBackColor = true;
			this->buttonDelete->Click += gcnew System::EventHandler(this, &MyForm::buttonDelete_Click);
			// 
			// textBoxName
			// 
			this->textBoxName->Location = System::Drawing::Point(7, 32);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(305, 22);
			this->textBoxName->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(7, 112);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(305, 22);
			this->textBox2->TabIndex = 4;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(4, 79);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(69, 17);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Скорость";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(4, 12);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 17);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Название";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->id, this->Name,
					this->Speed
			});
			this->dataGridView1->Location = System::Drawing::Point(328, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(774, 569);
			this->dataGridView1->TabIndex = 7;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellClick);
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// id
			// 
			this->id->HeaderText = L"id";
			this->id->MinimumWidth = 6;
			this->id->Name = L"id";
			this->id->Width = 125;
			// 
			// Name
			// 
			this->Name->HeaderText = L"Название";
			this->Name->MinimumWidth = 6;
			this->Name->Name = L"Name";
			this->Name->Width = 125;
			// 
			// Speed
			// 
			this->Speed->HeaderText = L"Скорость";
			this->Speed->MinimumWidth = 6;
			this->Speed->Name = L"Speed";
			this->Speed->Width = 125;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1114, 593);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBoxName);
			this->Controls->Add(this->buttonDelete);
			this->Controls->Add(this->buttonEdit);
			this->Controls->Add(this->ButtonAdd);
			this->Text = L"MyForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:int current_id;
	private:bool showdata(LIST* list)
		//Показывает данные
	{
		dataGridView1->Rows->Clear();
		int rownumber = 0;
		if (moveHead(&mylist) == false)
			return false;
		do
		{
			DataType d;
			get(&mylist, &d);
			dataGridView1->Rows->Add();
			dataGridView1->Rows[rownumber]->Cells[0]->Value = Convert::ToString(list->curr->value.id);
			dataGridView1->Rows[rownumber]->Cells[1]->Value = marshal_as <String^>(list->curr->value.name);
			dataGridView1->Rows[rownumber]->Cells[2]->Value = Convert::ToString(list->curr->value.speed);
			rownumber += 1;
		} while (moveNext(&mylist) == true);
		for (int i = 0; i < dataGridView1->Rows->Count;)
		{
			dataGridView1->Rows[i]->ReadOnly = true;
		}
		return true;
	}
	private:bool checkdata(DataType& dt)
	{
		//Проверка скорости
		if (textBox2->Text == "")
		{
			MessageBox::Show("Скорость : входная строка");
			return false;
		}
		else
		{
			dt.name = marshal_as < std::string>(textBoxName->Text);
		}
		try
		{
			dt.speed = Convert::ToInt32(textBox2->Text);

			if ((dt.speed < 0) || (dt.speed > 800))
			{
				MessageBox::Show("Некорректная скорость ", "Ошибка");
				return false;
			}
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Скорость: " + ex->Message, "Ошибка");
			return false;
		}
		return true;
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		create(&mylist);
		if (readfile(&mylist) == false)
			MessageBox::Show("Ошибка", "Ошибка при открытии файла");
		showdata(&mylist);
	}
	private: System::Void MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		if (savefile(&mylist) == false)
			MessageBox::Show("Ошибка", "Ошибка сохранения файла");
		destroy(&mylist);
	}
	private: System::Void buttonDelete_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (dataGridView1->RowCount < 1)
		{
			MessageBox::Show("В таблице нету строк", "Ошибка");
			return;
		}
		int index;
		try
		{
			index = dataGridView1->CurrentCell->RowIndex;
		}
		catch (...)
		{
		}
		if (index != -1)
		{
			try
			{
				int id = Convert::ToInt32(dataGridView1->Rows[index]->Cells[0]->Value);
				moveHead(&mylist);
				do
				{
					DataType d;
					get(&mylist, &d);
					if (id == d.id)
					{
						del(&mylist);
						break;
					}
				} while (moveNext(&mylist) == true);
				dataGridView1->Rows->Clear();
				showdata(&mylist);
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Вы не ввели данные: " + ex->Message, "Ошибка");
			}
		}
	}
	private: System::Void buttonEdit_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (dataGridView1->RowCount < 1 )
		{
			MessageBox::Show("В таблице нету строк");
			return;
		}
		int index;
		try
		{
			index = dataGridView1->CurrentCell->RowIndex;
		}
		catch (...)
		{
		}
		if (index != 1)
		{
			try
			{
				int id = Convert::ToInt32(dataGridView1->Rows[index]->Cells[0]->Value);
				moveHead(&mylist);
				do
				{
					DataType d;
					get(&mylist, &d);
					if (id == d.id)
					{
						if ((this->checkdata(d) == true))
						{
							set(&mylist, &d);
							break;
						}
					}
				} while (moveNext(&mylist) == true);
				textBoxName->Text = "";
				textBox2->Text = "";
				this->showdata(&mylist);
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Изменение недоступно в данный момент");
			}
		}
	}
	private: System::Void buttonAdd_Click(System::Object^ sender, System::EventArgs^ e)
	{
		try
		{
			DataType dt;
			if ((checkdata(dt) == true))
			{
				add(&mylist, &dt);
				this->showdata(&mylist);
				textBoxName->Text = "";
				textBox2->Text = "";
			}
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Вы не ввели данные: " + ex->Message, "Ошибка");
		}
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e)
	{

	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
	{

	}
	private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) 
	{
		if (moveHead(&mylist) == false)
		{
			MessageBox::Show("В таблице нету строчек");
			return;
		}
		this->current_id = Convert::ToInt32(dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[0]->Value);
		moveHead(&mylist);
		do
		{
			DataType d;
			get(&mylist, &d);
			if (current_id == d.id)
			{
				textBoxName->Text = marshal_as <String^>(d.name);
				textBox2->Text = Convert::ToString(d.speed);
				break;
			}
		} while(moveNext(&mylist) == true);
	}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
