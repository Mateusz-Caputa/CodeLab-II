#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

struct Book
{
    std::string title;
    std::string author;
    int pages;
    std::string id;
    bool borrowed;
};

class Libary
{
private:
    std::ifstream file;
    std::vector<Book> all_books;

public:
    Libary(std::string file_path)
    {
        file.open(file_path);

        if (!file.is_open())
        {
            throw std::invalid_argument("Unable to open jokes file: " + file_path);
        }

        std::string file_line;
        while (std::getline(file, file_line))
        {
            Book book;

            // Parse csv
            std::stringstream textline(file_line);
            std::getline(textline, book.title, ',');
            std::getline(textline, book.author, ',');

            // Convert pages to numeric value
            std::string pages_str;
            std::getline(textline, pages_str, ',');
            book.pages = std::stoi(pages_str);

            std::getline(textline, book.id, ',');

            // Is borrowed, convert to bool
            std::string borrowed_str;
            std::getline(textline, borrowed_str, ',');
            book.borrowed = borrowed_str == "true";

            all_books.push_back(book);
        }
    }

    static int menuPrompt()
    {
        std::cout << "===== Library Menu =====\n";
        std::cout << "1. View all books\n";
        std::cout << "2. View a book\n";
        std::cout << "3. Quit\n\n";
        std::cout << "Choose option: ";

        int option;
        if (std::cin >> option)
        {
            if (option < 0 || option > 5)
                throw std::out_of_range("Selected option must be between 1 and 5.");

            return option;
        }

        throw std::out_of_range("Invalid option selected.");
    }

    void printBook(Book book)
    {
        std::cout << "====== Book ====== \n";
        std::cout << "Title: " << book.title << "\n";
        std::cout << "Author: " << book.author << "\n";
        std::cout << "Pages: " << book.pages << "\n";
        std::cout << "ID: " << book.id << "\n";
        std::cout << "Borrowed: " << (book.borrowed ? "Yes" : "No") << "\n";
    }

    void printBooks()
    {
        for (Book book : all_books)
        {
            printBook(book);
        }
    }

    void viewBook()
    {
        std::string book_id;
        std::cout << "Enter book id: ";
        std::cin >> book_id;

        for (Book book : all_books)
        {
            if (book_id == book.id)
            {
                printBook(book);
                return;
            }
        }
        std::cout << "Book with ID: " << book_id << " not found";
    }
};

int main()
{
    try
    {
        Libary libary("bookData.txt");
        while (true)
        {
            int selected_option = Libary::menuPrompt();

            switch (selected_option)
            {
            case 1:
                libary.printBooks();
                break;
            case 2:
                libary.viewBook();
                break;
            case 3:
                return 0;
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "[ERROR] " << e.what();
    }
}