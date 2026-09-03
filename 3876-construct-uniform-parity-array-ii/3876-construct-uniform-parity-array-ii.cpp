class Solution {
public:
    bool uniformArray(auto& A) {
        uint32_t x[2] = {-1u, -1u};

        for (uint32_t a : A)
            x[a & 1] = min(x[a & 1], a);

        //TRUE IF: The min is odd || ∄ Odd elements  
        return x[1] < x[0] | x[1] == -1u;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna