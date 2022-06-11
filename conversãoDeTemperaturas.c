//#include <stdio.h>
//
//void CtoF(float v); //celsius to fahreheint
//void FtoC(float v); //fahreheint to celsius
//void CtoK(float v); //celsius to kelvin
//void KtoC(float v); //kelvin to celsius
//
//int main(){
//	float celsius, fahreheint, kelvin, valor;
//	int escalaBase, cp;
//	printf("De qual escala termometrica voce quer converter? \n");
//	printf("1- De celsius\n2- De fahreheint\n3- De kelvin\n");
//	scanf("%d", &escalaBase);
//	
//	switch(escalaBase){
//		case 1:
//			printf("\nPara qual escala termometrica voce quer converter? \n");
//			printf("\n1- para fahreheint\n2- para kelvin ");
//			scanf("%d", &cp); 
//
//			if(cp == 1){
//				printf("\nDigite o valor em celsius ");
//				scanf("%f", &valor);				
//				CtoF(valor);
//				
//			}else if(cp == 2){
//				printf("\nDigite o valor em celsius ");
//				scanf("%f", &valor);				
//				CtoK(valor);
//				
//			}else{
//				printf("Escolha um numero valido!");
//			}
//			
//			break;
//		case 2:
//			
//			break;
//		case 3:
//			
//			break;
//		default:
//			printf("Erro!");
//			break;
//	}
//		
//	return 0;
//}
//
//void CtoF(float v){
//	//F = C x 1,8 +32
//	float f;
//	
//	f = v * 1.8 + 32;
//	
//	printf("%.2f Graus celsius convertido para fahreheint e igual a: %.2f Fahreheint", v, f);
//}
//void FtoC(float v){
//	float c;
//	
//}
//void CtoK(float v){
//	float k;
//	
//	k = v + 273.15;
//	printf("%.2f Graus celsius convertido para Kelvin e igual a: %.2f Kelvin", v, k);
//}
//void KtoC(float v){
//	float c;
//}


#include <stdio.h>
#include <dos.h>

void celsius_to_fahreheint_or_kelvin(float valor, float para_escalaY);
void fahreheint_to_celsius_or_kelvin(float valor, float para_escalaY);
void kelvin_to_fahreheint_or_celsius(float valor, float para_escalaY);

int main(){
	float valor;
	int de_escalaX, para_escalaY;
	printf("\nDe qual escala termometrica voce quer converter? \n");
	printf("1- De celsius\n2- De fahreheint\n3- De kelvin ");
	scanf("%d", &de_escalaX);
			
	switch(de_escalaX){
		case 1:
			printf("\nPara qual escala termometrica voce quer converter? \n");
			printf("\n1- para fahreheint\n2- para kelvin ");
			scanf("%d", &para_escalaY); 
			
			printf("\nDigite o valor em celsius ");
			scanf("%f", &valor);
			
			celsius_to_fahreheint_or_kelvin(valor, para_escalaY);
			
			break;
		case 2:
			printf("\nPara qual escala termometrica voce quer converter? \n");
			printf("\n1- para celsius\n2- para kelvin ");
			scanf("%d", &para_escalaY); 
			
			printf("\nDigite o valor em fahreheint ");
			scanf("%f", &valor);
			
			fahreheint_to_celsius_or_kelvin(valor, para_escalaY);
			
			break;
		case 3:
			printf("\nPara qual escala termometrica voce quer converter? \n");
			printf("\n1- para celsius\n2- para fahreheint ");
			scanf("%d", &para_escalaY); 
			
			printf("\nDigite o valor em kelvin ");
			scanf("%f", &valor);
			
			kelvin_to_fahreheint_or_celsius(valor, para_escalaY);
			
			break;
		default:
			printf("Erro!");
			break;
	}
	
	int continuar;
	
	printf("\n\nDeseja fazer outra operacao? \n1- para sim\n2- para nao ");
	scanf("%d", &continuar);
	printf("\n");
	if(continuar == 1){
		main();
		
	}else if (continuar == 2){
		int x;
		printf("\nSaindo");
		for(x =0; x< 3; x++){
			printf(" .");
			sleep(1);
		}
		
	}else{
		printf("\nComando invalido, saindo...");
	}
		
	return 0;
}

void celsius_to_fahreheint_or_kelvin(float valor, float para_escalaY){
	
	if(para_escalaY == 1){
		//converte celsius para fahreheint
		
		float f;
		f = valor * 1.8 + 32;
		printf("\n%.2f Graus celsius convertido para fahreheint e igual a: %.2f Fahreheint.\n", valor, f);
		
	}else if(para_escalaY == 2){
		//converte celsius para kelvin
		
		float k;
		k = valor + 273.15;
		printf("\n%.2f Graus celsius convertido para Kelvin e igual a: %.2f Kelvin\n", valor, k);
		
	}else{
		printf("\nDigite um numero valido!");
	}
}
void fahreheint_to_celsius_or_kelvin(float valor, float para_escalaY){
	
	if(para_escalaY == 1){
		//converte de Fahreheint para celsius
		
		float c;
		c = (valor - 32) / 1.8;
		printf("\n%.2f fahreheint convertido para celsius e igaul a %.2f Graus celsius.\n", valor, c);
		
	}else if(para_escalaY == 2){
		//converte de Fahreheint para kelvin
		
		float k;
		k = (valor - 32) * 5/9 +273;
		printf("\n%.2f fahreheint convertido para kelvin e igual a %.2f kelvin.\n", valor, k);
	}else{
		printf("\nDigite um numero valido!");
	}
}
void kelvin_to_fahreheint_or_celsius(float valor, float para_escalaY){
	
	if(para_escalaY == 1){
		//kelvin para celsius
		
		float c;
		c = valor - 273;
		printf("\n%.2f kelvin convertido para celsius e igual a %.2f Graus celsius.\n", valor, c);
		
	}else if(para_escalaY == 2){
		//kelvin para fahreheint
		
		float f;
		f = (valor - 273) * 1.8 + 32;
		printf("\n%.2f kelvin convertido para fahreheint e igual a %.2f fahreheint.\n", valor, f);
		
	}else{
		printf("\nDigite um numero valido!");
	}
}
