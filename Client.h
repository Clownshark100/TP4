/********************************************
* Titre: Travail pratique #4 - Client.h
* Date: 12 mars 2018
* Auteur: Daniel Nahum et Loic LeBlanc
*
* Classe Client, permet la création et la modification d'un
* Client ayant les attributs derives de la classe Usager en plus d'un code Client.
* Le client a un panier qui contient les produits achetes
*******************************************/
#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>
#include "Usager.h"
#include "Produit.h"

using namespace std;

class Client : public Usager
{
  public:
    Client(unsigned int codeClient = 0);
    Client(const string &nom, const string &prenom, int identifiant, const string &codePostal, unsigned int codeClient = 0);

    unsigned int obtenirCodeClient() const;
    vector<Produit *> obtenirPanier() const;
    virtual double obtenirTotalAPayer() const;
    void afficherPanier() const;
    virtual void afficherProfil() const;

    void modifierCodeClient(unsigned int codeClient);
    virtual void enleverProduit(Produit *produit);
    virtual void ajouterProduit(Produit *produit);
    virtual void reinitialiser();
  
  protected:
    vector<Produit *> panier_;

  private:
    unsigned int codeClient_;
};

#endif
