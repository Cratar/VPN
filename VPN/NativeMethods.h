#pragma once
#include <string>

using namespace System::Runtime::InteropServices;
using namespace System;

public class NativeMethods abstract sealed {

public:
	[DllImport(L"Temp_add_lib.dll")]
		static void Ñountry(std::string country);


};
