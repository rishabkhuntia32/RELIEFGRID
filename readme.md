RELIEFGRID – Emergency Resource Allocation and Priority Management System


1. Project Overview
RELIEFGRID is a menu-driven C program designed as a classroom simulation of emergency resource allocation. It stores information about affected areas, calculates a simple priority score for each area, ranks areas from highest to lowest priority, and distributes available resources in that order.

The program starts with eight sample areas. During a demonstration, users can register additional areas and enter available resource quantities.
Note: RELIEFGRID is an educational project. Its priority formula and sample data are illustrative only; they are not an official emergency-response policy or a substitute for professional emergency-management decisions.

2. Team Details
- Team Name: Team NEXORITHM
- Batch: 58
- Project: RELIEFGRID

Team Members
1. Rishab Khuntia – 590041171
2. Divyaraj Singh – 590037788
3. Aditya Singh – 590036933
3. Problem Statement

During an emergency, multiple areas may require supplies such as food, water, medical kits and blankets. When the available stock is limited, it can be difficult to decide which area should receive resources first.

RELIEFGRID provides a basic computer-based simulation that records affected areas, calculates their priority scores, ranks them and allocates available resources according to that ranking.


4. Objectives
- Register and store details of affected areas.
- Display the registered area information.
- Calculate a priority score for each area.
- Arrange areas in descending order of priority.
- Accept the available stock of four resource types.
- Allocate resources according to priority and show the quantity supplied against the quantity required.


5. Main Features
a. Preloaded sample data: Eight sample areas are loaded when the program starts.
b. Area registration: A user can register additional areas, up to the maximum capacity of ten areas.
c. Area display: The program displays the details of all registered areas.
d. Priority calculation: A score is calculated using severity, injured people, affected people and vulnerable people.
e. Priority ranking: Bubble Sort arranges the areas from highest score to lowest score.
f. Resource entry: The user enters available quantities of food packets, water units, medical kits and blankets.
g. Resource allocation: The program allocates each resource to areas in priority order, without allocating more than the available stock.
h. Allocation report: The program displays the quantity allocated and the quantity required for each resource in every area.


6. Priority Calculation
The current program uses this formula:
Score = (Severity × 10) + Injured
        + (Affected / 10) + (Vulnerable / 100)
The program limits the score to a maximum of 100.


Priority categories:
Score	Priority
75–100	Critical
50–74	High
25–49	Medium
0–24	Low


Programming note: The program uses integer variables, so divisions by 10 and 100 use integer division. The formula above matches the current source code.


7. Resources Managed
- Food packets
- Water units
- Medical kits
- Blankets

For each resource, the program compares the area's requirement with the remaining stock. It allocates the smaller of those two quantities, then updates the remaining stock before moving to the next area.


8. Program Logic / Algorithm
a. Start the program.
b. Create an array of structures to store area details.
c. Load the eight sample areas into the array.
d. Display the menu.
e. Read the user's menu choice.
f. Perform the selected operation:
   - Register an area.
   - Display all areas.
   - Calculate priority scores.
   - Sort and display the priority ranking.
   - Enter available resources.
   - Allocate resources in priority order.
   - Display the allocation report.
g. Return to the menu until the user selects Exit.
h. End the program.


9. C Concepts Used
- Header files: stdio.h and string.h
- Structure (struct Area)
- Array of structures
- One-dimensional arrays
- Character arrays (strings)
- User-defined functions and function prototypes
- printf() and scanf() for input and output
- if, else if and else
- switch-case
- for and while loops
- do-while loop
- Bubble Sort
- Basic arithmetic and comparison operators


10. Files
- RELIEFGRID.c – C source code of the project.
- README.md – Project description and instructions.
- RELIEFGRID_Presentation.pptx – Project presentation (add this file to the repository when ready).


11. Requirements
- A C compiler such as GCC.
- A terminal or command prompt.


12. How to Compile and Run
Windows (GCC)
gcc RELIEFGRID.c -o RELIEFGRID.exe
RELIEFGRID.exe
Linux / macOS (GCC)
gcc RELIEFGRID.c -o RELIEFGRID
./RELIEFGRID


13. Demonstration Steps
a. Run the program and select 2 to display the eight preloaded areas.
b. Select 1 to register another affected area during the demonstration.
c. Select 4 to display the priority ranking.
d. Select 5 to enter available resource quantities.
e. Select 6 to allocate resources.
f. Select 7 to display the allocation report.
g. Select 0 to exit.


14. Sample Test Cases
The following examples are based on the current program logic.
Test	Input / Action	Expected result
a	Start the program and select option 2	The eight preloaded areas are displayed.
b	Register an area with severity 5, 20 injured, 200 affected and 30 vulnerable people	The area is registered, provided the
     maximum of ten areas has not been reached.
c	Enter severity 6 while registering an area	The program asks again for a severity between 1 and 5.
d	Enter a negative number for an area's required resource quantity	The program asks again for a non-negative quantity.
e	Enter available stock and select option 6	Resources are allocated in descending priority order, up to the available stock.
f	Select option 7 before allocating resources	The program asks the user to allocate resources first.


Example Priority Calculation
For an area with severity 5, 20 injured people, 200 affected people and 30 vulnerable people:
Score = (5 × 10) + 20 + (200 / 10) + (30 / 100)
      = 50 + 20 + 20 + 0
      = 90
The resulting priority is Critical.


15. Limitations
- Area information is stored in program memory and is lost when the program closes.
- Area names are accepted as a single word.
- The program supports a maximum of ten areas.
- Input validation handles specified numeric ranges and negative quantities, but does not handle non-numeric input robustly.
- The priority formula is a simplified model created for this educational project.


16. Conclusion
RELIEFGRID demonstrates how basic C programming concepts can be used to build a menu-driven system for recording affected areas, ranking their priority and allocating limited resources. The project combines structures, arrays, functions, loops, conditional statements and sorting in one practical application.