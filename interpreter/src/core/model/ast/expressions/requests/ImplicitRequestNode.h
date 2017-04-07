//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_REQUEST_H
#define NAYLANG_REQUEST_H

#include <core/model/ast/expressions/Expression.h>
#include <core/model/ast/expressions/requests/RequestNode.h>
#include <string>
#include <memory>
#include <vector>

namespace naylang {

class ImplicitRequestNode : public RequestNode {

public:

    ImplicitRequestNode(const std::string &methodName);
    ImplicitRequestNode(const std::string &methodName, const std::vector<ExpressionPtr> &params);

    void accept(Evaluator &evaluator) override;

};

} // end namespace naylang

#endif //NAYLANG_REQUEST_H
