class ProductOfNumbers {
private:
    std::vector<int> prefixProduct;
public:
    ProductOfNumbers() {
        prefixProduct = {1}; // Initialize with 1 for easy product calculations
    }
    
    void add(int num) {
        if (num == 0) {
            prefixProduct = {1}; // Reset if 0 is encountered
        } else {
            prefixProduct.push_back(prefixProduct.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = prefixProduct.size();
        if (k >= n) return 0; // If k elements go beyond a zero reset, return 0
        return prefixProduct[n-1] / prefixProduct[n-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */