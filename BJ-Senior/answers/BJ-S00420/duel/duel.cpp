#include<bits/stdc++.h>
using namespace std;
long long a,ma=-1001,mi=782138,e,f,z;
long long b[100001];
long long  c[100001],d[100001];
int main(){
freopen("duel.in","r",stdin);
freopen("duel.out","w",stdout);
cin>>a;

for(long long i=1;i<=a;i++){
cin>>b[i];
c[i]=b[i];
}
for(long long i=1;i<=a;i++){
        if(b[i]!=b[i+1]){
            e++;
        }

    if(e==a-1){
        cout<<1;
        return 0;
    }
}
for(long long  i=1;i<=a;i++){
    if(b[i]<b[i+1]){
        f++;
        b[i]=0;
        z=i+1;
        c[z]=0;
    }
}
    for(int i=1;i<=a;i++){
        for(int j=1;j<=a;j++){
            if(b[i]!=0&&c[j]!=0&&b[j]>b[i]){
                f++;
                b[i]=0;
                b[j]=0;
            }
        }
    }

cout<<a-f;
return 0;
}

