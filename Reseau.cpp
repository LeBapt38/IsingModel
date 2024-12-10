#include "Reseau.hpp"
#include <cstdlib>
#include <array>
//Site



//Reseau

Reseau::Reseau(int NX, int NY, int8_t val_def) : nx(NX), ny(NY), tab(nullptr){
    tab = new int8_t[nx*ny];
    for(int l = 0; l < nx*ny; l++){
        tab[l] = val_def;
    }
}

Reseau::Reseau() : Reseau(0,0,0){}

Reseau::Reseau(const Reseau& other) : nx(other.nx), ny(other.ny), tab(nullptr) {
// le constructeur a acces au donnees prives du meme type    
    tab = new int8_t[nx*ny];
    for(int i = 0; i < nx*ny; i++){
        tab[i] = other.tab[i];
    }
}

Reseau::~Reseau(){
    if (tab != nullptr){
        delete[] tab;
    }
    tab = nullptr;
}

Reseau& Reseau::operator=(const Reseau& reseau){
    Reseau temp(reseau);
    std::swap(nx, temp.nx);
    std::swap(ny, temp.ny);
    std::swap(tab, temp.tab);

    return *this;
    // Destruction auto de temp
}

Site Reseau::site_index(int index) const{
    Site a(index, index/nx, index%ny);
    return a;
}

Site Reseau::site_xy(int x, int y) const{
    x = x % nx;
    y = y % ny;
    if(x < 0){
        x += nx;
    }
    if(y < 0){
        y += ny;
    }
    Site a(x*nx + y, x, y);
    return a;
}

Site Reseau::site_aleatoire() const{
    int x = std::rand();
    int y = std::rand();
    return site_xy(x,y);
}

int Reseau::nbSite(){
    return nx*ny;
}

int8_t Reseau::operator[](Site site) const{
    return tab[site._index];
}
int8_t& Reseau::operator[](Site site){
    return tab[site._index];
}

std::array<Site,4> Reseau::voisins(Site site){
    int x = site._x;
    int y = site._y;
    std::array<Site,4> sitesVoisins = {site_xy(x-1, y), site_xy(x+1, y), site_xy(x, y-1), site_xy(x, y+1)};
    return sitesVoisins;
}

void Reseau::affiche_SFML(sf::RenderWindow& window, float x, float y) const{
    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            sf::RectangleShape rectangle(sf::Vector2f(2,2));
            if (tab[site_xy(i,j)._index] == -1){
                rectangle.setFillColor(sf::Color(0,0,0));
            }else if(tab[site_xy(i,j)._index] ==1){
                rectangle.setFillColor(sf::Color(255, 255, 255));
            }else{
                rectangle.setFillColor(sf::Color(100,100,100));
            }
            rectangle.setPosition(x+(2*i), y+(2*j));
            window.draw(rectangle);
        }
    }
}

double Reseau::energieIsing(double B){
    double E = 0;
    for(int i=0; i<nx*ny; i++){
        E -= B * tab[i];
        Site XY = site_index(i);
        std::array<Site,4> vois = voisins(XY);
        for(size_t j = 0; j < vois.size(); j++){
            E -=0.5*(tab[i] * tab[vois[j]._index]);
        }
    }
    return E/(nx*ny);
}

double Reseau::magnetisationIsing(){
    double M = 0;
    for(int i=0; i<nx*ny; i++){
        M += tab[i];
    }
    M /= (double)(nx*ny);
    return M;
}

