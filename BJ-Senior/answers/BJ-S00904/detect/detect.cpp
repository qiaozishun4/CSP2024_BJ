#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T;
int n,m,L,V;
int d[N],v[N],a[N];
int p[N];
vector<int> man[N];
int check1(int num){//jiansu
    int ans=0;
    int l=1,r=m;
    while(l<r){
        int sum=l+r>>1;
        if(p[sum]>=d[num]){
            r=sum;
        }else{
            l=sum+1;
        }
    }
    if(v[num]*v[num]+2*a[num]*(p[r]-d[num]) > V*V){
        man[r].push_back(num),ans=1;
    }
    int ddd=(V*V-v[num]*v[num])/(2*a[num]);
    for(int i=r+1;p[i]<=d[num]+ddd;++i){
        man[i].push_back(num);
    }
    return ans;
}
int check2(int num){//jiasu
    cout<<p[m]<<" "<<d[num]<<endl;
    //if(p[m]<d[num])cout<<"hahaha";
    cout<<"!!!!!!";
    int ans=0;
    int ddd=(V*V-v[num]*v[num])/(2*a[num])+0.999999;
    cout<<ddd;
    if(v[num]*v[num]+2*a[num]*(p[m]-d[num]) > V*V){
        man[m].push_back(num);
        ans=1;
    }
    for(int i=m-1;p[i]>=d[num]+ddd;--i){
        man[i].push_back(num);
    }
    return ans;
}
struct liebiao{
    int first,last;
}l[100005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        int ans=0;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;++i){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;++i){
            cin>>p[i];
            l[i].first=i-1;l[i].last=i+1;
        }
        sort(p+1,p+m+1);
        for(int i=1;i<=n;++i){
            if(a[i]>=0)ans+=check2(i);
            else ans+=check1(i);
            cout<<i<<"ch"<<ans<<endl;
        }
        int ans2=0;
        for(int i=1;i<=m;++i){
            if(man[i].size()==0){
                --m;
                l[l[i].first].last=l[i].last;
                l[l[i].last].first=l[i].first;
            }
        }
        while(m){
            ++ans2;
            int maxn=0,tomax;
            for(int i=0;i<=m;i=l[i].last){
                if(man[i].size()>maxn){
                    maxn=man[i].size();tomax=i;
                }
            }
            l[l[tomax].first].last=l[tomax].last;
            l[l[tomax].last].first=l[tomax].first;
            for(int i=0;i<man[tomax].size();++i){
                for(int j=0;j<=m;j=l[j].last){
                    for(int k=0;k<man[j].size();++k){
                        if(man[j][k]==man[tomax][i]){
                            int aa[114514],sz=man[j].size();
                            for(int z=man[j].size()-1;z>k;--z){
                                aa[sz-z]=man[j][z];
                                man[j].pop_back();
                            }man[j].pop_back();
                            for(int z=1;z<=sz-k;++z){
                                man[j].push_back(a[z]);
                            }
                            break;
                        }
                    }
                }
            }
            for(int i=0;i<=m;i=l[i].last){
                if(man[i].size()==0){
                    --m;
                    l[l[i].first].last=l[i].last;
                    l[l[i].last].first=l[i].first;
                }
            }
        }
        cout<<ans<<" "<<ans2<<endl;
    }
    return 0;
}
