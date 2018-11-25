/* equation.h */
#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>
#pragma once

class Equation
{
private:
    double accuracy;
    double leftPointX;
    double rightPointX;

public:
    Equation(double, double, double);
    ~Equation();

    std::vector<double> pointsX;
    std::vector<double> pointsY;

    double findEquation(double);

    double findDerivativeEquation1(double);

    double findDerivativeEquation2(double);

    double initApproximation();

    double findToMethodHord();

    double findToMethodNyutona();

    double IsIntervalFabs();

    std::vector<std::tuple<double, double>> getPoints();

    void setPoint(double, double);
    
};