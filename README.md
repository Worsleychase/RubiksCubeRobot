# Rubik's Cube Solving Robot

This project started as a university project for my modern electronics class. Our requirements were simple:
1. Take in some form of data
2. Do some sort of processing/calculation with the data
3. Output something based on these calculations

Here it is in action solving a Rubik's cube:
https://www.youtube.com/shorts/5jGwbwq_Clw

So, this is a simple Rubik's Cube Solving Robot software that leverages **Herbert Kociemba's RubiksCube-TwophaseSolver** repository, [wiringPi](https://github.com/WiringPi/WiringPi), [OpenCV](https://opencv.org), [cURL](https://curl.se), and [libcamera](https://libcamera.org).
Huge thanks to Herbert Kociemba for his work! You can find his repository [here](https://github.com/hkociemba/RubiksCube-TwophaseSolver).
Also big thanks to everyone who contributed to the libraries above.

I initially tried to implement my own solving algorithm in C++, but after writing about 1500 lines of code, I gave up due to performance issues. The existing two-phase solver is much faster and more efficient.

---

## Hardware Setup

If you'd like to assemble the project and use the code to control it, the files needed are in the DIY folder of the repo. However, you are 100% able to run this without making the robot itself, you can simply use it as a digital cube if you'd like. 

In the DIY folder, there is a .zip containing all the SolidWorks parts and STLs for the robot. There is also a spreadsheet that has all the parts we used. I will note that top arch on the assembly looks incorrect because I needed to extend it for our actual robot (engineering mishaps).

---

## Usage

Note: This was all run and installed on a Raspberry Pi 4 (4GB) with Raspbian (Raspberry Pi OS)

### Dependencies

1. **OpenCV**
   To install OpenCV on Linux, follow their tutorial [here](https://docs.opencv.org/4.x/d7/d9f/tutorial_linux_install.html).
   
2. **libcamera**
	To install libcamera on Linux, follow their instructions [here](https://libcamera.org/getting-started.html). For testing/debugging the camera, I used the libcamera--still command.

3. **cURL (libcurl)**  
   To install the cURL library, run the following commands:
   ```bash
   sudo apt update
   sudo apt upgrade
   sudo apt install libcurl4-openssl-dev
   curl --version

4. **wiringPi**
	To install wiringPi, run the following commands:
	```bash
	# fetch the source
	sudo apt install git
	git clone https://github.com/WiringPi/WiringPi.git
	cd WiringPi

	# build the package
	./build debian
	mv debian-template/wiringpi-3.0-1.deb .

	# install it
	sudo apt install ./wiringpi-3.0-1.deb

5. **TwophaseSolver Server**  
   Set up a simple **TwophaseSolver** server using a short Python script. Define an IP address and port on your local network or machine.  
   Update the IP and port settings in `main.cpp` accordingly. For more information, please see the [source repo](https://github.com/hkociemba/RubiksCube-TwophaseSolver).

---

### Running the Program

1. Ensure you have installed the dependencies mentioned above.
2. Clone the GitHub repo to some folder:
	```bash
	git clone https://github.com/Worsleychase/RubiksCubeRobot.git
	cd RubiksCubeSolver

3. Set the IP and port configurations at the top of `main.cpp`.
4. Run the following commands to make/build the program:
	```bash
	cd build
	cmake ..
	make # Note: The "make" command compiles the code, so if you make any changes be sure to run that command again.

5. Run the program and hope!
	```bash
	./rubikSolver

For all commands, consult the `main.cpp` takeCommands() function. Here is short list of the commands:

	- 'connect': Connects the program to the robot, only use this if you have the robot built 
	- 'solve': Sends HTTP request to server (make sure the server is set up before running)
	- 'scan': Scans the Rubik's cube with the camera on top, takes about 40 moves to complete
	- 'random': Prompts for # of moves, don't do to many if you are connected

---

## Disclaimer

I do not take ANY credit for OpenCV, cURL, wiringPi, libcamera, or Herbert Kociemba's two-phase solver. All credit for these components goes to their respective creators. The hardware and software integration in this project is the result of my own work.

This project is intended for educational purposes only.
