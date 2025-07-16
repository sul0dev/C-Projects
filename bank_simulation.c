#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#define SIFRE 4534

int main() {
    int bakiye = 1000;
    int girilenSifre;
    int yatirilacakPara, cekilecekPara;
    int islem;
    int pinHakki = 3;
    // Şifre giriş hakkı kontrolü
    while (pinHakki > 0) {
        printf("Sifrenizi giriniz: ");
        scanf("%d", &girilenSifre);

        if (girilenSifre == SIFRE) {
            printf("Sisteme hosgeldiniz.\n");
            _sleep(1000);

            while (1) {
                printf("\nIslem seciniz:\n");
                printf("1: Bakiye Goruntule\n");
                printf("2: Para Yatir\n");
                printf("3: Para Cek\n");
                printf("4: Cikis\n");
                printf("Seciminiz: ");
                scanf("%d", &islem);

                switch (islem) {
                    case 1:
                        printf("Bakiyeniz: %d TL\n", bakiye);
                        _sleep(1000);
                        break;

                    case 2:
                        printf("Yatirmak istediginiz miktari giriniz: ");
                        scanf("%d", &yatirilacakPara);
                        if (yatirilacakPara <= 0) {
                            printf("Gecersiz miktar!\n");
                            _sleep(1000);
                        } else {
                            bakiye += yatirilacakPara;
                            printf("Yeni bakiyeniz: %d TL\n", bakiye);
                            _sleep(1000);
                        }
                        break;

                    case 3:
                        printf("Cekmek istediginiz miktari giriniz: ");
                        scanf("%d", &cekilecekPara);
                        if (cekilecekPara <= 0) {
                            printf("Gecersiz miktar!\n");
                            _sleep(1000);
                        } else if (cekilecekPara > bakiye) {
                            printf("Yetersiz bakiye!\n");
                            _sleep(1000);
                        } else {
                            bakiye -= cekilecekPara;
                            printf("Yeni bakiyeniz: %d TL\n", bakiye);
                            _sleep(1000);
                        }
                        break;

                    case 4:
                        printf("Iyi gunler!\n");
                        _sleep(1000);
                        exit(0);

                    default:
                        printf("Gecersiz islem!\n");
                        _sleep(1000);
                        break;
                }
            }

        } else {
            pinHakki--;
            if (pinHakki == 0) {
                printf("3 kez hatali giris yaptiniz. Hesabiniz kilitlendi.\n");
                _sleep(1000);
                exit(1);
            } else {
                printf("Hatali sifre. Kalan deneme hakkiniz: %d\n", pinHakki);
                _sleep(1000);
            }
        }
    }

    return 0;
}