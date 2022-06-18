class WordFilter {
   private:
   // creating Hashmap of string and integer
    unordered_map<string, int> mp;

   public:
    WordFilter(vector<string>& words) {
        int n = words.size();
		// Loop through entire words array that contains all the words in dictionary
        for (int i = 0; i < n; i++) {
            string word = words[i];
			// Look at each word and create its prefix.
            for (int j = 1;j<=word.size();j++) {
                string prefix = word.substr(0,j);
				// Loop through the word in array to generate its suffix.
                for (int k = 0;k<word.size();k++) {
                    string suffix = word.substr(k, word.size());
					// Stroting the key in hashmap that needs to be compared in the function "f".
                    mp[prefix + "*" + suffix] = i + 1;
                }
            }
        }
    }

    int f(string prefix, string suffix) {
        string s = prefix + "*" + suffix;
        return mp[s] - 1;
    }
};