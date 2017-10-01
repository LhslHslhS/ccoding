#include <stdio.h>

int main () {

	int sum = 0;

	int f = 1;
	int g = 2;
	while (g < 4000000 || f < 4000000) {
		int n = 0;
		if (f > g)
		{
			if ( g % 2 == 0)
			{
				sum += g;
			}
			g = f + g;
		}
		else if (g > f)
		{
			if ( f % 2 == 0)
			{
				sum += f;
			}
			f = f + g;
		}
	}

	printf("%d\n", sum);

	return 0;
}