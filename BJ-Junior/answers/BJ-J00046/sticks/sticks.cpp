#include<bits/stdc++.h>
#include<queue>
using namespace std;
int n,ans;
int bang[10]={6,2,5,0,4,0,6,3,7,0};
int inn[100005];
string vis[100005];

bool xiaoyu(string x,string y){
    if(x.size()!=y.size()){
        return x.size()<y.size();
    }else{
        return x<y;
    }
}

string cha(string s,char rus){
    int siz=s.size();
    if(rus=='0'){
        return s[0]+"0"+s.substr(1,siz-2);
    }
    int dian=0;
    while(s[dian]<rus && dian<siz){
         dian++;
    }
    s=s.substr(0,dian)+rus+s.substr(dian,siz-dian);
    return s;
}

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","r",stdin);
    int t;
    cin>>t;
    int ji=-1;
    for(int i=0;i<t;i++){
        cin>>inn[i];
        ji=max(ji,inn[i]);
    }
    vis[2]="1";
    vis[3]="7";
    vis[4]="4";
    vis[5]="2";
    vis[6]="6";
    vis[7]="8";
    for(int i=8;i<=ji;i++){
        if(vis[i-6]!=""){
            if(vis[i-6][0]=='0'){
                vis[i]=cha(vis[i-6],'6');
            }else{
                vis[i]=cha(vis[i-6],'0');
            }
        }
        if(vis[i-2]!="" && xiaoyu(cha(vis[i-2],'1'),vis[i])){
            vis[i]=cha(vis[i-2],'1');
        }
        if(vis[i-7]!="" && xiaoyu(cha(vis[i-7],'8'),vis[i])){
            vis[i]=cha(vis[i-7],'8');
        }
        if(vis[i-5]!="" && xiaoyu(cha(vis[i-5],'2'),vis[i])){
            vis[i]=cha(vis[i-5],'2');
        }
        if(vis[i-4]!="" && xiaoyu(cha(vis[i-4],'4'),vis[i])){
            vis[i]=cha(vis[i-4],'4');
        }
        if(vis[i-3]!="" && xiaoyu(cha(vis[i-3],'7'),vis[i])){
            vis[i]=cha(vis[i-3],'7');
        }
    }
    for(long long i=0;i<t;i++){
        int tt=inn[i];
        if(vis[tt]==""){
            cout<<"-1"<<endl;
        }else{
            cout<<vis[tt]<<endl;
        }

    }
    return 0;
}