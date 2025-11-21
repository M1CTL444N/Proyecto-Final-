#include <stdio.h>

int buscarMayor(int c[]) {
    int idx = 0;
    for(int i = 1; i < 10; i++) {
        if(c[i] > c[idx]) idx = i;
    }
    return idx;
}

int buscarSegundo(int c[], int primero) {
    int idx = (primero == 0) ? 1 : 0; // Empezar en uno que no sea el primero
    for(int i = 0; i < 10; i++) {
        if(i != primero && c[i] > c[idx]) idx = i;
    }
    return idx;
}

int main() {
    int v[100][3];    // Matriz  votos de oyente
    int c[10] = {0};  // Arreglo para contar votos por canción (0 al 9)
    int n = 0, a, b, d;
    
    printf("Ingresa votos (3 numeros), -1 para terminar:\n");
    scanf("%d", &a);

    //Lectura de datos y conteo al mismo tiempo
    while(a != -1 && n < 100) {
        scanf("%d %d", &b, &d);
        
        // Guardamos en la matriz
        v[n][0] = a; v[n][1] = b; v[n][2] = d;
        
        // Sumamos al conteo global
        c[a]++; c[b]++; c[d]++;
        n++;
        
        scanf("%d", &a);
    }

    // Buscar ganadores
    int win1 = buscarMayor(c);
    int win2 = buscarSegundo(c, win1);
    
    printf("\nTop 1: Cancion %d | Top 2: Cancion %d\n", win1, win2);
    printf("-----------------------------------\n");

    //Calcular puntos y buscar al oyente ganador
    int maxPuntos = -1, idGanador = -1;

    for(int i = 0; i < n; i++) {
        int p = 0;
        int tiene1 = 0, tiene2 = 0;

        // Validacion
        for(int k = 0; k < 3; k++) {
            if(v[i][k] == win1) tiene1 = 1;
            if(v[i][k] == win2) tiene2 = 1;
        }

        // Asignar puntos según reglas
        if(tiene1) p += 30;
        if(tiene2) p += 20;
        if(tiene1 && tiene2) p += 10; // Bono extra

        printf("Oyente %d: %d pts\n", i, p);

        if(p > maxPuntos) {
            maxPuntos = p;
            idGanador = i;
        }
    }

    printf("\nGanador: Oyente %d con %d puntos.\n", idGanador, maxPuntos);

    return 0;
}
