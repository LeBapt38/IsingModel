#include<iostream>
#include<cmath>
#include<vector>
#include<array>
#include<algorithm>
#include<random>
#include<fstream>
#include <SFML/Graphics.hpp>
#include"complexe_encaps.hpp"
#include"Reseau.hpp"

using namespace std;

bool ising_metropolis_step(Reseau& S, float beta, float B);
int random1_1();
int nx = 100;
int ny = 100;
double B = 0;
double TSurTc = 1.5;

int main(){
    double beta = (log(1+sqrt(2))/2) / TSurTc;
    Reseau S(nx,ny,1);
    for(int i=0; i<nx; i++){
        for(int j=0; j < ny; j++){
            S[S.site_xy(i,j)] = random1_1();
        }
    }
    sf::ContextSettings settings; settings.antialiasingLevel = 8; 
    sf::RenderWindow win (sf::VideoMode(nx*2,ny*2), "Mon super projet");
    int steps = 0;
    fstream fichier;
    fichier.open("mag_energie.txt", ios::out);
    while (win.isOpen()) {
        
        double e = S.energieIsing(B);
        double m = S.magnetisationIsing();
        fichier << steps << " " << m << " " << e << endl;
        for(int i=0; i<1e4; i++){
            ising_metropolis_step(S, beta, B);
        } 
        steps ++;
        win.clear(); 
        sf::Event event;
        while (win.pollEvent(event)) {
            if (event.type == sf::Event::Closed) win.close();
        }
        S.affiche_SFML(win,0,0);
        win.display();
    }
    fichier.close();
    return 0;
}

bool ising_metropolis_step(Reseau& S, float beta, float B){
    Reseau Sprop = S;
    Site XY = Sprop.site_aleatoire();
    Sprop[XY] = -Sprop[XY];
    double deltaE = -B * (Sprop[XY] - S[XY]);
    std::array<Site,4> voisins = Sprop.voisins(XY);
    for(size_t i = 0; i < voisins.size(); i++){
        deltaE -= Sprop[XY] * Sprop[voisins[i]] - S[XY] * S[voisins[i]];
    }
    double r = min(exp(-beta*deltaE),1.);
    //Tire un nb aleatoire entre 0 et 1
    float t = (float)(rand()) / (float)(RAND_MAX);
    bool propValid = (t<r);
    if(propValid){
        S = Sprop;
    }
    return propValid;
}

int random1_1(){
    float t = (float)(rand()) / (float)(RAND_MAX);
    int a = -1;
    if (t < 0.5){
        a = 1;
    }
    return a;
}