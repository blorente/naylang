#ifndef NAYLANG_ASSIGNMENTSTATEMENT_H
#define NAYLANG_ASSIGNMENTSTATEMENT_H

#include <string>

namespace naylang {

template <class T>
class AssignmentStatement;

template <class T>
class AssignmentStatement : public Statement{
    Environment &_env;
    std::string _lhs;
    const Expression<T> &_rhs;
public:

    AssignmentStatement
};
}

#endif //NAYLANG_ASSIGNMENTSTATEMENT_H
