
#include <stdio.h>
#include <stdlib.h>

int main() {

  struct article{
    char *name;
    int qty;
    float price;
  };

  int n,s=0,i=0,code,q=0;
  float total=0,amnt=0;
  struct article art;
  int a[8],co[8];
  float p[8],m[8];
  char *t[8];

int check_code(int code)
{
    switch (code) {
      case 1: art.price = 370.00;
              art.qty = 5;
              art.name = "Samsung";
              break;
      case 2: art.price = 199.05;
              art.qty = 3;
              art.name = "Huawei";
              break;
      case 3: art.price = 295.25;
              art.qty = 8;
              art.name = "Oppo";
              break;
      case 4: art.price = 125.99;
              art.qty = 2;
              art.name = "Vivo";
              break;
      case 5: art.price = 440.00;
              art.qty = 3;
              art.name = "Realmi";
              break;
      case 6: art.price = 657.99;
              art.qty = 11;
              art.name = "Alcatel";
              break;
      case 7: art.price = 999.99;
              art.qty = 1;
              art.name = "Iphone";
              break;
    }
  return 0;
}
void calculate_totale(int q){
  amnt = art.price * q;
  total = total + amnt;

}

do {
  printf("Combien d'article à facturer?(1-7)\n");
  scanf("%d",&n);
} while(n < 1 || n > 7);


while (i < n) {
  printf("Code article (1-7)?\n");
  scanf("%d",&code);
  while (code < 1 || code > 7 || code == co[i-1]) {
    if(code == co[i-1]) {
        printf("Tu a deja choisir cette article donner un autre code:\n");
        scanf("%d",&code);
    }
    else {
        printf("redonner le code (1-7):\n");
        scanf("%d",&code);
        }
    }

  check_code(code);

  printf("Quantité de telephone %s au prix unitaire de %.2f$ ?\n",art.name,art.price);
  scanf("%d",&q);

    while (art.qty < q) {
      printf("Quantité demande n'est pas valable \n");
      printf("Redonner la quantité de telephone %s au prix unitaire de %.2f$ ?\n",art.name,art.price);
      scanf("%d",&q);
    }
  calculate_totale(q);

  a[i] = q ;
  t[i] = art.name ;
  p[i] = art.price ;
  float mont = q * art.price;
  m[i] = mont;
  co[i] = code;
  i++;
}
printf("\nArticle       Nmbre      P-Unite        Montant\n");
for(s=0;s< n;s++){
    printf("%s       %d           %.2f$       %.2f$\n",t[s],a[s],p[s],m[s]);
    }
    printf("    Totale: %.2f $",total);
}
