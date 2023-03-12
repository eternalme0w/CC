#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <regex>

class Statistic {

    
public:

    std::vector<int> sales;
    Statistic& operator=(const Statistic& statistic);

    const int operator[](const size_t) const;
    int &operator[](const size_t ind);

    Statistic(const std::vector<int>& a);
    Statistic(int const *a, const size_t &n);
    Statistic(Statistic const &statistic);
    Statistic(const std::string &str);

    long long sum_sales() const;
    int average_sales() const;
    std::vector<int> max_sales() const;
    std::vector<int> min_sales() const;
    int months_sales_below_average() const;
    int months_sales_above_average() const;


};