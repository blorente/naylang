#ifndef NAYLANG_VISITOR_H
#define NAYLANG_VISITOR_H

namespace naylang {

class Expression;
class Environment;

class Visitor {
public:
    Visitor() {}
    ~Visitor() = default;

    virtual void process(Expression &exp) = 0;
};
}


#endif //NAYLANG_VISITOR_H
