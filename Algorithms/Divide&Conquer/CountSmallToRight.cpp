#include <vector>
#include <utility>
class RightSideSmallerTemperatures
{
public:
    void merge(std::vector<int> &count, std::vector<std::pair<int, int>> &v, int low, int mid, int high)
    {
        std::vector<std::pair<int, int>> tmp(high - low + 1);
        int i = low, j = mid + 1, k = 0;

        while (i <= mid && j <= high)
        {
            // NOTE: We're sorting in descending order
            if (v[i].first <= v[j].first)
            {
                tmp[k++] = v[j++];
            }
            else
            {
                count[v[i].second] += high - j + 1;
                tmp[k++] = v[i++];
            }
        }
        while (i <= mid)
        {
            tmp[k++] = v[i++];
        }
        while (j <= high)
        {
            tmp[k++] = v[j++];
        }
        for (int i = low; i <= high; i++)
        {
            v[i] = tmp[i - low];
        }
    }

    void mergeSort(std::vector<int> &count, std::vector<std::pair<int, int>> &v, int low, int high)
    {
        if (low >= high)
        {
            return;
        }
        int mid = low + (high - low) / 2;
        mergeSort(count, v, low, mid);
        mergeSort(count, v, mid + 1, high);
        merge(count, v, low, mid, high);
    }

    std::vector<int> getSmallerTemperaturesCount(std::vector<int> arr)
    {
        int N = arr.size();
        std::vector<std::pair<int, int>> v(N);
        for (int i = 0; i < N; i++)
        {
            v[i] = std::make_pair(arr[i], i);
        }
        std::vector<int> ans(N, 0);
        // sorting in descending order
        mergeSort(ans, v, 0, N - 1);

        return ans;
    }
};
