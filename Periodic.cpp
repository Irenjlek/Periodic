#include <string>
#include <iostream>

int CountRepeat(const std::string& rapport, const std::string& txt)
{
    int i = 0;
    int j = 0;
    int count = 0;
    while (i < txt.size()) {
        if (rapport[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == rapport.size()) {
            count++;
            j = 0;
        }
        else if (i < txt.size() && rapport[j] != txt[i]) {
            break;
        }
    }
    return count;
}

bool IsKPeriodic(const std::string& str, int period) {
    if (period <= 0 || str.size() % period != 0)
        return false;

    std::string rapport = std::string(str, 0, period);
    int count = CountRepeat(rapport, str);

	return str.size() / period == count;
}

int main() {
	std::string string("asdasdasdasd");
	int k = 3;
	std::cout << IsKPeriodic(string, k) << std::endl; // true

	k = 4;
	std::cout << IsKPeriodic(string, k) << std::endl; // false

	string = "werwertyu";
	k = 3;
	std::cout << IsKPeriodic(string, k) << std::endl; // false

    string = "weasdasdasdasd";
    k = 3;
    std::cout << IsKPeriodic(string, k) << std::endl; // false

    string = "weasdasdasdasdweasdasdasdasdweasdasdasdasd";
    k = 14;
    std::cout << IsKPeriodic(string, k) << std::endl; // true

    string = "werwertyu";
    k = -8;
    std::cout << IsKPeriodic(string, k) << std::endl; // false

    string = "werwertyu";
    k = 0;
    std::cout << IsKPeriodic(string, k) << std::endl; // false

    return 0;
}