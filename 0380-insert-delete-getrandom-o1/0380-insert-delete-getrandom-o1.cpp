class RandomizedSet {
    std::unordered_set<int> s;
public:
    RandomizedSet() {
        // declared
    }
    
    bool insert(int val) {
        if (s.find(val) == s.end())
        {
            s.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if (s.find(val) == s.end())
        {
            return false;
        }
        return s.erase(val);
        return true;
    }
    
    int getRandom() {
        if (s.size() > 0)
        {
            int random_number = rand() % s.size();
            int counter = 0;
            for (auto& i : s)
            {
                if (counter == random_number)
                {
                    return i;
                }
                counter++;
            }
        }
        return 0;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */