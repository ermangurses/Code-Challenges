//******************************************************************************
//
//
//
//
//******************************************************************************

#ifndef VARIABLE_H
#define VARIABLE_H

#include <cctype>
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_set>

class Variable{

  public:
    Variable();
    Variable(std::string & line);
    ~Variable();
    void getLine(std::string  & line);
    void setVariableName(std::string & variable_name);
    std::string getVariableName();

//  private:
    std::string variable_name;
    std::unordered_set<std::string> dependencies;
    unsigned int the_number_of_dependencies;
    unsigned int sum_of_unsigned_integers;
    bool isVariableNameSet;
    void setDependencies(std::string & dependency_name);
    void parseLine(std::string & line);
    void addValues(unsigned int value);
    std::unordered_set<std::string> getDependencies();
    unsigned int getTheNumberOfDependencies();
    unsigned int getTheSumOfUnsignedIntegers();
    
};
#endif
