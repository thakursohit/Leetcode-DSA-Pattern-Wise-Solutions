class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int freq[26] = {0};

        for (int i = 0; i < text.length(); i++)
            freq[text[i] - 'a']++;

        int B = freq['b' - 'a'];
        int A = freq['a' - 'a'];
        int L = freq['l' - 'a'] / 2;
        int O = freq['o' - 'a'] / 2;
        int N = freq['n' - 'a'];

        return min({B, A, L, O, N});
    }
};
