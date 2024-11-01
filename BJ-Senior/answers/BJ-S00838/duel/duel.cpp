#include <bits/stdc++.h>
using namespace std;
long long n;
int r[100001],k[100001];
int s = 0;
int main(){
freopen("duel.in","r",stdin);
freopen("duel.out","w",stdout);
cin>>n;
for(int i = 0;i<n;i++){
    cin>>r[i];
}
for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
        if(r[i]>r[j]&&k[i]==0&&k[j]==0){
            k[i]==1;
            k[j]==1;
            s+=1;
            break;
        }
    }
}
    cout<<n-s;
    fclose(stdin);
    fclose(stdout);

return 0;
}
