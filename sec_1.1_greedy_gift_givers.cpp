/*
ID: igor6
LANG: C++
TASK: gift1
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

static string taskname = "gift1";
static string filein = taskname + ".in";
static string fileout = taskname + ".out";

int process()
{
    ofstream fout(fileout.c_str());
    ifstream fin(filein.c_str());

    vector<string> friends;
    map<string, int> givers;
    map<string, int> receivers;

    int np = 0;
    fin >> np;

    for (int i = 0; i < np; ++i)
    {
        string f;
        fin >> f;
        friends.push_back(f);
    }

    for (int i = 0; i < np; ++i)
    {
        string f;
        fin >> f;

        int k1, k2;
        fin >> k1 >> k2;

        givers[f] = k1;

        if (!k2) continue;

        int money = k1 / k2;

        for (int j = 0; j < k2; ++j)
        {
            string s;
            fin >> s;
            receivers[s] += money;
        }

        receivers[f] += k1 % k2;
    }


    for (int i = 0; i < friends.size(); ++i)
    {
        string f = friends[i];
        fout << f << " " << (receivers[f] - givers[f]) << endl;
    }



}

int main()
{
    process();
    return 0;
}
