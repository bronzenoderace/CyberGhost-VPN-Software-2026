#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <iomanip>

class Order {
public:
    Order(const std::string& customer, double amount)
        : customer(customer), amount(amount) {}

    const std::string& getCustomer() const {
        return customer;
    }

    double getAmount() const {
        return amount;
    }

private:
    std::string customer;
    double amount;
};

class OrderManager {
public:
    void addOrder(const std::string& customer, double amount) {
        orders.emplace_back(customer, amount);
    }

    double totalRevenue() const {
        double total = 0.0;
        for (const auto& order : orders) {
            total += order.getAmount();
        }
        return total;
    }

    void printReport() const {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Order Report\n";
        std::cout << "============\n";

        for (const auto& order : orders) {
            std::cout << order.getCustomer()
                      << " | $"
                      << order.getAmount()
                      << std::endl;
        }

        std::cout << "============\n";
        std::cout << "Total Revenue: $" << totalRevenue() << std::endl;
    }

private:
    std::vector<Order> orders;
};

int main() {
    OrderManager manager;

    manager.addOrder("Alice", 149.90);
    manager.addOrder("Brian", 89.50);
    manager.addOrder("Clara", 215.75);
    manager.addOrder("David", 64.20);

    manager.printReport();

    return 0;
}
