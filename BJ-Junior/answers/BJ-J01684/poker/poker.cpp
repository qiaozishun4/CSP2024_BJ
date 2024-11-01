#include<bits/stdc++.h>
using namespace std;

string datas[20]={"A","2","3","4","5","6","7","8","9","T","J","Q","K"};
string a[10]={"D","C","H","S"};
unordered_map<string,int> m;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        m[s]=min(1,m[s]+1);
    }
    int ans=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            string tmp=a[i]+datas[j];
            ans+=(1-m[tmp]);
        }
    }
    cout<<ans<<endl;
    return 0;
}

