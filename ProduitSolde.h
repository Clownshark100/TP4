#ifndef PRODUIT_SOLDE_H
#define PRODUIT_SOLDE_H

#include <string>
#include <iostream>
#include "Solde.h"
#include "Produit.h"

using namespace std;

/********************************************
* Titre: Travail pratique #4 - ProduitSolde.h
* Date: 12 mars 2018
* Auteur: Daniel Nahum et Loic LeBlanc
*
* Classe ProduitSolde, permet la création et la modification d'un
* ProduitSolde, soit un Produit sous l'effet d'un Solde
*
*******************************************/
class ProduitSolde : public Produit, public Solde
{
  public:
    ProduitSolde(int pourcentageRabais = 0);
    ProduitSolde(Fournisseur *fournisseur, const string &nom, int reference,
                 double prix, int pourcentageRabais = 0);

    virtual double obtenirPrix() const;
    virtual void afficher() const;
};

#endif
