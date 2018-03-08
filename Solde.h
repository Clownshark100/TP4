#ifndef SOLDE_H
#define SOLDE_H

#include <string>
#include <iostream>

using namespace std;

/********************************************
* Titre: Travail pratique #4 - Solde.h
* Date: 12 mars 2018
* Auteur: Daniel Nahum et Loic LeBlanc
*
* Classe Solde abstraite pure, permet la création et la modification d'un
* Solde, soit un un pourcentage de rabais 
*
*******************************************/
class Solde
{
  public:
    Solde(int pourcentageRabais);
    virtual ~Solde() = 0; // par convention, pour rendre une classe abstraite lorsque celle-ci
                          // n'a aucune méthode qui mériterait d'être virtuelle pure, on préfère
                          // généralement rendre le destructeur de la classe virtuel pur.

    double obtenirPourcentageRabais() const;

    void modifierPourcentageRabais(int pourcentageRabais);

  protected:
    int pourcentageRabais_;
};

#endif
