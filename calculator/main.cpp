#include <iostream>
#include <cstdlib>
#include <limits>

int Multiplication(int a, int b) {
    return a * b;
}

int Subtraction(int a, int b) {
    return a - b;
}

int Addition(int a, int b) {
    return a + b;
}

int Divide(int a, int b) {
    return a / b;
}

void waitForEnter()
{
    std::cout << "\nPress Enter To Continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

int main()
{
    int option = 0;

    do {
        std::system("cls");

        std::cout << "Choose option:\n";
        std::cout << "1. Addition\n";
        std::cout << "2. Subtraction\n";
        std::cout << "3. Multiplication\n";
        std::cout << "4. Divide\n";

        std::cin >> option;
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 4." << std::endl;
            waitForEnter();
            continue;
        }

        int num1 = 0;
        int num2 = 0;
        int result = 0;
        bool validChoice = true;

        if (option == 1) {
            std::cout << "Enter first number: ";
            std::cin >> num1;
            std::cout << "Enter second number: ";
            std::cin >> num2;
            result = Addition(num1, num2);
        }
        else if (option == 2) {
            std::cout << "Enter first number: ";
            std::cin >> num1;
            std::cout << "Enter second number: ";
            std::cin >> num2;
            result = Subtraction(num1, num2);
        }
        else if (option == 3) {
            std::cout << "Enter first number: ";
            std::cin >> num1;
            std::cout << "Enter second number: ";
            std::cin >> num2;
            result = Multiplication(num1, num2);
        }
        else if (option == 4) {
            std::cout << "Enter first number: ";
            std::cin >> num1;
            std::cout << "Enter second number: ";
            std::cin >> num2;
            result = Divide(num1, num2);
        }
        else {
            validChoice = false;
            std::cout << "Invalid option. Please choose 1-4." << std::cin.get();
        }

        if (validChoice && option >= 1 && option <= 4) {
            std::cout << "Result: " << result << std::cin.get();
        }

        if (option != 4) {
            waitForEnter();
        }

    } while (option != 4);

    return 0;
}
 