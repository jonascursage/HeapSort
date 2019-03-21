#ifndef HEAPSORT_H_INCLUDED
#define HEAPSORT_H_INCLUDED


typedef struct heap* Heap;
typedef struct item* Item;

Heap h_new(char* prefixo, int item);
void h_free(Heap heap);
void resize(Heap heap, int capacity);
int h_isEmpty(Heap heap);
Heap h_insert(Heap heap, char* prefixo,int item);
Heap ler_arquivo_1(Heap heap);
Heap ler_arquivo_2(Heap heap);
Heap ler_arquivo_3(Heap heap);
void h_print(Heap heap);
int menu(Heap heap);
int h_exit(Heap heap);
void h_show(Heap heap);

#endif //HEAPSORT_H_INCLUDED