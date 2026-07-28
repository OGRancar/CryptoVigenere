#include <stdio.h>
#include <string.h>

int main() {

	char Keyword[50];
	char UserText[100];
	char CipherText[100];
	char PlainText[100];

	printf("Welcome to the Vigenere Cipher!\n");
	printf("Enter a short phrase you would like encoded: ");
	fgets(UserText, 100, stdin);

	printf("Enter a keyword: ");
	scanf("%49s", Keyword);

	{
		int j = 0;
		for (int i = 0; UserText[i]; i++) {


			if (UserText[i] >= 'a' && UserText[i] <= 'z') {

				PlainText[j] = UserText[i];
				j++;
			}
			else if (UserText[i] < 91 && UserText[i] > 64) {

				PlainText[j] = UserText[i] + 32;
				j++;
			}
		}

			PlainText[j] = '\0';
	}


	for (int i = 0; Keyword[i]; i++) {

		if (Keyword[i] < 97) {

			Keyword[i] += 32;
		}
	}


	{
		int Count = 0;
		int KeyLength = strlen(Keyword);

		for (int i = 0; PlainText[i]; i++) {

			CipherText[i] = (((PlainText[i] - 96) % 26) + ((Keyword[Count] - 96) % 26)) % 26;

			if (CipherText[i] == 0) {

				CipherText[i] += 26;
			}

			CipherText[i] += 64;

			Count = (Count + 1) % KeyLength;
		}

		CipherText[strlen(PlainText)] = '\0';
	}


	printf("User Entered: %s", UserText);
	printf("Keyword: %s\n", Keyword);
	printf("Encoded Message: ");


	for (int i = 0; CipherText[i]; i++) {

		printf("%c", CipherText[i]);
	}



		return 0;
}
