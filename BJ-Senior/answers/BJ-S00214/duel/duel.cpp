#include<bits/stdc++.h>
using namespace std;
long long n,r[200002],maxn,z,cnt=0;
int main(){
	freopen("r","duel.in",stdin);
	freopen("w","duel.out",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r[i];
    }
    cnt=n;
    for(int i=1;i<=n;i++){
        maxn=0;
        z=9999999;
        for(int j=1;j<=n;j++){
            if(abs(r[i]-r[j])<z&&r[i]!=r[j]&&r[i]>r[j]){
                z=abs(r[i]-r[j]);
                maxn=j;
            }
        }
        if(z!=9999999)
        cnt--;
    }
    cout<<cnt;
    return 0;

}
