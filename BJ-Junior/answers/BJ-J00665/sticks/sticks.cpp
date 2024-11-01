#include <bits/stdc++.h>
using namespace std;
long long T,B,a[100005],w=2;
bool h=0;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> T;
    a[1]=-1;
    a[2]=1;
    a[3]=7;
    a[4]=4;
    a[5]=2;
    a[6]=6;
    a[7]=8;
    for(int i=1;i<=T;i++)
    {

        cin >> B;
        for(int i=8;i<=B;i++)
        {
            if(i-2>7*w)
            {
                if(i-5>7*w)
                {
                    if(i-6>7*w)
                    {
                        if(i-7>7*w)
                        {
                            w++;
                            i--;
                        }
                        else
                        {
                            a[i]=a[7]*(10^(w-1))+a[i-7];
                            if(a[i-7]%(10^(w-2))==6)
                            {
                                a[i]-=6*(10^(w-2));
                            }
                        }
                    }
                    else
                    {
                        a[i]=a[6]*(10^(w-1))+a[i-6];
                        if(a[i-6]%(10^(w-2))==6)
                        {
                            a[i]-=6*(10^(w-2));
                        }
                    }
                }
                else
                {
                    a[i]=a[5]*(10^(w-1))+a[i-5];
                    if(a[i-5]%10^(w-2)==6)
                    {
                        a[i]-=6*(10^(w-2));
                    }
                }
            }
            else
            {
                a[i]=a[2]*(10^(w-1))+a[i-2];
                if(a[i-2]%(10^(w-2))==6)
                {
                    a[i]-=6*(10^(w-2));
                }
            }
        }
     cout << a[B] << endl;
    }
}