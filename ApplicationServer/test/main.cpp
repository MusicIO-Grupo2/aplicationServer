//
// Created by Nicolas Alvarez on 5/11/17.
//

#include <cppunit/ui/text/TestRunner.h>
#include "SongControllerTest.h"

int main( int argc, char **argv)
{
    CppUnit::TextUi::TestRunner runner;
    runner.addTest( SongControllerTest::suite() );

    runner.run();
    return 0;
}