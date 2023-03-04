# Traffic Simulation in Attiki Odos Highway
This project is a traffic simulation program written in C++. It simulates a highway with several entrances, each of which has multiple tolls. The program generates a specified number of vehicles and lets them enter the highway through the entrances and tolls. Once on the highway, the vehicles move along it at a specified speed. The program can be used to study how traffic flows and how different parameters, such as the number of vehicles, affect the flow of traffic.

### Prerequisites
This program requires a C++ compiler to build and run. The program has been tested with g++ 7.5.0 on Ubuntu.

### Running the project
To run the program, open a terminal and navigate to the directory containing the source code and header files. Then, type the following command:


```cpp
g++ -o main main.cpp classes.cpp
```
This will compile the source code and create an executable file called "main". To run the program, type the following command: 

```cpp
./main <N> <NSegs> <K> <Percent>
```
where:

- N: the number of cycles to run the simulation for
- NSegs: the number of segments on the highway
- K: the speed at which the vehicles move along the highway
Percent: the percentage of vehicles that use the automatic tolls
For example, to run the simulation for 100 cycles with 5 segments on the highway, a vehicle speed of 60 km/h, and 30% of vehicles using the automatic tolls, type the following command:

```cpp
./main 100 5 60 30
```
### Project Output
The project outputs the following information to the console:

The command-line arguments passed to the program
The number of cycles completed
A message for each vehicle that enters the highway
A message for each vehicle that exits the highway
A message for each toll that creates a vehicle
A message for each cycle completed

### Modifying the Project
The project can be modified to change the simulation parameters, such as the number of segments on the highway, the number of entrances and tolls, and the speed of the vehicles. It can also be modified to add new features, such as different types of vehicles, different types of tolls, and different types of highway segments.
