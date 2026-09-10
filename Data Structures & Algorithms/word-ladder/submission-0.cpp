class Solution {
public:

    int ladderLength(string beginWord,
                     string endWord,
                     vector<string>& wordList) {

        unordered_set<string> words(wordList.begin(),
                                     wordList.end());

        // If endWord doesn't exist, transformation is impossible
        if (!words.count(endWord))
            return 0;

        queue<string> q;
        q.push(beginWord);

        unordered_set<string> visited;
        visited.insert(beginWord);

        int level = 1;

        while (!q.empty()) {

            int size = q.size();

            // Process one BFS level
            for (int i = 0; i < size; i++) {

                string word = q.front();
                q.pop();

                if (word == endWord)
                    return level;

                // Change each character
                for (int j = 0; j < word.size(); j++) {

                    char original = word[j];

                    for (char c = 'a'; c <= 'z'; c++) {

                        word[j] = c;

                        // Valid unvisited word
                        if (words.count(word) &&
                            !visited.count(word)) {

                            visited.insert(word);
                            q.push(word);
                        }
                    }

                    word[j] = original;
                }
            }

            level++;
        }

        return 0;
    }
};
