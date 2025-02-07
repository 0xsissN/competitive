#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	map<string, int> mp;
	mp["first"] = 1;
	mp["second"] = 2;
	
	cout << mp.size() << "\n";
	for(auto i = mp.begin(); i != mp.end(); i++)
		cout << i->first << " " << i->second << endl;
	
	mp.erase("first");
	mp.clear();
	cout << mp.empty() << endl;
	
	unordered_map<int, int> ump;
	ump[4] = 23;
	ump[2] = 2;
	ump[3] = 3;
	for(auto i = ump.begin(); i != ump.end(); i++)
		cout << i->first << " " << i->second << endl;
	
	multimap<int, int> mm;
	mm.insert(make_pair(1, 100));
	mm.insert(make_pair(2, 200));
	mm.insert(make_pair(1, 50));
	for(auto i : mm)
		cout << i.first << " " << i.second << endl;
	
	unordered_multimap<int, int> umm;
	umm.insert(make_pair(3, 150));
	umm.insert(make_pair(2, 250));
	umm.insert(make_pair(5, 350));
	for(auto i : umm)
		cout << i.first << " " << i.second << endl;
	
	return 0;
}

