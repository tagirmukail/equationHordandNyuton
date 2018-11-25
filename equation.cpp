/* equation.cpp */

#include <iostream>
#include <cmath>
#include <vector>
#include "equation.h"

Equation::Equation(double accuracy, double leftX, double rightX)
{
    Equation::accuracy = accuracy;
    Equation::leftPointX = leftX;
    Equation::rightPointX = rightX;
}

// проверка интервала
double Equation::IsIntervalFabs()
{
    return fabs(Equation::rightPointX - Equation::leftPointX) > Equation::accuracy;
}

// нахождение результата уравнения от x
double Equation::findEquation(double x)
{
    return pow(x, 4.0) - (2 * x) - 4;
}
// нахождение первой производной функции
double Equation::findDerivativeEquation1(double x)
{
    return 4 * pow(x, 3.0) - 2;
}

// нахождение второй производной функции
double Equation::findDerivativeEquation2(double x)
{
    return 12 * pow(x, 2.0);
}

// Выбор начального приближения
double Equation::initApproximation()
{
    return Equation::findDerivativeEquation1(Equation::leftPointX)*Equation::findDerivativeEquation2(Equation::leftPointX) > 0 ? Equation::rightPointX : Equation::leftPointX;
}

// Добавление точки функции
void Equation::setPoint(double x, double y)
{
        Equation::pointsY.push_back(y);
        Equation::pointsX.push_back(x);
}

// Нахождение корня уравнения методом Хорд
double Equation::findToMethodHord() {
    Equation::pointsX.clear();
    Equation::pointsY.clear();

    while (Equation::IsIntervalFabs()) {
        Equation::rightPointX = Equation::leftPointX - (Equation::leftPointX - Equation::rightPointX)
        * Equation::findEquation(Equation::leftPointX) 
        / (Equation::findEquation(Equation::leftPointX) - Equation::findEquation(Equation::rightPointX));

        Equation::leftPointX = Equation::rightPointX - (Equation::rightPointX - Equation::leftPointX) 
        * Equation::findEquation(Equation::rightPointX) 
        / (Equation::findEquation(Equation::rightPointX) - Equation::findEquation(Equation::leftPointX));
        
        Equation::setPoint(Equation::leftPointX, Equation::findEquation(Equation::leftPointX));
        Equation::setPoint(Equation::rightPointX, Equation::findEquation(Equation::rightPointX));
    } 

    return Equation::leftPointX;
}

// Нахождение корня уравнения методом Ньютона
double Equation::findToMethodNyutona()
{
    Equation::pointsX.clear();
    Equation::pointsY.clear();

    double initX = Equation::initApproximation();

    Equation::leftPointX = initX;
    Equation::rightPointX = initX - Equation::findEquation(initX) / Equation::findDerivativeEquation1(initX);

    Equation::setPoint(Equation::leftPointX, Equation::findEquation(Equation::leftPointX));
    Equation::setPoint(Equation::rightPointX, Equation::findEquation(Equation::rightPointX));

    while(Equation::IsIntervalFabs()) 
    {
        Equation::leftPointX = Equation::rightPointX;
        Equation::rightPointX = Equation::rightPointX - Equation::findEquation(Equation::rightPointX) / Equation::findDerivativeEquation1(Equation::rightPointX);

        Equation::setPoint(Equation::leftPointX, Equation::findEquation(Equation::leftPointX));
        Equation::setPoint(Equation::rightPointX, Equation::findEquation(Equation::rightPointX));
    }

    return Equation::rightPointX;
}

Equation::~Equation()
{

}