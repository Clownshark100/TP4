/********************************************
* Titre: Travail pratique #4 - Client.cpp
* Date: 12 mars 2018
* Auteur: Daniel Nahum et Loic LeBlanc
*******************************************/
#include "Client.h"
#include "ProduitAuxEncheres.h"
#include <iostream>

/**
* Constructeur par default.
*/
Client::Client(unsigned int codeClient)
    : Usager(),
      codeClient_(codeClient)
{
}
/**
* Constructeur par parametres.
*/
Client::Client(const string &nom, const string &prenom, int identifiant,
               const string &codePostal, unsigned int codeClient)
    : Usager(nom, prenom, identifiant, codePostal),
      codeClient_(codeClient)
{
}
/**
* accesseur de codeClient_.
*/
unsigned int Client::obtenirCodeClient() const
{
    return codeClient_;
}
/**
* accesseur de panier_.
*/
vector<Produit *> Client::obtenirPanier() const
{
    return panier_;
}
/**
* Additionne la somme des prix des produits dans le panier du client
*/
double Client::obtenirTotalAPayer() const
{
	double prixTotal = 0;
    for(int i=0; i<panier_.size(); i++){
		prixTotal += panier_[i]-> obtenirPrix();
	}
	return prixTotal;
}
/**
* Affiche le Nom du client ainsi que le contenu du panier
*/
void Client::afficherPanier() const
{
    cout << "PANIER (de " << obtenirNom() << ")"
         << "\n";
    for (unsigned int i = 0; i < panier_.size(); i++)
        panier_[i]->afficher();
    cout << endl;
}
/**
* Affiche les informations du client
*/
void Client::afficherProfil() const
{
	Usager::afficherProfil();
	cout << "	code client:	" << codeClient_ << endl 
		<<  "	panier:		" << panier_.size() << " elements" << endl;
}
/**
*  modification de codeClient_.
*/
void Client::modifierCodeClient(unsigned int codeClient)
{
    codeClient_ = codeClient_;
}
/**
*  Enleve un produit du panier
*/
void Client::enleverProduit(Produit *produit)
{
    for (unsigned int i = 0; i < panier_.size(); i++)
    {
        if (panier_[i] == produit)
        {
            panier_[i] = panier_[panier_.size() - 1];
            panier_.pop_back();
            return;
        }
    }
}
/**
*  Ajoute un produit au panier
*/
void Client::ajouterProduit(Produit *produit)
{
    for (unsigned int i = 0; i < panier_.size(); i++)
        if (panier_[i] == produit)
            return;
    panier_.push_back(produit);
}
/**
*  Vide le panier et remet les produits aux encheres du panier a leur valeur intial
*/
void Client::reinitialiser()
{
    for(int i = panier_.size()-1; i>=0; i--){

		ProduitAuxEncheres* pae = dynamic_cast<ProduitAuxEncheres*>(panier_[i]);
		if(pae){
			pae -> modifierPrix(pae->obtenirPrixInitial());
			pae -> modifierEncherisseur(nullptr);
		}
		panier_.pop_back();
	}
}
