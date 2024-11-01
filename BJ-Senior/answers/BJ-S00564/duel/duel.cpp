#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<fstream>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
int a[100005],cnt,t[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int cnt=n,p=1;
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        if(a[i]>a[p]){
            cnt--;
            p++;
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
