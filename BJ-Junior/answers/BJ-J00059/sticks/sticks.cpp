#include<bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int k[1000005];
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    for(int i=1;i<=100000;i++){
        string str=to_string(i);
        for(int j=0;j<str.size();j++){
            k[i]+=a[str[j]-'0'];
        }
    }
    while(T--){
        int n;
        cin>>n;
        bool flag=false;
        for(int i=1;i<=100000;i++){
            if(k[i]==n) {cout<<i<<"\n";flag=true;break;}
        }
        if(flag==false) cout<<"-1\n";
    }
    return 0;
}
