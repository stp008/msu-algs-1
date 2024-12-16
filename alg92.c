#include <stdio.h>

#define TOTAL_STUDENTS 30

// Структура для представления множества студентов
typedef struct {
    int elements[TOTAL_STUDENTS];
    int size;
} Set;

// Функция для добавления элемента в множество
void add_to_set(Set *s, int element) {
    for (int i = 0; i < s->size; i++) {
        if (s->elements[i] == element) {
            return;  // Элемент уже есть в множестве
        }
    }
    s->elements[s->size++] = element;
}

// Функция для проверки наличия элемента в множестве
int is_in_set(Set *s, int element) {
    for (int i = 0; i < s->size; i++) {
        if (s->elements[i] == element) {
            return 1;
        }
    }
    return 0;
}

// Функция для нахождения пересечения двух множеств
void intersection(Set *s1, Set *s2, Set *result) {
    result->size = 0;
    for (int i = 0; i < s1->size; i++) {
        if (is_in_set(s2, s1->elements[i])) {
            add_to_set(result, s1->elements[i]);
        }
    }
}

// Функция для нахождения пересечения трёх множеств
void intersection_three(Set *s1, Set *s2, Set *s3, Set *result) {
    Set temp;
    intersection(s1, s2, &temp);
    intersection(&temp, s3, result);
}

// Функция для нахождения разности двух множеств
void difference(Set *s1, Set *s2, Set *result) {
    result->size = 0;
    for (int i = 0; i < s1->size; i++) {
        if (!is_in_set(s2, s1->elements[i])) {
            add_to_set(result, s1->elements[i]);
        }
    }
}

// Функция для вывода множества
void print_set(Set *s) {
    for (int i = 0; i < s->size; i++) {
        printf("%d ", s->elements[i]);
    }
    printf("\n");
}

int main() {
    // Создаем множества студентов, знающих языки
    Set english = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}, 20};
    Set german = {{3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17}, 15};
    Set french = {{5, 6, 7, 8, 9, 10, 11, 12, 13, 14}, 10};

    // Находим студентов, которые знают все три языка
    Set all_languages;
    intersection_three(&english, &german, &french, &all_languages);

    printf("Студенты, которые знают все три языка:\n");
    print_set(&all_languages);

    // Находим студентов, которые не знают ни одного языка
    Set all_students;
    all_students.size = 0;
    for (int i = 1; i <= TOTAL_STUDENTS; i++) {
        add_to_set(&all_students, i);
    }

    Set known_languages;
    known_languages.size = 0;
    intersection_three(&english, &german, &french, &known_languages);

    Set not_any_language;
    difference(&all_students, &known_languages, &not_any_language);

    printf("Студенты, которые не знают ни одного языка:\n");
    print_set(&not_any_language);

    return 0;
}
