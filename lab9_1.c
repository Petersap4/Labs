#include<stdio.h>
#include <string.h>
#include <errno.h>
struct files
{
    double is, antis;
    char coin[22];
};

void convert_files(char *f1, char *f2)
{
    struct files curr;
    FILE *file, *bfile;
    file = fopen("f1", "r");
    if(file == NULL)
    {
        perror("error");
        fclose(file);
        exit(0);
    }
    bfile = fopen("f2", "wb");
    if(bfile == NULL)
    {
        perror("error");
        fclose(bfile);
        exit(0);
    }
    char line[100];
    while(fgets(line,sizeof(line),file))
    {
        char *t = strtok(line, ",");
        strncpy(curr.coin, t, sizeof(curr.coin)-1);
        curr.coin[sizeof(curr.coin)-1] = '\0';
        t = strtok(NULL,",");
        curr.is = atof(t);
        t = strtok(NULL,",");
        curr.antis = atof(t);
        fwrite(&curr, sizeof(curr), 1, bfile);
    }
    fclose(file);
    fclose(bfile);
}

void rate_range(char *f1, char *f2, double up ,double lo)
{
    struct files curr;
    FILE *file, *bfile;
    bfile = fopen("f1", "rb");
    if(bfile == NULL)
    {
        perror("error");
        fclose(bfile);
        exit(errno);
    }
    file = fopen("f2", "w");
    if(file == NULL)
    {
        perror("error");
        fclose(file);
        exit(errno);
    }
    while(fread(&curr, sizeof(curr), 1, bfile))
    {
        if(curr.is>=lo &&curr.is<up)
            fprintf(file, "%s,%f,%f\n", curr.coin, curr.is, curr.antis);
    }
    fclose(file);
    fclose(bfile);
}

int count_currencies(char *bin)
{
    char *ext = strrchr(bin, '.');
    if(ext == NULL || strncmp(ext, ".dat", 4)&&strncmp(ext, ".DAT", 4))
        return -1;
    FILE *f = fopen("bin", "rb");
    if(f==NULL)
    {
        perror("error");
        fclose(f);
        exit(errno);
    }
    struct files curr;
    int cnt = 0;
    while(fread(&curr, sizeof(curr), 1, bin))
        cnt++;
    fclose(f);
    return cnt;
}
