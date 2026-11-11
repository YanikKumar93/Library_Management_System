#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Admin(void);
void Student(void);
void Student_Login(void);
void Admin_Login(void); 
void Check_File_Opening(FILE *file, const char *filename)
{
    if (file == NULL)
    {
        printf("Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
}

int main(void)
{
    int User;
    FILE *catalogue;
    catalogue = fopen("IT_College_Library_Catalogue.csv", "a+");

start:
    printf("-------------------WELCOME TO JIIT LIBRARY--------------------\n\n");
    printf("Please select your category:\n");
    printf("\t 1. Admin\n");
    printf("\t 2. Student\n");
    printf("Enter your choice here: ");

    if (scanf("%d", &User) != 1)
    {
        printf("Invalid input. Please enter a number.\n\n");
        while (getchar() != '\n');
        goto start;
    }

    printf("\n\n");

    switch (User)
    {
        case 1:
            Admin_Login();
            break;

        case 2:
            Student_Login();
            break;

        default:
            printf("Invalid choice. Please enter 1 or 2.\n\n");
            goto start;
    }

    if (catalogue != NULL)
    {
        fclose(catalogue);
    }

    return 0;
}

void Admin_Login(void) // Fix for general 
{
    char username[20], password[20];
    printf("Enter admin username: "); 
    scanf("%s", username);
    printf("Enter admin password: ");
    scanf("%s", password);

    if (strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0)
    {
        printf("Admin login successful.\n");
        Admin();
    }
    else
    {
        printf("Invalid admin credentials.\n");
    }
}

void Student_Login(void)// Fix for general 
{
    char username[20], password[20];
    printf("Enter student username: ");
    scanf("%s", username);
    printf("Enter student password: ");
    scanf("%s", password);

    if (strcmp(username, "student") == 0 && strcmp(password, "student123") == 0)
    {
        printf("Student login successful.\n");
        Student();
    }
    else
    {
        printf("Invalid student credentials.\n");
    }
}

//Error handling throughout the code 

void Admin(void)
{
    int Choice;
    Admin:
    FILE *student_file;
    Check_File_Opening(student_file = fopen("students.csv", "a+"), "students.csv");
    FILE *IT_College_Library_Catalogue;
    Check_File_Opening(IT_College_Library_Catalogue = fopen("IT_College_Library_Catalogue.csv", "a+"), "IT_College_Library_Catalogue.csv");
    printf("\nWelcome to the Admin Dashboard\n");
    printf("What do you want to do?\n");
    printf("\t1. Add a student\n");//Completed
    printf("\t2. Add a book\n");//Completed
    printf("\t3. Check availability of books\n");//To be done
    printf("\t4. Checking pending fines\n");//To be done
    printf("\t5. Issue a book\n");//To be done
    printf("\t6. Return a book\n");//To be done
    printf("\t7. Library statistics dashboard\n");//To be done
    printf("\t8. Exit\n");//To be done
    printf("Enter your choice here: ");

    if (scanf("%d", &Choice) != 1)
    {
        printf("Invalid input.\n");
        printf("Please enter a valid choice. \n");
        goto Admin;
    }

    switch (Choice)
    {
        case 1: // Add a student 
           { 
            int num;
            Check_File_Opening(student_file, "students.csv");
            printf("How many students do you want to add? ");
            scanf("%d", &num);
            getchar();
            printf("\n");
            char name[50], roll_number[20], email[50],Branch[50];
            fprintf(student_file, "Name,Roll Number,Email,Branch\n");
            for (int i = 0; i < num; i++)
            {
                printf("Enter the name of student %d: ", i + 1);
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("\n");
                printf("Enter the Branch of student %d: ", i + 1);
                fgets(Branch, sizeof(Branch), stdin); 
                Branch[strcspn(Branch, "\n")] = '\0';
                printf("\n");
                printf("Enter the roll number of student %d: ", i + 1);
                fgets(roll_number, sizeof(roll_number), stdin);
                roll_number[strcspn(roll_number, "\n")] = '\0';
                printf("Enter the email of student %d: ", i + 1);
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = '\0';
                fprintf(student_file, "%s,%s,%s,%s\n", name, roll_number, email, Branch);
            }
            fclose(student_file);
            printf("Students added successfully.\n");
            printf("The changes will be reflected in the students.csv file.\n");
            goto Admin;
        }    

        case 2: // Add a book
            {
            Check_File_Opening(IT_College_Library_Catalogue, "IT_College_Library_Catalogue.csv");
            char book_name[100], author_name[100], publisher_name[100];
            char num_books[10];
            int total_books = 0;
            printf("How many books do you want to add? ");
            scanf("%d", &total_books);
            fprintf(IT_College_Library_Catalogue, "Book Name,Author Name,Publisher Name,Number of Books\n");
            for (int i = 0; i < total_books; i++)
            {
                printf("Enter the name of book %d: ", i + 1);
                getchar(); 
                fgets(book_name, sizeof(book_name), stdin); 
                book_name[strcspn(book_name, "\n")] = '\0'; 
                printf("Enter the author name of book %d: ", i + 1);
                fgets(author_name, sizeof(author_name), stdin); 
                author_name[strcspn(author_name, "\n")] = '\0'; 
                printf("Enter the publisher name of book %d: ", i + 1);
                fgets(publisher_name, sizeof(publisher_name), stdin); 
                publisher_name[strcspn(publisher_name, "\n")] = '\0'; 
                printf("Enter the quantity of copies of the books added to the library %d: ", i + 1);
                scanf("%s", num_books); 
                num_books[strcspn(num_books, "\n")] = '\0'; 
                fprintf(IT_College_Library_Catalogue, "%s,%s,%s,%s\n", book_name, author_name, publisher_name, num_books);
            }
            fclose(IT_College_Library_Catalogue);
            printf("Books added to the library successfully.\n");
            printf("The changes will be reflected in the IT_College_Library_Catalogue.csv file.\n");
            goto Admin;
            }

        case 3: // Check availability of books
            {
               FILE *catalogue;
                Check_File_Opening(catalogue, "IT_College_Library_Catalogue.csv");
                char book_name[100];
                char author_name[100];
                char publisher_name[100];
                char search_book[100];
                int num_books;
                int found = 0;                
                fscanf(catalogue, "%*[^\n]\n");
                printf("Enter the name of the book to search: ");
                scanf(" %99[^\n]", search_book);
                while (fscanf(catalogue, " %99[^,],%99[^,],%99[^,],%d",
                            book_name,
                            author_name,
                            publisher_name,
                            &num_books) == 4)
                {
                    if (strcmp(search_book, book_name) == 0)
                    {
                        printf("\nBook Found!\n");
                        printf("Book Name: %s\n", book_name);
                        printf("Author Name: %s\n", author_name);
                        printf("Publisher Name: %s\n", publisher_name);
                        printf("Quantity: %d\n", num_books);
                        found = 1;
                        break;
                    }
                }
                if (found == 0)
                {
                    printf("\nBook not found in the catalogue.\n");
                }
                fclose(catalogue);
                goto Admin;
            }

        case 4: // Checking pending fines
            {   
                FILE *Issued_Books;
                int enrollment_number;
                char book_name[100];
                char book[100];
                char author[100];
                char publisher[100];
                int enrollment;
                int date_issued, date_today;
                int found = 0;
                Issued_Books = fopen("Issued_Books.csv", "r");
                Check_File_Opening(Issued_Books, "Issued_Books.csv");
                printf("Enter the enrollment number of the student: ");
                scanf("%d", &enrollment_number);
                printf("Enter the name of the book to check pending fine: ");
                getchar();
                fgets(book_name, sizeof(book_name), stdin);
                book_name[strcspn(book_name, "\n")] = '\0';
                // Search for the matching record in the Issued_Books.csv file
                //[^,]- Used to skip the programme from reading commas
                while (fscanf(Issued_Books,
                            "%99[^,],%99[^,],%99[^,],%d,%d",
                            book,
                            author,
                            publisher,
                            &enrollment,
                            &date_issued) == 5)
                {
                    if (enrollment == enrollment_number &&
                        strcmp(book, book_name) == 0)
                    {
                        found = 1;
                        break;
                    }
                }
                fclose(Issued_Books);
                if (found>0)
                {
                    printf("Enter the current date (DDMMYYYY): ");
                    scanf("%d", &date_today);
                    if ((date_today - date_issued) > 15)
                    {
                        printf("\nBook is overdue.\n");
                        int fine = (date_today - date_issued - 15) * 2 + 10; // Assuming a fine of 2 rupees per day after 15 days and a base fine of 10 units
                        printf("\nPending fine for enrollment number %d and book '%s' is: %d rupees.\n",
                            enrollment_number, book_name, fine);
                    }
                    else
                    {
                        printf("\nNo pending fine for enrollment number %d and book '%s'.\n",
                            enrollment_number, book_name);
                    }
                }
                else
                {
                    printf("\nNo matching issued-book record found.\n");
                }
                goto Admin;
            }

        case 5: // Issue a book 
            {
                FILE *Issued_Books;
                Check_File_Opening(Issued_Books = fopen("Issued_Books.csv", "a+"), "Issued_Books.csv");
                char book_name[100], author_name[100], publisher_name[100];
                int enrollment_number;
                int date;
                printf("Enter the enrollment number of the student: ");
                scanf("%d", &enrollment_number);
                int num_books;
                printf("Enter the number of books to issue: ");
                scanf("%d", &num_books);
                printf("Enter the issue date (in format DDMMYYYY): ");
                scanf("%d", &date);
                if (num_books > 5)
                {
                    printf("You can issue maximum 5 books at a time.\n");
                    goto Admin;
                }
                for (int i = 0; i < num_books; i++)
                {
                    printf("Enter the name of book %d to issue: ", i + 1);
                    getchar(); 
                    fgets(book_name, sizeof(book_name), stdin); 
                    book_name[strcspn(book_name, "\n")] = '\0'; 
                    printf("Enter the author name of book %d to issue: ", i + 1);
                    fgets(author_name, sizeof(author_name), stdin); 
                    author_name[strcspn(author_name, "\n")] = '\0'; 
                    printf("Enter the publisher name of book %d to issue: ", i + 1);
                    fgets(publisher_name, sizeof(publisher_name), stdin); 
                    publisher_name[strcspn(publisher_name, "\n")] = '\0'; 
                    fprintf(Issued_Books, "%s,%s,%s,%d,%d\n", book_name, author_name, publisher_name, enrollment_number, date);
                }
                fclose(Issued_Books);
                printf("Books issued successfully.\n"); 
                goto Admin;
            }

        case 6: // Return a book
            {
                FILE *Issued_Books;
                Check_File_Opening(Issued_Books = fopen("Issued_Books.csv", "a+"), "Issued_Books.csv");
                char book_name[100], author_name[100], publisher_name[100];
                int enrollment_number;  
                int num_books;
                printf("Enter the enrollment number of the student: ");
                scanf("%d", &enrollment_number);
                printf("Enter the number of books to return: ");
                scanf("%d", &num_books);
                for (int i = 0; i < num_books; i++)
                {
                    printf("Enter the name of book %d to return: ", i + 1);
                    getchar(); 
                    fgets(book_name, sizeof(book_name), stdin); 
                    book_name[strcspn(book_name, "\n")] = '\0'; 
                    printf("Enter the author name of book %d to return: ", i + 1);
                    fgets(author_name, sizeof(author_name), stdin); 
                    author_name[strcspn(author_name, "\n")] = '\0'; 
                    printf("Enter the publisher name of book %d to return: ", i + 1);
                    fgets(publisher_name, sizeof(publisher_name), stdin); 
                    publisher_name[strcspn(publisher_name, "\n")] = '\0'; 
                    fprintf(Issued_Books, "%s,%s,%s,%d\n", book_name, author_name, publisher_name, enrollment_number);
                }
                fclose(Issued_Books);
                printf("Books returned successfully.\n");
                goto Admin;
            }
        case 7:
            {
                FILE *catalogue;
                FILE *student_file;
                FILE *Issued_Books;
                char book_name[100], author_name[100], publisher_name[100];
                char name[50], roll_number[20], email[50], Branch[50];
                int enrollment_number;
                int num_books;
                int date;
                int total_books = 0;
                int total_students = 0;
                int total_issued_books = 0;
                Issued_Books = fopen("Issued_Books.csv", "r");
                Check_File_Opening(Issued_Books, "Issued_Books.csv");
                Check_File_Opening(catalogue, "IT_College_Library_Catalogue.csv");
                Check_File_Opening(student_file, "students.csv");
                fscanf(catalogue, "%*[^\n]\n");
                while (fscanf(catalogue, "%99[^,],%99[^,],%99[^,],%d",
                            book_name,
                            author_name,
                            publisher_name,
                            num_books,
                            &date) == 5)
                {
                    total_books += num_books;
                }
                while (fscanf(Issued_Books, "%99[^,],%99[^,],%99[^,],%d,%d",
                            book_name,
                            author_name,
                            publisher_name,
                            &enrollment_number,
                            &date) == 5)
                {
                    total_issued_books += 1;
                }
                fclose(Issued_Books);
                fclose(catalogue);
                fclose(student_file);
                student_file = fopen("students.csv", "r");
                fscanf(student_file, "%*[^\n]\n");
                while (fscanf(student_file, "%99[^,],%99[^,],%99[^,],%c",
                            name,
                            roll_number,
                            email,
                            &Branch) == 4)
                {
                    total_students += 1;
                }
                fclose(student_file);
                printf("\nLibrary Statistics Dashboard\n");
                printf("1. Total number of books in the library: %d\n", total_books);
                printf("2. Total number of books currently present in the library: %d\n", total_books-total_issued_books); 
                printf("3. Total issued books: %d\n", total_issued_books); 
                printf("4. Total registered students: %d\n", total_students);
                goto Admin;
            }

        case 8:
            {
                printf("\nExiting the Admin Dashboard.\n");
                printf("Thank you for using the JIIT Library Management System.\n");
                break;
            }

        default:
            {
                printf("Invalid Admin choice.\n");
                goto Admin;
            }
    }
}

// To be formatted completly

// To create : 
//1. Isseue fine  csv
//2. issue book csv 
//3. Adding time stamp to the issued book csv
//4. Showing up the fine charges and the return duration of the book

// Issued books csv will have the following columns : Book Name, Author Name, Publisher Name, Issue Date, Return Date, Fine calculated 
void Student(void)
{
    Student:
    int Choice;
    printf("\nWelcome to the Student Dashboard\n");
    printf("What do you want to do?\n");
    printf("\t1. Search for a book\n");
    printf("\t2. Check pending fine\n");//To be done
    printf("\t3. Check the issued books\n");
    printf("\t4. Exit\n");
    printf("Enter your choice here: ");
    if (scanf("%d", &Choice) != 1)
    {
        printf("Invalid input.\n");
        goto Student;
    }

    switch (Choice)
    {
        case 1:
        {
            FILE *catalogue;
            Check_File_Opening(catalogue = fopen("IT_College_Library_Catalogue.csv", "r"), "IT_College_Library_Catalogue.csv");
            char book_name[100];
            char author_name[100];
            char publisher_name[100];
            char search_book[100];
            int num_books;
            int found = 0;
            fscanf(catalogue, "%*[^\n]\n");
            printf("Enter the name of the book you want to search for: ");
            scanf("%99s", search_book);
            while (fscanf(catalogue, "%99[^,],%99[^,],%99[^,],%d", book_name, author_name, publisher_name, &num_books) == 4)
            {
                if (strcmp(book_name, search_book) == 0)
                {
                    printf("Book found: \n");
                    printf("Book Name: %s\n", book_name);
                    printf("Author Name: %s\n", author_name);
                    printf("Publisher Name: %s\n", publisher_name);
                    printf("Number of copies available in library: %d\n", num_books);
                    found = 1;
                    break;
                }
            }
            if (found==0)
            {
                printf("Book not found.\n");
            }
            fclose(catalogue);
            goto Student;
        }

        case 2:
        {
            FILE *Issued_Books;
                int enrollment_number;
                char book_name[100];
                char book[100];
                char author[100];
                char publisher[100];
                int enrollment;
                int date_issued, date_today;
                int found = 0;
                Issued_Books = fopen("Issued_Books.csv", "r");
                Check_File_Opening(Issued_Books, "Issued_Books.csv");
                printf("Enter your enrollment number : ");
                scanf("%d", &enrollment_number);
                printf("Enter the name of the book to check pending fine: ");
                getchar();
                fgets(book_name, sizeof(book_name), stdin);
                book_name[strcspn(book_name, "\n")] = '\0';
                // Search for the matching record in the Issued_Books.csv file
                //[^,]- Used to skip the programme from reading commas
                while (fscanf(Issued_Books,
                            "%99[^,],%99[^,],%99[^,],%d,%d",
                            book,
                            author,
                            publisher,
                            &enrollment,
                            &date_issued) == 5)
                {
                    if (enrollment == enrollment_number &&
                        strcmp(book, book_name) == 0)
                    {
                        found = 1;
                        break;
                    }
                }
                fclose(Issued_Books);
                if (found>0)
                {
                    printf("Enter the current date (DDMMYYYY): ");
                    scanf("%d", &date_today);
                    if ((date_today - date_issued) > 15)
                    {
                        printf("\nBook is overdue.\n");
                        int fine = (date_today - date_issued - 15) * 2 + 10; // Assuming a fine of 2 rupees per day after 15 days and a base fine of 10 units
                        printf("\nPending fine for enrollment number %d and book '%s' is: %d rupees.\n",
                            enrollment_number, book_name, fine);
                    }
                    else
                    {
                        printf("\nNo pending fine for enrollment number %d and book '%s'.\n",
                            enrollment_number, book_name);
                    }
                }
                else
                {
                    printf("\nNo matching issued-book record found.\n");
                }
            goto Student;
        }

        case 3:
        {
            FILE *Issued_Books;
            Check_File_Opening(Issued_Books = fopen("Issued_Books.csv", "r"), "Issued_Books.csv");
            printf("---------NOTE----------\n");
            printf("\t1. Please note that the books can be issued for a max of 15 days.\n");
            printf("\t2. If the book is not returned within 15 days, a fine of 2 rupees per day will be charged with a base charge of 10 rupees.\n");
            int enrollment_number;
            printf("Enter your enrollment number to check the issued books: ");
            scanf("%d", &enrollment_number);
            char book[100];
            char author[100];
            char publisher[100];
            int enrollment;
            int date_issued;
            int i=1;
            while (fscanf(Issued_Books,
                            "%99[^,],%99[^,],%99[^,],%d,%d",
                            book,
                            author,
                            publisher,
                            &enrollment,
                            &date_issued) == 5)
                {
                    if (enrollment == enrollment_number)
                    {
                        printf("\nIssued Book %d Details:\n", i);
                        printf("Book Name: %s\n", book);
                        printf("Author Name: %s\n", author);
                        printf("Publisher Name: %s\n", publisher);
                        printf("Date Issued(DDMMYYYY): %d\n", date_issued);
                        i++;
                    }
                }
            fclose(Issued_Books);
            goto Student;
        }

        case 4:
        {
            printf("\nExiting the Student Dashboard.\n");
            printf("Thank you for visiting the JIIT Library .\n");
            break;
        }

        default :
            {
                printf("Invalid Student choice.\n");
                printf("Please enter a valid choice.\n");
                goto Student;
            }
    }      
}
