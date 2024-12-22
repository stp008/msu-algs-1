#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

#define MAX_DNA_LENGTH 3000
#define GENETIC_CODE_SIZE 64

typedef struct {
    char triplet[4];  // Триплет нуклеотидов
    char amino_acid[5];  // Аминокислота
} GeneticCode;

// Массив возможных замен для каждого нуклеотида
const char nucleotides[4][3] = {
    {'C', 'G', 'T'}, // Для 'A'
    {'A', 'G', 'T'}, // Для 'C'
    {'A', 'C', 'T'}, // Для 'G'
    {'A', 'C', 'G'}  // Для 'T'
};

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

// Функция для поиска аминокислоты по триплету
const char* get_amino_acid(const char* triplet) {
    for (int i = 0; i < GENETIC_CODE_SIZE; i++) {
        if (strcmp(genetic_code[i].triplet, triplet) == 0) {
            return genetic_code[i].amino_acid;
        }
    }
    return "Unknown";  // Если триплет не найден
}

// Функция для генерации мутации для одного символа триплета
char generate_mutated_char(char original_char) {
    int index;
    switch (original_char) {
        case 'A': index = 0; break;
        case 'C': index = 1; break;
        case 'G': index = 2; break;
        case 'T': index = 3; break;
        default: return original_char; // Если символ не распознан, возвращаем его же
    }
    return nucleotides[index][rand() % 3];
}

// Функция для внесения мутаций
void mutate_dna(char* dna, int mutation_count) {
    int len = strlen(dna);
    srand(time(NULL));
    for (int i = 0; i < mutation_count; i++) {
        int pos = rand() % len;
        dna[pos] = generate_mutated_char(dna[pos]);
    }
}

// Функция для сравнения оригинальной и мутированной ДНК
void compare_dna(const char* original_dna, const char* mutated_dna) {
    int len = strlen(original_dna);

    printf("\nИнформация о мутациях:\n\n");
    for (int i = 0; i < len - 2; i += 3) {
        char original_triplet[4], mutated_triplet[4];
        strncpy(original_triplet, original_dna + i, 3);
        strncpy(mutated_triplet, mutated_dna + i, 3);
        original_triplet[3] = '\0';
        mutated_triplet[3] = '\0';

        if (strcmp(original_triplet, mutated_triplet) != 0) {
            const char* original_aa = get_amino_acid(original_triplet);
            const char* mutated_aa = get_amino_acid(mutated_triplet);
            int original_group = (original_aa != NULL) ? original_aa[0] : -1;
            int mutated_group = (mutated_aa != NULL) ? mutated_aa[0] : -1;

            printf("Номер позиции триплета: %d\n", i / 3 + 1);
            printf("Триплет до мутации: %s → %s\n", original_triplet, original_aa);
            printf("Группа до мутации: %d\n", original_group + 1);
            printf("Триплет после мутации: %s → %s\n", mutated_triplet, mutated_aa);
            printf("Группа после мутации: %d\n", mutated_group + 1);

            if (original_group == mutated_group) {
                printf("Свойства остатка не изменились после мутации.\n");
            } else {
                printf("Мутация привела к изменению свойств остатка.\n");
            }
            printf("\n");
        }
    }
}

//gcc -o dna_mutation dna_mutation.c -DTESTS
#ifdef TESTS
void test_get_amino_acid() {
    assert(strcmp(get_amino_acid("TTT"), "Phe") == 0);
    assert(strcmp(get_amino_acid("TAC"), "Tyr") == 0);
    assert(strcmp(get_amino_acid("AAA"), "Lys") == 0);
    assert(strcmp(get_amino_acid("ZZZ"), "Unknown") == 0);
    printf("get_amino_acid тест пройден.\n");
}

void test_generate_mutated_char() {
    char bases[] = {'A', 'C', 'G', 'T'};
    for (int i = 0; i < 4; i++) {
        char mutated = generate_mutated_char(bases[i]);
        switch (bases[i]) {
            case 'A':
                assert(mutated == 'C' || mutated == 'G' || mutated == 'T');
                break;
            case 'C':
                assert(mutated == 'A' || mutated == 'G' || mutated == 'T');
                break;
            case 'G':
                assert(mutated == 'A' || mutated == 'C' || mutated == 'T');
                break;
            case 'T':
                assert(mutated == 'A' || mutated == 'C' || mutated == 'G');
                break;
            default:
                assert(0 && "Invalid base");
        }
    }
    printf("generate_mutated_char пройден");
}

void test_mutate_dna() {
    char dna[MAX_DNA_LENGTH] = "TTTCCCAAAGGG";
    char original_dna[MAX_DNA_LENGTH];
    strcpy(original_dna, dna);

    int mutation_count = 3;
    mutate_dna(dna, mutation_count);

    // Проверка, что ДНК изменилась
    int mutation_changes = 0;
    for (int i = 0; i < strlen(dna); i++) {
        if (dna[i] != original_dna[i]) {
            mutation_changes++;
        }
    }

    assert(mutation_changes == mutation_count);
    printf("mutate_dna тест пройден.\n");
}

void test_compare_dna() {
    char original_dna[MAX_DNA_LENGTH] = "TTTCCCAAAGGG";
    char mutated_dna[MAX_DNA_LENGTH] = "TTTCCGAAAGGG";
    compare_dna(original_dna, mutated_dna);
    printf("compare_dna небходтима визуальная проверка.\n");
}

int main() {
    test_get_amino_acid();
    test_generate_mutated_char();
    test_mutate_dna();
    test_compare_dna();
    printf("All tests passed.\n");
    return 0;
}
#endif

#ifndef TESTS
int main() {
    FILE* file = fopen("NC_sequence.txt", "r");
    if (file == NULL) {
        printf("Ошибка при открытии файла.\n");
        return 1;
    }

    char original_dna[MAX_DNA_LENGTH];
    fgets(original_dna, MAX_DNA_LENGTH, file);
    fclose(file);

    char mutated_dna[MAX_DNA_LENGTH];
    strcpy(mutated_dna, original_dna);

    int mutation_count;
    printf("Введите количество мутаций: ");
    scanf("%d", &mutation_count);

    mutate_dna(mutated_dna, mutation_count);

    compare_dna(original_dna, mutated_dna);

    return 0;
}
#endif
