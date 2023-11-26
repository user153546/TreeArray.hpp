#include <iostream>
#include <map>
#include <vector>
#define lowbit(x) ((x) & (-x))
using std::cout;
using std::map;
using std::vector;
template <typename T>
class TreeArray
{
private:
    int n;
    int Size;
    vector<T> tree;
    map<T, vector<T>> num;
    bool init = false;
    void update(T i, T val)
    {
        for (int pos = i + 1; pos < tree.size(); pos += lowbit(pos))
            tree[pos] += val, num[pos].push_back(val);
    }

public:
    T operator[](const int i)
    {
        return query(i, i);
    }
    TreeArray()
    {
        n = 10;
        tree.resize(n);
        Size = 0;
    };
    TreeArray(int size)
    {
        n = size;
        Size = n;
        tree.resize(n + 1);
    };
    TreeArray(vector<T> nums)
    {
        init = true;
        n = nums.size();
        Size = n;
        tree.resize(n + 1);
        for (int i = 0; i < nums.size(); i++)
            update(i, nums[i]);
    };
    ~TreeArray(){};
    void updata(int i, T val)
    {
        update(i, val - query(i, i));
    }
    T query(int i)
    {
        if (i < 0 || i >= Size && init == true)
        {
            cout << "Index is supposed to be in range [0," << Size - 1 << "]\n";
            exit(0);
        }
        T ans = 0;
        for (int pos = i + 1; pos; pos -= lowbit(pos))
            ans += tree[pos];
        return ans;
    }
    T query(int l, int r)
    {
        if (l > r)
            cout << "Left is supposed that should smaller than Right\n";
        if (l == 0)
            return query(r);
        return query(r) - query(l - 1);
    }
    int size() { return Size; }
    void clear()
    {
        Size = 0;
        tree.clear();
        num.clear();
    }
    void show()
    {
        for (auto &y : num)
        {
            std::cout << y.first << ":\n [ ";
            for (auto &x : y.second)
                std::cout << x << ' ';
            std::cout << "] ";
            std::cout << '\n';
        }
        std::cout << "\n";
    }
    void show(int i)
    {
        if (i < 0 || i > Size)
        {
            cout << "Index is supposed to be in range [0," << Size - 1 << "]\n";
            exit(0);
        }
        std::cout << i << ":\n [";
        for (auto &y : num[i])
            std::cout << y << ' ';
        std::cout << "] ";
        std::cout << '\n';
    }
    void push_back(T val)
    {
        if (Size == n)
            tree.resize(n * 2);
        n = tree.size();
        update(Size++, val);
    }
};
