#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 10
typedef struct {
	char type;
	int amount;
	char unit;
} item;

item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

void produce(item *i) {
	while ((first + 1) % BUFFER_SIZE == last) {
	}
	memcpy(&buffer[first], i, sizeof(item));
	first = (first + 1) % BUFFER_SIZE;
}

item *consume() {
	item *i = malloc(sizeof(item));
	while (first == last) {
	}
	memcpy(i, &buffer[last], sizeof(item));
	last = (last + 1) % BUFFER_SIZE;
	return i;
}

int main() {
	item n1 ,n2;
	n1.type = '1';
	n1.amount = 4;
	n1.unit = 3;
	printf("Item 1: %c, %d. %c\n", n1.tyoe, n1.amount, n1.unit);
	n2.type = '2';
	n2.amount = 1;
	n2.unit = '1';
	printf("Item 2: %c, %d, %c\n", n2.type, n2.amount, n2.unit);
	printf("First = %d, Last = %d\n", first, last);
	produce(&n1);
	printf("Produce item 1:\tFirst = %d, Last = %d\n", first, last);
	produce(&n2);
	printf("Produce item 2:\tFirst = %d, Last = %d\n", first, last);
	item *consumed_item = consume();
	printf("Consumed item: %c, %d, %c\tFirst = %d, Last = %d\n", consumed_item->type, 		consumed_item->amount, consumed_item->unit, first, last);
	return 0;
}
