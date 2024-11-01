#include <bits/stdc++.h>
using namespace std;
int T,n,used[10];
string ans="-1";
int Min(string a,string b) {
    int size_a=a.size(),size_b=b.size();
    if (size_a<size_b)
        return 1;
    if (size_b<size_a)
        return 2;
    for (int i=0;i<size_a;i++) {
        if (a[i]<b[i])
            return 1;
        if (a[i]>b[i])
            return 2;
    }
    return 0;
}
string put_last(int use1,int use2,int use3,int use4,int use5,int use6) {
    string num="";
    while (use2--)
        num+='0';
    while (use6--)
        num+='1';
    while (use3--)
        num+='2';
    while (use4--)
        num+='4';
    while (use5--)
        num+='7';
    while (use1--)
        num+='8';
    return num;
}
string create_num(int use1,int use2,int use3,int use4,int use5,int use6) {
    string num="";
    if (use6>=1) {
        num+='1';
        use6--;
    }
    else if (use3>=1) {
        num+='2';
        use3--;
    }
    else if (use4>=1) {
        num+='4';
        use4--;
    }
    else if (use2>=1) {
        num+='6';
        use2--;
    }
    else if (use5>=1) {
        num+='7';
        use5--;
    }
    else if (use1>=1) {
        num+='8';
        use1--;
    }
    num+=put_last(use1,use2,use3,use4,use5,use6);
    return num;
}
void devide(int now,int num) {
    int maxx=now/num,l=now%num;
    used[8-num]=maxx;
    if (l==0) {
        string s=create_num(used[1],used[2],used[3],used[4],used[5],used[6]);
        if (ans=="-1")
            ans=s;
        if (Min(s,ans)==1)
            ans=s;
        return;
    }
    else if (num!=2) {
        devide(l,num-1);
        used[8-num+1]=0;
    }
    if (num==2)
        return;
    if (used[1]+used[2]+used[3]+used[4]+used[5]+used[6]>ans.size()&&ans!="-1")
        return;
    for (int i=1;i<=maxx;i++) {
        l+=num;
        used[8-num]--;
        devide(l,num-1);
        used[8-num+1]=0;
    }
    return;
}
int main() {
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        if (n==1) {
            printf("-1\n");
            continue;
        }
        devide(n,7);
        cout<<ans<<"\n";
        ans="-1";
    }
    return 0;
}
