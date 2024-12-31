#pragma once

namespace VPN {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;
	using namespace System::Threading::Tasks;

	/// <summary>
	/// Сводка для main_win
	/// </summary>
	public ref class main_win : public System::Windows::Forms::Form
	{
	public:
		main_win(void)
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
		~main_win()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::PictureBox^ main_photo;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
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
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
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
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(16, 15);
			this->progressBar1->Margin = System::Windows::Forms::Padding(4);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(576, 28);
			this->progressBar1->TabIndex = 2;
			// 
			// button_connect_1
			// 
			int cornerRadius = 15; // Задаём меньший радиус для уменьшенного закругления
			MakeButtonRounded(button_connect_1, cornerRadius);

			this->button_connect_1->Location = System::Drawing::Point(16, 266);
			this->button_connect_1->Margin = System::Windows::Forms::Padding(4);
			this->button_connect_1->Name = L"button_connect_1";
			this->button_connect_1->Size = System::Drawing::Size(124, 28);
			this->button_connect_1->TabIndex = 3;
			this->button_connect_1->Text = L"Подключиться";
			this->button_connect_1->UseVisualStyleBackColor = true;
			this->button_connect_1->Click += gcnew System::EventHandler(this, &main_win::button_connect_Click);
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
			this->Controls->Add(this->progressBar1);
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
#pragma endregion
	private: System::Void main_win_Load(System::Object^ sender, System::EventArgs^ e) {


	}


	private: System::Void main_photo_Click(System::Object^ sender, System::EventArgs^ e) {
		

	}
	private: void MakeButtonRounded(Button^ btn, int cornerRadius) {
		System::Drawing::Drawing2D::GraphicsPath^ gp = gcnew System::Drawing::Drawing2D::GraphicsPath();

		// Углы с заданным радиусом
		gp->AddArc(0, 0, cornerRadius, cornerRadius, 180, 90); // Левый верхний угол
		gp->AddArc(btn->Width, 0, cornerRadius, cornerRadius, 270, 90); // Правый верхний угол
		gp->AddArc(btn->Width, btn->Height - cornerRadius, cornerRadius, cornerRadius, 0, 90); // Правый нижний угол
		gp->AddArc(0, btn->Height - cornerRadius, cornerRadius, cornerRadius, 90, 90); // Левый нижний угол

		// Замыкаем контур
		gp->CloseFigure();

		btn->Region = gcnew System::Drawing::Region(gp);
	}
	private: System::Void button_connect_Click(System::Object^ sender, System::EventArgs^ e ) {
		static bool isConnected = false; // Состояние кнопки


		try
		{
			if (!isConnected) {
				
				Process::Start(".\\source\\test.bat"); //ON  .\\source\\Start_VPN_ON.vbs
				this->button_connect_1->Text = "Отключиться";
				isConnected = true;
			}
			else {
				
				Process::Start(".\\source\\test.bat"); //OFF .\\source\\End_VPN_OFF.vbs
				this->button_connect_1->Text = "Подключиться";
				isConnected = false;
			}
		}
		catch (System::ComponentModel::Win32Exception^& ex)
		{
			MessageBox::Show("Ошибка: " + ex->Message, "Ошибка запуска", MessageBoxButtons::OK, MessageBoxIcon::Error);

		}
	}


};
}
