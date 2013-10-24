/* 
 * File:   TipContact.h
 * Author: sboros
 *
 * Created on October 23, 2013, 5:24 PM
 */

#ifndef TIPCONTACT_H
#define TIPCONTACT_H

class TipContact
{
    bool prieten, serviciu, familie;

public:

    TipContact(){ prieten=serviciu=familie=0; }

    bool obtineTipPrieten(void) const;
    bool obtineTipServiciu(void) const;
    bool obtineTipFamilie(void) const;
    void modificaTipPrieten(bool);
    void modificaTipServiciu(bool);
    void modificaTipFamilie(bool);
};

inline void TipContact::modificaTipPrieten(bool stare)
{
    this->prieten=stare;
}

inline void TipContact::modificaTipServiciu(bool stare)
{
    this->serviciu=stare;
}

inline void TipContact::modificaTipFamilie(bool stare)
{
    this->familie=stare;
}

inline bool TipContact::obtineTipPrieten(void) const
{
    return this->prieten;
}

inline bool TipContact::obtineTipServiciu(void) const
{
    return this->serviciu;
}

inline bool TipContact::obtineTipFamilie(void) const
{
    return this->familie;
}

#endif // TIPCONTACT_H