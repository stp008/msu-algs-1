#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GENETIC_CODE_SIZE 64

// Структура для хранения информации о триплетах и аминокислотах
typedef struct {
    char triplet[4];   // Триплет из 3 букв + 1 для завершающего нуля
    char amino_acid[5]; // Трехбуквенное название аминокислоты
} GeneticCode;

// Генетический код для триплетов
const GeneticCode genetic_code[GENETIC_CODE_SIZE] = {
    {"TTT", "Phe"}, {"TTC", "Phe"}, {"TTA", "Leu"}, {"TTG", "Leu"},
    {"TCT", "Ser"}, {"TCC", "Ser"}, {"TCA", "Ser"}, {"TCG", "Ser"},
    {"TAT", "Tyr"}, {"TAC", "Tyr"}, {"TAA", "Stop"}, {"TAG", "Stop"},
    {"TGT", "Cys"}, {"TGC", "Cys"}, {"TGA", "Stop"}, {"TGG", "Trp"},
    {"CTT", "Leu"}, {"CTC", "Leu"}, {"CTA", "Leu"}, {"CTG", "Leu"},
    {"CCT", "Pro"}, {"CCC", "Pro"}, {"CCA", "Pro"}, {"CCG", "Pro"},
    {"CAT", "His"}, {"CAC", "His"}, {"CAA", "Gln"}, {"CAG", "Gln"},
    {"CGT", "Arg"}, {"CGC", "Arg"}, {"CGA", "Arg"}, {"CGG", "Arg"},
    {"ATT", "Ile"}, {"ATC", "Ile"}, {"ATA", "Ile"}, {"ATG", "Met"},
    {"ACT", "Thr"}, {"ACC", "Thr"}, {"ACA", "Thr"}, {"ACG", "Thr"},
    {"AAT", "Asn"}, {"AAC", "Asn"}, {"AAA", "Lys"}, {"AAG", "Lys"},
    {"AGT", "Ser"}, {"AGC", "Ser"}, {"AGA", "Arg"}, {"AGG", "Arg"},
    {"GTT", "Val"}, {"GTC", "Val"}, {"GTA", "Val"}, {"GTG", "Val"},
    {"GCT", "Ala"}, {"GCC", "Ala"}, {"GCA", "Ala"}, {"GCG", "Ala"},
    {"GAT", "Asp"}, {"GAC", "Asp"}, {"GAA", "Glu"}, {"GAG", "Glu"},
    {"GGT", "Gly"}, {"GGC", "Gly"}, {"GGA", "Gly"}, {"GGG", "Gly"}
};

// Функция для получения случайного аминокислотного остатка
const char* getRandomTriplet() {
    return genetic_code[rand() % GENETIC_CODE_SIZE].triplet;
}

// Функция для записи случайных аминокислот в файл
void writeTripletsToFile(int N, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Ошибка при открытии файла.\n");
        return;
    }

    for (int i = 0; i < N; i++) {
        const char *triplet = getRandomTriplet();
        fprintf(file, "%s", triplet);
    }

    fclose(file);
}

// Функция для подсчета количества триплетов
void countTripletsInFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Ошибка при открытии файла.\n");
        return;
    }

    // Считывание содержимого файла
    char buffer[10000];
    fread(buffer, sizeof(char), 10000, file);
    fclose(file);

    int counts[GENETIC_CODE_SIZE] = {0};

    // Подсчет триплетов
    for (int i = 0; i < strlen(buffer); i += 3) {
        // Получаем триплет
        char triplet[4] = {buffer[i], buffer[i + 1], buffer[i + 2], '\0'};

        // Ищем триплет в таблице и увеличиваем счетчик
        for (int j = 0; j < GENETIC_CODE_SIZE; j++) {
            if (strcmp(genetic_code[j].triplet, triplet) == 0) {
                counts[j]++;
                break;
            }
        }
    }

    // Вывод результатов
    for (int i = 0; i < GENETIC_CODE_SIZE; i++) {
        if (counts[i] > 0) {
            printf("Количество: %d, Триплет: %s, Наименование остатка: %s\n", counts[i], genetic_code[i].triplet, genetic_code[i].amino_acid);
        }
    }
}

int main() {
    int N;
    printf("Введите количество аминокислотных остатков (1 <= N <= 1000): ");
    scanf("%d", &N);

    if (N < 1 || N > 1000) {
        printf("Неверный ввод.\n");
        return 1;
    }

    // Шаг 1: Записать N аминокислот в файл
    writeTripletsToFile(N, "NC_sequence.txt");

    // Шаг 2: Подсчитать и вывести количество триплетов
    countTripletsInFile("NC_sequence.txt");

    return 0;
}