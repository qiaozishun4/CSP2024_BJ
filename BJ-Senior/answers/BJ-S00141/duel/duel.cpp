#include<bits/stdc++.h>

using namespace std;

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin >> n;

    int cnt=n;
    int r[n+1];
    bool flg[n+1];
    memset(flg,true,n+1);
    for(int i = 0;i < n;i++){
        cin >> r[i];

    }

    sort(r,r+n,cmp);
    for(int i=0;i < n;){
        int ct=0;
        int j=i;
        while(r[i]==r[j]){
            ct++;
            i++;

        }


        if(ct>=n-1-i){
            cnt-=n-i;
            break;
        }
        else{
            cnt-=ct;
        }
    }
    cout << cnt << endl;
    return 0;
}
