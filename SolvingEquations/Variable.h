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
                        std::string getVariableName();
    std::unordered_set<std::string> getDependencies();
                               bool removeDependency(std::string & dependency_name);
                               void printDependencies();
                       unsigned int getTheNumberOfDependencies();
                       unsigned int getTotalValue();
  private:
                        std::string variable_name;
    std::unordered_set<std::string> dependencies;
                       unsigned int sum_of_unsigned_integers;
                               bool isVariableNameSet;

    void parseLine(std::string & line);
    void setVariableName(std::string & variable_name);
    void setDependency(std::string & dependency_name);
    void addValue(unsigned int value);
};
#endif // VARIABLE_H
