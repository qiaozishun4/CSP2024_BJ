#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
    int t;cin>>t;
    while(t--){
        cin>>n;
        if(n==1){
            cout<<-1;
        }
        else if(n%7==0){
            n/=7;
            while(n--)cout<<'8';
        }
        else if(n%7==1){
            cout<<"10";
            n/=7;n--;
            for(int i=0;i<n;i++)cout<<8;
        }
        cout<<'\n';
    }
    return 0;
}
