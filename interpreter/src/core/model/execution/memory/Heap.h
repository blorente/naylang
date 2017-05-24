//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_HEAP_H
#define NAYLANG_HEAP_H

#include <core/model/execution/objects/GraceObjectDefinitions.h>
#include <list>

namespace naylang {

typedef std::unique_ptr<GraceObject> HeapCell;

class Heap {
    std::list<HeapCell> _storage;
    long _capacity;
    long _threshold;

public:
    static const long DefaultThreshold;
    static const long DefaultCapacity;
    Heap();
    Heap(long capacity);

    template <typename T, typename... Args>
    T* make_obj(Args&&...args) {
        _storage.push_back(std::unique_ptr<T>{new T{std::forward<Args>(args)...}});
        return static_cast<T*>(_storage.back().get());
    };

    const std::list<HeapCell> &storage() const;
    long capacity() const;
    long threshold() const;
};
} // end namespace naylang

#endif //NAYLANG_HEAP_H
