//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <cmath>
#include "Heap.h"

namespace naylang {
const long Heap::DefaultCapacity = 1000;
const long Heap::DefaultThreshold = std::ceil(Heap::DefaultCapacity / 2.0);

Heap::Heap() : Heap(Heap::DefaultCapacity){}

Heap::Heap(long capacity) :
        _capacity{capacity},
        _threshold{std::ceil(capacity / 2.0)},
        _storage{}{}

const std::list<HeapCell> &Heap::storage() const {
    return _storage;
}

long Heap::capacity() const {
    return _capacity;
}

long Heap::threshold() const {
    return _threshold;
}
}