// 981. Time Based Key-Value Store
// Medium
// 4.1K
// 388
// Companies

// Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

// Implement the TimeMap class:

//     TimeMap() Initializes the object of the data structure.
//     void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
//     String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".

 

// Example 1:

// Input
// ["TimeMap", "set", "get", "get", "set", "get", "get"]
// [[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
// Output
// [null, null, "bar", "bar", null, "bar2", "bar2"]

// Explanation
// TimeMap timeMap = new TimeMap();
// timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
// timeMap.get("foo", 1);         // return "bar"
// timeMap.get("foo", 3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
// timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
// timeMap.get("foo", 4);         // return "bar2"
// timeMap.get("foo", 5);         // return "bar2"

 

// Constraints:

//     1 <= key.length, value.length <= 100
//     key and value consist of lowercase English letters and digits.
//     1 <= timestamp <= 107
//     All the timestamps timestamp of set are strictly increasing.
//     At most 2 * 105 calls will be made to set and get.

// Accepted
// 322.5K
// Submissions
// 623K
// Acceptance Rate
// 51.8%


// Time complexity:

//     In the set() function, in each call, we store a value at (key, timestamp) location, which takes O(L)O(L)O(L) time to hash the string.
//     Thus, for MMM calls overall it will take, O(M⋅L)O(M \cdot L)O(M⋅L) time.

//     In the get() function, in each call, we iterate linearly from timestamp to 1 which takes O(timestamp)O(timestamp)O(timestamp) time and again to hash the string it takes O(L)O(L)O(L) time.
//     Thus, for NNN calls overall it will take, O(N⋅timestamp⋅L)O(N \cdot timestamp \cdot L)O(N⋅timestamp⋅L) time.


class TimeMap {
    unordered_map<string, unordered_map<int, string>> ds;

public:
    TimeMap() {
    }
    
    void set(string key, string value, int ts) {
        this->ds[key][ts] = value;
    }
    
    string get(string key, int ts) {
        if(this->ds.find(key) == this->ds.end())
            return "";
        
        for(int t = ts; t > 0; t--){
            if (this->ds[key].find(t) != this->ds[key].end())
                return this->ds[key][t];
        }

        return "";
    }
};

    // Time complexity:

    //     In the set() function, in each call we store a value at (key, timestamp) location, which takes O(L⋅logM)O(L \cdot logM)O(L⋅logM) time as the internal implementation of sorted maps is some kind of balanced binary tree and in worst case we might have to compare logM nodes (height of tree) of length L each with our key.
    //     Thus, for MMM calls overall it will take, O(L⋅M⋅logM)O(L \cdot M \cdot logM)O(L⋅M⋅logM) time.

    //     In the get() function, we will find correct key in our map, which can take O(L⋅logM)O(L \cdot logM)O(L⋅logM) time and then use binary search on that bucket which can have at most M elements, which takes O(logM)O(logM)O(logM) time.
    //     peekitem in python will also take O(logN)O(logN)O(logN) time to get the value, but the upper bound remains the same.
    //     Thus, for NNN calls overall it will take, O(N⋅(L⋅logM+logM))O(N \cdot (L \cdot logM + logM))O(N⋅(L⋅logM+logM)) time.

    // Space complexity:

    //     In the set() function, in each call we store one value string of length L, which takes O(L)O(L)O(L) space.
    //     Thus, for MMM calls we may store MMM unique values, so overall it may take O(M⋅L)O(M \cdot L)O(M⋅L) space.

    //     In the get() function, we are not using any additional space.
    //     Thus, for all NNN calls it is a constant space operation.


class TimeMap {
    unordered_map<string, map<int, string>> ds;

public:
    TimeMap() {
    }
    
    void set(string key, string value, int ts) {
        this->ds[key][ts] = value;
    }
    
    string get(string key, int ts) {
        if (this->ds.find(key) == this->ds.end()) {
            return "";
        }

        auto it = this->ds[key].upper_bound(ts);
        if(it == this->ds[key].begin())
            return "";

        return prev(it)->second;
    }
};


class TimeMap {
    unordered_map<string, vector<pair<int, string>>> ds;

public:
    TimeMap() {
    }

    void set(string key, string value, int ts) {
        this->ds[key].push_back({ts, value});
    }

    string get(string key, int ts) {
        if (this->ds.find(key) == this->ds.end()) {
            return "";
        }
        int n = this->ds[key].size();
        int st = 0, en = n - 1;

        while(st <= en){
            int mid = st + (en - st) / 2;
            if(this->ds[key][mid].first > ts)
                en = mid - 1;
            else st = mid + 1; //( <= therefore ans will be always at st - 1)
        }

        if(st == 0) return "";
        return this->ds[key][st - 1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */