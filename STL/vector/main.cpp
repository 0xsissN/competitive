#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	vector<int> nums = {1, 2, 3, 4};
	
	for(auto i = nums.begin(); i != nums.end(); i++){
		cout << *i << " ";
	}
	cout << "\n";
	for(auto i = nums.rbegin(); i != nums.rend(); i++){
		cout << *i << " ";
	}
	cout << "\n";
	
	vector<long long int> a;
	vector<string> b;
	vector<char> c;
	
	cout << a.max_size() << "\n";
	cout << b.max_size() << "\n";
	cout << c.max_size() << "\n";
	
	a.resize(10);
	cout << a.capacity() << "\n";
	
	cout << b.empty() << "\n";

	cout << nums.front() << "\n";
	cout << nums.back() << "\n";
	
	nums.push_back(5);
	cout << nums.back() << "\n";
	nums.pop_back();
	cout << nums.back() << "\n";
	
	cout << nums.front() << "\n";
	nums.erase(nums.begin());
	cout << nums.front() << "\n";
	
	nums.clear();
}

