#include <bits/stdc++.h>
using namespace std;
class IHash {
protected:
    string password;
    string salt;

public:
    IHash() {}
    virtual string hashPassword() = 0;
    virtual ~IHash() = default;

    void setPassword(const string& pwd) {
        password = pwd;
    }

    void setSalt(const string& s) {
        salt = s;
    }
};

// FNV-1a hash implementation
class Hasher : public IHash {
private:
    uint32_t fnv1aHash(const string& input) {
        const uint32_t FNV_PRIME = 0x01000193; // 16777619
        const uint32_t FNV_OFFSET_BASIS = 0x811C9DC5; // 2166136261

        uint32_t hash = FNV_OFFSET_BASIS;
        for (char c : input) {
            hash ^= static_cast<uint8_t>(c);
            hash *= FNV_PRIME;
        }
        return hash;
    }

public:
    string hashPassword() override {
        string combined = salt + password; // Simple salting
        uint32_t hashVal = fnv1aHash(combined);

        // Convert hash to hex string
        stringstream ss;
        ss << hex << setw(8) << setfill('0') << hashVal;
        return ss.str();
    }
};

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
        Hasher hasher1;
        hasher1.setSalt("melt");
        hasher1.setPassword(string1);
        getline(ss,string2, ',');
        Hasher hasher2;
        hasher2.setSalt("melt");
        hasher2.setPassword(string2);
        cout<<hasher2.hashPassword()<<endl;
        bool ok=(hasher1.hashPassword()==hasher2.hashPassword());
        cout<<ok<<'\t'<<string1<<'\t'<<string2<<endl;
    }

    return 0;
}
