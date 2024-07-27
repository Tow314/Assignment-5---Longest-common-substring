#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to find the longest common substring
pair<int, string> longestCommonSubstring(const string& str1, const string& str2) {
    int n = str1.length();
    vector<vector<int>> table(n + 1, vector<int>(n + 1, 0));
    int maxLength = 0;
    int endIndex = 0;

    // Populate the table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                table[i][j] = table[i - 1][j - 1] + 1;
                if (table[i][j] > maxLength) {
                    maxLength = table[i][j];
                    endIndex = i;
                }
            }
        }
    }

    // Extract the longest common substring
    string longestSubstring = str1.substr(endIndex - maxLength, maxLength);

    // Print the lookup table
    cout << "Lookup Table:" << endl;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }

    // Return the length and the substring
    return { maxLength, longestSubstring };
}

int main() {
    string str1, str2;
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;

    auto result = longestCommonSubstring(str1, str2);
    cout << "Length of Longest Common Substring: " << result.first << endl;
    cout << "Longest Common Substring: " << result.second << endl;

    return 0;
}