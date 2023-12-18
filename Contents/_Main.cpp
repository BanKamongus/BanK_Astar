#include "_Final.h"


void PointOP() 
{
    Point p1(1.0f, 2.0f);
    Point p2(4.0f, 6.0f);

    Point sum = p1 + p2;
    Point diff = p1 - p2;

    p1 += p2;
    p1 -= p2;

    float distance = B_Distance(p1, p2);

    // Output the results
    cout << "Sum: (" << sum.x << ", " << sum.y << ")\n";
    cout << "Difference: (" << diff.x << ", " << diff.y << ")\n";
    cout << "Distance between points: " << distance << endl;
}



int main() {

    Board B1(16, 16, Point(0, 0), Point(15, 8));
    B1.setObstacle(Point(1, 0), Point(1, 8));
    B1.setObstacle(Point(1, 10), Point(1, 15));
    B1.setObstacle(Point(1, 15), Point(8, 15));
    B1.setObstacle(Point(1, 8), Point(6, 8));
    B1.setObstacle(Point(1, 10), Point(8, 10));
    B1.setObstacle(Point(8, 10), Point(8, 6)); 
    B1.setObstacle(Point(5, 6), Point(8, 6)); 
    B1.setObstacle(Point(10, 14), Point(10, 6)); 
    B1.setObstacle(Point(12, 10), Point(12, 2)); 
    //B1.setObstacle(Point(5, 2), Point(15, 2)); 
    Pathfinder W1(B1);


    int ContinueSteps =75;
    while (true)
    {
        for (int i = 0; i < ContinueSteps; i++) {
            system("cls");
            B1.displayNodes();
            W1.Explore();
        }

        cout << "\n\nContinue(Steps): ";
        cin >> ContinueSteps;
        if (ContinueSteps <= 0) { break; }

    }



    return 0;
}
