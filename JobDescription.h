#ifndef JOBDESCRIPTION_H
#define JOBDESCRIPTION_H
#include <string>
using namespace std;
class JobDescription{
    public:
    string description;
    JobDescription(string description){
        this->description = description;
    }
    string getDescription(){
        return description;
    }
    void setDescription(string description){
        this->description = description;
    }
};
#endif