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

    // Tulostetaan pyramidin rivit
    for (int i = 1; i <= n; i++)
    {
        int spaces = n - i;  // Välilyöntejä vasemmalla
        int bricks = i;      // Lohkojen määrä
        print_row(spaces, bricks);  // Kutsu tulostusfunktiota
    }
}

// Tulostaa rivin, jossa on spaces määrä välilyöntejä, bricks määrä vasemmanpuoleisia lohkoja,
// kaksi välilyöntiä ja bricks määrä oikeanpuoleisia lohkoja
void print_row(int spaces, int bricks)
{
    // Tulostetaan välilyönnit vasemmalla
    for (int j = 0; j < spaces; j++)
    {
        printf(" ");
    }

    // Tulostetaan vasemmanpuoleiset lohkot
    for (int j = 0; j < bricks; j++)
    {
        printf("#");
    }

    // Tulostetaan välilyönnit keskellä
    printf("  ");

    // Tulostetaan oikeanpuoleiset lohkot
    for (int j = 0; j < bricks; j++)
    {
        printf("#");
    }

    // Siirrytään seuraavalle riville
    printf("\n");
}
