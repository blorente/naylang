//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <cmath>
#include "Heap.h"

namespace naylang {
const long Heap::DefaultThreshold = 5;
const long Heap::DefaultCapacity = 10;

Heap::Heap() :
        _capacity{DefaultCapacity},
        _threshold{DefaultThreshold} {}

const std::list<HeapCell> &Heap::storage() const {
    return _storage;
}

long Heap::capacity() const {
    return _capacity;
}

long Heap::threshold() const {
    return _threshold;
}

Heap::Heap(long capacity) :
    _capacity{capacity},
    _threshold{std::ceil(capacity / 2.0)}{}
}