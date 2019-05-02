# cmsc240_s2019_final_trafficJam

Final Project CMSC 240 Spring 2019

Authors:
    Allie Davidge
    Suvinay Bothra
    Ting Chen

The following program simulates a traffic intersection with randomly arriving
and turning cars.


Compilation:

In order to compile the program, all you need to do is enter the command "make"
in the project directory which uses our provided makefile. This creates the 
object files and links them in order to produce the executable file named
"Simulation".


Execution:

In order to execute the program, run the executable file with the following command
format:

./Simulation [name of input file] [boolean value of whether or not to have keystroke pauseability]

If the user inputs a boolean value of true, the program prompts the user the press enter to 
begin the simulation and thereafter can advance the time by one unit through each additional
press on the enter key. The program continues until it reaches the maximum simulated time, 
specified in the input file. If the user inputs a boolean value of true, the program advances
each clock tick every 200 milliseconds until again it reaches the maximum simulated time.

The input file must contain the following information in the order as this example:
maximum_simulated_time:                 1000

number_of_sections_before_intersection:   10

green_north_south:                        12

yellow_north_south:                        3

green_east_west:                          12

yellow_east_west:                          3

prob_new_vehicle_northbound:               0.1

prob_new_vehicle_southbound:               0.1

prob_new_vehicle_eastbound:                0.15

prob_new_vehicle_westbound:                0.15

proportion_of_cars:                        0.6

proportion_of_SUVs:                        0.3

prob_right_turn_cars:                      0.4

prob_left_turn_cars:                       0.1

prob_right_turn_SUVs:                      0.3

prob_left_turn_SUVs:                       0.05

prob_right_turn_trucks:                    0.2

prob_left_turn_trucks:                     0.02


Traffic-related design decisions: 

Most of our traffic related decisions revolve around our Intersection class.
Turns and going straight are handled by the logic of the intersection, the only
thing that the driver and container classes (Simulation.cpp and Roadways) has
to do are specify the ultimate direction of the vehicle's destination. 

When progressing through the traffic light, we calculate the amount 
of section of the vehicle still left to pass through the intersection. If 
there is not enough time left on the green light, to pass through the whole 
vehicle, the vehicle stops. All vehicles stop at yellow and red lights.

Advancing the lane up to the traffic light is handled by the Lane class
and is straight forward. When the traffic light is green for that lane,
advance all section by one. When the traffic light is red for that lane,
advance up to the traffic light so that vehicles begin to pile up but never
overlap.

Arrivals are also handled by the Lane's class and would proceed as you would expect,
with vehicles coming into a lane one section at a time and the rest of the vehicle held
in a buffer. Once the lane has become full however, we throw out any additional arrivals.

Unfortunately, we did not have the time to implement the left turn, but if we were to
the only things we would need to modify are the Intersection's internal logic to add
the third possibility as well as the Roadway's method of determining what direction a
spawned vehicle will ultimately advance to. 


OOP design decisions:

Our class design starts with the driver class, Simulation.cpp, which reads in the inputs
and creates the container class Roadways and advances the simulation up until the maximum
simulated time parameter.

The container class, Roadways, contains a vector of lanes, two traffic lights, an animator,
and an intersection in order to be the main body of the simulation. The advancing of the 
simulation is done in this class, as well as the randomness of vehicle arrivals and outcomes.
All of the many factors in the simulation interact here.

The Animator class is used in the container class and visuals the simulation just by drawing the 
lanes, the vehicles, and the traffic lights.

The TrafficLight class handles the timing of the traffic lights, holding green, yellow, and
red times and updating their colors accordiningly.

The Lane class represented one of the 8 lanes of an intersection, not including the actual
intersection in the middle. It is made up of a vector of sections and can advance the vehicle
pointers in those sections.

The Intersection class is where most of the logic of the simulation occurs. This class allows 
for easy right turns and going straight of the vehicles. One central design feature is that
this class is made up of a vector of sections and are thus numbered in the following order:

    -----------------
    |       |       |
    |   0   |   1   |
    |       |       |
    -----------------
    |       |       |
    |   2   |   3   | 
    |       |       |
    -----------------

These numberings of the sections are essential to the design of the class and are used extensively
in pairs depending on what direction the vehicle in traveling in.

The Section Class represents each section of the lane and contains a vehicle pointer as well as
information about whether it is occupied by a real vehicle or not.

Finally the VehicleBase class represents the actual vehicle. This class contains information on the 
direction the vehicle is headed, the size of the vehicle, the type of vehicle, and the id of the vehicle,
We use pointers of the VehicleBase class throughout the simulation.
    
