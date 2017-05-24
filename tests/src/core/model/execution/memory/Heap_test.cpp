//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <core/model/execution/memory/Heap.h>
#include <core/model/execution/objects/GraceObjectDefinitions.h>
#include <core/model/evaluators/ExecutionEvaluator.h>
#include "catch.h"

using namespace naylang;

TEST_CASE("Naylang Heap", "[Heap]") {
    ExecutionEvaluator eval;

    SECTION("Construction") {
        SECTION("A Heap needs to hold a reference to an ExecutionEvaluator") {
            Heap defaultHeap(&eval);
        }

        SECTION("A Heap has default values for it's max capacity, threshold and trigger interval") {
            Heap defaultHeap(&eval);
            REQUIRE(defaultHeap.capacity() == Heap::DefaultCapacity);
            REQUIRE(defaultHeap.threshold() == Heap::DefaultThreshold);
            REQUIRE(defaultHeap.interval() == Heap::DefaultTriggerInterval);
        }

        SECTION("The capacity can be specified. "
                        "The threshold is half of the capacity, rounded up."
                        "The trigger interval is 1/10 of the capacity, rounded up.") {
            Heap capacity(&eval, 7);
            REQUIRE(capacity.capacity() == 7);
            REQUIRE(capacity.threshold() == 4);
            REQUIRE(capacity.interval() == 1);
        }

        SECTION("The capacity, threshold and interval can be specified by hand") {
            Heap capacity(&eval, 7, 6, 5);
            REQUIRE(capacity.capacity() == 7);
            REQUIRE(capacity.threshold() == 6);
            REQUIRE(capacity.interval() == 5);
        }
    }

    SECTION("Object Creation") {
        SECTION("A Heap can create an object, and will return a pointer to it") {
            Heap largeHeap(&eval, 100);
            auto num = largeHeap.make_obj<GraceNumber>(4.9);
            REQUIRE(num->value() == 4.9);
            auto str = largeHeap.make_obj<GraceString>("Hello");
            REQUIRE(str->value() == "Hello");
            auto usr = largeHeap.make_obj<UserObject>();
            REQUIRE(usr);
        }

        SECTION("When creating an object, it stores it") {
            Heap largeHeap(&eval, 100);
            REQUIRE(largeHeap.storage().size() == 0);
            auto num = largeHeap.make_obj<GraceNumber>(4.9);
            auto str = largeHeap.make_obj<GraceString>("Hello");
            auto usr = largeHeap.make_obj<UserObject>();
            REQUIRE(largeHeap.storage().size() == 3);
        }
    }

    SECTION("Garbage Collection") {
        SECTION("The heap throws if 'capacity' is reached") {
            /*Heap tinyHeap(&eval, 1, 1, 1);
            auto usr = tinyHeap.make_obj<UserObject>();
            usr->setField("good", tinyHeap.make_obj<GraceNumber>(5));
            REQUIRE_THROWS(usr->setField("Bad", tinyHeap.make_obj<GraceString>("Too much")));*/
        }

        SECTION("Garbage collection triggers every 'interval' insertions, if there are at least 'threshold' objects") {
            Heap tinyHeap(&eval, 2, 2, 1);
            tinyHeap.make_obj<UserObject>();
            REQUIRE(tinyHeap.storage().size() == 1);
            tinyHeap.make_obj<GraceNumber>(0);
            REQUIRE(tinyHeap.storage().size() == 2);
            tinyHeap.make_obj<GraceNumber>(2);
            REQUIRE(tinyHeap.storage().size() == 0);
        }
    }
}