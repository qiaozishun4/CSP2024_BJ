#include <bits/stdc++.h>
using namespace std;
#define ll long long
int read(){
    int x=0,f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c-'0');
    return x*f;
}
void read(int &x){
    int f=1; x=0;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c-'0');
    x*=f;
}
void write(int x){
    if(x<10){
        putchar(x+'0');
        return ;
    }
    write(x/10);
    putchar(x%10+'0');
}
const int N=55;
string s[N];
int n;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    sort(s+1,s+n+1);
    n=unique(s+1,s+n+1)-s-1;
    cout<<52-n<<endl;
    return 0;
}
