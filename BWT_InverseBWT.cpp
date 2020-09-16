#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include<map>
#include<queue>
using namespace std;
/*
* Author: mahmoud youssef
* Respect Coursera Honor Code
* Copyright © 2019. All rights reserved
*/

//we can encrybit and decribit strings by this  
//encrybit
string BWT(const string& text) {
  string result = "";
  int n = text.size();
  vector<string>matrix;

  queue<char> q;
  for (int i = n-1; i >=0; i--) { // aag$ -> $gaa
      q.push(text[i]);
  }

  matrix.push_back(text);
  for (int i = 0; i < n-1; i++) {
      string row = q.front() + matrix.back().substr(0, n - 1);
      matrix.push_back(row);
      q.pop();
  }

  //sort the cycled matrix
  sort(matrix.begin(), matrix.end());
  //get last col
  for (int i = 0; i < n; i++) {
      result += matrix[i][n-1];
  }
  return result;
}

//decribit
string InverseBWT(const string& bwt) {
    string text = "";
    int n = bwt.size();
    vector<pair<char, int>>first;
    for (int i = 0; i < n; i++) {
        first.push_back(make_pair(bwt[i], i));
    }

    sort(first.begin(), first.end());
    
    pair<char, int> pair = first[0];
    for (int i = 0; i < n; i++) {
        pair = first[pair.second];
        text += pair.first;
    }
    return text;
}

void security(string text) {
    if (text[text.size() - 1] != '$')
        text += '$';
    string encrybited = BWT(text);
    string decribited = InverseBWT(encrybited).substr(0, text.size() - 1);

    cout << "(encrybited) BWT= " << encrybited << endl << "(decribited) INVERSE BWT= " << decribited << endl;
}

int main() {
    //input GAGAGA$
    //output AGGGAA$
  string text;
  cin >> text;
  security(text);
  return 0;
}


