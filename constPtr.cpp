#include <iostream>
int main(int argc, char** argv)
{
    char* ptr = "This is Berk!";
    const char* ptrA = ptr;
    char* ptrB = ptr;
    const char* const ptrC = ptr;
    char* const ptrD = ptr;


    // can ptrA change content? and it's pointing data?
    std::cout << "ptrA:" << ptrA << std::endl;
    ptrA++;
    std::cout << "ptrA:" << ptrA << std::endl;
    //ptrA[0] = 'I'; // didnt work
    std::cout << "ptrA:" << ptrA << std::endl;

    // can ptrA change content? and it's pointing data?
    std::cout << "ptrB:" << ptrB << std::endl;
    ptrB++;
    std::cout << "ptrB:" << ptrB << std::endl;
    *ptrB = 'I';
    std::cout << "ptrB:" << ptrB << std::endl;

    // can ptrA change content? and it's pointing data?
    std::cout << "ptrC:" << ptrC << std::endl;
    //ptrC++;
    std::cout << "ptrC:" << ptrC << std::endl;
    //ptrC[0] = 'I';
    std::cout << "ptrC:" << ptrC << std::endl;

    // can ptrA change content? and it's pointing data?
    std::cout << "ptrD:" << ptrD << std::endl;
    //ptrD++;
    std::cout << "ptrD:" << ptrD << std::endl;
    ptrD[0] = 'I';
    std::cout << "ptrD:" << ptrD << std::endl;
}
