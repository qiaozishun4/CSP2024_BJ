#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int a,b;
    cin>>a>>b;
    if(a>=b){
        a++;
    }
    else {
        b++;
    }
    cout<<a*b-a+b-a/b;
    return 0;
}
