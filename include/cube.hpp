// cube.hpp

#include <vector>
#include <queue>
#include <random>
#include <sstream>

#include "servo.hpp"
#include "piece.hpp"
#include "imageProcess.hpp"


#ifndef CUBE
#define CUBE

class virCube {
public:
    piece pieces[3][9]; // Array of pieces, where the first index is the "layer", so pieces[0]: z=1, pieces[1]: z=0, pieces[2]: z=-1
                        // Second index is the position facing the XY plane (front-facing), in a square going from 0-8.
    // Front = pieces[0]                                            col[2]
    // Right = pieces[0]2,5,8 + pieces[1]2,5,8 + pieces[2]2,5,8     col[0]
    // Back  = pieces[2]                                            col[2]
    // Left  = pieces[0]0,3,6 + pieces[1]0,3,6 + pieces[2]0,3,6     col[0]
    // Up    = pieces[0]0,1,2 + pieces[1]0,1,2 + pieces[2]0,1,2     col[1]
    // Down  = pieces[0]6,7,8   pieces[1]6,7,8 + pieces[2]6,7,8     col[1]

    int rotationCount;
    
    virServo bottomServo = virServo(0);
    virServo frontServo = virServo(1);
    virServo leftServo = virServo(2);
    virServo backServo = virServo(3);
    virServo rightServo = virServo(5);
    
    bool robotStatus;

    virCube(bool robotState) : robotStatus(robotState) {
        bottomServo.rotationTimeCW = 140;
        bottomServo.CWStop = 1.59;
        bottomServo.rotationTimeCCW = 150;
        //frontServo.rotationTimeCW = 150;
        frontServo.rotationTimeCCW = 155;
        leftServo.rotationTimeCW = 145;
        leftServo.rotationTimeCCW = 150;
        backServo.rotationTimeCW = 180;
        backServo.rotationTimeCCW = 165;
        backServo.CCWStop = 1.51;
        rightServo.rotationTimeCW = 170;
        rightServo.rotationTimeCCW = 165;
        
        rotationCount = 0;
        robotStatus = robotState;
        if (robotStatus) {
            std::cout << "I am the robot :)" << std::endl;
        } else {
            for (int layer = 0; layer < 3; layer++) {
                for (int position = 0; position < 9; position++) {
                    int x = position % 3 - 1;
                    int y = 1 - position / 3;
                    int z = 1- layer;
                    pieces[layer][position] = piece(x, y, z);

                    if (layer == 0) {
                        pieces[layer][position].col[2]='O'; // Front Color
                    } else if (layer == 2) {
                        pieces[layer][position].col[2]='R'; // Back Color
                    }

                    if (position % 3 == 0) {
                        pieces[layer][position].col[0]='B'; // Left Color
                    } else if (position % 3 == 2) {
                        pieces[layer][position].col[0]='G'; // Right Color
                    }

                    if (position / 3 == 0) {
                        pieces[layer][position].col[1]='W'; // Top Color
                    } else if (position / 3 == 2) {
                        pieces[layer][position].col[1]='Y'; // Bottom Color
                    }
                }
            }
        }
    }

    std::string getColorCode(char color) {
        switch (color) {
            case 'W': return "\033[47m"; // White background
            case 'Y': return "\033[43m"; // Yellow background
            case 'R': return "\033[41m"; // Red background
            case 'O': return "\033[48;5;208m"; // Magenta for orange background
            case 'G': return "\033[42m"; // Green background
            case 'B': return "\033[44m"; // Blue background
            default:  return "\033[40m"; // Default to black background
        }
    }

    void printSquare(char color) {
        std::cout << getColorCode(color) << "  " << "\033[0m"; // Print colored block and reset
    }

    void printCube() {
        // Print top face
        std::cout << "       ";
        for (int i = 0; i < 3; i++) {
            printSquare(pieces[2][i].col[1]);
        }
        std::cout << std::endl;
        std::cout << "       ";
        for (int i = 0; i < 3; i++) {
            printSquare(pieces[1][i].col[1]);
        }
        std::cout << std::endl;
        std::cout << "       ";
        for (int i = 0; i < 3; i++) {
            printSquare(pieces[0][i].col[1]);
        }
        std::cout << std::endl << std::endl;

        // Print left, front, right, and back faces
        for (int i = 0; i < 3; i++) {
            // Left face
            for (int j = 0; j < 3; j++) {
               printSquare(pieces[2-j][i * 3].col[0]);
            }
            std::cout << " ";

            // Front face
            for (int j = 0; j < 3; j++) {
                printSquare(pieces[0][i * 3 + j].col[2]);
            }
            std::cout << " ";

            // Right face
            for (int j = 0; j < 3; j++) {
                printSquare(pieces[j][i * 3 + 2].col[0]);
            }
            std::cout << " ";

            // Back face
            for (int j = 2; j >= 0; j--) {
                printSquare(pieces[2][i * 3 + j].col[2]);
            }
            std::cout << std::endl;
        }

        // Print bottom face
        std::cout << std::endl;
        std::cout << "       ";
        for (int i = 0; i < 3; i++) {
            printSquare(pieces[0][i + 6].col[1]);
        }
        std::cout << std::endl;
        std::cout << "       ";
        for (int i = 0; i < 3; i++) {
            printSquare(pieces[1][i + 6].col[1]);
        }
        std::cout << std::endl;
        std::cout << "       ";
        for (int i = 0; i < 3; i++) {
            printSquare(pieces[2][i + 6].col[1]);
        }
        std::cout << std::endl;
    }

    // f = front clockwise, F = front counter clockwise, u = upper clockwise, etc...
    void rotateFace(char face) {
        rotationCount++;
        rotMatrix rotMatricies;
        piece temp[9];
        switch (face)
        {
        case 'f': {
            for (int i = 0; i < 9; i++) {
                temp[i] = pieces[0][i];
            }

            for (int i = 0; i < 9; i++) {
                temp[i].rotate(rotMatricies.FCW);
            }

            for (int i = 0; i < 9; i++) {
                int x = temp[i].pos[0];
                int y = temp[i].pos[1];
                int newIndex = (1 - y) * 3 + (x + 1);
                pieces[0][newIndex] = temp[i];
            }
            if (robotStatus) {
                frontServo.rotate(0,1,1);
            }
            break;
        }

        case 'F': {
            for (int i = 0; i < 9; i++) {
                temp[i] = pieces[0][i];
            }

            for (int i = 0; i < 9; i++) {
                temp[i].rotate(rotMatricies.FCCW);
            }

            for (int i = 0; i < 9; i++) {
                int x = temp[i].pos[0];
                int y = temp[i].pos[1];
                int newIndex = (1 - y) * 3 + (x + 1);
                pieces[0][newIndex] = temp[i];
            }
            if (robotStatus) {
                frontServo.rotate(0,1,0);
            }
            break;
        }

        case 'r': {
            int index = 0;
            for (int layer = 0; layer < 3; layer++) {
                for (int pos = 2; pos < 9; pos += 3) {
                    temp[index++] = pieces[layer][pos];
                }
            }

            for (int i = 0; i < 9; i++) {
                temp[i].rotate(rotMatricies.RCW);
            }

            for (int i = 0; i < 9; i++) {
                int y = temp[i].pos[1];
                int z = temp[i].pos[2];
                int layer = 1 - z;
                int pos = (1 - y) * 3 + 2;
                pieces[layer][pos] = temp[i];
            }
            if (robotStatus) {
                rightServo.rotate(0,1,1);
            }
            break;            
        }

        case 'R': {
            int index = 0;
            for (int layer = 0; layer < 3; layer++) {
                for (int pos = 2; pos < 9; pos += 3) {
                    temp[index++] = pieces[layer][pos];
                }
            }

            for (int i = 0; i < 9; i++) {
                temp[i].rotate(rotMatricies.RCCW);
            }

            for (int i = 0; i < 9; i++) {
                int y = temp[i].pos[1];
                int z = temp[i].pos[2];
                int layer = 1 - z;
                int pos = (1 - y) * 3 + 2;
                pieces[layer][pos] = temp[i];
            }
            if (robotStatus) {
                rightServo.rotate(0,1,0);
            }
            break;
        }

        case 'b': {
            int index = 0;
            for (int i = 0; i < 9; i++) {
                temp[i] = pieces[2][i];
            }

            for (int i = 0; i < 9; i++) {
                temp[i].rotate(rotMatricies.BCW);
            }

            for (int i = 0; i < 9; i++) {
                int x = temp[i].pos[0];
                int y = temp[i].pos[1];
                int newIndex = (1 - y) * 3 + (x + 1);
                pieces[2][newIndex] = temp[i];
            }
            if (robotStatus) {
                backServo.rotate(0,1,1);
            }
            break;
        }

        case 'B': {
            int index = 0;
            for (int i = 0; i < 9; i++) {
                temp[i] = pieces[2][i];
            }

            for (int i = 0; i < 9; i++) {
                temp[i].rotate(rotMatricies.BCCW);
            }

            for (int i = 0; i < 9; i++) {
                int x = temp[i].pos[0];
                int y = temp[i].pos[1];
                int newIndex = (1 - y) * 3 + (x + 1);
                pieces[2][newIndex] = temp[i];
            }
            if (robotStatus) {
                backServo.rotate(0,1,0);
            }
            break;
        }

        case 'l': {
            int index = 0;
            for (int layer = 0; layer < 3; layer++) {
                for (int pos = 0; pos < 9; pos += 3) {
                    temp[index++] = pieces[layer][pos];
                }
            }

            for (int i = 0; i < 9; i++) {
                temp[i].rotate(rotMatricies.LCW);
            }

            for (int i = 0; i < 9; i++) {
                int y = temp[i].pos[1];
                int z = temp[i].pos[2];
                int layer = 1 - z;
                int pos = (1 - y) * 3;
                pieces[layer][pos] = temp[i];
            }
            if (robotStatus) {
                leftServo.rotate(0,1,1);
            }
            break;
        }

        case 'L': {
            int index = 0;
            for (int layer = 0; layer < 3; layer++) {
                for (int pos = 0; pos < 9; pos += 3) {
                    temp[index++] = pieces[layer][pos];
                }
            }

            for (int i = 0; i < 9; i++) {
                temp[i].rotate(rotMatricies.LCCW);
            }

            for (int i = 0; i < 9; i++) {
                int y = temp[i].pos[1];
                int z = temp[i].pos[2];
                int layer = 1 - z;
                int pos = (1 - y) * 3;
                pieces[layer][pos] = temp[i];
            }
            if (robotStatus) {
                leftServo.rotate(0,1,0);
            }
            break;
        }

        case 'd': {
            int index = 0;
            for (int layer = 0; layer < 3; layer++) {
                for (int pos = 6; pos < 9; pos++) {
                    temp[index++] = pieces[layer][pos];
                }
            }

            for (int i = 0; i < 9; i++) {
                temp[i].rotate(rotMatricies.DCW);
            }

            for (int i = 0; i < 9; i++) {
                int x = temp[i].pos[0];
                int z = temp[i].pos[2];
                int layer = 1 - z;
                int pos = 6 + (x + 1);
                pieces[layer][pos] = temp[i];
            }
            if (robotStatus) {
                bottomServo.rotate(0,1,1);
            }
            break;
        }

        case 'D': {
            int index = 0;
            for (int layer = 0; layer < 3; layer++) {
                for (int pos = 6; pos < 9; pos++) {
                    temp[index++] = pieces[layer][pos];
                }
            }

            for (int i = 0; i < 9; i++) {
                temp[i].rotate(rotMatricies.DCCW);
            }

            for (int i = 0; i < 9; i++) {
                int x = temp[i].pos[0];
                int z = temp[i].pos[2];
                int layer = 1 - z;
                int pos = 6 + (x + 1);
                pieces[layer][pos] = temp[i];
            }
            if (robotStatus) {
                bottomServo.rotate(0,1,0);
            }
            break;
        }

        case 'u': {// R L F2 B2 R' L' D R L F2 B2 R' L' 
            rotationCount += 16;
            rotateFace('r');
            rotateFace('l');
            rotateFace('f');
            rotateFace('f');
            rotateFace('b');
            rotateFace('b');
            rotateFace('R');
            rotateFace('L');
            rotateFace('d');
            rotateFace('r');
            rotateFace('l');
            rotateFace('f');
            rotateFace('f');
            rotateFace('b');
            rotateFace('b');
            rotateFace('R');
            rotateFace('L');
            break;
            }

        case 'U': {// L R F2 B2 L' R' D' L R F2 B2 L' R'
            rotationCount += 16;
            rotateFace('l');
            rotateFace('r');
            rotateFace('f');
            rotateFace('f');
            rotateFace('b');
            rotateFace('b');
            rotateFace('L');
            rotateFace('R');
            rotateFace('D');
            rotateFace('l');
            rotateFace('r');
            rotateFace('f');
            rotateFace('f');
            rotateFace('b');
            rotateFace('b');
            rotateFace('L');
            rotateFace('R');
            break;
            }
        }
    }
    
    void rotateFaceServoONLY(char face) {
        switch (face) {
            case 'f': {
                if (robotStatus) {
                    frontServo.rotate(0, 1, 1);
                }
                break;
            }

            case 'F': {
                if (robotStatus) {
                    frontServo.rotate(0, 1, 0);
                }
                break;
            }

            case 'r': {
                if (robotStatus) {
                    rightServo.rotate(0, 1, 1);
                }
                break;            
            }

            case 'R': {
                if (robotStatus) {
                    rightServo.rotate(0, 1, 0);
                }
                break;
            }

            case 'b': {
                if (robotStatus) {
                    backServo.rotate(0, 1, 1);
                }
                break;
            }

            case 'B': {
                if (robotStatus) {
                    backServo.rotate(0, 1, 0);
                }
                break;
            }

            case 'l': {
                if (robotStatus) {
                    leftServo.rotate(0, 1, 1);
                }
                break;
            }

            case 'L': {
                if (robotStatus) {
                    leftServo.rotate(0, 1, 0);
                }
                break;
            }

            case 'd': {
                if (robotStatus) {
                    bottomServo.rotate(0, 1, 1);
                }
                break;
            }

            case 'D': {
                if (robotStatus) {
                    bottomServo.rotate(0, 1, 0);
                }
                break;
            }

            case 'u': {
                rotateFaceServoONLY('r');
                rotateFaceServoONLY('l');
                rotateFaceServoONLY('f');
                rotateFaceServoONLY('f');
                rotateFaceServoONLY('b');
                rotateFaceServoONLY('b');
                rotateFaceServoONLY('R');
                rotateFaceServoONLY('L');
                rotateFaceServoONLY('d');
                rotateFaceServoONLY('r');
                rotateFaceServoONLY('l');
                rotateFaceServoONLY('f');
                rotateFaceServoONLY('f');
                rotateFaceServoONLY('b');
                rotateFaceServoONLY('b');
                rotateFaceServoONLY('R');
                rotateFaceServoONLY('L');
                break;
            }

            case 'U': {
                rotateFaceServoONLY('l');
                rotateFaceServoONLY('r');
                rotateFaceServoONLY('f');
                rotateFaceServoONLY('f');
                rotateFaceServoONLY('b');
                rotateFaceServoONLY('b');
                rotateFaceServoONLY('L');
                rotateFaceServoONLY('R');
                rotateFaceServoONLY('D');
                rotateFaceServoONLY('l');
                rotateFaceServoONLY('r');
                rotateFaceServoONLY('f');
                rotateFaceServoONLY('f');
                rotateFaceServoONLY('b');
                rotateFaceServoONLY('b');
                rotateFaceServoONLY('L');
                rotateFaceServoONLY('R');
                break;
            }
        }
    }

    void randomize(int numMoves, bool robotState) {
        if (robotState) {
            char moves[] = {'f', 'F', 'r', 'R', 'b', 'B', 'l', 'L', 'd', 'D'};
            std::random_device rd;   
            std::mt19937 gen(rd());  
            std::uniform_int_distribution<> dist(0, 9); 

            for (int i = 0; i < numMoves; i++) {
                int randomIndex = dist(gen);    
                char move = moves[randomIndex]; 

                rotateFace(move);
            }
        } else {
            char moves[] = {'f', 'F', 'r', 'R', 'b', 'B', 'l', 'L', 'd', 'D', 'u', 'U'};
            std::random_device rd;   
            std::mt19937 gen(rd());  
            std::uniform_int_distribution<> dist(0,11); 

            for (int i = 0; i < numMoves; i++) {
                int randomIndex = dist(gen);    
                char move = moves[randomIndex]; 

                rotateFace(move);
            }
        }
    }

    bool isSolved() {
        // centers:
        // Left  = G  |  Front = O
        // Right = B  |  Back  = R
        // Up    = Y  |  Down  = W

        char leftColor = 'G';
        char frontColor = 'O';
        char rightColor = 'B';
        char backColor = 'R';
        char upColor = 'Y';
        char downColor = 'W';
                
        for (int i = 0; i < 9; i++) {
            // Check the front face
            if (pieces[0][i].col[2] != frontColor) return false;

            // Check the back face
            if (pieces[2][i].col[2] != backColor) return false;

            // Check the left face
            if (pieces[0][i % 3 == 0 ? i : 0].col[0] != leftColor) return false;
            if (pieces[1][i % 3 == 0 ? i : 0].col[0] != leftColor) return false;
            if (pieces[2][i % 3 == 0 ? i : 0].col[0] != leftColor) return false;

            // Check the right face
            if (pieces[0][i % 3 == 2 ? i : 2].col[0] != rightColor) return false;
            if (pieces[1][i % 3 == 2 ? i : 2].col[0] != rightColor) return false;
            if (pieces[2][i % 3 == 2 ? i : 2].col[0] != rightColor) return false;

            // Check the top face
            if (pieces[0][i < 3 ? i : 0].col[1] != upColor) return false;
            if (pieces[1][i < 3 ? i : 0].col[1] != upColor) return false;
            if (pieces[2][i < 3 ? i : 0].col[1] != upColor) return false;

            // Check the bottom face
            if (pieces[0][i > 5 ? i : 6].col[1] != downColor) return false;
            if (pieces[1][i > 5 ? i : 6].col[1] != downColor) return false;
            if (pieces[2][i > 5 ? i : 6].col[1] != downColor) return false;
        }
        return true;
    }

    std::string getStateID() const {
        std::string stateID = ""; // Prints in the format "YYYYYYYYYBBBBBBBBBOOOOOOOOOWWWWWWWWWGGGGGGGGGRRRRRRRRR", but would be replaced by the piece's respective color(s)

        // Top face
        for (int i = 0; i < 3; i++) {
            stateID += pieces[2][i].col[1];
        }
        for (int i = 0; i < 3; i++) {
            stateID +=  pieces[1][i].col[1];
        }
        for (int i = 0; i < 3; i++) {
            stateID += pieces[0][i].col[1];
        }

        // Right face
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                stateID += pieces[j][i * 3 + 2].col[0];
            }
        }

        // Front face
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                stateID += pieces[0][i * 3 + j].col[2];
            }
        }

        // Bottom face
        for (int i = 0; i < 3; i++) {
            stateID += pieces[0][i + 6].col[1];
        }

        for (int i = 0; i < 3; i++) {
            stateID += pieces[1][i + 6].col[1];
        }

        for (int i = 0; i < 3; i++) {
            stateID += pieces[2][i + 6].col[1];
        }

        // Left face
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
               stateID += pieces[2-j][i * 3].col[0];
            }
        }

        // Back face
        for (int i = 0; i < 3; i++) {
            for (int j = 2; j >= 0; j--) {
                stateID += pieces[2][i * 3 + j].col[2];
            }
        }
        return stateID;
    }

    void applyMovesServer(std::string moves) { // Applies moves in the form of the server format.
        std::istringstream moveStream(moves);
        std::string move;

        while (moveStream >> move) {
            if (move.length() == 2) {
                char moveType = move[0];
                int count = move[1] - '0';
                
                if (move == "U2") {
                    rotateFace('W');
                    printCube(); std::cout << "\n";
                }
                
                if (count == 3) {
                    rotateFace(moveType);
                    printCube(); std::cout << "\n";
                } else {
                    for (int i = 0; i < count; ++i) {
                        rotateFace(tolower(moveType));
                        printCube(); std::cout << "\n";
                    }
                }
            } else {
                std::cerr << "Invalid move format: " << move << std::endl;
            }
        }
    }

    void pictureSequence() { 
        // Sequence:
        // 1: P(top)     r L - front to top
        // 2: P(front)   r L - bottom to top
        // 3: P(bottom)  r L - back to top
        // 4: P(back)    r L (back to normal) f B - left to top
        // 5: P(left)    f B - bottom to top
        // 6: P(bottom)  f B - right to top
        // 7: P(right)   f B (back to normal) f r L - front to top 
        // 8: P(front)   l R F (back to normal) b R l - back to top
        // 9: P(back)    L r B (back to normal) r b F - right to top
        // 10:P(right)   f B R (back to normal) l B f - left to top
        // 11:P(left)    F b L (back to normal)
        // 40 total moves :p

        std::string currentFace;
        
        // Delete existing cube config, for debugging basically
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 9; j++) {
                for (int k = 0; k < 3; k++) {
                    pieces[i][j].col[k] = 'A';
                }
            }
        }
        // set centers for all but top
        pieces[0][4].col[2] = 'O';
        pieces[1][3].col[0] = 'B';
        pieces[2][4].col[2] = 'R';
        pieces[1][5].col[0] = 'G';
        pieces[1][7].col[1] = 'Y';
        

        // 1: P(top)     r L - front to top
        currentFace = returnFaceColors();
        // assign top colors
        pieces[2][0].col[1] = currentFace[0];
        pieces[2][1].col[1] = currentFace[1];
        pieces[2][2].col[1] = currentFace[2];
        pieces[1][0].col[1] = currentFace[3];
        pieces[1][1].col[1] = 'W'; // center doesn't change == white
        pieces[1][2].col[1] = currentFace[5];
        pieces[0][0].col[1] = currentFace[6];
        pieces[0][1].col[1] = currentFace[7];
        pieces[0][2].col[1] = currentFace[8];
        
        this->printCube();
        this->rotateFaceServoONLY('r'); this->rotateFaceServoONLY('L');
        
        // 2: P(front)   r L - bottom to top
        currentFace = returnFaceColors();
        // assign front colors
        pieces[0][0].col[2] = currentFace[0];
        pieces[0][2].col[2] = currentFace[2];
        pieces[0][3].col[2] = currentFace[3];
        pieces[0][5].col[2] = currentFace[5];
        pieces[0][6].col[2] = currentFace[6];
        pieces[0][8].col[2] = currentFace[8];
        
        this->printCube();
        this->rotateFaceServoONLY('r'); this->rotateFaceServoONLY('L');
        
        // 3: P(bottom)  r L - back to top
        currentFace = returnFaceColors();
        // assign bottom colors
        pieces[0][6].col[1] = currentFace[0];
        pieces[0][8].col[1] = currentFace[2];
        pieces[1][6].col[1] = currentFace[3];
        pieces[1][8].col[1] = currentFace[5];
        pieces[2][6].col[1] = currentFace[6];
        pieces[2][8].col[1] = currentFace[8];
        
        this->printCube();
        this->rotateFaceServoONLY('r'); this->rotateFaceServoONLY('L');

        // 4: P(back)    r L (back to normal) f B - left to top
        currentFace = returnFaceColors();
        // assign back colors
        pieces[2][0].col[2] = currentFace[6];
        pieces[2][2].col[2] = currentFace[8];
        pieces[2][3].col[2] = currentFace[3];
        pieces[2][5].col[2] = currentFace[5];
        pieces[2][6].col[2] = currentFace[0];
        pieces[2][8].col[2] = currentFace[2];
        
        this->printCube();
        this->rotateFaceServoONLY('r'); this->rotateFaceServoONLY('L'); this->rotateFaceServoONLY('f'); this->rotateFaceServoONLY('B'); 
        
        // 5: P(left)    f B - bottom to top
        currentFace = returnFaceColors();
        // assign left
        pieces[0][0].col[0] = currentFace[8];
        pieces[0][3].col[0] = currentFace[7];
        pieces[0][6].col[0] = currentFace[6];
        pieces[2][0].col[0] = currentFace[2];
        pieces[2][3].col[0] = currentFace[1];
        pieces[2][6].col[0] = currentFace[0];
        
        this->printCube();
        this->rotateFaceServoONLY('f'); this->rotateFaceServoONLY('B');
        
        // 6: P(bottom)  f B - right to top
        currentFace = returnFaceColors();
        // assign bottom
        pieces[0][6].col[1] = currentFace[8];
        pieces[0][7].col[1] = currentFace[7];
        pieces[0][8].col[1] = currentFace[6];
        pieces[2][6].col[1] = currentFace[2];
        pieces[2][7].col[1] = currentFace[1];
        pieces[2][8].col[1] = currentFace[0];
        
        this->printCube();
        this->rotateFaceServoONLY('f'); this->rotateFaceServoONLY('B');

        // 7: P(right)   f B (back to normal) f r L - front to top 
        currentFace = returnFaceColors();
        // assign right
        pieces[0][2].col[0] = currentFace[6];
        pieces[0][5].col[0] = currentFace[7];
        pieces[0][8].col[0] = currentFace[8];
        pieces[2][2].col[0] = currentFace[0];
        pieces[2][5].col[0] = currentFace[1];
        pieces[2][8].col[0] = currentFace[2];
        
        this->printCube();
        this->rotateFaceServoONLY('f'); this->rotateFaceServoONLY('B'); this->rotateFaceServoONLY('f'); this->rotateFaceServoONLY('r'); this->rotateFaceServoONLY('L');
        
        // 8: P(front)   l R F (back to normal) b R l - back to top
        currentFace = returnFaceColors();
        // assign front
        pieces[0][1].col[2] = currentFace[5];
        pieces[0][7].col[2] = currentFace[3];
        
        this->printCube();
        this->rotateFaceServoONLY('l'); this->rotateFaceServoONLY('R'); this->rotateFaceServoONLY('F'); this->rotateFaceServoONLY('b'); this->rotateFaceServoONLY('R'); this->rotateFaceServoONLY('l');
        
        // 9: P(back)    L r B (back to normal) r b F - right to top
        currentFace = returnFaceColors();
        // assign back
        pieces[2][1].col[2] = currentFace[3];
        pieces[2][7].col[2] = currentFace[5];
        
        this->printCube();
        this->rotateFaceServoONLY('L'); this->rotateFaceServoONLY('r'); this->rotateFaceServoONLY('B'); this->rotateFaceServoONLY('r'); this->rotateFaceServoONLY('b'); this->rotateFaceServoONLY('F');
        
        // 10:P(right)   f B R (back to normal) l B f - left to top
        currentFace = returnFaceColors();
        // assign right
        pieces[1][2].col[0] = currentFace[1];
        pieces[1][8].col[0] = currentFace[7];
        
        this->printCube();
        this->rotateFaceServoONLY('f'); this->rotateFaceServoONLY('B'); this->rotateFaceServoONLY('R'); this->rotateFaceServoONLY('l'); this->rotateFaceServoONLY('B'); this->rotateFaceServoONLY('f');
        
        // 11:P(left)    F b L (back to normal)
        currentFace = returnFaceColors();
        // assign left
        pieces[1][0].col[0] = currentFace[7];
        pieces[1][6].col[0] = currentFace[1];
        
        this->printCube();
        this->rotateFaceServoONLY('F'); this->rotateFaceServoONLY('b'); this->rotateFaceServoONLY('L'); 
        
    }
    

};
#endif
