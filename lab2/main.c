#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

#include <stdint.h>
#include <inttypes.h>

#ifdef __linux__
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#endif

typedef char* string;

int64_t getFileSize(const char* file_name){
    int64_t _file_size = 0;
    struct stat _fileStatbuff;
    int fd = open(file_name, O_RDONLY);
    if(fd == -1){
        _file_size = -1;
    }
    else{
        if ((fstat(fd, &_fileStatbuff) != 0) || (!S_ISREG(_fileStatbuff.st_mode))) {
            _file_size = -1;
        }
        else{
            _file_size = _fileStatbuff.st_size;
        }
        close(fd);
    }
    return _file_size;
}

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

void passTree(char *name, char *filePath) {
    int64_t the_biggest = -1;
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
            passTree(path, filePath);
        } else {
            char *path = malloc(strlen(name) + strlen(entry->d_name) + 2);
            strcpy(path, name);
            strcat(path, "/");
            strcat(path, entry->d_name);
            strcat(path, "\0");
            int64_t tmp = getFileSize(path);
            if(tmp > the_biggest){
                the_biggest = tmp;
                strcpy(filePath, path);
            }
        }
    }
    if(the_biggest == -1){
        strcat(filePath, "There is no files.");
    }
    closedir(dir);
}

int main() {
    printf("Input a directory: ");
    string dir = getstring();
    char resultPath[1024] = "";
    passTree(dir, resultPath);
    printf("The biggest file path: %s\n", resultPath);
    return 0;
}