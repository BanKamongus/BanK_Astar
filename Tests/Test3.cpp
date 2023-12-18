#include "../Contents/_Final.h"

int main() {

    Board B1(16, 16, Point(0, 0), Point(16, 16));
    B1.setObstacle(Point(1, 1), Point(1, 4));
    B1.setObstacle(Point(1, 6), Point(1, 10));
    B1.setObstacle(Point(2, 10), Point(4, 10));
    B1.setObstacle(Point(2, 12), Point(4, 12));
    B1.setObstacle(Point(2, 14), Point(4, 14));
    B1.setObstacle(Point(4, 1), Point(4, 5));
    B1.setObstacle(Point(4, 7), Point(4, 11));
    B1.setObstacle(Point(4, 13), Point(4, 15));
    B1.setObstacle(Point(6, 1), Point(6, 3));
    B1.setObstacle(Point(6, 5), Point(6, 7));
    B1.setObstacle(Point(6, 9), Point(6, 12));
    B1.setObstacle(Point(8, 2), Point(8, 5));
    B1.setObstacle(Point(8, 7), Point(8, 11));
    B1.setObstacle(Point(10, 4), Point(10, 7));
    B1.setObstacle(Point(10, 9), Point(10, 13));
    B1.setObstacle(Point(12, 1), Point(12, 14));
    Pathfinder W1(B1);


    int ContinueSteps = 75;
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
