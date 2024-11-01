#include<bits/stdc++.h>
using namespace std;
int r[100001];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>r[i];
    }
    sort(r+1,r+n+1);
    int a=0,b=0;
    for(int i=1;i<=n;i++)
    {
        if(r[i]==r[i-1])
        {
            b++;
            if(a>0)
            {
                a--;
            }
        }
        else
        {
            a+=b;
            b=0;
            if(a>0)
            {
                a--;
            }
            b++;
        }
    }
    a+=b;
    cout<<a<<endl;
    return 0;
}
