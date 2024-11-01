#include<bits/stdc++.h>
using namespace std;
int n,cnt=52;
bool c[205][205];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        char a,b;
        cin>>a>>b;
        if(c[a][b]==0) c[a][b]=1,cnt--;
    }
    cout<<cnt;
    return 0;
}
