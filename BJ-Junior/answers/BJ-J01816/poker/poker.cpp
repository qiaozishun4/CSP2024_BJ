#include<iostream>
using namespace std;
bool have[5][14];
int n,ans,q1[256],q2[256];
const char s1[]="DCHS",s2[]="A23456789TJQK";
void init(){
    for(int i=0;i<4;i++) q1[s1[i]]=i;
    for(int i=0;i<13;i++) q2[s2[i]]=i;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    init();
    cin>>n;
    while(n--){
        char c1,c2;
        cin>>c1>>c2;
        have[q1[c1]][q2[c2]]=true;
    }
    for(int i=0;i<4;i++)
        for(int j=0;j<13;j++)
            if(!have[i][j])
                ans++;
    cout<<ans<<endl;
    return 0;
}