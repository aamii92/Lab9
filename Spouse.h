#ifndef SPOUSE_H
#define SPOUSE_H
#include <string>
#include "Person.h"
using namespace std;
class Spouse: public Person{
    public:
    int annDate;
    Spouse(string name, string ssnum, int age, int annDate) 
        :Person(name, ssnum, age){
        this->annDate = annDate;
    }
    int getAnndate(){
        return annDate;
    }
    void setAnndate(int annDate){
        this->annDate = annDate;
    }

};
#endif