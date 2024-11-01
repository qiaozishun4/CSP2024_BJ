#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d,e,f,g,h,i,j;
    cin>>a;
    while (a--)
    {
        cin>>b>>c>>d;
        cin>>e>>f>>g;
        int l[b+1][c+1];
        char m[b+1][c+1];
        for (i=1;i<=b;i++)
        {
            for (j=1;j<=c;j++) l[i][j]=0,cin>>m[i][j];
        }
        l[e][f]=1;
        h=1;
        while (d>0)
        {
            if (g==0)
            {
                while (f+1<=c&&d>0&&m[e][f+1]=='.')
                {
                    f++;
                    d--;
                    if (l[e][f]==0) h++,l[e][f]=1;
                }
            }
            else if (g==1)
            {
                while (e+1<=b&&d>0&&m[e+1][f]=='.')
                {
                    e++;
                    d--;
                    if (l[e][f]==0) h++,l[e][f]=1;
                }
            }
            else if (g==2)
            {
                while (f-1>=1&&d>0&&m[e][f-1]=='.')
                {
                    f--;
                    d--;
                    if (l[e][f]==0) h++,l[e][f]=1;
                }
            }
            else
            {
                while (e-1>=1&&d>0&&m[e-1][f]=='.')
                {
                    e--;
                    d--;
                    if (l[e][f]==0) h++,l[e][f]=1;
                }
            }
            g=(g+1)%4;
            d--;
        }
        cout<<h<<endl;
    }
    return 0;
}
