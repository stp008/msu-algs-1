#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DNA_LENGTH 3000
#define NUCLEOTIDES "ACGT"
#define GENETIC_CODE_SIZE 64
#define AMINO_ACID_GROUPS 4
#define AMINO_ACID_GROUP_SIZE 8

typedef struct {
    char triplet[4];  // Триплет нуклеотидов
    char amino_acid[5];  // Аминокислота (3 буквы)
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

// Группы аминокислот
const char* amino_acid_groups[AMINO_ACID_GROUPS][AMINO_ACID_GROUP_SIZE] = {
    {"Ala", "Gly", "Phe", "Val", "Ile", "Leu", "Pro", "Met"},
    {"Asn", "Ser", "Cys", "Gln", "Thr", "Tyr"},
    {"Arg", "Lys", "His"},
    {"Asp", "Glu"}
};

// Функция для поиска аминокислоты по триплету
const char* get_amino_acid(const char* triplet) {
    for (int i = 0; i < GENETIC_CODE_SIZE; i++) {
        if (strcmp(genetic_code[i].triplet, triplet) == 0) {
            return genetic_code[i].amino_acid;
        }
    }
    return "Неизвестная группа";  // Если триплет не найден
}

// Функция для нахождения группы аминокислоты
int get_amino_acid_group(const char* amino_acid) {
    for (int i = 0; i < AMINO_ACID_GROUPS; i++) {
        for (int j = 0; j < AMINO_ACID_GROUP_SIZE && amino_acid_groups[i][j] != NULL; j++) {
            if (strcmp(amino_acid, amino_acid_groups[i][j]) == 0) {
                return i;
            }
        }
    }
    return -1;  // Если не найдено
}

// Функция для генерации мутации для одного символа триплета
char generate_mutated_char(char original_char) {
    char new_char;
    do {
        new_char = NUCLEOTIDES[rand() % 4];  // Случайно выбираем новый символ
    } while (new_char == original_char);  // Повторяем, пока новый символ не будет отличаться
    return new_char;
}

// Функция для мутации ДНК
void mutate_dna(char* dna, int mutation_count) {
    int len = strlen(dna);
    for (int i = 0; i < mutation_count; i++) {
        int pos = rand() % (len - 2);  // Позиция для триплета
        char original_triplet[4];
        strncpy(original_triplet, dna + pos, 3);
        original_triplet[3] = '\0';

        // Мутация: изменение одного символа в триплете
        char mutated_triplet[4];
        strcpy(mutated_triplet, original_triplet);

        int mutate_pos = rand() % 3;  // Выбираем случайную позицию для мутации
        mutated_triplet[mutate_pos] = generate_mutated_char(mutated_triplet[mutate_pos]);

        // Определяем аминокислоту до и после мутации
        const char* original_aa = get_amino_acid(original_triplet);
        const char* mutated_aa = get_amino_acid(mutated_triplet);

        // Определяем группы аминокислот
        int original_group = get_amino_acid_group(original_aa);
        int mutated_group = get_amino_acid_group(mutated_aa);

        // Выводим информацию о мутации
        printf("Номер позиции триплета: %d\n", pos / 3 + 1);
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

int main() {
    FILE *file = fopen("NC_sequence.txt", "r");
    if (file == NULL) {
        printf("Ошибка при открытии файла.\n");
        return 1;
    }

    char dna[MAX_DNA_LENGTH];
    fgets(dna, MAX_DNA_LENGTH, file);
    fclose(file);

    int mutation_count;
    printf("Введите количество мутаций: ");
    scanf("%d", &mutation_count);
    printf("\n");

    mutate_dna(dna, mutation_count);

    return 0;
}
