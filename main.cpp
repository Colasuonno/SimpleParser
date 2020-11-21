#include <iostream>
#include "parser/parser.h"


/**
 *
 * Program goals:
 *
 *
 * 2x + 40y + 22x - 20y = { 24x + 20y }
 *
 *
 * @return
 */

int main() {

    Parser parser("2x + 40y + 22x - 20y");

    std::cout << parser.parse();

    return 0;
}
