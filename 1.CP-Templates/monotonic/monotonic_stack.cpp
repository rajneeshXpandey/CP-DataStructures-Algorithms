/*
def monotonic_stack(nums):
    """An increasing monotonic stack, all elements are sorted in ascending order"""

    stack = []
    res = [-1] * len(nums)

    # Template for descending traversal
    for i in range(len(nums)-1, -1, -1):
        while stack and nums[stack[-1]] <= nums[i]:
            stack.pop()   # Remove existing element that is smaller than incoming element
        if stack:
            res[i] = nums[stack[-1]]
        stack.append(i)  # use for next iteration

    # # Template for ascending traversal
    # for i in range(len(nums)):
    #     while stack and (nums[stack[-1]] < nums[i]):
    #         res[stack.pop()] = nums[i]
    #     stack.append(i)
    return res
*/    

vector<int> nextGreaterElement(vector<int> &nums)
{
    vector<int> ans(nums.size()); // array to store answer
    stack<int> s;
    for (int i = nums.size() - 1; i >= 0; i--)
    { // put it into the stack back to front
        while (!s.empty() && s.top() <= nums[i])
        {            // determine by height
            s.pop(); // short one go away while blocked
        }
        ans[i] = s.empty() ? -1 : s.top(); // the first tall behind this element
        s.push(nums[i]);                   // get into the queue and wait for later height determination
    }
    return ans;
}