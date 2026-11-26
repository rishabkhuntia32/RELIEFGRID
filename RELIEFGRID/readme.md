# RELIEFGRID
## Emergency Resource Allocation and Priority Management System

### 1. Project Overview

**RELIEFGRID** is a menu-driven C program developed as a classroom simulation of an emergency resource allocation system. It is designed to demonstrate how basic programming concepts can be applied to organize affected-area data, determine relative priorities, and distribute limited emergency resources systematically.

The system stores information about disaster-affected areas, calculates a priority score for each area, ranks the areas from highest to lowest priority, and allocates available resources according to this ranking.

The program begins with **eight preloaded sample areas**. During the demonstration, users can register additional affected areas and enter the available quantities of emergency resources.

> **Disclaimer:** RELIEFGRID is an educational project. The priority formula, sample data, and allocation method are simplified for classroom demonstration purposes. They do not represent an official emergency-response policy and should not be used as a substitute for professional emergency-management decisions.

---

### 2. Team Details

**Team Name:** Team NEXORITHM  
**Batch:** 58  
**Project Title:** RELIEFGRID – Emergency Resource Allocation and Priority Management System

#### Team Members

| S. No. | Name | SAP ID |
|---|---|---|
| 1 | Rishab Khuntia | 590041171 |
| 2 | Divyaraj Singh | 590037788 |
| 3 | Aditya Singh | 590036933 |

---

### 3. Problem Statement

During an emergency or disaster, several affected areas may simultaneously require essential supplies such as food, water, medical kits, and blankets. When the available resources are limited, determining which areas should receive assistance first becomes an important challenge.

A systematic method is therefore required to record information about affected areas, evaluate their level of need, establish a priority order, and distribute available resources accordingly.

**RELIEFGRID** addresses this problem through a basic computer-based simulation. It records information about affected areas, calculates a priority score for each area, ranks them according to their scores, and allocates the available resources in descending order of priority.

---

### 4. Objectives

The main objectives of RELIEFGRID are to:

- Register and store information about disaster-affected areas.
- Display the details of all registered areas.
- Calculate a priority score for each area based on selected parameters.
- Classify areas into different priority categories.
- Rank areas from highest to lowest priority.
- Accept the available stock of four essential resource types.
- Allocate resources according to the calculated priority ranking.
- Ensure that the allocated quantity does not exceed the available stock.
- Generate an allocation report showing the quantity required and supplied for each area.

---

### 5. Main Features

**a. Preloaded Sample Data**  
Eight sample affected areas are automatically loaded when the program starts, allowing the system to be demonstrated immediately.

**b. Area Registration**  
Users can register additional affected areas. The program supports a maximum of **10 areas**.

**c. Area Information Display**  
The system displays the stored details of all registered areas.

**d. Priority Calculation**  
A priority score is calculated for each area using its severity level and the number of injured, affected, and vulnerable people.

**e. Priority Classification**  
Based on the calculated score, each area is classified as **Critical, High, Medium, or Low priority**.

**f. Priority Ranking**  
The program uses **Bubble Sort** to arrange affected areas from the highest priority score to the lowest.

**g. Resource Entry**  
Users can enter the currently available quantities of food packets, water units, medical kits, and blankets.

**h. Resource Allocation**  
Resources are allocated to affected areas according to their priority ranking. The program ensures that an area cannot receive more than its requirement or more than the remaining available stock.

**i. Allocation Report**  
The program generates a report showing the quantity allocated and the quantity required for each resource in every affected area.

---

### 6. Priority Calculation

RELIEFGRID uses the following simplified formula to calculate the priority score:

**Priority Score = (Severity × 10) + Injured + (Affected / 10) + (Vulnerable / 100)**

The calculated score is limited to a maximum value of **100**.

#### Priority Categories

| Score | Priority Level |
|---|---|
| 75–100 | Critical |
| 50–74 | High |
| 25–49 | Medium |
| 0–24 | Low |

**Programming Note:**  
The program uses integer variables. Therefore, division by `10` and `100` is performed using **integer division**, meaning that any fractional part is discarded. The formula shown above reflects the behavior of the current source code.

#### Example Priority Calculation

Consider an area with:

- Severity = 5
- Injured people = 20
- Affected people = 200
- Vulnerable people = 30

The score is calculated as:

**Score = (5 × 10) + 20 + (200 / 10) + (30 / 100)**  
**Score = 50 + 20 + 20 + 0**  
**Score = 90**

Therefore, the area's priority category is **Critical**.

---

### 7. Resources Managed

RELIEFGRID manages four types of emergency resources:

1. **Food Packets**
2. **Water Units**
3. **Medical Kits**
4. **Blankets**

For each resource, the program compares an area's requirement with the remaining available stock.

The allocated quantity is:

**Allocated Quantity = Minimum(Required Quantity, Available Quantity)**

After allocation, the available stock is updated before the program proceeds to the next area in the priority ranking.

This process continues until all areas have been considered or the available stock has been exhausted.

---

### 8. Program Logic / Algorithm

The overall working of RELIEFGRID follows these steps:

1. Start the program.
2. Create an array of structures to store affected-area information.
3. Load eight predefined sample areas into the array.
4. Display the main menu.
5. Accept the user's menu choice.
6. Perform the selected operation:
   - Register a new affected area.
   - Display all registered areas.
   - Calculate priority scores.
   - Sort and display the priority ranking.
   - Enter available resource quantities.
   - Allocate resources according to priority.
   - Display the resource allocation report.
7. Return to the main menu after completing the selected operation.
8. Repeat the process until the user selects **Exit**.
9. Terminate the program.

---

### 9. C Programming Concepts Used

RELIEFGRID demonstrates several fundamental concepts of the C programming language:

- Header files: `stdio.h` and `string.h`
- Structures (`struct Area`)
- Arrays of structures
- One-dimensional arrays
- Character arrays and strings
- User-defined functions
- Function prototypes
- Input and output using `printf()` and `scanf()`
- `if`, `else if`, and `else` statements
- `switch-case` statements
- `for` loops
- `while` loops
- `do-while` loops
- Bubble Sort
- Arithmetic operators
- Comparison operators
- Basic input validation

These concepts work together to create a complete menu-driven C application.

---

### 10. Project Files

The project contains the following files:

| File | Description |
|---|---|
| `RELIEFGRID.c` | Main C source code containing the complete program |
| `README.md` | Project documentation, description, and instructions |
| `RELIEFGRID_Presentation.pptx` | Project presentation to be added to the repository when completed |

---

### 11. System Requirements

To compile and execute RELIEFGRID, the following are required:

- A C compiler such as **GCC**
- A terminal, command prompt, or compatible IDE
- Any operating system capable of running a standard C compiler

---

### 12. How to Compile and Run

#### Windows using GCC

```text
gcc RELIEFGRID.c -o RELIEFGRID.exe
RELIEFGRID.exe
```

#### Linux / macOS using GCC

```text
gcc RELIEFGRID.c -o RELIEFGRID
./RELIEFGRID
```

---

### 13. Suggested Demonstration Sequence

The following sequence can be used during the project demonstration:

**Step 1:** Run the program.

**Step 2:** Select **Option 2** to display the eight preloaded affected areas.

**Step 3:** Select **Option 1** to register an additional affected area.

**Step 4:** Select **Option 4** to calculate and display the priority ranking.

**Step 5:** Select **Option 5** to enter the available quantities of emergency resources.

**Step 6:** Select **Option 6** to allocate resources according to priority.

**Step 7:** Select **Option 7** to display the final allocation report.

**Step 8:** Select **Option 0** to exit the program.

This sequence demonstrates the major functionalities of RELIEFGRID in a logical order.

---

### 14. Sample Test Cases

The following test cases are based on the current program logic:

| Test | Input / Action | Expected Result |
|---|---|---|
| A | Start the program and select Option 2 | The eight preloaded areas are displayed. |
| B | Register an area with severity 5, 20 injured, 200 affected, and 30 vulnerable people | The area is successfully registered, provided the maximum capacity of 10 areas has not been reached. |
| C | Enter severity 6 while registering an area | The program asks the user to enter the severity again within the valid range of 1–5. |
| D | Enter a negative value for a required resource quantity | The program asks the user to enter a non-negative quantity. |
| E | Enter available resource stock and select Option 6 | Resources are allocated according to descending priority, subject to available stock. |
| F | Select Option 7 before allocating resources | The program informs the user that resources must be allocated first. |

---

### 15. Limitations

The current version of RELIEFGRID has the following limitations:

- All area information is stored temporarily in program memory and is lost when the program terminates.
- Area names are currently accepted as a single word.
- The system supports a maximum of **10 affected areas**.
- The priority calculation uses a simplified educational formula.
- The system manages only four predefined resource types.
- Numeric validation checks specified ranges and prevents negative quantities where required, but non-numeric input is not handled robustly.
- Resource allocation is based only on priority order and available quantity.
- The system does not use real-time disaster information, databases, maps, or external APIs.
- The program is a classroom simulation and is not intended for real-world emergency decision-making.

---

### 16. Future Scope

RELIEFGRID can be extended in several ways to make the system more advanced:

- Store area and resource information permanently using files or a database.
- Support multi-word area names.
- Increase or dynamically manage the number of affected areas.
- Improve input validation and error handling.
- Add more categories of emergency resources.
- Introduce more advanced priority-calculation methods.
- Add graphical visualization of affected areas.
- Develop a graphical user interface (GUI).
- Integrate location and mapping features.
- Maintain historical records of resource allocation.
- Provide alerts when critical resources fall below a specified level.
- Extend the project into a web-based or mobile emergency-management system.

---

### 17. Conclusion

**RELIEFGRID – Emergency Resource Allocation and Priority Management System** demonstrates how fundamental C programming concepts can be combined to create a practical menu-driven application.

The project records information about affected areas, calculates priority scores, ranks areas according to their level of need, manages available emergency resources, and distributes those resources systematically according to priority.

Through the implementation of **structures, arrays, functions, loops, conditional statements, input validation, and Bubble Sort**, RELIEFGRID provides a practical demonstration of core C programming concepts while addressing a simplified real-world problem.

Although the current version is intended only as an educational simulation, the project provides a strong foundation that can be expanded with persistent storage, improved algorithms, graphical interfaces, mapping systems, and more advanced resource-management features.