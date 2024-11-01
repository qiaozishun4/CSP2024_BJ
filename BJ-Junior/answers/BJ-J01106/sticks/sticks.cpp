#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long t,n;
string nmin,nmint="999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";
int su[] = {0,2,5,5,4,0,7,3,8,0};
void dfs(long long cnt){
    bool flag = 0;
    for(int i=1;i<10;i++){
        if(cnt >= su[i]){
            if(su[i] == 0){
                continue;
            }
            flag = 1;
            nmin += (char)(i + '0');
            if(cnt - su[i] == 0){
                if(nmint.size() == nmin.size()){
                    if(nmint > nmin){
                        nmint = nmin;
                    }
                }
                if(nmint.size() > nmin.size()){
                    nmint = nmin;
                }
                return ;
            }
            dfs(cnt - su[i]);
        }
    }
    if(!flag){
        nmint = "-1";
        nmin = "";
        nmint="999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++){
        scanf("%lld",&n);
        dfs(n);
        cout<<nmint<<endl;
        nmin = "";
        nmint="999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";
    }
    return 0;
}

