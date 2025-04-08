#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream file("testcases1.txt");
    if (!file.is_open()){
        cerr << "Error while loading file" << endl;
        return 1;
    }
    string line;
    int testcases = 1;
    while (getline(file, line)) {
        stringstream ss(line);
        string string1,string2;
        string salt;

        getline(ss,string1, ',');
        getline(ss,string2, ',');
        bool ok=(string1==string2);\
        cout<<ok<<'\t'<<string1<<'\t'<<string2<<endl;
    }

    return 0;
}
