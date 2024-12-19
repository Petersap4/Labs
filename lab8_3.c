#include <stdio.h>
#include <stdlib.h>

int **create_arr(int nor, int noc);
void populate_arr(int nor, int noc, int **arr);
int **modify_arr(int **arr,int nor,int noc,int newnor,int newnoc);
void clear_line_arr(int nullr, int noc, int **arr);
void clear_column_arr(int nullc, int nor, int **arr);
void free_arr(int nor, int **arr);
void print_arr(int nor, int noc, int **arr);

int main(void)
{
  int nor, noc, **arr;
  while (1) {
    puts("Δώσε τις δύο διαστάσεις της συστοιχίας:");
    scanf("%i %i", &nor, &noc);
    arr = create_arr(nor, noc);
    if (arr!=NULL)
      break;
    puts("Ανεπαρκής διαθέσιμη μνήμη.\n"
         "Προσπάθησε με μικρότερες διαστάσεις.");
  }
  populate_arr(nor, noc, arr);
  print_arr(nor, noc, arr);
  int newnor, newnoc;
    while(1)
    {
    puts("Δώσε τις δύο νέες διαστάσεις της συστοιχίας:");
    scanf("%i %i", &newnor, &newnoc);
    arr = modify_arr(arr,nor, noc, newnor, newnoc);
    if (arr!=NULL)
        break;
    puts("Προσπάθησε με μικρότερες διαστάσεις.\n");
    }

  if(newnor-nor>0)
  {
      for(int ni=nor; ni<newnor;ni++)
        clear_line_arr(ni, newnoc, arr);
  }
  if(newnoc-noc>0)
  {
      for(int nc=noc; nc<newnoc;nc++)
        clear_column_arr(nc, newnor, arr);
  }
  print_arr(newnor, newnoc, arr);
  free_arr(newnor, arr);
}

int **create_arr(int nor, int noc)
/* Δημιουργεί μία δισδιάστατη συστοιχία ακεραίων.

   Δημιουργεί μία συστοιχία από ακέραιους, ως δείκτη σε δείκτη
   σε ακέραιο, διαστάσεων nor επί noc, διανέμοντας μνήμη.

   Επιστρέφει είτε ένα δείκτη ουδενός, είτε ένα δείκτη στον
   διανεμημένο χώρο.
*/
{
  int **arr;
  arr = malloc(nor*sizeof(int*));
  if (arr==NULL)
    return NULL;
  for (int r=0; r<nor; r++) {
    arr[r] = malloc(noc*sizeof(int));
    if (arr[r]==NULL) {
      for (int rr=0; rr<r; rr++)
        free(arr[rr]);
      free(arr);
      return NULL;
    }
  }
  return arr;
}

void populate_arr(int nor, int noc, int **arr)
/* Συμπληρώνει με μονοψήφιους ψευδοτυχαίους αριθμούς μία δισδιάστατη
   συστοιχία από int.

   Συμπληρώνει τις nor γραμμές και noc στήλες της συστοιχίας arr.

   Δεν επιστρέφει τιμή.
*/
{
  for (int r=0; r<nor; r++)
    for (int c=0; c<noc; c++)
      arr[r][c] = rand()%10;
}

void free_arr(int nor, int **arr)
/* Απελεθερώνει την εκχωρημένη μνήμη μίας δισδιάστατης συστοιχίας από
   int.

   Απελευθερώνει τις nor γραμμές της συστοιχίας arr, ως δείκτη σε
   δείκτες ακεραίων.

   Δεν επιστρέφει τιμή.
*/
{
  for (int r=0; r<nor; r++)
    free(arr[r]);
  free(arr);
}

void print_arr(int nor, int noc, int **arr)
/* Τυπώνει μία δισδιάστατη συστοιχία από int.

   Τυπώνει τις nor γραμμές και τις noc στήλες της συστοιχίας arr.

   Δεν επιστρέφει τιμή.
*/
{
  for (int r=0; r<nor; r++) {
    for (int c=0; c<noc; c++)
      printf("%2i", arr[r][c]);
    putchar('\n');
  }
}

int **modify_arr(int **arr,int nor,int noc,int newnor,int newnoc)
{
    int **narr;
    narr = malloc(newnor*4);
    if(narr == NULL)
        return NULL;
    for(int k = 0; k<newnoc; k++)
    {
        narr[k] = malloc(newnoc*4);
        if (narr[k]==NULL)
        {
            for (int rr=0; rr<k; rr++)
                free(narr[rr]);
            free(narr);
            return NULL;
        }
    }
    for(int i=0; i<nor; i++)
    {
        for(int j = 0; j<noc;j++)
        {
                narr[i][j]=arr[i][j];
        }
    }
    int nr = newnor-nor;
    int nc = newnoc-noc;
    if(nr>0)
    {
        if(nc>0)
        {
            for(int i = nor+1; i<=nr; i++)
            {
                for(int j =noc+1; j<=nc; j++)
                    arr[i][j] = 0;
            }
        }
    }
    free_arr(nor, arr);
    return narr;
}


void clear_line_arr(int nullr, int noc, int **arr)
{
    for(int j = 0; j<noc; j++)
    {
        arr[nullr][j] = 0;
    }
}

void clear_column_arr(int nullc, int nor, int **arr)
{
    for(int i= 0; i<nor; i++)
    {
        arr[i][nullc] = 0;
    }
}
