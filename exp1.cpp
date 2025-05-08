#include <iostream>
#include <string>

bool isValidString(const std::string& str) {
    int state = 0;

    for (char ch : str) {
        switch (state) {
            case 0:
                if (ch == 'a') {
                    state = 1;
                } else {
                    return false;
                }
                break;
            case 1:
                if (ch == 'b' || ch == 'c') {
                    state = 1;
                } else {
                    return false;
                }
                break;
            default:
                return false;
        }
    }

    return state == 1;
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;

    if (isValidString(input)) {
        std::cout << "The string is recognized by the regular expression a(b|c)*.\n";
    } else {
        std::cout << "The string is NOT recognized by the regular expression a(b|c)*.\n";
    }

    return 0;
}