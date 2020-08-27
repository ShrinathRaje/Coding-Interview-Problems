#include<bits/stdc++.h>

using namespace std;

class LRUcache {

private:
	int capacity;
	list<pair<int, int>> cache;
	unordered_map<int, list<pair<int, int>>::iterator> mp;
public:
	LRUcache(int given_capacity) {
		capacity = given_capacity;
	}

	int get(int key) {
		auto it = mp.find(key);

		if(it == mp.end())
			return -1;

		//if the key is found, move it to the front of the list so it becomes most recently used value
		pair<int, int> p = make_pair(it->second->first, it->second->second);
		cache.erase(it->second);
		cache.push_front(p);
		mp[key] = cache.begin();

		return p.second;
	}

	void set(int key, int value) {
		auto it = mp.find(key);

		//update the value and move to front
		if(it != mp.end()) {
			cache.erase(it->second);
			cache.push_front(make_pair(key, value));
			mp[key] = cache.begin();
		} else {
			if(mp.size() == capacity) {
				mp.erase(cache.back().first);
				cache.pop_back();
			}
				

			cache.push_front(make_pair(key, value));
			mp[key] = cache.begin();
		}
	}

	void display() {
		for(auto i = cache.begin(); i != cache.end(); ++i) {
			cout << i->second << " ";
		}

		cout << "\n";
	}
};

int main() {
	int t;
	cin >> t;

	while(t--) {
		int c;
		cin >> c;

		LRUcache lru(c);

		int q;
		cin >> q;

		while(q--) {
			int qt;
			cin >> qt;

			if(qt == 1) {
				int k, v;
				cin >> k >> v;

				lru.set(k, v);
			} else if(qt == 2) {
				int k;
				cin >> k;

				cout << lru.get(k) << "\n";
			}

			//lru.display();
		}
	}

	return 0;
}

/*
input

2
3
5
1 1 5
1 2 10
1 3 15
1 4 20
2 3
5
13
1 1 10
2 1
1 2 20
1 3 30
1 4 40
1 5 50
1 6 60
2 1
2 2
2 8
1 5 100
1 10 120
2 5
*/
