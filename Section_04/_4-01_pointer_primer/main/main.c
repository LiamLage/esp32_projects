/* Author:  Liam Lage
 * Created: 15/11/2021
 *
 * Target: ESP-WROOM-32
 * 
 * Section 4  - Working With C
 * Lecture 01 - Structure & Pointer Primer
 * https://learnesp32.com/videos/3/1_structure%20and%20pointer%20primer 
 * */

#include <stdio.h>
#include <string.h>
#include "esp_log.h"

// void updatePerson(Person person);

typedef struct Person_struct {
    char firstName[20];
    char lastName[20];
    int age;
} Person;

// updatePerson: populate Person struct with updated values
void updatePerson(Person *person) {
    strcpy(person->firstName, "Liam"); // because person is a pointer, we use -> instead of the . operator
    strcpy(person->lastName, "Lage");
    person->age = 23;
}

// exclaimIt: concatenate '!' to the end of the input arg
void exclaimIt(char *phrase) {
    strcat(phrase, "!");
}

void app_main(void) {
    Person person;
    char phrase[20] = {"hello world"};
    
    exclaimIt(phrase);
    printf("function output: %s\n", phrase);

    updatePerson(&person);  // we are passing the actual memory address of person
    printf("Person: %s %s is %d years old.\n", person.firstName, person.lastName, person.age);
    ESP_LOGI("TAG", "Person: %s %s is %d years old.", person.firstName, person.lastName, person.age);
}