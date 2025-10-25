// testing gemini
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

// Function to solve a single test case
void solve() {
    long long n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;

    long long ones_count = 0;
    for (char ch : s) {
        if (ch == '1') {
            ones_count++;
        }
    }

    // Loop simulates the game round by round, tracking the number of ones.
    while (true) {
        // Terminal Condition 1: Alice wins.
        // If Alice starts her turn with k or fewer ones, she can remove them all.
        if (ones_count <= k) {
            std::cout << "Alice" << std::endl;
            return;
        }

        // The number of ones Alice has to place after her move.
        long long ones_to_place = ones_count - k;

        // Terminal Condition 2: Bob wins.
        // Check if Alice can force Bob to flip at least one '1'.
        // If she cannot, Bob can flip an all-zero substring, restoring the number
        // of ones and stalling the game indefinitely.
        // The condition for this is based on a packing argument.
        if ((ones_to_place + 1) * k < n + 1) {
            std::cout << "Bob" << std::endl;
            return;
        }

        // Progress Condition: The game continues.
        // If Alice can force a non-zero flip, the number of ones will decrease
        // by at least 1. We take the most pessimistic case for Alice (m=1).
        ones_count--;
    }
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}