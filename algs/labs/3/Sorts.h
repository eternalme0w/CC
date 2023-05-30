#pragma once
#include <iostream>
#include <vector>



struct Sorts {

    std::vector<int> mass;
    std::vector<int> initial_mass;
    int n;

    Sorts(const std::vector<int> &a);
    void reset();
    std::vector<int> simple_buble_sort();
    std::vector<int> buble_sort();
    std::vector<int> select_sort();
    std::vector<int> shaker_sort();
    std::vector<int> insert_sort();
    std::vector<int> insert_sort_with_barrier();

    void merge(const std::vector<int> &a, const std::vector<int> &b, std::vector<int> &c);
    void merge_sort(std::vector<int> &a);
    void quick_sort(int first, int last);

    void problem_1(int m);
    void problem_2();


    void out(int i1 = -1, int i2 = -1);

};
