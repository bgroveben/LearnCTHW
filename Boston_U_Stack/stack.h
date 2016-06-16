// Prototypes for each stack function go here

typedef char stackElementT;  /* Give it a generic name--makes  */
                             /* changing the type of things in */
                             /* the stack easy.                */
typedef struct {
    stackElementT *contents  // contents is a pointer since it will be dynamically allocated
    int top;
    int maxSize;  // maximum size of the array is determined at run-time (not compile time) 
} stackT;
