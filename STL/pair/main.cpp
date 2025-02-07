#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	pair<int, int> p;
	p.first = 23;
	p.second = 14;
	cout << p.first << " " << p.second << endl;
	
	pair<string, int> p1("opcion", 2);
	cout << p1.first << " " << p1.second << endl;
	
	pair<string, int> p2;
	p2 = make_pair("funcion", 1);
	
	cout << p2.first << " " << p2.second << endl;
	
	pair<int, pair<int, string>> p3 = {1, {2, "three"}};
	int x, y;
	string z;
	tie(x, ignore) = p3;
	tie(y, z) = p3.second;
	cout << x << " " << y << " " << z << endl;
	cout << p3.second.second << endl;
	
	vector<pair<int, pair<int, int>>> p4;
	p4.push_back({2, {3, 4}});
	p4.push_back({1, {5, 6}});
	sort(p4.begin(), p4.end());
    for(auto i : p4)
		cout << i.first << " " << i.second.first << " " << i.second.second << endl;
	
	vector<pair<int, int>> p5;
	p5.push_back({3, 4});
	p5.push_back({4, 1});
	p5.push_back({1, 5});
	sort(p5.begin(), p5.end());
	for(auto i : p5)
		cout << i.first << " " << i.second << endl;
	
	sort(p5.begin(), p5.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    
    for(auto i : p5)
		cout << i.first << " " << i.second << endl;
	
	return 0;
}

