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
#include <queue>

class Variable{

  public:
    Variable();
    Variable(std::string & line);
   ~Variable();
                               void getLine(std::string  & line);
                      std::string & getVariableName();
                      std::string & getDependency();
                               bool removeDependency(std::string & dependency_name);
                               void printDependencies();
                       unsigned int getTheNumberOfDependencies();
                               bool isDependencySetEmpty();
                       unsigned int getTotalValue();
  private:
                                  std::string line; 
                                  std::string variable_name;
              std::unordered_set<std::string> dependencies;
                                 unsigned int sum_of_unsigned_integers;
                                         bool isVariableNameSet;
    std::unordered_set<std::string>::iterator iter;
                      std::queue<std::string> tokens;
  

    void parseTokens();
    void tokenizer(std::string & line);
    bool getToken(std::string & token);
    void setVariableName(std::string & variable_name);
    void setDependency(std::string & dependency_name);
    void addValue(unsigned int value);
   
};
#endif // VARIABLE_H
