#include "Login.h"
#include <Windows.h>
#include <string>
#include "variables.h"

using namespace MSP;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Login());
	return 0;
}