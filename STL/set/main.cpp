#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	set<int> a;
	a.insert(10);
	a.insert(3);
	a.insert(4);
	
	for(auto i = a.begin(); i != a.end(); i++){
		cout << *i << "\n";
	}
	
	cout << a.size() << "\n";
	cout << a.empty() << "\n";
	cout << a.count(3) << "\n";
	
	a.erase(10);
	for(auto i = a.begin(); i != a.end(); i++){
		cout << *i << "\n";
	}	
	
	unordered_set<int> b;
	b.insert(4);
	b.insert(10);
	b.insert(1);
	
	for(auto i = b.begin(); i != b.end(); i++)
		cout << *i << "\n";
		
	multiset<int> c;
	c.insert(20);
	c.insert(10);
	c.insert(10);
	for(auto i = c.begin(); i != c.end(); i++){
		cout << *i << "\n";
	}
	
	cout << c.count(10) << "\n";
}
 
