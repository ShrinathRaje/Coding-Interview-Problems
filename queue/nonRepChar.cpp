//first non repeating character in a stream
//problem: https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream/0/

#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cin >> ws; //consume the whitespace left in input stream

		int i = 0;
		int h[26] = {0};
		queue<char> q;
		while(i < n) {
			char c = getchar(); 
			if(c == '\n')
				break;

			if(c != ' ') {
				int v = c - 'a';
				if(h[v] == 0) {
					q.push(c);
				} else if(h[v] == 1) {
					int s = q.size();

					for(int j=0; j<s; ++j) {
						char ch = q.front();
						q.pop();
						if(ch != c)
							q.push(ch);
					}
				}

				++h[c - 'a'];
				if(q.empty())
					printf("%i ", -1);
				else printf("%c ", q.front());

				++i;
			}
		}

		cout << endl;
	}
	return 0;
}