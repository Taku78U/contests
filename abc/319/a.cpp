#include <bits/stdc++.h>

using namespace std;

vector<pair<string, int>> V;

string S;

void InitV()
{
    V.emplace_back("tourist", 3858);
    V.emplace_back("ksun48", 3679);
    V.emplace_back("Benq", 3658);
    V.emplace_back("Um_nik", 3648);
    V.emplace_back("apiad", 3638);
    V.emplace_back("Stonefeang", 3630);
    V.emplace_back("ecnerwala", 3613);
    V.emplace_back("mnbvmar", 3555);
    V.emplace_back("newbiedmy", 3516);
    V.emplace_back("semiexp", 3481);
}

int main()
{
    InitV();
    cin >> S;
    cin.ignore();

    for (const auto& elm : V)
    {
        if (S == elm.first)
        {
            cout << elm.second << endl;
            return 0;
        }
    }
    return 0;
}