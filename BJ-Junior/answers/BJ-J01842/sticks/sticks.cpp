#include<bits/stdc++.h>
using namespace std;
int stick[6]={2,3,4,5,6,7};//1,7,4,2,(0,6),8
int s1[6]={1,7,4,2,6,8};
int n;
string dfs(int sum,int wei,int s1,int s2,int s3,int s4,int s5,int s6)
{
    if(wei>n/7||sum<0)return "99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";
    if(sum==0)
    {
        string ans;
        if(s1)
        {
            ans+="1";
            s1--;
            for(int i=0;i<s4;i++)
                ans+="0";
            for(int i=0;i<s1;i++)
                ans+="1";
            for(int i=0;i<s3;i++)
                ans+="2";
            for(int i=0;i<s6;i++)
                ans+="7";
            for(int i=0;i<s2;i++)
                ans+="4";
            for(int i=0;i<s5;i++)
                ans+="8";
        }
        else if(s3)
        {
            ans+="2";
            s3--;
            for(int i=0;i<s4;i++)
                ans+="0";
            for(int i=0;i<s3;i++)
                ans+="2";
            for(int i=0;i<s6;i++)
                ans+="7";
            for(int i=0;i<s2;i++)
                ans+="4";
            for(int i=0;i<s5;i++)
                ans+="8";
        }
        else if(s6)
        {
            ans+="7";
            s6--;
            for(int i=0;i<s4;i++)
                ans+="0";
            for(int i=0;i<s6;i++)
                ans+="7";
            for(int i=0;i<s2;i++)
                ans+="4";
            for(int i=0;i<s5;i++)
                ans+="8";
        }
        else if(s2)
        {
            ans+="4";
            s2--;
            for(int i=0;i<s4;i++)
                ans+="0";
            for(int i=0;i<s2;i++)
                ans+="4";
            for(int i=0;i<s5;i++)
                ans+="8";
        }
        else if(s5)
        {
            ans+="8";
            s5--;
            for(int i=0;i<s4;i++)
                ans+="0";
            for(int i=0;i<s5;i++)
                ans+="8";
        }
        else if(s4)
        {
            ans+="6";
            s4--;
            for(int i=0;i<s4;i++)
                ans+="0";
        }
        return ans;
    }

    string aa1=dfs(sum-stick[0],wei+1,s1+1,s2,s3,s4,s5,s6);
    string aa2=dfs(sum-stick[1],wei+1,s1,s2+1,s3,s4,s5,s6);
    string aa3=dfs(sum-stick[2],wei+1,s1,s2,s3+1,s4,s5,s6);
    string aa4=dfs(sum-stick[3],wei+1,s1,s2,s3,s4+1,s5,s6);
    string aa5=dfs(sum-stick[4],wei+1,s1,s2,s3,s4,s5+1,s6);
    string aa6=dfs(sum-stick[5],wei+1,s1,s2,s3,s4,s5,s6+1);
    return min(min(min(aa1,aa2),min(aa6,aa3)),min(aa4,aa5));
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n%7==0)
        {
            for(int i=0;i<n/7;i++)
            {
                printf("8");
            }
            printf("\n");
            continue;
        }
        if(n==1)
        {
            printf("-1\n");
            continue;
        }
        if(n%7==1)
        {
            printf("10");
            for(int i=0;i<n/7-1;i++)printf("8");
            printf("\n");
            continue;
        }
        int f=0;
        for(int i=0;i<5;i++)
        {
            if(n==stick[i])
            {
                cout<<s1[i]<<endl;
                f=1;
                break;
            }
        }
        if(f)continue;
        cout<<dfs(n,0,0,0,0,0,0,0)<<endl;
    }
return 0;
}
