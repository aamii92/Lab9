#ifndef SPOUSE_H
#define SPOUSE_H
#include <string>
#include "Person.h"
using namespace std;
class Spouse: public Person{
    public:
    string annDate;
    Spouse(string name, string ssnum, int age, string annDate) 
        :Person(name, ssnum, age){
        this->annDate = annDate;
    }
    string getAnndate(){
        return annDate;
    }
    void setAnndate(int annDate){
        this->annDate = annDate;
    }

};
#endif