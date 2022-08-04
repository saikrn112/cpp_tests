#include <iostream>
#include <string>
using namespace std;
std::string tmp = "Hello!";

const string& funcAccept(const string& str)
{
    return str;
}

void func(std::string& tmp0)
{
   &tmp0 = &tmp; 
}

int main()
{
    cout << funcAccept("hello") << endl;
    std::string check; 
    func(check);
    cout << check << endl;
    tmp = "he";
    cout << tmp << endl;
    cout << check << endl;
    return 0;
}
