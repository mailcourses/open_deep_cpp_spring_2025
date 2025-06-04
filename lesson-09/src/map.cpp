#include <iostream>
#include <unordered_map>
#include <map>

int main()
{
    //std::unordered_map<std::string, size_t> frequencyDictionary;
    std::map<std::string, size_t> frequencyDictionary;
    std::string word;
    while (std::cin >> word)
    {
        auto it = frequencyDictionary.find(word);
        if (it == frequencyDictionary.end())
            frequencyDictionary[word] = 1;
        else
            ++it->second;
    }

    for (auto [key, value] : frequencyDictionary)
    {
        std::cout << "key=" << key << ", value=" << value << std::endl;
    }

    const std::map<std::string, std::vector<size_t>> m1;
    std::cout << m1.size() << std::endl;
    std::cout << m1.count("cat") << std::endl;
    std::cout << m1.contains("cat") << std::endl;
    //m1["cat"]; <-- operator[] он не константный
    m1.at("cat");
}
