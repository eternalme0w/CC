#include "Statistic.h"

const int Statistic::operator[](const size_t ind) const {

	if (ind < 0 || ind > sales.size() - 1)
		throw std::exception();
	else 
		return sales[ind];
}

int& Statistic::operator[](const size_t ind) {

	if (ind < 0 || ind > sales.size() - 1)
		throw std::exception();
	else
		return sales[ind];
}

Statistic::Statistic(const std::vector<int>& a): sales(a) {}

Statistic::Statistic(int const *a, size_t const &n) {

	sales.insert(sales.begin(), a, a + n);
}

Statistic::Statistic(Statistic const &statistic) {

	sales = statistic.sales;
}

Statistic& Statistic::operator=(const Statistic& statistic)  {

	sales = statistic.sales;
	return *this;
}

Statistic::Statistic(const std::string &str) {

	static const std::regex rdelim{" "};
	std::vector<std::string> words{
		std::sregex_token_iterator(str.begin(), str.end(), rdelim, -1),
		std::sregex_token_iterator()
	};

	for (const auto &x : words) {
		
		sales.push_back(stoi(x));
	}
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

		if (sales[i] == max) max_sales.push_back(i);
	}

	return max_sales;
}

std::vector<int> Statistic::min_sales() const {

	int min = *std::min_element(sales.begin(), sales.end());
	std::vector<int> min_sales;

	for (int i = 0; i < sales.size(); ++i) {

		if (sales[i] == min) min_sales.push_back(i);
	}

	return min_sales;
}

void Statistic::out() {

	std::cout << "\n\n";

	std::cout << "data set: ";

	for (int x : sales)
	{

		std::cout << x << " ";
	}

	std::cout << "\n\n";
}