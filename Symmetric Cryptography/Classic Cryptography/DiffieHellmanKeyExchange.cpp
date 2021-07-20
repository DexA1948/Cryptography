#include<iostream>
#include<math.h>

using namespace std;

//global variables
int p = 7, g = 3;

class user
{
private:
    int x;
public:
    int y, k;

    void setxy(){
        cout<<"\nEnter your private key value: ";
        cin>>x;
        int extra = pow(g ,x);
        y = extra % p;
        cout<<"Your Public Key is: "<<y<<endl;
    }

    void calck(int y2){
        int extra = pow(y2, x);
        k = extra % p;
    }

    void checkkey(int k2){
        if (k == k2)
            cout<<"Success"<<endl;
        else
            cout<<"Failure"<<endl;
    }

};

int main()
{
    cout<<"The global variables p and g are: "<<p<<" and "<<g<<endl;;

    user a, b;
    cout<<"\nFor user A:";
    a.setxy();
    cout<<"\nFor user B:";
    b.setxy();

    cout<<"\nCalculating Keys for both users: \n";
    a.calck(b.y);
    b.calck(a.y);

    cout<<"\nChecking if generated keys for both parties match: ";
    a.checkkey(b.k);
}

