    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
    #ifndef ONLINE_JUDGE
        freopen("input2.txt", "rt", stdin);
        freopen("output2.txt", "wt", stdout);
    #endif
      ios::sync_with_stdio(false);
      cin.tie(0);
      cout.tie(0);
      int t;
      cin>>t;
      while(t--)
      {
      	int n;
      	cin>>n;
      	string s[n];
      	for(int i=0;i<n;i++)
      	 cin>>s[i];
       int a[25],ia[25];
       for(int i=0;i<26;i++)
       {
       	a[i]=0;
       	ia[i]=0;
       }
       for(int i=0;i<n;i++)
       {
       	 for(int j=0;j<s[i].length();j++)
       	 {
       	 	if(ia[int(s[i][j])-97]==i+1)
       	 	 continue;
       	 	else
       	 	{
       	 		a[int(s[i][j])-97]+=1;
       	 		ia[int(s[i][j]-97)]=i+1;
       	 	}
       	 }
       }
       int ans=0;
       for(int i=0;i<26;i++)
       {
       	if(a[i]==n)
       	 ans++;
       }
       cout<<ans<<"\n";
      }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
      return 0;
    } 