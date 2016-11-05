#define CATCH_CONFIG_MAIN
#include "catch.h"

TEST_CASE( "Dumb tests", "[Dumb]" ) {
    REQUIRE( 1 == 1 );
    REQUIRE( 1 + 1 == 2 );
}