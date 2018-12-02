//
//  Personnage.h
//  SauvegardeBinaire
//
//  Created by Kevin on 02/12/2018.
//  Copyright © 2018 Moks. All rights reserved.
//

#ifndef Personnage_h
#define Personnage_h

#include <fstream>
#include <iostream>
class Personnage
{
public:
    Personnage();
    ~Personnage();
    
    void SetNom(std::string &);
    std::string GetNom() const;
    void SetAge (unsigned short);
    unsigned short GetAge () const;
    void SetVie (unsigned short);
    unsigned short GetVie () const;
    void Enregistrer (std::string) const;
    void Lire (std::string);
    friend std::ostream& operator<< (std::ostream&, Personnage&);
    
private:
    std::string wNom;
    unsigned short wAge;
    unsigned short wVie;
};


#endif /* Personnage_h */
