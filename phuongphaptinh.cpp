#include <stdio.h>
#include <math.h>

#define gioihan 0.0001 
#define max 1000 


double giatridathuc(double heso[], int bac, double x) {
    double ketqua = 0;
    for (int i = 0; i <= bac; i++) {
        ketqua += heso[i] * pow(x, bac - i);
    }
    return ketqua;
}
double g(double heso[], int bac, double x) {
    double P_x = giatridathuc(heso, bac, x);
    double hesodaoham[bac];
    
    for (int i = 0; i < bac; i++) {
        hesodaoham[i] = heso[i] * (bac - i);
    }
    
    double P_prime_x = giatridathuc(hesodaoham, bac - 1, x);
    
    return x - P_x / P_prime_x; // g(x) = x - P(x) / P'(x)
}

void lapdiemcodinh(double heso[], int bac ,double giatrikhoitao) {
    double x0 = giatrikhoitao;
    double x1;
    int solanlap = 0;

    printf("lan\tx\n");

    do {
        x1 = g(heso, bac, x0);
        printf("%d\t%.6f\n", solanlap, x1);
        if (fabs(x1 - x0) < gioihan) {
            printf("nghiem gan dung: %.6f\n", x1);
            return;
        }

        x0 = x1;
        solanlap++;

        if (solanlap >= max) {
            printf("So lan lap toi da da dat. Không tim thay nghiem trong khoang cach sai so cho phep.\n");
            return;
        }
    } while (1);
}

int main() {
    int bac;
    double giatrikhoitao;
    printf("Nhap bac cua phuong trinh: ");
    scanf("%d", &bac);

    double heso[bac + 1];
    printf("Nhap cac he so cua phuong trinh (tu bac cao den bac thap):\n");
    for (int i = 0; i <= bac; i++) {
        printf("He so bac %d: ", bac - i);
        scanf("%lf", &heso[i]);
    }

    printf("Nhap gia tri khoi tao ban dau: ");
    scanf("%lf", &giatrikhoitao);

    lapdiemcodinh(heso, bac, giatrikhoitao);

    return 0;
}
