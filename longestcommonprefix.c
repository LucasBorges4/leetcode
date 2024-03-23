#include <stdio.h>

/*
Input: strs = ["flower","flow","flight"]
Output: "fl"
*/

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return ""; // Retorna uma string vazia se o array estiver vazio
    
    // Percorre o primeiro string no array
    for (int i = 0; i < strlen(strs[0]); i++) {
        // Percorre as outras strings no array
        for (int j = 1; j < strsSize; j++) {
            // Verifica se o caractere atual é diferente nas outras strings
            if (strs[j][i] != strs[0][i]) {
                // Se os caracteres não forem iguais, retorna o prefixo encontrado até agora
                char* prefix = malloc(sizeof(char) * (i + 1));
                strncpy(prefix, strs[0], i);
                prefix[i] = '\0';
                return prefix;
            }
        }
    }
    
    // Se todas as strings tiverem o mesmo prefixo, retorna a primeira string completa
    return strs[0];
}

/*
char* longestCommonPrefix(char** strs, int strsSize)
{
    for(int c=0;; ++c)
    {
		if(strs[0][c] == '\0') // the longest common prefix is the first string
			return strs[0];
		for(int s=1; s<strsSize; ++s)
		{
			if(strs[s][c] != strs[0][c]) // compare all strings character to the first one
			{
				strs[0][c] = '\0'; // replace the current character with '\0'
				return strs[0];
			}
		}
	}
}
*/



int main(void) {
    char* strs[] = {"flower", "flow", "flight"};
    int strsSize = 3;

    char* prefixoComum = longestCommonPrefix(strs, strsSize);
    printf("O prefixo comum mais longo é: %s\n", prefixoComum);

    return 0;
}