//
// Created by VuHai on 8/6/25.
//

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int call_count = 0;

int fibonacci_recursion(int n) {
    call_count++;
    if (n <= 1) return n;
    return fibonacci_recursion(n - 1) + fibonacci_recursion(n - 2);
}

int rev_fibonacci(int n, vector<int> &dp) {
    call_count++;
    if (n <= 1) return n;
    if (dp[n]) return dp[n];
    dp[n] = rev_fibonacci(n - 1, dp) + rev_fibonacci(n - 2, dp);
    return dp[n];
}

int fibonacci_dynamic_bottom_up(int n) {
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    return rev_fibonacci(n, dp);
}

template <typename Func, typename... Args>
void benchmark(const string& label, Func func, Args&&... args) {
    call_count = 0;
    auto start = chrono::high_resolution_clock::now();
    auto result = func(std::forward<Args>(args)...);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    cout << label << ": " << result << " (Time: " << duration.count() << " ms, Calls: " << call_count << ")" << endl;
}

int main() {
    int n = 20;
    benchmark("Recursion", fibonacci_recursion, n);
    benchmark("Dynamic topdown", fibonacci_dynamic_bottom_up, n);
}