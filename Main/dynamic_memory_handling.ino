//this code is used to make the track array on dynamic memory to be able to pass them to other funtions
//Notes: using global variables instead passing arrays would cost to repeat code for each track array - which is not efficient

boolean** create2DArray(unsigned height, unsigned width)
{
  boolean** array2D = 0;
  array2D = new boolean*[height];

  for (int h = 0; h < height; h++)
  {
        array2D[h] = new boolean[width];

        for (int w = 0; w < width; w++)
        {
              // fill in some initial values
              // (filling in zeros would be more logic, but this is just for the example)
              array2D[h][w] = w + width * h;
        }
  }

  return array2D;
}

void destroyArray(float** arr)
{
  //TODO: write array deletion codex
}
