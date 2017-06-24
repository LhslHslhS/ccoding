#include <stdio.h>
#include <string.h>

int main () {

    char a[100][100] = {"il", "ee", "sahm", "sa", "oh", "yook", "chil", "pal", "gu" };
    char b[100][100] = {"sheep", "baek", "cheon"};
    char c[100][100] = {"mahn", "uck", "jo", "gyung", "hae", "ja", "yang", "gu", "gan", "jung", "jae", "geuk"};
    char n[100];

    gets(n);

    int l = strlen(n);

    char *tmp = strdup(n);

    if ( l % 4 == 1 ) {
		strcpy(n, "000");
    } else if ( l % 4 == 2 ) {
    	strcpy(n, "00");
    } else if ( l % 4 == 3 ) {
    	strcpy(n, "0");
    } else {
    	strcpy(n, "");
    }
    strcat(n, tmp);

    int lNew = strlen(n);

    for ( int i = lNew/4, k = 0; i > 0; --i ) {

    	for ( int j = 4; j > 0; --j, ++k) {

    		if ( n[k] == '0' ) continue;

 			printf("%s ", a[ n[k]-'0' -1 ]); // 노란색

    		printf("%s ", b[ j-2 ]); // 주황색

    	}

	    	printf("%s ", c[ i-2 ]); // 초록색

    }

    printf("\n");

	return 0;
}
