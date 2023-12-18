#include "../Contents/_Final.h"

int main() {

    Board B1(18, 18, Point(0, 0), Point(11, 11));
    B1.setObstacle(Point(1, 0), Point(1, 8));
    B1.setObstacle(Point(1, 10), Point(1, 15));
    B1.setObstacle(Point(1, 15), Point(8, 15));
    B1.setObstacle(Point(1, 8), Point(6, 8));
    B1.setObstacle(Point(1, 10), Point(8, 10));
    B1.setObstacle(Point(8, 10), Point(8, 6));
    B1.setObstacle(Point(10, 10), Point(11, 10));
    B1.setObstacle(Point(3, 0), Point(3, 6));
    B1.setObstacle(Point(5, 6), Point(8, 6));
    B1.setObstacle(Point(10, 14), Point(10, 6));
    B1.setObstacle(Point(12, 10), Point(12, 2));
    B1.setObstacle(Point(5, 2), Point(15, 2));
    B1.setObstacle(Point(15, 8), Point(18, 15));
    B1.setObstacle(Point(8, 12), Point(12, 15));
    Pathfinder W1(B1);



    int ContinueSteps =75;
    B1.displayNodes();
    while (true)
    {
        cout << "\n\nContinue(Steps): ";
        cin >> ContinueSteps;
        if (ContinueSteps <= 0) { break; }

        for (int i = 0; i < ContinueSteps; i++) {
            system("cls");
            B1.displayNodes();
            W1.Explore();
        }

    }



    return 0;
}
