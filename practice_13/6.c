#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Course {
 int price;
 char cname[100];
};
int main() {
 // Open binary file in read mode
 FILE *ptr = fopen("file.bin", "rb");

 // store the file data
 struct Course fileData;

// Start reading the data using fread
 while (fread(&fileData, sizeof(struct
 Course), 1, ptr)) {
 printf("Course Name = %s Price = %d\n",
 fileData.cname, fileData.price);
 }

 fclose(ptr);
 return 0;
}
