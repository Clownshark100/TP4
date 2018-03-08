
/********************************************
* Titre: Travail pratique #4 - ProduitSolde.cpp
* Date: 12 mars 2018
* Auteur: Daniel Nahum et Loic LeBlanc
*******************************************/

#include "ProduitSolde.h"


/**
* Constructeur par parametre
*/
ProduitSolde::ProduitSolde(int pourcentageRabais)
    : Produit(),
      Solde(pourcentageRabais)
{
}

/**
* Constructeur par parametres
*/
ProduitSolde::ProduitSolde(Fournisseur *fournisseur, const string &nom,
                           int reference, double prix, int pourcentageRabais)
    : Produit(fournisseur, nom, reference, prix),
      Solde(pourcentageRabais)
{
}

/**
* Obtient le prix du produit soldé soit le prix moins le solde
*/
double ProduitSolde::obtenirPrix() const
{
	return prix_ * (100 - pourcentageRabais_) /100;
}
/*
* Affiche de façon formattée les informations de ProduitAuxEncheres
*/
void ProduitSolde::afficher() const
{
	Produit::afficher();
	cout << "		rabais:		" << pourcentageRabais_ << "%" << endl;
}
