#include <bits/stdc++.h>
using namespace std;
string a[10]={"","10","1","22","20","2","6"};
int b[10]={0,8,2,10,11,5,6};
int c[10]={0,-1,1,7,4,2,6};
string d[30];
string qu(int x){
    string ans="";
    for(int i=0;i<=20;i++){
        if((x>>i)&1){
            ans+=d[i];
        }
    }
    return ans;

}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    //next_permutation();
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    d[0]="8";
    for(int i=1;i<=24;i++){
        d[i]=d[i-1]+d[i-1];
    }
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n<7){
            cout<<c[n]<<endl;
            continue;
        }
        cout<<a[n%7]+qu((n-b[n%7])/7)<<endl;
    }
    return 0;
}
