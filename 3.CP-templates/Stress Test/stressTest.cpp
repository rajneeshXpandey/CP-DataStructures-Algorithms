// *********************** Code Begins ************************ //

struct testcase
{
    int a, n, d;
};
int randomNumber(int a, int b)
{
    return a + (rand() % b);
}
testcase generateTestCase()
{
    testcase randomTest;
    randomTest.a = randomNumber(1, 100000);
    randomTest.n = randomNumber(1, 100000);
    randomTest.d = randomNumber(-100000, 100000);
}
int bruteForce(testcase T)
{
    int brute_result;
    // Brute Force Code
    return brute_result;
}
int optimizedSolution(testcase T)
{
    int opt_result;
    // Optimized Code
    return opt_result;
}

void compare()
{
    testcase random = generateTestCase();
    int ans1 = bruteForce(random);
    int ans2 = optimizedSolution(random);
    if (ans1 != ans2)
    {
        cout << random.a;
        return;
    }
}
