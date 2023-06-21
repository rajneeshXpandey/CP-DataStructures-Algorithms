#include <vector>
using namespace std;
class PascalsTriangle
{
public:
    // DO NOT read from stdin or write to stdout.
    // Input is given as the function arguments.
    // Output is taken as the function return value.
    std::vector<long> getNthRow(int N)
    {
        // Code here
        vector<long> kthrow;
        long curr = 1L, prev = 1L;
        // nC0 nC1......nCn
        kthrow.push_back(curr);
        for (long i = 1; i <= N; i++)
        {
            curr = (prev * (N - i + 1)) / i;
            kthrow.push_back(curr);
            prev = curr;
        }
        return kthrow;
    }
};
