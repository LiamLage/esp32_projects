/* Author:  Liam Lage
 * Created: 15/11/2021
 *
 * Target: ESP-WROOM-32
 * 
 * Section 4  - Working With C
 * Lecture 02 - Function Pointers
 * https://learnesp32.com/videos/3/2_function%20pointers
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Person_struct: a structure containing a person's name and age
typedef struct Person_struct {
    char firstName[20];
    char lastName[20];
    int age;
} Person;

// updatePerson: fill the Person struct with values
void updatePerson(Person *person, char *dataReceived) {
    strcpy(person->firstName, "data from dataReceived");
    strcpy(person->lastName, "data from dataReceived");
    person->age = 23;
}

void connectAndGetInfo(char *url, void (*doWork)(char *dataReceived)) {
    // connect to WiFi
    // connect to endpoint
    // allocate memory
    char *dataReceived = (char *) malloc(1024);
    // fill buffer with data: getRequest(&dataReceived)
    // do work and get a person object
    doWork(dataReceived);
    // clean up memory and other resources
    free((void *) dataReceived);
}

// doWorkForPerson: call updatePerson & update values with dataReceived,
//                  print updated parameters
void doWorkForPerson(char *dataReceived) {
    Person person;
    updatePerson(&person, dataReceived);
    printf("Person: %s %s is %d years old.\n", person.firstName, person.lastName, person.age);
}

// app main: call connectAndGetInfo
void app_main(void) {
    connectAndGetInfo("https://getperson.com", doWorkForPerson);
}
