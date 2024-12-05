# Rubik's Cube Solving Robot (Software)

This is a simple Rubik's Cube Solving Robot software that leverages **Herbert Kociemba's RubiksCube-TwophaseSolver** repository.  
Huge thanks to Herbert Kociemba for his work! You can find his repository [here](https://github.com/hkociemba/RubiksCube-TwophaseSolver).

I initially tried to implement my own solving algorithm in C++, but after writing about 1500 lines of code, I gave up due to performance issues. The existing two-phase solver is much faster and more efficient.

---

## Usage

### Dependencies

1. **cURL Library**  
   To install the cURL library, use **vcpkg**. For installation instructions, visit the [cURL package page](https://vcpkg.io/en/package/curl.html).  
   After installation, make sure to move the `libcurl.dll` file into the same directory where your `main.cpp` is running. If it's not in the correct location, you might encounter issues.

2. **TwophaseSolver Server**  
   Set up a simple **TwophaseSolver** server using a short Python script. Define an IP address and port on your local network or machine.  
   Update the IP and port settings in `main.cpp` accordingly. For more information, please see the [source repo](https://github.com/hkociemba/RubiksCube-TwophaseSolver).

---

### Running the Program

1. Ensure you have installed the dependencies mentioned above.
2. Set the IP and port configurations at the top of `main.cpp`.
3. Run `main.cpp` and hope it works!

---

## Hardware Setup

This project is designed to work with a physical assembly consisting of:

- **5 Servos**: Each servo is responsible for rotating a Rubik's Cube face (except for the top face). I used 360 degree servos, but you can make 180 degrees work.
- **Raspberry Pi Camera Module 2**: Positioned above the Rubik's Cube's top face. The camera is used to capture the colors of each side of the cube through a series of rotations.

---

## Software Design

My C++ code differs from Mr. Kociemba's cube representations because I started this project independently and wanted to build everything from scratch. So, I apologize if the structure of the code seems unconventional.

The cube is composed of 27 "pieces", defined in `piece.hpp`. These pieces have a 3D position array and a 3D color array, in (x,y,z) format for both. The center piece is at (0,0,0), and has no visible colors, so its color array is ('A','A','A'), where 'A' represents a null color (used for ASCII math).

Then, the cube holds all these pieces in a 3x9 array, where the first dimension (3) is the layer, starting from the front layer, meaning the entire front face, and working back. See `cube.hpp` for more information.

The cube is printed to the console as shown below:

![image](https://github.com/user-attachments/assets/b0c55e5d-5f36-4c9d-868d-fbae72b52298)

You can then execute very simple commands, see `takeCommands()` in `main.cpp` for the commands.

---

## Disclaimer

I do not take ANY credit for the OpenCV library, cURL library or Herbert Kociemba's two-phase solver. All credit for these components goes to their respective creators. The hardware and software integration in this project is the result of my own work.
