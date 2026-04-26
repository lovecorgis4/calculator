#include <iostream>
#include <limits>
#include <sstream>
#include <iomanip>

// ---------- Math functions ----------
double Addition(double a, double b) {
    return a + b;
}

double Subtraction(double a, double b) {
    return a - b;
}

double Multiplication(double a, double b) {
    return a * b;
}

double Divide(double a, double b) {
    return a / b;
}

// Function pointer
using MathFunc = double (*)(double, double);

// ---------- UI helper ----------
std::string centerText(const std::string& text, int width) {
    int padding = width - text.length();
    if (padding <= 0) return text;

    int left = padding / 2;
    int right = padding - left;

    return std::string(left, ' ') + text + std::string(right, ' ');
}

// ---------- Input ----------
double getDouble() {
    double value;
    while (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Enter a number: ";
    }
    return value;
}

void waitForEnter() {
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

// ---------- Main ----------
int main() {
    int option = 0;

    MathFunc operations[] = { Addition, Subtraction, Multiplication, Divide };

    do {
        std::cout << "\n+--------------+\n";
        std::cout << "|Choose option:|\n";
        std::cout << "+--------------+\n";
        std::cout << "1. Addition\n";
        std::cout << "2. Subtraction\n";
        std::cout << "3. Multiplication\n";
        std::cout << "4. Divide\n";
        std::cout << "5. Exit\n";
        std::cout << "Choice: ";

        std::cin >> option;

        if (option == 5) {
            std::cout << "Exiting program...\n";
            break;
        }

        if (option < 1 || option > 5) {
            std::cout << "Invalid option. Choose 1-5.\n";
            continue;
        }

        std::cout << "Enter first number: ";
        double num1 = getDouble();

        std::cout << "Enter second number: ";
        double num2 = getDouble();

        double result = 0;
        bool valid = true;

        if (option == 4 && num2 == 0) {
            std::cout << "Error: Cannot divide by zero.\n";
            valid = false;
        } else {
            result = operations[option - 1](num1, num2);
        }

        if (valid) {
            std::ostringstream oss;
            oss << std::fixed << std::setprecision(2) << result;
            std::string resultStr = "Result: " + oss.str();

            int width = 30;

            std::cout << "+" << std::string(width, '-') << "+\n";
            std::cout << "|" << centerText(resultStr, width) << "|\n";
            std::cout << "+" << std::string(width, '-') << "+\n";
        }

        waitForEnter();

    } while (true);

    return 0;
}
