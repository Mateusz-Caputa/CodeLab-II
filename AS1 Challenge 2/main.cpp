#include <iostream>
#include <fstream>
#include <vector>

// Stores jokes loaded from file and allows to access random joke
class Jokes
{
private:
    std::vector<std::pair<std::string, std::string>> all_jokes; // jokes stored in {Setup : Punchline} paris

public:
    // Load and parse jokes file with "setup?puchnline" format in new line
    // @param file_path path to file with jokes
    // @throw <runtime_error> file not open
    // @throw <length_error> invalid format, empty file
    Jokes(std::string file_path)
    {
        std::ifstream file(file_path);

        if (!file.is_open())
            throw std::runtime_error("Unable to open jokes file: " + file_path);

        std::string textline;
        int line_num = 0; // Current reader position

        while (std::getline(file, textline)) // Read lines until EOF
        {
            line_num++;

            // Split line on '?'
            size_t questionmark_position = textline.find('?');
            std::string question = textline.substr(0, questionmark_position + 1);
            std::string punchline = textline.substr(questionmark_position + 1);

            // Validate line
            if (question.length() <= 0 || punchline.length() <= 0 || questionmark_position == std::string::npos)
            {
                file.close();
                throw std::length_error("Invalid line in the jokes file on line: " + std::to_string(line_num));
            }

            // Add pair of question punchline to all_jokes vector
            all_jokes.push_back({question, punchline});
        }

        file.close();

        // Check if any jokes are loaed
        if (all_jokes.empty())
            throw std::length_error(file_path + " Has no valid jokes.");

        // Set seed for rand() function
        srand(time(nullptr));
    }

    // Get random joke from loaded jokes vector
    // @return <std::pair<std::string, std::string>> random joke queston(first) punchline(last)
    std::pair<std::string, std::string> getRandomJoke()
    {
        int random_index = rand() % all_jokes.size();
        return all_jokes.at(random_index);
    }
};

// Entry point
int main()
{
    try // Define randomJokes instance and run alexa loop
    {
        Jokes randomJokes("randomJokes.txt");

        std::cout << "Alexa: Waiting for commands.\n";

        std::string user_input;
        while (true)
        {
            std::cout << "Alexa: Say 'Alexa, tell me a joke' or 'quit'\nYou: ";
            getline(std::cin, user_input);

            if (user_input == "quit")
            {
                std::cout << "Alexa: Bye Bye." << std::endl;
                return 0;
            }

            if (user_input != "Alexa, tell me a joke")
                continue;

            // Request random joke
            auto joke = randomJokes.getRandomJoke();
            std::string question = joke.first;
            std::string punchline = joke.second;

            // Question user
            std::cout << "Alexa: " << question << "\nYou: ";
            getline(std::cin, user_input);

            if (user_input == punchline)
                std::cout << "Alexa: Oh, you know that one." << std::endl; // User answered punchline
            else
                std::cout << "Alexa: " << punchline << std::endl; // User did not know punchline
        }
    }
    catch (const std::exception &e) // Catch exceptions
    {
        std::cerr << "[ERROR] " << e.what() << std::endl;
        return 1;
    }
}