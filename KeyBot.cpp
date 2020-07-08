#include <iostream>
#include <Windows.h>
#include <vector>

void ecrireTexte(std::wstring texte) {
    std::wstring msg = texte;

    std::vector<INPUT> vec;
    for (auto ch : msg)
    {
        INPUT input = { 0 };
        input.type = INPUT_KEYBOARD;
        input.ki.dwFlags = KEYEVENTF_UNICODE;
        input.ki.wScan = ch;
        vec.push_back(input);

        input.ki.dwFlags |= KEYEVENTF_KEYUP;
        vec.push_back(input);
    }

    // Cherche la fenetre notepad
    HWND hwnd = FindWindow(L"Notepad", 0);
    if (hwnd)
        SetForegroundWindow(hwnd);
    else
        std::cout << "Pas de bloc-note !\n";

    SendInput(vec.size(), vec.data(), sizeof(INPUT));
}

int main() {
	//system("notepad.exe"); // ouvre un notepad 
    printf("Ouvrez un bloc-note...\n");
	Sleep(5000); // 5s
    printf("C'est parti !\n Appuyez sur S pour m'arreter.\n");
	while (true) {

		if (GetAsyncKeyState(0x53) & 0x1) { // touche s
			return 0;
		}
        ecrireTexte(L"Je possede un labrador de couleur pruneau.\n");
		Sleep(1000);
	}
}