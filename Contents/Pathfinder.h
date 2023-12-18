#pragma once
#include <limits>


#include "Board.h"


class Pathfinder {
    Board& MyBoard;

public:


    Pathfinder(Board& MyBoard) :MyBoard(MyBoard){   
        Node_Start = MyBoard.getNode(MyBoard.Start);
        Node_End = MyBoard.getNode(MyBoard.End);
        OpenList.push_back(Node_Start);
    }

    bool Found = false;
    Node* Node_Start ;
    Node* Node_End ;
    vector<Node*> OpenList;
    vector<Node*> ClosedList;
    void Explore() {
        if (Found) { cout << "Found!"; return; }

                        Node* Node_Current = OpenList[0];

                        //F-H Node move
                        for (int i = 1; i < OpenList.size(); i++) {
                            if (  
                                (OpenList[i]->F < Node_Current->F) || 
                                ((OpenList[i]->F == Node_Current->F) && (OpenList[i]->H< Node_Current->H))
                               )
                            {    Node_Current = OpenList[i];    }
                        }

                        //Node List Transfer
                        for (int i = OpenList.size() - 1; i >= 0;i--) {
                            if (OpenList[i] == Node_Current) {
                                OpenList.erase(OpenList.begin() + i);
                            }
                        }
                        ClosedList.push_back(Node_Current);
                        MyBoard.setStatus(Node_Current->Position, Node_Current->Position, _1_WalkedPath);

                        //Found End
                        if (Node_Current == Node_End) {
                            Found = true;
                            return;
                        }

                        //Neighbor
                        for (Node* Each : GetNeighborNodes(Node_Current->Position)) {

                                        bool ClosedListContainsNeighbor = false;
                                        for (Node* nodePtr : ClosedList) {
                                            if (nodePtr == Each) {
                                                ClosedListContainsNeighbor = true;
                                                break; 
                                            }
                                        }
                            if (
                                Each->getStatusINT() != _0_Unexplored || 
                                ClosedListContainsNeighbor) {
                                if (Each->getStatusINT() != _4_End) {
                                    continue;
                                }
                            }

                                        bool OpenListContainsNeighbor = false;
                                        for (Node* nodePtr : OpenList) {
                                            if (nodePtr == Each) {
                                                OpenListContainsNeighbor = true;
                                                break; 
                                            }
                                        }
                            float NewMoveCostToNeigh = Node_Current->G + B_Distance(Node_Current->Position,Each->Position);
                            if (NewMoveCostToNeigh < Each->G || !OpenListContainsNeighbor) {
                                Each->G = NewMoveCostToNeigh;
                                Each->H = B_Distance( Node_End->Position, Each->Position);
                                Each->Parent = Node_Current;

                                if (!OpenListContainsNeighbor) {
                                    OpenList.push_back(Each);
                                }
                            }
                        }

                
    }














private:

    vector<Point> GetNeighborCoords(Point& CurrentPos) {
        vector<Point> neighborCoords = {
            {CurrentPos.x - 1, CurrentPos.y + 1},
            {CurrentPos.x, CurrentPos.y + 1},
            {CurrentPos.x + 1, CurrentPos.y + 1},
            {CurrentPos.x - 1, CurrentPos.y},
            {CurrentPos.x + 1, CurrentPos.y},
            {CurrentPos.x - 1, CurrentPos.y - 1},
            {CurrentPos.x, CurrentPos.y - 1},
            {CurrentPos.x + 1, CurrentPos.y - 1}
        };
        return neighborCoords;
    }

    ///////////// Must use STL ///////////////
    vector<Node*> GetNeighborNodes(Point& CurrentPos) {
        vector<Point> neighborCoords = GetNeighborCoords(CurrentPos);
        vector<Node*> neighborNodes;

        for (const Point& neighborCoord : neighborCoords) {
            Node* Nnode = MyBoard.getNode(neighborCoord);
            if (Nnode) {
                neighborNodes.push_back(Nnode);
            }
        }

        if (neighborNodes.empty()) { neighborNodes.push_back(nullptr); }
        return neighborNodes;
    }


};