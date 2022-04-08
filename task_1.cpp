//var - 2
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

typedef pair <string , int> pair_;

multimap <string, int> day;
multimap <string, int> number;

string& to_low (string& data) {
    transform(data.begin(), data.end(), data.begin(),
        [](unsigned char c){ return std::tolower(c); });
    return data;
}

vector<string> split(string & s) {
    vector<string> res; 
    string cur = "";

    for(int i = 0; i < s.size(); i++) {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            cur.push_back(s[i]);
        }
        else {
            if(cur.size()) {
                res.push_back(to_low(cur));
            }
            res.push_back(s.substr(i, 1));
            cur = "";
        }
    }
    if(cur.size()) {
        res.push_back(to_low(cur));
    }
    return res;
}

void convert(string& s) {
    vector<string> data = split(s);
    string res = "";
    for(int i = 0; i < data.size(); i++) {
        auto it = day.find(data[i]);
        if(it != day.end()) {
            res += to_string(it->second);
        }
        else {
            auto it = number.find(data[i]);
            if(it != number.end()) {
                if(it->first == "one") {
                    if(i+2 < data.size()) {
                        auto it_1 = number.find(data[i+2]);
                        if(it_1 != number.end()) {
                            if(it_1->first == "hundred") {
                                res += to_string(100);
                                i+= 2;
                            }
                            else {
                                res += to_string(1);
                            }
                        }
                    }
                    else {
                        res += to_string(1);
                    }
                }
                else {
                    if(it->first == "zero" || it->first == "two" || it->first == "three" || it->first == "four" || it->first == "five" 
                        || it->first == "six" || it->first == "seven" || it->first == "eight" || it->first == "nine" || it->first == "ten"
                        || it->first == "eleven" || it->first == "twelve" || it->first == "thirteen" || it->first == "fourteen" 
                        || it->first == "fifteen" || it->first == "sixteen" || it->first == "seventeen" || it->first == "eighteen" 
                        || it->first == "nineteen") {
                            res += to_string(it->second);
                    }
                    else {
                        if(i+2 < data.size()) {
                        auto it_1 = number.find(data[i+2]);
                        if(it_1 != number.end()) {
                            res += (to_string(it->second + it_1->second));
                            i+= 2;
                        }
                    }
                    }
                }
            } 
            else {
                res += data[i];
            }   
        }
    }
    s = res;
}

void fill_maps() {
    day.insert(pair_("sunday", 0));
    day.insert(pair_("monday", 1));
    day.insert(pair_("tuesday", 2));
    day.insert(pair_("wednesday", 3));
    day.insert(pair_("thursday", 4));
    day.insert(pair_("friday", 5));
    day.insert(pair_("saturday", 6));

    number.insert(pair_("zero", 0));
    number.insert(pair_("one", 1));
    number.insert(pair_("two", 2));
    number.insert(pair_("three", 3));
    number.insert(pair_("four", 4));
    number.insert(pair_("five", 5));
    number.insert(pair_("six", 6));
    number.insert(pair_("seven", 7));
    number.insert(pair_("eight", 8));
    number.insert(pair_("nine", 9));
    number.insert(pair_("ten", 10));
    number.insert(pair_("eleven", 11));
    number.insert(pair_("twelve", 12));
    number.insert(pair_("thirteen", 13));
    number.insert(pair_("fourteen", 14));
    number.insert(pair_("fifteen", 15));
    number.insert(pair_("sixteen", 16));
    number.insert(pair_("seventeen", 17));
    number.insert(pair_("eighteen", 18));
    number.insert(pair_("nineteen", 19));
    number.insert(pair_("twenty", 20));
    number.insert(pair_("thirty", 30));
    number.insert(pair_("forty", 40));
    number.insert(pair_("fifty", 50));
    number.insert(pair_("sixty", 60));
    number.insert(pair_("seventy", 70));
    number.insert(pair_("eighty", 80));
    number.insert(pair_("ninety", 90));
    number.insert(pair_("hundred", 100));
}

int main() {

    fill_maps();
    string s = "Monday: fifteen dollars";
    cout << s << endl;
    convert(s);
    cout << s << endl;
    
    s = "kuyg MoNday;; twenty one one one hundred sixteen; -_-";
    cout << s << endl;
    convert(s);
    cout << s << endl;

}