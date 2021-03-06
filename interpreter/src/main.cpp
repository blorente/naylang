//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <iostream>
#include <frontends/ConsoleFrontend.h>

using namespace naylang;

int main() {
    ConsoleFrontend frontend;
    try {
        frontend.run();
    } catch (std::string msg){
        std::cerr << msg << std::endl;
    }
    return 0;
}

