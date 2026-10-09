#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void the_print_stuff(char* german, int type, int gender, char* translation ) {
    if (german[0] == '\0') return;
    switch (type) {
        default :
            puts("not supported yet !\n");
            exit(1);
            break;
        case 0 : //noun
            char genderName[10] = "         ";
            switch (gender) {
                case 0:
                    strcpy(genderName, "der");
                    break;
                case 1:
                    strcpy(genderName, "die");
                    break;
                case 2:
                    strcpy(genderName, "das");
                    break;
                default:
                    return;
            }

            printf("%s %s | %s\n", genderName, german, translation);
            break;

            }
    }


int main(int argc, char *argv[]) {

    if ((argc > 1) /* no, the comment wasn't ai */ && (strcmp(argv[1], "echo") == 0)) {
        //nothing at the moment
    }
    if ((argc > 1)  && (strcmp(argv[1], "print") == 0)) {
        FILE *file_opened;
        file_opened = fopen("data.idk", "r");
        char readbuf[6000];

        if (file_opened == NULL) {
            printf("Does the file exist ?");
            return 1;
        }

        while (fgets(readbuf, sizeof(readbuf), file_opened)) {
            if ((readbuf[0] == '#') || (readbuf[0] == ' ')) {
                // Absolutely **nothing**
            } else {
                char german[3000];
                char translation[3000];
                int type;
                int gender;
                german[0] = '\0';
                translation[0] = '\0';
                if (0 != sscanf(readbuf, "%s : %d : %d : %s", german, &type, &gender, translation)) { //TODO : Make if end-of-file proof or else segfaults
                    the_print_stuff(german, type, gender, translation);
                }
            }
        }
    }
    return 0;
}
