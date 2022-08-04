// A program to demonstrate the use of stringstream
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	string s = "-12345";

	// object from the class stringstream
	stringstream geek(s);

	// The object has the value 12345 and stream
	// it to the integer x
	int x = 0;
	geek >> x;

	// Now the variable x holds the value 12345
	cout << "Value of x : " << x << endl;

    int i = -456;
    ostringstream os;
    os << i;
    cout << "ier: " << os.str() << " actiter: " << i << endl;;

    istringstream is(os.str());
    int tmpI = 0;
    is >> tmpI;
    cout << "tmp ier: " << is.str() << " actiter: " << tmpI << endl;

    int int_min = INT_MIN;
    cout << int_min << endl;
    cout << -1*int_min << endl;

 
	return 0;
}

