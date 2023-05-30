#include "Sorts.h"
#include <time.h>

Sorts::Sorts(const std::vector<int> &a) {

    mass = a;
    initial_mass = a;
    n = a.size();
}

void Sorts::reset() {

    mass = initial_mass;
}

std::vector<int> Sorts::select_sort() {

    int min_index, tmp, cmps = 0, swps = 0, other_cmps = 0;
    std::vector<int> ans;

    for (int i = 0; i < n - 1; i++) {

        min_index = i;

        for (int j = i + 1; j < n; j++) {

            cmps++;

            if (mass[j] < mass[i]) {

                min_index = j;
            }
        }

        other_cmps++;

        if (min_index != i) {

            swps++;
            
            tmp = mass[i];
            mass[i] = mass[min_index];
            mass[min_index] = tmp;
        }

    }

    ans.push_back(cmps);
    ans.push_back(swps);
    ans.push_back(other_cmps);

    return ans;
    
}

std::vector<int> Sorts::simple_buble_sort() {

    int tmp, cmps = 0, swps = 0, other_cmps = 0;
    std::vector<int> ans;

    for (int k = 1; k <= n - 1; k++) {

        for (int i = 0; i < n - k; i++) {

            //std::cout << i << ") " << mass[i] << " / " << mass[i + 1] << "\n\n";
            cmps++;

            if (mass[i] > mass[i+1]) {

                swps++;

                tmp = mass[i];
                mass[i] = mass[i+1];
                mass[i+1] = tmp;
            }

        }
    }

    ans.push_back(cmps);
    ans.push_back(swps);
    ans.push_back(other_cmps);

    return ans;
   
}

std::vector<int> Sorts::buble_sort() {

    int tmp, cmps = 0, swps = 0, other_cmps = 0, last = n, swap_index;
    bool f;
    std::vector<int> ans;

    for (int k = 1; k <= n - 1; k++) {

        f = true;

        for (int i = 0; i < n - k; i++) {

            if (i >= last) {

                other_cmps++;
                break;
            };

            cmps++;

            //out(i, i + 1);

            if (mass[i] > mass[i+1]) {

                swps++;
                swap_index = i;

                f = false;
                tmp = mass[i];
                mass[i] = mass[i+1];
                mass[i+1] = tmp;
            }
        }

        last = swap_index;
        //std::cout << "  end  last swap at " << last;
        if (f) break;
    
    }

    ans.push_back(cmps);
    ans.push_back(swps);
    ans.push_back(other_cmps);

    return ans;


}

std::vector<int> Sorts::shaker_sort() {

    int cmps = 0, swps = 0, other_cmps = 0;
    std::vector<int> ans;

    int left = 0, right = n - 1, last_swap;

    while(left < right) {

        other_cmps++;

        last_swap = 0;

        for (int i = left; i < right; i++) {

            cmps++;

            if (mass[i] > mass[i+1]) {

                swps++;
                
                std::swap(mass[i], mass[i+1]);
                last_swap = i;
            }
        }

        right = last_swap;

        for (int i = right; i > left; i--) {

            cmps++;

            if (mass[i] < mass[i-1]) {

                swps++;
                
                std::swap(mass[i], mass[i-1]);
                last_swap = i;
            }
        }

        left = last_swap;
    }
    
    

    ans.push_back(cmps);
    ans.push_back(swps);
    ans.push_back(other_cmps);

    return ans;


}

std::vector<int> Sorts::insert_sort() {

    int cmps = 0, swps = 0, other_cmps = 0;
    std::vector<int> ans;

    int k;

    for (int i = 1; i < n; i++) {

        k = i;
        cmps++;

        while( k > 0 && mass[k] < mass[k - 1]) {

            swps++;
            std::swap(mass[k], mass[k - 1]);
            k--;
        }
    }


    ans.push_back(cmps);
    ans.push_back(swps);
    ans.push_back(other_cmps);

    return ans;
}

std::vector<int> Sorts::insert_sort_with_barrier() {

    int cmps = 0, swps = 0, other_cmps = 0;
    std::vector<int> ans;

    int k;

    mass.insert(mass.begin(), -1);

    for (int i = 2; i <= n; i++) {

        k = i;
        cmps++;

        while(mass[k] < mass[k - 1]) {

            swps++;
            std::swap(mass[k], mass[k - 1]);
            k--;
        }
    }

    mass.erase(mass.begin());

    ans.push_back(cmps);
    ans.push_back(swps);
    ans.push_back(other_cmps);

    return ans;

}

void Sorts::merge(const std::vector<int> &a, const std::vector<int> &b, std::vector<int> &c) {    

    int i = 0, j = 0, n = 0;

    while (i < a.size() && j < b.size()) {

        if (a[i] <= b[j]) c[n++] = a[i++];
        else c[n++] = b[j++];
    }

    while (i < a.size()) 
        c[n++] = a[i++];

    while (j < b.size()) 
        c[n++] = b[j++];

}

void Sorts::merge_sort(std::vector<int> &a) {

    int cmps = 0, swps = 0, other_cmps = 0;
    std::vector<int> ans;

    int n = a.size();
    if (n <= 1) return;
    int middle = n / 2;

    std::vector<int> left(a.begin(), a.begin() + middle);
    std::vector<int> right(a.begin() + middle, a.end());

    merge_sort(left);
    merge_sort(right);

    merge(left, right, a);
    

    ans.push_back(cmps);
    ans.push_back(swps);
    ans.push_back(other_cmps);

    //return ans;
}

void Sorts::quick_sort(int first, int last) {

    int i = first, j = last;
    int x = mass[(first + last) / 2];

    while (i <= j) {

        while(mass[i] < x) i++;
        while(mass[j] > x) j--;

        if (i <= j) std::swap(mass[i++], mass[j--]);
    }

    if (first < j) quick_sort(first, j);
    if ( i < last) quick_sort(i, last);

}
    
void Sorts::out(int i1, int i2) {

    std::cout << "\n\n"; 

    for (int i = 0; i < mass.size(); i++) {

        if (i == i1 || i == i2) {

            std:: cout << "|" << mass[i] << "| ";

        } else {

            std::cout << mass[i] << " ";
        }
    }

    std::cout << "\n\n";
}

void Sorts::problem_1(int m) {

    std::vector<int> proto;
    proto.resize(mass.size() + 1);

    for(int i = 0; i < mass.size(); ++proto[mass[i++]]);    

    mass.clear();

    for(int i = 0; i < proto.size(); i++) {

        for (int j = 0; j < proto[i]; j++) mass.push_back(i);
    }

}

void Sorts::problem_2() {

    std::vector<int> tmp;

    for (int x : mass) 
        if (x % 2 == 0) tmp.push_back(x);
    
    for (int x : mass) 
        if (x % 2 != 0) tmp.push_back(x);
    
    mass = tmp;
}


