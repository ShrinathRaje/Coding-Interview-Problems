//implement strstr
//problem: https://practice.geeksforgeeks.org/problems/implement-strstr/1/


#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}
// } Driver Code Ends


/* The function should return position where the target string 
   matches the string str
Your are required to complete this method */
int strstr(string s, string x) {
    for(int i=0; i<s.length(); ++i) {
        if(s[i] == x[0]) {
            int a = i;
            
            int f = 1;
            for(int j=1; j<x.length(); ++j) {
                if(x[j] != s[++i]) {
                    f = 0;
                    break;
                }
            }
            
            if(f)
                return a;
        }
    }
    
    return -1;
}