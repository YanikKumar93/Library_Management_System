#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
    printf("\t4. Check pending fines\n");//To be done
    printf("\t5. Library statistics dashboard\n");//To be done
    printf("\t6. Exit\n");//To be done
    printf("Enter your choice here: ");

    if (scanf("%d", &Choice) != 1)
    {
        printf("Invalid input.\n");
        return;
    }

    switch (Choice)
    {
        case 1:
           { 
            int num;
            if (student_file == NULL)
            {
                printf("Error opening student file.\n");
                return;
            }
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

            
        case 2:
            {
            if (IT_College_Library_Catalogue == NULL)
            {
                printf("Error opening library catalogue file.\n");
                return;
            }
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


        case 3:
            {
               FILE *catalogue;

                char book_name[100];
                char author_name[100];
                char publisher_name[100];
                char search_book[100];
                int num_books;
                int found = 0;
                Check_File_Opening(catalogue = fopen("IT_College_Library_Catalogue.csv", "r"), "IT_College_Library_Catalogue.csv");
                if (catalogue == NULL)
                {
                    printf("Error opening catalogue file.\n");
                    return;
                }
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

        case 5:
            {
                FILE *catalogue;
                FILE *student_file;

                char book_name[100], author_name[100], publisher_name[100];
                char name[50], roll_number[20], email[50], Branch[50];
                int num_books;
                int total_books = 0;
                int total_students = 0;
                catalogue = fopen("IT_College_Library_Catalogue.csv", "r");

                if (catalogue == NULL)
                {
                    printf("Error opening library catalogue file.\n");
                    return;
                }
                fscanf(catalogue, "%*[^\n]\n");
                while (fscanf(catalogue, "%99[^,],%99[^,],%99[^,],%d",
                            book_name,
                            author_name,
                            publisher_name,
                            &num_books) == 4)
                {
                    total_books += num_books;
                }
                fclose(catalogue);
                student_file = fopen("students.csv", "r");
                if (student_file == NULL)
                {
                    printf("Error opening student file.\n");
                    return;
                }
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
                printf("2. Total number of books currently present in the library: %d\n", total_books); // Update it after maintaining a record of issued books
                printf("3. Total issued books: %d\n", total_books); //Update it after maintaining a record of issued books
                printf("4. Total registered students: %d\n", total_students); // Placeholder for actual number of registered students
                goto Admin;
            }

        case 4:
            {
                printf("\nChecking student fine:\n");
                goto Admin;
            }
        case 6:
            {
                printf("\nExiting the Admin Dashboard.\n");
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

// To create : 1. Isseue fine  csv
//2. issue book csv 
//3. Adding time stamp to the issued book csv
//4. Showing up the fine charges and the return duration of the book
void Student(void)
{
    Student:
    int Choice;
    printf("\nWelcome to the Student Dashboard\n");
    printf("What do you want to do?\n");
    printf("\t1. Issue a book\n");
    printf("\t2. Return a book\n");
    printf("\t3. Check pending fine\n");
    printf("\t4. Search for a book\n");
    printf("\t5. Check student fine\n");
    printf("\t6. Exit\n");
    printf("Enter your choice here: ");

    if (scanf("%d", &Choice) != 1)
    {
        printf("Invalid input.\n");
        return;
    }

    switch (Choice)
    {
        case 1:
            {
                FILE *Issued_Books;
                Issued_Books = fopen("Issued_Books.csv", "a");
                Check_File_Opening(Issued_Books, "Issued_Books.csv");
                printf("Before issuing the book please go through the following instructuons :\n");
                printf("\t1. You can issue a book for a maximum of 15 days.\n");
                printf("\t2. If you return the book after 15 days, a fine of Rs. 10 per day will be charged.\n");
                printf("\t3. If you lose the book, you will be required to pay the replacement cost.\n");
                printf("\n\n");
                printf("\nEnter the following details of the book:\n");
                printf("\t1. Book Name\n");
                printf("\t2. Author Name\n");
                printf("\t3. Publisher Name\n");
                printf("\t4.Enter the number of days for which you want to issue the book: ");
                /* Add input handling for book details and issue date. */
                goto Student;
            }

        case 2:
            {
                printf("\nEnter the following details of the book:\n");
                printf("\t1. Book Name\n");
                printf("\t2. Author Name\n");
                printf("\t3. Publisher Name\n");
                printf("\t4. Return the book\n");
                goto Student;
            }
        case 3:
            {
                printf("\nEnter the name of the book you issued: ");
                printf("\nEnter the name of the author of the book  : ");
                goto Student;
            }

        case 4:
            {
                printf("\nEnter the name of the book: ");
                goto Student;
            }
        case 5:
            {
                printf("\nEnter the student ID to check the fine: ");
                goto Student;
            }   
        case 6:
            {
                printf("\nExiting the Student Dashboard.\n");
                break;
            }
        default:
            {
                printf("Invalid choice.\n");
                printf("Please enter  a valid choice. \n");
                goto Student;
            }
        }
}      
