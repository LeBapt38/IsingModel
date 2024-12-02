#ifndef COMPLEXE_ENCAPS_H
#define COMPLEXE_ENCAPS_H

#include <iostream>
using namespace std;

class Complexe {
    
    double x;
    double y;
    double norme;
    double argument;
    
    public :

        Complexe(double, double);//
        Complexe();//
        void affiche();//
        void setReal(double);
        double getReal() const;
        double computeReal();
        void setIm(double) ;
        double getIm() const;
        double computeIm();
        double computeNorme();
        double getNorme() const;
        void setNorme(double);
        double computeArgument();
        double getArgument() const;
        void setArgument(double);
        Complexe& operator-(Complexe);
        Complexe& operator-();
        Complexe& operator/(Complexe);
        Complexe& operator+= (const Complexe&);
        Complexe& operator-= (const Complexe&);
        Complexe& operator*= (const Complexe&);

};

Complexe exponentielle(Complexe);
Complexe operator+(Complexe, Complexe);
Complexe operator*(Complexe, Complexe);
Complexe operator*(Complexe, double);
Complexe operator*(double, Complexe);
Complexe operator/ (double, Complexe);
ostream& operator<<(ostream&, const Complexe);




#endif 