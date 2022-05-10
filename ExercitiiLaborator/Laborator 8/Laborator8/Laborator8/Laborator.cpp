#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include <map>
#include <utility>

using namespace std;

ifstream fin("input.in");

struct compare {
    bool operator()(pair<string,int> a , pair<string,int> b) {
        if (a.second == b.second)
            return a.first > b.first;

        return a.second < b.second;
    }
};

bool delim(char, string);

int main() {
    string s;
    string exp = ",.?! ";
    vector<string> v;

    getline(fin, s);

    for (int i = 0; i < s.length(); i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] + 32;

    int l = 0;
    for (int i = 0; i < s.length(); i++) {
        char c = s.at(i);
        if (delim(c, exp) == true) {
            string sub = s.substr(l, i - l);
            l          = i + 1;
            if (sub.length() > 0)
                v.push_back(sub);
        }
    }

    vector<string> uniq;
    map<string, int> mapa;

    for (int h = 0; h < v.size(); h++) {
        if (mapa[v[h]] == 0)
            uniq.push_back(v[h]);
        mapa[v[h]]++;
    }

    vector<pair<string, int>> vect;
    for (int g = 0; g < uniq.size(); g++)
        vect.push_back(make_pair(uniq[g], mapa[uniq[g]]));

    priority_queue<pair<string, int>, vector<pair<string, int>>, compare> prior;
    for (int l = 0; l < vect.size(); l++)
        prior.push(vect[l]);

    while (!prior.empty()) {
        cout << prior.top().first << " => " << prior.top().second << "\n";
        prior.pop();
    }

    return 0;
}

bool delim(char c, string exp) {
    for (int j = 0; j < exp.length(); j++)
        if (exp[j] == c)
            return true;
    return false;
}