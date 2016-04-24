#include<stdio.h>
#include<math.h>
#include<string.h>
#include<conio.h>
 main()
{
    /*Declarations of arrays;1.s:-it is array of name of substances
                             2.m:-it is array of molecular weights of substances which follows same order respectively.
                             3.i1 and i2:arrays of substances and their amounts respectively.*/
    /*Declarations of Variables:1.c:-it is conversion factor.
                                2.a:-it is the unit entered by user.
                                3.x:-amount in CaSO4 equivalents of respectively substance.
                                4.psum,tsum,totalsum:-They are permanent hardness,temporary hardness and total hardness respectively.
                                5.i,j,k,v,t,:-They are counters.
                                6.n:-Number of substances user enters.
                                7.x:-It is multiplication factor.*/
    char s[11][10]={"CaCl2","CaSO4","MgSO4","MgCl2","Mg(NO3)2","Ca(HCO3)2","Mg(HCO3)2","CaCO3","MgCO3","Ca(OH)2","Mg(OH)2"},i1[11][10],a[100],t[10];
    float m[11]={111,136,120,95,148,162,146,100,84,74,58},c,x,psum,tsum,totalsum;
    int i,j,k,n,b,v,i2[11];
    /*This will direct user about entering name of substance and units. */
    printf("1.To write substance name don't write numbers in subscript and it is case sensitive.Ex. CaSO4,Mg(HCO3)2.\n2.You can opt unit form below and enter it when asked.\n\t1.ppm\n\t2.mg/l \n\t3.clarke\n\t4.french");
    /*Getting Inputs From user*/
    printf("\nPlease Enter Total Number Of Substances You Want To enter=");
    scanf("%d",&n);
    /*This will ask unit and then it will define conversion factor c.*/
    b=0;
    while(b==0)
    {
        b=0;
        printf("Please Enter The Unit In Which You Want To Enter Amount=");
        scanf("%s",a);
        if(strcmp(a,"ppm")==0)
        {
            c=1;
            b=1;
        }
        else if(strcmp(a,"mg/l")==0)
        {
            c=1;
            b=1;
        }
        else if(strcmp(a,"clarke")==0)
        {
            c=0.07;
            b=1;
        }
        else if(strcmp(a,"french")==0)
        {
            c=0.1;
            b=1;
        }
        else
        {
            printf("Invalid Unit!");
            b=0;
        }
    }
    /*This Will Form 2 arrays which is entered by user*/
    k=0;
    do
    {
        v=k+1;
        printf("Please Enter Substance %d=",v);
        scanf("%s",i1[k]);
        printf("Please Enter Its Amount=");
        scanf("%d",&i2);
        i2[k]=i2[k]*c;
        k=k+1;
    }while(k<=n-1);
    /*This is The Part Where we differentiate substances and add them to their category.*/
    psum=0;
    tsum=0;
    for(i=0;i<=n-1;i++)
    {
        j=0;

        while((strcmp(s[j],i1[i])!=0)||(j>10))
        {
            j=j+1;
        }
         if(j>10)
         {
             x=0;
         }
         else
         {printf("%f\n",i2[j]);
             x=(i2[j]*100)/m[j];
         }
         if(j<=4)
         {
             psum=psum+x;
         }
         else
         {
             tsum=tsum+x;
         }
    }
    totalsum=psum+tsum;
    printf("Permanent Hardness is %f",psum);
    printf("\nTemporary Hardness is %f",tsum);
    printf("\nTotal Hardness is %f",totalsum);
}
