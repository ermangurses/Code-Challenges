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
    void readLine(std::string  & line);
    void parseLine(std::string & line);
  private:
    std::string variable;
    std::set<std::string> dependencies;
    void trim(std::string & token);
    int the_number_of_dependencies;
    int sum_of_unsigned_integers;
    
};
#endif
