#include <bits/stdc++.h>
using namespace std;

int onebit(int n,int m)
{
         if(n==7) return 8;
    else if(n==6) return ((m==1)?0:6);
    else if(n==5) return 2;
    else if(n==4) return 4;
    else if(n==3) return 7;
    else if(n==2) return 1;
}

int main(void)
{
    int t,n,numh[6]={2,5,4,6,3,7},numo[6]={6,2,5,4,3,7};
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> t;
    while(t--)
    {
        int ps[100010]={0},top=0;
        cin >> n;
        if(n==1)
        {
            cout << -1 << endl;
            continue;
        }
        if(n<=7)
        {
            cout << onebit(n,0) << endl;
            continue;
        }
        int ansbit=(n/7),q=0;
        for(int i=0;i<6;i++)
        {
            if((((n-numh[i])/7)+1)==(n/7))
            {
                    ps[top++]=onebit(numh[i],0);
                    n=n-numh[i];
                    break;
            }
        }
        for(int i=0;i<ansbit;i++)
        {
            if(n<=0) break;
            if(n<=7&&n>0)
            {
                ps[top++]=onebit(n,1);
                n=n-onebit(n,1);
                continue;
            }
            for(int i=0;i<6;i++)
            {
                if((((n-numo[i])/7))==(n/7)-1)
                {
                    ps[top++]=onebit(numo[i],1);
                    n=n-numo[i];
                    break;
                }
            }
        }
        int mnh=2147483647,mnzb=0;
        for(int i=0;i<top;i++) if(ps[i]<mnh&&ps[i]!=0) mnh=ps[i],mnzb=i;
        int ne[100010]={0},cnt=0;
        for(int i=0;i<top;i++)
        {
            if(ps[i]!=mnh)
            {
                ne[cnt++]=ps[i];
            }
        }
        sort(ne+0,ne+cnt);
        cout << mnh;
        for(int i=0;i<cnt;i++) cout << ne[i];
        cout << endl;
    }
    return 0;
}
