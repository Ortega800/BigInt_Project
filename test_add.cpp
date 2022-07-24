#include <iostream>
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main () {
    {


        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;

        // Test
        result = left + right;

        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);

        std::cout << right << " + " << left << " = " << result << std::endl;
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(0);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 0);
      assert(result == 1);

      std::cout << right << " + " << left << " = " << result << std::endl;
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 1);
      assert(result == 2);

      std::cout << right << " + " << left << " = " << result << std::endl;
    }

    {
        bigint left(300);
        bigint right(255);
        bigint result;

        // Test

        result = left + right;

        //verify

        assert(left == 300);
        assert(right == 255);
        assert(result == 555);

        std::cout << right << " + " << left << " = " << result << std::endl;
    }
    {
        bigint right(147483647);
        bigint left(2000000000);
        bigint result;

        //Test

        result = left + right;

        //verify

        assert(left == 2000000000);
        assert(right == 147483647);
        assert(result == 2147483647);

        std::cout << right << " + " << left << " = " << result << std::endl;

    }
    {
        bigint right(123456);
        bigint left(654321);
        bigint result;

        //Test
        result = left + right;

        //Verify
        assert(right == 123456);
        assert(left == 654321);
        assert(result == 777777);

        std::cout << right << " + " << left << " = " << result << std::endl;
    }

    // Done with Testing
    std::cout << "Done with testing addition." << std::endl;
    return 0;
}
