#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

#include <iostream>
#include <vector>

using std::vector;

class solution {
  public:
    vector<int> lexicalOrder(int n) {
        vector<vector<int>> buckets(9);
        for (int i = 1; i <= n; i++)
            buckets[firstDigit(i)-1].push_back(i);

        vector<int> result;
        for (auto & vec : buckets)
            result.insert(result.end(), vec.begin(), vec.end());
        return result;
    }

  private:
    int firstDigit(int num) {
        while (!(num >= 1 && num <= 9))
            num /= 10;
        return num;
    }
};

int main() {
    int n = 5000000;
    solution soln;
    auto sorted = soln.lexicalOrder(n);
    std::for_each(sorted.begin(), sorted.end(), [](const auto & n){std::cout << n << " ";});
    std::cout << std::endl;
}
