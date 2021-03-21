// C program for the above approach
#include <stdio.h>
#include <string.h>

// Driver Code
int main()
{
    // Substitute the full file path
    // for the string file_path
    FILE *fp = fopen("notas.csv", "r");

    if (!fp)
        printf("No se puede abrir el archivo\n");

    else
    {
        char buffer[1024]; //Crea un array de 1024 espacios tipo char
        int row = 0;
        int column = 0;
        float count = 0;
        float average = 0;
        float grade;
        float super_average = 0;

        while (fgets(buffer, 1024, fp)) //Itera por cantidad de filas
        {
            column = 0;
            row++;
            count = 0;

            if (row == 1)
                continue; //Se salta la primera iteración

            char *value = strtok(buffer, ", "); //Separa en bloques según , (En este caso de la fila correspondiente a la iteración)

            while (value) //Itera según cantidad de bloques de value
            {
                if (sscanf(value, "%f", &grade) != 1) //Evalua si algún dato no es un float
                    printf("%s ", value);

                if (sscanf(value, "%f", &grade) == 1) //Evalua si algún dato es un float y lo hace float

                    if ((grade >= 0.0) && (grade <= 7.0))
                    {
                        average = average + grade; //Va sumando las notas de cada evaluación
                        count++;                   //Contador para calcular el divisor de la cantidad total de evaluaciones
                    }
                value = strtok(NULL, ", ");
                column++; //Cambia de columna
            }
            printf(": %.1f ", average / count);
            super_average = super_average + (average / count); //Esta variable tendrá las sumas de todas las notas
            average = 0;                                       //Resetea el valor del promedio para la próxima persona
            grade = 0;                                         //Resetea el  valor de la nota para la próxima persona

            printf("\n");
        }
        printf("Promedio general : %.1f", super_average / (row - 1));

        fclose(fp); //Cierra el archivo fp
        printf("\n");
    }
    return 0;
}