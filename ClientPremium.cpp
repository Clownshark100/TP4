/********************************************
* Titre: Travail pratique #4 - ClientPremium.cpp
* Date: 12 mars 2018
* Auteur: Daniel Nahum et Loic LeBlanc
*******************************************/
#include "ClientPremium.h"
#include <iostream>
/**
* Constructeur par default.
*/
ClientPremium::ClientPremium(unsigned int joursRestants)
    : Client(),
      joursRestants_(joursRestants)
{
}
/**
* Constructeur par parametres.
*/
ClientPremium::ClientPremium(const string &nom, const string &prenom, int identifiant,
                             const string &codePostal, unsigned int codeClient,
                             unsigned int joursRestants)
    : Client(nom, prenom, identifiant, codePostal, codeClient),
      joursRestants_(joursRestants)
{
}
/**
* accesseur de joursRestants_.
*/
unsigned int ClientPremium::obtenirJoursRestants() const
{
    return joursRestants_;
}
/**
* Additionne la somme des prix des produits avec deduction de 5$ par produit dans le panier du client 
*/
double ClientPremium::obtenirTotalAPayer() const
{
	double prixTotal = 0;
	for (int i = 0; i<panier_.size(); i++) {
		if (panier_[i]->obtenirPrix() > 5) {
			prixTotal += panier_[i]->obtenirPrix() - 5;
		}
	}
	return prixTotal;
}
/**
* Affiche le profil du client ainsi que les jours restants a son abonnement
*/
void ClientPremium::afficherProfil() const
{
	Client::afficherProfil();
	cout << "	jours restants:	" << joursRestants_ << endl;
}
/**
*  modification de joursRestants_.
*/
void ClientPremium::modifierJoursRestants(unsigned int joursRestants)
{
    joursRestants_ = joursRestants_;
}
