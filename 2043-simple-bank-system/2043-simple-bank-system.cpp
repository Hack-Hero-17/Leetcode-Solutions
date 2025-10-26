class Bank {
public:
    vector<long long> bal; // Stores balance for each account (1-indexed)

    // Inline check to verify if an account number is valid
    inline bool valid(int acc) const {
        return acc >= 1 && acc <= (int)bal.size();
    }

    // Constructor initializes the bank with given balances
    Bank(vector<long long>& balance) : bal(balance) {}

    // Transfer 'money' from account 'from' to account 'to'
    bool transfer(int from, int to, long long money) {
        // Validate both accounts first
        if (!valid(from) || !valid(to)) return false;

        // Use references to avoid repeated vector indexing
        long long &src = bal[from - 1];
        long long &dst = bal[to - 1];

        // Check sufficient balance before transfer
        if (src < money) return false;

        // Perform transfer
        src -= money;
        dst += money;
        return true;
    }

    // Deposit 'money' into given account
    bool deposit(int acc, long long money) {
        if (!valid(acc)) return false;
        bal[acc - 1] += money;
        return true;
    }

    // Withdraw 'money' from given account (if sufficient funds)
    bool withdraw(int acc, long long money) {
        if (!valid(acc)) return false;

        long long &cur = bal[acc - 1];
        if (cur < money) return false;

        cur -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */