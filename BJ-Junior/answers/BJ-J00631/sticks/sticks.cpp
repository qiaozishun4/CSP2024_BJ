#include<bits/stdc++.h>
using namespace std;
int a[60]={6,2,5,5,4,5,6,3,7,6,8,4,7,7,6,7,8,5,9,8,11,7,10,10,9,10,11,8,12,11,11,7,10,10,9,10,11,8,12,11,10,6,9,9,8,9,10,7,11,10,11,7,10,10,9,10,11,8};
int b[10]={6,2,5,5,4,5,6,3,7,6};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int k;
    cin>>k;
    for(int i=1;i<=k;i++){
        int n;
        cin>>n;
        bool flag=1;
        for(int i=1;i<=55;i++){
            if(a[i]==n){
                cout<<i<<endl;
                flag=0;
                break;
            }
        }
        if(flag) cout<<-1<<endl;
    }
    return 0;
}
