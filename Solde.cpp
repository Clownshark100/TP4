/********************************************
* Titre: Travail pratique #4 - Solde.cpp
* Date: 12 mars 2018
* Auteur: Daniel Nahum et Loic LeBlanc
*******************************************/

#include "Solde.h"

/*
* Constructeur par paramètre
*/
Solde::Solde(int pourcentageRabais)
    : pourcentageRabais_(pourcentageRabais)
{
}
/*
* Destructeur de Solde
*/
Solde::~Solde() {}
/*
* Accesseur de pourcentageRabais_
*/
double Solde::obtenirPourcentageRabais() const
{
    return pourcentageRabais_;
}
/*
* Modificateur de pourcentageRabais_
*/
void Solde::modifierPourcentageRabais(int pourcentageRabais)
{
    pourcentageRabais_ = pourcentageRabais;
}
