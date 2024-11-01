#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =10005;
int main(){
freopen("poker.in","r",stdin);
freopen("poker.out","w",stdout);
string s;
bool ans[105][105];
int n,cnt;
cin>>n;
for(int i=0;i<=100;i++)
        for(int j=0;j<=100;j++)
            ans[i][j]=0;
for(int i=0;i<n;i++){
    cin>>s;
    ans[s[0]][s[1]]=1;

}
    cnt=0;
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            if(ans[i][j])
                    cnt++;
        }
    }
    cout<<52-cnt;
return 0;
}
