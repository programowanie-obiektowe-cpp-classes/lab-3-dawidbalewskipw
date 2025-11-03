#pragma once

#include "Stocznia.hpp"

inline unsigned int transportujFlota(unsigned int towar)
{
    
    if (towar == 0)
        return 0;

    Stocznia     stocznia{};             
    unsigned int sumaPrzewiezionego = 0; 
    unsigned int liczbaZaglowcow    = 0; 

    while (sumaPrzewiezionego < towar) {
        Statek*            statek  = stocznia();            
        const unsigned int ladunek = statek->transportuj(); 
        sumaPrzewiezionego += ladunek;                      

        if (dynamic_cast< Zaglowiec* >(statek) != nullptr)
            ++liczbaZaglowcow;

        delete statek;
    }

    return liczbaZaglowcow;
}
