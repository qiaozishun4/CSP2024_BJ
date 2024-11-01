#include<bits/stdc++.h>
using namespace std;
//         0,1,2,3,4,5,6,7,8,9
int s[10]={6,2,5,5,4,5,6,3,7,6};
int ans1[10]={0,-1,1,7,4,2,6,8};
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n,T,i;
	cin>>T;
	while(T--)
    {
        cin>>n;
        int w=n/7+1;
        int y=n%7;
        if(y==0)
            w--;
        if(w==1)
            cout<<ans1[y]<<endl;
        else if(w==2&&y==3)
            cout<<22<<endl;
        else
        {
            string ans="";
            if(y==1)
                ans="10";
            if(y==2)
                ans="18";
            if(y==3)
                ans="200";
            if(y==4)
                ans="20";
            if(y==5)
                ans="28";
            if(y==6)
                ans="68";
            if(y==0)
                ans="88";
            if(y==3)
                w--;
            for(i=1;i<=w-2;i++)
                ans+='8';
            cout<<ans<<endl;
        }
    }
	return 0;
}
