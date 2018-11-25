/* main.cpp */

#include <iostream>
#include "equation.cpp"

int main()
{
    setlocale(LC_ALL, "");

    double result;

    double leftX;
    double rightX;
    double accuracy = 0.01;
    std::string method;

    std::cout << "Введите h/H для выбора метода Хорд или n/N - для метода Ньютона: ";
    getline(std::cin, method);

    std::cout << "Введите начало интервала: ";
    std::cin >> leftX;

    std::cout << "Введите конец интервала: ";
    std::cin >> rightX;

    Equation *equation = new Equation(accuracy, leftX, rightX);

    if (method == "n" || method == "N") {
        result = equation ->findToMethodNyutona();
    } else if (method == "h" || method == "H") {
        result = equation -> findToMethodHord();
    } else {
        std::cout << "Метод не выбран!" << std::endl;    
        return 0;
    }

    for (int i=0; i < equation ->pointsX.size(); ++i)
    {
        std::cout << equation ->pointsX[i] 
        << ":" << equation ->pointsY[i] << "\n";
    }
    std::cout << result << std::endl;

    delete equation;

    return 0;
}