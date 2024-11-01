#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,r[N],s=1,sm;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++)   cin>>r[i];
    sort(r+1,r+n+1);
    for(int i=2;i<=n;i++){
        if(r[i]==r[i-1])    s++;
        else{
            if(s>sm)    sm=s;
            s=1;
        }
    }
    if(s>sm)    sm=s;
    cout<<sm;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
