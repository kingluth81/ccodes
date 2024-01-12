#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int X_AXIS_MAX = 1000, Y_AXIS_MAX = 1000;
    int LR_COLORING_CENTER[2] = {500, 500};
    static unsigned char COLOR[][3] = {
            {255,0,0},
            {0, 255, 0},
            {0, 0, 255},
            {255, 255, 0},
            {255, 0, 255}
    };
    FILE *fp = fopen("outPut.ppm", "wb");
    (void) fprintf(fp, "P6\n%d %d\n255\n", X_AXIS_MAX, Y_AXIS_MAX);


    for (int j = 0; j < Y_AXIS_MAX; j++) {

        if (j <= 250) {     //TOP area of the shape

            for (int i = 0; i < X_AXIS_MAX; i++) {

                if (i < 500)
                    (void) fwrite(COLOR[0], 1, sizeof(COLOR[0]), fp);

                else
                    (void) fwrite(COLOR[1], 1, sizeof(COLOR[1]), fp);

            }
        }

        else if (250 < j && j <= 500) {     //MIDDLE area of the shape

            for (int i = 0; i < X_AXIS_MAX; i++) {

                if (i < LR_COLORING_CENTER[0])
                    (void) fwrite(COLOR[0], 1, sizeof(COLOR[0]), fp);

                else if (LR_COLORING_CENTER[0] <= i && i <= LR_COLORING_CENTER[1])
                    (void) fwrite(COLOR[2], 1, sizeof(COLOR[2]), fp);

                else if (LR_COLORING_CENTER[1] <= i)
                    (void) fwrite(COLOR[1], 1, sizeof(COLOR[1]), fp);

            }
            LR_COLORING_CENTER[0]-=1;
            LR_COLORING_CENTER[1]+=1;
        }

        else if (500 < j && j <= 750) {     //MIDDLE area of the shape

            for (int i = 0; i < X_AXIS_MAX; i++) {

                if (i < LR_COLORING_CENTER[0])
                    (void) fwrite(COLOR[3], 1, sizeof(COLOR[3]), fp);

                else if (LR_COLORING_CENTER[0] <= i && i <= LR_COLORING_CENTER[1])
                    (void) fwrite(COLOR[2], 1, sizeof(COLOR[2]), fp);

                else if (LR_COLORING_CENTER[1] <= i)  //the bottom right of the shape
                    (void) fwrite(COLOR[4], 1, sizeof(COLOR[4]), fp);

            }
            LR_COLORING_CENTER[0] += 1;
            LR_COLORING_CENTER[1] -= 1;
        }

        else if (750 < j && j <= 1000) {     //BOTTOM area of shape

            for (int i = 0; i < X_AXIS_MAX; i++) {

                if (i <= 500) //the bottom left of the shape
                    (void) fwrite(COLOR[3], 1, sizeof(COLOR[3]), fp);
					
				else if (i > 500) //the bottom right of the shape
					(void) fwrite(COLOR[4], 1, sizeof(COLOR[4]), fp);

                
            }
        }
    }

    (void) fclose(fp);
    return EXIT_SUCCESS;
}