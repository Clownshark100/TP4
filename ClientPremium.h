/********************************************
* Titre: Travail pratique #4 - ClientPremium.h
* Date: 12 mars 2018
* Auteur: Daniel Nahum et Loic LeBlanc
*
* Classe ClientPremium, permet la création et la modification d'un
* ClientPremium ayant les attributs derives de la classe Client en plus du nombre de jours restants de l'abonnement.
* 
*******************************************/
#ifndef CLIENT_PREMIUM_H
#define CLIENT_PREMIUM_H

#include <string>
#include "Client.h"

using namespace std;

class ClientPremium : public Client
{
  public:
    ClientPremium(unsigned int joursRestants = 0);
    ClientPremium(const string &nom, const string &prenom, int identifiant, const string &codePostal, unsigned int codeClient, unsigned int joursRestants = 0);

    unsigned int obtenirJoursRestants() const;
    virtual double obtenirTotalAPayer() const;
    void afficherProfil() const;

    void modifierJoursRestants(unsigned int joursRestants);

  private:
    unsigned int joursRestants_; // avant la fin de l'abonnement
};

#endif
