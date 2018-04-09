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

    the_number_of_dependencies = 0;
    sum_of_unsigned_integers = 0;
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
void Variable::getLine(std::string & line){

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

void Variable::setVariableName(){



}


void Variable::setDependencies(){




    the_number_of_dependencies++; 
}


void Variable::setValue(){



}


void Variable::sumValues(unsigned int value){

    sum_of_unsigned_integers += value;

}

 
