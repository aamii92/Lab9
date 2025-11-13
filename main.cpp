#include<iostream>
#include "Employee.h"
#include<string>
using namespace std;
int main(){
    Division techDivision("techDivision");
    Division hrDivision("hrDivisio");
    Division financeDivision("financeDivision");
    auto pmJob = std::make_shared<JobDescription>("programmer");
    auto mgJob = std::make_shared<JobDescription>("manager");
    auto anJob = std::make_shared<JobDescription>("analyst");}
}
