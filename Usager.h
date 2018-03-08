#ifndef USAGER_H
#define USAGER_H

#include "Produit.h"
#include <string>

using namespace std;

class Usager
{
  public:
    Usager(const string &nom = "Doe", const string &prenom = "John",
           int identifiant = 0, const string &codePostal = "A1A A1A");

    string obtenirNom() const;
    string obtenirPrenom() const;
    int obtenirIdentifiant() const;
    string obtenirCodePostal() const;
    //Il est sensé de dire que nous ne pouvons déterminer le total a Payer d'un Usager abstrait,
    //car il n'a aucune propriété permettant de le déterminer.
    virtual double obtenirTotalAPayer() const = 0;
    virtual void afficherProfil() const;

    void modifierNom(const string &nom);
    void modifierPrenom(const string &prenom);
    void modifierIdentifiant(int identifiant);
    void modifierCodePostal(const string &codePostal);
    virtual void reinitialiser() = 0;
    virtual void ajouterProduit(Produit *produit) = 0;
    virtual void enleverProduit(Produit *produit) = 0;

  private:
    string nom_;
    string prenom_;
    int identifiant_;
    string codePostal_;
};

#endif
