#include <iostream>
#include <cmath>
using namespace std;

struct x
{
   int b;      // 4 bytes
   double e;    // 4 bytes
   int f;
   short c;    // 2 bytes
   char a;     // 1 byte
   char d;     // 1 byte
} ;
x bar[2];

struct PRecord {
    uint16_t fnIdx;
    uint16_t fnTriggerExch; // the exchange the quote object that triggered profiler originated from, 0 if not a quote obj
    uint64_t timeSpent;
    uint64_t timeStamp;
    uint64_t fnTriggerId; // to track a single object that triggered several functions such as a quote.
};

struct alignas(16) Bar
{
    int i;       // 4 bytes
    int n;      // 4 bytes
    alignas(4) char arr[3];
    short s;          // 2 bytes
};

struct Foo {
    double i; // 4 bytes
    double f; // 8 bytes
    char a;
} foo;

struct test
{
    char a;
    short int b;
    int c;
    char d;
};

struct shm
{
    uint64_t writePtr;
    uint32_t writeSeqNum;
    char padding1[52];
    uint64_t readPtr;
    uint32_t readSeqNum;
    char padding2[52];
};


int main()
{
    int A[3] = {1, 2, 3};
    float floatval = 2.95;
    cout << sizeof(Foo) << "\t" << alignof(Foo)<< "\t" << alignof(Foo)<<  endl;
    cout << (int)floatval << endl;
    cout << std::floor(floatval) << endl;
    char* x = new char[5];
    cout << x[0] << endl;
    delete[] x;
    cout << sizeof(double) << endl;
    cout << sizeof(uint32_t) << endl;
    cout << sizeof(uint64_t) << endl;
    cout << sizeof(char[48]) << endl;
    cout << sizeof(shm) << endl;


    uint32_t b1 =0, c1 =0;
    uint32_t a1 = 0;
    a1 = 4;
    b1 = 5;
    c1 = 7;
    a1 += b1 - c1;
    cout << (uint32_t)(b1 - c1) << " " <<  a1 << endl;

    cout << sizeof(PRecord) << endl;

}

