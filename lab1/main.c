#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

typedef char* string;

char* getstring (void)
{
    char* buffer = NULL;                        //буфер для хранения символов
    unsigned int capacity = 0;              //размер буфера
    unsigned int n = 0;                     //сколько символов в буфере
    int bitofchar = sizeof(char);           //сколько бит в одном char
    int MAX_LEN = 2048;                     //1 строка максимум 4 Мб (MAX_LEN*2)
    int c;                                      //сюда записываем символы

    // получаем символы
    while ((c = fgetc(stdin)) != '\n' && c != EOF)
    {
        if (n + 1 > capacity)               //проверяем размер буфера
        {
            if (!capacity) capacity = 32; //по умолчанию 32 символа
            else if (capacity <= MAX_LEN) capacity *= 2;
            else                                    //угроза переполнения буфера
            {
                free(buffer);
                return NULL;
            }
            // меняем размер буфера в памяти
            char* temp = (char*) realloc(buffer, capacity * bitofchar);
            if (!temp)
            {
                free(buffer);
                return NULL;
            }
            buffer = temp;
        }
        // заносим символ в буфер
        buffer[n++] = c;
    }
    if (n == 0 && c == EOF) return NULL;//если пустая строка, вернем NULL

    // минимизируем размер буфера
    char* minimal = (char*) malloc((n + 1) * bitofchar);
    strncpy(minimal, buffer, n);
    free(buffer);                               //освобождаем память
    minimal[n] = '\0';                      //добавляем конец строки

    return minimal;                         //возвращаем получившуюся строку
}

void findDir(char *name, char *fileName, char *filePath) {
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(name))) {
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            string path = malloc(strlen(name)+strlen(entry->d_name)+2);
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            strcpy(path, name);
            strcat(path, "/");
            strcat(path, entry->d_name);
            findDir(path, fileName, filePath);
        } else {
            if (strcmp(entry->d_name, fileName) == 0) {
                char *path = malloc(strlen(name) + strlen(entry->d_name) + 2);
                strcpy(path, name);
                strcat(path, "/");
                strcat(path, entry->d_name);
                strcat(path, "\0");
                strcpy(filePath, path);
            }
        }
    }
    closedir(dir);
}

int main() {
    printf("Input a directory: ");
    string dir = getstring();
    printf("Input source file name: ");
    string sourceName = getstring();
    printf("Input result file name: ");
    string resultName = getstring();
    char sourcePath[1024] = "", resultPath[1024] = "", cc[256] = "", key[] = "kulizhenko";

    findDir(dir, sourceName, sourcePath);
    findDir(dir, resultName, resultPath);

    printf("\n%s file path: %s\n", sourceName, sourcePath);
    printf("%s file path: %s\n", resultName, resultPath);

    if(!strlen(sourcePath))
        printf("WARNING: There is no such source file.");
    else {
        strlen(resultPath) ? printf("WARNING: already have such result file. Recorded data from it will be deleted.") : printf("Creating new result file with name: %s on %s", resultName, dir);
        FILE *fp, *fp2;
        fp = fopen(sourcePath, "r");

        if(strlen(resultPath))
            fp2 = fopen(resultPath, "wb");
        else{
            strcat(dir, "/");
            strcat(dir, resultName);
            fp2 = fopen(dir, "wb");
        }


        while((fgets(cc, 256, fp)) != NULL)
        {
            char xor[256] = "";
            int count = 0;
            printf("%s\n", cc);
            while(count != strlen(cc)){
                for(int i = 0; i < 10; i++){
                    if(count == strlen(cc))
                        break;
                    xor[count] = (char)(cc[count] ^ key[i]);
                    count++;
                }
            }
            fputs(xor, fp2);
        }
        fclose(fp);
        fclose(fp2);
        printf("\nSuccess!");
    }

    return 0;
}
