//
//  main.cpp
//  SauvegardeBinaire
//
//  Created by Kevin on 02/12/2018.
//  Copyright © 2018 Moks. All rights reserved.
//

#include <iostream>

#include "Personnage.h"
int main()
{
    // CREATION D'UN OBJET PERSONNAGE :
    Personnage *Brice = new Personnage;
    
    // LECTURE DE L'OBJET
    std::cout << "Creation d'un personnage : \n";
    std::cout << *Brice;
    
    // MODIFICATION DE L'OBJET
    std::string nom = "Brice";
    Brice->SetNom(nom);
    Brice->SetAge (25);
    Brice->SetVie (50);
    
    // LECTURE DE L'OBJET
    std::cout << "Personnage defini : \n";
    std::cout << *Brice;
    
    // ENREGISTREMENT DE L'OBJET
   Brice->Enregistrer ("BRICE");
    
    // SUPRESSION DE L'OBJET
    delete Brice;
    
    // CREATION DE L'OBJET
    std::cout << "Creation d'un personnage : \n";
    Brice = new Personnage;
    
    // LECTURE DE L'OBJET
    std::cout << *Brice;
    
    // MODIFICATION A PARTIR DU FICHIER
   Brice->Lire ("Brice");
    
    // LECTURE DE L'OBJET
    std::cout << "Personnage du fichier : \n";
    std::cout << *Brice;
    
    return EXIT_SUCCESS;
}
