#include <iostream>
#include <iomanip>

// Assumptions - Constant values from brief known at compile time
constexpr double CONSUMPTION_PER_100MILES = 9.66;                   // Fuel consumption for 100 miles distance [liters]
constexpr double MILE_CONSUMPTION = CONSUMPTION_PER_100MILES / 100; // CONSUMPTION_PER_100MILES/100 miles = 0.0966/mile
constexpr double DIESEL_EMISSION = 2.68;                            // Diesel CO₂ emission/litre [kilogram] = 2.68 kg
constexpr double PETROL_EMISSION = 2.31;                            // Petrol CO₂ emission/litre [kilogram] = 2.31 kg

// Prompt user to enter travel distance in miles
// @return <double> - travel distance from user input
// @throw <invalid_argument> - non numeric value, distance <= 0
double getTravelDistance()
{
    double user_input = 0.00;

    std::cout << "Enter travel distance in miles: ";
    if (!(std::cin >> user_input))
        throw std::invalid_argument("Travel distance must be numeric value.");

    if (user_input <= 0)
        throw std::invalid_argument("Travel distance must be more than 0.");

    return user_input;
}

// Prompt user with question if fuel type is diselsel
// @return <bool> - true if user wants to calculates for diesel
// @throw <invalid_argument> - invalid input string / not y/n
bool isDiesel()
{
    char user_input = 'n';
    std::cout << "Do you want to calculate distance for Diesel? [y/n]: ";

    if (!(std::cin >> user_input))
        throw std::invalid_argument("Answer for diesel must be single character");

    user_input = std::tolower(user_input);

    if (user_input == 'y' || user_input == 'n')
        return user_input == 'y';

    throw std::invalid_argument("Answer must be 'y' or 'n'");
}

// Calculate co2 emission for a diststance with selected fuel type
// @param distance travel distance in miles
// @param is_diesel fuel type
// @return <double> - calculated fuel emision in kg
double calculateCo2Emission(double distance, bool is_diesel)
{
    const double fuel_used = distance * MILE_CONSUMPTION;
    const double emission_per_litre = is_diesel ? DIESEL_EMISSION : PETROL_EMISSION;

    return fuel_used * emission_per_litre;
}

// Extra - Recursion

// Prints breakdown of co2 emission for a distance recursively
// @param distance total travel distance [miles]
// @param emission total CO2 emission for the trip [kg]
// @param start starting percentage of the journey (0, 10, 20, ... 100)
// @param step increment of percentage for each step in breakdown
// @return <void> - not returning anything
void printBreakdown(double distance, double emission, double start = 5, double step = 5)
{
    if (start > 100) // Return when over 100% distance
        return;

    const double fraction = start / 100.0;

    std::cout << std::fixed << (distance <= 1 ? std::setprecision(6) : std::setprecision(2)) << "Emission: " << emission * fraction << " kg" << "  Distance: " << distance * fraction << " miles" << "  (" << start << "%)\n";

    printBreakdown(distance, emission, start + step, step);
}

// Entry point
int main()
{
    try // Invoke required functions
    {
        const double distance = getTravelDistance();
        const bool is_diesel = isDiesel();
        const double emission = calculateCo2Emission(distance, is_diesel);

        std::cout << "\nIn " << distance << " miles " << (is_diesel ? "Diesel" : "Petrol") << " emits " << emission << " kg. CO₂!";

        // Extra - Example recursive function explained in class
        std::cout << " Would you like to see breakdown [y/N]: ";
        std::string breakdown_prompt;
        if (std::cin >> breakdown_prompt && breakdown_prompt == "y")
        {
            printBreakdown(distance, emission);
        }
    }
    catch (const std::exception &e) // Catch thrown exceptions
    {
        std::cerr << "[ERROR] " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
