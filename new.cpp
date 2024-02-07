#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution
{
public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {

        unordered_map<char, list<pair<char, long long>>> mp;
        int size = changed.size();
        for (int i = 0; i < size; i++)
        {
            mp[original[i]].push_back({changed[i], cost[i]});
        }
        // for(auto x: mp){
        //     // list<pair<char,int>> p=x.second;
        //     cout<<x.first<<" : ";
        //     for(auto i:x.second ){
        //         cout<<i.first<<"  "<<i.second<<"    ,  ";
        //     }
        //     cout<<endl;
        // }
        long long c = 0;
        long long xx = INT_MAX;
        for (int i = 0; i < source.size(); i++)
        {
            // cout<<source[i]<<" "<<target[i]<<endl;
            if (source[i] == target[i])
            {
            }
            else
            {
                long long mini = LLONG_MAX;
                list<pair<char, long long>> p = mp[source[i]];
                for (auto x : p)
                {
                    if (x.first == target[i])
                    {
                        mini = x.second < mini ? x.second : mini;
                        cout << x.first << " : " << x.second << endl;
                    }
                    else
                    {
                        xx = x.second;
                        list<pair<char, long long>> z = mp[x.first];
                        for (auto ii : z)
                        {
                            if (ii.first == target[i])
                            {
                                xx += ii.second;
                                // break;
                            }
                            mini = mini < xx ? mini : xx;
                        }
                        // mini=mini<xx?mini:xx;
                    }
                    // mini=mini<xx?mini:xx;
                }
                //   cout<<mini<<" "<<endl;
                c += mini;
            }
        }
        if (c == INT_MAX)
        {
            return -1;
        }
        cout << endl;
        return c;
    }
};

int main()
{
    Solution yourObject;

    // Example usage:
    string source = "aaaabadaaa";
    string target = "dbdadddbad";
    vector<char> original = {'c', 'a', 'c', 'a', 'a', 'b', 'b', 'b', 'd', 'd', 'c'};
    vector<char> changed = {'a', 'c', 'b', 'd', 'b', 'c', 'a', 'd', 'c', 'b', 'd'};
    vector<int> cost = {7, 8, 11, 9, 7, 6, 4, 6, 9, 5, 9};

    long long result = yourObject.minimumCost(source, target, original, changed, cost);

    cout << "Minimum Cost: " << result << endl;

    return 0;
}
