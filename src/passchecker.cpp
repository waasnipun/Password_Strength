#include <iostream>
#include <string>
#include <cctype>
#include <regex>

#include "passchecker.h"

using namespace std;

string passchecker(string& password) {
	
	if (password.length() < 8) {
        return "Weak";
    }

    // Check for lowercase, uppercase, digit, and special character
    bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;
    for (char c : password) {
        if (std::islower(c)) {
            hasLower = true;
        } else if (std::isupper(c)) {
            hasUpper = true;
        } else if (std::isdigit(c)) {
            hasDigit = true;
        } else if (!std::isalnum(c)) {
            hasSpecial = true;
        }
    }

    // Check for consecutive characters (e.g., "123" or "abc")
    std::regex consecutivePattern(R"((\w)\1\1)");
    if (std::regex_search(password, consecutivePattern)) {
        return "Weak";
    }

    int score = 0;

    if (hasLower) score++;
    if (hasUpper) score++;
    if (hasDigit) score++;
    if (hasSpecial) score++;

    // Assign strength based on score
    if (score == 1) {
        return "Weak";
    } else if (score == 2) {
        return "Moderate";
    } else if (score == 3) {
        return "Strong";
    } else if (score == 4) {
        return "VeryStrong";
    }

    return "VeryWeak"; // Default
}