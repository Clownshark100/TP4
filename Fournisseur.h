/********************************************
* Titre: Travail pratique #4 - Fournisseur.h
* Date: 12 mars 2018
* Auteur: Daniel Nahum et Loic LeBlanc
*
* Classe Fournisseur, permet la création et la modification d'un
* Fournisseur ayant les attributs derives de la classe Usager.
* Le fournisseur a un catalogue qui contient des produits
*******************************************/
#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <string>
#include <vector>
#include "Usager.h"
#include "Produit.h"

using namespace std;

class Fournisseur : public Usager
{
  public:
    Fournisseur();
    Fournisseur(const string &nom, const string &prenom, int identifiant, const string &codePostal);

    vector<Produit *> obtenirCatalogue() const;
    void afficherCatalogue() const;

    //Nous preferons dire qu'un Fournisseur est un Usager special qui n'a rien a payer
    //Plutot que de dire qu'un Usager n'a rien a payer par defaut
    virtual double obtenirTotalAPayer() const;
    virtual void afficherProfil() const;
    virtual void reinitialiser();
    virtual void ajouterProduit(Produit *produit);
    virtual void enleverProduit(Produit *produit);

  private:
    vector<Produit *> catalogue_;
};

#endif
