#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int t[10010],maxx;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,a[10010];
    cin>>n;
    int sum=n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>maxx){
            maxx=a[i];
        }
        t[a[i]]++;
    }
    for(int i=0;i<=maxx;i++){
        for(int x=1;x<=t[i];x++){
            for(int j=maxx;j>=1;j--){
                if(j<i&&t[j]>0){
                    t[j]--;
                    sum--;
                }
            }
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
