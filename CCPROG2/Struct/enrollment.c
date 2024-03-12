#include <stdio.h>
#include <string.h>

struct StudentTag
{
  int idNumber;
  int n;
  struct CourseTag *courseList[5];
};

struct CourseTag
{
  char courseCode[8];
  int numUnits;
};

typedef struct StudentTag Student;
typedef struct CourseTag Course;

int checkEnrollment(Student student, char *key)
{
  int i;
  for (i = 0; i < student.n; i++)
  {
    if (strcmp(key, student.courseList[i]->courseCode) == 0)
    {
      return 1;
    }
  }
  return 0;
}

int enroll(Student *student, Course courseList[], int n, char *key)
{
  int i;
  int courseExists = 0;
  Course *targetAddress;

  if (checkEnrollment(*student, key) == 1)
  {
    return 0;
  }

  for (i = 0; i < n; i++)
  {
    if (strcmp(key, courseList[i].courseCode) == 0)
    {
      courseExists = 1;
      targetAddress = &courseList[i];
    }
  }

  if (courseExists == 0)
  {
    return 0;
  }

  // NOTE: THIS EXAMPLE IGNORES THE THIRD CONDITION, WHICH IS THE STUDENT
  // CNANOT ENROLL IN MORE THAN  20 UNITS.

  student->courseList[student->n] = targetAddress;
  student->n++;

  return 1;
}

void printEnrollments(Student s)
{
  int i;
  for (i = 0; i < s.n; i++)
  {
    printf("%s\n", s.courseList[i]->courseCode);
  }
  printf("====\n");
}

int main()
{
  Student s1;
  Course c1, c2, c3;
  Course list[100];
  
  s1.idNumber = 1111111;
  s1.n = 0;

  strcpy(c1.courseCode, "CCPROG1");
  strcpy(c2.courseCode, "CCPROG2");
  strcpy(c3.courseCode, "CCPROG3");

  c1.numUnits = 3;
  c2.numUnits = 3;
  c3.numUnits = 3;

  list[0] = c1;
  list[1] = c2;
  list[2] = c3;
  
  printEnrollments(s1);

  if (enroll(&s1, list, 3, "CCPROG2") == 1)
    printEnrollments(s1);

  if (enroll(&s1, list, 3, "CCPROG1") == 1)
    printEnrollments(s1);

  if (enroll(&s1, list, 3, "CCPROG4") == 1)
    printEnrollments(s1);

  return 0;
}