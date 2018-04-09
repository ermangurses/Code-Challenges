/******************************************************************************
//
//
//
//
*****************************************************************************/
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

  private:
    std::string variable_name;
    std::unordered_set<std::string> dependencies;
    int the_number_of_dependencies;
    unsigned int the_sum_of_unsigned_integers;
    bool isVariableNameSet;
    void setVariableName(std::string & variable_name);
    void setDependencies(std::string & dependency_name);
    void parseLine(std::string & line);
    void sumValues(unsigned int value);
    std::string getVariableName();
    std::unordered_set<std::string> getDependencies();
    unsinged int getTheNumberOfDependencies();
    unsinged int getTheSumOfInsignedIntegers();
    
};
#endif
