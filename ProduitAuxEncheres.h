#ifndef PRODUIT_AUX_ENCHERES_H
#define PRODUIT_AUX_ENCHERES_H

#include <string>
#include <iostream>
#include "Produit.h"
#include "Client.h"

using namespace std;

/********************************************
* Titre: Travail pratique #4 - ProduitAuxEncheres.h
* Date: 12 mars 2018
* Auteur: Daniel Nahum et Loic LeBlanc
*
* Classe ProduitAuxEncheres, permet la création et la modification d'un
* ProduitAuxEncheres, soit un Produit ayant un encherisseur et un prixInitial
* et pouvant participer à des encheres.
*
*******************************************/


class ProduitAuxEncheres : public Produit
{
  public:
    ProduitAuxEncheres(double prix = 0.0);
    ProduitAuxEncheres(Fournisseur *fournisseur, const string &nom, int reference,
                       double prix = 0.0);

    double obtenirPrixInitial() const;
    Client *obtenirEncherisseur() const;
    //Ajout de modificateur d'encherisseur afin de pouvoir reinitialiser 
    //cette valeur depuis Client::reinitialiser(). Une autre solution, peut-être
    //meilleure relatif a l'encapsulation aurait été la définition d'une méthode 
    //void ProduitAuxEncheres::reinitialiser();
    void modifierEncherisseur(Client* encherisseur); 
    void afficher() const;

    void modifierPrixInitial(double prixInitial);
    void mettreAJourEnchere(Client *encherisseur, double nouveauPrix);

  private:
    double prixInitial_;
    Client *encherisseur_;
};

#endif
