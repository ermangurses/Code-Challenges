#include "Variable.h"

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
    isVariableNameSet = false;
}

Variable::Variable(std::string & line){

    parseLine(line);

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
                
                if(!isVariableNameSet){
                    setVariableName(token);
                    isVariableNameSet = true;
                } else {
                    setDependencies(token);                    
                }
            } else if (isdigit(token.at(0))){
                    sumValues(std::stoul(token,nullptr,0)); 
            }        
        }
    }
}

void Variable::setVariableName(std::string & variable_name){

    this->variable_name = variable_name;

}


void Variable::setDependencies(std::string & dependency_name){

    dependencies.insert(dependency_name);
    the_number_of_dependencies++; 
}

void Variable::sumValues(unsigned int value){

    sum_of_unsigned_integers += value;

}

std::string Variable::getVariableName(){

    return *(this->variable_name);
}

std::unordered_set<std::string> getDependencies(){

 


}

unsinged int getTheNumberOfDependencies(){

    return the_number_of_dependencies;
}

unsinged int getTheSumOfInsignedIntegers(){

    return the_sum_of_unsigned_integers;
}

