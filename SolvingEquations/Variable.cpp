#include "Variable.h"

//******************************************************************************
//
//
//  Default Costructor 
//
//
//******************************************************************************
Variable::Variable(){

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

    sum_of_unsigned_integers = 0;
    isVariableNameSet = false;
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
//  getLine(std::string & line)
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
                    setDependency(token);                    
                }
            } else if (isdigit(token.at(0))){
                    addValue(std::stoul(token,nullptr,0)); 
            }        
        }
    }
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
// getDependencies()
//
//
//******************************************************************************
std::unordered_set<std::string> Variable::getDependencies(){

   return dependencies;

}

//******************************************************************************
//
//
// setDependency(std::string & dependency_name)
//
//
//******************************************************************************
void Variable::setDependency(std::string & dependency_name){

    dependencies.insert(dependency_name);
}

//******************************************************************************
//
//
// removeDependency(std::string & dependency_name)
//
//
//******************************************************************************
bool Variable::removeDependency(std::string & dependency_name){

    return dependencies.erase(dependency_name);

}

//******************************************************************************
//
//
// printDependencies()
//
//
//******************************************************************************
void Variable::printDependencies(){

    for (const auto & element: dependencies) {
        std::cout<<element<<"\n";
    }
}

//******************************************************************************
//
//
//
//
//******************************************************************************
unsigned int Variable::getTheNumberOfDependencies(){

    return dependencies.size();
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

//******************************************************************************
//
//
//
//
//******************************************************************************
void Variable::addValue(unsigned int value){

    sum_of_unsigned_integers += value;

}

