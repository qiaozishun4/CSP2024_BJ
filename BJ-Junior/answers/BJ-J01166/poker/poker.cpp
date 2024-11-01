#include<bits/stdc++.h>
using namespace std;
int c[4][13];
int cnt=52;
int main(){
freopen("poker.in","r",stdin);
freopen("poker.out","w",stdout);
   int n;cin>>n;
   for(int i=1;i<=n;i++){
       string s;cin>>s;
       int x,y;
       if(s[0]=='D')x=0;
       if(s[0]=='C')x=1;
       if(s[0]=='H')x=2;
       if(s[0]=='S')x=3;
       if(s[1]=='A')y=0;
       else if(s[1]=='T')y=9;
       else if(s[1]=='J')y=10;
       else if(s[1]=='Q')y=11;
       else if(s[1]=='K')y=12;
       else y=s[1]-49;
       if(c[x][y]==0)cnt--;
       c[x][y]=1;
   }
   cout<<cnt;
   return 0;
}
/*游记

今天是CSP2024

J组

目标：350

考场估分：100+100+100+60=360

最终得分：

考试经过：

考试开始后，我先读了一下T1，然后秒了。

中途codeblock还炸了，不过问题不大。

T2直接模拟即可。写完后9：10

T3却有难度了，但是特殊性质很明显，写完后9：40

T4是神秘DP！想了好久都没想出来，直接暴力DP，能得60pts。

这个方法难写+难调，差点就假了，不过还是在11：27调完了。

检查。睡觉。

*/
