#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int T,n,k,q,r,c,l;
int user[1005][1005],len[1005];

bool check(int endnum,int lastuser,int leftround,int endsub){
    bool ans=false;
    if(leftround==1){
        for(int i=endsub-k+1;i<=endsub-1;i++){
            if(user[lastuser][i]==1) return true;
        }
        return false;
    }
    for(int p=endsub-1;p>=endsub-k+1&&p>0;p--){
        int startnum=user[lastuser][p];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=len[i];j++){
                if(i==lastuser)continue;
                if(user[i][j]==startnum){
                    ans=ans|check(startnum,i,leftround-1,j);
                }
            }
        }
    }
    return ans;

}

int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--){
        memset(user,0,sizeof(user));
        memset(len,0,sizeof(len));
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l;
            len[i]=l;
            for(int j=1;j<=l;j++){cin>>user[i][j];}

        }

        while(q--){
            bool flag=true;
            cin>>r>>c;
            for(int i=1;i<=n&&flag;i++){
                for(int j=1;j<=len[i]&&flag;j++){
                    if(user[i][j]==c){
                        if(check(c,i,r,j)){cout<<1<<endl; flag=false;}
                    }

                }
            }
            if(flag)cout<<0<<endl;
        }

    }
    return 0;
}
