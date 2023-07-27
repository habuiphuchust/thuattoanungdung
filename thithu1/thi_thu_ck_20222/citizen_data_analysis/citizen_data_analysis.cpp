#include <bits/stdc++.h>

using namespace std;

int num_people = 0;
map<string, int> num_people_born_at;  // <date>
map<string, vector<string>> parent;   // <code>
map<string, int> most_alive_ancestor;
vector<string> pCode;
set<string> date;
map<string, int> sum_date;
int iMem[100000];

vector<string> dp;

bool check(int u) {
    for (string d : dp) {
        for (string p : parent[d]) {
            if (pCode[u] == p) return false;
        }

        for (string p : parent[pCode[u]]) {
            if (d == p) return false;
        }
    }
    return true;
}

int max_unrelated_people(int u) {
    if (u == pCode.size()) return 0;

    if (iMem[u] != -1) return iMem[u];
    int res = 0;
    if (check(u)) {
        dp.push_back(pCode[u]);
        res = max(res, 1 + max_unrelated_people(u + 1));
        dp.pop_back();
    }

    res = max(res, max_unrelated_people(u + 1));

    return iMem[u] = res;
}

int main() {
    freopen("test.inp", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(iMem, -1, sizeof(iMem));

    string code, birthday, father, mother, alive, region;

    while (1) {
        cin >> code;
        if (code == "*") break;
        cin >> birthday;
        cin >> father;
        cin >> mother;
        cin >> alive;
        cin >> region;
        num_people++;
        if (father != "0000000") {
            parent[code].push_back(father);
            most_alive_ancestor[code] =
                max(most_alive_ancestor[father] + 1, most_alive_ancestor[code]);
        }
        if (mother != "0000000") {
            most_alive_ancestor[code] =
                max(most_alive_ancestor[mother] + 1, most_alive_ancestor[code]);
            parent[code].push_back(mother);
        }
        num_people_born_at[birthday]++;
        date.insert(birthday);
        pCode.push_back(code);
    }

    int tmp = 0;
    for (auto dat : date) {
        sum_date[dat] = tmp + num_people_born_at[dat];
        tmp = sum_date[dat];
    }

    string syntax;

    while (1) {
        cin >> syntax;
        if (syntax == "***") break;
        if (syntax == "NUMBER_PEOPLE")
            cout << num_people << endl;
        else if (syntax == "NUMBER_PEOPLE_BORN_AT") {
            cin >> birthday;
            cout << num_people_born_at[birthday] << endl;
        } else if (syntax == "MOST_ALIVE_ANCESTOR") {
            cin >> code;
            cout << most_alive_ancestor[code] << endl;
        } else if (syntax == "NUMBER_PEOPLE_BORN_BETWEEN") {
            static string datemin, datemax;
            cin >> datemin;
            cin >> datemax;
            int sum = 0;
            // for (auto dat : date) {
            //     if (dat >= datemin && dat <= datemax) {
            //         sum += num_people_born_at[dat];
            //     }
            // }
            if (!(datemin > *date.rbegin() || datemax < *date.begin())) {
                auto itmin = upper_bound(date.begin(), date.end(), datemin);
                auto itmax = lower_bound(date.begin(), date.end(), datemax);
                string first_greater, last_smaller;
                if (itmin == date.end())
                    first_greater = *date.begin();
                else
                    first_greater = *itmin;
                if (itmax == date.end())
                    last_smaller = *date.rbegin();
                else
                    last_smaller = *prev(itmax);

                sum = sum_date[last_smaller] - sum_date[first_greater] +
                      num_people_born_at[first_greater];
            }

            cout << sum << endl;
        } else if (syntax == "MAX_UNRELATED_PEOPLE") {
            cout << max_unrelated_people(0) << endl;
        }
    }

    return 0;
}