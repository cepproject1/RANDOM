'''
Write a Python program to manage the borrowing records of books in a library. Implement
the following functionalities:
• Compute the average number of books borrowed by all library members.
• Find the book with the highest and lowest number of borrowings in the library.
• Count the number of members who have not borrowed any books (denoted by a
borrow count of 0).
• Display the most frequently borrowed book (i.e., the mode of borrow counts).
After performing, determine the time and Space complexity of each operation
'''

students = {
    1: ['Deld', 'os', 'dsa', 'oop'],
    2: ['Deld', 'os', 'dsa'],
    3: ['Deld', 'dsa'],
    4: [],
    5: ['oop']
}

# ---------------- Function Definitions ---------------- #

def average_books(students):
    """Compute the average number of books borrowed."""
    total = 0
    for i in students:
        total += len(students[i])
    return total / len(students)


def count_zero_borrowers(students):
    """Count members with zero borrowed books."""
    count = 0
    for i in students:
        if len(students[i]) == 0:
            count += 1
    return count


def book_borrow_count(students):
    """Compute how many times each book is borrowed."""
    book_count = {}
    for books in students.values():
        for book in books:
            if book not in book_count:
                book_count[book] = 1
            else:
                book_count[book] += 1
    return book_count


def highest_lowest_books(book_count):
    """Find book(s) with highest and lowest borrowings — without using max()/min()."""
    if not book_count:
        return [], []

    # Find highest and lowest manually
    first_value = True
    for book in book_count:
        if first_value:
            high = low = book_count[book]
            first_value = False
        else:
            if book_count[book] > high:
                high = book_count[book]
            if book_count[book] < low:
                low = book_count[book]

    # Collect books
    highest_books = []
    lowest_books = []
    for book in book_count:
        if book_count[book] == high:
            highest_books.append(book)
        if book_count[book] == low:
            lowest_books.append(book)

    return highest_books, lowest_books


def most_frequent_book(book_count):
    """Find the most frequently borrowed book(s) (mode) without using max()."""
    if not book_count:
        return []
    
    # Step 1: Find highest borrow count
    highest = None
    for book in book_count:
        count = book_count[book]
        if highest is None or count > highest:
            highest = count

    # Step 2: Collect all books with that count
    mode_books = []
    for book in book_count:
        if book_count[book] == highest:
            mode_books.append(book)

    return mode_books


# ---------------- Main Menu ---------------- #

while True:
    print("\n----- LIBRARY MENU -----")
    print("1. Compute the average number of books borrowed")
    print("2. Count the number of members who have not borrowed any books")
    print("3. Find the book with the highest and lowest borrowings")
    print("4. Display the most frequently borrowed book (mode)")
    print("5. Exit")

    choice = int(input("Enter your choice: "))

    match choice:
        case 1:
            avg = average_books(students)
            print(f"Average number of books borrowed: {avg:.2f}")

        case 2:
            zero_count = count_zero_borrowers(students)
            print(f"Members with zero borrowed books: {zero_count}")

        case 3:
            book_count = book_borrow_count(students)
            high, low = highest_lowest_books(book_count)
            print(f"Highest borrowed book(s): {high}")
            print(f"Lowest borrowed book(s): {low}")

        case 4:
            book_count = book_borrow_count(students)
            mode_books = most_frequent_book(book_count)
            print(f"Most frequently borrowed book(s): {mode_books}")

        case 5:
            print("Exiting... Goodbye!")
            break

        case _:
            print("Invalid choice. Please select from 1–5.")
