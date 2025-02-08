class NumberContainers {
private:
    unordered_map<int, set<int>> numToIndices; // Stores indices for each number
    unordered_map<int, int> indexToNum; // Stores number at each index

public:
    void change(int index, int number) {
        if (indexToNum.count(index)) {
            int oldNumber = indexToNum[index];
            numToIndices[oldNumber].erase(index);
            if (numToIndices[oldNumber].empty()) {
                numToIndices.erase(oldNumber);
            }
        }
        indexToNum[index] = number;
        numToIndices[number].insert(index);
    }

    int find(int number) {
        if (numToIndices.count(number) && !numToIndices[number].empty()) {
            return *numToIndices[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */