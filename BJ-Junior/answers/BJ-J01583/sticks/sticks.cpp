#include<bits/stdc++.h>

using namespace std;

typedef pair<int,string> pis;

//0 6
//1 2
//2 5
//3 5
//4 4
//5 5
//6 6
//7 3
//8 7
//9 6

bool cmp(string s1,string s2){
    if(s1.length()!=s2.length()){
        return s1.length()<s2.length();
    }else{
        return s1<s2;
    }
}

bool hasf[100010][2];
pis f[100010][2];
string F[8]={" "," ","1","7","4","2","0","8"};
pis dfs(int n,bool isfirst){
    if(hasf[n][isfirst]){
        return f[n][isfirst];
    }
    if(n<2){
        hasf[n][isfirst]=1;
        return f[n][isfirst]={0,""};
    }
    if(n==2){
        hasf[n][isfirst]=1;
        return f[n][isfirst]={1,"1"};
    }
    if(n==3){
        hasf[n][isfirst]=1;
        return f[n][isfirst]={1,"7"};
    }
    if(n==4){
        hasf[n][isfirst]=1;
        return f[n][isfirst]={1,"4"};
    }
    if(n==5){
        hasf[n][isfirst]=1;
        return f[n][isfirst]={1,"2"};
    }
    if(n==6){
        hasf[n][isfirst]=1;
        if(isfirst){
            return f[n][isfirst]={1,"6"};
        }else{
            return f[n][isfirst]={1,"0"};
        }
    }
    if(n==7){
        hasf[n][isfirst]=1;
        return f[n][isfirst]={1,"8"};
    }
    if(n==2){
        hasf[n][isfirst]=1;
        return f[n][isfirst]={1,"1"};
    }

    string ans="-1";
    for(int i=7;i>=2;i--){
        if((i==6)&&isfirst){
            pis tans=dfs(n-i,false);
            if(tans.first){
                tans.second="6"+tans.second;
                if(ans=="-1"){
                    ans=tans.second;
                }else if(cmp(tans.second,ans)){
                    ans=tans.second;
                }
            }
        }else{
            pis tans=dfs(n-i,false);
            if(tans.first){
                tans.second=F[i]+tans.second;
                if(ans=="-1"){
                    ans=tans.second;
                }else if(cmp(tans.second,ans)){
                    ans=tans.second;
                }
            }
        }
    }
    if(ans!="-1"){
        hasf[n][isfirst]=1;
        return f[n][isfirst]={1,ans};
    }else{
        hasf[n][isfirst]=1;
        return f[n][isfirst]={0,""};
    }
}

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        pis ans=dfs(n,1);
        if(ans.first){
            //cout<<ans.second<<endl;
            printf("%s\n",ans.second.c_str());
        }else{
            //cout<<"-1"<<endl;
            printf("-1\n");
        }
    }
    return 0;
}
