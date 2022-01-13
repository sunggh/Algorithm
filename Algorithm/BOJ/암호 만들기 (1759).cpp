#include <iostream>
#include <algorithm>
#include<vector>
#include<math.h>
#include<map>
using namespace std;

int L1759, C1759;
int vowel1759 = 0;
char s1759[15];
bool vowels[15] = {};

bool isVowel(char s) {
    switch (s)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    }
    return false;
}

void dfs1759(string s, int num, int k) {
    int ks = 1;
    if (k == L1759) {
        int a = 0, b = 0;
        for (int j = 0; j < k;j++) {
            if (!isVowel(s[j])) {
                a++;
            }
            else
                b++;
        }
        if (a >= 2 && b >= 1)
            cout << s << "\n";
        return;
    }
    else {
        for (int i = num; i < C1759; i++) {
            if (!vowels[k] && isVowel(s1759[i])) {
                vowels[k] = true;
            }
            vowels[k + 1] = vowels[k];
            dfs1759(s + s1759[i], i + 1, k + 1);
            if (k != 0)
                vowels[k] = vowels[k - 1];
            else
                vowels[k] = false;

        }
    }
}



void n1759() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> L1759 >> C1759;
    for (int i = 0; i < C1759; i++) {
        cin >> s1759[i];
        if (isVowel(s1759[i])) vowel1759++;
    }
    sort(s1759, s1759 + C1759);
    dfs1759("", 0, 0);

}
