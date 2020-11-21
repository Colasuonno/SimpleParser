//
// Created by admin on 11/21/20.
//

#ifndef PARSE_PARSER_H
#define PARSE_PARSER_H

#include <iostream>
#include <vector>
#include "node.h"

class Parser {

    std::string input;

public:
    Parser(std::string input);
    std::string parse();
    std::vector<Node> nodes;

};


#endif //PARSE_PARSER_H
