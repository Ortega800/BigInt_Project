//  Tests:  default constructor, string constructor,
// 	    integer constructor, <<operator, and >>operator

#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    {
    	// Test
  	bigint bi;

  	// Verify
    	std::cout << "0 == " << bi << std::endl;
    	assert(bi == 0);
    }

    std::cout << "Done testing default constructor." << std::endl;

    {
        //------------------------------------------------------
        // Test: Construct with 0
        // Setup fixture

        // Test
        bigint bi("0");

        // Verify
        assert(bi == 0);
    }

    {
        //------------------------------------------------------
        // Test: Construct with 1
        // Setup fixture

        // Test
        bigint bi("1");

        // Verify
        assert(bi == 1);
    }

    {
        //------------------------------------------------------
        // Test: Construct with two-digit value
        // Setup fixture

        // Test

        bigint bi("123456");
        std::cout << bi << std::endl;
        // Verify
        assert(bi == 123456);
    }

    {
        //------------------------------------------------------
        // Test: Construct with six-digit value
        // Setup fixture

        // Test
        bigint bi("456789");

        // Verify
        assert(bi == 456789);
    }


    {
        //------------------------------------------------------
        // Test: Construct with value that greater than an int will hold
        // Setup fixture
        // Larger than max int so need to check manually.

        // Test
        bigint bi("6234567890");

        // Verify
        assert(bi == "6234567890");
        std::cout << "6234567890 == ";
        std::cout << bi;
        std::cout << std::endl;

        bi = bigint("62345");   //Check re-assignment.
        assert(bi == "62345");
        std::cout << "62345 == ";
        std::cout << bi;
        std::cout << std::endl;


    }

    {
        //------------------------------------------------------
        // Test: Output
        // Setup fixture
        // Larger than max int so need to check manually.

        // Test
        bigint bi("12345678901234567890123456789012345678901234567890123456789012345678901234567890");

        // Verify
        assert(bi == "12345678901234567890123456789012345678901234567890123456789012345678901234567890");

        std::cout << "1234567890123456789012345678901234567890123456789012345678901234567890"<< std::endl;
        std::cout << "1234567890" << std::endl;
        std::cout << "==" << std::endl;
        std::cout << bi;
        std::cout << std::endl;

    }

    {
        //------------------------------------------------------
        // Test: Construct with multiple declarations.
        // Setup fixture

        // Test
        bigint a("0");
        bigint b("11");
        bigint c("222");
        bigint d("3333");
        bigint e("44444");
        bigint f("555555");
        bigint g("6666666");
        bigint h("77777777");
        bigint i("888888888");


        // Verify
        assert(a == 0);
        assert(b == 11);
        assert(c == 222);
        assert(d == 3333);
        assert(e == 44444);
        assert(f == 555555);
        assert(g == 6666666);
        assert(h == 77777777);
        assert(i == 888888888);
   }


    std::cout << "Done testing constructor bigint(const char[])." << std::endl;

    {

        // Test
        bigint bi(0);

        // Verify
        assert(bi == 0);
        std::cout << "0 == ";
        std::cout << bi;
        std::cout << std::endl;

    }

    {

        // Test
        bigint bi(1);

        // Verify
        assert(bi == 1);
        std::cout << "1 == ";
        std::cout << bi;
        std::cout << std::endl;

    }

    {

        // Test
        bigint bi(100000);

        // Verify
        assert(bi == 100000);
        std::cout << "100000 == ";
        std::cout << bi;
        std::cout << std::endl;

    }


    {

        // Test
        bigint bi(27);

        // Verify
        assert(bi == 27);
        std::cout << "27 ==  ";
        std::cout << bi;
        std::cout << std::endl;

        // Verify
        bi = bigint(5006);   //Check re-assignment.
        assert(bi == 5006);
        std::cout << "5006 ==  ";
        std::cout << bi;
        std::cout << std::endl;

    }

    {

        // Test
        bigint bi(456789);

        // Verify
        assert(bi == 456789);
        std::cout << "456789 == " << bi << std::endl;
    }

    std::cout << "Done testing constructor bigint(int)." << std::endl;

    {
        // Setup
        bigint bi1;
        // Test
        // Verify
        std::cout << "Enter a bigint to test '>>' operator" << std::endl;
        std::cin >> bi1;
        std::cout << "bigint " << bi1 << " was entered." << std::endl;
    }

    return 0;
}
