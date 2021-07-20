#include<iostream>
#include<stdlib.h>

using namespace std;

int extendedEuclid(int m, int b)
{
    int a1=1, a2=0, a3=m;
    int b1=0, b2=1, b3=b;
    int t1, t2, t3;
    int q;

    while(1)
    {
        q=int(a3/b3);

        t1=a1-q*b1;
        t2=a2-q*b2;
        t3=a3-q*b3;

        a1=b1;
        a2=b2;
        a3=b3;
        b1=t1;
        b2=t2;
        b3=t3;

        if(b3==0||b3==1) break;
    }

    if(b3==0)
    {
        cout<<"\nInverse Doesn't Exist"<<endl;
        exit(1);
    }
    else
    {
        return b1;
    }
}

int main()
{
    int a=550, b=1759;

    int ans=extendedEuclid(a,b);

    cout<<"Multiplicative inverse of "<<a<<" in GF("<<b<<") is:"<<ans<<endl;

    return 0;
}
