#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_USERS 10
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100
#define GENRE_LENGTH 50
#define REVIEW_LENGTH 500

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    char genre[GENRE_LENGTH];
    int rating; // 1 to 5
    char review[REVIEW_LENGTH];
} Book;

typedef struct {
    char username[50];
    Book wantToRead[MAX_BOOKS];
    Book currentlyReading[MAX_BOOKS];
    Book finishedBooks[MAX_BOOKS];
    int wantToReadCount;
    int currentlyReadingCount;
    int finishedBooksCount;
} User;

User users[MAX_USERS];
int userCount = 0;

void addBookToReadingList(User *user, Book book, char *listType) {
    if (strcmp(listType, "want") == 0) {
        user->wantToRead[user->wantToReadCount++] = book;
    } else if (strcmp(listType, "currently") == 0) {
        user->currentlyReading[user->currentlyReadingCount++] = book;
    } else if (strcmp(listType, "finished") == 0) {
        user->finishedBooks[user->finishedBooksCount++] = book;
    }
}

void displayBooks(Book *books, int count) {
    for (int i = 0; i < count; i++) {
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Genre: %s\n", books[i].genre);
        printf("Rating: %d\n", books[i].rating);
        printf("Review: %s\n\n", books[i].review);
    }
}

void searchBooks(User *user, char *title) {
    // Simple search in user's lists
    for (int i = 0; i < user->wantToReadCount; i++) {
        if (strcmp(user->wantToRead[i].title, title) == 0) {
            printf("Found in Want to Read: %s\n", user->wantToRead[i].title);
            return;
        }
    }
    // Repeat for currently reading and finished books...
    printf("Book not found.\n");
}

void addUser(char *username) {
    strcpy(users[userCount++].username, username);
}

int main() {
    char command[50];
    char username[50];

    // User registration
    printf("Enter username: ");
    scanf("%s", username);
    addUser(username);
    
    User *currentUser = &users[userCount - 1];

    // Main loop
    while (1) {
        printf("Enter command (add, display, search, exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            Book newBook;
            printf("Enter book title: ");
            scanf("%s", newBook.title);
            printf("Enter author: ");
            scanf("%s", newBook.author);
            printf("Enter genre: ");
            scanf("%s", newBook.genre);
            printf("Enter rating (1-5): ");
            scanf("%d", &newBook.rating);
            printf("Enter review: ");
            scanf(" %[^\n]", newBook.review);  // To capture spaces in the review
            printf("Add to (want/currently/finished): ");
            char listType[10];
            scanf("%s", listType);
            addBookToReadingList(currentUser, newBook, listType);
        } else if (strcmp(command, "display") == 0) {
            printf("Want to Read:\n");
            displayBooks(currentUser->wantToRead, currentUser->wantToReadCount);
            // Display other lists similarly...
        } else if (strcmp(command, "search") == 0) {
            char title[TITLE_LENGTH];
            printf("Enter book title to search: ");
            scanf("%s", title);
            searchBooks(currentUser, title);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
    
    return 0;
}
