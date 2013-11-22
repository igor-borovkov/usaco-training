/*
ID: igor6
LANG: C++
TASK: ride
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

static string taskname = "ride";
static string filein = taskname + ".in";
static string fileout = taskname + ".out";

int group_number(string s)
{
    int num = 1;
    for (int i = 0; i < s.length(); ++i)
    {
        num *= (s[i] - 'A' + 1);
    }

    return num % 47;
}

void process()
{
    ofstream fout(fileout.c_str());
    ifstream fin(filein.c_str());

    string s1, s2;
    fin >> s1 >> s2;

    if (group_number(s1) == group_number(s2))
        fout << "GO" << endl;
    else
        fout << "STAY" << endl;
}

int main()
{
    process();
    return 0;
}
