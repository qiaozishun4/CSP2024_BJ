#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=1;j<=a[i]/7;j++){
            cout<<"8";
        }
        cout<<endl;
    }
    return 0;
}