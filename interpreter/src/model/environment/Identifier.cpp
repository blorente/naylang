//
// Copyright (c) 1/2/2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "Identifier.h"

namespace naylang {

std::string Identifier::identifier() const {
    std::string identifier;
    for (auto part : _identifiers) {
        identifier += part;
        identifier += blankIdentifier;
    }

    //Remove trailing blank
    identifier = identifier.substr(0, identifier.size() - blankIdentifier.size());
    return identifier;
}

bool Identifier::operator<(const Identifier &other) const  {
    return other.identifier() < identifier();
}

bool Identifier::operator==(const Identifier &other) const {
    return other.identifier() == identifier();
}

bool Identifier::operator!=(const Identifier &other) const {
    return !(other == *this);
}

}