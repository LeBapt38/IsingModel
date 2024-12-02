#include<iostream>
#include<cmath>
#include"complexe_encaps.hpp"

using namespace std;

Complexe::Complexe(double x_init, double y_init){
    x = x_init;
    y = y_init;
    norme = computeNorme();
    argument = computeArgument();
}

Complexe::Complexe(){
    x = 0;
    y = 0;
    norme = 0;
    argument = 0;
}

void Complexe::affiche(){
    cout << x << "  " << y << endl;
}

double Complexe::getReal() const{
    return x;
}

double Complexe::getIm() const{
    return y;
}

void Complexe::setReal(double a){
    x = a;
    norme = computeNorme();
    argument = computeArgument();
}

double Complexe::computeReal(){
    return norme * cos(argument);
}

double Complexe::computeIm(){
    return norme * sin(argument);
}

void Complexe::setIm(double a){
    y = a;
    norme = computeNorme();
    argument = computeArgument();
}

double Complexe::computeNorme(){
    double n = x*x + y * y;
    return sqrt(n);
}

double Complexe::getNorme() const{
    return norme;
}

void Complexe::setNorme(double a){
    norme = a;
    x = computeReal();
    y = computeIm();
}

double Complexe::computeArgument(){
    return atan2(x, y);
}

double Complexe::getArgument() const{
    return argument;
}

void Complexe::setArgument(double a){
    argument = a;
    x = computeReal();
    y = computeIm();
}

Complexe &Complexe::operator-(Complexe a){
    x -= a.getReal();
    y -= a.getIm();
    norme = computeNorme();
    argument = computeArgument();

    return *this;
}

Complexe & Complexe::operator-(){
    x = -x;
    y = -y;
    argument = computeArgument();
    return *this;
}

Complexe & Complexe::operator/(Complexe a){
    double z = x;
    x = x*a.getReal() + y*a.getIm();
    y = y*a.getReal() - z * a.getIm();
    x /= a.getNorme() * a.getNorme();
    y /= a.getNorme() * a.getNorme();
    norme = 1/norme;
    argument = computeArgument();
    return *this;
}

Complexe& Complexe::operator+= (const Complexe& a){
    x += a.getReal();
    y += a.getIm();
    norme = computeNorme();
    argument = computeArgument();
    return *this;
}

Complexe& Complexe::operator-= (const Complexe& a){
    x -= a.getReal();
    y -= a.getIm();
    norme = computeNorme();
    argument = computeArgument();
    return *this;
}

Complexe& Complexe::operator*= (const Complexe& a){
    double z = x;
    x *= a.getReal();
    x -= a.getIm() * y;
    y *= a.getReal();
    y += a.getIm() * z;
    norme *= a.getNorme();
    argument = computeArgument();
    return *this;
}

Complexe exponentielle(Complexe z){const
    Complexe z_res(exp(z.getReal()) * cos(z.getIm()), exp(z.getReal()) * sin(z.getIm()));
    return z_res;
}

Complexe operator+(Complexe a, Complexe b){
    Complexe res(a.getReal() + b.getReal(), a.getIm() + b.getIm());
    return res;
}

Complexe operator*(Complexe a, Complexe b){
    Complexe res(a.getReal()*b.getReal() - a.getIm()*b.getIm(), a.getReal()*b.getIm() + a.getIm() * b.getReal());
    return res;
}

Complexe operator*(Complexe a, double b){
    Complexe res(a.getReal() * b, a.getIm() * b);
    return res;
}
Complexe operator*(double b, Complexe a){
    Complexe res(a.getReal() * b, a.getIm() * b);
    return res;
}

Complexe operator/ (double left, Complexe right){
    double n = left / right.getNorme();
    double arg = -right.getArgument();
    Complexe z;
    z.setArgument(arg);
    z.setNorme(n);
    return z;
}

ostream& operator<<(ostream& os, const Complexe a){
    os << a.getReal() << "+i " << a.getIm();
    return os;
}