# Challenge 3: Book Manager

> **Constraint:** Your solution must be **no more than 200 lines of code**.

## Task

Develop a simple **library management system** that reads book data from a file and uses it to create `Book` objects.

## Dataset

The `bookData.txt` file (available on Ultra in the assessment session) contains the following information for each book:

| Field | Description |
|---|---|
| Title | The title of the book |
| Author | The author of the book |
| Pages | The number of pages |
| ID | A unique identifier for the book |
| Borrowed Status | Whether the book is currently borrowed |

## Requirements

1. Read the book data from `bookData.txt` using **appropriate file handling techniques**.
2. Use the data to **instantiate a `Book` class** with relevant attributes.
3. Provide a **menu** that allows users to:
   - **View all books**
   - **View an individual book**

## Additional Challenge

Extend the functionality to support:

- **Borrowing** a book
- **Returning** a book

The system should **update the availability status** of each book accordingly.

## Example Menu

```
===== Library Menu =====
1. View all books
2. View a book
3. Borrow a book
4. Return a book
5. Quit
Choose an option:
```