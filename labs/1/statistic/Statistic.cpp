#include "Statistic.h"
#include <vector>
#include <algorithm>


Statistic::Statistic(const std::vector<int>& a): sales(a) {}

Statistic::Statistic(int const *a, size_t const &n) {

	sales.insert(sales.begin(), a, a + n);
}

Statistic::Statistic(Statistic const &statistic) {

	sales = statistic.sales;
}

Statistic &operator=(Statistic const &statistic) {

	sales = statistic.sales;
	return *this;
}

Statistic(std::string const &str) {

	size_t i = 0;
	while(str[i] != '\0') 
		sales.push_back(static_cast<int>(str[i++]));
}

long long Statistic::sum_sales() const {

	long long sum = 0;

	for (int i = 0; i < sales.size(); ++i) sum += sales[i];

	return sum;
}

int Statistic::average_sales() const {

	return static_cast<double>(sum_sales()) / sales.size(); 
}

int Statistic::months_sales_below_average() const {

	int cnt = 0;
	int avg = average_sales();

	for (int i = 0; i < sales.size(); ++i) {

		if (sales[i] < avg) cnt++;
	}

	return cnt;
}

int Statistic::months_sales_above_average() const {

	int cnt = 0;
	int avg = average_sales();

	for (int i = 0; i < sales.size(); ++i) {

		if (sales[i] > avg) cnt++;
	}

	return cnt;
}

std::vector<int> Statistic::max_sales() const {

	int max = *std::max_element(sales.begin(), sales.end());
	std::vector<int> max_sales;

	for (int i = 0; i < sales.size(); ++i) {

		if (sales[i] == max) max_sales.push_back(i + 1);
	}

	return max_sales;
}

std::vector<int> Statistic::min_sales() const {

	int min = *std::min_element(sales.begin(), sales.end());
	std::vector<int> min_sales;

	for (int i = 0; i < sales.size(); ++i) {

		if (sales[i] == min) min_sales.push_back(i+1);
	}

	return min_sales;
}