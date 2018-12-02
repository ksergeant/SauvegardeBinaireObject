//
//  Personnage.cpp
//  SauvegardeBinaire
//
//  Created by Kevin on 02/12/2018.
//  Copyright © 2018 Moks. All rights reserved.
//

#include <stdio.h>
#include "Personnage.h"


Personnage::Personnage()
{
    wNom = "Aucun_nom";
    wAge = 20;
    wVie = 100;
}
Personnage::~Personnage()
{
}
void Personnage::SetNom(std::string &Nom)
{
    try
    {
        if (Nom == "")
            throw "La chaine de caractere est vide !";
        if (Nom.size() > 40)
            throw "Nom trop long !";
        wNom = Nom;
    }
    catch (const char *exception)
    {
        std::cerr << "\n*** " << exception << " ***\n";
    }
    catch (...)
    {
        std::cerr << "\n*** Une erreur s'est produite ! ***\n";
    }
}
std::string  Personnage::GetNom() const
{
    return wNom;
}
void Personnage::SetAge (unsigned short Age)
{
    try
    {
        if (Age > 137)
            throw "L'age est trop grand !";
        wAge = Age;
    }
    catch (const char *exception)
    {
        std::cerr << "\n*** " << exception << " ***\n";
    }
    catch (...)
    {
        std::cerr << "\n*** Une erreur s'est produite ! ***\n";
    }
}
unsigned short Personnage::GetAge () const
{
    return wAge;
}
void Personnage::SetVie (unsigned short Vie)
{
    try
    {
        if (Vie > 100)
            throw "Il y a trop de points de vie !";
        wVie = Vie;
    }
    catch (const char *exception)
    {
        std::cerr << "\n*** " << exception << " ***\n";
    }
    catch (...)
    {
        std::cerr << "\n*** Une erreur s'est produite ! ***\n";
    }
}
unsigned short Personnage::GetVie () const
{
    return wVie;
}
void Personnage::Enregistrer (std::string Chemin) const
{
    try
    {
        if (Chemin == "")
            throw "Chemin vide !";
        if (Chemin.size() > 300)
            throw "Chemin trop long";
        std::ofstream fichier_sortant (Chemin.c_str(), std::ios::binary);
        if (!fichier_sortant)
        {
            std::cerr << "\a\n\nImpossible de creer le fichier de sauvegarde\n\n";
            return;
        }
        fichier_sortant.write ((char*) this, sizeof (*this));
        fichier_sortant.close();
    }
    catch (const char *exception)
    {
        std::cerr << "\n*** " << exception << " ***\n";
    }
    catch (...)
    {
        std::cerr << "\n*** Une erreur s'est produite ! ***\n";
    }
}
void Personnage::Lire (std::string Chemin)
{
    try
    {
        if (Chemin == "")
            throw "Chemin vide !";
        if (Chemin.size() > 300)
            throw "Chemin trop long";
        std::ifstream fichier_entrant(Chemin.c_str(), std::ios::binary);
        if (!fichier_entrant)
        {
            std::cerr << "\a\n\nImpossible de lire le fichier de sauvegarde\n\n";
            return;
        }
        fichier_entrant.read((char*) this, sizeof(*this));
        fichier_entrant.close();
    }
    catch (const char *exception)
    {
        std::cerr << "\n*** " << exception << " ***\n";
    }
    catch (...)
    {
        std::cerr << "\n*** Une erreur s'est produite ! ***\n";
    }
}
std::ostream& operator<< (std::ostream &Flux, Personnage &rhs)
{
    try
    {
        Flux << "\nNom du personnage : " << rhs.GetNom()
        << "\nAge du personnage : " << rhs.GetAge()
        << "\nVie restante du personnage : " << rhs.GetVie()
        << "\n\n";
        return Flux;
    }
    catch (...)
    {
        std::cerr << "\n*** Une erreur s'est produite ! ***\n";
        return Flux;
    }
}
