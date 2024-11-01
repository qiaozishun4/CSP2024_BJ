#include<bits/stdc++.h>
using namespace std;
int n,sn;
string s[53],c;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>c;
        bool f=1;
        for(int j=1;j<i;j++)
        {
            if(s[j]==c)
            {
                f=0;
            }
        }
        if(f)
        {
            sn++;
            s[sn]=c;
        }
    }
    cout<<52-sn;
    return 0;
}
