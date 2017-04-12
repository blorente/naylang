//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_NAYLANGPARSERSTACK_H
#define NAYLANG_NAYLANGPARSERSTACK_H

#include <core/model/ast/ASTTreeDefinition.h>

namespace naylang {
class NaylangParserStack {

    std::vector<StatementPtr> _contents;

public:
    NaylangParserStack() = default;

    ~NaylangParserStack() = default;

    template<typename T>
    std::vector <std::shared_ptr<T>> pop(int length) {
        std::deque<std::shared_ptr<T>> contents;
        for (int i = 0; i < length; i++) {
            contents.push_front(std::dynamic_pointer_cast<T>(_contents.back()));
            _contents.pop_back();
        }
        return std::vector<std::shared_ptr<T>>{contents.begin(), contents.end()};
    }

    template<typename T>
    std::shared_ptr<T> pop() {
        return pop<T>(1)[0];
    }

    void push(StatementPtr node) {
        _contents.push_back(node);
    }

    void clear() {
        _contents.clear();
    }
};
}
#endif //NAYLANG_NAYLANGPARSERSTACK_H
