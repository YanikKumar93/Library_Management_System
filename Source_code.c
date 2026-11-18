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

static void clear_input(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    if (c == EOF) exit(EXIT_SUCCESS);
}

unsigned long HashPassword(char password[])// Reurns a hash value for the given password using a simple hashing algorithm and working on bits inspite of words.
{
    unsigned long hash = 111;
    int i;
    for (i = 0; password[i] != '\0'; i++)
    {
        hash = hash * 31 + password[i];
    }
    return hash;
}

int main(void)
{
    int User;
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

    return 0;
}

void Admin_Login(void)
{
    FILE *Admin_Credentials;
    char username[20], password[20], stored_username[20];
    unsigned long password_hash, stored_hash;
    int exists = 0;
    int choice;
    Admin_login :
    printf("----- ADMIN LOGIN DASHBOARD -----\n");
    printf("\t1. Login\n");   
    printf("\t2. Register\n");
    printf("Enter your choice here: ");
    if (scanf("%d", &choice) != 1)
    {
        clear_input();
        goto Admin_login;
    }
    if (choice == 1)
    {
        printf("\n----- ADMIN LOGIN -----\n");
        printf("Enter your username: ");
        scanf("%19s", username);
        printf("Enter your password: ");
        scanf("%19s", password);
        password_hash = HashPassword(password);
        Admin_Credentials = fopen("Admin_Credentials.csv", "r");
        if (Admin_Credentials != NULL)
        {
            while (fscanf(Admin_Credentials, " %19[^,],%lu",
                          stored_username, &stored_hash) == 2)
            {
                if (strcmp(username, stored_username) == 0 &&
                    password_hash == stored_hash)
                {
                    printf("\nAdmin login successful!\n");
                    fclose(Admin_Credentials);
                    Admin();
                    return;
                }
            }
            fclose(Admin_Credentials);
        }
        printf("\nInvalid username or password. Please try again.\n\n");
        goto Admin_login;
    }
    else if (choice == 2)
    {
        printf("\n----- ADMIN REGISTRATION -----\n");
        printf("Enter your username: ");
        scanf("%19s", username);
        Admin_Credentials = fopen("Admin_Credentials.csv", "r");
        if (Admin_Credentials != NULL)
        {
            while (fscanf(Admin_Credentials, " %19[^,],%lu",
                        stored_username, &stored_hash) == 2)
            {
                if (strcmp(username, stored_username) == 0)
                {
                    exists = 1;
                    break;
                }
            }
            fclose(Admin_Credentials);
        }
        if (exists ==1)
        {
            printf("This username is already registered.\n");
            printf("Please choose a different username or login if you are already registered.\n");
            goto Admin_login;
        }
        printf("Create your password: ");
        scanf("%19s", password);
        password_hash = HashPassword(password);
        Admin_Credentials = fopen("Admin_Credentials.csv", "a");
        Check_File_Opening(Admin_Credentials, "Admin_Credentials.csv");
        fprintf(Admin_Credentials, "%s,%lu\n", username, password_hash);
        fclose(Admin_Credentials);
        printf("\nAdmin registration successful!\n");
        printf("You can now log in with your credentials.\n\n");
        goto Admin_login;
    }
    else
    {
        printf("Invalid choice. \n");
        printf("Please enter a valid choice.\n\n");
        goto Admin_login;
    }
}

void Student_Login(void)
{
    FILE *Student_Credentials;
    char roll_number[20], name[50], password[20];
    char stored_roll_number[20], stored_name[50];
    unsigned long password_hash, stored_hash;
    Student_login:
    printf("----- STUDENT LOGIN DASHBOARD -----\n");
    {
        printf("Enter your roll number: ");
        scanf("%19s", roll_number);
        printf("Enter your name: ");
        scanf(" %49[^\n]", name);
        printf("Enter your password: ");
        scanf("%19s", password);
        password_hash = HashPassword(password);
        Student_Credentials = fopen("Student_Credentials.csv", "r");
        if (Student_Credentials != NULL)
        {
            while (fscanf(Student_Credentials,
                          " %19[^,],%49[^,],%lu",
                          stored_roll_number,
                          stored_name,
                          &stored_hash) == 3)
            {
                if (strcmp(roll_number, stored_roll_number) == 0 &&
                    strcmp(name, stored_name) == 0 &&
                    password_hash == stored_hash)
                {
                    printf("\nStudent login successful!\n");
                    fclose(Student_Credentials);
                    Student();
                    return;
                }
            }
            fclose(Student_Credentials);
        }
        printf("\nInvalid student credentials. Please try again.\n\n");
        goto Student_login;
    } 
}

void Admin(void)
{
    int Choice;
    FILE *student_file;
    FILE *IT_College_Library_Catalogue;
Admin:
    printf("\nWelcome to the Admin Dashboard\n");
    printf("What do you want to do?\n");
    printf("\t1. Add a student\n");
    printf("\t2. Add a book\n");
    printf("\t3. Check availability of books\n");
    printf("\t4. Checking pending fines\n");
    printf("\t5. Issue a book\n");
    printf("\t6. Return a book\n");
    printf("\t7. Library statistics dashboard\n");
    printf("\t8. Exit\n");
    printf("Enter your choice here: ");
    if (scanf("%d", &Choice) != 1)
    {
        printf("Invalid input.\n");
        printf("Please enter a valid choice. \n");
        clear_input();
        goto Admin;
    }
    switch (Choice)
    {
        case 1: // Add a student 
           { 
            int num = 0;
            Check_File_Opening(student_file = fopen("students.csv", "a+"), "students.csv");
            FILE *Student_Credentials;
            printf("How many students do you want to add? ");
            scanf("%d", &num);
            getchar();
            printf("\n");
            char name[50], roll_number[20], email[50], Branch[50], password[20];
            unsigned long password_hash;
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
                printf("Create password for student %d: ", i + 1);
                fgets(password, sizeof(password), stdin);
                password[strcspn(password, "\n")] = '\0';

                password_hash = HashPassword(password);
                fprintf(student_file, "%s,%s,%s,%s\n", name, roll_number, email, Branch);

                Check_File_Opening(Student_Credentials = fopen("Student_Credentials.csv", "a"),
                                   "Student_Credentials.csv");
                fprintf(Student_Credentials, "%s,%s,%lu\n",
                        roll_number, name, password_hash);
                fclose(Student_Credentials);
            }
            fclose(student_file);
            printf("Students added successfully.\n");
            printf("The changes will be reflected in the students.csv file.\n");
            goto Admin;
        }    

        case 2: // Add a book
            {
            Check_File_Opening(IT_College_Library_Catalogue = fopen("IT_College_Library_Catalogue.csv", "a+"), "IT_College_Library_Catalogue.csv");
            Book:
            Check_File_Opening(IT_College_Library_Catalogue, "IT_College_Library_Catalogue.csv");
            char book_name[100], author_name[100], publisher_name[100];
            int num_books =0,total_books = 0;
            printf("How many books do you want to add? ");
            scanf("%d", &total_books);
            getchar();
            if(sizeof(total_books)!= 4)
            {
                printf("Please enter a valid entry.");
                goto Book;
            }
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
                scanf("%d", &num_books); 
                fprintf(IT_College_Library_Catalogue, "%s,%s,%s,%d\n", book_name, author_name, publisher_name, num_books);
            }
            fclose(IT_College_Library_Catalogue);
            printf("Books added to the library successfully.\n");
            printf("The changes will be reflected in the IT_College_Library_Catalogue.csv file.\n");
            goto Admin;
            }

        case 3: // Check availability of books
            {
                FILE *catalogue;
                FILE *Issued_Books;
                FILE *Returned_Books;
                Returned_Books = fopen("Returned_Books.csv", "r");
                catalogue = fopen("IT_College_Library_Catalogue.csv", "r");
                Issued_Books = fopen("Issued_Books.csv", "r");
                Check_File_Opening(catalogue, "IT_College_Library_Catalogue.csv");
                Check_File_Opening(Issued_Books, "Issued_Books.csv");
                Check_File_Opening(Returned_Books, "Returned_Books.csv");
                char book_name[100],author_name[100],publisher_name[100],search_book[100];
                int num_books=0,found = 0,i=0,j=0;             
                fscanf(catalogue, "%*[^\n]\n");
                printf("Enter the name of the book to search: ");
                scanf(" %99[^\n]", search_book);
                fscanf(Issued_Books, "%*[^\n]\n");
                fscanf(Returned_Books, "%*[^\n]\n");
                while (fscanf(Issued_Books, " %99[^,],%99[^,],%99[^,],%d",
                            book_name,
                            author_name,
                            publisher_name,
                            &num_books) == 4)
                {
                    if (strcmp(search_book, book_name) == 0)
                    {
                        i++;
                    }
                }
                while (fscanf(Returned_Books, " %99[^,],%99[^,],%99[^,],%d",
                            book_name,
                            author_name,
                            publisher_name,
                            &num_books) == 4)
                {
                    if (strcmp(search_book, book_name) == 0)
                    {
                        j++;
                    }
                }
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
                        printf("Quantity: %d\n", num_books-i+j);
                        found = 1;
                        break;
                    }
                }
                if (found == 0)
                {
                    printf("\nBook not found in the catalogue.\n");
                }
                fclose(catalogue);
                fclose(Returned_Books);
                fclose(Issued_Books);
                goto Admin;
            }

        case 5: // Issue a book 
            {
                FILE *Issued_Books;
                Check_File_Opening(Issued_Books = fopen("Issued_Books.csv", "a+"), "Issued_Books.csv");
                char book_name[100], author_name[100], publisher_name[100];
                int enrollment_number = 0,num_books = 0;
                printf("Enter the enrollment number of the student: ");
                scanf("%d", &enrollment_number);
                printf("Enter the number of books to issue: ");
                scanf("%d", &num_books);
                if (num_books > 5)
                {
                    printf("You can issue maximum 5 books at a time.\n");
                    fclose(Issued_Books);
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
                    fprintf(Issued_Books, "%s,%s,%s,%d\n",
                            book_name, author_name, publisher_name,
                            enrollment_number);
                }
                fclose(Issued_Books);
                printf("Books issued successfully.\n"); 
                goto Admin;
            }

        case 6: // Return a book : To be completed
            {
                FILE *Returned_Books;
                Check_File_Opening(Returned_Books = fopen("Returned_Books.csv", "a+"), "Returned_Books.csv");
                char book_name[100], author_name[100], publisher_name[100];
                int enrollment_number = 0,num_books = 0;
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
                    fprintf(Returned_Books, "%s,%s,%s,%d\n", book_name, author_name, publisher_name, enrollment_number);
                }
                fclose(Returned_Books);
                printf("Books returned successfully.\n");
                goto Admin;
            }
        
        case 7:// Library Statistics Dashboard
        {
            FILE *catalogue;
            FILE *student_file;
            FILE *Issued_Books;
            FILE *Backup_issue;
            FILE *Returned_Books;
            char line[300];
            int enrollment_number,num_books,total_books = 0,total_students = 0;
            int total_issued_books = 0,total_returned_books = 0,backup_issued_books = 0;
            Issued_Books = fopen("Issued_Books.csv", "r");
            Backup_issue = fopen("Backup_issue.csv", "r");
            catalogue = fopen("IT_College_Library_Catalogue.csv", "r");
            student_file = fopen("students.csv", "r");
            Returned_Books = fopen("Returned_Books.csv", "r");
            Check_File_Opening(Issued_Books, "Issued_Books.csv");
            if (Backup_issue == NULL)
            {
                Backup_issue = fopen("Backup_issue.csv", "a+");
                Check_File_Opening(Backup_issue, "Backup_issue.csv");
                rewind(Backup_issue);
            }
            Check_File_Opening(catalogue, "IT_College_Library_Catalogue.csv");
            Check_File_Opening(student_file, "students.csv");
            Check_File_Opening(Returned_Books, "Returned_Books.csv");
            // Count total books
            while (fgets(line, sizeof(line), catalogue) != NULL)
            {
                char *last_comma = strrchr(line, ',');
                if (last_comma != NULL &&
                    sscanf(last_comma + 1, "%d", &num_books) == 1)
                {
                    total_books += num_books;
                }
            }

            // Count total issued books
            while (fgets(line, sizeof(line), Issued_Books) != NULL)
            {
                char *last_comma = strrchr(line, ',');
                if (last_comma != NULL &&
                    sscanf(last_comma + 1, "%d", &enrollment_number) == 1)
                {
                    total_issued_books++;
                }
            }

            // Case 5 currently stores issue records in this backup file.
            rewind(Backup_issue);
            while (fgets(line, sizeof(line), Backup_issue) != NULL)
            {
                char *last_comma = strrchr(line, ',');
                if (last_comma != NULL &&
                    sscanf(last_comma + 1, "%d", &enrollment_number) == 1)
                {
                    backup_issued_books++;
                }
            }

            if (total_issued_books == 0)
            {
                total_issued_books = backup_issued_books;
            }

            // Count total registered students
            while (fgets(line, sizeof(line), student_file) != NULL)
            {
                if (strncmp(line, "Name,", 5) != 0 &&
                    strchr(line, ',') != NULL)
                {
                    total_students++;
                }
            }

            // Count total returned books
            while (fgets(line, sizeof(line), Returned_Books) != NULL)
            {
                char *last_comma = strrchr(line, ',');
                if (last_comma != NULL &&
                    sscanf(last_comma + 1, "%d", &enrollment_number) == 1)
                {
                    total_returned_books++;
                }
            }

            fclose(Issued_Books);
            fclose(Backup_issue);
            fclose(catalogue);
            fclose(student_file);
            fclose(Returned_Books);
            printf("\nLibrary Statistics Dashboard\n");

            printf("1. Total number of books in the library: %d\n", total_books);
            printf("2. Total number of books currently present in the library: %d\n",total_books - total_issued_books + total_returned_books);
            printf("3. Total issued books: %d\n",total_issued_books);
            printf("4. Total returned books: %d\n",total_returned_books);
            printf("5. Total registered students: %d\n",total_students);
            goto Admin;
        }

        case 8://Exit
            {
                printf("\nExiting the Admin Dashboard.\n");
                printf("Thank you for using the JIIT Library Management System.\n");
                break;
            }

        default://Case of any error
            {
                printf("Invalid Admin choice.\n");
                goto Admin;
            }
    }
}

static int csv_field_count(const char *line)
{
    int count = 1;
    int quoted = 0;

    for (; *line != '\0'; line++)
    {
        if (*line == '"')
        {
            quoted = !quoted;
        }
        else if (*line == ',' && !quoted)
        {
            count++;
        }
    }
    return count;
}

static int get_csv_field(const char *line, int field_number,char *output, size_t output_size)
{
    int current = 0;
    int quoted = 0;
    size_t length = 0;

    if (output_size == 0)
    {
        return 0;
    }

    for (; *line != '\0'; line++)
    {
        if (*line == '"')
        {
            quoted = !quoted;
            continue;
        }

        if (*line == ',' && !quoted)
        {
            if (current == field_number)
            {
                output[length] = '\0';
                return 1;
            }
            current++;
            continue;
        }

        if (current == field_number && length + 1 < output_size)
        {
            if (*line != '\r' && *line != '\n')
            {
                output[length++] = *line;
            }
        }
    }

    if (current == field_number)
    {
        output[length] = '\0';
        return 1;
    }
    return 0;
}

static int names_match(const char *first, const char *second)
{
    while (*first != '\0' && *second != '\0')
    {
        char a = *first;
        char b = *second;
        if (a >= 'A' && a <= 'Z') a = (char)(a - 'A' + 'a');
        if (b >= 'A' && b <= 'Z') b = (char)(b - 'A' + 'a');
        if (a != b) return 0;
        first++;
        second++;
    }
    return *first == '\0' && *second == '\0';
}

void Student(void)
{
    int Choice;
Student:
    printf("\nWelcome to the Student Dashboard\n");
    printf("What do you want to do?\n");
    printf("\t1. Search for a book\n");
    printf("\t2. Check the issued books\n");
    printf("\t3. Exit\n");
    printf("Enter your choice here: ");
    if (scanf("%d", &Choice) != 1)
    {
        printf("Invalid input.\n");
        clear_input();
        goto Student;
    }

    switch (Choice)
    {
        case 1:// Searching for a book
        {
            FILE *catalogue;
            FILE *Issued_Books;
            FILE *Backup_issue;
            FILE *Returned_Books;
            Check_File_Opening(catalogue = fopen("IT_College_Library_Catalogue.csv", "r"), "IT_College_Library_Catalogue.csv");
            Check_File_Opening(Issued_Books = fopen("Issued_Books.csv", "r"), "Issued_Books.csv");
            Check_File_Opening(Backup_issue = fopen("Backup_issue.csv", "r"), "Backup_issue.csv");
            Check_File_Opening(Returned_Books = fopen("Returned_Books.csv", "r"), "Returned_Books.csv");
            char book_name[100],author_name[100],publisher_name[100],search_book[100],record_book_name[100],line[500];
            int num_books,found = 0,issued_count = 0,returned_count = 0;
            printf("Enter the name of the book you want to search for: ");
            scanf(" %99[^\n]", search_book);
            while (fgets(line, sizeof(line), catalogue) != NULL)
            {
                int fields = csv_field_count(line);

                if (fields >= 7)
                {
                    get_csv_field(line, 1, book_name, sizeof(book_name));
                    get_csv_field(line, 2, author_name, sizeof(author_name));
                    get_csv_field(line, 5, publisher_name, sizeof(publisher_name));
                    get_csv_field(line, 6, record_book_name, sizeof(record_book_name));
                    if (sscanf(record_book_name, "%d", &num_books) != 1)
                    {
                        continue;
                    }
                }
                else if (fields == 4)
                {
                    get_csv_field(line, 0, book_name, sizeof(book_name));
                    get_csv_field(line, 1, author_name, sizeof(author_name));
                    get_csv_field(line, 2, publisher_name, sizeof(publisher_name));
                    get_csv_field(line, 3, record_book_name, sizeof(record_book_name));
                    if (sscanf(record_book_name, "%d", &num_books) != 1)
                    {
                        continue;
                    }
                }
                else
                {
                    continue;
                }

                if (names_match(book_name, search_book))
                {
                    Issued_Books = fopen("Issued_Books.csv", "r");
                    Backup_issue = fopen("Backup_issue.csv", "r");
                    Returned_Books = fopen("Returned_Books.csv", "r");

                    if (Issued_Books != NULL)
                    {
                        while (fgets(line, sizeof(line), Issued_Books) != NULL)
                        {
                            get_csv_field(line, 0, record_book_name, sizeof(record_book_name));
                            if (names_match(record_book_name, search_book))
                            {
                                issued_count++;
                            }
                        }
                        fclose(Issued_Books);
                    }
                    if (Backup_issue != NULL)
                    {
                        while (fgets(line, sizeof(line), Backup_issue) != NULL)
                        {
                            get_csv_field(line, 0, record_book_name, sizeof(record_book_name));
                            if (names_match(record_book_name, search_book))
                            {
                                issued_count++;
                            }
                        }
                        fclose(Backup_issue);
                    }
                    if (Returned_Books != NULL)
                    {
                        while (fgets(line, sizeof(line), Returned_Books) != NULL)
                        {
                            get_csv_field(line, 0, record_book_name, sizeof(record_book_name));
                            if (names_match(record_book_name, search_book))
                            {
                                returned_count++;
                            }
                        }
                        fclose(Returned_Books);
                    }
                    num_books = num_books - issued_count + returned_count;
                    if (num_books < 0)
                    {
                        num_books = 0;
                    }
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

        case 2: // Checking Issued books
        {
            FILE *Issued_Books;
            FILE *Backup_issue;
            Check_File_Opening(Issued_Books = fopen("Issued_Books.csv", "r"), "Issued_Books.csv");
            printf("---------NOTE----------\n");
            printf("\t1. Please note that the books can be issued for a max of 15 days.\n");
            printf("\t2. If the book is not returned within 15 days, a fine of 2 rupees per day will be charged with a base charge of 10 rupees.\n");
            int enrollment_number = 0;
            printf("Enter your enrollment number to check the issued books: ");
            scanf("%d", &enrollment_number);
            char line[500],book[100], author[100], publisher[100], field[100];
            int enrollment = 0, date_issued = 0, i = 1, found = 0;
            while (fgets(line, sizeof(line), Issued_Books) != NULL)
            {
                int fields = csv_field_count(line);

                if (fields == 4)
                {
                    get_csv_field(line, 0, book, sizeof(book));
                    get_csv_field(line, 1, author, sizeof(author));
                    get_csv_field(line, 2, publisher, sizeof(publisher));
                    get_csv_field(line, 3, field, sizeof(field));
                    if (sscanf(field, "%d", &enrollment) != 1)
                        continue;
                    date_issued = 0;
                }
                else if (fields == 5)
                {
                    get_csv_field(line, 0, book, sizeof(book));
                    get_csv_field(line, 1, author, sizeof(author));
                    get_csv_field(line, 2, publisher, sizeof(publisher));
                    get_csv_field(line, 3, field, sizeof(field));
                    if (sscanf(field, "%d", &enrollment) != 1)
                        continue;
                    get_csv_field(line, 4, field, sizeof(field));
                    if (sscanf(field, "%d", &date_issued) != 1)
                        date_issued = 0;
                }
                else
                {
                    continue;
                }

                if (enrollment == enrollment_number)
                {
                    printf("\nIssued Book %d Details:\n", i);
                    printf("Book Name: %s\n", book);
                    printf("Author Name: %s\n", author);
                    printf("Publisher Name: %s\n", publisher);
                    if (date_issued != 0)
                        printf("Date Issued(DDMMYYYY): %d\n", date_issued);
                    else
                        printf("Date Issued(DDMMYYYY): Not recorded\n");
                    i++;
                    found = 1;
                }
            }
            fclose(Issued_Books);
            Backup_issue = fopen("Backup_issue.csv", "r");
            if (Backup_issue != NULL)
            {
                while (fgets(line, sizeof(line), Backup_issue) != NULL)
                {
                    get_csv_field(line, 0, book, sizeof(book));
                    get_csv_field(line, 1, author, sizeof(author));
                    get_csv_field(line, 2, publisher, sizeof(publisher));
                    get_csv_field(line, 3, field, sizeof(field));

                    if (sscanf(field, "%d", &enrollment) == 1 &&
                        enrollment == enrollment_number)
                    {
                        printf("\nIssued Book %d Details:\n", i);
                        printf("Book Name: %s\n", book);
                        printf("Author Name: %s\n", author);
                        printf("Publisher Name: %s\n", publisher);
                        printf("Date Issued(DDMMYYYY): Not recorded\n");
                        i++;
                        found = 1;
                    }
                }
                fclose(Backup_issue);
            }
            if (!found)
            {
                printf("\nNo issued books found for enrollment number %d.\n",
                       enrollment_number);
            }
            goto Student;
        }

        case 3: // Exit 
        {
            printf("\nExiting the Student Dashboard.\n");
            printf("Thank you for visiting the JIIT Library .\n");
            break;
        }

        default : // Case of any invlaid input.
            {
                printf("Invalid Student choice.\n");
                printf("Please enter a valid choice.\n");
                goto Student;
            }
    }      
}
