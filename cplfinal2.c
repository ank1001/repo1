#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 64
//size can be modified; (1024 bit)/(4*8) = 32 integers; (32+32 = 64 requires in multiplication)
int ascii(char c)
{
    //this function converts a char to int
    int num;
    num = c;
    num = num-48;
    /*printf("ascii value is %d", num);*/
    return num;
}


void add(char string1[],int length1, char string2[],int length2)
{
    int length = length1>length2?length1:length2;char ch = '0';
    int arr[length+1];int x,i,j;int carry=0;
    char string3[length];
    //initializing the array
    for(int i = 0;i<length+1;i++)
    {
        arr[i] = 0;
    }
    if(strlen(string1)>strlen(string2))
    {
        i=strlen(string1)-1;j=strlen(string2)-1;
        while(i!=-1 )
        {
            if(j<0)
            {
                string2[j]= ch;
            }
            x=ascii(string1[i]) + ascii(string2[j]);
            if(x>9)
            {
                arr[i] = carry + (x%10);
                carry=x/10;
            }
            else
            {
                arr[i] = carry + x;
                carry = x/10;
            }
            
            i--;
            j--;
        }
    
        printf("\nAddition: ");
        for(int i = 0;i<length;i++)
        {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
    else if(strlen(string1)<strlen(string2))
    {
        strcpy(string3,string2);
        strcpy(string2,string1);
        strcpy(string1,string3);


        add(string1,length1, string2,length2);
    }
    else
    {
        i=strlen(string1)-1;j=strlen(string2)-1;
         while(i!=-1 )
        {
            x=ascii(string1[i]) + ascii(string2[j]);
            if(x>9)
            {
                arr[i] = carry + (x%10);
                carry=x/10;
            }
            else
            {
                arr[i] = carry + x;
                carry = x/10;
            }
            
            i--;
            j--;
        }
        printf("\nAddition: ");
        for(int i = 0;i<length;i++)
        {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

void subtract(char string1[],int length1, char string2[],int length2)
{
    int length = length1>length2?length1:length2;
    int arr[length];int x,i,j,k;int carry=0;
    char string3[length];char ch = '0',ch1,ch2;
    int flag = 0;
    //initializing the array
    for(int i = 0;i<length+1;i++)
    {
        arr[i] = 0;
    }
    if(strlen(string1)>strlen(string2))
    {
        i=strlen(string1)-1;j=strlen(string2)-1;k=length -1;
        while(i!= -1 )
        {
            if(j<0)
            {
                string2[j]= ch;
            }
            ch1=string1[i];ch2=string2[j];
            if(ascii(ch1)>=ascii(ch2))
            {
                arr[k] = ascii(ch1)- ascii(ch2);
            }
            else
            {
                arr[k] = ascii(ch1)- ascii(ch2) + 10;
                string1[i-1] = string1[i-1] - 1;
            }
            i--;
            j--;
            k--;
        }
        printf("\nSubtraction: ");
        for(int i = 0;i<length;i++)
        {
            printf("%d", arr[i]);
        }
    }
    else if(strlen(string1)<strlen(string2))
    {
        strcpy(string3,string2);
        strcpy(string2,string1);
        strcpy(string1,string3);
        i=strlen(string1)-1;j=strlen(string2)-1;
        while(i!= -1 )
        {
            if(j<0)
            {
                string2[j]= ch;
            }
            ch1=string1[i];ch2=string2[j];
            if(ascii(ch1)>=ascii(ch2))
            {
                arr[i] = ascii(ch1)- ascii(ch2);
            }
            else
            {
                arr[i] = ascii(ch1)- ascii(ch2) + 10;
                if(i!=0)
                {
                    string1[i-1] = string1[i-1] -1;
                }
            }
            i--;
            j--;
        }
        printf("\nSubtraction: -");
        for(int i = 0;i<length;i++)
        {
            printf("%d", arr[i]);
        }
    }

    else
    {
        i=0;
        while(i<length && flag == 0)
        {
            ch1=string1[i];ch2=string2[i];
            if(ascii(ch1)>ascii(ch2))
            {
                flag=1;
            }
            else if(ascii(ch1)<ascii(ch2))
            {
                flag=2;
            }
            i++;
        }
        if(flag==0)
        {
            printf("\nSubtraction: 0\n");
        }
        else if(flag==1)
        {
            i=strlen(string1)-1;j=strlen(string2)-1;k=length -1;
            while(i!= -1 )
            {
                ch1=string1[i];ch2=string2[j];
                if(ascii(ch1)>=ascii(ch2))
                {
                    arr[k] = ascii(ch1)- ascii(ch2);
                }
                else
                {
                    arr[k] = ascii(ch1)- ascii(ch2) + 10;
                    string1[i-1] = string1[i-1] - 1;
                }
                i--;
                j--;
                k--;
            }
            printf("\nSubtraction: ");
            for(int i = 0;i<length;i++)
            {
                printf("%d", arr[i]);
            }
            printf("\n");
        }
        else
        {
            strcpy(string3,string2);
            strcpy(string2,string1);
            strcpy(string1,string3);
            i=strlen(string1)-1;j=strlen(string2)-1;
            while(i!= -1 )
            {
                ch1=string1[i];ch2=string2[j];
                if(ascii(ch1)>=ascii(ch2))
                {
                    arr[i] = ascii(ch1)- ascii(ch2);
                }
                else
                {
                    arr[i] = ascii(ch1)- ascii(ch2) + 10;
                    if(i!=0)
                    {
                        string1[i-1] = string1[i-1] -1;
                    }
                }
                i--;
                j--;
            }
            printf("\nSubtraction: -");
            for(int i = 0;i<length;i++)
            {
                printf("%d", arr[i]);
            }
            printf("\n");
        }
        
    }
}

void multiply(char string1[],int length1, char string2[],int length2)
{
    char ch1,ch2;
    int carry=0,j;
    int arr[length1+length2+1];
    for(int i=0;i<length1+length2;i++)
    {
        arr[i] = 0;
    }
    for(int i=length2-1;i>=0;i--)
    {
        carry = 0;
        for(j=length1-1;j>=0;j--)
        {
            ch1 = string2[i]; ch2 = string1[j];
            int t = ascii(ch1) * ascii(ch2) + carry + arr[i+j+1];
            /*printf("\n\ni=%d\tj=%d\n",i,j);
            printf("\ncarry:%d \narr[i+j]: %d \nt: %d\n\n",carry,arr[i+j+1],t);*/
          
            carry = t/10;
            arr[i+j+1] = t%10;
            /*printf("arr[i+j]after: %d\ncarry after: %d",arr[i+j+1],carry);*/
        }
        arr[i+j+1]= carry;
    }
    printf("\nMultiplication: ");
    for(int i=0;i<length1+length2;i++)
    {
        printf("%d",arr[i]);
    }
	printf("\n");
}

int main()
{
    char string1[size],string2[size],s1[20],s2[size];int l1,l2;
    printf("Enter the numbers:\n");
    scanf("%s %s",string1,string2);
    int length1 = strlen(string1), length2 = strlen(string2);
    strcpy(s1,string1);strcpy(s2,string2);l1=length1; l2=length2;
    add(s1,l1,s2,l2);
    strcpy(s1,string1);strcpy(s2,string2);l1=length1; l2=length2;
    subtract(s1,l1,s2,l2);
    strcpy(s1,string1);strcpy(s2,string2);l1=length1; l2=length2;
    multiply(s1,l1,s2,l2);
    return 0;
}
