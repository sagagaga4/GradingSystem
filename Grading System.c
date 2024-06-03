#include <stdio.h>
#define T 5
#define N 100
#define P 5
#define L 50  

int main() {
  int PleaseTryAgain = 0, i = 0, j = 0, grades[T] = {0}, students = 0,
      grade1 = 0, ALLGRADES[L][T] = {}, HighestG = 0, LowestG = 100, GradeSum = 0, Passed = 0;
  float taskPer[T] = {0}, totalPer = 0, CourseAverageG = 0;

  do {

    PleaseTryAgain = 0;
    totalPer = 0;

    printf("Welcome to our grading system!\n");

    for (i = 0; i < T; i++) {
      printf("Please enter the percentage of task %d:\n", i + 1);
      while (scanf("%f", &taskPer[i]) != 1 || taskPer[i] < 0 ||
             taskPer[i] > 1) {
        printf("Maximum percentage is 1 and minimum percentage is 0!, Please "
               "try again\n");
      }
      totalPer += taskPer[i];
    }

    if (totalPer > 1 || totalPer < 1) {
      printf("Please try again!\n");
      PleaseTryAgain = 1;
    }
  } while (PleaseTryAgain);

  printf("How many students is your class?\n");
  while (scanf("%d", &students) <= 1 && students > N) {
    printf("Input Error!\n");
  }

  for (i = 0; i < students; i++) {
    printf("Please enter student %d grades.\n", i + 1);
    GradeSum = 0;
    
    for (j = 0; j < 5; j++) {
      printf("Enter grade %d:\n", j + 1);
      while (scanf("%d", &grades[j]) != 1 || grades[j] < 0 || grades[j] > N) {
        printf("Input Error!\n");
      }
      ALLGRADES[i][j] = grades[j]; 
      
      if (HighestG < grades[j]) {
        HighestG = grades[j];
      }

      if (grades[j] < LowestG) {
        LowestG = grades[j];
      }

      GradeSum += grades[j];
    }
    if (GradeSum / T > P) {
      Passed++;
    }
    CourseAverageG += GradeSum / T;
  }
  
  CourseAverageG = CourseAverageG / students;


  printf("\n");
  printf("Number of students: %d\n", students);
  printf("Percentage of each task:\n");
  printf("%.2f, %.2f, %.2f, %.2f, %.2f\n", taskPer[0], taskPer[1], taskPer[2],
         taskPer[3], taskPer[4]);
  printf("The grades are:\n");
  
  for(i =0; i < students ; i++)
    {
      for(j = 0; j < T ; j++)
        {
          printf(" %d ", ALLGRADES[i][j]);
        }
    }
  printf("\n");
  printf("Highest grade: %d \n", HighestG);
  printf("Lowest grade: %d \n", LowestG);
  printf("Average: %.2f \n", CourseAverageG );
  printf("Number of passing students: %d \n", Passed);
  printf("Thank you for using our system! \n");

  return 0;
}