#include<bits/stdc++.h>
using namespace std;
struct node{
    int num[10],l;
}dp[100001];
bool cmp(node a,node b){
    if(a.l>b.l){
        return 1;
    }else if(a.l<b.l){
        return 0;
    }else {
        int ma=0,mb=0;
        for(int i=1;i<10;i++){
            if(a.num[i]){ma=i;break;}
        }
        for(int i=1;i<10;i++){
            if(b.num[i]){mb=i;break;}
        }
        if(!ma&&a.l!=1) return 1;
        if(!mb&&b.l!=1) return 0;
        if(ma>mb){
            return 1;
        }else if(ma<mb){
            return 0;
        }else{
            a.num[ma]--;b.num[mb]--;
            for(int i=0;i<10;i++){
                if(a.num[i]<b.num[i]){
                    return 1;
                }else if(a.num[i]>b.num[i]){
                    return 0;
                }
            }
        }
    }
    return 0;
}
void out(node x){
    int m=0;
    for(int i=1;i<10;i++){
        if(x.num[i]){m=i;break;}
    }

    if(m){x.num[m]--;cout << m;}
    for(int i=0;i<10;i++){
        while(x.num[i]--){
            cout << i;
        }
    }
    cout << endl;
}

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    int n,T,a[51];
    cin >> T;
    for(int i=1;i<=T;i++){
        cin >> a[i];
        if(n<a[i]){
            n=a[i];
        }
    }

    for(int i=2;i<=n;i++){
        dp[i].l=0x7fffffff;
        int c[7][2]={2,1,3,7,4,4,5,2,6,0,6,6,7,8};
        for(int j=0;j<7;j++){
            int nxt=i-c[j][0];
            if(nxt==1) continue;
            if(nxt<0)break;
            node t=dp[nxt];
            t.num[0]+=t.num[6];
            t.num[6]=0;
            t.num[c[j][1]]++;
            t.l++;
            //out(t);
            if(cmp(dp[i],t)){
                dp[i]=t;
            }
        }

        //out(dp[i]);
    }

    for(int i=1;i<=T;i++){
        if(a[i]<=1){
            cout << -1 << endl;
        }else if(a[i]==6){
            cout << 6 << endl;
        }else{
            out(dp[a[i]]);
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
