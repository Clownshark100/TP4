#include <iostream>
#include "Gestionnaire.h"

vector<Usager *> Gestionnaire::obtenirUsagers() const
{
    return usagers_;
}

void Gestionnaire::afficherLesProfils() const
{
	for (int i = 0; i < usagers_.size(); i++) {
		usagers_[i]->afficherProfil();
	}
}

double Gestionnaire::obtenirChiffreAffaires() const
{
	double chiffreAffaires = 0;
	for (int i = 0; i < usagers_.size(); i++) {
		chiffreAffaires+= usagers_[i]->obtenirTotalAPayer();
	}
	return chiffreAffaires;
}

void Gestionnaire::ajouterUsager(Usager *usager)
{
    for(int i=0; i<usagers_.size(); i++){
		if(usagers_[i] == usager){
			return;
		}
	}
	usagers_.push_back(usager);
}

void Gestionnaire::reinitialiser()
{
    for(int i=0; i<usagers_.size(); i++){
		usagers_[i] -> reinitialiser();
	}
}

void Gestionnaire::encherir(Client *client, ProduitAuxEncheres *produit, double montant) const
{
    if(montant > produit->obtenirPrix()){
		produit->mettreAJourEnchere(client, montant);
	}
}
