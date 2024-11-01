#include<bits/stdc++.h>
using namespace std;
int d[100010];
int v[100010];
int a[100010];
int st1[100010],st2[100010];
int p[100010];
int t[1000010];
void Main(){
    int n,m,l,q,ans1=0,ans2=0;
    cin>>n>>m>>l>>q;
    for(int i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i];
    for(int i=1;i<=m;i++)cin>>p[i];
    if(a[1]==0){
        for(int i=1;i<=n;i++){
            if(v[i]>q){
                if(d[i]<=p[m])ans1++;
            }
        }
        ans2=m;
        if(ans1!=0)ans2--;
        cout<<ans1<<" "<<ans2<<"\n";
    }else if(a[1]>0){
        for(int i=1;i<=n;i++){
            if(d[i]<=p[m]){
                int cha=p[m]-d[i];
                cha*=(2*a[i]);
                cha+=v[i]*v[i];
                v[i]=ceil(sqrt(cha));
                if(v[i]>q)ans1++;
            }
        }

        ans2=m;
        if(ans1!=0)ans2--;
        cout<<ans1<<" "<<ans2<<"\n";
    }
    return;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){Main();}
    return 0;
}
