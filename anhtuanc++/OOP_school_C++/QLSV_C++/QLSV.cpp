#include "QLSV.h"

QLSV::QLSV()
{
    this->p = NULL;
    this->length = 0;
}

QLSV::~QLSV()
{
    delete[] this->p;

}

SV& QLSV::operator [] (const int& index)
{
    static SV ngu;
    return (index >= 0 && index < this->length)
   ? *(this->p + index) : ngu; 
}

ostream& operator << (ostream& os, const QLSV& db)
{
    for (int i = 0; i < db.length; i++)
    {
        os << *(db.p + i);
    }
    return os;
}

void QLSV::add(const SV& s)
{
    if(this->length == 0)
    {
        this->p = new SV[this->length + 1];
        *(this->p + this->length) = s;
    }
    else 
    {
        SV* temp = new SV[this->length];
        for (int i = 0; i < this->length; i++)
        {
            *(temp + i) =  *(this->p + i);
        }
        delete[] this->p;
        this->p = new SV[this->length + 1];
        for( int i = 0; i < this->length; i++)
        {
            *(this->p + i) = *(temp + i);
        }
        *(this->p + this->length) = s;
    }
    this->length++;
}

int QLSV::indexof(SV s)
{
    int index = -1;
    for(int i = 0; i < this->length; i++)
    {
        if (((*this)[i])._mssv() == s._mssv())
        {
            index = i;
            break;
        }
    }
    return index;
}

void QLSV::removeat(const int& index)
{
    for(int i = index; i < this->length; i++)
    {
        *(this->p + i) = *(this->p + i + 1);
    }
    this->length--;
}

void QLSV::remove(SV& s)
{
    int index = indexof(s);
    if (index >= 0)
    {
        removeat(index);
    }   
}

void QLSV::update(const int& m)
{
    for (int i = 0; i < this->length; i++)
    {
        if(((*this)[i])._mssv() == m)
        {
            cin >> (*this)[i];
        }
    }
}