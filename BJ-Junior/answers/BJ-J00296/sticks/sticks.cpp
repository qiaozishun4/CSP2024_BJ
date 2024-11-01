#include<bits/stdc++.h>
using namespace std;
int t;
string s="";
bool flag=0;
int a[11]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int k=0;k<t;k++){
        int n;
        cin>>n;
        if(n<2) cout<<-1;
        else cout<<(n-1)/7;
    }

    return 0;
}