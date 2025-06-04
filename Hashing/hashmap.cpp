#include <iostream>
#include <vector>
#include <list>
using namespace std;

template<typename Key, typename Value>
class HashMap {
    static const int DEFAULT_SIZE = 10007;
    vector<list<pair<Key, Value>>> table;
    int size;

    int hashFunction(const Key& key) const {
        return hash<Key>()(key) % size;
    }

public:
    HashMap(int s = DEFAULT_SIZE) : size(s), table(s) {}

    void insert(const Key& key, const Value& value) {
        int index = hashFunction(key);
        for (auto& kv : table[index]) {
            if (kv.first == key) {
                kv.second = value;
                return;
            }
        }
        table[index].emplace_back(key, value);
    }

    bool get(const Key& key, Value& value) const {
        int index = hashFunction(key);
        for (const auto& kv : table[index]) {
            if (kv.first == key) {
                value = kv.second;
                return true;
            }
        }
        return false;
    }

    bool erase(const Key& key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                return true;
            }
        }
        return false;
    }
};

int main() {
    HashMap<string, int> mp;
    int choice;
    string key;
    int value;

    while (true) {
        cout << "\n1. Insert\n2. Get\n3. Delete\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key (string): ";
                cin >> key;
                cout << "Enter value (int): ";
                cin >> value;
                mp.insert(key, value);
                cout << "Inserted successfully!\n";
                break;

            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                if (mp.get(key, value)) {
                    cout << "Value = " << value << "\n";
                } else {
                    cout << "Key not found!\n";
                }
                break;

            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                if (mp.erase(key)) {
                    cout << "Deleted successfully.\n";
                } else {
                    cout << "Key not found!\n";
                }
                break;

            case 4:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice.\n";
        }
    }
}
