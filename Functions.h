void strcp_c(char *str1, const char *cstr2)
{
     // This function copies a const array of chars into an array of chars
     
     unsigned short i = 0;

     do
     {
              str1[i] = cstr2[i];
     }
     while (str1[i++]);
}

short strcmp_c(char *str1, const char *str2)
{
      // This function compares an array of chars with a const array of chars
      
     short i = 0;

     for (;(i==0) || (str2[i-1]!='\n');i++)
     {
           if (str1[i] != str2[i]) return 0;
     }

     return 1;
}

short str_starts_with(char *str1, const char *str2)
{
      // This function checks whether an array of chars starts with a certain const array of chars

     short i = 0;

     for (;(i==0) || (str2[i]!='\n');i++)
     {
           if (str1[i] != str2[i]) return 0;
     }

     return 1;
}

void SendLine(char *l)
{
     // This functions sends an array of chars ended with new line codes through USART
     
     int t;

     for (t=0; l[t]!= '\n'; t++) Usart_Write(l[t]);

     Usart_Write(13);

     Usart_Write(10);
}


void SendConstLine( const char *l)
{
     // This functions sends a constant array of chars ended with new line codes through USART
     
     int t;

     for (t=0; l[t]!= '\n'; t++) Usart_Write(l[t]);

     Usart_Write(13);

     Usart_Write(10);
}


short ValidChar(char i)
{
      // This function determins if a received character is an accepted communication character

      if (i>31 && i<127) return 1;

      return 0;
}

unsigned long max_long(unsigned long a, unsigned long b, unsigned long c)
{
      if (a>b)
      {
              if (a>c) return a; else return c;
      }
      else
      {
              if (b>c) return b; else return c;
      }
}

unsigned long Extract_Numeric_Argument(const int start)
{
       sum = 0;
       
       for (j=start; j<b_i; j++)
       {
            sum = sum * 10 + (b[j] - 48);
       }

       return sum;

}
