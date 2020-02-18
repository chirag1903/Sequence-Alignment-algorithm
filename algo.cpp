#include <bits/stdc++.h>

using namespace std;

int align(const string &a,const string &b,int gap,int arr[26][26],string &a2,string &b2);

int main()
{
    // Input strings are given below (we can also take user defined inputs of strings)
    string a1="FTFTALILLAVAV";
    string b1="FTALLLAAV";
    int gap_penalty = 2; 
    //Penalty for a gap matched with an alphabet is 2
    //Penalty for matching an alphabet with another one is 1 
    //Penalty for matching an alphabet with itself is 0
    
    int arr[26][26];
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
        {
            if(i==j) arr[i][j]=0;      // 
            else arr[i][j]=1;       //
        }
    string a2,b2;
    int score=align(a1, b1, gap_penalty, arr, a2, b2);
    cout<<"Input strings:"<<endl;
    cout<<"s1: "<<a1<<endl;
    cout<<"s2: "<<b1<<endl;
    cout<<"Output strings: "<<endl;
    cout<<a2<<endl;
    cout<<b2<<endl;
    cout<<"Total Gap score: "<<score<<endl;
    return 0;
}
int align(const string &a,const string &b,int gap,int arr[26][26],string &a2,string &b2)
{
    int n=a.size();     //length of 1st string
    int m=b.size();     //length of 2nd string
    int A[n][m];        //Declaring a 2-D array for storing optimal substructure answers
    for(int i=0;i<=m;i++)
        A[0][i]=gap*i;
    for(int i=0;i<=n;i++)
        A[i][0]=gap*i;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            char x=a[i-1];
            char y=b[j-1];
            A[i][j]=min({A[i-1][j-1]+arr[x-'A'][y-'A'],A[i-1][j]+gap,A[i][j-1]+gap});
        }
    a2="";
    b2="";
    int j=m;
    int i=n;
    for(;i>=1&&j>=1;--i)
    {
        char x=a[i-1];
        char y=b[j-1];
        if(A[i][j]==A[i-1][j-1]+arr[x-'A'][y-'A'])
        {
            a2=x+a2;
            b2=y+b2;
            --j;
        }
        else if(A[i][j]==A[i-1][j]+gap)
        {
            a2=x+a2;
            b2='-'+b2;
        }
        else
        {
            a2='-'+a2;
            b2=y+b2;
            --j;
        }
    }
    while(i>=1&&j<1)
    {
        a2=a[i-1]+a2;
        b2='-'+b2;
        --i;
    }
    while(j>=1&&i<1)
    {
        a2='-'+a2;
        b2=b[j-1]+b2;
        --j;
    }
    return A[n][m];
}

