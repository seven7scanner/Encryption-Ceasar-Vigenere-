#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 128

char ascii_lowercase[88] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9','`','~','!','@','#','$','%','^','&','*','(',')','_','-','=','+','[',']','{','}',';',':','"','|','?','/'};
static char ceasar_table[88];

void generate_ceasar_table(int n){
	
    int k;
    for (k=0; k<87; k++){
        if (k + n < 88 ) {
            ceasar_table[k] = ascii_lowercase[k + n -1] ;
        } 
		else {
            ceasar_table[k] = ascii_lowercase[k + n -88];
        }
    }
}

int encrypt(int n) {
	
    generate_ceasar_table(n);
    
	fseek(stdin,0,SEEK_END);

    int i, j;
    char encrypt_array[MAX_LENGTH];
    
    printf("Type your secret message: ");
    scanf("%[^\n]s", &encrypt_array);
    
    for(i=0;i<MAX_LENGTH;i++) {
        for (j=0;j < 87;j++) {
            if (encrypt_array[i] == ascii_lowercase[j]) {
                if (encrypt_array[i] == ascii_lowercase[j]){
                    encrypt_array[i] = ceasar_table[j];
                }
                break;
            }
        }
    }
    
    printf("Your encrypted password is: %s\n", encrypt_array);
    
    return 0;
}

int decrypt(int n) {
	
    generate_ceasar_table(n);
	
    fseek(stdin,0,SEEK_END);
    
    int i, j;
    char decrypt_array[MAX_LENGTH];
    printf("Type your secret message: ");
    scanf("%[^\n]s", &decrypt_array);
    
    for(i=0; i<MAX_LENGTH; i++) {
        for (j=0; j < 87; j++) {
            if (decrypt_array[i] == ceasar_table[j]) {
                if (decrypt_array[i] == ceasar_table[j]){
                    decrypt_array[i] = ascii_lowercase[j];
                }
                break;
            }
        }
    }
    
    printf("Your encrypted password is: %s\n", decrypt_array);
    
    return 0;
}

int main() {
    
    puts("type the encryption shity number: ");
    int enc_num;
    do
    {
    	scanf("%d", &enc_num);
    	if(enc_num>87)
    	{
    		puts("try a lower number plz\n");
		}
		else if(enc_num<0)
		{
			puts("try a higher number plz\n");
		}
	}while(enc_num>87 || enc_num<0);
	
    encrypt(enc_num);
    decrypt(enc_num);
    
    return 0;
}

