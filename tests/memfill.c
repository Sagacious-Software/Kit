#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <kit/util.h>

int main (int argc, char **argv) {

    char match[]       = "Haha. Haha. Haha. Haha. Haha. Hah";
    char destination[] = "                                 ";
    char source[]      = "Haha. ";

    memfill (destination, source, strlen (destination), strlen (source));

    printf ("source: '%s'\n", source);
    printf ("final:  '%s'\n", destination);

    return (strcmp (destination, match) == 0) &&
           (modulo (17, 8) == 1) &&
           (modulo (-.2, 2) == 1.8)
           ? EXIT_SUCCESS : EXIT_FAILURE;
}
