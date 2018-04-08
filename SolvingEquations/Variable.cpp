#include "Variable.h"
#include <cctype>

//******************************************************************************
//
//
//  Default Costructor 
//
//
//******************************************************************************

Variable::Variable(){



}

//******************************************************************************
//
//
//  Destructor
//
//
//******************************************************************************
Variable::~Variable(){


}
void Variable::readLine(std::string & line){

    parseLine(line);
}

void Variable::parseLine(std::string & line){
 
    std::stringstream ss(line);
    std::string token;
    while (getline(ss, token, ' ')){ 
        if (token.find_first_not_of(' ') != std::string::npos){
            if (isalpha(token.at(0))){

                std::cout<<"This is variable: "<<token<<"\n";             
            } else if (isdigit(token.at(0))){

                std::cout<<"This is unsigned integer: "<<token<<"\n";
            } else {
       
                std::cout<<"This is something else: "<<token<<"\n";
            }        
        }
    }
} 
