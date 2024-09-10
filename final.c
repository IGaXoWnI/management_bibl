#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOKS 10
#define MAX_LENGTH 50

int main() {
    char titles[MAX_BOOKS][MAX_LENGTH];
    char auteurs[MAX_BOOKS][MAX_LENGTH];
    float prices[MAX_BOOKS];
    int quantities[MAX_BOOKS];
    char rep[3];
    int choice;
    int book_count = 0;

    while (1) {
        printf("--------MENU--------\n");
        printf("1 : Insert a book data\n");
        printf("2 : Show book data\n");
        printf("3 : Show book count\n");
        printf("4 : edit the book\n");
        printf("5 : Exit\n");
        printf("-----------------------------------------\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                do {
                    if (book_count >= MAX_BOOKS) {
                        printf("Cannot add more books, storage is full.\n");
                        break;
                    }

                    printf("Please insert the title of the book: \n");
                    fgets(titles[book_count], sizeof(titles[book_count]), stdin);
                    titles[book_count][strcspn(titles[book_count], "\n")] = '\0'; // Remove newline

                    printf("Please insert the author of the book: \n");
                    fgets(auteurs[book_count], sizeof(auteurs[book_count]), stdin);
                    auteurs[book_count][strcspn(auteurs[book_count], "\n")] = '\0'; // Remove newline

                    printf("Please insert the book price: \n");
                    scanf("%f", &prices[book_count]);
                    getchar(); // Consume newline left by scanf

                    printf("Please insert the quantity of the book: \n");
                    scanf("%d", &quantities[book_count]);
                    getchar(); // Consume newline left by scanf

                    book_count++;

                    printf("Do you want to add another one (Y/N)? ");
                    fgets(rep, sizeof(rep), stdin);
                    rep[strcspn(rep, "\n")] = '\0'; // Remove newline

                } while (strcmp(rep, "Y") == 0 || strcmp(rep, "y") == 0);

                break;

            case 2:
                if (book_count == 0) {
                    printf("No books have been entered.\n");
                } else {
                    for (int i = 0; i < book_count; i++) {
                        printf("Book %d:\n", i + 1);
                        printf("Title: %s\n", titles[i]);
                        printf("Author: %s\n", auteurs[i]);
                        printf("Price: %.2f\n", prices[i]);
                        printf("Quantity: %d\n", quantities[i]);
                        printf("----------------------\n");
                    }
                }
                break;
            case 3 : 
                printf("the number of book did you insert is is %d\n" , book_count) ;
                break;
            case 4 :
                ;
                if (book_count == 0 ) {
                    printf("there no book insterted\n");
                }else {
                    char search_title[MAX_LENGTH] ;
                    char new_title[MAX_LENGTH] ;
                    char new_auteur[MAX_LENGTH] ;
                    char new_price[MAX_BOOKS];
                    char new_quantity[MAX_BOOKS];
                    int index_found = -1;
                    printf("please insert the title of the book you want to modify :");
                    fgets(search_title, sizeof(search_title), stdin);
                    search_title[strcspn(search_title, "\n")] = '\0'; // Remove newline

                    for (int i = 0; i < book_count; i++) {
                        if (strcspn(titles[i], search_title) == 0) {
                            index_found = i ;
                            

                            break;
                        }
                    }
                    if (index_found == -1) {
                        printf("the book didn't exist\n") ;
                    }else {
                        printf("the book founded\n") ;
                        printf("please insert the new title or press enter to keep it :") ;
                        fgets(new_title, sizeof(new_title), stdin);
                        
                        if (strcmp(new_title, "\n") == 0) {
                            
                        }else {
                            new_title[strcspn(new_title, "\n")] = '\0'; 
                            strncpy(titles[index_found], new_title , sizeof(titles[index_found]));
                            printf("the book title updated !! \n") ;

                        };
                        
                        printf("please insert the new auteur or press enter to keep it :") ;
                        fgets(new_auteur, sizeof(new_auteur), stdin);
                        
                        if (strcmp(new_auteur, "\n") == 0) {
                            
                        }else {
                            new_auteur[strcspn(new_auteur, "\n")] = '\0'; 
                            strncpy(auteurs[index_found], new_auteur , sizeof(auteurs[index_found]));
                            printf("the book auteur title updated !!\n") ;
                            
                        }
                        
                        printf("please insert the new price or press enter to keep it :") ;
                        fgets(new_price, sizeof(new_price), stdin) ;
                        
                        if (strcmp(new_price, "\n") == 0) {
                            
                        }else {
                            new_price[strcspn(new_price, "\n")] = '\0'; 
                            prices[index_found] = atof(new_price) ;
                            printf("the book price title updated !!\n") ;
                            
                        }
                        
                        printf("please insert the new quantity or press enter to keep it :") ;
                        fgets(new_quantity, sizeof(new_quantity), stdin) ;
                        
                        if (strcmp(new_quantity, "\n") == 0) {
                            
                        }else {
                            new_quantity[strcspn(new_quantity, "\n")] = '\0'; 
                            quantities[index_found] = atof(new_quantity) ;
                            printf("the book quantity title updated !!\n") ;
                            
                        }


                                            }
                                    }
                
                break;

            case 5:
                printf("Exiting the program.\n");
                return 0;
break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}