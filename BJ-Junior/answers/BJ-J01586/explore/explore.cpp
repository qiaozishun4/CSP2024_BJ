#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    int t;
    cin>>t;
    for(int z=1;z<=t;z++)
    {

        int n,m,k,x,y,d,cnt=1;
        char a[1001][1001];
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        a[x][y]='1';
        while(k>0)
        {
            char nextt;
            if(d==0){
                if(1<=x&&x<=n&&1<=y+1&&y+1<=m){
                    nextt=a[x][y+1];
                    if(nextt!='x'){
                        if(nextt=='1'){
                            y++;
                        }
                        else{
                            y++;
                            cnt++;
                            a[x][y]='1';
                        }
                    }
                    else{
                        d=(d+1)%4;
                    }
                }
                else{
                    d=(d+1)%4;
                }
                //cout<<d<<endl;
            }
            else if(d==1){
                nextt=a[x+1][y];
                if(1<=x+1&&x+1<=n&&1<=y&&y<=m){
                    if(nextt!='x'){
                        if(nextt=='1'){
                            x++;
                        }
                        else{
                            x++;
                            cnt++;
                            a[x][y]='1';
                        }
                    }
                    else{
                        d=(d+1)%4;
                    }
                }
                else{
                    d=(d+1)%4;
                }
                //cout<<d<<endl;
            }
            else if(d==2){
                if(1<=x&&x<=n&&1<=y-1&&y-1<=m){
                    nextt=a[x][y-1];
                    if(nextt!='x'){
                        if(nextt=='1'){
                            y--;
                        }
                        else{
                            y--;
                            cnt++;
                            a[x][y]='1';
                        }
                    }
                    else{
                        d=(d+1)%4;
                    }
                }
                else{
                    d=(d+1)%4;
                }
                //cout<<d<<endl;
            }
            else if(d==3){
                if(1<=x-1&&x-1<=n&&1<=y&&y<=m){
                    nextt=a[x-1][y];
                    if(nextt!='x'){
                        if(nextt=='1'){
                            x--;
                        }
                        else{
                            x--;
                            cnt++;
                            a[x][y]='1';
                        }
                    }
                    else{
                        d=(d+1)%4;
                    }
                }
                else{
                    d=(d+1)%4;
                }
                //cout<<d<<endl;
            }
            k--;
        }
        cout<<cnt<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
