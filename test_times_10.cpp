#include <iostream>
#include <cassert>
#include "bigint.hpp"

// Tests the times10 function in bigint class

//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test
        bi = bi.times10(0);

        // Verify
        assert(bi == 3);
        std::cout << "Bigint 3 times 10^0 equals " << bi << std::endl;
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(10);

        // Test
        bi = bi.times10(3);

        // Verify
        //assert(bi == 10000);
        std::cout << "Bigint 10 times 10^3 equals " << bi << std::endl;
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(0);

        // Test
        bi = bi.times10(2);

        // Verify
        //assert(bi == 0);
        std::cout << "Bigint 0 times 10^2 equals " << bi << std::endl;
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("1234567");

        // Test
        bi = bi.times10(2);

        // Verify
        //assert(bi == 123456700);
        std::cout << "Bigint 1234567 times 10^2 equals " << bi << std::endl;
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(987);

        // Test
        bi = bi.times10(2);

        // Verify
        //assert(bi == 98700);
        std::cout << "Bigint 987 times 10^2 equals " << bi << std::endl;
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("0000123");

        // Test
        bi = bi.times10(4);

        // Verify
        //assert(bi == 1230000);
        std::cout << "Bigint 123 times 10^4 equals " << bi << std::endl;
    }


    std::cout << "Done testing times_10" << std::endl;
    return 0;
}