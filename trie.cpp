/*
  trie
  author : Ahmed Fahim

*/
#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <fstream>
#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<algorithm>
#include<numeric>
#include<utility>
#include<functional>
#include<assert.h>
#include<memory.h>
#include<bitset>
#define mod 1000000007
#define int long long
#define endl "\n"
using namespace std;
vector<int> numbers;
const int SIZE = 1e6 + 1;
int dp[2502][2502];
const int MAXX = 1e9+7;
const int MAXNUMBERs=10;
/*
    استعن بالله ولا تعجز
*/
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
struct trie{
    trie* child[MAXNUMBERs];
    bool isLeaf;

  trie(){
    memset(child,-1,sizeof(child));
    isLeaf=0;
  }
  void insert(string word,int i){
     if(i==word.length())
       isLeaf=1;
    else 
        { 
        int cur=word[i]-'0';
        if((int)child[cur]==-1)
           child[cur]=new trie();

        child[cur]->insert(word,i+1);
        }
   }
  bool isExist(string word,int i){
     if(i==word.length())
       return isLeaf;

    
     if((int)child[i]==-1)
    return false;

     return child[i]->isExist(word,i+1);
  }
  bool isPrefix(string word,int i){
     if(i==word.length())
        {
            for (int j = 0; j < 10; j++)
            {
                if((int)child[j]!=-1)
                return true;
            }
            return false;
            
        }
     
     int cur=word[i]-'0';
     if((int)child[cur]==-1)
        return false;
      return child[cur]->isPrefix(word,i+1);
  }
};
int t,n,q;
signed main()
{
    fast();
    cin >> t;
    while(t--){
    cin >>n;
    string ss[n];
    trie tt;
    for (int i = 0; i < n; i++)
    {
        cin>>ss[i];
        tt.insert(ss[i],0);
    }
    int f=0;
    for (int i = 0; i < n; i++)
    {
        if(tt.isPrefix(ss[i],0))
           {
            cout<<"NO"<<endl;
            f=1;
            break;
           }
    }
    if(!f)
    cout<<"YES"<<endl;
    
    
    }

    return 0;
}