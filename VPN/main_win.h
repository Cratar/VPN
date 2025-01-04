﻿#pragma once

namespace VPN {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;
	using namespace System::Threading::Tasks;
	using namespace System::IO;
	using namespace System::Drawing::Drawing2D;
	using namespace System::Threading;

	/// <summary>
	/// Сводка для main_win
	/// </summary>
	public ref class main_win : public System::Windows::Forms::Form
	{
	public:
		main_win(void)
		{
			InitializeComponent();
			StartClearTXT();
			

			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~main_win()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::PictureBox^ main_photo;
	private: System::Windows::Forms::ProgressBar^ progressBar_main;

	private: System::Windows::Forms::Button^ button_connect_1;



	private:

	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(main_win::typeid));
			this->main_photo = (gcnew System::Windows::Forms::PictureBox());
			this->progressBar_main = (gcnew System::Windows::Forms::ProgressBar());
			this->button_connect_1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->main_photo))->BeginInit();
			this->SuspendLayout();
			// 
			// main_photo
			// 
			this->main_photo->BackColor = System::Drawing::Color::White;
			this->main_photo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"main_photo.BackgroundImage")));
			this->main_photo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->main_photo->Location = System::Drawing::Point(-1, -2);
			this->main_photo->Margin = System::Windows::Forms::Padding(4);
			this->main_photo->Name = L"main_photo";
			this->main_photo->Size = System::Drawing::Size(613, 324);
			this->main_photo->TabIndex = 1;
			this->main_photo->TabStop = false;
			this->main_photo->WaitOnLoad = true;
			this->main_photo->Click += gcnew System::EventHandler(this, &main_win::main_photo_Click);
			// 
			// progressBar_main
			// 
			this->progressBar_main->Location = System::Drawing::Point(16, 15);
			this->progressBar_main->Margin = System::Windows::Forms::Padding(4);
			this->progressBar_main->Name = L"progressBar_main";
			this->progressBar_main->Size = System::Drawing::Size(576, 28);
			this->progressBar_main->TabIndex = 2;
			this->progressBar_main->Move += gcnew System::EventHandler(this, &main_win::progressBar_main_Move);
			
			//MakeButtonRounded(progressBar_main , 15.0f);
			// 
			// button_connect_1
			// 
			this->button_connect_1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->button_connect_1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button_connect_1->Location = System::Drawing::Point(16, 266);
			this->button_connect_1->Margin = System::Windows::Forms::Padding(4);
			this->button_connect_1->Name = L"button_connect_1";
			this->button_connect_1->Size = System::Drawing::Size(124, 28);
			this->button_connect_1->TabIndex = 3;
			this->button_connect_1->Text = L"Подключиться";
			this->button_connect_1->UseVisualStyleBackColor = false;
			this->button_connect_1->Click += gcnew System::EventHandler(this, &main_win::button_connect_Click);
			
			//MakeButtonRounded(this->button_connect_1 , 15.0f);
			// 
			// main_win
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(605, 311);
			this->Controls->Add(this->button_connect_1);
			this->Controls->Add(this->progressBar_main);
			this->Controls->Add(this->main_photo);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximumSize = System::Drawing::Size(623, 358);
			this->MinimumSize = System::Drawing::Size(261, 112);
			this->Name = L"main_win";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"VIPTOP";
			this->Load += gcnew System::EventHandler(this, &main_win::main_win_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->main_photo))->EndInit();
			this->ResumeLayout(false);

		}

									//#Вспомогательные функции 
#pragma endregion
	//	private:
	//		template <typename T>
	//		GraphicsPath^ RoundedRectangle(T rect, float roundSize) {
	//			GraphicsPath^ gp = gcnew GraphicsPath();

	//			// Используем float для всех аргументов AddArc
	//			gp->AddArc((float)rect.X, (float)rect.Y, roundSize, roundSize, 180.0f, 90.0f); // Левый верхний угол
	//			gp->AddArc((float)(rect.X + rect.Width - roundSize), (float)rect.Y, roundSize, roundSize, 270.0f, 90.0f); // Правый верхний угол
	//			gp->AddArc((float)(rect.X + rect.Width - roundSize), (float)(rect.Y + rect.Height - roundSize), roundSize, roundSize, 0.0f, 90.0f); // Правый нижний угол
	//			gp->AddArc((float)rect.X, (float)(rect.Y + rect.Height - roundSize), roundSize, roundSize, 90.0f, 90.0f); // Левый нижний угол

	//			gp->CloseFigure();

	//			return gp;
	//		}
	//private:
	//	template <typename T>
	//	void MakeButtonRounded(T^ btn, float roundSize) {
	//		// Получаем область кнопки
	//		System::Drawing::Rectangle rect = System::Drawing::Rectangle(0, 0, btn->Width, btn->Height);

	//		// Создаём закруглённый прямоугольник
	//		System::Drawing::Drawing2D::GraphicsPath^ path = RoundedRectangle(rect, roundSize);

	//		// Устанавливаем область кнопки
	//		btn->Region = gcnew System::Drawing::Region(path);
	//	}

	private :
		String^ ReadTXT(String^ dirFile) {
			try {
				FileStream^ file = gcnew FileStream(dirFile, FileMode::Open, FileAccess::Read, FileShare::Read, 65536, FileOptions::SequentialScan);
				StreamReader^ reader = gcnew StreamReader(file);

				String^ content = reader->ReadToEnd();

				reader->Close();
				file->Close();

				return content;
			}
			catch (Exception^ ex) {
				return nullptr;
			}
		}


		void ProgersBar(String^& text) {
			// Константы для улучшения читаемости
			const int progressMax = 100;
			const int specialConditionThreshold = 89;

			// Настройка ProgressBar
			this->progressBar_main->Visible = true;
			this->progressBar_main->Minimum = 1;
			this->progressBar_main->Maximum = progressMax;
			this->progressBar_main->Value = 1;
			this->progressBar_main->Step = 1;

			try {
				// Основной цикл
				for (int x = 1; x <= progressMax; ++x) {
					if ((text == "Connection_correct.\n" || text == "Disconnect_correct.\n")) {
						this->progressBar_main->Value = progressMax;
						break;
					}
					else if(text->Empty) {
						
						// Изменение цвета ProgressBar на красный при ошибке
						this->progressBar_main->ForeColor = Color::Red;
						
					}

				}
			}
			catch (System::ComponentModel::Win32Exception^ ex) {
				this->progressBar_main->ForeColor = Color::Red;
				MessageBox::Show("Ошибка: " + ex->Message, "Ошибка соединения",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

	private:
			void ClearTXT() {
		try {

			Process^ process = Process::Start(".\\source\\Start_Clear.vbs");
			//process->WaitForExit(); // Ждем завершения процесса

		}
		catch (Exception^& ex) {

			MessageBox::Show("Ошибка запуска: " + ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

		// Метод для запуска потока
	private:
		void StartClearTXT() {
			try
			{
				Thread^ ThreadClearTXT = gcnew Thread(gcnew ThreadStart(this, &main_win::ClearTXT));
				ThreadClearTXT->IsBackground = true; // Поток завершится при завершении приложения
				ThreadClearTXT->Start();
			}
			catch (System::ComponentModel::Win32Exception^& ex)
			{
				MessageBox::Show("Ошибка: " + ex->Message, "Ошибка запуска потока", MessageBoxButtons::OK, MessageBoxIcon::Error);

			}

		}


									// Основыне функции 
#pragma endregion				


	private: System::Void main_win_Load(System::Object^ sender, System::EventArgs^ e) {


	}


	private: System::Void main_photo_Click(System::Object^ sender, System::EventArgs^ e) {
		

	}

	private:
		System::Void button_connect_Click(System::Object^ sender, System::EventArgs^ e) {
			static bool isConnected = false; // Состояние кнопки
			String^ TextON;
			String^ TextOFF;

			try {
				if (!isConnected) {
					// Запуск процесса подключения VPN
					Process::Start(".\\source\\Start_VPN_ON.vbs");
					this->button_connect_1->Text = "Отключиться";
					isConnected = true;
					// Попытка загрузить лог подключения

					//!!!!!!Сдеалть что бы основной поток ждал когда в логах появится запись!!!!!!

					while (String::IsNullOrEmpty(TextON)) {
						Thread::Sleep(150);
						TextON = ReadTXT("VPN_ON_LOG.txt");
						Thread::Sleep(150);

					}

					// Запуск прогресс-бара только если текст был загружен
					if (!String::IsNullOrEmpty(TextON)) {
						ProgersBar(TextON);
					}
					else
					{
						this->progressBar_main->ForeColor = Color::Red;
						MessageBox::Show("Ошибка: ", "Ошибка запуска", MessageBoxButtons::OK, MessageBoxIcon::Error);
					}

					

				}
				else {
					// Запуск процесса отключения VPN
					Process::Start(".\\source\\End_VPN_OFF.vbs");
					this->button_connect_1->Text = "Подключиться";
					isConnected = false;
					// Попытка загрузить лог отключения
					TextOFF = ReadTXT("VPN_OFF_LOG.txt");


					// Запуск прогресс-бара только если текст был загружен

					while (String::IsNullOrEmpty(TextOFF)) {
						Thread::Sleep(150);
						TextOFF = ReadTXT("VPN_ON_LOG.txt");
						Thread::Sleep(150);

					}

					// Запуск прогресс-бара только если текст был загружен
					if (!String::IsNullOrEmpty(TextOFF)) {
						ProgersBar(TextOFF);

					}
					else
					{
						this->progressBar_main->ForeColor = Color::Red;
						MessageBox::Show("Ошибка: ", "Ошибка завершения ", MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
				}
			}
			catch (System::ComponentModel::Win32Exception^& ex) {
				MessageBox::Show("Ошибка: " + ex->Message, "Ошибка запуска", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}


	private: System::Void progressBar_main_Move(System::Object^ sender, System::EventArgs^ e) {
		

	}
};
}
