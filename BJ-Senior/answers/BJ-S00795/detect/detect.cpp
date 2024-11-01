#include<bits/stdc++.h>
using namespace std;
int d[100010],v[100010],a[100010],x[100010];
vector<int> s[1000010];
int c[100010];
bool vi[1000010];
map<int,int>mp[30];
int n,m,l,k,p;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    for(p=1;p<=t;p++){
        cin>>n>>m>>l>>k;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>x[i];
            mp[p][x[i]]=1;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                if(v[i]>k){
                    bool f=0;
                    for(int j=d[i];j<=l;j++){
                        if(mp[p][j]){
                            if(!f)ans++,f=1;
                            s[j].push_back(i);
                            c[i]++;
                        }
                    }
                }
            }else{
                int x=k*k-v[i]*v[i],y=2*a[i];
                x/=y;
                bool f=0;
                for(int j=d[i];j<=d[i]+x;j++){
                    if(mp[p][j]){
                        if(!f)ans++,f=1;
                        s[j].push_back(i);
                        c[i]++;
                    }
                }
            }
        }
        int ans2=0;
        while(1){
            int ma=1e9,an=-1;
            for(int i=1;i<=m;i++){
                bool f=0;
                for(int j=0;j<c[x[i]];j++){
                    if(mp[p][s[x[i]][j]]<1){
                        f=1;
                        break;
                    }
                }
                if(f==0){
                    if(c[x[i]]<ma&&!vi[i]){
                        ma=s[x[i]].size();
                        an=i;
                    }
                }
            }
            if(an==-1)break;
            for(int i=0;i<c[x[an]];i++){
                mp[p][s[x[an]][i]]--;
            }
            vi[an]=1;
            ans2++;
        }
        memset(vi,0,sizeof(v));
        cout<<ans<<" "<<ans2-1<<endl;
    }
    return 0;
}
