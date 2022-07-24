#include "bigint.hpp"
#include <cstdlib>
#include <iostream>

        bigint::bigint()
        {
        }


     bigint::bigint(int intValue)
        {
                int index = 0;

                while(index < CAPACITY)
                {
                        intArray[index] = intValue % 10;
                        intValue /= 10;
                        ++index;
                }
        }

        bigint::bigint(const char charArray[])
        {
                int charIndex = 0;

                while(charArray[charIndex] != '\0')
                {
                        ++charIndex;
                }

                int intIndex = 0;

                for(--charIndex; charIndex >= 0; --charIndex)
                {
                        // The 'for' loop counts down because counting down is
                        // more efficient than counting up in assembly, and
                        // thus in C++

                        intArray[intIndex] = int(charArray[charIndex]) - 48;
                        ++intIndex;
                }
        }

        void bigint::debugPrint(std::ostream& out) const
        {
                for(int i = CAPACITY - 1; i >= 0; i--)
                {
                        out << bigint::intArray[i] << '|';
                }
                out << bigint::intArray[0];
        }

        bool bigint::operator== (const bigint& rhs)
        {
                bool boolValue = true;

                for(int i = CAPACITY - 1; i >= 0; i--)
                {
                        if(intArray[i] != rhs[i])
                        {
                                boolValue = false;
                        }
                }

        return boolValue;
        }

        void bigint::setBigIntVal(int index, int value)
        {
                intArray[index] = value;
        }

        int bigint::operator[] (int index) const
        {
                return intArray[index];
        }

        std::ostream& operator<< (std::ostream& out, const bigint& outIntArray)
        {
                int i = CAPACITY - 1;

                while((outIntArray[i] == 0) && (i > 0))
                {
                        --i;
                }

                while(i >= 0)
                {
                        if((i % 80 != 0) || (i == 0))
                        {
                                out << outIntArray[i];
                        }
                        else
                        {
                                out << outIntArray[i] << std::endl;
                        }
                --i;
                }
                return out;
        }

        std::istream& operator>> (std::istream& in, bigint& inIntArray)
        {
                int i = CAPACITY - 1;
                int k = 0;

                while ((i >= 0) && (in.peek() != '\n'))

                {
                        in >> inIntArray.intArray[i];

                        --i;
                }
                ++i;

                while(CAPACITY - 1 >= i)
                {
                        inIntArray.intArray[k] = inIntArray.intArray[i];
                        inIntArray.intArray[i] = 0;
                        ++k;
                        ++i;
                }
                return in;

        }

        bigint bigint::operator+ (const bigint& intArrayObj) const
        {
                int carry = 0;
                int indexResult;
                int i = 0;

                bigint intArraySum;

                while(i < CAPACITY)
                {
                        indexResult = intArray[i] + intArrayObj[i] + carry;

                        carry = indexResult / 10;

                        indexResult %= 10;

                        intArraySum.setBigIntVal(i, indexResult);

                        ++i;
                }
                return intArraySum;
        }

        bigint bigint::timesDigit(int x) const
        {
                bigint intArrayResult;
                bigint tempIntArray;

                for(int i = CAPACITY -1; i >= 0; i--) // Copies intArray to tempIntArray
                {
                        tempIntArray.setBigIntVal(i, intArray[i]);
                }

                while(x > 0)
                {
                        intArrayResult = tempIntArray + intArrayResult;

                        --x;
                }
                return intArrayResult;
        }

        bigint bigint::times10(int x) const
        {
                int i = CAPACITY - 1;

                bigint intArrayResult;

                while((intArray[i] == 0) && (i > 0))
                {
                        --i;
                }

                int j = i + x;  // j now contains pointer i shifted by x addresses
                                // towards the larger digits.

                while(i >= 0)
                {
                        intArrayResult.setBigIntVal(j, intArray[i]);

                        --i;
                        --j;
                }
                return intArrayResult;
        }

        bigint bigint::operator* (bigint rhs)
        {
                bigint intArrayResult;
                bigint tempIntArray;

                for(int i = CAPACITY - 1; i >= 0; i--) // Copies intArray to tempIntArray
                {
                        tempIntArray.setBigIntVal(i, intArray[i]);
                }

                int j = CAPACITY - 1; // j will point to the most significant,
                                      // non-zero digit in bigint rhs.

                while((rhs[j] == 0) && (j > 0))
                {
                        --j;
                }

                int i = 0;

                while(i <= j)
                {
                        tempIntArray = tempIntArray.timesDigit(rhs[i]);

                        tempIntArray = tempIntArray.times10(i);

                        intArrayResult = intArrayResult + tempIntArray;

                        for(int k = CAPACITY -1; k >= 0; k--) // Sets tempIntArray
                                                              // to intArray.
                        {
                                tempIntArray.setBigIntVal(k, intArray[k]);
                        }

                        ++i;
                }
                return intArrayResult;
        }