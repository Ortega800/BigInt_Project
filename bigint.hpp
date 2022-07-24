#include <iostream>
#include <cstdlib>
#include <cassert>
#include <fstream>

const int CAPACITY = 400;

class bigint{
public:
int intArray[CAPACITY] = {};
bigint();
bigint(int intValue);
bigint(const char charArray[]);

friend std::ostream& operator<< (std::ostream& out, const bigint& outIntArray);
friend std::istream& operator>> (std::istream& in, bigint& inIntArray);

bool operator== (const bigint& rhs);
bigint operator+ (const bigint& intArrayObj) const;
int operator[] (int index) const;
bigint operator* (bigint rhs);

void debugPrint(std::ostream& out) const;
void setBigIntVal(int index, int value);
bigint timesDigit(int x) const;
bigint times10(int x) const;
};
