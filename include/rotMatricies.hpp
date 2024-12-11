// rotMatricies.hpp
// Stores rotational matricies for each side/face

#ifndef MATRICIES
#define MATRICIES

class rotMatrix {
public:
    // Front face (Z-axis rotations)
    int FCW[3][3] = {
        { 0, -1, 0},
        { 1,  0, 0},
        { 0,  0, 1}
    };
    int FCCW[3][3] = {
        { 0,  1, 0},
        {-1,  0, 0},
        { 0,  0, 1}
    };

    // Back face (Z-axis rotations)
    int BCW[3][3] = {
        { 0,  1, 0},
        {-1,  0, 0},
        { 0,  0, 1}
    };
    int BCCW[3][3] = {
        { 0, -1, 0},
        { 1,  0, 0},
        { 0,  0, 1}
    };

    // Right face (X-axis rotations)
    int RCW[3][3] = {
        {1,  0,  0},
        {0,  0, -1},
        {0,  1,  0}
    };
    int RCCW[3][3] = {
        {1,  0,  0},
        {0,  0,  1},
        {0, -1,  0}
    };

    // Left face (X-axis rotations)
    int LCW[3][3] = {
        {1,  0,  0},
        {0,  0,  1},
        {0, -1,  0}
    };
    int LCCW[3][3] = {
        {1,  0,  0},
        {0,  0, -1},
        {0,  1,  0}
    };

    // Up face (Y-axis rotations)
    int UCW[3][3] = {
        { 0, 0,  1},
        { 0, 1,  0},
        {-1, 0,  0}
    };
    int UCCW[3][3] = {
        { 0, 0, -1},
        { 0, 1,  0},
        { 1, 0,  0}
    };

    // Down face (Y-axis rotations)
    int DCW[3][3] = {
        { 0, 0, -1},
        { 0, 1,  0},
        { 1, 0,  0}
    };
    int DCCW[3][3] = {
        { 0, 0,  1},
        { 0, 1,  0},
        {-1, 0,  0}
    };
};

#endif