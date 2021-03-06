#include "stdafx.h"
#include <unordered_map>
#include <list>

using namespace std;

/*
Follow up:
Could you do both operations in O(1) time complexity?
*/

class LRUCache {
	int cap;
	unordered_map<int, int> hash;
	unordered_map<int, list<int>::iterator> recent_it;
	list<int> recent;

public:
	LRUCache(int capacity) {
		cap = capacity;
	}

	int get(int key) {
		if (hash.find(key) != hash.end()) {
			recent.erase(recent_it[key]);
			recent.push_back(key);
			recent_it[key] = --recent.end();
			return hash[key];
		}
		else return -1;
	}

	void put(int key, int value) {

		if (hash.find(key) != hash.end()) {
			recent.erase(recent_it[key]);
		}
		else {
			if (hash.size() == cap) {
				hash.erase(*recent.begin());
				recent_it.erase(*recent.begin());
				recent.erase(recent.begin());
			}
		}
		recent.push_back(key);
		recent_it[key] = --recent.end();
		hash[key] = value;
	}
};

/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache* obj = new LRUCache(capacity);
* int param_1 = obj->get(key);
* obj->put(key,value);
*/

int main()
{
	LRUCache cache = LRUCache(2 /* capacity */);

	cache.put(1, 1);
	cache.put(2, 2);
	cache.get(1);       // returns 1
	cache.put(3, 3);    // evicts key 2
	cache.get(2);       // returns -1 (not found)
	cache.put(4, 4);    // evicts key 1
	cache.get(1);       // returns -1 (not found)
	cache.get(3);       // returns 3
	cache.get(4);       // returns 4

    return 0;
}

