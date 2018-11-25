/* main.cpp */

#include <iostream>
#include "equation.cpp"

int main()
{
    setlocale(LC_ALL, "");

    double leftX;
    double rightX;
    double accuracy = 0.01;

    std::cout << "Введите начало интервала: ";
    std::cin >> leftX;

    std::cout << "Введите конец интервала: ";
    std::cin >> rightX;

    Equation *equation = new Equation(accuracy, leftX, rightX);

    double result = equation ->findToMethodNyutona();
    
    for (int i=0; i < equation ->pointsX.size(); ++i)
    {
        std::cout << equation ->pointsX[i] 
        << ":" << equation ->pointsY[i] << "\n";
    }
    std::cout << result << std::endl;
}