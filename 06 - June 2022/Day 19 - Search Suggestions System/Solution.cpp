class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = products.size(), m = searchWord.size();
        vector<vector<string>> ans;
        // Sort the words list to get the solution in lexicographical order.
        sort(products.begin(), products.end());
        // Initialise a string to store the current prefix.
        string pre = "";
        int low = 0, start = 0;
        // Traverse over the string.
        for (char &c:searchWord) {
            // Add the character to the prefix.
            pre += c;
            // Get the starting index of suggestions in the array.
            // Here we will search only after the 'start' index.
            low = lower_bound(products.begin() + start, products.end(), pre) - products.begin();
            ans.push_back({});
            // Check if the next three words are valid suggestions.
            for (int i = low; i < min(low + 3, n) && !products[i].compare(0, pre.size(), pre); i++)
                ans.back().push_back(products[i]);
            // Update the starting index for next search.
            start = low;
        }
        return ans;
    }
};