#include <bits/stdc++.h>
using namespace std;
long long n,sum=52;
bool b[100][100]={0};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        string a;
        cin>>a;
        if(a[0]=='D'&&!b[1][a[1]]){
            b[1][a[1]]=1;
            sum--;
        }
        else if(a[0]=='C'&&!b[2][a[1]]){
            b[2][a[1]]=1;
            sum--;
        }
        else if(a[0]=='H'&&!b[3][a[1]]){
            b[3][a[1]]=1;
            sum--;
        }
        else if(a[0]=='S'&&!b[4][a[1]]){
            b[4][a[1]]=1;
            sum--;
        }
    }
    cout<<sum;
    return 0;
}

