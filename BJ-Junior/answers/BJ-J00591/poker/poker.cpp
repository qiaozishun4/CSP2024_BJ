#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int bok[6][15] = {},n,ans=52;
    cin >> n;
    for(int i = 1;i<= n;i++)
    {
        char a1,a2;
        int b1,b2;
        cin >> a1 >> a2;
        if(a1=='D')
        {
            b1=0;
        }
        else
        {
            if(a1=='C')
            {
                b1=1;
            }
            else
            {
                if(a1=='H')
                {
                    b1=2;
                }
                else
                {
                    if(a1=='S')
                    {
                        b1=3;
                    }
                }
            }
        }
        if(a2=='A')
        {
            b2=1;
        }
        else
        {
            if(a2=='T')
            {
                b2=10;
            }
            else
            {
                if(a2=='J')
                {
                    b2=11;
                }
                else
                {
                    if(a2=='Q')
                    {
                        b2=12;
                    }
                    else
                    {
                        if(a2=='K')
                        {
                            b2=13;
                        }
                        else
                        {
                            b2 = a2-'0';
                        }
                    }
                }
            }
        }
        if(bok[b1][b2]==0)
        {
            ans--;
            bok[b1][b2]++;
        }
    }
    cout << ans<<endl;
    return 0;
}
