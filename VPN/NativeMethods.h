#pragma once

using namespace System::Runtime::InteropServices;
using namespace System;

public ref class NativeMethods abstract sealed {

public:
	[DllImport(L"Temp_add_lib.dll")]
		static void Ñountry(String^ country);


};
