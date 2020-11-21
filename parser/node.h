//
// Created by admin on 11/21/20.
//

#ifndef PARSE_NODE_H
#define PARSE_NODE_H
#include <iostream>

enum NodeType{
    SIGN,NUMBER,LETTER
};

class Node {


public:

    Node(NodeType t, std::string r);

    NodeType type;
    std::string raw_value;

};


#endif //PARSE_NODE_H
