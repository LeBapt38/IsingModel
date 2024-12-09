#include<iostream>
#include<cmath>
#include<vector>
#include<array>
#include<algorithm>
#include<random>
#include<fstream>
#include"complexe_encaps.hpp"
#include"Reseau.hpp"

using namespace std;

bool ising_metropolis_step(Reseau& S, float beta, float B);
int random1_1();
int nx = 100;
int ny = 100;
double B = 0;

int main(){
    double beta0 = log(1+sqrt(2))/2;
    Reseau S(nx,ny,1);
    for(int i=0; i<nx; i++){
        for(int j=0; j < ny; j++){
            S[S.site_xy(i,j)] = random1_1();
        }
    }
    fstream fichier;
    fichier.open("mag_energie.txt", ios::out);
    for(int i_T=0; i_T<30; i_T++) {
        double TSurTc = 0.05 * i_T;
        double beta = beta0 / TSurTc;
        for(int i=0; i<1e5; i++){
            ising_metropolis_step(S, beta, B);
        } 
        double m = S.energieIsing(B);
        double e = S.magnetisationIsing();
        fichier << TSurTc << " " << m << " " << e << endl;
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
    mt19937 rng;
    uniform_real_distribution<float> distrib_u01 (0,1);
    float t = distrib_u01(rng);
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