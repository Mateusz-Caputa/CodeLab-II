# Challenge 1 Task
Develop a program that estimates the CO₂ emissions from a car journey based on the **distance travelled** and the **type of fuel used**.

## Requirements
Program should include functions to:
- **get the distance travelled**
- **get the fuel type**
- **calculate the result**

## Assumptions
| Parameter | Value |
|---|---|
| CONSUMPTION_PER_100MILES | 9.66 litres per 100 miles |
| MILE_CONSUMPTION | CONSUMPTION_PER_100MILES / 100 miles |
| PETROL_EMISSION| 2.68 kg CO₂ / L |
| PETROL_EMISSION | 2.31 kg CO₂ / L |

## Calculation
```
consumption_per_mile = 9.66 (liters) / 100 (miles) = 0.0966 L
fuel_used = distance (miles) * consumption_per_mile
co2_emited = fuel_used * [fuel_type]_emission
```

# CO₂ Calculator

## Techniques showed in CodeLab II
- Functions
- Exceptions
- Function Recursion

## My approach to solving the problem
I began by identifying the formulas needed to calculate fuel consumption per mile, total fuel consumption, and CO₂ emissions. Since the task clearly specifies part of the input data as well as the implementation requirements, defining all the constants used in the program and declaring the required functions was straightforward. I declared the constants as constexpr, as their values are known at compile time.

The basic version of the program was short (37 lines of code), so I extended it with input validation and exception handling. The input functions throw std::invalid_argument when the distance is not numeric or not greater than zero, or when the fuel type answer is not "y" or "n". All exceptions are caught in main(), which displays an error message and returns a non-zero exit code.

As the task focuses on functions, I decided it would be worthwhile to also demonstrate recursion, so I added the printBreakdown() function, which prints the emissions for successive percentages of the journey until it exceeds 100%, which is its base case. I also considered adding an example of function overloading however, this would have only required copying printBreakdown() without the step parameter and with a hardcoded value instead. Keeping the parameter with a default value is a much better solution in this case, as it avoids code duplication.

Finally, I added comments describing each function's purpose, parameters, return values and the exceptions it may throw, to make the code easier to read and maintain.