class RandomizedCollection {
public:
    std::unordered_multimap<int, int> collection;
    int place = 0;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        collection.insert(std::make_pair(val, place));
        place++;
        if (collection.count(val) > 1)
        {
            return false;
        }
        return true;
    }
    
    bool remove(int val) {
        if (collection.count(val) == 0)
        {
            return false;
        }
        auto it = collection.find(val);
        if (it != collection.end()) 
        {
            collection.erase(it); 
        }
        place--;
        return true;
    }
    
    int getRandom() {
        int num = rand() % place;
        int counter = 0;
        for (auto& i : collection)
        {
            if (num == counter)
            {
                return i.first;
            }
            counter++;
        }
        return 0;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */