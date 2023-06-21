#include <vector>
using namespace std;
class RotatedArray
{
public:
    // DO NOT read from stdin or write to stdout.
    // Input is given as the function arguments.
    // Output is taken as the function return value.
    bool checkIfSorted(std::vector<int> arr)
    {
        // Code here
        int n = arr.size();
        int endpt = n;
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                endpt = i + 1;
                break;
            }
        }
        for (int i = endpt; i < n; i++)
        {
            if (arr[i] <= arr[0])
            {
                if (i < n - 1)
                    if (arr[i] > arr[i + 1])
                        return false;
            }
            else
                return false;
        }
        return true;
    }
};
