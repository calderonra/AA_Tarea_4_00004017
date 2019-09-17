#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int t, n, a;


/* Función para imprimir arreglo */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivote
    int i = (low - 1);     // posición del primer elemento
    for (int j = low; j <= high - 1; j++)
    {
        // Si el el elemento actual es menor que el pivote
        if (arr[j] < pivot)
        {
            i++; // incrementar el index del menor elemento
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /*pi es la partición del índice, arr[p] está en el lugar correcto */
        int pi = partition(arr, low, high);
        // Ordenando separadamente los elementos antes y después de la
        // partición
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;

        int numeros[n];
        int tamano = sizeof(numeros) / sizeof(numeros[0]);

        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            numeros[i] = a;
        }

        quickSort(numeros, 0, tamano - 1);
        if (numeros[n-1] % 2==0)
        {
            int final=numeros[n-1]+2;
            cout<<final<<endl;
        }else
        {
            int final=numeros[n-1]+1;
            cout<<final<<endl;
        }
        
        
    }

    return 0;
}