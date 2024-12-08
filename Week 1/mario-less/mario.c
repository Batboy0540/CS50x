#include <stdio.h>
#include <cs50.h>

void print_row(int spaces, int bricks);

int main(void)
{   
    // Prompt the user for the pyramid's height
    int n;
    do
    {
        n = get_int("height: ");
    }
    while (n < 1 || n > 8); // Rajoita korkeus 1-8:aan

    for (int i = 1; i <= n; i++)
    {
        int spaces = n - i;  // Välilyöntejä
        int bricks = i;      // Lohkoja
        print_row(spaces, bricks);  // Kutsu tulostusfunktiota
    }
}

// Tulostaa rivin, jossa on spaces määrä välilyöntejä ja bricks määrä lohkoja
void print_row(int spaces, int bricks)
{
    // Tulostetaan välilyönnit
    for (int j = 0; j < spaces; j++)
    {
        printf(" ");
    }

    // Tulostetaan lohkot
    for (int j = 0; j < bricks; j++)
    {
        printf("#");
    }

    // Siirrytään seuraavalle riville
    printf("\n");
}
