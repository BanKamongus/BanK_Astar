#include "../Contents/_Final.h"

int main() {

    Board B1(9, 15, Point(0, 0), Point(7, 10));
    B1.setObstacle(Point(1, 1), Point(1, 4));
    B1.setObstacle(Point(1, 6), Point(1, 9));
    B1.setObstacle(Point(1, 11), Point(1, 13));
    B1.setObstacle(Point(2, 4), Point(4, 4));
    B1.setObstacle(Point(2, 9), Point(4, 9));
    B1.setObstacle(Point(2, 13), Point(4, 13));
    B1.setObstacle(Point(4, 1), Point(4, 5));
    B1.setObstacle(Point(4, 7), Point(4, 11));
    B1.setObstacle(Point(4, 13), Point(4, 14));
    B1.setObstacle(Point(6, 1), Point(6, 3));
    B1.setObstacle(Point(6, 5), Point(6, 7));
    B1.setObstacle(Point(6, 9), Point(6, 12));
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
