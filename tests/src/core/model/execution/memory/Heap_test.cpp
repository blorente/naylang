//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <core/model/execution/memory/Heap.h>
#include <core/model/execution/objects/GraceObjectDefinitions.h>
#include "catch.h"

using namespace naylang;

TEST_CASE("Naylang Heap", "[Heap]") {
    Heap h;

    SECTION("Construction") {
        SECTION("A Heap has default values for it's max capacity and threshold") {
            Heap defaultHeap;
            REQUIRE(defaultHeap.capacity() == Heap::DefaultCapacity);
            REQUIRE(defaultHeap.threshold() == Heap::DefaultThreshold);
        }

        SECTION("The capacity can be specified. The threshold is half of the capacity, rounded up") {
            Heap capacity(7);
            REQUIRE(capacity.capacity() == 7);
            REQUIRE(capacity.threshold() == 4);
        }
    }

    SECTION("Object Creation") {
        SECTION("A Heap can create an object, and will return a pointer to it") {
            Heap largeHeap(100);
            auto num = largeHeap.make_obj<GraceNumber>(4.9);
            REQUIRE(num->value() == 4.9);
            auto str = largeHeap.make_obj<GraceString>("Hello");
            REQUIRE(str->value() == "Hello");
            auto usr = largeHeap.make_obj<UserObject>();
            REQUIRE(usr);
        }

        SECTION("When creating an object, it stores it") {
            Heap largeHeap(100);
            REQUIRE(largeHeap.storage().size() == 0);
            auto num = largeHeap.make_obj<GraceNumber>(4.9);
            auto str = largeHeap.make_obj<GraceString>("Hello");
            auto usr = largeHeap.make_obj<UserObject>();
            REQUIRE(largeHeap.storage().size() == 3);
        }
    }
}