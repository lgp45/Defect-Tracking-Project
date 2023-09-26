#include "MainWindow.h"

using namespace PorterQADefectTrackingSystemv5;
[STAThreadAttribute]

void main()
{

	MainWindow window;
	window.ShowDialog();


	//to open a process/window in C++ unmanaged
	/*
	#include <shellapi.h>
	#include <string>

	int main() {
		std::string fileName = "example.txt";
		ShellExecute(NULL, "open", "notepad.exe", fileName.c_str(), NULL, SW_SHOW);

		return 0;
	}
	*/
	
}