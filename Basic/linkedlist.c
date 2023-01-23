#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _student {
    char *name;
    double gpa;
    struct _student *next;
} Student;

Student *createStudent(char name[], double gpa, Student *next) {
    Student *pNew = malloc(sizeof(Student));
    pNew->name = malloc(strlen(name) + 1);
    strcpy(pNew->name, name);
    pNew->gpa = gpa;
    pNew->next = next;
    return pNew;
}

int compareStudents(Student *pNew, Student *pExisting) {
    if (pNew->gpa>pExisting->gpa) return -1;
	if (pNew->gpa<pExisting->gpa) return 1;
	return strcmp(pNew->name, pExisting->name);
    return -1;
}

Student *add(Student *head, char name[], double gpa) {
    for (Student *ptr=head; ptr!=NULL; ptr=ptr->next) {
		if (strcmp(name, ptr->name)==0) {
			printf("Student named %s exists.\n", name);
			return head;
		}
	}
	Student *pNew=createStudent(name, gpa, NULL);
	if (head==NULL) return pNew;
	if (compareStudents(pNew, head)<0) {
		pNew->next=head;
		return pNew;
	}
	for (Student *ptr=head; ptr!=NULL; ptr=ptr->next) {
		if (ptr->next==NULL) {
			ptr->next=pNew;
			return head;
		}
		if (compareStudents(pNew, ptr->next)<0) {
			pNew->next=ptr->next;
			ptr->next=pNew;
			return head;
		}
	}
    return NULL;
}

void print(char prefix[], Student *head) {
    printf("%s", prefix);
    for (Student *ptr = head; ptr != NULL; ptr = ptr->next)
        printf("[%s-%g] ", ptr->name, ptr->gpa);
    printf("\n");
}

double getGPA(Student *head, char name[]) {
    for (Student *ptr=head; ptr!=NULL; ptr=ptr->next) {
		if (strcmp(name, ptr->name)==0) return ptr->gpa;
	}
    return -1.0;
}

int main(void) {
    char name[100];
    double gpa;
    Student *head = NULL;
    while (1) { // build the list
        printf("\nEnter a name (one word) and gpa, or xxx and 0 to exit: ");
        scanf("%s%lf", name, &gpa);
        if (strcmp(name, "xxx") == 0) break;
        head = add(head, name, gpa);
        print("\n\tNow the list is: ", head);
    }
    while (1) { // perform search
        printf("\nEnter a name to look up the gpa or xxx to exit: ");
        scanf("%s", name);
        if (strcmp(name, "xxx") == 0) break;
        gpa = getGPA(head, name);
        if (gpa < 0)
            printf("\n\t%s does not exist\n", name);
        else
            printf("\n\t%s has a GPA of %g\n", name, gpa);
    }
    return 0;
}