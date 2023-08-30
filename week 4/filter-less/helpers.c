#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int tmpRed, tmpGreen, tmpBlue;
    float grayOut;
    for(int i = 0 ; i < height ; i++)
    {
        for(int j = 0 ; j < width ; j++)
        {
            tmpRed = image[i][j].rgbtRed;
            tmpGreen = image[i][j].rgbtGreen;
            tmpBlue = image[i][j].rgbtBlue;

            grayOut = round((tmpRed + tmpGreen + tmpBlue) / 3.0);
            image[i][j].rgbtRed = grayOut;
            image[i][j].rgbtGreen = grayOut;
            image[i][j].rgbtBlue = grayOut;

        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int originalRed, originalGreen, originalBlue;
    int sepiaRed, sepiaGreen, sepiaBlue;

    for(int i = 0 ; i < height ; i++)
    {
        for(int j = 0 ; j < width ; j++)
        {
            originalRed = image[i][j].rgbtRed;
            originalGreen = image[i][j].rgbtGreen;
            originalBlue = image[i][j].rgbtBlue;

            sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
            if(sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
            if(sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;
            if(sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE rowplace[width];
    for(int i = 0 ; i < height ; i++)
    {
        for(int j = 0 ; j < width ; j++)
        {
            rowplace[j] = image[i][j];
        }

        for(int j = 0 ; j < width ; j++)
        {
            image[i][j].rgbtRed = rowplace[width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = rowplace[width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = rowplace[width - j - 1].rgbtBlue;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for(int h = 0 ; h < height ; h++)
    {
        for(int w = 0 ; w < width ; w++)
        {
            copy[h][w] = image[h][w];
        }
    }

    for(int h = 0 ; h < height ; h++)
    {
        for(int w = 0 ; w < width ; w++)ye
        {
            int counter = 0;
            float redSum = 0;
            float greenSum = 0;
            float blueSum = 0;

            for(int k = -1 ; k < 2 ; k++)
            {
                for(int l = -1 ; l < 2 ; l++)
                {
                    if(!(h+k < 0 || h+k >= height || w+l < 0 || w+l >= width))
                    {
                        redSum += copy[h+k][w+l].rgbtRed;
                        greenSum += copy[h+k][w+l].rgbtGreen;
                        blueSum += copy[h+k][w+l].rgbtBlue;
                        counter++;
                    }
                    else
                    {
                        continue;
                    }
                }
            }

            image[h][w].rgbtRed = (int)round(redSum / counter);
            image[h][w].rgbtGreen = (int)round(greenSum / counter);
            image[h][w].rgbtBlue = (int)round(blueSum / counter);

        }
    }
}
