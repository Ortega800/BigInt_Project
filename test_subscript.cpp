#include <iostream>
#include <cassert>
#include "bigint.hpp"

// Tests the subscript operator for bigint

//===========================================================================
int main () {

    {
        // Setup
        bigint bi(4);

        // Test
        int digit = bi[0];

        // Verify
        assert(bi    == 4);
        assert(digit == 4);

        std::cout << " bigint is " << bi << ", digit in index 0 is " << digit << std::endl;
    }
    {
        // Setup
        bigint bi(123456789);

        // Test
        int digit = bi[5];

        // Verify
        //bigint bi is too big to test using assert function.
        assert(digit == 4);

        std::cout << " bigint is " << bi << ", digit in index 5 is " << digit << std::endl;
    }
    {
        // Setup
        bigint bi("1213141516171819");

        // Test
        int digit = bi[12];

        // Verify
        //bigint bi is too big to test using assert function.
        assert(digit == 3);

        std::cout << " bigint is " << bi << ", digit in index 12 is " << digit << std::endl;
    }
    {
        // Setup
        bigint bi(0);

        // Test
        int digit = bi[0];

        // Verify
        assert(bi    == 0);
        assert(digit == 0);

        std::cout << " bigint is " << bi << ", digit in index 0 is " << digit << std::endl;
    }
    {
        // Setup
        bigint bi(876);

        // Test
        int digit = bi[1];

        // Verify
        assert(bi    == 876);
        assert(digit == 7);

        std::cout << " bigint is " << bi << ", digit in index 1 is " << digit << std::endl;
    }
    {
        // Setup
        bigint bi(1);

        // Test
        int digit = bi[399];

        // Verify
        assert(bi    == 1);
        assert(digit == 0);

        std::cout << " bigint is " << bi << ", digit in index 399 is " << digit << std::endl;
    }

    std::cout << "Done testing subscript." << std::endl;
    return 0;
}
