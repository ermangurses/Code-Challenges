/******************************************************************************
//
//
//
//
*****************************************************************************/
#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
class Variable{

  public:
    Variable();
    ~Variable();
    void getLine(std::string  & line);
  private:
    std::string variable;
    std::set<std::string> dependencies;
    int the_number_of_dependencies;
    int sum_of_unsigned_integers;
    void setVariableName();
    void setDependencies();
    void setValue();
    void parseLine(std::string & line);
    void sumValues(unsigned int value);
};
#endif
