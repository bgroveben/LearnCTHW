// Exercise 17: Heap And Stack Memory Allocation
// Create an entire small program to manage a (very simple) database

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>  // Macros reporting error conditions
#include <string.h> // String handling

// The #define directive takes two forms: defining a constant and creating a macro
// http://tigcc.ticalc.org/doc/cpp.html GNU C Preprocessor
#define MAX_DATA 512
#define MAX_ROWS 100
// It looks like these are constants

// In ex16, Zed says that structs are 'similar to a record in a database table'.
struct Address {
    int id;
    int set;
    char name[MAX_DATA];
    char email[MAX_DATA];
};

struct Database {
    struct Address rows[MAX_ROWS];
};

struct Connection {
    // Remember, if you add a * directly before a variable name, it will declare the variable to be a pointer
    FILE *file;
    // *ptr means 'the value of whatever ptr is pointed at'
    struct Database *db;
    // Also remember to assign a pointer to memory address before using it
};

void die(const char *message)
// The die() function is used to quit your script and display a message for the user to read
{
    if(errno) {
        // Check linux man pages for errno(3)
        perror(message);
        // The C library function void perror(const char *str) prints a descriptive error message to stderr
    } else {
        printf("ERROR: %s\n", message);
    }
    // https://stackoverflow.com/questions/9944785/what-is-the-difference-between-exit0-and-exit1-in-c
    exit(1);  // aka EXIT_FAILURE, although it does not have to be a 1
    // The C standard defines EXIT_FAILURE as the standard value for returning unsuccessful termination
}

void Address_print(struct Address *addr)
{
    printf("%d %s %s\n",
            addr->id, addr->name, addr->email);
            // The -> operator lets us access a member of the structure pointed to by a pointer
            // https://www.cs.cf.ac.uk/Dave/C/node10.html -- pointers on pointers...Yeah, I said it.
}

void Database_load(struct Connection *conn)
{
    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
    // fread() reads data from conn->file into the array conn->db
    // size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)
    // http://www.tutorialspoint.com/c_standard_library/c_function_fread.htm
    if(rc != 1) die("Failed to load database.");
}

struct Connection *Database_open(const char *filename, char mode)
{
    struct Connection *conn = malloc(sizeof(struct Connection));
    if(!conn) die("Memory error");

    conn->db = malloc(sizeof(struct Database));
    if(!conn->db) die("Memory error");

    if(mode == 'c') {
        // c=create, g=get, s=set, d=del, l=list
        conn->file = fopen(filename, "w");
    } else {
        conn->file = fopen(filename, "r+");

        if(conn->file) {
            Database_load(conn);
        }
    }

    if(!conn->file) die("Failed to open the file");

    return conn;
}

void Database_close(struct Connection *conn)
{
    if(conn) {
        if(conn->file) fclose(conn->file);
        // fclose(3) - closes the given file stream
        if(conn->db) free(conn->db);
        free(conn);
        // The C library function void free(void *ptr) deallocates the memory previously
        // allocated by a call to calloc, malloc, or realloc
    }
}

void Database_write(struct Connection *conn)
{
    rewind(conn->file);
    // The C library function void rewind(FILE *stream) sets the file position to the beginning
    // of the file of the given stream

    int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
    // size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
    // writes data from the array pointed to by ptr to the given stream
    if(rc != 1) die("Failed to write database.");

    rc = fflush(conn->file);
    // int fflush(FILE *stream) flushes the output buffer of a stream
    if(rc == -1) die("Cannot flush database.");
}

void Database_create(struct Connection *conn)
{
    int i = 0;

    for(i = 0; i < MAX_ROWS; i++) {
        // make a prototype to initialize it
        struct Address addr = {.id = i, .set = 0};
        // then just assign it
        conn->db->rows[i] = addr;
        // the dot notation (.id = i) means a 'designated initializer' is being used to initialize a struct
        // https://gcc.gnu.org/onlinedocs/gcc/Designated-Inits.html explains Designated Initializers in detail
    }
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
    struct Address *addr = &conn->db->rows[id];
    if(addr->set) die("Already set, delete it first");

    addr->set = 1;
    // WARNING: bug, read the "How To Break It" and fix this
    char *res = strncpy(addr->name, name, MAX_DATA);
    addr->name[MAX_DATA - 1]= '\0';
    // demonstrate the strncpy bug
    if(!res) die("Name copy failed");
    // char *strncpy(char *dest, const char *src, size_t n) copies up to n characters from the
    // string pointed to, by src to dest
    res = strncpy(addr->email, email, MAX_DATA);
    if(!res) die("Email copy failed");
}

void Database_get(struct Connection *conn, int id)
{
    struct Address *addr = &conn->db->rows[id];

    if(addr->set) {
        Address_print(addr);
    } else {
        die("ID is not set");
    }
}

void Database_delete(struct Connection *conn, int id)
{
    struct Address addr = {.id = id, .set = 0};
    conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn)
{
    int i = 0;
    struct Database *db = conn->db;

    for(i = 0; i < MAX_ROWS; i++) {
        struct Address *cur = &db->rows[i];

        if(cur->set) {
            Address_print(cur);
        }
    }
}

int main(int argc, char *argv[])
{
    if(argc < 3) die("USAGE: ex17 <dbfile> <action> [action params]");

    char *filename = argv[1];
    char action = argv[2][0];
    // argv[2][0] is a 2-dimensional array
    struct Connection *conn = Database_open(filename, action);
    int id = 0;

    if(argc > 3) id = atoi(argv[3]);
    // int atoi(const char *str) converts the string argument str to an integer (type int)
    if(id >= MAX_ROWS) die("There aren't that many records");

    switch(action) {
        case 'c':
            Database_create(conn);
            Database_write(conn);
            break;

        case 'g':
            if(argc != 4) die("Need an id to get");

            Database_get(conn, id);
            break;

        case 's':
            if(argc != 6) die("Need id, name, email to set");

            Database_set(conn, id, argv[4], argv[5]);
            Database_write(conn);
            break;

        case 'd':
            if(argc != 4) die("Need id to delete");

            Database_delete(conn, id);
            Database_write(conn);
            break;

        case 'l':
            Database_list(conn);
            break;
        default:
            die("Invalid action, only: c=create, g=get, s=set, d=del, l=list");
    }

    Database_close(conn);

    return 0;
}
