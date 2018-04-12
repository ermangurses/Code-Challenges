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

//******************************************************************************
//
//
//  Costructor 
//
//
//******************************************************************************
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

//******************************************************************************
//
//
//  Destructor
//
//
//******************************************************************************
void Variable::getLine(std::string & line){

    parseLine(line);
}


//******************************************************************************
//
//
//  Destructor
//
//
//******************************************************************************
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
                    addValues(std::stoul(token,nullptr,0)); 
            }        
        }
    }
}
//******************************************************************************
//
//
//  setVariableName(std::string & variable_name);
//
//
//******************************************************************************
void Variable::setVariableName(std::string & variable_name){

    this->variable_name = variable_name;

}

//******************************************************************************
//
//
// setDependencies(std::string & dependency_name)
//
//
//******************************************************************************
void Variable::setDependencies(std::string & dependency_name){

    dependencies.insert(dependency_name);
    the_number_of_dependencies++; 
}

//******************************************************************************
//
//
//
//
//******************************************************************************
void Variable::addValue(unsigned int value){

    sum_of_unsigned_integers += value;

}

//******************************************************************************
//
//
//
//
//******************************************************************************
std::string Variable::getVariableName(){

    return this->variable_name;
}

//******************************************************************************
//
//
//
//
//******************************************************************************
std::unordered_set<std::string> Variable::getDependencies(){

}

//******************************************************************************
//
//
//
//
//******************************************************************************
unsigned int Variable::getTheNumberOfDependencies(){

    return the_number_of_dependencies;
}         

//******************************************************************************
//
//
//
//
//******************************************************************************
unsigned int Variable::getTheSumOfUnsignedIntegers(){

    return sum_of_unsigned_integers;
}

