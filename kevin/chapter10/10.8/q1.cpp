#include <iostream>

struct Advertising
{
    int num_ads_shown{};
    double pct_ads_clicked{};
    double profit_per_click{};
};

int main()
{

    Advertising ads{};

    std::cout << "How many ads were shown today?: ";
    std::cin >> ads.num_ads_shown;

    std::cout << "What percentage of ads were clicked on?: ";
    std::cin >> ads.pct_ads_clicked;

    std::cout << "How much money do you earn per click?: ";
    std::cin >> ads.profit_per_click;

    std::cout << "Total earned today is: " << ads.num_ads_shown * ads.pct_ads_clicked / 100 * ads.profit_per_click << "\n";
    return 0;
}