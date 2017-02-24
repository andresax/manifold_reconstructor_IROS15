/*
 * EdgePointConfigurator.h
 *
 *  Created on: 02/lug/2015
 *      Author: andrea
 */

#ifndef EDGEPOINTCONFIGURATOR_H_
#define EDGEPOINTCONFIGURATOR_H_

#include <fstream>
#include <iostream>
#include <string>

#include <manifoldReconstructor/types_config.hpp>
#include <manifoldReconstructor/utilities.hpp>

class EdgePointConfigurator {
public:
  EdgePointConfigurator(const std::string &path);
  virtual ~EdgePointConfigurator();

  Configuration parseConfigFile();
private:

  Configuration config_;
    std::ifstream file_;
};

#endif /* EDGEPOINTCONFIGURATOR_H_ */
