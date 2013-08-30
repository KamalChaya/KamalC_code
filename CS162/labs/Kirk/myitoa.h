 void reverse(char s[])
 {
     int i, j;
     char a;
 
     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         a = s[i];
         s[i] = s[j];
         s[j] = a;
     }
 }
 
  void itoa1(int n, char c[])
 {
     int i = 0, signOfN = n;
 
     if (signOfN  < 0)  
         n = -n;   //make number positive if negative.       
   
     do {       
         c[i] = n % 10 + '0';  //
		 i++;
     } while ((n /= 10) > 0);  
	 
     if (signOfN < 0) {
         c[i] = '-';
		 i++;
	 }
	 
     c[i] = '\0';
	 
     reverse(c);
 }
