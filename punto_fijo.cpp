# include <iostream>

# include <stdio.h>

# include <conio.h>

# include <math.h>

# include <iomanip>

# include <Windows.h>

# include <complex.h>

using namespace std;

//Metodo de punto fijo

void gotoxy(int x, int y)

{

	COORD coord;

	coord.X = x; coord.Y = y;

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(hStdOut, coord);

}

void Mostrar(){

	printf("%51s\n", "Universidad de Oriente");

	printf("%50s\n", "Nucleo de Anzoategui");

	printf("%51s\n", "Escuela de Ingenieria");

	printf("%60s\n", "Departamento de Computacion y Sistemas");

	printf("%45s\n\n\n\n\n\n\n", "Seccion 04");

	printf("%50s\n\n\n", "METODOS NUMERICOS");

	printf("%25s", "Profesor:");

	printf("%40s\n", "Bachiller:");

	printf("%27s", " Pedro Dorta");

	printf("%43s\n", "Randolph Zamora");



 

	system("pause");

	system("cls");

}

void coeficientes(int a, double b[]){//determina los coeficiente

	for (int i = a; i >=0; i--){

		if (a  != 0){

			cout << "Ingrese el valor que acompaña a la x^" <<a--<< endl;

			cin >> b[i];

		}

		else{

 

			cout << "Ingrese el termino independiente" << endl;

			cin >> b[i];

		}

	}

}

 

double calculo(int a, double b[]){//Determina el punto medio de la funcion polinomica 

	int i = 0;

	int c=0;

 

	double PM = 0;

	int z;

	int x=0;

	for (int j = -5; j <= 5; j++){

		z = a;

		x = c;

		c = 0;

		for (i = z; i >= 0; i--){

 

			c = c + (b[i] * pow(j, (z)));

			z--;

 

		}

			if (c >= 0 && x < 0){

 

				float N1, N2;

				N2 = j;

				N1 = j - 1;

				PM = (N1 + N2) / 2;

 

				return PM;

			}

 

	}

	return PM;//si no consigue el punto medio se le asignara 0

}

 

 

double despeje_Polinomio(double PM,int a,double b[]){//despeja la funcion polinomica y posteriormente la itera

	int i;

 

		double resultado=0;

		for (i = a - 1; i >= 0; i--)

			resultado = resultado + b[i] * pow(PM, i);

		i = a;

		resultado = -resultado / b[i];

		if (a == 3)

			resultado = cbrt(resultado);//calcula raices cubicas negativas para evitar  errores por resultado imaginario

		else

		resultado = pow(resultado,1/float(a));

 

 

		return resultado;

 

}

int main(){

	Mostrar();

	double coeficiente[10], pi, pf, aux, x, y;

	int grado, iteraciones, j = 0;

	double tol, error;

	double PM;

	double resultado;

	double diferencia = 0.0;

	do{

		cout << "ingrese el numero de polinomios" << endl;

		cin >> grado;

	} while (grado<0 || grado>10);

 

	coeficientes(grado, coeficiente);

 

	cout << "ingrese el valor de tolerancia" << endl;

	cin >> tol;

 

	do{

		cout << "Cuantas iteraciones desea realizar";

		cin >> iteraciones;

	} while (iteraciones<0 || iteraciones>50);

 

		PM = calculo(grado, coeficiente);

		system("cls");

		printf("%50s\n\n", "METODO DE PUNTO FIJO");

		cout << "i :Numero de iteraciones " << endl;

		cout << "xi: Valor que se sustituye en la funcion" << endl;

		cout << "Fx: Resultado de la iteracion "<<endl;

		cout << "fx: Error" << endl<<endl;

		cout << "   i              xi             Fx            fx  "<<endl;

		for (int i = 0; i < iteraciones; i++){

			resultado = despeje_Polinomio(PM, grado, coeficiente);

			diferencia = PM-resultado;

			if (diferencia < 0)

				diferencia *= -1;

 

 

			cout << setprecision(10);

			gotoxy(3, i+9); cout << i<<endl;

			gotoxy(15, i+9); cout << PM<<endl;

			gotoxy(30, i+9); cout << resultado;

			gotoxy(45, i+9); cout << diferencia;

			PM = resultado;

			if (diferencia <= tol){

				break;

 

			}

		}

		cout << "\n\n\nLa raiz aproximada de la funcion es:" << PM<<endl;

 

	system("pause");

}

 

//Si no puede calcular el resultado  es porque el despeje queda una raiz negativa (solo calcula raices negativa de polinomio elevado 3)...

//C++, Visual Basic 2013