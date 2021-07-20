#include<iostream>

using namespace std;

int gcd(int a, int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    int a=15,b=10;

    cout<<"\nGCD("<<a<<", "<<b<<") is: "<<gcd(a,b);
}
