#include<bits/stdc++.h>
using namespace std;
int T,n,a,b,c;
int main()
{
    stdin("sticks.in",stdin,r);
    stdout("sticks.out",stdout,w);
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>n;
        c=1;
        if(n>=7)
        {
            while(n>=7)
            {
                n-=7;
                a+=8*c;
                c*=10;
            }
            if(n==1)
            {
                a-=8*c/10;
                a+=1*c;
            }
            else if(n==2)
            {
                a+=1*c;
            }
            else if(n==3)
            {
                a-=8*c/10;
                a+=22*c/10;
            }
            else if(n==4)
            {
                a-=8*c/10;
                a+=2*c;
            }
            else if(n==5)
            {
                a+=2*c;
            }
            else if(n==6)
            {
                a+=6*c;
            }
        }
        else
        {
            if(n==1)
            a=-1;
            else if(n==2)
            a=1;
            else if(n==3)
            a=7;
            else if(n==4)
            a=4;
            else if(n==5)
            a=2;
            else if(n==6)
            a=6;
        }
        cout<<a<<endl;
    }
    return 0;
}
