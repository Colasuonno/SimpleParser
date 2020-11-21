//
// Created by admin on 11/21/20.
//

#include "parser.h"
#include <utility>
#include <iostream>
#include "node.h"
#include "FinalNode.h"
#include <cctype>
#include <string>
#include <algorithm>
#include <map>

char const spacers [2] = {'+', '-'};

Parser::Parser(std::string in) : input(std::move(in)) {
    // trim spaces
    input.erase(remove(input.begin(), input.end(), ' '), input.end());
    nodes = {};
}

bool is_spacer(char c){
    for (char s : spacers){
        if (s == c) return true;
    }
    return false;
}

NodeType type_from_char(char c){
    if (is_spacer(c)) return SIGN;
    else if (isdigit(c)) return NUMBER;
    else return LETTER;
}

std::string Parser::parse() {

    // clear nodes
    nodes.clear();
    std::vector<FinalNode> result = {};

    // "2x + 40y + 22x - 20y"

    std::string temp_till_spacer;

    // setting up nodes
    std::cout << "INPUT: " << input << std::endl;
    for (int i = 0; i < input.length(); i++){
        char c = input[i];
        Node node(type_from_char(c), std::string{c});
        nodes.push_back(node);
    }

    // do the magic

    std::vector<Node> prv = {};

    for (Node s : nodes){
        std::cout << "NODE: " << s.raw_value << std::endl;
        //std::cout << "NODE " << s.type << " " << s.raw_value << std::endl;

        switch (s.type) {
            case LETTER:
                if (prv.empty()){
                    FinalNode fn('+', s.raw_value, "");
                    std::cout << "ADDING NODE +" << s.raw_value << std::endl;
                    result.push_back(fn);
                } else {
                    char si;
                    std::string rr;
                    for (Node pr : prv){
                        if (pr.type == SIGN) si = *pr.raw_value.c_str();
                        else rr += pr.raw_value;
                    }
                    rr += s.raw_value;
                    std::cout << "ADDING NODE " << si << rr << std::endl;
                    FinalNode fn(si, s.raw_value, rr);
                    result.push_back(fn);
                }
                prv.clear();
                break;
            case NUMBER:
            case SIGN:
                prv.push_back(s);
                break;
        }
    }

    // add or substract
    std::map<std::string, std::string> letters;
    std::string rr;
    for (FinalNode res : result){
        if (letters.count(res.letter)){
            int pr = std::stoi(letters[res.letter]) + std::stoi(res.sign + res.text);
            letters[res.letter] = std::to_string(pr);
        } else letters[res.letter] = res.sign + res.text;
    }

    for (auto le : letters){

        rr += le.second + le.first + " ";

    }

    return rr;
}