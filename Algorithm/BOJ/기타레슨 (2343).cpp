#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
int Ns, Ms;
int ls = 1, rs = 0;
int  mids = 0, anss = 0;
vector<int> as;



void n2343() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> Ns >> Ms;
    for (int i = 0; i < Ns;i++) {
        int ss;
        cin >> ss;
        as.push_back(ss);
        rs += ss;
    }

    while (ls <= rs) {
        mids = (ls + rs) / 2;
        int cnt = 1;
        int sum = 0;

        for (int i = 0; i < Ns;i++) {
            if (as[i] > mids) {
                cnt = Ms + 1;
                break;
            }
            sum += as[i];
            if (sum > mids) {
                sum = as[i];
                cnt++;
            }
        }

        if (Ms >= cnt) {
            anss = mids;
            rs = mids - 1;
        }
        else {

            ls = mids + 1;
        }


    }
    cout << anss;
}
