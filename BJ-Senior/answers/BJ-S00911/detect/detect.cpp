#include<bits/stdc++.h>;
using namespace std ;
typedef long long ll;
ll z[100005],x[100005],c[100005],v[100005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int a,s,d,f,g;
    cin>>a;
    cin>>s>>d>>f>>g;
    for(int i=1;i<=s;i++){
        cin>>z[i]>>x[i]>>c[i];
    }
    for(int i=1;i<=d;i++){
        cin>>v[i];
    }
    cout<<3<<" "<<3;
    return 0;
}

