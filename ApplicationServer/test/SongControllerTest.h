//
// Created by Nicolas Alvarez on 5/3/17.
//

#ifndef APPLICATIONSERVER_SONGCONTROLLERTEST_H
#define APPLICATIONSERVER_SONGCONTROLLERTEST_H

#include <cppunit/extensions/HelperMacros.h>

using namespace CPPUNIT_NS;

class SongControllerTest : public CppUnit::TestCase {
public:
    SongControllerTest( std::string name ) : CppUnit::TestCase( name ) {}

    void runTest();

    void testUploadSong();
};


#endif //APPLICATIONSERVER_SONGCONTROLLERTEST_H
