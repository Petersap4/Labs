/* ex-6-5-29 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ���������� ��� ���� ���������������� ������ ����� */
typedef enum { INTEGER, STRING, REAL } Valtype;

typedef struct
/* ����� ������������ �� ��������������� ������ ����� */
{
  Valtype type;
  union  {
    int integer;
    char *string;
    float real;
  };  // ��� C99 ��� �����������: `} v;'
} Val;

void readv(Val *v)
/* �������� ��� ���� ��� ��� ���� ��� ��� ����������� ���������������
   �����. */
{
  char c;
  while (1) {
    puts("���� ��� ���� ��� ����� [i: integer, s: string, r: real]:");
    char t;
    scanf("%c", &t);
    while ((c=getchar()) != '\n' && c != EOF);
    switch (t) {
    case 'i':
      puts("���� ��� ���� ��� ��������:");
      scanf("%i", &(v->integer)); // ��� C99 ��� �����������:
      // `v->v.integer'
      while ((c=getchar()) != '\n' && c != EOF);
      v->type = INTEGER;
      break;
    case 's':
      puts("���� �� ������������:");
      char s[1025];
      fgets(s, 1024, stdin);
      s[strcspn(s, "\n")] = '\0';
      v->string = malloc((strlen(s)+1)*sizeof(char));
      if (v->string==NULL) {
        puts("��������� ��������� �����.");
        exit(EXIT_FAILURE);
      }
      strcpy(v->string, s);
      v->type = STRING;
      break;
    case 'r':
      puts("���� ��� ���� ��� �����������:");
      scanf("%f", &(v->real));
      while ((c=getchar()) != '\n' && c != EOF);
      v->type = REAL;
      break;
    default:
      puts("���������� �����.");
      continue;
    }
    break;
  }
}

void freev(Val v)
/* ������������� ���������� ����� �� ����������� ���������������
   �����. */
{
  if (v.type==STRING) // ��� C99 ��� ��������: `if (v.v.type==STRING)'
    free(v.string); // ��� C99 ��� ��������: `free(v.v.string)'
}

int addv(Val *v1, Val v2, Val v3)
/* ��������� ��� ����������� �������������� �����.

   ��������� �� ����������� v2 ��� v3, ������������� ��
   ���������� ��� ����������� ��� ������� � v1.

   �� �� ����������� v2 ��� v3 ����� ���������� ������ ��� ��������,
   ���������� 1, �����������, ���������� 0.
*/
{
  switch (v2.type) {
  case INTEGER:
    switch (v3.type) {
    case INTEGER:
      v1->integer = v2.integer + v3.integer;
      /* ��� C99 ��� ��������:
         `v1->v.integer = v2.v.integer + v3.v.integer;'
      */
      v1->type = INTEGER;
      break;
    default:
      return 1;
    }
    break;
  case STRING:
    switch (v3.type) {
    case STRING:
      v1->string = calloc(strlen(v2.string) + strlen(v3.string)+1,
                          sizeof(char));
      if (v1->string==NULL)
        {
          puts("��������� ��������� �����.");
          exit(EXIT_FAILURE);
        }
      strcat(strcpy(v1->string, v2.string), v3.string);
      v1->type = STRING;
      break;
    default:
      return 1;
    }
    break;
  case REAL:
    switch (v3.type) {
    case REAL:
      v1->real = v2.real + v3.real;
      v1->type = REAL;
      break;
    default:
      return 1;
    }
    break;
  default:
    return 1;
  }
  return 0;
}

int multv(Val *v1, Val v2, Val v3)
/* ��������� ��� ����������� �������������� �����.

   ��������� �� ����������� v2 ��� v3, ������������� ��
   ���������� ��� ����������� ��� ������� � v1.

   �� �� ����������� v2 ��� v3 ����� ���������� ������ ��� ��������,
   ���������� 1, �����������, ���������� 0.
*/
{
  switch (v2.type) {
  case INTEGER:
    switch (v3.type) {
    case INTEGER:
      v1->integer = v2.integer * v3.integer;
      /* ��� C99 ��� ��������:
         `v1->v.integer = v2.v.integer + v3.v.integer;'
      */
      v1->type = INTEGER;
      break;
    case REAL:
        v1->real = v2.integer * v3.real;
        v1->type = REAL;
        break;
    case STRING:
        v1->string = malloc(strlen(v3.string)*v2.integer +1);

        if(v1->string == NULL)
        {
            puts("��������� �����\n");
            exit(0);
        }
        v1->string[0] = '\0';
        for(int i = 0; i<v2.integer; i++)
        {
            strcat(v1->string,v3.string);
        }
        v1->type = STRING;
    break;
    default:
      return 1;
    }
    break;
  case STRING:
    switch (v3.type) {
    case INTEGER:
      v1->string = malloc(strlen(v2.string)*v3.integer +1);

        if(v1->string == NULL)
        {
            puts("��������� �����\n");
            exit(0);
        }
        v1->string[0] = '\0';
        for(int i = 0; i<v3.integer; i++)
        {
            strcat(v1->string,v2.string);
        }
        v1->type = STRING;
      break;
    default:
      return 1;
    }
    break;
  case REAL:
    switch (v3.type) {
    case INTEGER:
      v1->real = v2.real * v3.integer;
      v1->type = REAL;
      break;
    case REAL:
      v1->real = v2.real * v3.real;
      v1->type = REAL;
      break;
    default:
      return 1;
    }
    break;
  default:
    return 1;
  }
  return 0;
}

void putv(Val v)
/* ������� ���� ������ ����� ��� ����������� ��������������� �����,
   ���������� ������. */
{
  switch (v.type) {
  case INTEGER:
    printf("%i\n", v.integer);
    /* ��� C99 ��� ��������:
       `printf("%i", v.v.integer);'
    */
    break;
  case STRING:
    printf("%s\n", v.string);
    break;
  case REAL:
    printf("%f\n", v.real);
    break;
  }
}

void process()
{
  Val v1={0}, v2={0}, v3={0};
  puts("������ ���������");
  readv(&v2);
  puts("�������� ���������");
  readv(&v3);
  puts("���������� ���������������:");
  if (multv(&v1, v2, v3)==0)
    putv(v1);
  else
    puts("������! ��������� �����.");
  freev(v1);
  freev(v2);
  freev(v3);
}

int main(void)
{
    process();
}
