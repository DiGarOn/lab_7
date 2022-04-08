//var - 2
#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

float sr (list<int> mas) {
    float res = 0;
    int sum = 0;
    int count = 0;
    for(int i : mas) {
        sum += i;
        count++;
    }
    if(count >= 6) return -100000000;
    return (sum*1.0)/mas.size();
}

void convert(vector<list<int> >& vec, vector<int>& res) {
    res.clear();
    multimap<float, list<int>, less<int> > mymap;
    for(int i = 0; i < vec.size(); i++) {
        float s = sr(vec[i]);
        if(s != -100000000) mymap.insert(make_pair(s, vec[i]));
    }

    for(auto i = mymap.begin(); i != mymap.end(); i++) {
        i->second.sort();
        i->second.reverse();
        for(auto j = i->second.begin(); j != i->second.end(); j++) {
            //cout << *j << endl;
            res.push_back(*j);
        }
    }

}

int main() {

    vector<list<int> > vec ={{9,22,10,2,6,3,9,1}, {4,6}, {8,10}};
    vector<int> res;

    convert(vec, res);

    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}