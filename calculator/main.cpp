#include <iostream>
#include <limits>

int Addition(int a, int b) {
    return a + b;
}

int Subtraction(int a, int b) {
    return a - b;
}

int Multiplication(int a, int b) {
    return a * b;
}

int Divide(int a, int b) {
    return a / b;
}

void waitForEnter() {
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

int getInt() {
    int value;
    while (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Enter a number: ";
    }
    return value;
}

int main() {
    int option = 0;

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

        option = getInt();

        if (option == 5) {
            std::cout << "Exiting program...\n";
            break;
        }

        if (option < 1 || option > 5) {
            std::cout << "Invalid option. Choose 1-5.\n";
            continue;
        }

        std::cout << "Enter first number: ";
        int num1 = getInt();

        std::cout << "Enter second number: ";
        int num2 = getInt();

        int result = 0;
        bool valid = true;

        if (option == 1) result = Addition(num1, num2);
        else if (option == 2) result = Subtraction(num1, num2);
        else if (option == 3) result = Multiplication(num1, num2);
        else if (option == 4) {
            if (num2 == 0) {
                std::cout << "Error: Cannot divide by zero.\n";
                valid = false;
            } else {
                result = Divide(num1, num2);
            }
        }

        if (valid) {
            std::cout << "+---------+\n";
            std::cout << "|Result: " << result << "|\n";
            std::cout << "+---------+\n";
        }

        waitForEnter();

    } while (true);

    return 0;
}