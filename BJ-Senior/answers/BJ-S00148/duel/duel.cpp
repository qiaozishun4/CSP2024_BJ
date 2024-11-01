#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y;
}a[100009];
bool cmp(node c,node d){
    return c.x<d.x;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,mn=INT_MAX;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x;
        a[i].y=1;
        mn=min(mn,a[i].x);
    }
    int f=mn;
    sort(a+1,a+n+1,cmp);
    int ans=n;
    for(int i=1;i<=n;i++){
        if(a[i].y==0) continue;
        if(a[i].x==f) continue;
        int j=i;
        while(a[i].x<=a[j].x&&j>=1){
            j--;
            while(a[j].y==0) j--;
        }
        if(j<1){
            f=a[i].x;
            continue;
        }
        a[j].y=0;
        ans--;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
