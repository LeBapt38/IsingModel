#ifndef RESEAU_H
#define RESEAU_H

#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>
using namespace std;

class Site {
private :
    int _index;
    int _x;
    int _y;

    friend class Reseau;
    Site (int i, int x, int y) : _index(i), _x(x), _y(y) {}
    Site () = default;
};

class Reseau{
private :
    int nx;
    int ny;
    int8_t* tab; 
    Site site_index(int) const;

public :
//constructeurs
    Reseau(int, int, int8_t);
    Reseau();
    Reseau(const Reseau&);
    Reseau& operator= (const Reseau&);

// Destructeur
    ~Reseau();

// autres methodes
    Site site_xy(int,int) const;
    Site site_aleatoire() const;
    int nbSite();
    int8_t operator[](Site) const;
    int8_t& operator[](Site);
    std::array<Site,4> voisins(Site);

// Rendue 
    void affiche_SFML(sf::RenderWindow& window, float x, float y) const;
    double energieIsing(double B);
    double magnetisationIsing();
};



#endif