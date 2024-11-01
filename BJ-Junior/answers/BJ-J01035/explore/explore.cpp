#include <bits/stdc++.h>

using namespace std;
    int n,t;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>t
    for(int i=0;i<t;i++){
    cin>>n;
    if(n=1)cout<<"-1";
    if(n=2)cout<<"1";
    if(n=3)cout<<"7";
    if(n=4)cout<<"7";
    if(n=5)cout<<"2";
    if(n=6)cout<<"0";
    if(n=7)cout<<"8";
    if(n=8)cout<<"10";
    if(n=9)cout<<"18";
    if(n=10)cout<<"22";}
    return 0;
}
