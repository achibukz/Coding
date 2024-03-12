#include <stdio.h>
#include <string.h>


struct PointTag{

    int x;
    int y;

};

typedef struct PointTag point;

int main(){
    point p1;
    
    printf("Pick your x-coordinate: ");
    scanf("%d", &p1.x);
    printf("Pick your y-coordinate: ");
    scanf("%d", &p1.y);

    if (p1.x > 0 && p1.y > 0){
        printf("Quadrant 1");
    }
    else if (p1.x < 0 && p1.y > 0){
        printf("Quadrant 2");
    }
    else if (p1.x < 0 && p1.y < 0){
        printf("Quadrant 3");
    }
    else if (p1.x > 0 && p1.y < 0){
        printf("Quadrant 4");
    }

    return 0;
}