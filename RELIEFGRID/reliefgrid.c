
#include <stdio.h>
#include <string.h>

#define MAX_AREAS 10

struct Area
{
    int id;
    char name[30];

    int affected;
    int injured;
    int vulnerable;
    int severity;

    int score;

    int required[4];
    int allocated[4];
};

// all the fuction prototypes
void showMenu();
int registerArea(struct Area areas[], int count);
void displayAreas(struct Area areas[], int count);
int calculatePriority(struct Area a);
void calculateAllPriorities(struct Area areas[], int count);
void sortAreas(struct Area areas[], int count);
void displayPriorityRanking(struct Area areas[], int count);
void enterResources(int stock[]);
void allocateResources(struct Area areas[], int count, int stock[]);
void displayAllocation(struct Area areas[], int count);
void loadSampleAreas(struct Area areas[]);

// this function we have created to show all the options
void showMenu()
{

    printf("RELIEFGRID SYSTEM\n");

    printf("1. Register affected area\n");
    printf("2. Display all areas\n");
    printf("3. Calculate priority scores\n");
    printf("4. Display priority ranking\n");
    printf("5. Enter available resources\n");
    printf("6. Allocate resources\n");
    printf("7. Display allocation report\n");
    printf("0. Exit\n");
}

// this fucntion to register a area
int registerArea(struct Area areas[], int count)
{
    if (count >= MAX_AREAS)
    {
        printf("\nMaximum area limit reached\n");
        return count;
    }

    areas[count].id = count + 1;

    printf("\nEnter area name (one word)\n");
    scanf("%29s", areas[count].name);

    printf("Enter total affected people\n");
    scanf("%d", &areas[count].affected);

    while (areas[count].affected < 0)
    {
        printf("Enter a valid number\n");
        scanf("%d", &areas[count].affected);
    }

    printf("Enter injured people\n");
    scanf("%d", &areas[count].injured);

    while (areas[count].injured < 0 || areas[count].injured > areas[count].affected)
    {
        printf("Enter a valid number\n");
        scanf("%d", &areas[count].injured);
    }

    printf("Enter vulnerable people\n");
    scanf("%d", &areas[count].vulnerable);

    while (areas[count].vulnerable < 0 || areas[count].vulnerable > areas[count].affected)
    {
        printf("Enter a valid number\n");
        scanf("%d", &areas[count].vulnerable);
    }

    printf("Enter severity (1 to 5)\n");
    scanf("%d", &areas[count].severity);

    while (areas[count].severity < 1 || areas[count].severity > 5)
    {
        printf("Enter severity between 1 and 5\n");
        scanf("%d", &areas[count].severity);
    }

    printf("\nEnter required resources\n");

    printf("Food packets\n");
    scanf("%d", &areas[count].required[0]);

    printf("Water units\n");
    scanf("%d", &areas[count].required[1]);

    printf("Medical kits\n");
    scanf("%d", &areas[count].required[2]);

    printf("Blankets\n");
    scanf("%d", &areas[count].required[3]);

    for (int i = 0; i < 4; i++)
    {
        while (areas[count].required[i] < 0)
        {
            printf("Enter a non-negative quantity\n");
            scanf("%d", &areas[count].required[i]);
        }

        areas[count].allocated[i] = 0;
    }

    areas[count].score = 0;

    count++;

    printf("\nArea registered successfully\n");

    return count;
}

// this funtion is to display the registered area
void displayAreas(struct Area areas[], int count)
{
    if (count == 0)
    {
        printf("\nNo areas registered yet\n");
        return;
    }

    printf("\nREGISTERED AREAS\n");

    for (int i = 0; i < count; i++)
    {
        printf("\nArea ID: %d", areas[i].id);
        printf("\nName: %s", areas[i].name);
        printf("\nAffected people: %d", areas[i].affected);
        printf("\nInjured people: %d", areas[i].injured);
        printf("\nVulnerable people: %d", areas[i].vulnerable);
        printf("\nSeverity: %d", areas[i].severity);
        printf("\n");
    }
}

// this function is our self made score giving function for sorting the area
int calculatePriority(struct Area a)
{
    int score;

    score = (a.severity * 10) + a.injured + (a.affected / 10) + (a.vulnerable / 100);

    if (score > 100)
    {
        score = 100;
    }

    return score;
}

// this function compare the score
void calculateAllPriorities(struct Area areas[], int count)
{
    for (int i = 0; i < count; i++)
    {
        areas[i].score = calculatePriority(areas[i]);
    }
}

// we used sorting to put area in decending order
void sortAreas(struct Area areas[], int count)
{
    struct Area temp;

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (areas[j].score < areas[j + 1].score)
            {
                temp = areas[j];
                areas[j] = areas[j + 1];
                areas[j + 1] = temp;
            }
        }
    }
}

// it displays the area in sorted manner
void displayPriorityRanking(struct Area areas[], int count)
{
    if (count == 0)
    {
        printf("\nNo areas registered yet\n");
        return;
    }

    printf("\nPRIORITY RANKING\n");

    for (int i = 0; i < count; i++)
    {
        printf("\nRank: %d", i + 1);
        printf("\nArea: %s", areas[i].name);
        printf("\nPriority Score: %d", areas[i].score);

        if (areas[i].score >= 75)
        {
            printf("\nPriority: CRITICAL");
        }
        else if (areas[i].score >= 50)
        {
            printf("\nPriority: HIGH");
        }
        else if (areas[i].score >= 25)
        {
            printf("\nPriority: MEDIUM");
        }
        else
        {
            printf("\nPriority: LOW");
        }

        printf("\n");
    }
}

// this fucntion is take inout of the resources
void enterResources(int stock[])
{
    printf("\nAVAILABLE RESOURCES\n");

    printf("Food packets\n");
    scanf("%d", &stock[0]);

    printf("Water units\n");
    scanf("%d", &stock[1]);

    printf("Medical kits\n");
    scanf("%d", &stock[2]);

    printf("Blankets\n");
    scanf("%d", &stock[3]);

    for (int i = 0; i < 4; i++)
    {
        while (stock[i] < 0)
        {
            printf("Enter a non-negative quantity\n");
            scanf("%d", &stock[i]);
        }
    }

    printf("\nResource stock updated successfully\n");
}

// this function allocate resources according to sorting
void allocateResources(struct Area areas[], int count, int stock[])
{
    int remaining[4];

    for (int i = 0; i < 4; i++)
    {
        remaining[i] = stock[i];
    }

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            areas[i].allocated[j] = 0;

            if (areas[i].required[j] <= remaining[j])
            {
                areas[i].allocated[j] = areas[i].required[j];
            }
            else
            {
                areas[i].allocated[j] = remaining[j];
            }

            remaining[j] = remaining[j] - areas[i].allocated[j];
        }
    }
}

// it display resource allocation
void displayAllocation(struct Area areas[], int count)
{
    printf("\nALLOCATION REPORT\n");

    for (int i = 0; i < count; i++)
    {
        printf("\nArea: %s", areas[i].name);

        printf("\nFood: %d / %d",areas[i].allocated[0], areas[i].required[0]);

        printf("\nWater: %d / %d",areas[i].allocated[1], areas[i].required[1]);

        printf("\nMedical Kits: %d / %d",areas[i].allocated[2], areas[i].required[2]);

        printf("\nBlankets: %d / %d",areas[i].allocated[3], areas[i].required[3]);

        printf("\n");
    }
}

// this is for general sampled aread for demonstration
void loadSampleAreas(struct Area areas[])
{
    // Area 1
    areas[0].id = 1;
    strcpy(areas[0].name, "Dehradun");
    areas[0].affected = 500;
    areas[0].injured = 40;
    areas[0].vulnerable = 60;
    areas[0].severity = 5;

    areas[0].required[0] = 300;
    areas[0].required[1] = 250;
    areas[0].required[2] = 50;
    areas[0].required[3] = 100;

    // Area 2
    areas[1].id = 2;
    strcpy(areas[1].name, "Rishikesh");
    areas[1].affected = 300;
    areas[1].injured = 20;
    areas[1].vulnerable = 40;
    areas[1].severity = 3;

    areas[1].required[0] = 200;
    areas[1].required[1] = 150;
    areas[1].required[2] = 30;
    areas[1].required[3] = 60;

    // Area 3
    areas[2].id = 3;
    strcpy(areas[2].name, "Haridwar");
    areas[2].affected = 700;
    areas[2].injured = 70;
    areas[2].vulnerable = 80;
    areas[2].severity = 4;

    areas[2].required[0] = 400;
    areas[2].required[1] = 350;
    areas[2].required[2] = 70;
    areas[2].required[3] = 120;

    // Area 4
    areas[3].id = 4;
    strcpy(areas[3].name, "Mussoorie");
    areas[3].affected = 200;
    areas[3].injured = 25;
    areas[3].vulnerable = 30;
    areas[3].severity = 5;

    areas[3].required[0] = 150;
    areas[3].required[1] = 100;
    areas[3].required[2] = 25;
    areas[3].required[3] = 50;

    // Area 5
    areas[4].id = 5;
    strcpy(areas[4].name, "Roorkee");
    areas[4].affected = 450;
    areas[4].injured = 30;
    areas[4].vulnerable = 50;
    areas[4].severity = 3;

    areas[4].required[0] = 250;
    areas[4].required[1] = 200;
    areas[4].required[2] = 40;
    areas[4].required[3] = 80;

    // Area 6
    areas[5].id = 6;
    strcpy(areas[5].name, "Vikasnagar");
    areas[5].affected = 250;
    areas[5].injured = 15;
    areas[5].vulnerable = 25;
    areas[5].severity = 2;

    areas[5].required[0] = 150;
    areas[5].required[1] = 120;
    areas[5].required[2] = 20;
    areas[5].required[3] = 40;

    // Area 7
    areas[6].id = 7;
    strcpy(areas[6].name, "Doiwala");
    areas[6].affected = 350;
    areas[6].injured = 35;
    areas[6].vulnerable = 45;
    areas[6].severity = 4;

    areas[6].required[0] = 220;
    areas[6].required[1] = 180;
    areas[6].required[2] = 35;
    areas[6].required[3] = 70;

    // Area 8
    areas[7].id = 8;
    strcpy(areas[7].name, "Chakrata");
    areas[7].affected = 150;
    areas[7].injured = 20;
    areas[7].vulnerable = 25;
    areas[7].severity = 5;

    areas[7].required[0] = 100;
    areas[7].required[1] = 80;
    areas[7].required[2] = 20;
    areas[7].required[3] = 35;

    for (int i = 0; i < 8; i++)
    {
        areas[i].score = 0;

        for (int j = 0; j < 4; j++)
        {
            areas[i].allocated[j] = 0;
        }
    }
}

int main()
{
    struct Area areas[MAX_AREAS];

    int count = 8;

    loadSampleAreas(areas);
    int stock[4] = {0, 0, 0, 0};

    int choice;
    int resourcesEntered = 0;
    int allocationDone = 0;

    do
    {
        showMenu();

        printf("\nEnter your choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            count = registerArea(areas, count);
            allocationDone = 0;
            break;

        case 2:
            displayAreas(areas, count);
            break;

        case 3:
            calculateAllPriorities(areas, count);
            printf("\nPriority scores calculated successfully\n");
            break;

        case 4:
            calculateAllPriorities(areas, count);
            sortAreas(areas, count);
            displayPriorityRanking(areas, count);
            break;

        case 5:
            enterResources(stock);
            resourcesEntered = 1;
            allocationDone = 0;
            break;

        case 6:
            if (count == 0)
            {
                printf("\nPlease register an area first\n");
            }
            else if (resourcesEntered == 0)
            {
                printf("\nPlease enter available resources first\n");
            }
            else
            {
                calculateAllPriorities(areas, count);
                sortAreas(areas, count);
                allocateResources(areas, count, stock);
                allocationDone = 1;
                printf("\nResources allocated successfully\n");
            }
            break;

        case 7:
            if (allocationDone == 1)
            {
                displayAllocation(areas, count);
            }
            else
            {
                printf("\nPlease allocate resources first\n");
            }
            break;

        case 0:
            printf("\nExit RELIEFGRID\n");
            break;

        default:
            printf("\nInvalid choice\n");
        }

    } while (choice != 0);

    return 0;
}
