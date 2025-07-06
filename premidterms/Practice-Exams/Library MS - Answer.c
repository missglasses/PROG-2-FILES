#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BOOKS 100
#define MAX_MEMBERS 50
#define MAX_BORROWED 3

typedef struct {
    char title[100];
    char author[50];
    int book_id;
    bool is_borrowed;
    int days_borrowed;
} Book;

typedef struct {
    char name[50];
    int member_id;
    Book borrowed_books[MAX_BORROWED];
    int books_borrowed;
} Member;

Book library[MAX_BOOKS];
Member members[MAX_MEMBERS];
int book_count = 0;
int member_count = 0;

void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }
    
    Book new_book;
    printf("Enter book title: ");
    scanf(" %[^\n]", new_book.title);
    
    printf("Enter author name: ");
    scanf(" %[^\n]", new_book.author);
    
    new_book.book_id = 1000 + book_count;
    new_book.is_borrowed = false;
    new_book.days_borrowed = 0;
    
    library[book_count++] = new_book;
    printf("Book added successfully! ID: %d\n", new_book.book_id);
}

void register_member() {
    if (member_count >= MAX_MEMBERS) {
        printf("Member capacity reached!\n");
        return;
    }
    
    Member new_member;
    printf("Enter member name: ");
    scanf(" %[^\n]", new_member.name);
    
    new_member.member_id = 2000 + member_count;
    new_member.books_borrowed = 0;
    
    members[member_count++] = new_member;
    printf("Member registered successfully! ID: %d\n", new_member.member_id);
}

void borrow_book() {
    if (book_count == 0 || member_count == 0) {
        printf("No books or members available!\n");
        return;
    }
    
    int member_id, book_id;
    printf("Enter member ID: ");
    scanf("%d", &member_id);
    
    int member_index = -1;
    for (int i = 0; i < member_count; i++) {
        if (members[i].member_id == member_id) {
            member_index = i;
            break;
        }
    }
    
    if (member_index == -1) {
        printf("Member not found!\n");
        return;
    }
    
    if (members[member_index].books_borrowed >= MAX_BORROWED) {
        printf("Member has reached maximum borrowed books!\n");
        return;
    }
    
    printf("Enter book ID to borrow: ");
    scanf("%d", &book_id);
    
    int book_index = -1;
    for (int i = 0; i < book_count; i++) {
        if (library[i].book_id == book_id) {
            book_index = i;
            break;
        }
    }
    
    if (book_index == -1) {
        printf("Book not found!\n");
        return;
    }
    
    if (library[book_index].is_borrowed) {
        printf("Book is already borrowed!\n");
        return;
    }
    
    library[book_index].is_borrowed = true;
    members[member_index].borrowed_books[members[member_index].books_borrowed++] = library[book_index];
    printf("Book borrowed successfully!\n");
}

void return_book() {
    int member_id, book_id;
    printf("Enter member ID: ");
    scanf("%d", &member_id);
    
    int member_index = -1;
    for (int i = 0; i < member_count; i++) {
        if (members[i].member_id == member_id) {
            member_index = i;
            break;
        }
    }
    
    if (member_index == -1) {
        printf("Member not found!\n");
        return;
    }
    
    printf("Enter book ID to return: ");
    scanf("%d", &book_id);
    
    int book_index = -1;
    for (int i = 0; i < members[member_index].books_borrowed; i++) {
        if (members[member_index].borrowed_books[i].book_id == book_id) {
            book_index = i;
            break;
        }
    }
    
    if (book_index == -1) {
        printf("This member didn't borrow this book!\n");
        return;
    }
    
    printf("Enter number of days borrowed: ");
    scanf("%d", &members[member_index].borrowed_books[book_index].days_borrowed);
    
    if (members[member_index].borrowed_books[book_index].days_borrowed > 14) {
        int overdue = members[member_index].borrowed_books[book_index].days_borrowed - 14;
        printf("Overdue by %d days. Fine: PHP %d\n", overdue, overdue * 5);
    }
    
    for (int i = 0; i < book_count; i++) {
        if (library[i].book_id == book_id) {
            library[i].is_borrowed = false;
            break;
        }
    }
    
    for (int i = book_index; i < members[member_index].books_borrowed - 1; i++) {
        members[member_index].borrowed_books[i] = members[member_index].borrowed_books[i + 1];
    }
    members[member_index].books_borrowed--;
    
    printf("Book returned successfully!\n");
}

void display_books() {
    printf("\n=== Library Books (%d) ===\n", book_count);
    printf("%-10s %-30s %-20s %s\n", "ID", "Title", "Author", "Status");
    
    for (int i = 0; i < book_count; i++) {
        printf("%-10d %-30s %-20s %s\n", 
               library[i].book_id,
               library[i].title,
               library[i].author,
               library[i].is_borrowed ? "Borrowed" : "Available");
    }
}

void display_members() {
    printf("\n=== Library Members (%d) ===\n", member_count);
    printf("%-10s %-20s %s\n", "ID", "Name", "Books Borrowed");
    
    for (int i = 0; i < member_count; i++) {
        printf("%-10d %-20s %d\n", 
               members[i].member_id,
               members[i].name,
               members[i].books_borrowed);
        
        if (members[i].books_borrowed > 0) {
            printf("  Borrowed Books:\n");
            for (int j = 0; j < members[i].books_borrowed; j++) {
                printf("  - %s (ID: %d) - Borrowed for %d days\n", 
                       members[i].borrowed_books[j].title,
                       members[i].borrowed_books[j].book_id,
                       members[i].borrowed_books[j].days_borrowed);
            }
        }
    }
}

int main() {
    int choice;
    
    printf("=== Library Management System ===\n");
    
    while (1) {
        printf("\nMain Menu\n");
        printf("1. Add Book\n");
        printf("2. Register Member\n");
        printf("3. Borrow Book\n");
        printf("4. Return Book\n");
        printf("5. Display All Books\n");
        printf("6. Display All Members\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: add_book(); break;
            case 2: register_member(); break;
            case 3: borrow_book(); break;
            case 4: return_book(); break;
            case 5: display_books(); break;
            case 6: display_members(); break;
            case 7: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
