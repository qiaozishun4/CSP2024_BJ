#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
int s[10] = {6,2,5,5,4,5,6,3,7,6};
int t,n;
int a[100005];
bool f = 1;
void dg(int m, int j){
    if(f == 0) return;
    if(m == 0){
        for(int i = 1;i<j;i++) cout<<a[i];
        cout<<endl;
        f = 0;
        return;
    }
    for(int i = 0;i<10;i++){
        if(f == 0) return;
        if(i ==0&&j == 1) continue;
        if(m>=s[i]){
            a[j] = i;
            dg(m-s[i],++j);
            j--;
        }
    }
    return ;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i = 1;i<=t;i++){
        cin>>n;
        if(n<2) cout<<"-1";
        f = 1;
        dg(n, 1);
    }
    return 0;
}
