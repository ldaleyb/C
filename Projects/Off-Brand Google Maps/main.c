/*This program creates a map with several sub-categories in the form 
of a linked list. Each map has a name and contains a pointer to the 
head of a category. Each category has a name, pointer to the next 
category in the linked list, and a pointer to the head of a business. 
Each business contains a name, number of employees, and a pointer to 
the next business in the linked list. The program automatically 
creates a map, and several sub-categories and businesses using malloc(), as well as
deletes several sub-categories and businesses using free(). Example test.txt was 
for programmer use to determine an output template and can be ignored.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define structs
typedef struct _map Map;
typedef struct _category Category;
typedef struct _business Business;

struct _map {
    char* name;
    Category* category_head;
};

struct _category {
    char* name;
    Business* business_head;
    Category* next;
};

struct _business {
    char* name;
    int num_employees;
    Business* next;
};

// Create a new map
Map* newMap(char* name) {
    Map *createMap = (Map*)malloc(sizeof(Map));
    createMap->category_head = NULL; 
    createMap->name = strdup(name);
    return createMap;
}

// Add a category to the list in proper lexicographical order
// Returns 1 if the category is already in the map, else returns 0
int addCategory(Map* map, char* name) {
    Category *curr = map->category_head;
    Category *prev = NULL;
    while (curr && strcmp(name, curr->name) >= 0) {
        prev = curr;
        curr = curr->next; 
    }
    if (prev && strcmp(prev->name, name) == 0) {
        return 1;
    }

    Category *newCategory = (Category*)malloc(sizeof(Category));
    newCategory->business_head = NULL;
    newCategory->name = strdup(name);
    newCategory->next = NULL;
    if (!prev) {
        map->category_head = newCategory;
    }
    else {
        prev->next = newCategory;
    }
    newCategory->next = curr;

   return 0;
}

// Add a business to the map sorted by number of employees descending
// Returns 1 if the category does not exist, else returns 0
int addBusiness(Map* map, char* category, char* name, int num_employees) {
    Category *currC = map->category_head;

    while (currC && strcmp(currC->name, category) != 0) {
        currC = currC->next;
    }
    if (!currC) return 1;

    Business *currB = currC->business_head;
    Business *prevB = NULL;
    while (currB && strcmp(currB->name, name) != 0) {
        prevB = currB;
        currB = currB->next;
    }
    if (currB) {//if business exists, delete and insert below
        if (!prevB) {
            currC->business_head = currB->next;
        }
        else {
            prevB->next = currB->next;
        }
        free(currB->name);
        free(currB);
    }

    Business *new = (Business*)malloc(sizeof(Business));
    new->name = strdup(name);
    new->num_employees = num_employees;
    new->next = NULL;

    currB = currC->business_head;
    prevB = NULL;
    while (currB && currB->num_employees >= new->num_employees) {
        prevB = currB;
        currB = currB->next; 
    }
    if (!prevB) {
        currC->business_head = new;
    }
    else {
        prevB->next = new;
    }
    new->next = currB;
    
    return 0;
}

// Display all the categories and businesses in a map
void display(Map* map) {
    if (map->category_head == NULL) {
        printf("%s\nMap is empty", map->name);
    }
    else {
        printf("%s\n", map->name);
        Category *ptr = map->category_head;
        while (ptr) {
            printf("%s: ", ptr->name);
            Business *curr = ptr->business_head;
            if (curr) {
            while (curr) {
                printf("%s (%d)", curr->name, curr->num_employees);
                if (curr->next) printf(", "); 
                curr = curr->next;
                }
            }
            else printf("Empty");
            printf("\n");
            ptr = ptr->next;
        }
    }
}

// Remove the business from the list.
// If the category does not exists, return 1. If the business does not exists, return 2.
// Else, removes the business and return 0.
int removeBusiness(Map* map, char* category, char* name) {
    Category *ptrC = map->category_head;
    while (ptrC && strcmp(ptrC->name, category) != 0) {
        ptrC = ptrC->next;
    }
    if (!ptrC) return 1;

    Business *currB = ptrC->business_head;
    Business *prevB = NULL;
    while (currB && strcmp(currB->name, name) != 0) {
        prevB = currB;
        currB = currB->next;
    }
    if (!currB) return 2;
    
    if (!prevB) {
        ptrC->business_head = currB->next;
    }
    else {
        prevB->next = currB->next;
    }
    free(currB->name);
    free(currB);
    return 0;
}

// Remove the category with provided name
// If the category doesn't exist, returns 1, else, removes the category and returns 0
int removeCategory(Map* map, char* name) {
    Category *currC = map->category_head;
    Category *prevC = NULL;
    while (currC && strcmp(currC->name, name) != 0) {
        prevC = currC;
        currC = currC->next;
    }
    if (!currC) return 1;

    Business *currB = currC->business_head;
    while (currB) {
        Business *nextB = currB->next;
        free(currB->name);
        free(currB);
        currB = nextB;
    }

    if (!prevC) {
        map->category_head = currC->next;
    }
    else {
        prevC->next = currC->next;
    }
    free(currC->name);
    free(currC);
    return 0;
}

// Returns the number of businesses in a category with at least min_employees and no more than max_employees
// Returns -1 if the category does not exist
int countBusinesses(Map* map, char* category, int min_employees, int max_employees) {
    int count = 0;
    Category *ptrC = map->category_head;
    while (ptrC) {
        if (strcmp(ptrC->name, category) == 0) {
            Business *ptrB = ptrC->business_head;
            while (ptrB) {
                if ((ptrB->num_employees >= min_employees) && (ptrB->num_employees <= max_employees)) {
                    count++;
                }
                ptrB = ptrB->next;
            }
            return count;
        }
        ptrC = ptrC->next;
    }
    return -1;
}

int main() {

     Map* map = newMap("TV City");

     addCategory(map, "Office");
     addBusiness(map, "Office", "Dunder Mifflin Utica", 10);
     display(map);
     printf("-----\n");

     addBusiness(map, "Office", "Dunder Mifflin Scranton", 19);

     display(map);
      printf("-----\n");
    
      addCategory(map, "Food and Drink");
      addBusiness(map, "Food and Drink", "Jasmine Dragon", 7);

     addCategory(map, "Hospitals");
     addBusiness(map, "Hospitals", "Princeton-Plainsboro Teaching Hospital", 8672);
     addBusiness(map, "Hospitals", "Seattle Grace Hospital", 6824);

     addCategory(map, "Gas");

     display(map);
     printf("-----\n");

    removeCategory(map, "Food and Drink");

     display(map);
     printf("-----\n");

     removeBusiness(map, "Hospitals", "Princeton-Plainsboro Teaching Hospital");

     display(map);
     printf("-----\n");

     printf("Number of very small office businesses: %d\n", countBusinesses(map, "Office", 0, 10));

 }

 