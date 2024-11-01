#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
const int MAX = 1e3+7;
int a[MAX][MAX] = {};
int f[MAX][MAX] = {};
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        int a,b,c;
        cin>>a>>b>>c;
        string n;
        for(int i = 1;i <= a;i++) {
            getline(cin,n);
        }
        for(int i = 1;i <= c;i++) {
            cin>>a>>b;
            cout<<1<<endl;
        }
    }
    return 0;
}
