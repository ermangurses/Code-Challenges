#include "Variable.h"

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
    while(getline(ss, token, ' ')){ 
        if(token.find_first_not_of(' ') != std::string::npos){
            std::cout<<token<<"\n";
        }
    }
}

void Variable::trim(std::string & token){

    std::string::iterator endPosition = std::remove(token.begin(), token.end(), ' ');
    token.erase(endPosition, token.end());
}
