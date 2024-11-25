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
   Update the IP and port settings in `main.cpp` accordingly.

---

### Running the Program

1. Ensure you have installed the dependencies mentioned above.
2. Set the IP and port configurations at the top of `main.cpp`.
3. Run `main.cpp` and hope it works!

---

## Hardware Setup

This project is designed to work with a physical assembly consisting of:

- **5 Servos**: Each servo is responsible for rotating a Rubik's Cube face (except for the top face). The servos should have 360-degree rotation capabilities.
- **Raspberry Pi Camera Module 2**: Positioned above the Rubik's Cube's top face. The camera is used to capture and analyze the colors of each side of the cube through a series of rotations.

---

## Disclaimer

I do not take ANY credit for the cURL library or Herbert Kociemba's two-phase solver. All credit for these components goes to their respective creators. The hardware and software integration in this project is the result of my own work.
