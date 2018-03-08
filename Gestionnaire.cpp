/********************************************
* Titre: Travail pratique #4 - Gestionnaire.cpp
* Date: 12 mars 2018
* Auteur: Daniel Nahum et Loic LeBlanc
*******************************************/
#include <iostream>
#include "Gestionnaire.h"
/**
* accesseur de usagers_.
*/
vector<Usager *> Gestionnaire::obtenirUsagers() const
{
    return usagers_;
}
/**
* Affiche le profil de tout les usagers du gestionnaire
*/
void Gestionnaire::afficherLesProfils() const
{
	for (int i = 0; i < usagers_.size(); i++) {
		usagers_[i]->afficherProfil();
	}
}
/**
* Fait la somme des totals a payer de tout les clients
*/
double Gestionnaire::obtenirChiffreAffaires() const
{
	double chiffreAffaires = 0;
	for (int i = 0; i < usagers_.size(); i++) {
		chiffreAffaires+= usagers_[i]->obtenirTotalAPayer();
	}
	return chiffreAffaires;
}
/**
* ajoute un usager
*/
void Gestionnaire::ajouterUsager(Usager *usager)
{
    for(int i=0; i<usagers_.size(); i++){
		if(usagers_[i] == usager){
			return;
		}
	}
	usagers_.push_back(usager);
}
/**
* reinitialise les usagers du gestionnaire
*/
void Gestionnaire::reinitialiser()
{
    for(int i=0; i<usagers_.size(); i++){
		usagers_[i] -> reinitialiser();
	}
}
/**
* Fait la mise a jour d'un produit aux encheres
*/
void Gestionnaire::encherir(Client *client, ProduitAuxEncheres *produit, double montant) const
{
    if(montant > produit->obtenirPrix()){
		produit->mettreAJourEnchere(client, montant);
	}
}
