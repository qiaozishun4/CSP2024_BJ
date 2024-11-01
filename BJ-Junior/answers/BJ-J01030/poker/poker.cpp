#include<bits/stdc++.h>
using namespace std;
int n,ans;
char a[5];
bool f[8][20];
int d[200];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    ans=52;
    d['D']=1,d['C']=2,d['H']=3,d['S']=4;
    d['A']=1,d['T']=10,d['J']=11,d['Q']=12,d['K']=13;
    for(int i='2';i<='9';i++)d[i]=i-'0';
    for(int i=1;i<=n;i++){
        scanf("%s",a+1);
        if(!f[d[a[1]]][d[a[2]]]){
            f[d[a[1]]][d[a[2]]]=true;
            ans--;
        }
    }
    cout<<ans;
    return 0;
}
