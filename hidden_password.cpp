#include <iostream>
#include <Windows.h>
#include <conio.h>

int main() {
	printf("Enter your password: ");

	std::string password;

	char key;
	while ((key = _getch()) != VK_RETURN) {
		#pragma region functionkeys
		static bool skip = false;

		if (!key || key == 224) { // Prevent function keys, eg. F7, Insert, Delete
			skip = true;
			continue;
		}
		
		if (skip) {
			skip = false; // Function keys send 2 inputs, 224 + **, where ** is the key id and 224 prefaces "this is a function key"
			continue;
		}
		#pragma endregion

		#pragma region specialkeys
		if (key == 32) // Ignore space
			continue;
			
		if (key == 8) { // Handle backspaces
			if (password.length()) { // No more password? Nothing to delete.
				password = password.substr(0, password.length() - 1);

				printf("\b \b"); // Move cursor left, replace with a space, now we are one spot over so move back again. This fills the character before with a ' ' char.
			}
			continue;
		}
		#pragma endregion

		password += key;
		std::cout << "*";
	}

	std::cout << "\n" << password;
}