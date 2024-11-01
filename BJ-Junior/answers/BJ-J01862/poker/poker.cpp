#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    string a[55];
    int n;
    cin>>n;
    int b=52-n;
    string s;
    for(int i=0;i<=n;i++){
        getline(cin,a[i]);
        for(int j=0;j<i;j++){
            if(a[i]==a[j]){
                b++;
            }
        }
    }
    cout<<b<<endl;
return 0;}
