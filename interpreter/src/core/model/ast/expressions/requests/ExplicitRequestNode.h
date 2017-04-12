//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_EXPLICITREQUESTNODE_H
#define NAYLANG_EXPLICITREQUESTNODE_H

#include <core/model/ast/expressions/requests/RequestNode.h>
#include <core/model/ast/expressions/Expression.h>

namespace naylang {

class ExplicitRequestNode : public RequestNode {
    ExpressionPtr _receiver;

public:

    ExplicitRequestNode(const std::string &method, ExpressionPtr receiver);
    ExplicitRequestNode(const std::string &method, ExpressionPtr receiver, const std::vector<ExpressionPtr> &params);

    virtual void accept(Evaluator &evaluator);

    const ExpressionPtr &receiver() const;
};
} // end namespace naylang

#endif //NAYLANG_EXPLICITREQUESTNODE_H
