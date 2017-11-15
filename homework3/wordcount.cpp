#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T1, typename T2>
struct less_second {
    typedef pair<T1, T2> type;
    bool operator ()(type const& a, type const& b) const {
        return a.second < b.second;
    }
};

int main() {
    map<string, int> word_count;
    string text;

    cout << "Enter a string" << '\n';
    getline (cin, text);

    std::transform(text.begin(), text.end(), text.begin(), ::tolower);

    string word = "";
    for (int i = 0, len = text.size(); i <= len; i++){

        if(isalpha(text[i]) && !isspace(text[i])){
          word += text[i];
        }
        if(!isalpha(text[i]) && word != ""){
          word_count[word]++;
          word = "";
        }

    }

    vector<pair<string, int> > mapcopy(word_count.begin(), word_count.end());
    sort(mapcopy.rbegin(), mapcopy.rend(), less_second<string, int>());

    for(int i = 0; i < mapcopy.size(); i++)
    {
        cout << mapcopy[i].first << " " << mapcopy[i].second << endl;
    }
    
    return 0;

}
