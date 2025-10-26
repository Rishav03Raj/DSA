class Bank {
private:
    vector<long long> balance;
    int n;

public:
    Bank(vector<long long>& bl) {
        balance = bl;
        n = bl.size();
    }

    bool transfer(int account1, int account2, long long money) {
        if (account1 >= 1 && account2 >= 1 && account2 <= n && account1 <=n &&
            balance[account1 - 1] >= money) {
            balance[account2 - 1] += money;
            balance[account1 - 1] -= money;

            return true;
        } else
            return false;
    }

    bool deposit(int account, long long money) {
        if (account >= 1 && account <= n) {
            balance[account - 1] += money;
            return true;
        } else
            return false;
    }

    bool withdraw(int account, long long money) {
        if (account >= 1 && account <= n && balance[account - 1] >= money) {
            balance[account - 1] -= money;
            return true;
        } else
            return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */