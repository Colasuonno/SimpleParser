//
// Created by admin on 11/21/20.
//

#include "node.h"

#include <utility>

Node::Node(NodeType t, std::string r)  {

    type = t;
    raw_value = std::move(r);

}
