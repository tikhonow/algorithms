#include <vector>
#include <algorithm>
#include <iomanip>
#include <functional>

//класс в котором реализован медианный и пороговый фильтр
class filters
{
private:

	float min = 0.03;
	float max = 50.0;

public:
	filters() {}
	std::vector<float> update(std::vector<float> &scan);
	std::vector<float> median(std::vector<float> &data, int q);
	void  set_min (float number1) {
		min = number1;
    }
	void  set_max (float number2) {
		max = number2;
    }
	~filters() {}

};

//пороговый фильтр
std::vector<float> filters::update(std::vector<float> &scan)
{
	std::vector<float> updated_scan(scan.size(), 0);
	for (int i = 0; i < scan.size(); i++)
	{
		if (scan[i] < min)
			updated_scan[i] = min;
		else if (scan[i] > max)
			updated_scan[i] = max;
		else
			updated_scan[i] = scan[i];
	}

	return updated_scan;
}

//медианный фильр
std::vector<float> filters::median(std::vector<float> &data, int q)
{
	std::vector<float> updated_scan(data.size(), 0);
	for (int i = 0; i < data.size(); i++)
	{
		const auto median_it = data.begin() + data.size() / 2.0;
		nth_element(data.begin(), median_it, data.end());
		auto median = *median_it;

		if (data.size() % 2 == 0)
		{
			const auto median_it1 = data.begin() + data.size() / 2.0 - 1.0;
			const auto median_it2 = data.begin() + data.size() / 2.0;

			std::nth_element(data.begin(), median_it1, data.end());
			const auto e1 = *median_it1;

			std::nth_element(data.begin(), median_it2, data.end());
			const auto e2 = *median_it2;

			updated_scan[i] = (e1 + e2) / 2.0;
		}
		else
		{
			const auto median_it = data.begin() + data.size() / 2.0;
			std::nth_element(data.begin(), median_it, data.end());
			updated_scan[i] = *median_it;
		}
	}

	return updated_scan;
}

