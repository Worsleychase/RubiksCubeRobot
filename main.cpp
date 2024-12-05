// main.cpp

#include <curl/curl.h>
#include <unordered_map>
#include <regex>

#include "cube.hpp"
#include "imageProcess.cpp"

#define serverIP "192.168.0.191" // Source IP for solving server (Placeholder)
#define serverPort 51420   // Port number for solving server (Placeholder)

void takeCommands();
size_t WriteCallback(void*, size_t, size_t, std::string*);
std::string getSolFromServer(std::string, int, std::string);
void trim(std::string&);

int main() {
    takeCommands();


    return 0;
}

void takeCommands() {
    virCube cube;
    std::string command;

    cube.printCube();
    std::cout << std::endl;

    std::cout << returnFaceColors();

    std::cout << "Enter commands (f,F,r,R,b,B,l,L,d,D,u,U), 'solve', 'random', or 'q' to quit:" << std::endl;

    while (true) {
        std::cout << "> ";
        std::cin >> command;
        
        if (command == "q" || command == "Q") {
            break;
        }
        
        if (command == "random" || command == "randomize") {
            int moves;
            std::cout << "How many random moves? ";
            std::cin >> moves;
            cube.randomize(moves);
            cube.printCube();
            std::cout << std::endl;
        }
        else if (command.length() == 1 && 
            (command[0] == 'f' || command[0] == 'F' ||
            command[0] == 'r' || command[0] == 'R' ||
            command[0] == 'b' || command[0] == 'B' ||
            command[0] == 'l' || command[0] == 'L' ||
            command[0] == 'd' || command[0] == 'D' ||
            command[0] == 'u' || command[0] == 'U')) {
            cube.rotateFace(command[0]);
            cube.printCube();
            std::cout << std::endl;
        } 
        else if (command == "solve") {
            if(cube.isSolved()) {
                std::cout << "Already solved." << std::endl;
            }
            else {
                // Default server address: http://localhost:51420/
                std::string solution = getSolFromServer(serverIP, serverPort, cube.getStateID());
                std::cout << solution << std::endl;
                std::cout << "Apply moves? (y/n): ";
                char apply;
                std::cin >> apply;

                if (apply == 'y' || apply == 'Y') {
                    std::cout << "Applying moves..."<< std::endl;
                    cube.applyMovesServer(solution);
                }
            }
        } 
        else if (command == "state") {
            std::cout << cube.getStateID() << std::endl;
        }
        else {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }
}

std::string getSolFromServer(std::string IP = "localhost", int port = 51420, std::string stateID = "YYYYYYYYYBBBBBBBBBOOOOOOOOOWWWWWWWWWGGGGGGGGGRRRRRRRRR") { // State ID is in the color format, NOT the server side format
    CURL* curl;
    CURLcode res;
    std::string response;
    std::string URL; 
    std::string serverFormat = "";

    std::unordered_map<char, char> translator = {
        {'Y', 'U'}, {'G', 'L'}, {'O', 'F'}, {'B', 'R'}, {'R', 'B'}, {'W', 'D'},
    };

    for (char c : stateID) {
        serverFormat += translator[c];
    }

    URL = "http://" + IP + ":" + std::to_string(port) + "/" + serverFormat;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "cURL Error: " << curl_easy_strerror(res) << std::endl;
        }

        curl_easy_cleanup(curl);
    } else {
        std::cerr << "Failed to initialize cURL" << std::endl;
    }

    size_t bodyStart = response.find("<body>");
    size_t bodyEnd = response.find("</body>");

    if (bodyStart != std::string::npos && bodyEnd != std::string::npos) {
        std::string bodyContent = response.substr(bodyStart + 6, bodyEnd - bodyStart - 6);

        size_t parenthesisPos = bodyContent.find('(');
        
        if (parenthesisPos != std::string::npos) {
            bodyContent = bodyContent.substr(0, parenthesisPos);
        }
        trim(bodyContent);
        return bodyContent;
    } 
    else {
        return "uh oh...";
    }
}

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* response) {
    response->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void trim(std::string& str) {
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));

    str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), str.end());
}