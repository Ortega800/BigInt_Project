#include <iostream>
#include <cassert>
#include "bigint.hpp"

// Tests the timesDigit function in the bigint class

//===========================================================================
int main () {
    {
        // Setup
        bigint bi(3);

        // Test
        bi = bi.timesDigit(1);

        // Verify
        assert(bi == 3);
        std::cout << "Bigint 3 times digit 1 equals " << bi << std::endl;
    }
    {
        // Setup
        bigint bi(500);

        // Test
        bi = bi.timesDigit(4);

        // Verify
        assert(bi == 2000);
        std::cout << "Bigint 500 times digit 4 equals " << bi << std::endl;
    }
    {
        // Setup
        bigint bi(2147483647);

        // Test
        bi = bi.timesDigit(1);

        // Verify
        assert(bi == 2147483647);
        std::cout << "Bigint 2147483647 times digit 1 equals " << bi << std::endl;
    }
    {
        // Setup
        bigint bi(12);

        // Test
        bi = bi.timesDigit(0);

        // Verify
        assert(bi == 0);
        std::cout << "Bigint 12 times digit 0 equals " << bi << std::endl;
    }
    {
        // Setup
        bigint bi(0);

        // Test
        bi = bi.timesDigit(8);

        // Verify
        assert(bi == 0);
        std::cout << "Bigint 0 times digit 8 equals " << bi << std::endl;
    }
    {
        // Setup
        bigint bi(1);

        // Test
        bi = bi.timesDigit(4);

        // Verify
        assert(bi == 4);
        std::cout << "Bigint 1 times digit 4 equals " << bi << std::endl;
    }


    //Add test cases as needed.

    std::cout << "Done testing bigint * digit" << std::endl;
    return 0;
}