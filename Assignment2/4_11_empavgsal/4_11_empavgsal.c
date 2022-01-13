#include <stdio.h>
#include <string.h>

#define OBJ_SIZE 8
#define SEP_LINE_LENGTH 105

struct employee {
    char num[8], name[30], dept[30], desig[20];
    double salary;
};

double calc_emp_avg_salary(struct employee[]);
double calc_total_dept_salary(char*, struct employee[]);
int get_unique_dept(char[OBJ_SIZE][30], struct employee[]);
void emp_input(struct employee[], int);
void emp_display(struct employee);
void print_header();
void print_dept_header();

int main(int argc, char const *argv[]) {
    struct employee emp[OBJ_SIZE];

    emp_input(emp, OBJ_SIZE);

    // Print average salary of the employees
    printf("\n");
    for (int i = 0; i < 43; i++) printf("=");
    printf("\n|%30s|%10.2lf|\n", "Average salary of employee", calc_emp_avg_salary(emp));
    for (int i = 0; i < 43; i++) printf("=");
    printf("\n");

    // print employees with salaries higher than average
    printf("\nEmployees with salaries above average");
    print_header();
    for (int i = 0; i < OBJ_SIZE; i++) {
        if (emp[i].salary > calc_emp_avg_salary(emp)) {
            emp_display(emp[i]);
        }
    }

    // make a list of unique departments
    char dept[OBJ_SIZE][30];
    int dept_count;
    dept_count = get_unique_dept(dept, emp);   
    // calculate total salary of departments
    printf("\nTotal salaries by departments");
    print_dept_header();
    for (int i = 0; i < dept_count; i++) {
        printf("\n|%30s|%11.2lf|\n", dept[i], calc_total_dept_salary(dept[i], emp));
        for (int i = 0; i < 44; i++) printf("-");
    }
    
    
    
    // for (int i = 0; i < OBJ_SIZE; i++) emp_display(emp[i]);

    printf("\n");
    return 0;
}

double calc_emp_avg_salary(struct employee obj[]) {
    double avg_salary;
    for (int i = 0; i < OBJ_SIZE; i++) {
        avg_salary += obj[i].salary;
    }
    avg_salary /= OBJ_SIZE;
    return avg_salary;
}

double calc_total_dept_salary(char *dept, struct employee obj[]) {
    double curr_salary_sum = 0;
    for (int j = 0; j < OBJ_SIZE; j++) {
          if (strcmp(dept, obj[j].dept) == 0) curr_salary_sum += obj[j].salary;            
    }
    return curr_salary_sum;
}

int get_unique_dept(char dept[OBJ_SIZE][30], struct employee obj[]) {
    int count = 0;
    for (int i = 0; i < OBJ_SIZE; i++) {
        int flag = 1;
        for (int j = 0; j <= i; j++) {
            if (strcmp(dept[j], obj[i].dept) == 0) {
                flag = 0;
                break;       
            }    
        }
        if (flag == 1) {
            strcpy(dept[count], obj[i].dept);
            count++;
        }
    }
    return count;
}

void emp_input(struct employee obj[], int count) {
    printf("Enter employee Number, First Name, Department, Designation and salary (separated by space)\n");
    for (int i = 0; i < count; i++) {
        printf(">> ");
        scanf("%s%s%s%s%lf", obj[i].num, obj[i].name, obj[i].dept, obj[i].desig, &obj[i].salary);
    }
}

void emp_display(struct employee obj) {
    printf("|%-8s|%-30s|%-30s|%-20s|%11.2lf|\n", obj.num, obj.name, obj.dept, obj.desig, obj.salary);
    for (int i = 0; i < SEP_LINE_LENGTH; i++) printf("-"); printf("\n");
}

void print_header() {
    printf("\n");
    for (int i = 0; i < SEP_LINE_LENGTH; i++) printf("="); printf("\n");
    printf("|%-8s|%-30s|%-30s|%-20s|%11s|\n", "Number", "Name", "Deptartment", "Designation", "Salary");
    for (int i = 0; i < SEP_LINE_LENGTH; i++) printf("="); printf("\n");
}

void print_dept_header() {
    printf("\n");
    for (int i = 0; i < 44; i++) printf("=");
    printf("\n|%-30s|%11s|\n", "Department", "Salary");
    for (int i = 0; i < 44; i++) printf("=");
}