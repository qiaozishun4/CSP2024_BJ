#include<bits/stdc++.h>
using namespace std;
int n,m,L,V;
int T;
int d[100005],v[100005],p[100005];
long long a[100005];
int Y,z,Z;
int main(){
freopen("detect.in","r",stdin);
freopen("detect.out","w",stdout);
cin>>T;
cin>>n>>m>>L>>V;
for(int i=0;i<n;i++){
    cin>>d[i]>>v[i]>>a[i];
    if(v[i]>V){
        Y++;
    }
}
for(int i=0;i<m;i++){
    cin>>p[i];
}


for(int i=0;i<n;i++){
    z=(V*V)-(d[i]*d[i]);
    z=z/(2*a[i]);
    z=z+d[i];
    for(int j=0;j<L;j++){
        if(a[j]>V){
            Y++;
        }
        if(p[j]>z){
            Z++;
        }
    }
}
cout<<Y<<Z;

return 0;
}