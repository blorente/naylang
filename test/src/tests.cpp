#define CATCH_CONFIG_MAIN
#include "catch.h"

TEST_CASE( "Dumb test", "[Dumb]" ) {
    REQUIRE( 1 == 1 );
    REQUIRE( 1 + 1 == 2 );
}
