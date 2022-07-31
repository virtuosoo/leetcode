class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        for (int i = 1; i <= 10000; ++i) {
            s.insert(i);
        }
    }
    
    int popSmallest() {
        int res = *s.begin();
        s.erase(s.begin());
        return res;
    }
    
    void addBack(int num) {
        s.insert(num);
    }

    set<int> s;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */