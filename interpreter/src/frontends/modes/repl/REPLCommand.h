//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_FRONTENDCOMMAND_H
#define NAYLANG_FRONTENDCOMMAND_H

#include <core/control/REPLInterpreter.h>

namespace naylang {
class REPLCommand {
protected:
    std::string _code;

public:
    REPLCommand(const std::string &code);
    virtual void execute(Interpreter *interpreter) = 0;
};

class ExecCommand : public REPLCommand {
public:
    ExecCommand(const std::string &code);

    void execute(Interpreter *interpreter) override;
};

class LoadCommand : public REPLCommand {
public:
    LoadCommand(const std::string &code);

    void execute(Interpreter *interpreter) override;
};

class PrintCommand : public REPLCommand {
public:
    PrintCommand(const std::string &code);

    void execute(Interpreter *interpreter) override;
};
}

#endif //NAYLANG_FRONTENDCOMMAND_H
