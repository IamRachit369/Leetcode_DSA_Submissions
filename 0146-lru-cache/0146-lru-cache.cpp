class LRUCache {
public:
    list<int>dll;
    unordered_map<int,pair<list<int>::iterator,int>>mp;
    int n;
    void put_front(int key)
    {
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first = dll.begin();
    }
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
        {
            return -1;
        }
        put_front(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end())
        {
            mp[key].second = value;
            put_front(key);
        }
        else
        {
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            n--;
        }
        if(n < 0)
        {
            int to_delete = dll.back();
            mp.erase(to_delete);
            dll.pop_back();
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */