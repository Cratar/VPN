#include "main_win.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]


int main(array<String^>^) {

	

	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	VPN::main_win form;
	Application::Run(% form);

}