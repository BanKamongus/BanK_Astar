#pragma once

#include "Node.h"

class Board {

public:
    vector<Node> Space;
    Point Start;
    Point End;
    int Xwide; int Yheight;

    Board(int Xwide, int Yheight, Point Start, Point End):Start(Start),End(End), Xwide(Xwide), Yheight(Yheight){
        Space.reserve(Xwide * Yheight);
        for (int y = Yheight; y >= 0; y--) {
            for (int x = 0; x <= Xwide; x++) {
                Point currentPoint(x, y);
                        Node newNode(currentPoint, Start, End);
                        if (currentPoint == Start) {    newNode.SetStatus(_3_Start);  }
                        else if (currentPoint == End) {   newNode.SetStatus(_4_End);  }
                Space.push_back(newNode);
            }
        }
    }

    void displayNodes()  {
        int CurrentY = -1;
        for (Node& Each : Space) {

                    if (Each.Position.y != CurrentY) {
                        CurrentY = Each.Position.y;
                        cout << endl <<"|" << CurrentY << "\t";
                    }
            cout << Each.getStatusSTR();
        }
    }

    Node* getNode(const Point& position) {
        // Find the node with the specified position
        for (Node& node : Space) {
            if (node.Position == position) {
                return &node;
            }
        }

        // Node not found, return nullptr
        return nullptr;
    }

                    void setStatus(Point startLocation, Point endLocation, int newStatus) {
                        // Ensure startLocation is less than or equal to endLocation in both axes
                        Point topLeft(min(startLocation.x, endLocation.x), min(startLocation.y, endLocation.y));
                        Point bottomRight(max(startLocation.x, endLocation.x), max(startLocation.y, endLocation.y));

                        for (Node& node : Space) {
                            Point nodePosition = node.Position;

                            if (nodePosition.x >= topLeft.x && nodePosition.x <= bottomRight.x &&
                                nodePosition.y >= topLeft.y && nodePosition.y <= bottomRight.y) {
                                node.SetStatus(newStatus);
                            }
                        }
                    }

                    void setObstacle(Point startObstacle, Point endObstacle) {
                        setStatus(startObstacle, endObstacle, 9);  // Assuming 9 represents an obstacle
                    }

};
