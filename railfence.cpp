#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    cout<<"\n ------This program depicts Rail-Fence Cipher----------------\n ";
    char msg[100]={},dom[50][50]={},pom[50][50]={},str[100]={};
    int i=0,j=0,col,key;
    cout<<"\n Enter Message to Encrypt\n";
    cin>>msg;
    col=strlen(msg);
    cout<<"\n Enter Key Length  ";
    cin>>key;
    while(j<col)
    {
       while(i<key)
       {
           dom[i][j]=msg[j];
           j++;
           i++;
       }
       i=i-2;
       while(i>=0)
       {
         dom[i][j]=msg[j];
         i--;
         j++;
       }
       i=i+2;
    }
    int k=0;
    for(i=0;i<key;i++)
    {
        for(j=0;j<col;j++)
        {
            if(dom[i][j]!='\0')

           {
              str[k]=dom[i][j];
              k++;
           }
        }

    }
      cout<<"\n The Cipher Text is----------------------------   ";
      cout<<str;
      cout<<"\n Decrypting to Original Text ----------------------------   ";
      i=j=0;
      while(j<col)
    {
       while(i<key)          ///////////////Helps move Diagonally Downwards
       {
           pom[i][j]='&';
           j++;
           i++;
       }
       i=i-2;
       while(i>=0)       ///////////////Helps move Diagonally Upwards
       {
         if(j<col)       /////i need to check if j has become out of range when iterated in inner loop that works on the value of I only
         {
              pom[i][j]='&';
              i--;
              j++;
         }
         else
            break;


       }
       i=i+2;
    }
     k=0;
    for(i=0;i<key;i++)
    {
        for(j=0;j<col;j++)
        {
            if(pom[i][j]!='\0')

           {
              pom[i][j]=str[k];
              k++;
           }
        }

    }
      i=j=0;
      while(j<col)
      {
          while(i<key)
          {
            str[j]=pom[i][j];
            i++;
            j++;
          }
          i=key-2;
          while(i>=0)
          {
            str[j]=pom[i][j];
            i--;
            j++;
          }
          i=i+2;
      }
      cout<<str;
      return 0;
}
