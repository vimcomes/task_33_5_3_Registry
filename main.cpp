#include <iostream>
#include <vector>

template<typename T1, typename T2>
class Registry {
private:
    std::vector<std::pair<T1, T2>> vec;
public:
    void add (T1& inKey, T2& inValue) {
        std::pair<T1, T2> pair(inKey, inValue);
        vec.push_back(pair);
    }
    void remove (T1& inKey) {
        for (auto it = vec.begin();it != vec.end();++it) {
            if (it->first == inKey) {
                vec.erase(it);
                return;
            }
        }
        std::cout << "There is no such element" << std::endl;
    }
    void print () const {
        if (vec.empty()) {
            std::cout << "The container is empty" << std::endl;
            return;
        }
        for (int i = 0;i < vec.size();++i) {
            std::cout << vec[i].first << "  " << vec[i].second << std::endl;
        }
    }
    void find(T1& inKey) const {
        std::vector<T2> values;
        for (auto it = vec.begin();it != vec.end();++it) {
            if (it->first == inKey) {
                values.push_back(it->second);
            }
        }
        if (values.empty()) {
            std::cout << "Not found" << std::endl;
            return;
        }
        for (int i = 0;i < values.size();++i) {
            std::cout << values[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Registry<int, std::string> reg;
    for (int i = 0;i<4;++i) {
        int key;
        std::string value;
        std::cout << "Enter the key: ";
        std::cin >> key;
        std::cout << "Enter the value: ";
        std::cin >> value;
        reg.add(key, value);
    }
    reg.print();
    std::cout << std::endl;
    int ind = 1;
    reg.find(ind);
    std::cout << std::endl;
    reg.remove(ind);
    reg.print();
    return 0;
}