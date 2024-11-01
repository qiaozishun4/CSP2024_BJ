#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,m,q,a[10]={0},s,c,r;
        cin>>n>>m>>q;
        for(int j=1;j<=n;j++)
        {
            cin>>l;
            for(int k=1;k<=l;k++)
            {
                cin>>s;
                a[s]++;
            }
        }
        for(int j=1;j<=q;j++)
        {

            cin>>c>>r;
            if(a[r]>0)
            {

                cout<<1<<endl;
            }
            else {cout<<0<<endl;}
        }
    }
    return 0;
}
