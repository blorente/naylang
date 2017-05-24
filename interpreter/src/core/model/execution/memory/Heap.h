//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_HEAP_H
#define NAYLANG_HEAP_H

#include <core/model/execution/objects/GraceObjectDefinitions.h>
#include <list>

namespace naylang {

class ExecutionEvaluator;
typedef std::unique_ptr<GraceObject> HeapCell;

class Heap {
    std::list<HeapCell> _storage;
    ExecutionEvaluator *_eval;
    long _capacity;
    long _threshold;
    long _triggerInterval;
    long _nthObject;

public:
    static const long DefaultThreshold;
    static const long DefaultCapacity;
    static const long DefaultTriggerInterval;
    Heap(ExecutionEvaluator *eval);
    Heap(ExecutionEvaluator *eval, long capacity);
    Heap(ExecutionEvaluator *eval, long capacity, long threshold, long interval);

    template <typename T, typename... Args>
    T* make_obj(Args&&...args) {
        _nthObject = (_nthObject + 1);
        triggerGCIfNeeded();
        _storage.push_back(std::unique_ptr<T>{new T{std::forward<Args>(args)...}});
        return static_cast<T*>(_storage.back().get());
    };

    const std::list<HeapCell> &storage() const;
    long capacity() const;
    long threshold() const;
    long interval() const;

private:
    void triggerGCIfNeeded();
    void markAndSweep();
    void visitMark(GraceObject *obj);
};
} // end namespace naylang

#endif //NAYLANG_HEAP_H
