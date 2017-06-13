//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <cmath>
#include <core/model/evaluators/ExecutionEvaluator.h>
#include "Heap.h"

namespace naylang {
const long Heap::DefaultCapacity = 1000;
const long Heap::DefaultThreshold = std::ceil(Heap::DefaultCapacity / 2.0);
const long Heap::DefaultTriggerInterval = std::ceil(Heap::DefaultCapacity / 10.0);

Heap::Heap(ExecutionEvaluator *eval) : Heap(eval, Heap::DefaultCapacity){}

Heap::Heap(ExecutionEvaluator *eval, long capacity) :
        _eval{eval},
        _capacity{capacity},
        _threshold{(long int)std::ceil(capacity / 2.0)},
        _triggerInterval{(long int)std::ceil(capacity / 10.0)},
        _nthObject{0},
        _storage{}
        {}

Heap::Heap(ExecutionEvaluator *eval, long capacity, long threshold, long interval) :
        _eval{eval},
        _capacity{capacity},
        _threshold{threshold},
        _triggerInterval{interval},
        _nthObject{0},
        _storage{}
        {}

const std::list<HeapCell> &Heap::storage() const {
    return _storage;
}

long Heap::capacity() const {
    return _capacity;
}

long Heap::threshold() const {
    return _threshold;
}

long Heap::interval() const {
    return _triggerInterval;
}

void Heap::triggerGCIfNeeded() {
    if (_storage.size() >= _capacity) {
        markAndSweep();
        if (_storage.size() >= _capacity) {
            throw std::string{"Heap: Out of Memory"};
        }
    }
    if (_storage.size() >= _threshold) {
        if (_nthObject == _triggerInterval) {
            _nthObject = 0;
            markAndSweep();
        }
    }
}

void Heap::markAndSweep() {
    for(auto&& obj : _storage) {
        obj->_accessible = false;
    }
    auto scope = _eval->currentScope();
    scope->_accessible = true;
    visitMark(scope);

    for (auto&& obj = _storage.begin(); obj != _storage.end();) {
        if (!(*obj)->_accessible) {
            obj = _storage.erase(obj);
        } else {
            ++obj;
        }
    }
}

void Heap::visitMark(GraceObject *obj) {
    for (auto field : obj->fields()) {
        if (field.first != "self" && !field.second->_accessible) {
            field.second->_accessible = true;
            visitMark(field.second);
        }
    }
}
}