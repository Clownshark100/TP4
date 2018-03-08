
/********************************************
* Titre: Travail pratique #4 - ProduitAuxEncheres.cpp
* Date: 12 mars 2018
* Auteur: Daniel Nahum et Loic LeBlanc
*******************************************/

#include "ProduitAuxEncheres.h"



/*
* Constructeur par paramètre
*/
ProduitAuxEncheres::ProduitAuxEncheres(double prix)
    : Produit(),
      prixInitial_(prix),
      encherisseur_(nullptr)
{
}
/*
* Constructeur par paramètres
*/
ProduitAuxEncheres::ProduitAuxEncheres(Fournisseur *fournisseur, const string &nom,
                                       int reference, double prix)
    : Produit(fournisseur, nom, reference, prix),
      prixInitial_(prix),
      encherisseur_(nullptr)
{
}
/*
* Accesseur de prixInitial_
*/
double ProduitAuxEncheres::obtenirPrixInitial() const
{
    return prixInitial_;
}
/*
* Accesseur de encherisseur_
*/
Client *ProduitAuxEncheres::obtenirEncherisseur() const
{
    return encherisseur_;
}
/*
* Modificateur de encherisseur_
*/
void ProduitAuxEncheres::modifierEncherisseur(Client* encherisseur)
{
	encherisseur_ = encherisseur;
}
/*
* Affiche de façon formattée les informations de ProduitAuxEncheres
*/
void ProduitAuxEncheres::afficher() const
{
	Produit::afficher();
	cout << "		prix initial:	$" << prixInitial_ << endl
		<< "		encherisseur:	" << encherisseur_->obtenirNom() << endl;
}
/*
* Modificateur de prixInitial_
*/
void ProduitAuxEncheres::modifierPrixInitial(double prixInitial)
{
    prixInitial_ = prixInitial;
}
/*
* Verifie que l'encherisseur n'est pas lui meme et que le prix donné est plus haut que le prix
* courant. Si c'est le cas, met à jour le prix et l'encherisseur, enlève le produit du
* panier de l'ancien enchérisseur et met le produit dans le panier du nouvel enchérisseur. 
*/
void ProduitAuxEncheres::mettreAJourEnchere(Client *encherisseur, double nouveauPrix)
{
	//Vérification double du prix en théorie dans l'implémentation spécifique de cette classe
	//dans le programme, mais revérification comme test de sanité.
	if(encherisseur_ != encherisseur && nouveauPrix > prix_){
		prix_ = nouveauPrix;
		
		if(encherisseur_){
			encherisseur_->enleverProduit(this);
		}
		
		encherisseur_ = encherisseur;
		encherisseur_->ajouterProduit(this);
	}
	
}
