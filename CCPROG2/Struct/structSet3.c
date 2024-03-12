#include <stdio.h>
#include <string.h> 

typedef char string[8];

struct StudentTag{

    int id;
    struct CourseTag *crsArr[21];
    int n;

};

struct CourseTag{

    string code;
    int units;

};

typedef struct StudentTag Student;
typedef struct CourseTag Course;

int checkEnrollment(Student student, string code){
    int i;

    for (i = 0; i < student.n; i++){
        if (strcmp(code, student.crsArr[i] -> code) == 0){
            return 1;
        }
    }

    return 0;
}

int getTotalUnits(Student student){
    int total = 0;
    int i;

    for (i = 0; i < student.n; i++){
        total += student.crsArr[i] -> units;
    }


    return total;
}

int getCommonCourses(Student a, Student b, Course commonCourses[]){
    int i,j;
    int cnt = 0;

    for (i = 0; i < a.n; i++){

        for (j = 0; j < b.n; j++){
            if (strcmp(a.crsArr[i] -> code, b.crsArr[j] -> code) == 0){
                strcpy(commonCourses[cnt].code, b.crsArr[j] -> code);
                cnt++;
            }
        }

    }

    return cnt;
}

void drop(Student student, string code){
    int i;

    for (i = 0; i < student.n; i++){
        if (strcmp(student.crsArr[i] -> code, code) == 0){
            strcpy(student.crsArr[i] -> code, NULL);
            student.n -= 1;
        }
    }
}

int enroll(Student *student, Course courseList[], string code, int n) {
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    int suc = 0;
    int i;
    Course *target;

    // Check c1
    if (checkEnrollment(*student, code) == 1) {
        c1 = 1;
    }

    // Check c2
    for (i = 0; i < n; i++) {
        if (strcmp(courseList[i].code, code) == 0) {
            target = &courseList[i];
            c2 = 1;
        }
    }

    // Check c3
    c3 = 1;

    if (c1 == 1 && c2 == 1 && c3 == 1) {
        suc = 1;
    }

    if (suc == 1) {
        student->crsArr[student->n] = target;
        student->n++;
    }

    return suc;
}


void printEnrollments(Student s)
{
  int i;
  for (i = 0; i < s.n; i++)
  {
    printf("%s\n", s.crsArr[i]-> code);
  }
  printf("====\n");
}

int main(){
  Student s1;
  Course c1, c2, c3;
  Course list[100];
  
  s1.id = 1111111;
  s1.n = 0;

  strcpy(c1.code, "CCPROG1");
  strcpy(c2.code, "CCPROG2");
  strcpy(c3.code, "CCPROG3");

  c1.units = 3;
  c2.units = 3;
  c3.units = 3;

  list[0] = c1;
  list[1] = c2;
  list[2] = c3;
  

  printEnrollments(s1);

  if (enroll(&s1, list, "CCPROG2", 3) == 1){
    printEnrollments(s1);
  }

  if (enroll(&s1, list, "CCPROG1", 3) == 1){
    printEnrollments(s1);
  }

  if (enroll(&s1, list, "CCPROG4", 3) == 1){
    printEnrollments(s1);
  }

    return 0;
}