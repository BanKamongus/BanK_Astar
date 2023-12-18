#pragma once
#include <limits>


#include "Board.h"


class Walker {
    Board& MyBoard;

public:
    Point CurrentPos;
    Walker(Board& MyBoard) :MyBoard(MyBoard){
        CurrentPos = MyBoard.Start;
    }


    //vector<Node*> Node_LowestF
    //vector<Node*> Node_LowestH
    //vector<Node*> NextNodes
    //Find neighbor Nodes only with unexplored 
    //Nextnodes = the neighbor Node with lowest F 
        //if (there are multiple Nodes with lowest F )
        //Nextnodes = All the neighbor Nodes with lowest H (ignore F)
            //Compare Displacement of F and H from CurrentNode to Nextnode
            //if (F increases more than H decreases)
            //Nextnodes = All the neighbor Node with the 2nd lowest H (ignore F)

    void Explore() {

        Node* NextNode = nullptr;

                    // F
                    vector<Node*> lowestFNodes = GetNeighborNodes_LowestF();
                    if (lowestFNodes.size() > 1) {
                                    // H
                                    vector<Node*> lowestHNodes = GetNeighborNodes_LowestH();
                                    if (lowestHNodes.size()>1) {

                                        Node* lowestHNode = lowestHNodes[0];
                                        float lowestHValue = lowestHNode->H;

                                        for (Node* node : lowestHNodes) {
                                            if (node->H < lowestHValue) {
                                                lowestHNode = node;
                                                lowestHValue = node->H;
                                            }
                                        }

                                        NextNode = lowestHNode;
                                    }
                                    else  {    NextNode = lowestFNodes[0];        }
                    }
                    else   {    NextNode = lowestFNodes[0];          }

        // Found Nextnode (No Neighbor is explored)
        if(NextNode){
            CurrentPos = NextNode->Position;
            MyBoard.setStatus(CurrentPos, CurrentPos, 1);
            cout << "NewFound";
        }
        // Found No Nextnode (All Neighbor is explored)
        else
        {
            cout << "Explored";
        }
        cout << "(" << CurrentPos.x << "," << CurrentPos.y<<")";
        
    }


private:

    vector<Point> GetNeighborCoords() {
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
    vector<Node*> GetNeighborNodes_LowestF() {
        vector<Point> neighborCoords = GetNeighborCoords();
        vector<Node*> neighborNodes;
        float lowestFValue = std::numeric_limits<float>::max();

        for (const Point& neighborCoord : neighborCoords) {
            Node* neighbor = MyBoard.getNode(neighborCoord);
            if (neighbor && neighbor->getStatusINT() == _0_Unexplored) {
                if (neighbor->F < lowestFValue) {
                    neighborNodes.clear();
                    neighborNodes.push_back(neighbor);
                    lowestFValue = neighbor->F;
                }
                else if (neighbor->F == lowestFValue) {
                    neighborNodes.push_back(neighbor);
                }
            }
        }

        if (neighborNodes.empty()) { neighborNodes.push_back(nullptr); }
        return neighborNodes;
    }

    vector<Node*> GetNeighborNodes_LowestH() {
        vector<Point> neighborCoords = GetNeighborCoords();
        vector<Node*> neighborNodes;
        float lowestHValue = std::numeric_limits<float>::max();

        for (const Point& neighborCoord : neighborCoords) {
            Node* neighbor = MyBoard.getNode(neighborCoord);
            if (neighbor && neighbor->getStatusINT() == _0_Unexplored) {
                if (neighbor->H < lowestHValue) {
                    neighborNodes.clear();
                    neighborNodes.push_back(neighbor);
                    lowestHValue = neighbor->H;
                }
                else if (neighbor->H == lowestHValue) {
                    neighborNodes.push_back(neighbor);
                }
            }
        }

        if (neighborNodes.empty()) { neighborNodes.push_back(nullptr); }
        return neighborNodes;
    }


};