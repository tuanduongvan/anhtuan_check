#include <stdio.h>
#include<math.h>
#include <time.h>
#include <stdlib.h>

#define maxsize 1000
 
void nhap(float a[],int n)
{
	for(int i=0;i<=n;i++)
	scanf("%f",&a[i]); 
 }
 void docFile(char* fileName, float a[], int* n, int *c) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Khong the doc file.\n");
        exit(1);
    } 
    fscanf(file, "%d%d", n, c);
    for (int i = 0; i <= *n; i++) {
            fscanf(file, "%f", &a[i]);
        }
    fclose(file);
}

 
double tinh( int n, int c,float a[],float p[])
 {
 	p[0] = a[0]; 
    for(int i = 1; i <= n ; ++i){  
	   p[i]=p[i-1]*c + a[i];
}
    return p[n]; 
}

 double tinh_random( int n, int c, float r[],float p[])
 {
 	do{
    srand(time(0));
    for(int i = 0; i <= n ; ++i)
        r[i] = rand()%20 - 10;
    } while (r[0] == 0);
    p[0] = r[0];
    for(int i = 0; i <= n ; ++i){
	   p[i]=p[i-1]*c + r[i];
    }
  return p[n]; 
}
void hoocner(float a[], float p[], int n)
{
	printf("\t  Ap dung phuong phap HOOCNER \n");
	printf("\nCong thuc: P(i) = P(i-1)*c + a(i),  i = (1,n) \n  "); 
	printf("he so a: ");
	for(int i = 0; i <= n; i++)
	  printf ("\t%1.0f\t", a[i]); 
	  printf("\n");
	printf("  p      : ");  
	for(int i = 0; i <= n; i++) 
	  printf ("\t%.0f\t", p[i]);	 
} 
void xuat_he_so(int n, float b[]){
	int k = n;
	  printf("P(x) = ");
	  if (b[0] == 1 || b[0] == -1)
	  {
	    if (b[0] == -1) printf("-x^%d", n);
	    if (b[0] == 1) printf("x^%d", n);
       }
	   else printf("%1.0f*x^%d", b[0], n);
	 for (int i = 1; i <= n; i++){
        if(b[i] > 0) printf(" + ");
        else if(b[i] == 0){
           k--;
		   continue;
	     }
		if(i == n-1 )
		{
		  printf("%1.0f*x ", b[i]);
		  continue;
	    }
        if(i == n){
            printf("%1.0f\n", b[i]);
			continue;	
		} 
		if (b[i] == -1) {
		    printf("-x^%d ", k - 1); 
		    k--;
		   	continue;}  
        if (b[i] == 1) {
		    printf("x^%d ", k - 1); 
		    k--;
		   	continue;}  	  
        printf (" %1.0f*", b[i]); 
        printf("x^%d ", k - 1);
		k--; 
	 }
  }
int main()
{
	int n, c, x, i, choice;
	float r[maxsize], a[maxsize];
	float p[maxsize];
	while (choice != 2)
	{
			
		printf("                                        MENU     \n");
		printf("                (1): Chay chuong trinh voi he so ngau nhien\n");
		printf("                (2): Chay chuong trinh voi he so nhap tu ban phim\n");
		printf("                (3): Chay chuong trinh voi he so tu file\n");
		printf ("Nhap lua chon cua ban...");
		scanf ("%d", &i);
		if (i == 1){
			printf("Nhap bac cua bieu thuc n = "); scanf("%d",&n);
			printf("Nhap c = "); scanf("%d",&c);
			printf("\n (1): In ra qua trinh tinh\n");
		    printf(" (2): Chi in ket qua\n");
		    printf ("Nhap lua chon cua ban...");
		    scanf ("%d", &x);
		    printf("\n");
		    if (x == 1){
		    
			    double P = tinh_random(n, c, r,p);
		    	for(int j = 0; j <= n ; j++){  
	               printf("a%d = %1.0f\n", j, r[j]);
	           }
			    xuat_he_so(n, r);
			    hoocner (r, p, n); 
			    printf ("\n\nP(%d) = %.0lf", c, P);
		   }
		    if (x == 2){
		    	double P = tinh_random(n, c, r,p);
		    	for(int j = 0; j <= n ; j++){  
	               printf("a%d = %1.0f\n", j, r[j]);
	           }
	           
		    	xuat_he_so(n, r);
		        printf ("\nP(%d) = %.0lf", c, P);
		}
		    
	}
		if(i == 2){
			printf("Nhap bac cua bieu thuc n = "); scanf("%d",&n);
			printf("Nhap c = "); scanf("%d",&c);
			printf ("Nhap cac he so cua da thuc\n");
			nhap(a, n);
			printf("\n (1): In ra qua trinh tinh\n");
		    printf(" (2): Chi in ket qua\n");
		    printf ("Nhap lua chon cua ban...");
		    scanf ("%d", &x);
		    printf("\n");
		    if(x == 1){
		    	xuat_he_so(n, a);
		    	double P = tinh(n, c, a,p);
		    	hoocner (a, p, n);
		    	printf ("\nP(%d) = %.0lf", c, P);
		    	
			}
			if (x == 2){
		        xuat_he_so(n, a);
				double P = tinh(n, c, a,p);
		    	printf ("\nP(%d) = %.0lf", c, P);
			}
		}
	    if(i == 3){
			char fileName[maxsize];
			printf("Nhap ten file : ");
			scanf("%s", &fileName);
			docFile(fileName, a, &n, &c);
			xuat_he_so(n,a);
			printf("\n (1): In ra qua trinh tinh\n");
		    printf(" (2): Chi in ket qua\n");
		    printf ("Nhap lua chon cua ban...");
		    scanf ("%d", &x);
		    printf("\n");
		    if(x == 1){
		    	double P = tinh(n, c, a,p);
		    	hoocner (a, p, n);
		    	printf ("\nP(%d) = %.0lf", c, P);
		    	
			}
			if (x == 2){
				double P = tinh(n, c, a,p);
		    	printf ("\nP(%d) = %.0lf", c, P);
			}
			
		}
	printf("\n\nBan muon tiep tuc chuong trinh?");
	printf("\n(1): Co");
	printf("\n(2): Khong");
	printf("\nNhap lua chon cua ban: ");	
	scanf("%d", &choice);  
	}
	system ("pause");
}
