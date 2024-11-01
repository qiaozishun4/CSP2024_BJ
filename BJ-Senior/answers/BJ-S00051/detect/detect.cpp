#include<bits/stdc++.h>
using namespace std;
struct node{
    long long d,v,a;
};
bool zhao(vector<long long>v,long long j){
    for (long long i=0;i<v.size();i++){
        if (v[i]==j){
            return false;
        }
    }
    return true;
}
int main(){
    long long T,a,n,m,l,v,chao;
    freopen("detect1.in","r",stdin);

    cin>>T;
    for(long long i=0;i<T;i++){
        cin>>n,m,l,v;
        vector<node>car(n);
        vector<long long>carp(l+10,0);
        vector<long long>carcnt;
        for(long long i=0;i<n;i++) cin>>car[i].d>>car[i].v>>car[i].a;
        for(long long i=0;i<m;i++){
                cin>>a;
                carp[a]++;
        }
        for(long long i=0;i<n;i++){
            if (car[i].v>=v&&car[i].a!=0){
                long long k=floor((v*v+car[i].v*car[i].v)/(2*car[i].a));
                if (car[i].a>0){
                    for (long long j=car[i].d;j<=l;j++){
                            if(carp[j]>0){
                                    chao++;
                                    if(zhao(carcnt,j)) carcnt.push_back(j);
                            }
                    }
                }
                else{
                    for (long long j=car[i].d;j<=car[i].d+k;j++){
                            if(carp[j]>0){
                                    chao++;
                                    if(zhao(carcnt,j)) carcnt.push_back(j);
                            }
                    }
                }
            }
        }
        long long jian=v;
        for (long long i=0;i<carcnt.size();i++){
            if(carp[carcnt[i]]!=1)
                jian--;
        }
        freopen("detect.out","w",stdout);
        cout<<chao<<' '<<jian<<endl;
    }

    return 0;
}
