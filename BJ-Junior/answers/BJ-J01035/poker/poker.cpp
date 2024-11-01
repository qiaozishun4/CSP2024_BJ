#include <bits/stdc++.h>

using namespace std;
    int n,sum,ps=52;
    bool s=1;
    string a[1000];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
       cin>>a[i];
       for(int j=0;j<i;j++){
           if(a[i]==a[j])s=0;
       }
       if(s)sum++;
       s=1;
    }
    cout<<ps-sum;
    return 0;
}