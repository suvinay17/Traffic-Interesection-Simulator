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

OOP design design decisions:
