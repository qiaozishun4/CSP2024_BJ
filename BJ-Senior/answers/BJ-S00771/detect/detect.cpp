#include<bits/stdc++.h>
using namespace std;
long long t,d[100001],u[100001],a[100001],x[100001],n,m,l,v,p[100001],vis[100001],cnt,ht;
set<long long>r[100001],st,tmp,his[100001];
bool histo(int n){
    for(int k=0;k<ht;k++)
        for(auto it=his[k].begin();it!=his[k].end();it++)
            if(r[n].count(*it)){
                st=his[k];
                return 1;
            }
    return 0;
}
string s1,s2;
bool operator<(set<long long>a,set<long long>b){
    for(auto it=a.begin();it!=a.end();it++){
        s1+=*it+48;
    }
    for(auto it=b.begin();it!=b.end();it++){
        s2+=*it+48;
    }
    return s1<s2;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>l>>v;
        for(int i=0;i<n;i++){
            cin>>d[i]>>u[i]>>a[i];
            if(a[i])x[i]=(u[i]+v)/(2.*a[i])*(v-u[i]);
            r[i].clear();
            vis[i]=0;
        }
        ht=0;
        for(int i=0;i<m;i++){
            cin>>p[i];
            for(int j=0;j<n;j++){
                if(d[j]>p[i]);
                else if(!a[j]&&u[j]>v){
                    vis[j]=1;
                    r[j].insert(i);
                }
                else if(a[j]>0&&p[i]>x[j]+d[j]){
                    vis[j]=1;
                    r[j].insert(i);
                }
                else if(a[j]<0&&p[i]<x[j]+d[j]){
                    vis[j]=1;
                    r[j].insert(i);
                }
            }
        }
        cnt=0;
        for(int i=0;i<n;i++)cnt+=vis[i];
        cout<<cnt<<' ';
        sort(r,r+n);
        cnt=1;
        // for(int i=0;i<n;i++){
        //     cout<<'\n';
        //     for(auto it=r[i].begin();it!=r[i].end();it++)
        //         cout<<*it;
        // }
        // cout<<'\n'<<'\n'<<'\n';
        for(int i=0;i<n;i++){
            if(!r[i].size())continue;
            if(!st.size()&&cnt==1){
                st=r[i];
                continue;
            }
            tmp.clear();
             his[ht]=st;
            for(auto it=st.begin();it!=st.end();it++)
                if(r[i].count(*it))tmp.insert(*it);
            st=tmp;
            // for(auto it=st.begin();it!=st.end();it++)
            //     cout<<*it;
            // cout<<'\n';
            if(!st.size()){
                st=r[i];
                if(histo(i))continue;
                cnt++;
                 ht++;
            }
        }
        cout<<m-cnt<<'\n';
        // for(int i=0;i<=ht;i++){
        //     cout<<'\n';
        //     for(auto it=his[i].begin();it!=his[i].end();it++)
        //         cout<<*it;
        // }
        // cout<<'\n'<<'\n'<<'\n';
    }
    return 0;
}