#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define TABLE_LINE_LENGTH 110
#define FILE_PATH "studata.dat"

/* The struct student is a data structure that contains the following data:

- msub1: marks of subject 1
- msub2: marks of subject 2
- elective: marks of elective subject
- allied: marks of allied subject
- avg: average marks
- total: total marks
- regno: registration number
- grade: grade
- name: name of the student
- major: major of the student */
struct student {
    double msub1, msub2, elective, allied, avg, total;
    char regno[10], grade, name[20], major[20];
};

int get_student_input(struct student*);
int get_student_batch_input(int);
void display_student_details(struct student);
int search_student(char*);
void calc_scores(struct student*);
int print_highest_three_avg();
int insert_data_to_file(struct student);
void print_header();
int display_all_student_data();

int main(int argc, char const *argv[]) {
    struct student obj;
    int opt = 0;

    /* The main function is responsible for taking user input and calling the appropriate functions. */
    printf("Enter a choice:\n1. Add new student data\n2. Batch input student data\n3. Display all student data\n4. Search for student\n5. Display students with top 3 averages\n6. Exit");
    while (opt != 6) {
        printf("\nMain>> ");
        scanf("%d", &opt);
        // opt = 5;

        switch (opt) {
            case 1: {   // Add new student data
                get_student_input(&obj);
                calc_scores(&obj);
                insert_data_to_file(obj);
                break;
            } case 2: {  // Batch input student data
                int count;
                printf("Enter number of records: ");
                scanf("%d", &count);
                printf("Enter Register Number, First Name, Major, 1st core subject marks(100), 2nd core subject marks(100), allied marks(100) and elective marks(100) (separated by space, new entries on new line)\nBatch Input Below>>\n");
                get_student_batch_input(count);
                break;
            } case 3: { // Display all student data
                printf("\nDisplay all student data\n");
                display_all_student_data();
                break;
            } case 4: { // Search student
                char regno[10];
                printf("Enter the register number to search\nSearch student>> ");
                scanf("%s", regno);
                print_header();
                search_student(regno);
                break;
            } case 5: { // Display students with highest 3 averages
                printf("\nDisplay students with highest 3 averages\n");
                print_header();
                print_highest_three_avg();
                break;
            } case 6: { // Exiting
                printf("\nExiting...\n");
                break;
            } default: {    //Invalid choice
                printf("\nInvalid choice, please try again.");
                break;
            }
        }
    }
    return 0;
}

/* The function get_student_input() takes a pointer to a struct student as an argument. It then asks
the user to enter the student's details and stores them in the struct student.

The function get_student_input() is called in the main() function.*/
int get_student_input(struct student *obj) {
    printf("Enter Register Number(10 digit), First Name, Major, 1st core subject marks(100), 2nd core subject marks(100), allied marks(100) and elective marks(100) (separated by space)\nNew Student>> ");
    scanf("%s%s%s%lf%lf%lf%lf", obj->regno, obj->name, obj->major, &obj->msub1, &obj->msub2, &obj->elective, &obj->allied);
    if (obj->msub1 > 100 || obj->msub2 > 100 || obj->elective > 100 || obj->allied > 100) {
        printf("\nError in marks input (max. 100).\n"); return 1;
    }
    return 0;
}

/* The function get_student_batch_input() takes in the number of students to be entered as an
argument. It then prompts the user to enter the details of each student. The details are then stored
in a struct student object. The function calc_scores() is called to calculate the scores of each
student. The function insert_data_to_file() is called to write the details of each student to the
file. The function get_student_batch_input() returns 0 if all the students are successfully written
to the file. */
int get_student_batch_input(int count) {
    struct student obj;
    int successwritecount = 0, failwritecount = 0;
    char *failedregnos[count];
    printf("===============================================\n");
    for (int i = 0; i < count; i++) {
        scanf("%s%s%s%lf%lf%lf%lf", obj.regno, obj.name, obj.major, &obj.msub1, &obj.msub2, &obj.elective, &obj.allied);
        if (obj.msub1 > 100 || obj.msub2 > 100 || obj.elective > 100 || obj.allied > 100) {
            printf("\nError in marks input (max. 100).\n"); return 1;
        }
        calc_scores(&obj);
        if (insert_data_to_file(obj) == 0) {
            successwritecount++;
        } else {
            strcpy(failedregnos[failwritecount], obj.regno);
            failwritecount++;
        }
    }
    printf("===============================================");
    printf("\n%d records written successfully.\n%d records failed to write.", successwritecount, failwritecount);
    if (failwritecount > 0) {
        printf("\nThe records with following reg.no.(s) failed to write.");
        /* Printing the failedregnos array. */
        for (int i = 0; i < failwritecount; i++)
            printf("\n%s", failedregnos[i]);
    }
    return 0;
}

/* Calculate the scores for each student and assign the grade. */
void calc_scores(struct student *obj) {
    obj->total = obj->msub1 + obj->msub2 + obj->elective + obj->allied;
    obj->avg = obj->total / 4;
    
    /* If the average is greater than 85, assign the letter grade A.
    If the average is greater than 75, assign the letter grade B.
    If the average is greater than 60, assign the letter grade C
    If the average is greater than 45, assign the letter grade D.
    If the average is less than or equal to 35, assign the letter grade F.*/
    if (obj->avg > 85) obj->grade = 'A';
    else if (obj->avg > 75) obj->grade = 'B';
    else if (obj->avg > 60) obj->grade = 'C';
    else if (obj->avg > 45) obj->grade = 'D';
    else if (obj->avg <= 35) obj->grade = 'F';
}

/* Write the object to the file. */
int insert_data_to_file(struct student obj) {
    FILE *file;
    file = fopen(FILE_PATH, "a");
    if (file == NULL) {printf("\nError opening file.\n"); return 1;}

    /* Write the object to the file. */
    int write_rc = fwrite(&obj, sizeof(struct student), 1, file);
    if (write_rc <= 0) {printf("\nError writing to file.\n"); return 2;}

    fclose(file);
    return 0;
}

/* Display the student details. */
void display_student_details(struct student obj) {
    printf("\n|%10s|%-20s|%-20s", obj.regno, obj.name, obj.major);
    printf("|%7.2lf|%7.2lf|%8.2lf|%7.2lf", obj.msub1, obj.msub2, obj.elective, obj.allied);
    printf("|%7.2lf|%7.2lf|%-6c|\n", obj.total, obj.avg, obj.grade);
    for (int i = 0; i < TABLE_LINE_LENGTH; i++) printf("-");
}

/* Print a header for the table. */
void print_header() {
    for (int i = 0; i < TABLE_LINE_LENGTH; i++) printf("=");
    printf("\n|%10s|%-20s|%-20s", "Reg. No.", "Name", "Major");
    printf("|%7s|%7s|%8s|%7s", "Core 1", "Core 2", "Elective", "Allied");
    printf("|%7s|%7s|%-6s|\n", "Total","Average", "Grade");
    for (int i = 0; i < TABLE_LINE_LENGTH; i++) printf("=");
}

/* Display all student data from the file. */
int display_all_student_data() {
    struct student obj;
    FILE *file;
    file = fopen(FILE_PATH, "r");
    if (file == NULL) {printf("\nError opening file.\n"); return 1;}

    print_header();
    /* Reading the file and displaying the details of the student. */
    while (fread(&obj, sizeof(struct student), 1, file)) {
        display_student_details(obj);
    }
    fclose(file);
    return 0;
}

/* The search_student() function searches the file for a student with the given registration number.
If found, the function displays the student's details.

The search_student() function returns 0 if the search was successful, and 1 if the search failed.*/
int search_student(char regno[]) {
    FILE *file;
    int count = 0;
    struct student obj;
    file = fopen(FILE_PATH, "r");
    if (file == NULL) {printf("\nError opening file.\n"); return 1;}

    while (fread(&obj, sizeof(struct student), 1, file)) {
        if (strcmp(obj.regno, regno) == 0) {
            display_student_details(obj);
            count++;
        }
    }
    if (count <= 0) printf("No matching records found");
    fclose(file);
    return 0;
}

/* The function searches for the highest three averages and prints them out.*/
int print_highest_three_avg() {
    struct student obj;
    FILE *file;
    double highestavgs[] = {INT_MIN, INT_MIN, INT_MIN}, found = 1;
    char highavgregno[3][10];
    file = fopen(FILE_PATH, "r");
    if (file == NULL) {printf("\nError opening file.\n"); return 1;}

    /* The highestavgs array is initialized to all 0's. 
    The for loop iterates through the array of highest avgs.

    If the current object's average is greater than the current highest average, 
    the highest average is set to the current object's average. 
    The highest average is then stored in the highestavgs array. 

    The regno of the object with the highest average is stored in the highavgregno
    array. Later this regno will be used to search for and print the students with
    highest averages.

    The for loop then iterates to the next object in the array. */
    for (int i = 0; i < 3; i++) {
        rewind(file);
        /* If the average of the student is larger than the current largest average, then save the
        average and the student's registration number. */
        while (fread(&obj, sizeof(struct student), 1, file)) {
            if (obj.avg > highestavgs[i]) { // if larger than current largest saved
                found = 1;
                for (int j = 0; j < 3; j++) {
                    if (highestavgs[j] == obj.avg) {    // if other highest is same as this one
                        found = 0;
                    }
                }
                /* Checking if the user has already been found in the database. */
                if (found == 1) {
                    highestavgs[i] = obj.avg;
                    strcpy(highavgregno[i], obj.regno);
                }
            }
        }
    }
    fclose(file);
    /* Searching for the student with the highest average grade. */
    for (int i = 0; i < 3; i++) {
        search_student(highavgregno[i]);
    }
    return 0;
}