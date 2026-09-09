#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>
#include <string>
#include <sstream> // Required for string stream conversion

/**
 * Multi-Number Calculator - Fully Compatible C++ Implementation
 * CodeAlpha Internship Project
 */

void displayMenu() {
    std::cout << "\n========================================\n";
    std::cout << "       MULTI-NUMBER CALCULATOR          \n";
    std::cout << "========================================\n";
    std::cout << " 1. Chain Addition (+)\n";
    std::cout << " 2. Chain Subtraction (-)\n";
    std::cout << " 3. Chain Multiplication (*)\n";
    std::cout << " 4. Chain Division (/)\n";
    std::cout << " 5. Exit Program\n";
    std::cout << "========================================\n";
    std::cout << "Select an operation (1-5): ";
}

// Safely gets valid numeric input, preventing crashes on invalid text
double getValidNumber(const std::string& prompt) {
    double num;
    while (true) {
        std::cout << prompt;
        if (std::cin >> num) {
            return num;
        }
        std::cout << "[Error] Invalid input. Please enter a valid number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

// Safely gets the count of numbers to calculate
int getValidCount() {
    int count;
    while (true) {
        std::cout << "How many numbers do you want to calculate? (Minimum 2): ";
        if (std::cin >> count && count >= 2) {
            return count;
        }
        std::cout << "[Error] Please enter an integer greater than or equal to 2.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main() {
    int choice = 0;
    std::cout << std::fixed << std::setprecision(2);

    while (true) {
        displayMenu();

        if (!(std::cin >> choice)) {
            std::cout << "\n[Error] Invalid choice! Please enter a number between 1 and 5.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (choice == 5) {
            std::cout << "\nExiting calculator. Thank you and goodbye!\n";
            break;
        }

        if (choice < 1 || choice > 5) {
            std::cout << "\n[Error] Out of range! Please select an option between 1 and 5.\n";
            continue;
        }

        int count = getValidCount();
        std::vector<double> numbers(count);

        for (int i = 0; i < count; ++i) {
            // Built using std::stringstream to avoid std::to_string compiler issues
            std::stringstream promptStream;
            promptStream << "Enter number " << (i + 1) << ": ";
            numbers[i] = getValidNumber(promptStream.str());
        }

        double result = numbers[0];
        bool hasError = false;

        switch (choice) {
            case 1: // Addition
                for (size_t i = 1; i < numbers.size(); ++i) {
                    result += numbers[i];
                }
                std::cout << "\n>>> Result: " << numbers[0];
                for (size_t i = 1; i < numbers.size(); ++i) {
                    std::cout << " + " << numbers[i];
                }
                std::cout << " = " << result << "\n";
                break;

            case 2: // Subtraction
                for (size_t i = 1; i < numbers.size(); ++i) {
                    result -= numbers[i];
                }
                std::cout << "\n>>> Result: " << numbers[0];
                for (size_t i = 1; i < numbers.size(); ++i) {
                    std::cout << " - " << numbers[i];
                }
                std::cout << " = " << result << "\n";
                break;

            case 3: // Multiplication
                for (size_t i = 1; i < numbers.size(); ++i) {
                    result *= numbers[i];
                }
                std::cout << "\n>>> Result: " << numbers[0];
                for (size_t i = 1; i < numbers.size(); ++i) {
                    std::cout << " * " << numbers[i];
                }
                std::cout << " = " << result << "\n";
                break;

            case 4: // Division
                for (size_t i = 1; i < numbers.size(); ++i) {
                    if (numbers[i] == 0.0) {
                        std::cout << "\n[Error] Division by zero encountered at number " << (i + 1) << "!\n";
                        hasError = true;
                        break;
                    }
                    result /= numbers[i];
                }
                if (!hasError) {
                    std::cout << "\n>>> Result: " << numbers[0];
                    for (size_t i = 1; i < numbers.size(); ++i) {
                        std::cout << " / " << numbers[i];
                    }
                    std::cout << " = " << result << "\n";
                }
                break;

            default:
                std::cout << "\n[Error] Unexpected selection.\n";
                break;
        }
    }

    return 0;
}
