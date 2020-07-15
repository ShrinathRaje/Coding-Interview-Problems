//implement atoi
//problem: https://practice.geeksforgeeks.org/problems/implement-atoi/1/

// { Driver Code Starts
 #include <bits/stdc++.h>
using namespace std;

int atoi(string str);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		cout<<atoi(s)<<endl;
	}
}// } Driver Code Ends


/*You are required to complete this method */
int atoi(string str) {
    int l = str.length();
    
    int p = 1;
    int num = 0;
    int neg = 0;
    for(int i=l-1; i>=0; --i) {
        char c = str[i];
        if(c <= '9' && c >= '0') {
            num += (c - '0')*p;
            p *= 10;
        } else if(c == '-' && i == 0) {
            neg = 1;
        } else {
            return -1;
        }
    }
    
    return neg ? -num : num;
}