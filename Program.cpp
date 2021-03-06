#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

/*
 * Terraria Auto Fisher
 * by QJ.js
 */

void rightClick() {
	mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
	Sleep(30);
	mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
	Sleep(30);
}

void moveUp() {
	mouse_event(MOUSEEVENTF_MOVE, 0, -15, 0, 0);
	Sleep(30);
}

void moveDown() {
	mouse_event(MOUSEEVENTF_MOVE, 0, 15, 0, 0);
	Sleep(30);
}

INPUT input;

void pressEsc() {
	input.ki.dwFlags = 0;
	SendInput(1, &input, sizeof(INPUT));
	Sleep(100);

	input.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &input, sizeof(INPUT));
	Sleep(100);
}

int main(int argc, char ** argv)
{
	string in;
	unsigned int i = 10, count;

	cout << "item count: ";
	cin >> in;
	count = stoi(in.c_str(), nullptr, 0);
	cout << "Starting in " << i << "..." << endl;
	while (i-- > 1) {
		Sleep(1000);
		cout << i << "..." << endl;
	}
	Sleep(1000);
	
	input.type = INPUT_KEYBOARD;
	input.ki.wVk = VK_ESCAPE;
	input.ki.wScan = 0;
	input.ki.time = 0;
	input.ki.dwExtraInfo = 0;
	input.ki.dwFlags = 0;

	wchar_t wnd_title[256];

	while (i++ < count) {
		wnd_title[0] = 0;
		GetWindowText(GetForegroundWindow(), wnd_title, sizeof(wnd_title));
		if (wnd_title[0] == 'T') {
			rightClick();
			moveDown();
			rightClick();
			moveUp();

			pressEsc();
			Sleep(100);
			pressEsc();
		}
		else i--;
	}

	return 1;
}
