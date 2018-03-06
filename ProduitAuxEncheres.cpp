#include "ProduitAuxEncheres.h"

ProduitAuxEncheres::ProduitAuxEncheres(double prix)
    : Produit(),
      prixInitial_(prix),
      encherisseur_(nullptr)
{
}

ProduitAuxEncheres::ProduitAuxEncheres(Fournisseur *fournisseur, const string &nom,
                                       int reference, double prix)
    : Produit(fournisseur, nom, reference, prix),
      prixInitial_(prix),
      encherisseur_(nullptr)
{
}

double ProduitAuxEncheres::obtenirPrixInitial() const
{
    return prixInitial_;
}

Client *ProduitAuxEncheres::obtenirEncherisseur() const
{
    return encherisseur_;
}
void ProduitAuxEncheres::modifierEncherisseur(Client* encherisseur)
{
	encherisseur_ = encherisseur;
}
void ProduitAuxEncheres::afficher() const
{
	Produit::afficher();
	cout << "		prix initial:	$" << prixInitial_ << endl
		<< "		encherisseur:	" << encherisseur_->obtenirNom() << endl;
}

void ProduitAuxEncheres::modifierPrixInitial(double prixInitial)
{
    prixInitial_ = prixInitial;
}

void ProduitAuxEncheres::mettreAJourEnchere(Client *encherisseur, double nouveauPrix)
{
	
	if(encherisseur_ != encherisseur && nouveauPrix > prix_){
		prix_ = nouveauPrix;
		
		if(encherisseur_){
			encherisseur_->enleverProduit(this);
		}
		
		encherisseur_ = encherisseur;
		encherisseur_->ajouterProduit(this);
	}
	
}
