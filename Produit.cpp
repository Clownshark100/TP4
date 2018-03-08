
/********************************************
* Titre: Travail pratique #3 - Produit.cpp
* Date: 12 mars 2018
* Auteur: Daniel Nahum et Loic LeBlanc
*******************************************/


#include "Produit.h"
#include "Fournisseur.h"
#include <iostream>
#include <string>

/**
* Constructeur par parametres.
*/
Produit::Produit(Fournisseur *fournisseur, const string &nom, int reference, double prix)
    : fournisseur_(fournisseur),
      nom_(nom),
      reference_(reference),
      prix_(prix)
{
    if (fournisseur_ != nullptr)
        fournisseur_->ajouterProduit(this);
}

// Methodes d'acces
/**
* accesseur de nom_.
*/
string Produit::obtenirNom() const
{
    return nom_;
}
/**
* accesseur de reference_.
*/
int Produit::obtenirReference() const
{
    return reference_;
}
/**
* accesseur de prix_.
*/
double Produit::obtenirPrix() const
{
    return prix_;
}
/**
* accesseur de fournisseur_.
*/
Fournisseur *Produit::obtenirFournisseur() const
{
    return fournisseur_;
}
/**
* affiche les informations du produit
*/

void Produit::afficher() const
{
	cout <<"	"<< nom_ << endl
		<< "		reference:	" << reference_ << endl
		<< "		prix:		$" << prix_ << endl;
}

//Modificateurs
/**
* modification de nom_.
*/
void Produit::modifierNom(const string &nom)
{
    nom_ = nom;
}
/**
* modification de reference_.
*/
void Produit::modifierReference(int reference)
{
    reference_ = reference;
}
/**
* modification de prix_.
*/
void Produit::modifierPrix(double prix)
{
    prix_ = prix;
}
/**
* modification de fournisseur_
*/
void Produit::modifierFournisseur(Fournisseur *fournisseur)
{
    fournisseur_ = fournisseur;
}
