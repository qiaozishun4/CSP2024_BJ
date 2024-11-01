#include<bits/stdc++.h>
using namespace std;
int n,r,s;
int bu[100005];
vector<int>m1,m2;
bool m2emp(){
    for(int i=0;i<m2.size();i++)if(m2[i]!=0)return 0;
    return 1;
}
int main(){
    freopen("duel1.in","r",stdin),freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r,bu[r]++;
    }
    for(int i=1;i<=1e5;i++)if(bu[i]!=0)m1.push_back(bu[i]),m2.push_back(bu[i]);
    int i=0,j=1;
    int len=m2.size();
    while(!m2emp()&&j<len&&m2[len-1]!=0){
        m1[i]--,m2[i]--,m2[j]--;
        //*
        for(int k=0;k<len;k++)cout<<m1[k]<<" ";
        cout<<endl;
        for(int k=0;k<len;k++)cout<<m2[k]<<" ";
        cout<<"\n---\n";
        //*/
        while(m2[i+1]==0||m1[i]==0)i++;
        j=max(j,i+1);
        if(j>=len)break;
        while(m2[j]==0)j++;
    }
    for(int i=0;i<m1.size();i++)s+=m1[i];
    cout<<s;
    return 0;
}
