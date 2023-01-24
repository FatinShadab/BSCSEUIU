#include <stdio.h>

int main(){
    int n, faces = 0;
    char polyhedron[12];

    scanf("%d", &n);
    getchar();

    while (n--){
        scanf("%s", polyhedron);

        switch (polyhedron[0]){
            case 'T':
                faces += 4;
                break;
            case 'C':
                faces += 6;
                break;
            case 'O':
                faces += 8;
                break;
            case 'D':
                faces += 12;
                break;
            case 'I':
                faces += 20;
                break;
            default:
                continue;
        }
    }

    printf("%d\n", faces);

    return 0;
}