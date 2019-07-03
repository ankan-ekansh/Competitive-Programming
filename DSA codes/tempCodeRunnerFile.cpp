fflush(stdin);
    for(int i=0;i<n;i++){
        vector<int> v;
        char s[100];
        cin.getline(s,100);
        //cout<<"String is "<<s<<"\n";
        for(int j=0;j<strlen(s);j++){
            if(s[j]!=' '){
                int a = (int)s[j]-48;
                v.push_back(a);
            }
        }
        for(auto j=v.begin();j!=v.end();j++){
            //cout<<"Value "<<*j<<" ";
        }
        //cout<<"\n";
        adj[i]=v;
    }