#ifndef UTILS_HPP
#define UTILS_HPP


#include <vector>
#include <string>
#include <regex>


namespace utils {


    std::vector<std::string> stringSplit(const std::string& string, const std::string& delimiter);

    void stringStrip(std::string& string, const std::string& strip);

    std::vector<std::string> applyRegex(const std::string& string, const std::regex& re);

    template <std::integral integral>
    std::vector<integral> getDivisors(integral number);

    template<std::integral integral>
    integral sumVector(std::vector<integral> list);

    std::vector<long long> findPrimesAmount(unsigned long long amount);

    std::vector<long long> findPrimes(unsigned long long limit);

    template<std::integral integral>
    bool isPrime(integral);

    template<std::integral integral>
    std::vector<integral> numToDigits(integral number);

    template<std::integral integral>
    integral digitsToNum(std::vector<integral> digits);

    template<std::integral integral>
    integral factorial(integral number);

    template<std::integral integral>
    std::string decimalToBinary(integral number);

    template<std::integral integral>
    bool isPalindrome(integral number);

    bool isPalindrome(const std::string& str);

    std::vector<std::string> readFileLines(const std::string& pathName);

    std::string readFile(const std::string& pathName);


}



#include "utils.tpp"


#endif //UTILS_HPP
