/********************************************
* Titre: Travail pratique #4 - Fournisseur.cpp
* Date: 12 mars 2018
* Auteur: Daniel Nahum et Loic LeBlanc
*******************************************/
#include "Fournisseur.h"
#include <iostream>
/**
* Constructeur par default.
*/
Fournisseur::Fournisseur()
    : Usager()
{
}
/**
* Constructeur par parametres.
*/
Fournisseur::Fournisseur(const string &nom, const string &prenom, int identifiant,
                         const string &codePostal)
    : Usager(nom, prenom, identifiant, codePostal)
{
}
/**
* accesseur de catalogue_.
*/
vector<Produit *> Fournisseur::obtenirCatalogue() const
{
    return catalogue_;
}
/**
* Affiche le nom du fournisseur et le contenu du catalogue
*/
void Fournisseur::afficherCatalogue() const
{
    cout << "CATALOGUE (de " << obtenirNom() << ")"
         << "\n";
    for (unsigned int i = 0; i < catalogue_.size(); i++)
        catalogue_[i]->afficher();
    cout << endl;
}
/**
* accesseur de codeClient_.
*/
//Nous preferons dire qu'un Fournisseur est un Usager special qui n'a rien a payer
//Plutot que de dire qu'un Usager n'a rien a payer par defaut
double Fournisseur::obtenirTotalAPayer() const
{

return 0.;

}
/**
* Affiche le profil du fournisseur ainsi que le nombre de produits dans le catalogue
*/
void Fournisseur::afficherProfil() const
{
	Usager::afficherProfil();
	cout << "	catalogue:	" << catalogue_.size() << endl;
}
/**
* Vide le catalogue 
*/
void Fournisseur::reinitialiser()
{
    for(int i = catalogue_.size()-1; i>=0; i--){
	
		catalogue_[i] -> modifierFournisseur(nullptr);
		catalogue_.pop_back();
	
	}
}
/**
* Ajoute un produit au catalogue
*/
void Fournisseur::ajouterProduit(Produit *produit)
{
    for (unsigned int i = 0; i < catalogue_.size(); i++)
        if (catalogue_[i] == produit)
            return;
    Fournisseur *fournisseur = produit->obtenirFournisseur();
    if (fournisseur != nullptr && fournisseur != this)
        fournisseur->enleverProduit(produit);
    catalogue_.push_back(produit);
}
/**
* Enleve un produit du catalogue
*/
void Fournisseur::enleverProduit(Produit *produit)
{
    produit->modifierFournisseur(nullptr);
    for (unsigned int i = 0; i < catalogue_.size(); i++)
    {
        if (catalogue_[i] == produit)
        {
            catalogue_[i] = catalogue_[catalogue_.size() - 1];
            catalogue_.pop_back();
            return;
        }
    }
}
