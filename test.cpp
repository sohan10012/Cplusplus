#include<iostream>
#include<cmath>
using namespace std;

class palindrome {
    public:
        bool isPalindrome(int x)
        {
            if (x < 0 || ((x % 10 == 0) && (x != 0)))
            {
                return false;
            }

            int d = 0;
            while (x > d)
            {
                d = d * 10 + x % 10;
                x /= 10;
            }
            return x == d || x == d / 10;
        }
};
int main()
{
    palindrome p;
    int x;
    cout << "Enter a number: ";
    cin >> x;
    if (p.isPalindrome(x))
    {
        cout << x << " is a palindrome." << endl;
    }
    else
    {
        cout << x << " is not a palindrome." << endl;
    }
    return 0;
}   
