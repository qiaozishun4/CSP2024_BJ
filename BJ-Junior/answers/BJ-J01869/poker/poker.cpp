#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<list>
#define endl '\n'
using namespace std;
int n,cnt;
map<string,bool> mp;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        if(mp[s]==true) continue;
        else
        {
            cnt++;
            mp[s]=true;
        }
    }
    cout<<52-cnt<<endl;
    return 0;
}


