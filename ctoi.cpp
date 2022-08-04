#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  vector<int> v = {104, 97, 104, 97};
  string s;

  for (auto x : v)
  {
    s += static_cast<char>(x);
  }

  cout << s << endl;
}
