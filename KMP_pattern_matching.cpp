#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/*
* Author: mahmoud youssef
* Respect Coursera Honor Code
* Copyright © 2019. All rights reserved
*/

// Find all occurrences of the pattern in the text and return a
// vector with all positions in the text (starting from 0) where 
// the pattern starts in the text.
//using Knuth-Morris-Pratt Algorithm in liner time complexity o(p+t)

vector<int> computePrefixFunction(string p) {
    int n = p.size();
    vector<int>s(n);
    s[0] = 0;
    int border = 0;
    for (int i = 1; i < n; i++) {
        while (border > 0 && p[i] != p[border]) {
            border = s[border - 1];
        }
        if (p[i] == p[border]) {
            border++;
        }
        else {
            border = 0;
        }
        s[i] = border;
    }
    return s;
}
vector<int> KMP(string pattern, string text) {
    string STR = pattern + "$" + text;
    vector<int> s = computePrefixFunction(STR);
    vector<int> startAppear;
    for (int i = pattern.size() + 1; i < STR.size(); i++) {
        if (s[i] == pattern.size()) {
            startAppear.push_back(i - (2 * pattern.size()));
        }
    }
    return startAppear;
}

vector<int> find_pattern(const string& pattern, const string& text) {
    return KMP(pattern, text);
}
int main() {
  string pattern, text;
  cout << "\t\t\t\twellcom in KMP pattern matching algorithm\n\n" << endl;
  cout << "enter the text that you search in it :: ";
  cin >> text;
  cout << "enter the pattren you are locking for :: ";
  cin >> pattern;
  
  vector<int> result = find_pattern(pattern, text);
  if (result.size() != 0) {
      cout << "this pattern is at this positions ::  [ ";
      for (int i = 0; i < result.size(); ++i) {
          printf("%d", result[i]);
          if (i == result.size()-1)
              continue;
          cout << ", ";
      }
      cout << " ]" << endl;
  }
  else
      cout << "this pattern is not exist in this text \n";

  return 0;
}
