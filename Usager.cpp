/********************************************
* Titre: Travail pratique #4 - Usager.cpp
* Date: 12 mars 2018
* Auteur: Daniel Nahum et Loic LeBlanc
*******************************************/
#include "Usager.h"
#include <iostream>
/**
* Constructeur par parametres.
*/
Usager::Usager(const string &nom, const string &prenom, int identifiant,
               const string &codePostal)
    : nom_(nom),
      prenom_(prenom),
      identifiant_(identifiant),
      codePostal_(codePostal)
{
}
/**
* accesseur de nom_.
*/
string Usager::obtenirNom() const
{
    return nom_;
}
/**
* accesseur de prenom_.
*/
string Usager::obtenirPrenom() const
{
    return prenom_;
}
/**
* accesseur de identifiant_.
*/
int Usager::obtenirIdentifiant() const
{
    return identifiant_;
}
/**
* accesseur de codePostal_.
*/
string Usager::obtenirCodePostal() const
{
    return codePostal_;
}
/**
* affiche les informations de l'usager
*/
void Usager::afficherProfil() const
{
	cout << nom_ << ", " << prenom_ << "(" << identifiant_ << ")" << endl
		<< "	code postal:	" << codePostal_ << endl;
}
/**
* modification de nom_.
*/
void Usager::modifierNom(const string &nom)
{
    nom_ = nom;
}
/**
* modification de prenom_.
*/
void Usager::modifierPrenom(const string &prenom)
{
    prenom_ = prenom;
}
/**
* modification de identifiant_.
*/
void Usager::modifierIdentifiant(int identifiant)
{
    identifiant_ = identifiant;
}
/**
* modification de codePostal_.
*/
void Usager::modifierCodePostal(const string &codePostal)
{
    codePostal_ = codePostal;
}


