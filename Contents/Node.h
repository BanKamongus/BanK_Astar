#pragma once

#include "_Begin.h"


enum NodeStatus {

    _0_Unexplored = 0,
    _1_WalkedPath ,
    _2_ShortestPath ,

    _3_Start ,
    _4_End ,

    _9_Obstacle = 9

};

class Node {
        string StatusSTR = " . "; 
        int StatusINT = _0_Unexplored  ;


    public:
        Node* Parent;
        Point Position;
        Node(Point MyPosition, Point Start, Point End)
            : Position(MyPosition) {
            G = B_Distance(Position, Start);
            H = B_Distance(Position, End);
            F = G + H;
        }
        float G = 0; // Distance ( me , Start)
        float H = 0; // Distance ( me , End  )
        float F = 0; // Decision (   G + H   )

                        void SetStatus(int S) {
                            switch (S) {
                                case _3_Start: StatusSTR = "(S)"; break;
                                case _4_End: StatusSTR = "(E)"; break;
                                case _0_Unexplored: StatusSTR = " . "; break;
                                case _1_WalkedPath: StatusSTR = " * "; break;
                                case _2_ShortestPath: StatusSTR = " 0 "; break;
                                case _9_Obstacle: StatusSTR = "|||"; break;
                                default: break;
                            }
                            StatusINT = S;
                        }
                        string getStatusSTR() { return StatusSTR; }
                        int getStatusINT() { return StatusINT; }
};
